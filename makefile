.PHONY: clean all
CC=gcc
AR=ar
FLAGS= -Wall -g
CCSO= gcc -shared -o

##create o files

basicClassification.o: basicClassification.c NumClass.h 
	$(CC) -c $(FLAGS) -fPIC basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) -c $(FLAGS) -fPIC advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) -c $(FLAGS) -fPIC advancedClassificationRecursion.c

main.o: main.c NumClass.h
	$(CC) -c $(FLAGS) main.c

##create static lib 

loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o 
	$(AR) rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: libclassrec.a
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

##create dynemic loop

recursived: libclassrec.so
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CCSO) libclassrec.so basicClassification.o advancedClassificationRecursion.o

loopd: libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CCSO) libclassloops.so basicClassification.o advancedClassificationLoop.o

##create mains

mains: main.o libclassrec.a
	$(CC) $(FLAGS) main.o libclassrec.a -o mains -lm

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) main.o ./libclassloops.so -o maindloop -lm

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) main.o ./libclassrec.so -o maindrec -lm

##create make all

all: mains maindloop maindrec libclassloops.a

## clean all the files with the end of this elements

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
