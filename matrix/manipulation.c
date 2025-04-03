//
// Created by mazin on 02.04.2025.
//

#include "manipulation.h"


void matrixTransposition(Matrix *mtx) {
    double *data = matrixGetData(mtx);
    if (!mtx || !data) return;

    size_t w = matrixGetW(mtx);
    size_t h = matrixGetH(mtx);
    if(w != h) return;

    size_t size = w * h;
    for (double *p = data, *end = data + size; p < end; p++) {
        size_t pos = p - data;
        size_t i = pos / w;
        size_t j = pos % w;

        if (j > i) {
            double *q = data + j * w + i;
            double tmp = *p;
            *p = *q;
            *q = tmp;
        }
    }
}
