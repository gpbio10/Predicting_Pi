#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUMBEROFPOINTS 10000000

/*  This is a pi predictor that uses linked lists
 *  to remove the limit of data points that can be used
 *  compared to that of an array. The NUMBEROFPOINTS is
 *  set to the highest my computer could handle but I'm
 *  sure 1-2 orders of magnitude could be added if you
 *  have some decent computing power. This method of
 *  prediction is a Monte Carlo Experiment which just
 *  uses as many possible data points to simulate outcomes.
 *
 *  In this case two random x and y coordinates were generated
 *  to represent a point on a graph with a domain and range of
 *  -1 to 1. The magnitude of the line to the point from the
 *  origin is then calculated to see what points would land
 *  in a circle with a radius 1. Pi is finally calculated with
 *  the equation (4 * Number of Points in the Circle) / (Total
 *  Number of Points).
 */


//Created the Linked List Node
struct Node {
    float x_coordinate;     //x and y coordinated stored at each node
    float y_coordinate;
    float distance;         //Value for euclidean distance
    struct Node *next;
};

void add(struct Node **head, float new_x, float new_y) {
    //Get memory for node with malloc
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    //Set x and y coordinates to inputed data
    new_node->x_coordinate = new_x;
    new_node->y_coordinate = new_y;

    //Next node
    new_node->next = *head;

    //Set pointer of head to new node
    *head = new_node;
} //push()

void printCoordinates(struct Node *node) {
    if (!node) {
        return;
    }
    while (node->next != NULL) {
        printf("%f %f\n", node->x_coordinate, node->y_coordinate);
        node = node->next;
    }
} //printCoordinates()

void printDistance(struct Node *node) {
    if (!node) {    //If there is a valid node
        return;     //If not exit
    }
    while (node->next != NULL) {    //While not the last node in the LL
        printf("%f\n", node->distance);     //Prints the distance
        node = node->next;                  //next Node
    }
} //printDistance()

int sumInCircle = 0;
void distanceCalc(struct Node *node) {
    if (!node) {    //Verify valid node
        return;
    }
    while (node->next != NULL) {
        float x = node->x_coordinate;   //Sets coordinates while not the last node in LL
        float y = node->y_coordinate;
        float sumOfSquares = (x*x) + (y*y); //Square x and y then add
        node->distance = sqrt(sumOfSquares);    //Square root to find distance from origin

        if (node->distance <= 1) {      //If inside the circle with radius of 1
            sumInCircle++;  //Increment count of points inside the circle
        }

        node = node->next;  //Next node

    }
} //distanceCalc()


float randInRange() {
    //Get rand value from -1 to 1
    return ((rand() % 10000) / 5000.0) - 1.0;
}  //randInRange()

int main() {

    //Initialize linked list node
    struct Node *start = NULL;

    //Initialize clock and start timer
    clock_t t;
    t = clock();

    //Reset random number generator
    srand(time(0));

    for (int i = 0; i < NUMBEROFPOINTS; i++) {  //For from 0 to the total number of points desired
        add(&start, randInRange(), randInRange());  //Add random value to x and y to a node
    }

    distanceCalc(start);    //Calc distance from origin from function


    //Can use these following statements to see all random values calculated
    /* ----- */

    //printCoordinates(start);
    //printDistance(start);

    /* ----- */

    printf("Points inside the circle:\t%d points.\nTotal Points:\t\t\t\t%d points.\n", sumInCircle, NUMBEROFPOINTS);

    /*  From Monte Carlo experiment,
     *
     *             4 * (Num inside Circle)
     *     PI =   ------------------------
     *              Total Num of Points
     *
     */

    printf("Calculated value of PI:\t\t%f\n", 4 * (double)sumInCircle / (double)NUMBEROFPOINTS);

    //End timer
    t = clock() - t;
    //Print time taken to console
    printf("Completed in:\t\t\t\t%f seconds.", (double)t / CLOCKS_PER_SEC);

} //main()
