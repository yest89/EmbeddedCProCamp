/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

#include "function_declaration.h"

#define FEET2CM  30.48f
#define INCHTOCM 2.54f
#define INONEMETER 100.0f
#define PI 3.14

#define THREEBITES 3
#define TWOBITES 2
#define FIVEBITES 5
#define ELEVENBITES 11

int main()
{

    float widthInMeters = 0.0f;
    float heightInMeters = 0.0f;

    float widthInInches = 0.0f;
    float heightInInches = 0.0f;

    printf("******************************************\n");
    printf("Enter your input for height(meters):");
    if (1 != scanf("%f", &widthInMeters)) {
            perror("scanf failed");
            return 0;
    }

    heightInInches = convert_meters_in_inches(heightInMeters);
    widthInInches = convert_meters_in_inches(widthInMeters);

    print_rectangle_perimeter(calculate_rectangle_perimeter(heightInInches, widthInInches), heightInInches, widthInInches);
    print_rectangle_area(calculate_rectangle_area(heightInInches, widthInInches), heightInInches, widthInInches);


    float radius = 6; // can be non decimal
    print_circle_perimeter(calculate_circle_perimeter(radius), radius);
    print_circle_area(calculate_circle_area(radius), radius);

    unsigned int number = 10;
    print_factorial(factorial(number), number);

    print_numbers_divided_by_number(5);

    return 0;
}

void print_numbers_divided_by_number(unsigned int number)
{
    printf("-----------------------------------------------------------\n");
    int i = 1;
    for (i = 1; i < 500; i++)
            if (i % number == 0)
                    printf("%i ", i);

    printf("\n-----------------------------------------------------------\n");
}

void print_factorial(unsigned int factorial, unsigned int number)
{
    printf("-----------------------------------------------------------\n");
    printf("Factorial = %f for number: %f\n", factorial, number);
    printf("-----------------------------------------------------------\n");
}

unsigned int factorial(unsigned int n)
{
    if (n == 0)
            return 1;

    return n * factorial(n - 1);
}

uint16_t convert_rgb888_to_rgb565(uint8_t *rgb888Pixel)
{
    if (rgb888Pixel == NULL)
            return 0;

    uint8_t red = rgb888Pixel[0];
    uint8_t green = rgb888Pixel[1];
    uint8_t blue = rgb888Pixel[2];

    uint16_t b = (blue >> THREEBITES) & 0x1f;
    uint16_t g = ((green >> TWOBITES) & 0x3f) << FIVEBITES;
    uint16_t r = ((red >> THREEBITES) & 0x1f) << ELEVENBITES;

    return (uint16_t)(r | g | b);
}

uint16_t swap_uint16(uint16_t val)
{
    return (val << 8) | (val >> 8);
}

uint32_t swap32(uint32_t val)
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | (val >> 16);
}

uint64_t swap64(uint64_t val)
{
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL) | ((val >> 8) & 0x00FF00FF00FF00FFULL);
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL) | ((val >> 16) & 0x0000FFFF0000FFFFULL);
    return (val << 32) | (val >> 32);
}


float convert_meters_in_inches(float meters)
{
    if (meters == 0.0)
            return 0.0;

    float feet = 0.0f;
    float centimeter = meters * INONEMETER;
    if (centimeter >= FEET2CM) {
            while (1) {
                    feet++;
                    centimeter = centimeter - FEET2CM;
                    if (centimeter < FEET2CM) break;
            }
    }
    return centimeter / INCHTOCM;
}

float calculate_rectangle_perimeter(float height, float width)
{
    return 2 * (height + width);
}

float calculate_rectangle_area(float height, float width)
{
    return height * width;
}

void print_rectangle_perimeter(float rectanglePerimeter, float height, float width)
{
    printf("-----------------------------------------------------------\n");
    printf("Rectangle Perimeter =  %f(inches) for height: %f and width: %f\n", rectanglePerimeter, height, width);
    printf("-----------------------------------------------------------\n");
}

void print_rectangle_area(float rectangleArea, float height, float width)
{
    printf("-----------------------------------------------------------\n");
    printf("Rectangle Area =  %f(inches) for height: %f and width: %f\n", rectangleArea, height, width);
    printf("-----------------------------------------------------------\n");
}

float calculate_circle_perimeter(float radius)
{
    return 2 * PI * radius;
}
float calculate_circle_area(float radius)
{
    return PI * radius * radius;
}

void print_circle_perimeter(float circlePerimeter, float radius)
{
    printf("-----------------------------------------------------------\n");
    printf("Circle Area =  %f for radius: %f\n", circlePerimeter, radius);
    printf("-----------------------------------------------------------\n");
}

void print_circle_area(float circleArea, float radius)
{
    printf("-----------------------------------------------------------\n");
    printf("Circle Area =  %f for radius: %f\n", circleArea, radius);
    printf("-----------------------------------------------------------\n");
} 