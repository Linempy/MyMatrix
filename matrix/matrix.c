//
// Created by mazin on 29.03.2025.
//
#include "matrix.h"
#include <stdio.h>


struct Matrix
{
    double *data; // data + w * i + j
    size_t w, h;
};

Matrix * matrixAlloc(size_t w, size_t h) {
    Matrix* pMatrix = (Matrix *) malloc(sizeof(Matrix));
    if (!pMatrix) {
        return NULL;
    }

    pMatrix->data = malloc(w * h * sizeof(double));
    if (!pMatrix->data) {
        return NULL;
    }

    pMatrix->w = w;
    pMatrix->h = h;
    return pMatrix;
}


void matrixFree(Matrix *mtx) {
    if (mtx) {
        free(mtx->data);
        free(mtx);
    }
}


double* matrixPtr(Matrix *mtx, size_t i, size_t j) {
    return mtx->data + i * mtx->w + j;
}


const double * matrixCPtr(const Matrix *mtx, size_t i, size_t j) {
    if (!mtx || !mtx->data) {
        return NULL;
    }

    if (i <= 0 || i > mtx->h || j <= 0 || j > mtx->w) {
        return NULL;
    }

    return mtx->data + i *mtx->w + j;
}


size_t matrixGetW(Matrix *mtx){
    return mtx->w;
}


size_t matrixGetH(Matrix *mtx){
    return mtx->h;
}


double * matrixGetData(Matrix *mtx) {
    if (!mtx || !mtx->data) return NULL;
    return mtx->data;
}


void matrixSetZero(Matrix *mtx) {
    if (!mtx || !mtx->data) return;

    size_t size = mtx->w * mtx->h;
    for (double *num = mtx->data, *end = mtx->data + size; num < end; num++) {
        *num = 0.0;
    }
}


void matrixSetId(Matrix *mtx) {
    if (!mtx || !mtx->data) return;

    size_t w = mtx->w, h = mtx->h;
    if (w != h || !w || !h) return;

    for (double *num = mtx->data, *end = mtx->data + w*h; num < end; num++) {
        size_t pos = (num - mtx->data);
        *num = (pos % w == pos / w) ? 1.0 : 0.0;
    }
}


Matrix * matrixAllocZero(size_t w, size_t h) {
    Matrix *mtx = matrixAlloc(w, h);
    if (!mtx) return NULL;

    if (w != h || !w || !h) return NULL;

    matrixSetZero(mtx);
    return mtx;
}


Matrix * matrixAllocId(size_t w, size_t h) {
    if (w != h || !w || !h) return NULL;

    Matrix *mtx = matrixAlloc(w, h);
    if (!mtx) return NULL;

    matrixSetId(mtx);
    return mtx;
}


int matrixAssign(Matrix *m1, const Matrix *m2) {
    if (!m1 || !m2) return -1;
    if (m1->w != m2->w || m1->h != m2->h) {
        return -1;
    }

    if (m2->data) {
        size_t size = originMatrix->h * originMatrix->w * sizeof(double);
        memcpy(m1->data, originMatrix->data, size);
    }

    return 0;
}


Matrix * matrixCopy(const Matrix *originMatrix) {
    Matrix *newMatrix = matrixAlloc(originMatrix->w, originMatrix->h);
    if(!newMatrix) {
        return NULL;
    }

    if(matrixAssign(newMatrix, originMatrix) == -1) {
        return NULL;
    }

    return newMatrix;
}


void printMatrix(Matrix *mtx) {
    size_t size = mtx->w * mtx->h;
    double * data = mtx->data;
    for(double *m = data, *end = data + size; m < end; m++) {
        size_t pos = data - m;
        if(!(pos % mtx->w) && pos) printf("\n");
        printf("%lf ", *m);
    }
}
