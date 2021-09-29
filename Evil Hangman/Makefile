CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o g_vector.o associative.o game.o
TESTOBJ = my_string.o unit_test.o test_def.o
ALL: string_driver unit_test

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

g_vector.o: g_vector.c
	$(CC) $(CFLAGS) -c  g_vector.c -o g_vector.o

associative.o: associative_array.c
	$(CC) $(CFLAGS) -c associative_array.c -o associative.o

game.o: game.c
	$(CC) $(CFLAGS) -c game.c -o game.o

unit_test: $(TESTOBJ)
	$(CC) $(CFLAGS) -o unit_test $(TESTOBJ)

unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o

test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o

clean:
	rm string_driver $(OBJECTS) unit_test unit_test.o test_def.o
