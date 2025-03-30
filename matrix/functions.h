//
// Created by mazin on 30.03.2025.
//

#ifndef MYMATRIX_FUNCTIONS_H
#define MYMATRIX_FUNCTIONS_H

#include "initMtx.h"

int matrixAdd(Matrix *m1, const Matrix *m2);
int matrixSub (Matrix *m1, const Matrix *m2);
void matrixSMul (Matrix *m, double d);
void matrixSdiv (Matrix *m, double d);

int matrixAddTwo(Matrix *m, const Matrix *m1, const Matrix *m2);
int matrixSubTwo(Matrix *m, const Matrix *m1, const Matrix *m2);
int matrixSMulTwo(Matrix *m, const Matrix *m1, double d);
int matrixSDivTwo(Matrix *m, const Matrix *m1, double d);

#endif //MYMATRIX_FUNCTIONS_H
