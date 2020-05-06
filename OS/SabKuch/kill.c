#include<bits/stdc++.h>
int main(int args, char *argv[])
{
	int pid=0;
	char *pstr = argv[1];
	int i=0;
	while(pstr[i]!='\0'){
		pid = (pid*10) + (pstr[i++]-'0');
	}
	int status = kill(pid,1);
	if(status==-1)
		printf("Process cannot be terminated, ERROR !\n\n");	
	else
		printf("Process stopped succesfully\n\n");
}
