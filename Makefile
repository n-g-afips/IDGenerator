CXX = gcc
CXXFLAGS = 
LDFLAGS =  

SRC = numerals.c main.c
OBJ = $(SRC:.cc=.o)
EXEC = idgenerator

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)