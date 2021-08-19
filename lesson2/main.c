/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

//Task#1
int findBiggestElement(int arr[], int n) {
    int i;

    int max = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

typedef enum { false, true } bool;

//Task#2
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* addElement(int value, Node* head);
void printList(Node* head);
Node* removeElement(int value, Node* head);
bool containsElement(Node* head, int x);
void freeList(Node* head);


int main() {
	
    //TASK#1
    int arr[] = { 10, 324, 45, 90, 9808 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The biggest in given array is %d", findBiggestElement(arr, n));

    printf("\n***************************************************\n");
    //TASK#2

    Node* head = NULL;
    
    int i;
    for (i = 0; i < 10; i++) {
        head = addElement(i * i, head);
    }

    printList(head);



    return 0;

}


Node* addElement(int value, Node* head) {
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

void printList(Node* head) {
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
}

Node* removeElement(int value, Node* head) {
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

bool containsElement(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

