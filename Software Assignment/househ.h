#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
typedef double complex comp;

int sign(double num) {
    if (num > 0) return 1;   
    else if (num < 0) return -1;
    else return 0;             
}

comp** hess(comp** mat, int a) {
    comp** A = mat; 
    for (int i = 0; i < a - 2; i++) {
        comp** w = mzeroes(a, 1);  
        double norm = 0.0;
        
        for (int j = i + 1; j < a; j++) {
            norm += creal(A[j][i]) * creal(A[j][i]);
        }
        norm = sqrt(norm);
        
        double alpha = -sign(creal(A[i + 1][i])) * norm;
        double r = csqrt(0.5 * alpha * alpha - 0.5 * alpha * creal(A[i + 1][i]));
        
        w[i + 1][0] = (A[i + 1][i] - alpha) / (2 * r);
        for (int j = i + 2; j < a; j++) {
            w[j][0] = A[j][i] / (2 * r);
        }
        
        comp** P = miden(a);
        
        comp** wwT = mmul2(w, mT(w, a, 1), a, 1, a);
        comp** H = madd(P, mmul1(wwT, a, a, -2.0 + 0 * I), a, a);
        
        A = mmul2(H, A, a, a, a);
        A = mmul2(A, mT(H, a, a), a, a, a);
        
        for (int j = 0; j < a; j++) {
            free(H[j]);
            free(P[j]);
            free(wwT[j]);
        }
        free(H);
        free(P);
        free(wwT);
        free(w);
    }
    return A;  // Return the transformed matrix

}