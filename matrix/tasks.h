//
// Created by mazin on 03.04.2025.
//

#ifndef MYMATRIX_TASKS_H
#define MYMATRIX_TASKS_H

#include <math.h>
#include "initMtx.h"
#include "operations.h"
#include "manipulation.h"


/**
 * @brief Вычисляет матричную экспоненту.
 * @param mtx Указатель на входную квадратную матрицу
 * @param eps Требуемая точность вычисления (погрешность)
 * @return Указатель на новую матрицу-результат или NULL при ошибке
 * @warning Для неквадратных матриц возвращает NULL
 */
Matrix* matrixExp(const Matrix *mtx, double eps);

/**
 * @brief Решает систему линейных уравнений AX = B.
 * @param A Указатель на матрицу коэффициентов (размер N x N)
 * @param B Указатель на матрицу правых частей (размер N x M)
 * @return Указатель на матрицу решений X (размер N x M) или NULL при ошибке
 * @note Использует метод Гаусса
 * @warning Проверяет вырожденность матрицы A (определитель ≈ 0)
 */
Matrix* solutionLinSystem(Matrix *A, Matrix *B);

/**
 * @brief Проверяет корректность решения СЛАУ, вычисляя AX - B.
 * @param A Указатель на матрицу коэффициентов исходной системы
 * @param X Указатель на матрицу предполагаемого решения
 * @param B Указатель на матрицу свободных коэффициентов
 * @note Выводит норму
 */
void checkSolution(Matrix* A, const Matrix* X, const Matrix* B);

#endif //MYMATRIX_TASKS_H
