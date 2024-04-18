#ifndef MATRIX_LIB
#define MATRIX_LIB

typedef struct matrix{
    int size1, size2; 
    double *data;
} matrix;

matrix* matrix_alloc(int, int);


void matrix_print(matrix*);


void matrix_free(matrix*);


void matrix_set(matrix*, int, int, double);


double matrix_get(matrix*, int, int);


void matrix_product(matrix*, matrix*, matrix*);


void matrix_transpose(matrix*, matrix*);


typedef struct vector{
    int size; 
    double *data;
} vector;


vector* vector_alloc(int);


void vector_print(vector*);


void vector_free(vector*);


void vector_set(vector*, int, double);


double vector_get(vector*, int);

#endif