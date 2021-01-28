#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Can be used to calculate PI but has max value of 1000000.
//Used linked list data structure for more accurate estimation of PI

#define NUMBEROFPOINTS 1000000

float random() {
    return ((rand() % 10000) / 5000.0) - 1;
} //random()

void printDataPoints(float x_coordinates[], float y_coordinates[]) {
    printf("Random Points between 0 and 1 to represent points on a graph for and domain and range of 0 to 1.\nX\t\t\tY\n");
    for (int i = 0; i < NUMBEROFPOINTS; i++) {
        printf("%f\t%f\n", x_coordinates[i], y_coordinates[i]);
    }
} //printDataPoints()

int checkDistance(float x, float y) {
    float sumOfSquares = (x*x) + (y*y);
    //printf("%f\n", sumOfSquares);
    if (sqrt(sumOfSquares) <= 1.0) {
        return 1;
    } else {
        return 0;
    }
} //checkDistance()

int main() {

    float x_coordinate[NUMBEROFPOINTS];
    float y_coordinate[NUMBEROFPOINTS];

    int numInsideCircle = 0.0;

    srand(time(0));
    for (int i = 0; i < NUMBEROFPOINTS; i++) {
        x_coordinate[i] = random();
        y_coordinate[i] = random();

        if (checkDistance(x_coordinate[i], y_coordinate[i]) == 1) {
            numInsideCircle++;
        }
    }

    //printDataPoints(x_coordinate, y_coordinate);

    printf("%d\n", numInsideCircle);
    float pi = 4 * (float)numInsideCircle / (float)NUMBEROFPOINTS;

    printf("%f", pi);

} //main()
