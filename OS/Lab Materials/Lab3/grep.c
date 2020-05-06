#include<stdio.h>
#include<string.h>
void main(int arg, char *argv[])
{
	char temp[100];
	FILE *fp;
	fp = fopen(argv[1],"r");
	while(!feof(fp)){
		fgets(temp,1000,fp);
		if(strstr(temp,argv[2]))
			printf("%s",temp);
	}
	fclose(fp);
}
