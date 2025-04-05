//
// Created by mazin on 29.03.2025.
//

#ifndef MYMATRIX_INITMTX_H
#define MYMATRIX_INITMTX_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Matrix;
typedef struct Matrix Matrix;

Matrix * matrixAlloc(size_t w, size_t h);
Matrix * matrixCopy(const Matrix *originMatrix);

void matrixFree(Matrix *m);

double * matrixPtr(Matrix *m, size_t i, size_t j);
const double * matrixCPtr(const Matrix *m, size_t i, size_t j);


size_t matrixGetW(const Matrix *mtx);
size_t matrixGetH(const Matrix *mtx);
double * matrixGetData(const Matrix *mtx);


void matrixSetZero(Matrix *m); // Занулить
void matrixSetId(Matrix *m);   // Сделать единичной


/**
 * Устанавливает новые данные для матрицы.
 * @param mtx Указатель на матрицу
 * @param new_data Указатель на новый массив данных (копируется)
 * @param size Ожидаемое количество элементов (должно совпадать с w*h)
 * @return true при успехе, false при ошибке
 */
bool matrixSetData(Matrix *mtx, const double *new_data, size_t size);


Matrix * matrixAllocZero(size_t w, size_t h);
Matrix * matrixAllocId(size_t w, size_t h);

int matrixAssign(Matrix *m1, const Matrix *m2);
int matrixAssignResize(Matrix *m1, const Matrix *m2);
//bool joinMatrix(Matrix *m1, const Matrix *m2);


void printMatrix(Matrix *mtx);
Matrix* inputMatrix();

#endif //MYMATRIX_INITMTX_H
