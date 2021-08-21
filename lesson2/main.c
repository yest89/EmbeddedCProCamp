/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define BOUND 4
int array_length = 0;
int top = -1;

int main() {
	
    //TASK#1
    int arr[] = { 10, 324, 45, 90, 9808 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The biggest in given array is %d", find_biggest_element(arr, n));

    printf("\n***************************************************\n");
    //TASK#2

    Node* head = NULL;
    
    int i;
    for (i = 0; i < 10; i++) {
        head = add_element(i * i, head);
    }

    print_list(head);

    printf("\n***************************************************\n");
    //TASK#3

    int* array;
    array = create_new(array);
    for (i = 0; i < array_length; i++) {
        array[i] = i * i;
    }

    printf("\nElements of array: ");
    for (i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }

    printf("\nElements of first occurence in the array: %d", find_first(array, 4));

    array = remove_array_element(array, 2);

    printf("\nElements of array after removing: ");
    for (i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }

    return 0;

}

//Task#1
int find_biggest_element(int arr[], int n)
{
    int i;

    int max = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

//Task#2
Node* add_element(int value, Node* head) {
    Node* new_node = NULL;
    Node* last = NULL;

    new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return head;
    }

    last = head;
    while (last->next) last = last->next;
    last->next = new_node;
    return head;
}

void print_list(Node* head) {
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
}

Node* remove_element(int value, Node* head) {
    Node* current_node = head;
    Node* prev_node;
    int cnt = 0;
    while (current_node != NULL) {
        if (current_node->data == value) {
            if (current_node == head) {
                head = current_node->next;
            }
            else {
                prev_node->next = current_node->next;
            }
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    return(head);
}

bool contains_element(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

void free_list(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

//Task#3
int find_first(int arr[], int x)
{
    int first = -1;
    int i;
    for (i = 0; i < array_length; i++) {
        if (x != arr[i])
                continue;
        if (first == -1)
                first = i;
    }
    return (first != -1) ? first : -1;
}


int* create_new(int* a)
{
    int* new_a = (int*)malloc((array_length + BOUND) * sizeof(float));

    for (int i = 0; i < array_length; i++)
        new_a[i] = a[i];

    array_length += BOUND;
    return new_a;
}

// function to push new element
int* push(int* a, int element)
{
    if (top == array_length - 1)
            a = create_new(a);

    a[++top] = element;
    return a;
}

int* remove_array_element(int * arr, int index)
{
    int i;
    /* Invalid delete position */
    if (index < 0 || index > array_length)
            printf("Invalid position! Please enter position between 1 to %d", array_length);
    else {
        for (i = index - 1; i < array_length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        array_length--;
    }
    return arr;
}

