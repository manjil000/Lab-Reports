#include <stdio.h>

// Function to integrate
float f(float x) {
    return x*x + 1;
}

int main() {
    int i, n = 6;   // n must be even (1/3) and multiple of 3 (3/8)
    float a = 0, b = 1;
    float h, sum, result;

    // ================= SIMPSON'S 1/3 RULE =================
    h = (b - a) / n;
    sum = f(a) + f(b);

    for(i = 1; i < n; i++) {
        if(i % 2 == 0)
            sum += 2 * f(a + i*h);
        else
            sum += 4 * f(a + i*h);
    }

    result = (h/3) * sum;

    printf("\nSimpson's 1/3 Rule Result = %.4f\n", result);


    // ================= SIMPSON'S 3/8 RULE =================
    h = (b - a) / n;
    sum = f(a) + f(b);

    for(i = 1; i < n; i++) {
        if(i % 3 == 0)
            sum += 2 * f(a + i*h);
        else
            sum += 3 * f(a + i*h);
    }

    result = (3*h/8) * sum;

    printf("Simpson's 3/8 Rule Result = %.4f\n", result);

    return 0;
}