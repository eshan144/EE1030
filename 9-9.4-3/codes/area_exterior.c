#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double circle_area() {
    double r = 4; // Radius of the circle
    return PI * r * r; // Area of the circle
}

double parabola_area(double x_start, double x_end) {
    double area = 0.0;
    int n = 1000; // Number of rectangles
    double delta_x = (x_end - x_start) / n;

    for (int i = 0; i < n; i++) {
        double x = x_start + i * delta_x;
        double y = sqrt(6 * x); // Only upper half of the parabola
        area += y * delta_x; // Approximate area using rectangles
    }
    
    return area; // Area under the parabola
}

int main() {
    double circleA = circle_area();
    double parabolaA = parabola_area(0, 4); // Calculate area from x=0 to x=4
    double exterior_area = circleA - parabolaA; // Area exterior to the parabola

    // Write results to a text file
    FILE *file = fopen("area_exterior.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(file, "%.2f\n", exterior_area); // Write the exterior area only
    fclose(file); // Close the file

    return 0;
}


