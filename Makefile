
tic_tac_toe.out: tic_tac_toe.o win.o main.o
	$(CC) $(CFLAGS) -o tic_tac_toe.out tic_tac_toe.o main.o
tic_tac_toe.o: tic_tac_toe.c tic_tac_toe.h
	$(CC) $(CFLAGS) -c tic_tac_toe.c tic_tac_toe.h
win.o: win.c win.h
	$(CC) $(CFLAGS) -c win.c win.h
main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c main.h
