#include <stdio.h>
#include <math.h>

int main() {
    FILE *fptr;
    fptr = fopen("circle_points.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Circle parameters
    float Cx = -2.0; // Center x-coordinate
    float Cy = 2.0;  // Center y-coordinate
    float r = sqrt(pow(-7 - Cx, 2) + pow(0 - Cy, 2));  // Radius from point A

    // Number of points to generate along the circumference
    int num_points = 100;

    // Generate points on the circle using parametric equations
    for (int i = 0; i <= num_points; i++) {
        float theta = 2.0 * M_PI * i / num_points;  // Angle in radians
        float x = Cx + r * cos(theta);
        float y = Cy + r * sin(theta);
        fprintf(fptr, "%f %f\n", x, y);  // Write the point to the file
    }

    fclose(fptr);
    printf("Points saved to circle_points.txt\n");
    return 0;
}
