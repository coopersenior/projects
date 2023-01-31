#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "class.h"

// finds the class based on user entered class number
void findClass(Class classes[], int length) {
        while ((getchar()) != '\n');  // clear the buffer for next scanf
        char cnum[15];
        printf("Enter class number: ");
        scanf ("%[^\n]%*c", cnum);  // reads in full string with spaces
        for (int i = 0; i < length; i++) {
                if (strcmp(cnum, classes[i].cnumber) == 0) {  // string compare to find class
                       printClass(classes[i]);
                       break;    // only want one so if found we stop searching
                }
        }
}


