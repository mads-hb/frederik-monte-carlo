#include "matrix.h"
#include <sys/types.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


#define M_PI 3.14159265358979323846


double drand()   /* uniform distribution, (0..1] */
{
  return (rand()+1.0)/(RAND_MAX+1.0);
}

double random_normal() 
 /* normal distribution, centered on 0, std dev 1 */
{
  return sqrt(-2*log(drand())) * cos(2*M_PI*drand());
}


int modulo(double_t x, double_t y, double_t L, size_t* FI, size_t* BI, double_t strip_l, double_t space_l){
    if (((0 < x) & (x < L)) & ((0 < y) & (y < L)))
    {
        double_t fi = (x-0.5*strip_l) / (strip_l+space_l);
        double_t bi = (y-0.5*strip_l) / (strip_l+space_l);
        *FI = round(fi);
        *BI = round(bi);
        return 1;
    }
    return 0;
}


void monte_carlo_data(matrix* hits, double_t x0, double_t y0, double_t z0, size_t N, double_t strip_l, double_t space_l) {
    for (size_t i = 0; i < N; i++)
    {
        matrix* vec = matrix_alloc(3, 1);
        double_t norm = 0.0;
        for (size_t j = 0; j < 3; j++)
        {   
            double_t r = random_normal();
            norm += r*r;
            matrix_set(vec, j, 0, r);
        }
        for (size_t j = 0; j < 3; j++)
        {   
            matrix_set(vec, j, 0, matrix_get(vec, j, 0)/sqrt(norm));
        }

        if (z0 / matrix_get(vec, 2,0) < 0)
        {
            double_t x = x0 - z0/matrix_get(vec, 2,0) * matrix_get(vec, 0,0);
            double_t y = x0 - z0/matrix_get(vec, 2,0) * matrix_get(vec, 1,0);
            size_t FI, BI;

            if(modulo(x, y, 1, &FI, &BI, strip_l, space_l))
            {
                matrix_set(hits, FI, BI, matrix_get(hits, FI, BI) + 1);
            }
            else
            {
                //pass here
            }

        }
        matrix_free(vec);
        
    }
}



int main() {
    matrix* hits = matrix_alloc(16, 16);

    size_t N = 1e8;
    double_t L = 1.0;
    double_t strip_l = 1/16.0;
    double_t space_l = 0;
    monte_carlo_data(hits, 0.5*L, 0.5*L, 2*L, N, strip_l, space_l);
    
    matrix_print(hits);
    matrix_free(hits);
    return 0;
}