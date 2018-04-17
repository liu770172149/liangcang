#include<stdio.h>
#include"mydb.h"
#include"select.h"
#include"uart.h"
int main()
{
	int ret1 = myuart_init();//整个串口初始化
	if(ret1==0)
	{
		printf("初始化串口成功\n");
	}
	
	int ret=InitDb();//创建数据库并初始化
	if(ret==DB_OK)
	{
		ret=0;
		printf("数据库开启成功\n");
        char buf[1024]="";
        //InitBbash("56","57","58");
        findbbash(buf);
        printf("man函数打印要发送的环境变量：%s \n",buf);
		
		ret=mysocket();
		if(ret==SEL_ERR)
		{
			printf("服务器开启失败\n");
		}
		printf("服务器开启成功，等待链接\n");
		
	}
	printf("数据库开启失败，请检查\n");
	return 0;
}
