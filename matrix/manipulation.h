//
// Created by mazin on 02.04.2025.
//

#ifndef MYMATRIX_MANIPULATION_H
#define MYMATRIX_MANIPULATION_H

#include "initMtx.h"
#include <math.h>


void matrixTransposition(Matrix *mtx);
void matrixPermutationRow(Matrix *mtx, size_t thisRow, size_t thatRow);
void matrixPermutationColumn(Matrix *mtx, size_t column1, size_t column2);
void matrixMulRowOnNum(Matrix *mtx, size_t row, double num);
void matrixDivRowOnNum(Matrix *mtx, size_t row, double num);
void matrixAdditionRows(Matrix *mtx, size_t row1, size_t row2, double coeff);
double matrixInfNorm(const Matrix *mtx);



#endif //MYMATRIX_MANIPULATION_H
