#include <stdio.h>
#include "matrix/initMtx.h"
#include "matrix/operations.h"
#include "matrix/manipulation.h"
#include "matrix/tasks.h"


int main(void) {
    system("chcp 65001");
//    Matrix *mtx = matrixAlloc(3, 3);
//    Matrix *B = matrixAlloc(1, 3);


//    Matrix *mtx = inputMatrix();
    size_t n = 3;
    Matrix* A = matrixAlloc(n, n);
    double a_data[] = {1, 1, 1,
                       1, 1, 1,
                       0, 4, -7};
    matrixSetData(A, a_data, n*n);

    Matrix* B = matrixAlloc(1, n);
    double b_data[] = {110, 0, 0};
    matrixSetData(B, b_data, n);
//    Matrix *mtx2 = inputMatrix();

    Matrix *X = solutionLinSystem(A, B);
    printMatrix(X);
    checkSolution(A, X, B);
//    Matrix *out = matrixAlloc(matrixGetH(mtx), matrixGetW(mtx2));
//
//    matrixMulSecond(out, mtx, mtx2);
//    printMatrix(mtx);
    matrixFree(A);
    matrixFree(B);
//    matrixFree(mtx);
    return 0;
}
