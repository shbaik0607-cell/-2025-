#include <stdio.h>


int main(void) {
    
    double x1, y1;
    double x2, y2;

    double slope;
    double bias;

    printf("Input 1st point (x y): ");
    if (scanf_s("%lf %lf", &x1, &y1) != 2) {
        printf("Invalid input for 1st point.\n");
        return 1;
    }

    printf("Input 2nd point (x y): ");
    if (scanf_s("%lf %lf", &x2, &y2) != 2) {
        printf("Invalid input for 2nd point.\n");
        return 1;
    }

    if (x2 != x1) {
        slope = (y2 - y1) / (x2 - x1);
    }
    else {
        slope = 0.0;
        
    }

    bias = y1 - slope * x1;

    printf("\n");
    printf("Input 1st point information: %.4lf %.4lf\n", x1, y1);
    printf("Input 2nd point information: %.4lf %.4lf\n", x2, y2);

    printf("\nCalculated Output. line equation:\n");
    printf("slope: %.4lf\n", slope);
    printf("bias: %.4lf\n", bias);

    return 0;
}