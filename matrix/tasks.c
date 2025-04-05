//
// Created by mazin on 03.04.2025.
//

#include "tasks.h"


Matrix* matrixExp(const Matrix *mtx, double eps) {
    if (!mtx || !matrixGetData(mtx) || matrixGetW(mtx) != matrixGetH(mtx)) {
        return NULL;
    }

    const size_t n = matrixGetW(mtx);
    Matrix *result = matrixAllocId(n, n);
    Matrix *term = matrixCopy(mtx);
    size_t i = 1;

    while(matrixInfNorm(term) >= eps){
        matrixAdd(result, term);

        if (matrixMul(term, mtx) == -1) {
            matrixFree(term);
            matrixFree(result);
            return NULL;
        }

        i++;
        matrixSDiv(term, i);
    }

    matrixFree(term);
    return result;
}


static size_t findMaxAbsElementColumn(const Matrix *mtx, size_t i, size_t j) {
    double maxNum = fabs(*matrixCPtr(mtx, i, j));
    size_t resRow = i;

    for (size_t row = i+1; row < matrixGetH(mtx); row++) {
        double elem = fabs(*matrixCPtr(mtx, row, j));
        if (maxNum < elem) {
            maxNum = elem;
            resRow = row;
        }
    }

    return resRow;
}


static bool nullifyColumn(Matrix *A, Matrix *B, size_t pivot_row) {
    const double pivot = *matrixCPtr(A, pivot_row, pivot_row);
    if (fabs(pivot) < 1e-12) return false;

    for (size_t row = pivot_row + 1; row < matrixGetH(A); row++) {
        double coeff = *matrixCPtr(A, row, pivot_row) / pivot;

        for (size_t col = pivot_row; col < matrixGetW(A); col++) {
            *matrixPtr(A, row, col) -= coeff * *matrixCPtr(A, pivot_row, col);
        }
        *matrixPtr(B, row, 0) -= coeff * *matrixCPtr(B, pivot_row, 0);

        *matrixPtr(A, row, pivot_row) = 0.0;
    }
    return true;
}


static void nullifyColumnBack(Matrix *A, Matrix *B, size_t i, size_t j) {
    if (i == 0)  {
        return;
    }

    for (int k = i - 1; k >= 0; k--) {
        double coeff = *matrixCPtr(A, k, i);
        *matrixPtr(B, k, 0) -= coeff * *matrixCPtr(B, i, 0);
        *matrixPtr(A, k, i) = 0.0;
    }
}


bool isSingular(const Matrix* A, size_t col) {
    double max_val = 0.0;
    for (size_t i = col; i < matrixGetW(A); i++) {
        max_val = fmax(max_val, fabs(*matrixCPtr(A, i, col)));
    }
    return (max_val < 1e-10 * matrixGetH(A));
}


Matrix* solutionLinSystem(Matrix *A, Matrix *B) {
    if (!A || !B || matrixGetH(A) != matrixGetH(B) ||
        matrixGetW(A) != matrixGetH(A)) {
        fprintf(stderr, "Ошибка: Несовместимые размеры матриц\n");
        return NULL;
    }

    size_t rows = matrixGetH(A);
    size_t cols = matrixGetW(A);

    for (size_t nRow = 0; nRow < cols; nRow++) {
        size_t rowWithMaxElement = findMaxAbsElementColumn(A, nRow, nRow);

        if (isSingular(A, nRow)) {
            fprintf(stderr, "Матрица вырождена в столбце %zu\n", nRow);
            return NULL;
        }
        if (rowWithMaxElement != nRow) {
            matrixPermutationRow(A, nRow, rowWithMaxElement);
            matrixPermutationRow(B, nRow, rowWithMaxElement);
        }

        double div = *matrixCPtr(A, nRow, nRow);
        matrixDivRowOnNum(A, nRow, div);
        matrixDivRowOnNum(B, nRow, div);

        if (!nullifyColumn(A, B, nRow)) {
            fprintf(stderr, "Ошибка в занулении столбца %zu\n", nRow);
            return NULL;
        }
    }

    for (size_t nRow = rows-1; nRow; nRow--) {
        nullifyColumnBack(A, B, nRow, nRow);
    }

    return B;
}


void checkSolution(Matrix* A, const Matrix* X, const Matrix* B) {
    if (!A || !X || !B ||
        matrixGetH(A) != matrixGetH(B) ||
        matrixGetW(A) != matrixGetH(X) ||
        matrixGetW(X) != 1) {
        fprintf(stderr, "Ошибка: Несовместимые размеры матриц\n");
        return;
    }

    Matrix* AX = matrixAlloc(1, matrixGetH(A));
    if (!AX) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return;
    }

    if (matrixMulSecond(AX, A, X) == -1) {
        fprintf(stderr, "Ошибка умножения матриц\n");
        matrixFree(AX);
        return;
    }

    Matrix* residual = matrixCopy(B);
    if (!residual) {
        matrixFree(AX);
        fprintf(stderr, "Ошибка копирования матрицы\n");
        return;
    }

    // residual = B + (-AX)
    if (matrixSub(residual, AX) == -1) {
        fprintf(stderr, "Ошибка сложения матриц\n");
        matrixFree(AX);
        matrixFree(residual);
        return;
    }

    printf("\n=== Проверка решения ===\n");

    printf("Вычисленное A*X:\n");
    printMatrix(AX);

    printf("\nОжидаемый вектор B:\n");
    printMatrix(B);


    printf("\nНорма: %e\n", matrixInfNorm(residual));

    // Освобождаем память
    matrixFree(AX);
    matrixFree(residual);
}





