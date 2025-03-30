//
// Created by mazin on 29.03.2025.
//

#ifndef MYMATRIX_MATRIX_H
#define MYMATRIX_MATRIX_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct Matrix;
typedef struct Matrix Matrix;

Matrix * matrixAlloc(size_t w, size_t h);
Matrix * matrixCopy(const Matrix *originMatrix);

void matrixFree(Matrix *m);

double * matrixPtr(Matrix *m, size_t i, size_t j);
const double * matrixCPtr(const Matrix *m, size_t i, size_t j);


size_t matrixGetW(Matrix *mtx);
size_t matrixGetH(Matrix *mtx);
double * matrixGetData(Matrix *mtx);


void matrixSetZero(Matrix *m); // Занулить
void matrixSetId(Matrix *m);   // Сделать единичной


Matrix * matrixAllocZero(size_t w, size_t h);
Matrix * matrixAllocId(size_t w, size_t h);

int matrixAssign(Matrix *m1, const Matrix *m2);

void printMatrix(Matrix *mtx);

#endif //MYMATRIX_MATRIX_H
