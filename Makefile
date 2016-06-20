TARGET = stegowav
LIBS = -lm -lssl -lcrypto
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(shell find . -name '*.c')
HEADERS = $(wildcard */*.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	find . -type f -name '*.o' -delete
	-rm -f $(TARGET)