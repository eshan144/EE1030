#include <stdio.h>
#include <math.h>

int main() {
    float r = sqrt(32); // Radius of the circle
    float area_triangle = 0.5 * r * r; // Area of the triangle formed by line y = x and axes
    float area_circle_quadrant = (M_PI * r * r) / 4; // Area of the first quadrant of the circle
    float area_enclosed = area_circle_quadrant - area_triangle; // Enclosed area

    FILE *fptr;
    fptr = fopen("area_info.txt", "w");
    if (fptr == NULL) {
        return 1;
    }

    fprintf(fptr, "Area of the region in the first quadrant: %f\n", area_enclosed);
    fclose(fptr);

    return 0;
}
