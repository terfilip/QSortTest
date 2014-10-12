CC=gcc
CXX=g++
JC=javac
SRCDIR=src
BINDIR=bin
MKDIR=mkdir -p $(BINDIR)

CFLAGS=-O2 -Wall

all: qs

qs: QsortC CheckSort Qsort java

QsortC:
	$(CC) $(CFLAGS) $(SRCDIR)/QsortC.c -o $(BINDIR)/QsortC

CheckSort:
	$(CC) $(CFLAGS) $(SRCDIR)/CheckSort.c -o $(BINDIR)/CheckSort

Qsort:
	$(CXX) $(CFLAGS) $(SRCDIR)/Qsort.cc -o $(BINDIR)/Qsort

java:
	$(JC) $(SRCDIR)/*.java -d $(BINDIR)

clean:
	rm -rf *o hello
