#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "househ.h"

typedef double complex comp;

// Function prototypes
void eig(comp** A, int n);

int main(){
    int n = 6; // Size of the matrix
    // scanf("%d", &n);
    comp** A = mzeroes(n, n);
    /*double real, imag;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element A[%d][%d] (real imag): ", i, j);
            scanf("%lf %lf", &real, &imag);
            A[i][j] = real + imag * I;
    }
    */

    A[0][0] = 2 + 0*I;
    A[0][1] = 4 + 0*I;
    A[0][2] = 1 + 0*I;
    A[0][3] = 3 + 0*I;
    A[0][4] = 5 + 0*I;
    A[0][5] = 7 + 0*I;

    A[1][0] = 6 + 0*I;
    A[1][1] = 1 + 0*I;
    A[1][2] = 2 + 0*I;
    A[1][3] = 4 + 0*I;
    A[1][4] = 3 + 0*I;
    A[1][5] = 8 + 0*I;

    A[2][0] = 5 + 0*I;
    A[2][1] = 2 + 0*I;
    A[2][2] = 3 + 0*I;
    A[2][3] = 6 + 0*I;
    A[2][4] = 1 + 0*I;
    A[2][5] = 9 + 0*I;

    A[3][0] = 7 + 0*I;
    A[3][1] = 8 + 0*I;
    A[3][2] = 4 + 0*I;
    A[3][3] = 2 + 0*I;
    A[3][4] = 6 + 0*I;
    A[3][5] = 3 + 0*I;

    A[4][0] = 1 + 0*I;
    A[4][1] = 7 + 0*I;
    A[4][2] = 9 + 0*I;
    A[4][3] = 5 + 0*I;
    A[4][4] = 8 + 0*I;
    A[4][5] = 4 + 0*I;

    A[5][0] = 3 + 0*I;
    A[5][1] = 4 + 0*I;
    A[5][2] = 2 + 0*I;
    A[5][3] = 7 + 0*I;
    A[5][4] = 5 + 0*I;
    A[5][5] = 6 + 0*I;

    // Print the original matrix
    printf("Original Matrix A:\n");
    mprint(A, n, n);

    // Apply the Householder transformation to get the Hessenberg form
    comp** H = hess(A, n);

    // Print the Hessenberg form
    printf("\nHessenberg Matrix H:\n");
    mprint(H, n, n);

    // Find eigenvalues using the QR method
    eig(H, n);
    
    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(H[i]);
    }
    free(A);
    free(H);

    return 0;
}

void eig(comp** A, int n) {
    comp** B = mzeroes(n, n);
    comp** Q;
    comp** R;
    int iterations = 0;
    for (iterations = 0; iterations < 1000; iterations++) {
        // Perform QR decomposition
        comp*** qr = QR(A, n, n);
        Q = qr[0]; // Extract Q matrix
        R = qr[1]; // Extract R matrix

        // Multiply R * Q to get the new matrix B
        B = mmul2(R, Q, n, n, n);

        // Check if the off-diagonal elements are close to 0 (convergence)
        double diff = 0.0;
        for (int i = 0; i < n - 1; i++) {
            diff += cabs(A[i][i+1]);
        }

        if (diff < 1e-10) { // Convergence threshold
            printf("\nConverged after %d iterations.\n", iterations);
            break;
        }

        // Update A to B
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = B[i][j];
            }
        }

        // Free QR decomposition matrices
        for (int i = 0; i < n; i++) {
            free(Q[i]);
            free(R[i]);
        }
        free(Q);
        free(R);
    }

    // Print the eigenvalues (diagonal of matrix B)
    printf("\nEigenvalues:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf + %lfi\n", creal(B[i][i]), cimag(B[i][i]));
    }

    // Free B
    for (int i = 0; i < n; i++) {
        free(B[i]);
    }
    free(B);
}
