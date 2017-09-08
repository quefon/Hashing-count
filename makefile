all: main.o hashing_hw7.o
	gcc main.o hashing_hw7.o  -o hw7
.PHONY: all

main.o: main.c
	gcc -c main.c
	
hashing_hw7.o: hashing_hw7.c
	gcc -c hashing_hw7.c	

clean:
	rm main.o hashing_hw7 hw7
	
