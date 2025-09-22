#include <stdio.h>

#define COURSE_TITLE "C Programming"
#define COURSE_VERSION 1
#define COURSE_YEAR 2025
#define PI_VALUE 3.1415926535
int main() {
    const char* demo_title = "printf"; 
    const int width_number = 123;      
    const char sample_char = 'A';      
    const char backslash_char = '\\';

    printf("=== Constants & Formats ===\n");
    printf("Course: %s (v%d, %d)\n", COURSE_TITLE, COURSE_VERSION, COURSE_YEAR); 
    printf("Title : C \"%s\" demo\n", demo_title); 
    printf("PI default \t: %.6f\n", PI_VALUE);       
    printf("PI 2 digits \t: %.2f\n", PI_VALUE);

    printf("Width demo \t: [      %d]\n", width_number); 

    printf("Char sample \t: %c\n", sample_char);     
    printf("Backslash \t: %c\n", backslash_char);
    

	return 0;
}