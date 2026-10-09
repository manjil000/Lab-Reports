#include <stdio.h>

#define AREA(l, w) ((l) * (w))
#define PERIMETER(l, w) (2 * ((l) + (w)))

int main() {
    float length, width;

    // Input length and width
    printf("Enter length and width of rectangle: ");
    scanf("%f %f", &length, &width);

    // Compute and display area and perimeter
    printf("Area of rectangle: %.2f\n", AREA(length, width));
    printf("Perimeter of rectangle: %.2f\n", PERIMETER(length, width));

    return 0;
}
