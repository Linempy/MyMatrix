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

/**
 * @brief Выделяет память под матрицу заданного размера.
 * @param w Ширина матрицы (количество столбцов)
 * @param h Высота матрицы (количество строк)
 * @return Указатель на созданную матрицу или NULL при ошибке выделения памяти
 */
Matrix* matrixAlloc(size_t w, size_t h);

/**
 * @brief Создает полную копию матрицы.
 * @param originMatrix Матрица-источник для копирования
 * @return Указатель на новую копию матрицы или NULL при ошибке
 */
Matrix* matrixCopy(const Matrix* originMatrix);

/**
 * @brief Освобождает память, занятую матрицей.
 * @param m Указатель на освобождаемую матрицу
 */
void matrixFree(Matrix* m);

/**
 * @brief Получает указатель на элемент матрицы для модификации.
 * @param m Указатель на матрицу
 * @param i Индекс строки (начинается с 0)
 * @param j Индекс столбца (начинается с 0)
 * @return Указатель на элемент матрицы или NULL при некорректных индексах
 */
double* matrixPtr(Matrix* m, size_t i, size_t j);

/**
 * @brief Получает константный указатель на элемент матрицы.
 * @param m Указатель на матрицу
 * @param i Индекс строки (начинается с 0)
 * @param j Индекс столбца (начинается с 0)
 * @return Константный указатель на элемент или NULL при некорректных индексах
 */
const double* matrixCPtr(const Matrix* m, size_t i, size_t j);

/**
 * @brief Возвращает ширину матрицы (количество столбцов).
 * @param mtx Указатель на матрицу
 * @return Количество столбцов в матрице
 */
size_t matrixGetW(const Matrix* mtx);

/**
 * @brief Возвращает высоту матрицы (количество строк).
 * @param mtx Указатель на матрицу
 * @return Количество строк в матрице
 */
size_t matrixGetH(const Matrix* mtx);

/**
 * @brief Получает прямой доступ к данным матрицы.
 * @param mtx Указатель на матрицу
 * @return Указатель на массив данных матрицы (хранятся одним блоком памяти)
 */
double* matrixGetData(const Matrix* mtx);

/**
 * @brief Заполняет все элементы матрицы нулями.
 * @param m Указатель на матрицу
 */
void matrixSetZero(Matrix* m);

/**
 * @brief Преобразует матрицу в единичную.
 * @param m Указатель на квадратную матрицу
 * @note Для неквадратных матриц ничего не произойдет
 */
void matrixSetId(Matrix* m);

/**
 * @brief Устанавливает новые данные для матрицы.
 * @param mtx Указатель на матрицу
 * @param new_data Указатель на новый массив данных (будет скопирован)
 * @param size Ожидаемое количество элементов (должно равняться w*h)
 * @return true - данные успешно установлены, false - ошибка размера
 */
bool matrixSetData(Matrix* mtx, const double* new_data, size_t size);

/**
 * @brief Создает нулевую матрицу заданного размера.
 * @param w Ширина матрицы
 * @param h Высота матрицы
 * @return Указатель на новую матрицу или NULL при ошибке
 */
Matrix* matrixAllocZero(size_t w, size_t h);

/**
 * @brief Создает единичную матрицу заданного размера.
 * @param w Ширина матрицы (должна равняться высоте для квадратной)
 * @param h Высота матрицы
 * @return Указатель на новую матрицу или NULL при ошибке
 */
Matrix* matrixAllocId(size_t w, size_t h);

/**
 * @brief Копирует данные из одной матрицы в другую (с одинаковыми размерами).
 * @param m1 Матрица-приемник
 * @param m2 Матрица-источник
 * @return 0 при успехе, -1 при ошибке (разные размеры)
 */
int matrixAssign(Matrix* m1, const Matrix* m2);

/**
 * @brief Копирует данные с изменением размера матрицы m1.
 * @param m1 Матрица, у которой будет изменен размер
 * @param m2 Матрица-источник
 * @return 0 при успехе, -1 при ошибке выделения памяти
 */
int matrixAssignResize(Matrix* m1, const Matrix* m2);

/**
 * @brief Выводит матрицу в читаемом формате.
 * @param mtx Указатель на матрицу для печати
 */
void printMatrix(Matrix* mtx);

/**
 * @brief Создает матрицу на основе пользовательского ввода.
 * @return Указатель на созданную матрицу или NULL при ошибке ввода
 * @note Запрашивает у пользователя размеры и элементы матрицы
 */
Matrix* inputMatrix();


#endif //MYMATRIX_INITMTX_H
