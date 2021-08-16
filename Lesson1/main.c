/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define FEET2CM  (30.48f)
#define INCHTOCM (2.54f)

uint16_t swap_uint16(uint16_t val);
uint32_t swap32(uint32_t val);
uint64_t swap64(uint64_t val);

uint16_t rgb888toRgb565(uint8_t* rgb888Pixel);

float convertMetersInInches(float meters);
float calculateRectanglePerimeter(float height, float width);
float calculateRectangleArea(float height, float width);
void printRectanglePerimeter(float rectanglePerimeter, float height, float width);
void printRectangleArea(float rectangleArea, float height, float width);

float calculateCirclePerimeter(float radius);
float calculateCircleArea(float radius);
void printCirclePerimeter(float circlePerimeter);
void printCircleArea(float circleArea);

unsigned int factorial(unsigned int n);
void printFactorial(unsigned int factorial, unsigned int number);

void printNumbersDividedByNumber(unsigned int number);

int main() {

    float widthInMeters = 0.0f;
    float heightInMeters = 0.0f;

    float widthInInches = 0.0f;
    float heightInInches = 0.0f;

    printf("Enter your input for height(meters):");
    if (1 != scanf("%f", &heightInMeters)) {
        perror("scanf failed");
        exit(EXIT_FAILURE);
    }
    printf("******************************************");
    printf("Enter your input for height(meters):");
    if (1 != scanf("%f", &widthInMeters)) {
        perror("scanf failed");
        exit(EXIT_FAILURE);
    }
   
    heightInInches = convertMetersInInches(heightInMeters);
    widthInInches = convertMetersInInches(widthInMeters);
    
    printRectanglePerimeter(calculateRectanglePerimeter(heightInInches, widthInInches));
    printRectangleArea(calculateRectangleArea(heightInInches, widthInInches));
    

    float radius = 6; // can be non decimal
    printCirclePerimeter(calculateCirclePerimeter(radius), radius);
    printCircleArea(calculateCircleArea(radius), radius);

    unsigned int number = 10;
    printFactorial(factorial(number), number);

    printNumbersDividedByNumber(5);

    return 0;
}

void printNumbersDividedByNumber(unsigned int number) {
    printf("-----------------------------------------------------------\n");
    int i = 1;
    for (i = 1; i < 500; i++) {
        if (i % number == 0) {
            printf("%i", i);
        }
    }
    printf("\n-----------------------------------------------------------\n");
}

void printFactorial(unsigned int factorial, unsigned int number) {
    printf("-----------------------------------------------------------\n");
    printf("Factorial = %f for number: %f\n", factorial, number);
    printf("-----------------------------------------------------------\n");
}

unsigned int factorial(unsigned int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

uint16_t rgb888toRgb565(uint8_t* rgb888Pixel) {
    uint8_t red = rgb888Pixel[0];
    uint8_t green = rgb888Pixel[1];
    uint8_t blue = rgb888Pixel[2];

    uint16_t b = (blue >> 3) & 0x1f;
    uint16_t g = ((green >> 2) & 0x3f) << 5;
    uint16_t r = ((red >> 3) & 0x1f) << 11;

    return (uint16_t)(r | g | b);
}

uint16_t swap_uint16(uint16_t val) {
    return (val << 8) | (val >> 8);
}

uint32_t swap32(uint32_t val) {
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | (val >> 16);
}

uint64_t swap64(uint64_t val) {
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL) | ((val >> 8) & 0x00FF00FF00FF00FFULL);
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL) | ((val >> 16) & 0x0000FFFF0000FFFFULL);
    return (val << 32) | (val >> 32);
}


float convertMetersInInches(float meters) {
    float feet = 0.0f;
    float centimeter = meters * 100.0f;
    if (centimeter >= FEET2CM) {
        while (1) {
            feet++;
            centimeter = centimeter - FEET2CM;
            if (centimeter < FEET2CM)
                break;
        }
    }
    return centimeter / INCHTOCM;
}

float calculateRectanglePerimeter(float height, float width) {
    return 2 * (height + width);
}

float calculateRectangleArea(float height, float width) {
    return height * width;
}

void printRectanglePerimeter(float rectanglePerimeter, float height, float width) {
    printf("-----------------------------------------------------------\n");
    printf("Rectangle Perimeter =  %f(inches) for height: %f and width: %f\n", rectanglePerimeter, height, width);
    printf("-----------------------------------------------------------\n");
}

void printRectangleArea(float rectangleArea, float height, float width) {
    printf("-----------------------------------------------------------\n");
    printf("Rectangle Area =  %f(inches) for height: %f and width: %f\n", rectangleArea, height, width);
    printf("-----------------------------------------------------------\n");
}

float calculateCirclePerimeter(float radius) {
    return 2 * 3.14 * radius;
}
float calculateCircleArea(float radius) {
    return 3.14 * radius * radius;
}

void printCirclePerimeter(float circlePerimeter, float radius) {
    printf("-----------------------------------------------------------\n");
    printf("Circle Area =  %f for radius: %f\n", circlePerimeter, radius);
    printf("-----------------------------------------------------------\n");
}

void printCircleArea(float circleArea, float radius) {
    printf("-----------------------------------------------------------\n");
    printf("Circle Area =  %f for radius: %f\n", circleArea, radius);
    printf("-----------------------------------------------------------\n");
}