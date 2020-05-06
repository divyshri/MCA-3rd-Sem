#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>

int main(){
    char inputCommand[256];
    char argv[64][64];
    int cmdIndex = 0;
    char* tofree;
    int argc = 0;
    int bufIndex = 0;

    system("clear screen");
    printf("Start Command Interpreter Porgram : (Y/N) ::\t");
    gets(inputCommand);

    if(!strcmp(inputCommand,"Y")){
        while(strcmp(inputCommand,"exit")){
            printf("$> ");
            fflush(stdout);
            pid_t pid;

            pid = fork();
            if(pid == 0){
            gets(inputCommand);

            // OPTIONAL //
            //argv argv code
		bufIndex=0;
		argc=0;
            for(cmdIndex = 0;cmdIndex < strlen(inputCommand); cmdIndex++){
                if(inputCommand[cmdIndex] == ' '){
                    argv[argc][bufIndex] = '\0';
                    argc++;
                    bufIndex = 0;
                }
                else{
                    argv[argc][bufIndex] = inputCommand[cmdIndex];
                    bufIndex++;
                }
            }
		argv[argc][bufIndex+1] = '\0';
		//printf("%s\n%s %s\n",inputCommand,argv[0],argv[1]);
            argc++;


            if(!strcmp(argv[0],"wc"))
		//execl("./wc","./wc",argv[1],(char*)0);
		execlp("wc",argv[1]);
            else if(!strcmp(argv[0],"ls"))
                //execl("./ls","./ls",argv[1],(char*)0);
		execlp("ls",argv[1]);
            else if(!strcmp(argv[0],"echo"))
                execlp("echo",argv[1]);
            else if(!strcmp(argv[0],"ps"))
                execlp("ps",argv[1]);
            else if(!strcmp(argv[0],"kill"))
                execl("./kill","./kill",argv[1]	,(char*)0);
            else if(!strcmp(argv[0],"rm"))
                execl("./rm",".rm",argv[1],(char*)0);
            else if(!strcmp(argv[0],"cat"))
                execl("./cat","./cat",argv[1],(char*)0);
            else
                printf("Command Not Found.\n");
            }
            wait(pid);

        }
        }else{
            printf("You Stopped Starting of the Interpreter. Please Restart.\n\n");
        }

    return 0;
}

