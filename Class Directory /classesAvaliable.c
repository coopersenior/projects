#include "class.h"
#include <string.h>
#include <stdio.h>

void classesAvailable(Class classes[], int length) {
        while ((getchar()) != '\n');  // clear the buffer for next scanf
        char days[10];
        printf("Enter class days to print (MWF or TR): ");
        scanf ("%[^\n]%*c", days);  // reads in full string with spaces
        printf("List of classes for days %s:\n", days);
        for (int i = 0; i < length; i++) {    // checks all classes in struct for match
                if (strcmp(days, classes[i].cdays) == 0) {  // uses string compare to check for match
                       printClass(classes[i]);   // if found, calls function to print info and sends in
						 // index of desired class
                }
        }
}

