/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1000  // Stack maximum capacity
#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

char *copy_string(char *destination, char *source);

struct stack
{
    int data;
    struct stack* next;
} *top;

unsigned int size = 0;

//TASK#2
void push(int element);
int  pop();

//TASK#3
int queue[CAPACITY];
unsigned int rear = CAPACITY - 1;
unsigned int front = 0;

int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();

//TASK#4
int cube(int i);
void apply_enumerate(int* arr, size_t len, int (*fnPtr)(size_t, int));
int mult(size_t i, int j);
void print_array(int* arr, size_t len, char* sep);
void apply(int* arr, size_t len, int (*fnPtr)(int));

int main() {
	
    char string1[20];
    char string2[20];

    printf("Enter first string: ");
    gets(string1);

    printf("Enter second string: ");
    gets(string2);

    printf("\nCopying first string into second... \n\n");
    copy_string(string2, string1); // copy the contents of string1 to string2

    printf("First string (string1) = %s\n", string1);
    printf("Second string (string2) = %s\n", string2);

    printf("\nCopying \"My string\" string into string1 ... \n");
    copy_string(string1, "My string"); // copy My string to string1

    printf("First string (string1) = %s\n", string1);
    printf("Second string (string2) = %s\n", string2);

    //TASK#2
    int data = 5;
    push(data);
    data = 47;
    push(data);
    int result = pop();
    printf("Pop elemenr = %d\n", result);


    //TASK#3
    data = 989;
    if (enqueue(data))
            printf("Element added to queue.\n");
    else
            printf("Queue is full.\n");

    data = dequeue();
    if (data == INT_MIN)
            printf("Queue is empty.\n");
    else
            printf("Data => %d\n", data);


    //TASK#4
    int arr[5] = { 1,2,3,4,5 };
    print_array(arr, ARRAY_SIZE(arr), NULL);
    apply(arr, ARRAY_SIZE(arr), cube);
    print_array(arr, ARRAY_SIZE(arr), NULL);
    apply_enumerate(arr, ARRAY_SIZE(arr), mult);
    print_array(arr, ARRAY_SIZE(arr), NULL);

    return 0;

}

/**
 * Function copy one string into another one
 */
char *copy_string(char *destination, char *source)
{
    if (source == NULL)
            return NULL;

    char *start = destination;

    while (*source != '\0'){
            *destination = *source;
            destination++;
            source++;
    }

    *destination = '\0'; // add '\0' at the end
    return start;
}

/**
 * Functiont to push a new element in stack.
 */
void push(int element)
{
    if (size >= CAPACITY) {
            printf("Can't add more element to stack.\n");
            return;
    }

    struct stack* newNode = (struct stack*)malloc(sizeof(struct stack));

    newNode->data = element;
    newNode->next = top;
    top = newNode;
    size++;

    printf("Data pushed to stack.\n");
}


/**
 * Function to pop element from top of stack.
 */
int pop()
{
    int data = 0;
    struct stack* topNode;

    if (size <= 0 || !top) {
            printf("Stack is empty.\n");
            return INT_MIN;
    }

    topNode = top;
    data = top->data;
    top = top->next;
    free(topNode);
    size--;

    return data;
}


//TASK#3
/**
 * Checks if queue is full or not. It returns 1 if queue is full,
 * overwise returns 0.
 */
int isFull()
{
    return (size == CAPACITY);
}

/**
 * Checks if queue is empty or not. It returns 1 if queue is empty,
 * otherwise returns 0.
 */
int isEmpty()
{
    return (size == 0);
}


/**
 * Enqueue/Insert an element to the queue.
 */
int enqueue(int data)
{
    if (isFull())
            return 0;

    rear = (rear + 1) % CAPACITY;
    size++;
    queue[rear] = data;
    return 1;
}


/**
 * Dequeue/Remove an element from the queue.
 */
int dequeue()
{
    int data = INT_MIN;

    if (isEmpty())
            return INT_MIN;

    data = queue[front];
    front = (front + 1) % CAPACITY;
    size--;
    return data;
}


//TASK#4
int cube(int i)
{
    return i * i * i;
};

int mult(size_t i, int j)
{
    return i * j;
};

void apply(int* arr, size_t len, int (*fnPtr)(int))
{
    for (size_t i = 0; i < len; ++i)
            arr[i] = fnPtr(arr[i]);
};

void apply_enumerate(int* arr, size_t len, int (*fnPtr)(size_t, int))
{
    for (size_t i = 0; i < len; ++i)
            arr[i] = fnPtr(i, arr[i]);
};

void print_array(int* arr, size_t len, char* sep)
{
    if (sep == NULL) sep = ", ";
    printf("%d", *arr);
    for (size_t i = 1; i < len; ++i)
            printf("%s%d", sep, arr[i]);
    printf("\n");
};