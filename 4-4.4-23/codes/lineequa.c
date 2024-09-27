#include <stdio.h>

int main() {
    // Coefficients of the first line (x - 2y + 3 = 0)
    float a1 = 1, b1 = -2, c1 = 3;

    // Coefficients of the second line (2x - 4y = 5)
    float a2 = 2, b2 = -4, c2 = -5;

    // Open file to write the coefficients
    FILE *fptr;
    fptr = fopen("line_coefficients.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fptr, "Line 1: %fx + (%fy) + (%f) = 0\n", a1, b1, c1);
    fprintf(fptr, "%f %f %f\n", a1, b1, c1);
    fprintf(fptr, "Line 2: %fx + (%fy) + (%f) = 0\n", a2, b2, c2);
    fprintf(fptr, "%f %f %f\n", a2, b2, c2);

    fclose(fptr);

    printf("Line coefficients saved to line_coefficients.txt\n");
    return 0;
}
