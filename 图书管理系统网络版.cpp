#include "stdafx.h"
#include <WinSock2.h> /*socket通信，系统头文件*/
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "D:\mysql-5.7.22-win32\include\mysql.h"
#pragma comment(lib, "libmysql.lib")
char InsertHead[20] = "insert into "; 
MYSQL_RES *res;
MYSQL_ROW row;
int main()
{
	/*
	*初始化数据库*
	*连接失败时返回数据库的错误信息*
	*/
	MYSQL *conn;
	char *server = "118.24.23.19";
	char *user = "test";
	char *password = "123456";//“******”为你设置的密码
	char *database = "test";
	conn = mysql_init(NULL);
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
		printf("连接失败：%s", mysql_error(conn));
	/*
	*图书管理系统的总界面*
	*/
Menu:
	printf("**********欢迎进入图书管理系统************\n");
	printf("*                                        *\n");
	printf("*       1.用户端    2.管理员端           *\n");
	printf("*       3.退出                           *\n");
	printf("*                                        *\n");
	printf("******************************************\n");
	int cmd;
	scanf("%d", &cmd);
	if (cmd == 2)
		goto AD;
	if (cmd == 3)
		return 0;
	if (cmd == 1);
	/*
	*图书管理系统用户登录页面*
	*/
MU:
	system("cls");
	printf("************图书系统用户端***************\n");
	printf("*                                       *\n");
	printf("*       1.注册新用户    2.登录          *\n");
	printf("*       3.返回主界面                    *\n");
	printf("*                                       *\n");
	printf("*****************************************\n");
	int cmd1=0;
	scanf("%d",&cmd1);
	if (cmd1 == 1)
	{
		system("cls");
		int t;
		char InsertQuery[200];//插入总命令
		char TableName[10] = "user ";
		char LeftBracket[2] = "(";
		char TempName[50];
		char TempLogID[9];
		char TempPwd1[10], TempPwd2[10];
		char RightBracket[2] = ")";
		memset(InsertQuery, '\0', 200);memset(TempName, '\0', 50);memset(TempLogID, '\0', 9);
		memset(TempPwd1, '\0', 10);memset(TempPwd2, '\0', 10);
		strcpy(InsertQuery, InsertHead);
		while (1)
		{
			printf("请输入您的名字：");
			scanf("%s", TempName);
			fflush(stdin);
			printf("请输入您的密码：");
			scanf("%s", TempPwd1);
			fflush(stdin);
			printf("请再次输入您的密码：");
			scanf("%s", TempPwd2);
			fflush(stdin);
			if (strcmp(TempPwd1, TempPwd2))
			{
				printf("两次密码不一致!2s后返回，请重新注册");
				Sleep(2000);
				system("cls");
				continue;
			}
			else
			{
				for (t = 0; t < 8; t++)
					TempLogID[t] = rand() % 10 + 48;
				/*把几个变量字符串连接成一个完整的mysql命令*/
				strcat(InsertQuery, TableName);strcat(InsertQuery, LeftBracket);strcat(InsertQuery, "Name,");strcat(InsertQuery, "LogID,");
				strcat(InsertQuery, "Pwd");strcat(InsertQuery, RightBracket);strcat(InsertQuery, " values ");
				strcat(InsertQuery, LeftBracket);strcat(InsertQuery, "\"");strcat(InsertQuery, TempName);strcat(InsertQuery, "\"");
				strcat(InsertQuery, ",");strcat(InsertQuery, "\"");strcat(InsertQuery, TempLogID);
				strcat(InsertQuery, "\"");strcat(InsertQuery, ",");strcat(InsertQuery, "\"");strcat(InsertQuery, TempPwd1);
				strcat(InsertQuery, "\"");strcat(InsertQuery, RightBracket);
				t = mysql_real_query(conn, InsertQuery, strlen(InsertQuery));
				if (t)
				{
					printf("注册失败:%s\n", mysql_error(conn));
					system("pause");
					goto MU;
				}
				printf("%s\n", TempLogID);
				printf("注册成功！登陆账号如上所示");
				system("pause");
				system("cls");
				goto MU;
			}
		}
	}
	if (cmd1 == 2)
	{
		while (1)
		{
			system("cls");
			char Find[100];
			char CheckID[10], CheckPwd[10];
			memset(Find, '\0', 100); memset(CheckID, '\0', 10); memset(CheckPwd, '\0', 10);
			printf("请输入您的账号：");
			scanf("%s", CheckID);
			printf("请输入您的密码：");
			scanf("%s", CheckPwd);
			char Part1[] = "select LogID,Pwd from user where (LogID=\'"; strcat(Find, Part1); strcat(Find, CheckID);
			char Part2[] = "\') AND (Pwd=\'"; strcat(Find, Part2); strcat(Find, CheckPwd); strcat(Find, "\')");
			int flag;
			mysql_query(conn, Find);
			res = mysql_store_result(conn);
			flag = mysql_num_rows(res);
			if (!flag)
			{
				printf("%s\n", mysql_error(conn));
				printf("账号密码不匹配!\n按任意键重新登录");
				system("pause");
				system("cls");
			}
			else
			{
				printf("登陆成功,2s后跳转\n");
				Sleep(2000);
				system("cls");
				goto MenuUser;
			}
		}
		
	}
	if (cmd1 == 3)
	{
		system("cls");
		goto Menu;
	}
	/*
	*图书管理系统用户操作页面*
	*/
MenuUser:
	printf("您可以1.查看全部图书；2.查找图书；3.借阅图书；4.归还图书；5.退出\n");
	int Cmd2;
	scanf("%d", &Cmd2);
	if (Cmd2 == 1)
	{
		int TotalUserFindAll;
		char table_name[50]="book";
		char query[50];
		memset(query, '\0', 50);
		memset(query, '\0', 50);
		strcpy(query, "select * from ");
		strcat(query, table_name);
		TotalUserFindAll = mysql_real_query(conn, query, strlen(query));
		if (TotalUserFindAll)
		{
			printf("failed to query:%s\n", mysql_error(conn));
			system("pause");
		}
		res = mysql_store_result(conn);
		printf("书号\t书名\t\tISBN\t\t作者\t主题\t剩余量\n");
		while (row = mysql_fetch_row(res))
		{
			for (TotalUserFindAll = 0; TotalUserFindAll<mysql_num_fields(res); TotalUserFindAll++)
			{
				printf("%s\t", row[TotalUserFindAll]);
			}
			printf("\n");
		}
		system("pause");
		goto MenuUser;
	}
/*图书信息检索*/ 
	if (Cmd2 == 2)
	{
		char TotalUserFind[1000], UserFind[1000];
		printf("请输入要查找的内容（书名、ISBN、作者、主题均可）：\n");
		scanf("%s", UserFind);

		strcpy(TotalUserFind, "SELECT Name,ISBN,Writer,Subject,LeftNum FROM book WHERE (Name=\'");
		strcat(TotalUserFind, UserFind);strcat(TotalUserFind, "\') OR (ISBN=\'");
	    strcat(TotalUserFind, UserFind);strcat(TotalUserFind, "\') OR (Writer=\'");
		strcat(TotalUserFind, UserFind);strcat(TotalUserFind, "\') OR (Subject=\'");strcat(TotalUserFind, UserFind);strcat(TotalUserFind, "\')");

		int TUserFind;
		mysql_query(conn, TotalUserFind);
		res = mysql_store_result(conn);
		TUserFind = mysql_num_rows(res);
		if (!TUserFind)
		{
			printf("查无此书!\n");
			system("pause");
			system("cls");
			goto MenuUser;
		}
		else
		{
			printf("书号\t书名\t\tISBN\t\t作者\t主题\t剩余量\n");
			if (mysql_num_rows(res))
			{
				while ((row = mysql_fetch_row(res)))
				{
					printf("%s\t%s\t%s\t%s\t%s\n", row[0], row[1], row[2],row[3],row[4]);
				}
			}
			system("pause");
			goto MenuUser;
		}
	}
/*图书借阅功能函数*/ 
	if (Cmd2 == 3)
	{
		int b;
		char TotalUserBorrow[80], UserBorrow[80];
		printf("请输入要借阅的书籍：\n");
		scanf("%s", UserBorrow);
		strcpy(TotalUserBorrow, "UPDATE book SET LeftNum=LeftNum-1 Where ID=");
		strcat(TotalUserBorrow, UserBorrow);
		b=mysql_query(conn, TotalUserBorrow);
		printf("借书成功！");
		system("pause");
		goto MenuUser;
		

	}
	if (Cmd2 == 4)
	{
		char TotalUserReturn[80], UserReturn[80];
		printf("请输入要归还的书籍：\n");
		scanf("%s", UserReturn);
		strcpy(TotalUserReturn, "UPDATE book SET LeftNum=LeftNum+1 Where ID=");
		strcat(TotalUserReturn, UserReturn);
		mysql_query(conn, TotalUserReturn);
		printf("还书成功！");
		system("pause");
		goto MenuUser;

	}
	if (Cmd2 == 5)
		goto Menu;
	/*
	*图书管理系统用户登录页面*
	*/
AD:
	system("cls");
	printf("***管理员登陆***\n");
	while (1)
	{
		char Find1[100];
		char CheckID1[10], CheckPwd1[10];
		memset(Find1, '\0', 100); memset(CheckID1, '\0', 10); memset(CheckPwd1, '\0', 10);
		printf("请输入您的账号：");
		scanf("%s", CheckID1);
		printf("请输入您的密码：");
		scanf("%s", CheckPwd1);
		char Part1[] = "select LogID,Pwd from admin where (LogID=\'"; strcat(Find1, Part1); strcat(Find1, CheckID1);
		char Part2[] = "\') AND (Pwd=\'"; strcat(Find1, Part2); strcat(Find1, CheckPwd1); strcat(Find1, "\')");
		int flag;
		mysql_query(conn, Find1);
		res = mysql_store_result(conn);
		flag = mysql_num_rows(res);
		if (!flag)
		{
			printf("账号密码不匹配!\n按任意键重新登录");
			system("pause");
			system("cls");
		}
		else
		{
			printf("登陆成功,2s后跳转\n");
			Sleep(2000);
			system("cls");
			goto AI;
		}
	}
AI:
	printf("**************图书系统管理员端*************\n");
	printf("*                                         *\n");
	printf("*      1.查看所有图书    2.查找图书       *\n");
	printf("*      3.录入图书  4.删除图书             *\n");
	printf("*      5.修改图书信息  6.返回主界面       *\n");
	printf("*                                         *\n");
	printf("*******************************************\n");
	int Cmd3 = 0;
	scanf("%d", &Cmd3);
	if (Cmd3 == 6)
		goto Menu;
	if (Cmd3 == 1)
	{
		int TAdmin;
		char TableNameAdmin[50] = "book";
		char query[50];
		memset(query, '\0', 50);
		memset(query, '\0', 50);
		strcpy(query, "select * from ");
		strcat(query, TableNameAdmin);
		TAdmin = mysql_real_query(conn, query, strlen(query));
		if (TAdmin)
		{
			printf("failed to query:%s\n", mysql_error(conn));
			system("pause");
		}
		res = mysql_store_result(conn);
		printf("书号\t书名\t\tISBN\t\t作者\t主题\t剩余量\n");
		while (row = mysql_fetch_row(res))
		{
			for (TAdmin = 0; TAdmin<mysql_num_fields(res); TAdmin++)
			{
				printf("%s\t", row[TAdmin]);
			}
			printf("\n");
		}
		system("pause");
		system("cls");
		goto AI;
	}
/*图书信息检索*/ 
	if (Cmd3 == 2)
	{
		char TotalAdminFind[150], AdminFind[150];
		printf("请输入要查找的内容（书名、ISBN、作者、主题均可）：\n");
		scanf("%s", AdminFind);

		strcpy(TotalAdminFind, "SELECT Name,ISBN,Writer,Subject,LeftNum FROM book WHERE (Name=\'");
		strcat(TotalAdminFind, AdminFind); strcat(TotalAdminFind, "\') OR (ISBN=\'");
		strcat(TotalAdminFind, AdminFind); strcat(TotalAdminFind, "\') OR (Writer=\'");
		strcat(TotalAdminFind, AdminFind); strcat(TotalAdminFind, "\') OR (Subject=\'"); strcat(TotalAdminFind, AdminFind); strcat(TotalAdminFind, "\')");

		int TAdminFind;
		TAdminFind = mysql_real_query(conn, TotalAdminFind, strlen(TotalAdminFind));
		if (TAdminFind)
		{
			printf("查无此书!\n");
			system("pause");
			system("cls");
			goto AI;
		}
		else
		{
			res = mysql_store_result(conn);
			if (mysql_num_rows(res))
			{
				printf("书名\t\tISBN\t\t作者\t主题\t剩余量\n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("%s\t%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3], row[4]);
				}
			}
			system("pause");
			goto AI;
		}
	}
/*图书信息录入*/ 
	if (Cmd3 == 3)
	{
		char TotalUserIn[80], UserInName[80], UserInIS[80], UserInWri[80], UserInSub[80], UserInLef[80];
		printf("请输入书名：\n"); scanf("%s", UserInName);
		printf("请输入ISBN：\n"); scanf("%s", UserInIS);
		printf("请输入作者：\n"); scanf("%s", UserInWri);
		printf("请输入主题：\n"); scanf("%s", UserInSub);
		printf("请输入剩余量：\n"); scanf("%s", UserInLef);
		strcpy(TotalUserIn, "INSERT INTO book(NAME,ISBN,Writer,Subject,LeftNum) VALUES ");
		strcat(TotalUserIn, "(\""); strcat(TotalUserIn, UserInName); strcat(TotalUserIn, "\","); strcat(TotalUserIn, "\""); strcat(TotalUserIn, UserInIS);
		strcat(TotalUserIn, "\","); strcat(TotalUserIn, "\""); strcat(TotalUserIn, UserInWri); strcat(TotalUserIn, "\","); strcat(TotalUserIn, "\"");
		strcat(TotalUserIn, UserInSub); strcat(TotalUserIn, "\","); strcat(TotalUserIn, "\""); strcat(TotalUserIn, UserInLef); strcat(TotalUserIn, "\")");
		int t8;
		t8 = mysql_real_query(conn, TotalUserIn, strlen(TotalUserIn));
		if (t8)
		{
			printf("录入失败:%s\n", mysql_error(conn));
			system("pause");
			goto AI;
		}
		printf("录入图书信息成功！");
		system("pause");
		system("cls");
		goto AI;
	}
	if (Cmd3 == 4)
	{
		int t7;
		char TotalUserDelete[100], UserDelete[100];
		printf("请输入要删除图书的ID：\n");
		scanf("%s", UserDelete);
		strcpy(TotalUserDelete, "DELETE from book WHERE ID=\'"); strcat(TotalUserDelete, UserDelete); strcat(TotalUserDelete, "\'");
		t7 = mysql_real_query(conn, TotalUserDelete, strlen(TotalUserDelete));
		if (t7)
		{
			printf("删除失败:%s\n", mysql_error(conn));
			goto AI;
		}
		printf("删除成功\n");
		system("pause");
		system("cls");
		goto AI;
	}
/*图书信息更新*/ 
	if (Cmd3 == 5)
	{
		int t8;
		char UserRenewID[100], UserRenewName[100], UserRenewIS[100], UserRenewWri[100], UserRenewSub[100], UserRenewLef[100], TotalUserRenew[100];
		printf("请输入要更新图书的ID：\n");scanf("%s", UserRenewID);
		printf("请输入要更新图书的名称：\n");scanf("%s", UserRenewName);
		printf("请输入要更新图书的ISBN：\n");scanf("%s", UserRenewIS);
		printf("请输入要更新图书的作者：\n");scanf("%s", UserRenewWri);
		printf("请输入要更新图书的主题：\n");scanf("%s", UserRenewSub);
		printf("请输入要更新图书的剩余量：\n");scanf("%s", UserRenewLef);

		strcpy(TotalUserRenew, "UPDATE book SET Name=\'");strcat(TotalUserRenew, UserRenewName);strcat(TotalUserRenew, "\',ISBN=\'");strcat(TotalUserRenew, UserRenewIS);strcat(TotalUserRenew, "\',Writer=\'");
		strcat(TotalUserRenew, UserRenewWri);strcat(TotalUserRenew, "\',Subject=\'");strcat(TotalUserRenew, UserRenewSub);strcat(TotalUserRenew, "\',LeftNum=\'");strcat(TotalUserRenew, UserRenewLef);strcat(TotalUserRenew, "\' WHERE ID=\'");
		strcat(TotalUserRenew, UserRenewID);strcat(TotalUserRenew, "\'");
		mysql_query(conn, TotalUserRenew);

		printf("更新成功！\n");
		goto AI;
	}
}



