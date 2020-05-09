#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int arg, char *argv[3]){
	int fd,fd1;
	char *file1,*file2;
	file1 = argv[1];
	file2 = argv[2];
	printf("%s , %s",file1,file2);
	char buff[1];
	fd = open(argv[1],O_RDONLY);
	fd1 = creat(argv[2],0777);
	while(read(fd,buff,1)>0)
		write(fd1,buff,1);
	remove(file1);
	close(fd);
	close(fd1);
	return 0;
}
