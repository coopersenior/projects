#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "class.h"

// prints the class information from the struct in requested format
void printClass(Class class) {
        printf("%-40s%-15s%-30s%-6s%-6s%-6s\n", class.ctitle, class.cnumber, class.cprof, class.cseats, class.cdays, class.ctime);
}
