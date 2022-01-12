Project4: main.o stack.o btree.o 
	gcc -o Project4 main.o stack.o btree.o 

main.o: main.c header.h
	gcc -c main.c

stack.o: stack.c header.h
	gcc -c stack.c

btree.o: btree.c header.h
	gcc -c btree.c

clean:
	rm main.o btree.o stack.o Project4