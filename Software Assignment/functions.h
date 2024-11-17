#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

typedef double complex comp;

void mprint(comp** mat, int a, int b){
    printf("[\n");
    for(int i = 0; i < a; i++) {
        printf("[ ");
        for(int j = 0; j < b; j++) {
            printf("%lf + %lfi ", creal(mat[i][j]), cimag(mat[i][j]));
        }
        printf("]\n");
    }
    printf("]\n");
}

comp** mzeroes(int a, int b){
    comp** mat = (comp**) malloc(sizeof(comp*) * a);  // Corrected to allocate pointer array
    for(int i = 0; i < a; i++) {
        mat[i] = (comp*) malloc(sizeof(comp) * b);
        for(int j = 0; j < b; j++) {
            mat[i][j] = 0 + 0*I;
        }
    }
    return mat;
}

comp** miden(int a){
    comp** mat = mzeroes(a, a);
    for(int i = 0; i < a; i++) {
        mat[i][i] = 1 + 0*I;
    }
    return mat;
}

comp** madd(comp** mat1, comp** mat2, int a, int b){
    comp** mat = (comp**) malloc(sizeof(comp*) * a);  // Corrected to allocate pointer array
    for(int i = 0; i < a; i++) {
        mat[i] = (comp*) malloc(sizeof(comp) * b);
        for(int j = 0; j < b; j++) {
            mat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat;
}

comp** mmul1(comp** mat, int a, int b, comp k){
    comp** nmat = (comp**) malloc(sizeof(comp*) * a);
    for(int i = 0; i < a; i++) {
        nmat[i] = (comp*) malloc(sizeof(comp) * b);
        for(int j = 0; j < b; j++) {
            nmat[i][j] = k * mat[i][j];
        }
    }
    return nmat;
}

comp** mmul2(comp** mat1, comp** mat2, int a, int b, int c){
    comp** mat = mzeroes(a, c);
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < c; j++) {
            for(int k = 0; k < b; k++) {
                mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return mat;
}

comp** mT(comp** mat, int a, int b){
    comp** nmat = (comp**) malloc(sizeof(comp*) * b);
    for(int i = 0; i < b; i++) {
        nmat[i] = (comp*) malloc(sizeof(comp) * a);
        for(int j = 0; j < a; j++) {
            nmat[i][j] = conj(mat[j][i]);
        }
    }
    return nmat;
}

comp** mcol(comp** mat, int a, int b, int k){
    comp** nmat = (comp**) malloc(sizeof(comp*) * a);
    for(int i = 0; i < a; i++) {
        nmat[i] = (comp*) malloc(sizeof(comp));  // Allocating only for one element per row
        nmat[i][0] = mat[i][k];  // Only store the k-th column in each row
    }
    return nmat;
}

comp** mcopy(comp** mat, int a, int b){
    comp** newmat = (comp**) malloc(sizeof(comp)*a);
    for(int i = 0; i < a; i++){
        newmat[i] = (comp*) malloc(sizeof(comp)*b);

        for(int j = 0; j < b; j++){
            newmat[i][j] = mat[i][j];
        }
    }
    return newmat;
}

double vnorm(comp** vec, int m) {
    double sum = 0;
    for(int i = 0; i < m; i++) {
        sum += creal(vec[i][0]) * creal(vec[i][0]) + cimag(vec[i][0]) * cimag(vec[i][0]);
    }
    return sqrt(sum);
}

comp*** QR(comp** A, int m, int n) {
    comp** Q = mzeroes(m, n);  // Matrix Q
    comp** R = mzeroes(n, n);  // Matrix R

    for (int i = 0; i < n; i++) {
        comp** a = mcol(A, m, n, i);  // Get the i-th column of A
        comp** q = mcopy(a, m, 1);  // Start q as a copy of the i-th column of A

        // Orthogonalize q against the previous q's in Q
        for (int j = 0; j < i; j++) {
            comp x = mmul2(mT(a, m, 1), mcol(Q, m, n, j), 1, m, 1)[0][0];
            q = madd(q, mmul1(mcol(Q, m, n, j), m, 1, -creal(x)), m, 1);
            R[j][i] = x;
        }

        // Normalize q to get the i-th column of Q
        R[i][i] = vnorm(q, m);
        q = mmul1(q, m, 1, 1.0 / creal(R[i][i]));  // Normalize q

        // Store the normalized q in the i-th column of Q
        for (int j = 0; j < m; j++) {
            Q[j][i] = q[j][0];
        }
    }

    // Allocate memory for returning Q and R matrices
    comp*** ret = (comp***) malloc(sizeof(comp**) * 2);
    ret[0] = Q;  // First element is Q matrix
    ret[1] = R;  // Second element is R matrix
    return ret;
}
