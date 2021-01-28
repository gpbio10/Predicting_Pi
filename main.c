#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUMBEROFPOINTS 100000

double randInRange() {
    return ((rand() % 10000) / 5000.0) - 1;
}

void printDataPoints(double x_coordinates[], double y_coordinates[]) {
    printf("Random Points between 0 and 1 to represent points on a graph for and domain and range of 0 to 1.\nX\t\t\tY\n");
    for (int i = 0; i < NUMBEROFPOINTS; i++) {
        printf("%f\t%f\n", x_coordinates[i], y_coordinates[i]);
    }
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

int main() {

    double x_coordinate[NUMBEROFPOINTS];
    double y_coordinate[NUMBEROFPOINTS];

    int numInsideCircle = 0.0;

    srand(time(0));
    for (int i = 0; i < NUMBEROFPOINTS; i++) {
        x_coordinate[i] = randInRange();
        y_coordinate[i] = randInRange();

        if (checkDistance(x_coordinate[i], y_coordinate[i]) == 1) {
            numInsideCircle++;
        }
    }

    //printDataPoints(x_coordinate, y_coordinate);

    printf("%d\n", numInsideCircle);
    double pi = 4 * (double)numInsideCircle / (double)NUMBEROFPOINTS;

    printf("%f", pi);

}
