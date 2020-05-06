#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int arg, char *argv[]){
	FILE *f;
	char ch;
	char *file;
	file = argv[1];
	//int count=0;
	f = fopen(argv[1],"r");
	if(f){
		while((ch=getc(f))!=EOF){
			printf("%c",ch);
		}
	}
	//printf("\n\nCounted words are %d\n\n\n",count);
	getchar();
	return 0;
}
