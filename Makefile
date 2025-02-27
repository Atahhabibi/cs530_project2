CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -Iinclude
TARGET = essy

SRC = src/main.cpp src/assembler.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
