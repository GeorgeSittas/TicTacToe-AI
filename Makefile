object_files = ./src/main.o ./src/tic_tac_toe.o ./src/board.o ./src/utilities.o
header_files = ./include/types.h ./include/tic_tac_toe.h \
               ./include/utilities.h ./include/board.h

CC = gcc
FLAGS = -Wall

tic_tac_toe: $(object_files)
	$(CC) $(FLAGS) $(LIB) $(object_files) -o tic_tac_toe

main.o: $(header_files)

tic_tac_toe.o: $(header_files)

board.o: $(header_files)

play: tic_tac_toe
	./tic_tac_toe

clean:
	@echo "Cleaning up .."
	rm $(object_files) tic_tac_toe
