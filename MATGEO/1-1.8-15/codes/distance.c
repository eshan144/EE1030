#include <stdio.h>
#include <math.h>

int main() {
    FILE *fptr;
    fptr = fopen("distance_points.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    float P[2] = {0, 5};   // Point (0, 5)
    float Q[2] = {-5, 0};  // Point (-5, 0)
    float PQ[2];
    PQ[0] = Q[0] - P[0];
    PQ[1] = Q[1] - P[1];
    float distance = sqrt(pow(PQ[0], 2) + pow(PQ[1], 2));
    fprintf(fptr, "%f\n", distance);

    fclose(fptr);
    printf("Distance saved to distance_points.txt\n");
    return 0;
}
