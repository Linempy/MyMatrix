//
// Created by mazin on 03.04.2025.
//

#ifndef MYMATRIX_TASKS_H
#define MYMATRIX_TASKS_H

#include "initMtx.h"
#include "operations.h"
#include "manipulation.h"


Matrix* matrixExp(const Matrix *mtx, double eps);
Matrix* solutionLinSystem(Matrix *A, Matrix *B);
void checkSolution(Matrix* A, const Matrix* X, const Matrix* B);

#endif //MYMATRIX_TASKS_H
