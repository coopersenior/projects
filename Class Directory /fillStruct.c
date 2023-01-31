#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "class.h"

int fillStruct(Class classes[]) {
        // open the file
        FILE *fptr = fopen("/public/pgm1/classes.csv", "r");
        // check that the file is open (not NULL)
        if (fptr == NULL) {
                printf("bad file");
                exit(1);
        }
        char line[100];   // might need more length
        int i = 0;
        char *result; // char pointer into line of the string

        while (1) {   // while true creating infinite loop
                if (fgets(line, 100, fptr) == NULL) {
                        // printf("%d %s",i, "breaking");
                        break;
                }
                result = strtok(line, ",");
                strcpy(classes[i].cnumber, result); // put class number in struct
                result = strtok(NULL, ",");
                strcpy(classes[i].ctitle, result); // put class title in
                result = strtok(NULL, ",");  // skips unused info
                result = strtok(NULL, ",");
                strcpy(classes[i].cseats, result); // put class seats number
                result = strtok(NULL, ","); // skips 0
                result = strtok(NULL, ","); // skips repeated seat number
                result = strtok(NULL, ",");
                strcpy(classes[i].cprof, result);  // put professor name
                result = strtok(NULL, " ");
                strcpy(classes[i].cdays, result);   // puts in days of class
                result = strtok(NULL, "\n");
                strcpy(classes[i].ctime, result);   // puts in time of class
                i++;
        }
        fclose(fptr);
        return(i);  // used to keep track of the number of structs in the array
}
