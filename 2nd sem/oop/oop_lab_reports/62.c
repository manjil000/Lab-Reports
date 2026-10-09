#include <stdio.h>

#define PI 3.14159
#define AREA(r) (PI * (r) * (r))
#define CIRCUMFERENCE(r) (2 * PI * (r))

int main() {
    float radius;
    
    // Input radius
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Compute and display area and circumference
    printf("Area of circle: %.2f\n", AREA(radius));
    printf("Circumference of circle: %.2f\n", CIRCUMFERENCE(radius));

    return 0;
}
