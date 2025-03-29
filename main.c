#include <stdio.h>
#include "matrix/matrix.h"

int main(void) {
    printf("Hello, World!\n");

//    Matrix *mtx = matrixAlloc(5, 5);

    Matrix *mtx = matrixAllocId(4, 4);

    for(size_t i = 0; i < matrixGetH(mtx) * matrixGetW(mtx); i++) {
        if(!(i % matrixGetW(mtx)) && i) printf("\n");
        printf("%lf ", matrixGetData(mtx)[i]);
    }

    return 0;
}
