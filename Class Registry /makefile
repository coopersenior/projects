CC = g++

EXEC_NAME = pgm2 

LDFLAGS = 
CFLAGS = -Wall

HEADERS = $(wildcard *.h)
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

$(EXEC_NAME).exe: $(OBJ)
	@echo "Linking to make executable"
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	@echo "Compiling"
	$(CC) $(CFLAGS) -c $<

