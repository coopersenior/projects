#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "class.h"

void classesTaught(Class classes[], int length) {
        while ((getchar()) != '\n');  // clear the buffer for next scanf
        char prof[20];
        char temp[45];
        printf("Enter Professor's Last Name: ");
        scanf ("%[^\n]%*c", prof);  // reads in full string with spaces
        printf("List of classes for Professor %s:\n", prof);
        for (int i = 0; i < length; i++) {  // checks through all options
                char *result;
                strcpy(temp, classes[i].cprof); // temp so orinal data not affected
                result = strtok(temp, " ");
                if (strcmp(result, prof) == 0) {   // string compare to check for match with user entered
                       printClass(classes[i]);  // class print function
                }
        }
}


