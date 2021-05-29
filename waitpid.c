#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid < 0){
		printf("创建进程失败！\n");
		exit(1);
	}
	else if(pid == 0){
		int i;
		for(i = 3;i>0;i--){
			printf("这是子进程\n");
			sleep(3);
		}
		exit(3);
	}
	else{
		int status;
		waitpid(pid,&status,0);
		if(WIFEXITED(status))
			printf("子进程的结束代码 %d\n",WEXITSTATUS(status));
		else
			printf("子进程的终止信号代码 %d\n",WTERMSIG(status));
	}
	return 0;
}
