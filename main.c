#include <stdio.h>
#include "matrix/initMtx.h"
#include "matrix/functions.h"
#include "matrix/manipulation.h"


int main(void) {
    printf("Hello, World!\n");

//    Matrix *mtx = matrixAlloc(5, 5);

    Matrix *mtx = inputMatrix();

    printMatrix(mtx);

    matrixFree(mtx);
    return 0;
}
