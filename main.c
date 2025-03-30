#include <stdio.h>
#include "matrix/initMtx.h"
#include "matrix/functions.h"

int main(void) {
    printf("Hello, World!\n");

//    Matrix *mtx = matrixAlloc(5, 5);

    Matrix *mtx = inputMatrix();
    Matrix *mtx2 = inputMatrix();

    matrixMul(mtx, mtx2);

    printMatrix(mtx);

    matrixFree(mtx2);
    matrixFree(mtx);
    return 0;
}
