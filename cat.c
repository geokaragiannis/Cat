#include<stdlib.h>
#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
    int file_opened; // file descriptor for the file opened
    ssize_t in_bytes; // size of the input file (or user input)
    char word[4096]; // array that holds the content of the files

    // no arguments --> take input from stdin
    if(argc == 1){
        // the array that holds the input
    	char a[1000];
    	// if the user input is not control+C, then don't exit
    	while(a[0]!=3){
            // read from stdin
    		in_bytes = read(STDIN_FILENO,a,sizeof(a)-1);
    
    		// write to stdout
            write(STDOUT_FILENO, a, in_bytes);
    	}
    	
    }

    // open input file(s) for reading
    int i;
    for(i=1;i<argc;i++){

    	file_opened = open(argv[i], O_RDONLY);
    	if( file_opened < 0 ){
        	perror(argv[i]);
        	return(EXIT_FAILURE);
    	}

        in_bytes = read(file_opened,word,sizeof(word)-1);
        write(STDOUT_FILENO,word,in_bytes);
    }

    close(file_opened);
    
}