#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;


void calculate_line_parameters(const Point* p1, const Point* p2, double* slope, double* bias) {
   
    if (p2->x != p1->x) {
        *slope = (p2->y - p1->y) / (p2->x - p1->x);
    }
    else {
     
        *slope = 0.0; 
    }

    
    *bias = p1->y - (*slope) * p1->x;
}

int main(void) {
    
    double p1_coords[2]; 
    double p2_coords[2]; 

    double calculated_slope;
    double calculated_bias;

    
    printf("Input 1st point information:\n");
    if (scanf_s("%lf %lf", &p1_coords[0], &p1_coords[1]) != 2) {
        
        return 1;
    }

    printf("\nInput 2nd point information:\n");
    if (scanf_s("%lf %lf", &p2_coords[0], &p2_coords[1]) != 2) {
       
        return 1;
    }

    Point p1 = { p1_coords[0], p1_coords[1] };
    Point p2 = { p2_coords[0], p2_coords[1] };

    calculate_line_parameters(&p1, &p2, &calculated_slope, &calculated_bias);

    
    printf("\nCalculated Output. line equation:\n");
    printf("slope: %.4lf\n", calculated_slope);
    printf("bias: %.4lf\n", calculated_bias);

    return 0;
}