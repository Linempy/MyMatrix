//
// Created by mazin on 30.03.2025.
//

#include "mtx_ops.h"

int matrixAdd(Matrix *m1, const Matrix *m2) {
    if (!m1 || !m2) return -1;

    if (matrixGetW(m1) != matrixGetW(m2) || matrixGetH(m1) != matrixGetH(m2)) return -1;

    size_t size = matrixGetH(m1) * matrixGetW(m1);
    double* dataAdded = matrixGetData(m1);
    double* dataAdding = matrixGetData(m2);

    if (!dataAdded || !dataAdding) return -1;

    for (double *pNum = dataAdded, *end = dataAdded + size; pNum < end; pNum++) {
        size_t pos = pNum - dataAdded;
        *pNum += *(dataAdding+pos);
    }

    return 0;
}

int matrixSub(Matrix *m1, const Matrix *m2) {
    if (!m1 || !m2) return -1;

    if (matrixGetW(m1) != matrixGetW(m2) || matrixGetH(m1) != matrixGetH(m2)) return -1;

    size_t size = matrixGetH(m1) * matrixGetW(m1);
    double* dataAdded = matrixGetData(m1);
    double* dataAdding = matrixGetData(m2);

    if (!dataAdded || !dataAdding) return -1;

    for (double *pNum = dataAdded, *end = dataAdded + size; pNum < end; pNum++) {
        size_t pos = pNum - dataAdded;
        *pNum -= *(dataAdding+pos);
    }

    return 0;
}

int matrixSMul(Matrix *mtx, double num) {
    if (!mtx) return -1;
    if (matrixGetW(mtx) <= 0 || matrixGetH(mtx) <= 0) return -1;

    double* data = matrixGetData(mtx);
    if (!data) return -1;

    size_t size = matrixGetH(mtx) * matrixGetW(mtx);
    for (double *pNum = data, *end = data + size; pNum < end; pNum++) {
        *pNum *= num;
    }
    return 0;
}


int matrixSDiv(Matrix *mtx, double d) {
    if (d == 0.0 || !mtx) return -1;
    matrixSMul(mtx, 1/d);
    return 0;
}


int matrixAddTwo(Matrix *outMatrix, const Matrix *m1, const Matrix *m2){
    if (!outMatrix || !m1 || !m2) return -1;

    if (matrixGetW(outMatrix) != matrixGetW(m1) ||
        matrixGetH(outMatrix) != matrixGetH(m1) ||
        matrixGetW(m1) != matrixGetW(m2) ||
        matrixGetH(m1) != matrixGetH(m2)) {
        return -1;
    }

    if (matrixAssign(outMatrix, m1) == -1) return -1;

    if (matrixAdd(outMatrix, m2) != 0) {
        return -1;
    }

    return 0;
}


int matrixSubTwo(Matrix *outMatrix, const Matrix *m1, const Matrix *m2) {
    if (!outMatrix || !m1 || !m2) return -1;

    if (matrixGetW(outMatrix) != matrixGetW(m1) ||
        matrixGetH(outMatrix) != matrixGetH(m1) ||
        matrixGetW(m1) != matrixGetW(m2) ||
        matrixGetH(m1) != matrixGetH(m2)) {
        return -1;
    }

    if (matrixAssign(outMatrix, m1) == -1) return -1;

    if (matrixSub(outMatrix, m2) != 0) return -1;

    return 0;
}


int matrixSMulTwo(Matrix *outMatrix, const Matrix *m1, double num) {
    if (!outMatrix || !m1) return -1;

    if (matrixGetW(outMatrix) != matrixGetW(m1) ||
        matrixGetH(outMatrix) != matrixGetH(m1)) {
        return -1;
    }

    if(matrixAssign(outMatrix, m1) == -1) return -1;
    matrixSMul(outMatrix, num);

    return 0;
}

int matrixSDivTwo(Matrix *outMatrix, const Matrix *m1, double d) {
    if (d == 0.0 || !m1 || !outMatrix) return -1;

    if (matrixAssign(outMatrix,m1) == -1) return -1;

    matrixSMul(outMatrix, 1/d);
    return 0;
}


static int matrixMultiplyTo(Matrix* outMatrix, const Matrix* m1, const Matrix* m2) {
    if (!outMatrix || !m1 || !m2) {
        printf("Некорректные данные");
        return -1;
    }

    size_t rows1 = matrixGetH(m1);
    size_t cols1 = matrixGetW(m1);
    size_t rows2 = matrixGetH(m2);
    size_t cols2 = matrixGetW(m2);

    if (cols1 != rows2) {
        printf("Неподходящий размер матриц");
        return -1;
    }

    bool isResize = outMatrix == m1 || outMatrix == m2;
    if (!isResize && (matrixGetH(outMatrix) != rows1 || matrixGetW(outMatrix) != cols2)) {
        printf("%d", (matrixGetH(outMatrix) != rows1 || matrixGetW(outMatrix) != cols2));
        return -1;
    }

    Matrix* temp = isResize ? matrixAlloc(rows1, cols2) : outMatrix;
    if (!temp) return -1;

    for (size_t nRow = 0; nRow < rows1; nRow++) {
        for (size_t nColumn = 0; nColumn < cols2; nColumn++) {
            double c = 0;
            for (size_t nElement = 0; nElement < cols1; nElement++) {
                c += *matrixCPtr(m1, nRow, nElement) * *matrixCPtr(m2, nElement, nColumn);
            }
            *matrixPtr(temp, nRow, nColumn) = c;
        }
    }

    int result = 0;
    if (temp != outMatrix) {
        result = isResize ? matrixAssignResize(outMatrix, temp) : matrixAssign(outMatrix, temp);
        matrixFree(temp);
    }

    return result;
}


int matrixMul(Matrix *m1, const Matrix *m2) {
    return matrixMultiplyTo(m1, m1, m2);
}


int matrixMulSecond(Matrix *outMatrix, Matrix *m1, const Matrix *m2) {
    return matrixMultiplyTo(outMatrix, m1, m2);
}






