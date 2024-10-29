#include <stdio.h>

int main() {
    float side = 3.0;
    
    FILE *fptr;
    fptr = fopen("square_points.txt", "w");
    if (fptr == NULL) {
        return 1;
    }

    // Coordinates of square vertices assuming one corner at (0, 0)
    float square[4][2] = {{0, 0}, {side, 0}, {side, side}, {0, side}};
    
    for (int i = 0; i < 4; i++) {
        fprintf(fptr, "%f %f\n", square[i][0], square[i][1]);
    }
    // Closing the square by repeating the first point
    fprintf(fptr, "%f %f\n", square[0][0], square[0][1]);

    fclose(fptr);
    return 0;
}
