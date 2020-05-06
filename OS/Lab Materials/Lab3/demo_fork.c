#include<bits/stdc++.h>
#include<unistd.h>
int main(){
	printf("First Statement\n");
	int id1 = fork(),id2;
	printf("Second Statement id = %d , %d\n",id1,id2);
	id2 = fork();
	printf("Third Statement id = %d , %d\n",id1,id2);
	printf("Fourth Statement = %d , %d\n",id1,id2);
	return 0;
}
