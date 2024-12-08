SRC := src
BUILD := build

CC := gcc
CFLAGS := `sdl2-config --libs --cflags` -Wall -lSDL2_image -lm

SOURCES := $(SRC)/main.c $(SRC)/sprite/sprite.c

OBJECTS := $(SOURCES:$(SRC)/%.c=$(BUILD)/%.o)
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
	mkdir -p $(BUILD)
	mkdir -p $(BUILD)/sprite

$(BIN): $(OBJECTS) | $(BUILD)
	$(CC) $(OBJECTS) -o $@ $(CFLAGS)

$(BUILD)/%.o: $(SRC)/%.c | $(BUILD)
	$(CC) -c $< -o $@ $(CFLAGS)
