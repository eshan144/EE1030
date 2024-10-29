#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("division_points.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Position vectors for points P and Q
    float Px = 3.0, Py = -2.0;  // Point P (3a - 2b)
    float Qx = 1.0, Qy = 1.0;   // Point Q (a + b)

    // Internal division ratio m:n (2:1)
    int m_internal = 1, n_internal = 2;
    float Rx_internal = (m_internal * Px + n_internal * Qx) / (m_internal + n_internal);
    float Ry_internal = (m_internal * Py + n_internal * Qy) / (m_internal + n_internal);

    // External division ratio m:n (2:1)
    int m_external = 2, n_external = 1;
    float Rx_external = (m_external * Qx - n_external * Px) / (m_external - n_external);
    float Ry_external = (m_external * Qy - n_external * Py) / (m_external - n_external);

    // Save the results to the file
    fprintf(fptr, "%f %f\n", Rx_internal, Ry_internal); // Internal division
    fprintf(fptr, "%f %f\n", Rx_external, Ry_external); // External division

    fclose(fptr);
    printf("Division points saved to division_points.txt\n");
    return 0;
}
