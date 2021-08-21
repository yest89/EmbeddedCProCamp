#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"

int find_biggest_element(int arr[], int n);

Node* add_element(int value, Node* head);
void print_list(Node* head);
Node* remove_element(int value, Node* head);
bool contains_element(Node* head, int x);
void free_list(Node* head);

int find_first(int arr[], int x);
int* create_new(int* a);
int* push(int* a, int element);
int* remove_array_element(int * arr, int index);

#endif