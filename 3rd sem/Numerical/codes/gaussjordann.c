#include <stdio.h>

int main() {
    int i, j, k;
    float a[3][4], ratio;

    // Input augmented matrix
    printf("Enter 3x4 augmented matrix:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<4; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for(i=0; i<3; i++) {
        // Make diagonal element = 1
        float pivot = a[i][i];
        for(j=0; j<4; j++) {
            a[i][j] = a[i][j] / pivot;
        }

        // Make other elements in column = 0
        for(k=0; k<3; k++) {
            if(k != i) {
                ratio = a[k][i];
                for(j=0; j<4; j++) {
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    // Output results
    printf("\nSolution:\n");
    printf("x = %.4f\n", a[0][3]);
    printf("y = %.4f\n", a[1][3]);
    printf("z = %.4f\n", a[2][3]);

    return 0;
}