TARGET = stegowav
LIBS = -l
CC = gcc
CFLAGS = -g 

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(shell find . -name '*.c')
HEADERS = $(wildcard */*.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

clean:
	find . -type f -name '*.o' -delete
	-rm -f $(TARGET)
