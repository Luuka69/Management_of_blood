btc:BTC.o main.o
	gcc BTC.o main.o -o btc -g
main.o:main.c
	gcc -c main.c -g
BTC.o:BTC.c
	gcc -c BTC.c -g

