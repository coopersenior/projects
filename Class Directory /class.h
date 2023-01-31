typedef struct {
        char cnumber[15];
	char ctitle[60];
	char cdays[10];
	char ctime[15];
	char cseats[5];
	char cprof[45];
} Class;

void printClass(Class);
void printOptions();
void userOptions(Class[], int);
int fillStruct(Class[]);
void findClass(Class[], int);
void classesAvailable(Class[], int);
void classesTaught(Class[], int);


