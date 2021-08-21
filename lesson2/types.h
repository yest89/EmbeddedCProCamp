#ifndef TYPES_H
#define TYPES_H

typedef enum { false, true } bool;

typedef struct node {
    int data;
    struct node* next;
} Node;


#endif