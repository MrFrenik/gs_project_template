# Makefile for gunslinger

# options
CC     = gcc
DDEBUG = gdb
LINKER = $(CC)
CFLAGS =  -Os -pthread
LFLAGS = -ldl -lX11 -lXi -lm -lpthread

# directories
TARGET   = App
SRC_DIR  = ../../source
BIN_DIR  = ../../bin
INCLUDE  = -I ../../third_party/include/
OBJ_DIR  = $(BIN_DIR)/.obj

# Finds source files two directories deep
HEADERS  = $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/*/*.h)
SOURCES  = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJ      = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: build

build: $(BIN_DIR) $(BIN_DIR)/$(TARGET)

$(BIN_DIR):
	mkdir -p $@

# compile
$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(INCLUDE) -c $(CFLAGS) $< -o $@

# link
$(BIN_DIR)/$(TARGET): $(OBJ)
	$(LINKER) $(OBJ) $(LFLAGS) -o $@

run: build
	./$(BIN_DIR)/$(TARGET)

debug: build
	$(DEBUGGER) $(BIN_DIR)/$(TARGET)

clean:
	rm -f $(OBJ)
	rm -f $(BIN_DIR)/$(TARGET)

.PHONY: all build run debug clean
