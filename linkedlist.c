#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUMBEROFPOINTS 10

struct Node {
    int *data;

    struct Node *next;
};

void add(struct Node **head_ref, void *new_data, size_t data_size) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = malloc(data_size);
    new_node->next = (*head_ref);

    int i;
    for (i = 0; i < data_size; i++) {
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    }

    (*head_ref) = new_node;
}

void printList(struct Node *node, void (*fptr)(void *))
{
    while (node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}

double randInRange() {
    return ((rand() % 10000) / 5000.0) - 1;
}

void printDataPoints(double x_coordinates[], double y_coordinates[]) {
    printf("Random Points between 0 and 1 to represent points on a graph for and domain and range of 0 to 1.\nX\t\t\tY\n");
}

int checkDistance(double x, double y) {
    double sumOfSquares = (x*x) + (y*y);
    //printf("%f\n", sumOfSquares);
    if (sqrt(sumOfSquares) <= 1.0) {
        return 1;
    } else {
        return 0;
    }
}

void printInt(void *n) {
    printf(" %d", *(int *) n);
}


int main() {

    struct Node *start = NULL;

    unsigned int_size = sizeof(int);

    double x[NUMBEROFPOINTS];

    for (int i = 0; i < NUMBEROFPOINTS; i++) {
        x[i] = randInRange();
        //printf(" %f", x[i]);
        add(&start, &x[i], int_size);
    }
    printList(start, printInt);

}
