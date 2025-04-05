//
// Created by mazin on 30.03.2025.
//

#ifndef MYMATRIX_OPERATIONS_H
#define MYMATRIX_OPERATIONS_H

#include <stdio.h>
#include <stdbool.h>
#include "initMtx.h"

int matrixAdd(Matrix *m1, const Matrix *m2);
int matrixSub(Matrix *m1, const Matrix *m2);
int matrixSMul(Matrix *m, double d);
int matrixSDiv(Matrix *m, double d);

int matrixAddTwo(Matrix *m, const Matrix *m1, const Matrix *m2);
int matrixSubTwo(Matrix *m, const Matrix *m1, const Matrix *m2);
int matrixSMulTwo(Matrix *m, const Matrix *m1, double d);
int matrixSDivTwo(Matrix *m, const Matrix *m1, double d);
int matrixMul(Matrix *m1, const Matrix *m2);
int matrixMulSecond(Matrix *outMatrix, Matrix *m1, const Matrix *m2);

#endif //MYMATRIX_OPERATIONS_H
