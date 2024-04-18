#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "matrix.h"



matrix* matrix_alloc(int n, int m){
    matrix* A = (matrix*) malloc(sizeof(matrix));
    A->size1 = n; 
    A->size2 = m;
    A->data = (double*) malloc(n * m * sizeof (double));
    return A;
}


void matrix_free(matrix* A){
    free(A->data); 
    free(A); 
}


void matrix_set(matrix* A, int i, int j, double x){
    A->data[i + j * A->size1] = x; 
}


double matrix_get(matrix* A, int i, int j){
    return A->data[i+j*(*A).size1];
}


void matrix_print(matrix *matrix){
    for (int i = 0; i < matrix->size1; ++i){
        for (int j = 0; j < matrix->size2; ++j)
        {
            printf("%.3f\t", matrix_get(matrix, i, j));
        }
        printf("\n");
    }
    printf("\n");
}


void matrix_product(matrix *A, matrix *B, matrix *C){
    assert(C->size1 == A->size1 && C->size2 == B->size2);
    assert(A->size2 == B->size1);
    for (int i = 0; i < A->size1; ++i){
        for (int j = 0; j < B->size2; ++j){
            double s = 0;
            for (int k = 0; k < B->size1; ++k){
                s += matrix_get(A, i, k) * matrix_get(B, k, j);
            }
            matrix_set(C, i, j, s);
        }
    }
}


void matrix_transpose(matrix *A, matrix *B){
    assert(A->size1 == B->size2 && A->size2 == B->size1);
    for (int i = 0; i < A->size1; ++i){
        for (int j = 0; j < A->size2; ++j){
            matrix_set(B, j, i, matrix_get(A, i, j));
        }
    }
}


vector* vector_alloc(int n){
    vector* A = (vector*) malloc(sizeof(vector));
    A->size = n; 
    A->data = (double*) malloc(n * sizeof (double));
    return A;
}


void vector_free(vector* A){
    free(A->data); 
    free(A); 
}


void vector_set(vector* A, int i, double x){
    A->data[i] = x; 
}


double vector_get(vector* A, int i){
    return A->data[i];
}


void vector_print(vector* vector){
    for (int i = 0; i < vector->size; ++i){
        printf("%.3f\t", vector_get(vector, i));
    }
    printf("\n\n");
}