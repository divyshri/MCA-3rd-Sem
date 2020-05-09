#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
int main(int args,char *argv[])
{
	DIR *p;
	struct dirent *d;
	p = opendir(".");
	if(p==NULL){
		perror("Cannot find directory");
		exit(-1);	
	}
	if(argv[1]!='\0'){
		while(d=readdir(p)){
				printf("%s  ",d->d_name);
		}
	}
	else{
		while(d=readdir(p)){
			if(d->d_name[0]!='.')
			printf("%s  ",d->d_name);
		}
	}
	printf("\n");
	return 0;
}
