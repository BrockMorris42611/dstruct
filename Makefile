CC = gcc
CFLAGS = -Wall -Wextra -g

# Object files for LinkedList.c and testLinkedList.c
OBJ = LinkedList.o testLinkedList.o

# Executable name
TARGET = testLinkedList

# Compile and link
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile LinkedList.c
LinkedList.o: LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

# Compile testLinkedList.c
testLinkedList.o: testLinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c testLinkedList.c

# Clean
clean:
	rm -f *.o