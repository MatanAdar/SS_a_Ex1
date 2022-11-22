.PHONY: clean all
CC=gcc
AR=ar
FLAGS= -Wall -g

##create o files

basicClassification.o: basicClassification.c NumClass.h 
	$(CC) $(FLAGS) -c $^

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c $^

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c $^

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c $^

##create static lib 

loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o 
	$(AR) rcs $@ $^

recursives: libclassrec.a
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) rcs $@ $^

##create dynemic loop

recursived: libclassrec.so
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CC) $(FLAGS) -shared $^ -o $@

loopd: libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) $(FLAGS) -shared $^ -o $@

##create mains

mains: main.o libclassrec.a
	$(CC) $(FLAGS) main.o ./libclassrec.a -lm -o $@

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) main.o ./libclassloops.so -lm -o $@

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) main.o ./libclassrec.so -lm -o $@

##create make all

all: mains maindloop maindrec libclassloops.a

## clean all the files with the end of this elements

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
