//
// Created by mazin on 30.03.2025.
//

#include "functions.h"

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

void matrixSMul(Matrix *mtx, double num) {
    if (!mtx) return;
    if (matrixGetW(mtx) <= 0 || matrixGetH(mtx) <= 0) return;

    double* data = matrixGetData(mtx);
    if (!data) return;

    size_t size = matrixGetH(mtx) * matrixGetW(mtx);
    for (double *pNum = data, *end = data + size; pNum < end; pNum++) {
        *pNum *= num;
    }
}


void matrixSDiv (Matrix *mtx, double d) {
    if (d == 0.0 || !mtx) return;
    matrixSMul(mtx, 1/d);
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



