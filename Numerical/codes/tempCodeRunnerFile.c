#include <stdio.h>

// Differential equation
float f(float x, float y) {
    return x + y;
}

int main() {
    float h = 0.1;
    int steps = 3;

    // Initial values
    float x, y;

    // ================= EULER METHOD =================
    x = 0; y = 1;
    printf("\nEuler Method:\n");
    printf("x\t y\n");

    for(int i = 0; i < steps; i++) {
        y = y + h * f(x, y);
        x = x + h;
        printf("%.2f\t %.4f\n", x, y);
    }

    // ================= HEUN METHOD =================
    x = 0; y = 1;
    printf("\nHeun Method:\n");
    printf("x\t y\n");

    for(int i = 0; i < steps; i++) {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h, y + k1);

        y = y + (k1 + k2) / 2;
        x = x + h;

        printf("%.2f\t %.4f\n", x, y);
    }

    // ================= RK4 METHOD =================
    x = 0; y = 1;
    printf("\nRunge-Kutta 4th Order Method:\n");
    printf("x\t y\n");

    for(int i = 0; i < steps; i++) {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h/2, y + k1/2);
        float k3 = h * f(x + h/2, y + k2/2);
        float k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;

        printf("%.2f\t %.4f\n", x, y);
    }

    return 0;
}