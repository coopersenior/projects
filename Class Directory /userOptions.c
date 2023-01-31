#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "class.h"

void userOptions(Class classes[], int length) {
        char opt;

        do {
                printOptions();
                scanf("%c", &opt); // ask user for choice
                // read in choice as a char and read in new line
                switch(opt) {
                        case 'n':
                                findClass(classes, length);    // calls correct function based on
							       // entered char
                                break;
                        case 'd':
                                classesAvailable(classes, length);
                                break;
                        case 'p':
                                classesTaught(classes, length);
                                break;
                }
        } while (opt != 'q'); // loops on options until user wants to quit
}
