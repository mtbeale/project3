CC = g++
DEBUG = -g -O0 -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)

all: cal date head

cal.o: cal.cpp
        $(CC) $(CFLAGS) cal.cpp
cal: cal.o
        $(CC) -o cal cal.o


date.o: date.cpp
        $(CC) $(CFLAGS) date.cpp
date: date.o
        $(CC) -o date date.o


head.o: head.cpp
        $(CC) $(CFLAGS) head.cpp
head: head.o
        $(CC) -o head head.o


ln.o: ln.cpp
        $(CC) $(CFLAGS) ln.cpp
ln: ln.o
        $(CC) -o ln ln.o


ls.o: ls.cpp
        $(CC) $(CFLAGS) ls.cpp
ls: ls.o
        $(CC) -o ls ls.o

mkdir.o: mkdir.cpp
        $(CC) $(CFLAGS) mkdir.cpp
mkdir: mkdir.o
        $(CC) -o mkdir mkdir.o


env.o: env.cpp
        $(CC) $(CFLAGS) env.cpp
env: env.o
        $(CC) -o env env.o

		
tail.o: tail.cpp
        $(CC) $(CFLAGS) tail.cpp
tail: tail.o
        $(CC) -o tail tail.o

true.o: true.cpp
		$(CC) $(CFLAGS) true.cpp
true: true.o
		$(CC) -o true true.o
		
false.o: false.cpp
		$(CC) $(CFLAGS) false.cpp
false: false.o
		$(CC) -o false false.o
	

wc.o: wc.cpp
        $(CC) $(CFLAGS) wc.cpp
wc: wc.o
        $(CC) -o wc wc.o


.PHONY: clean
clean:
        rm -rf *.o
        rm -rf ./cal
        rm -rf ./date
        rm -rf ./head
        rm -rf ./ln
        rm -rf ./ls
        rm -rf ./mkdir
        rm -rf ./env
        rm -rf ./tail
        rm -rf ./wc
