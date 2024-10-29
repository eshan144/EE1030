#include <stdio.h>
#include <math.h>

int main() {
    float alpha = 90.0;
    float beta = 135.0;
    float gamma = 45.0;

    float alpha_rad = alpha * M_PI / 180.0;
    float beta_rad = beta * M_PI / 180.0;
    float gamma_rad = gamma * M_PI / 180.0;

    float l = cos(alpha_rad);
    float m = cos(beta_rad);
    float n = cos(gamma_rad);

    FILE *fptr;
    fptr = fopen("direction_cosines.txt", "w");
    if (fptr == NULL) {
        return 1;
    }

    fprintf(fptr, "%f %f %f\n", l, m, n);
    fclose(fptr);
}

