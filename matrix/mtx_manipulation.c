//
// Created by mazin on 02.04.2025.
//

#include "mtx_manipulation.h"
#include <stdio.h>


void matrixTransposition(Matrix *mtx) {
    double *data = matrixGetData(mtx);
    if (!mtx || !data) return;

    size_t w = matrixGetW(mtx);
    size_t h = matrixGetH(mtx);
    if(w != h) return;

    for (size_t i = 0; i < w; i++) {
        for (size_t j = i + 1; j < w; j++) {
            double *a = matrixPtr(mtx, i, j);
            double *b = matrixPtr(mtx, j, i);
            double tmp = *a;
            *a = *b;
            *b = tmp;
        }
    }
}


/// отсчет с 0!!
void matrixPermutationRow(Matrix *mtx, size_t row1, size_t row2) {
    if (!mtx || !matrixGetData(mtx)) {
        fprintf(stderr, "Ошибка: NULL pointer\n");
        return;
    }

    size_t w = matrixGetW(mtx);
    size_t h = matrixGetH(mtx);

    if (row1 == row2) return;
    if (row1 >= h || row2 >= h) {
        fprintf(stderr, "Ошибка: Индекс строки за границами\n");
        return;
    }

    for (size_t j = 0; j < w; j++) {
        double *a = matrixPtr(mtx, row1, j);
        double *b = matrixPtr(mtx, row2, j);
        double tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void matrixPermutationColumn(Matrix *mtx, size_t column1, size_t column2) {
    if (!mtx || !matrixGetData(mtx)) {
        fprintf(stderr, "Ошибка: NULL pointer\n");
        return;
    }

    size_t w = matrixGetW(mtx);
    size_t h = matrixGetH(mtx);
    if (column1 == column2) return;
    if (column1 >= w || column2 >= w) {
        fprintf(stderr, "Ошибка: Индекс строки за границами\n");
        return;
    }

    for (size_t i = 0; i < h; i++) {
        double *a = matrixPtr(mtx, i, column1);
        double *b = matrixPtr(mtx, i, column2);
        double tmp = *a;
        *a = *b;
        *b = tmp;
    }
}


void matrixMulRowOnNum(Matrix *mtx, size_t row, double num) {
    if (!mtx || !matrixGetData(mtx) || row >= matrixGetH(mtx)) {
        fprintf(stderr, "Ошибка: некорректные данные\n");
        return;
    }

    if(fabs(num) < 1e-10) {
        fprintf(stderr, "Ошибка: умножение строки на 0\n");
        return;
    }

    for (size_t j = 0; j < matrixGetW(mtx); j++) {
        double *elem = matrixPtr(mtx, row, j);
        *elem *= num;
    }
}


void matrixDivRowOnNum(Matrix *mtx, size_t row, double num) {
    if (fabs(num) < 1e-10) {
        fprintf(stderr, "Ошибка: Деление на ноль!\n");
        return;
    }
    matrixMulRowOnNum(mtx, row, 1.0/num);
}


void matrixAdditionRows(Matrix *mtx, size_t row1, size_t row2, double coeff) {
    if (!mtx || !matrixGetData(mtx)) return;
    if (row1 >= matrixGetH(mtx) || row2 >= matrixGetH(mtx)) return;

    for (size_t j = 0; j < matrixGetW(mtx); j++) {
        double *target = matrixPtr(mtx, row1, j);
        const double *source = matrixCPtr(mtx, row2, j);
        *target += coeff * (*source);
    }
}


double matrixInfNorm(const Matrix *mtx) {
    double *data = matrixGetData(mtx);
    if (!mtx || !data) return 0.0;

    size_t col = matrixGetW(mtx);
    size_t row = matrixGetH(mtx);

    double maxNorma = 0.0;
    for (size_t i = 0; i < row; i++) {
        double rowSum = 0.0;
        for (size_t j = 0; j < col; j++) {
            rowSum += fabs(*matrixCPtr(mtx, i, j));
        }
        if (rowSum > maxNorma) maxNorma = rowSum;
    }
    return maxNorma;
}





