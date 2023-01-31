#include "class.h"
/*
 * Program 1, CSCI 112, Spring 2022
 * Author name: Cooper Senior
 */

int main(void) {
        Class classes[50];    // sets up more than enought space
        int length = fillStruct(classes); // returns how many classes there are
        userOptions(classes, length);  // passes in the array of structs and how many there are
        return(0);
}

