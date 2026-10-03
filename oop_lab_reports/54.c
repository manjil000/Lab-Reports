#include <stdio.h>
#include <math.h>

// Function to calculate series sum
double seriesSum(int x, int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(x, i) * (i % 2 == 0 ? -1 : 1);
    }
    return sum;
}

int main() {
    int x, n;
    
    // Input values
    printf("Enter x and n: ");
    scanf("%d %d", &x, &n);

    // Call function and display result
    printf("Sum of series: %.2f\n", seriesSum(x, n));

    return 0;
}
