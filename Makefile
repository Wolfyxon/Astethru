SRC := src
BUILD := build

CC := gcc
CFLAGS := `sdl2-config --libs --cflags` -Wall -lSDL2_image -lm

SOURCES := $(SRC)/main.c $(SRC)/sprite/sprite.c

OBJECTS := $(SOURCES:.c=.o)
BIN := $(BUILD)/astethru

.PHONY: all
all: ${BIN}

.PHONY: run
run: $(BIN)
	$(BIN)

.PHONY: clean
clean:
	rm -rf $(BUILD)

$(BUILD):
	mkdir $(BUILD)

$(BIN): $(OBJECTS)
	$(CC) $(BUILD)$(OBJECTS) -o $@ $(CFLAGS)

$(OBJECTS): $(@:.o=.c) $(BUILD)
	$(CC) $(SRC)$(@:.o=.c) -o $(BUILD)$@ -c $(CFLAGS)

