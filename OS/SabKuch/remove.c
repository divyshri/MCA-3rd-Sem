#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int arg, char *argv[]){
	for(int i=1;i<=arg;i++)
		remove(argv[i]);
	return 0;
}
