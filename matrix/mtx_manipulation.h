//
// Created by mazin on 02.04.2025.
//

#ifndef MYMATRIX_MTX_MANIPULATION_H
#define MYMATRIX_MTX_MANIPULATION_H

#include "mtx_core.h"
#include <math.h>

/**
 * @brief Транспонирует матрицу.
 * @param mtx Указатель на матрицу для транспонирования
 * @note Для неквадратных матриц ничего не произойдет
 */
void matrixTransposition(Matrix *mtx);

/**
 * @brief Меняет местами две строки матрицы.
 * @param mtx Указатель на матрицу
 * @param thisRow Индекс первой строки (начинается с 0)
 * @param thatRow Индекс второй строки (начинается с 0)
 */
void matrixPermutationRow(Matrix *mtx, size_t thisRow, size_t thatRow);

/**
 * @brief Меняет местами два столбца матрицы.
 * @param mtx Указатель на матрицу
 * @param column1 Индекс первого столбца (начинается с 0)
 * @param column2 Индекс второго столбца (начинается с 0)
 */
void matrixPermutationColumn(Matrix *mtx, size_t column1, size_t column2);

/**
 * @brief Умножает все элементы строки на заданное число.
 * @param mtx Указатель на матрицу
 * @param row Индекс строки (начинается с 0)
 * @param num Множитель
 * @note Проверяет умножение на ноль
 */
void matrixMulRowOnNum(Matrix *mtx, size_t row, double num);

/**
 * @brief Делит все элементы строки на заданное число.
 * @param mtx Указатель на матрицу
 * @param row Индекс строки (начинается с 0)
 * @param num Делитель
 * @warning Проверяет деление на ноль
 */
void matrixDivRowOnNum(Matrix *mtx, size_t row, double num);

/**
 * @brief Прибавляет к одной строке другую, умноженную на коэффициент.
 * @param mtx Указатель на матрицу
 * @param row1 Индекс строки-приемника (начинается с 0)
 * @param row2 Индекс строки-источника (начинается с 0)
 * @param coeff Коэффициент умножения для строки-источника
 * @note Используется в алгоритме Гаусса
 */
void matrixAdditionRows(Matrix *mtx, size_t row1, size_t row2, double coeff);

/**
 * @brief Вычисляет бесконечную норму матрицы (максимальная сумма по строкам).
 * @param mtx Указатель на матрицу
 * @return Значение нормы или -1.0 для пустой матрицы
 */
double matrixInfNorm(const Matrix *mtx);


#endif //MYMATRIX_MTX_MANIPULATION_H
