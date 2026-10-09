#include <stdio.h>
#include <math.h>

int main() {
    int i;
    float x0=0, y0=0, z0=0;   // initial guess
    float x1, y1, z1;

    int iterations = 3;

    // ================= GAUSS-JACOBI =================
    printf("\nGauss-Jacobi Method:\n");
    printf("Iter\t x\t y\t z\n");

    for(i=1; i<=iterations; i++) {
        x1 = (12 - y0 - z0) / 10;
        y1 = (12 - x0 - z0) / 10;
        z1 = (12 - x0 - y0) / 10;

        printf("%d\t %.4f\t %.4f\t %.4f\n", i, x1, y1, z1);

        x0 = x1;
        y0 = y1;
        z0 = z1;
    }

    // reset initial values
    x0=0; y0=0; z0=0;

    // ================= GAUSS-SEIDEL =================
    printf("\nGauss-Seidel Method:\n");
    printf("Iter\t x\t y\t z\n");

    for(i=1; i<=iterations; i++) {
        x0 = (12 - y0 - z0) / 10;
        y0 = (12 - x0 - z0) / 10;
        z0 = (12 - x0 - y0) / 10;

        printf("%d\t %.4f\t %.4f\t %.4f\n", i, x0, y0, z0);
    }

    return 0;
}