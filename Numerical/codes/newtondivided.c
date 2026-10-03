#include <stdio.h>

int main() {
    int n = 3, i, j;
    float x[3] = {1, 2, 3};
    float y[3] = {1, 4, 9};
    float f[3][3];

    // Initialize first column
    for(i = 0; i < n; i++)
        f[i][0] = y[i];

    // Build divided difference table
    for(j = 1; j < n; j++) {
        for(i = 0; i < n - j; i++) {
            f[i][j] = (f[i+1][j-1] - f[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    // Derivative at x = 2 (middle point)
    float derivative;
    derivative = f[0][1] + (2 - x[0]) * f[0][2];

    printf("Derivative at x = 2 is %.4f\n", derivative);

    return 0;
}