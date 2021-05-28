#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int status;  //保存被收集进程退出时的一些状态
	pid_t pc,pr;
	pc = fork(); // 创建子进程
	if(pc < 0){  //创建子进程失败
		printf("fork failed");
		exit(1);
	}
	else if (pc == 0){  //创建成功，子进程执行代码
		int i =0;
		for(i = 3;i > 0; i--){
			printf("This is the child.\n");
			sleep(5);
		}
		exit(3);  //终止子进程
	}
	else{                 //父进程执行代码
		pr = wait(&status);    //调用wait函数等待子进程终止

		if(WIFEXITED(status)){  //判断正常结束
			printf("The child process  %d exit normally. \n",pr);
			printf("The WIFEXITED return coded if %d\n",WIFEXITED(status));
		}
		else
			printf("The child process %d exit abnormally.\n",pr);
		}
			printf("Status is %d.\n",status);
		return 0;
}
