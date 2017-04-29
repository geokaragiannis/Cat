mycat: cat.c 
	gcc -o mycat cat.c
cat.o : cat.c
	gcc -c –std=c99 -Wall cat.c
clean :
	rm -f mycat mycat.o