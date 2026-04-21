TARGET    := kenko
SRC_DIR   := ./src
OBJ_DIR   := ./obj

SRCS := $(shell find $(SRC_DIR) -name '*.c') 
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC      := clang
CSTD    := c11
CFLAGS  := -std=$(CSTD) -g3 -Wall -Wextra -Wconversion   \
		   -Wdouble-promotion -Wno-unused-parameter      \
		   -Wno-unused-function -Wno-sign-conversion     \
		   -fsanitize=undefined -fsanitize-trap -pedantic
LDFLAGS := 

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

