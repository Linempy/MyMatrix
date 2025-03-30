#include <stdio.h>
#include "matrix/initMtx.h"

int main(void) {
    printf("Hello, World!\n");

//    Matrix *mtx = matrixAlloc(5, 5);

    Matrix *mtx = matrixAllocId(4, 4);

    printMatrix(mtx);

    Matrix *new;
    new = inputMatrix();

    printMatrix(new);

    return 0;
}
