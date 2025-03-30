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
    if (!d || !mtx) return;
    matrixSMul(mtx, 1/d);
}



