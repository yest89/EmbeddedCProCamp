#ifndef _FUNCTION_DECLARATION_H_
#define _FUNCTION_DECLARATION_H_

/*
swap bytes for uint16_t 
*/
uint16_t swap_uint16(uint16_t val);
/*
swap bytes for uint32_t 
*/
uint32_t swap32(uint32_t val);
/*
swap bytes for uint64_t 
*/
uint64_t swap64(uint64_t val);

/*
convert   rgb888 to rgb565
*/
uint16_t convert_rgb888_to_rgb565(uint8_t *rgb888Pixel);

/*
convert   meters to inches
*/
float convert_meters_in_inches(float meters);
/*
calculate rectangle perimeter
*/
float calculate_rectangle_perimeter(float height, float width);
/*
calculate rectangle area
*/
float calculate_rectangle_area(float height, float width);
/*
print rectangle perimeter
*/
void print_rectangle_perimeter(float rectanglePerimeter, float height, float width);
/*
print rectangle area
*/
void print_rectangle_area(float rectangleArea, float height, float width);

/*
calculate circle perimeter
*/
float calculate_circle_perimeter(float radius);
/*
calculate circle area
*/
float calculate_circle_area(float radius);
/*
print circle perimeter
*/
void print_circle_perimeter(float circlePerimeter, float radius);
/*
print circle area
*/
void print_circle_area(float circleArea, float radius);

/*
calculate factorial by number
*/
unsigned int factorial(unsigned int n);
/*
print factorial for number
*/
void print_factorial(unsigned int factorial, unsigned int number);
/*
print numbers which divided by number
*/
void print_numbers_divided_by_number(unsigned int number);


#endif