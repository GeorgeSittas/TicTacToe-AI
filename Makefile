OBJ_DIR = ./src
INC_DIR = ./include

CFLAGS = -Wall -I$(INC_DIR)
CC = gcc

OBJS = $(OBJ_DIR)/main.o  $(OBJ_DIR)/tic_tac_toe.o \
       $(OBJ_DIR)/board.o $(OBJ_DIR)/utilities.o

EXEC = tic_tac_toe

ifeq ($(USER), first)
  PARAMS += -x
endif

# The @ character is used to silence make's output

$(EXEC): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

.SILENT: $(OBJS) # Silence implicit rule output
.PHONY: clean

play: $(EXEC)
	@./$(EXEC) $(PARAMS)

clean:
	@echo "Cleaning up .."
	@rm -f $(OBJS) $(EXEC)
