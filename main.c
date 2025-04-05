#include <stdio.h>
#include "matrix/mtx_core.h"
#include "matrix/mtx_ops.h"
#include "matrix/mtx_manipulation.h"
#include "matrix/mtx_tasks.h"


int main(void) {
    system("chcp 65001");

    size_t n = 3;
    Matrix* A = matrixAlloc(n, n);
    double a_data[] = {1, 1, 1,
                       1, -1, -1,
                       0, 4, -7};
    matrixSetData(A, a_data, n*n);

    Matrix* B = matrixAlloc(1, n);
    double b_data[] = {110, 0, 0};
    matrixSetData(B, b_data, n);

    Matrix *X = solutionLinSystem(A, B);
    printMatrix(X);
    checkSolution(A, X, B);

    matrixFree(A);
    matrixFree(B);

    Matrix *m1 = matrixAlloc(4, 4);
    double data1[] = {1, 1, 1, 3,
                       1, -1, -1, 4,
                       0, 4, -7, 5,
                       1, -1, -1, 4};
    matrixSetData(m1, data1, 16);

    Matrix *m2 = matrixAlloc(4, 4);
    double data2[] = {1, 1, 1, 3,
                      0, 4, -7, 5,
                      1, -1, -1, 4,
                      1, -1, -1, 4};
    matrixSetData(m2, data2, 16);

    matrixSDiv(m1, 4);
    matrixSub(m1, m2);
    matrixAdd(m1, m2);
    matrixMulSecond(m1, m1, m2);
    matrixAdditionRows(m1, 1, 1, 4);
    matrixPermutationRow(m2, 1, 3);
    matrixPermutationColumn(m1, 1, 2);
    matrixTransposition(m2);

    matrixFree(m1);
    matrixFree(m2);

    Matrix* C = matrixAlloc(3, 3);
    double data[] = {1, 0, 0,
                       0, 2, 0,
                       0, 0, -1};
    matrixSetData(C, data, 3*3);

    Matrix *new = matrixExp(C, 0.00000001);

    matrixFree(C);
    matrixFree(new);

    return 0;
}
