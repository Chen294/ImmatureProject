#include "stdafx.h"
#include <WinSock2.h> /*socketͨ�ţ�ϵͳͷ�ļ�*/
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
	*��ʼ�����ݿ�*
	*����ʧ��ʱ�������ݿ�Ĵ�����Ϣ*
	*/
	MYSQL *conn;
	char *server = "118.24.23.19";
	char *user = "test";
	char *password = "123456";//��******��Ϊ�����õ�����
	char *database = "test";
	conn = mysql_init(NULL);
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
		printf("����ʧ�ܣ�%s", mysql_error(conn));
	/*
	*ͼ�����ϵͳ���ܽ���*
	*/
Menu:
	printf("**********��ӭ����ͼ�����ϵͳ************\n");
	printf("*                                        *\n");
	printf("*       1.�û���    2.����Ա��           *\n");
	printf("*       3.�˳�                           *\n");
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
	*ͼ�����ϵͳ�û���¼ҳ��*
	*/
MU:
	system("cls");
	printf("************ͼ��ϵͳ�û���***************\n");
	printf("*                                       *\n");
	printf("*       1.ע�����û�    2.��¼          *\n");
	printf("*       3.����������                    *\n");
	printf("*                                       *\n");
	printf("*****************************************\n");
	int cmd1=0;
	scanf("%d",&cmd1);
	if (cmd1 == 1)
	{
		system("cls");
		int t;
		char InsertQuery[200];//����������
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
			printf("�������������֣�");
			scanf("%s", TempName);
			fflush(stdin);
			printf("�������������룺");
			scanf("%s", TempPwd1);
			fflush(stdin);
			printf("���ٴ������������룺");
			scanf("%s", TempPwd2);
			fflush(stdin);
			if (strcmp(TempPwd1, TempPwd2))
			{
				printf("�������벻һ��!2s�󷵻أ�������ע��");
				Sleep(2000);
				system("cls");
				continue;
			}
			else
			{
				for (t = 0; t < 8; t++)
					TempLogID[t] = rand() % 10 + 48;
				/*�Ѽ��������ַ������ӳ�һ��������mysql����*/
				strcat(InsertQuery, TableName);strcat(InsertQuery, LeftBracket);strcat(InsertQuery, "Name,");strcat(InsertQuery, "LogID,");
				strcat(InsertQuery, "Pwd");strcat(InsertQuery, RightBracket);strcat(InsertQuery, " values ");
				strcat(InsertQuery, LeftBracket);strcat(InsertQuery, "\"");strcat(InsertQuery, TempName);strcat(InsertQuery, "\"");
				strcat(InsertQuery, ",");strcat(InsertQuery, "\"");strcat(InsertQuery, TempLogID);
				strcat(InsertQuery, "\"");strcat(InsertQuery, ",");strcat(InsertQuery, "\"");strcat(InsertQuery, TempPwd1);
				strcat(InsertQuery, "\"");strcat(InsertQuery, RightBracket);
				t = mysql_real_query(conn, InsertQuery, strlen(InsertQuery));
				if (t)
				{
					printf("ע��ʧ��:%s\n", mysql_error(conn));
					system("pause");
					goto MU;
				}
				printf("%s\n", TempLogID);
				printf("ע��ɹ�����½�˺�������ʾ");
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
			printf("�����������˺ţ�");
			scanf("%s", CheckID);
			printf("�������������룺");
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
				printf("�˺����벻ƥ��!\n����������µ�¼");
				system("pause");
				system("cls");
			}
			else
			{
				printf("��½�ɹ�,2s����ת\n");
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
	*ͼ�����ϵͳ�û�����ҳ��*
	*/
MenuUser:
	printf("������1.�鿴ȫ��ͼ�飻2.����ͼ�飻3.����ͼ�飻4.�黹ͼ�飻5.�˳�\n");
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
		printf("���\t����\t\tISBN\t\t����\t����\tʣ����\n");
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
/*ͼ����Ϣ����*/ 
	if (Cmd2 == 2)
	{
		char TotalUserFind[1000], UserFind[1000];
		printf("������Ҫ���ҵ����ݣ�������ISBN�����ߡ�������ɣ���\n");
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
			printf("���޴���!\n");
			system("pause");
			system("cls");
			goto MenuUser;
		}
		else
		{
			printf("���\t����\t\tISBN\t\t����\t����\tʣ����\n");
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
/*ͼ����Ĺ��ܺ���*/ 
	if (Cmd2 == 3)
	{
		int b;
		char TotalUserBorrow[80], UserBorrow[80];
		printf("������Ҫ���ĵ��鼮��\n");
		scanf("%s", UserBorrow);
		strcpy(TotalUserBorrow, "UPDATE book SET LeftNum=LeftNum-1 Where ID=");
		strcat(TotalUserBorrow, UserBorrow);
		b=mysql_query(conn, TotalUserBorrow);
		printf("����ɹ���");
		system("pause");
		goto MenuUser;
		

	}
	if (Cmd2 == 4)
	{
		char TotalUserReturn[80], UserReturn[80];
		printf("������Ҫ�黹���鼮��\n");
		scanf("%s", UserReturn);
		strcpy(TotalUserReturn, "UPDATE book SET LeftNum=LeftNum+1 Where ID=");
		strcat(TotalUserReturn, UserReturn);
		mysql_query(conn, TotalUserReturn);
		printf("����ɹ���");
		system("pause");
		goto MenuUser;

	}
	if (Cmd2 == 5)
		goto Menu;
	/*
	*ͼ�����ϵͳ�û���¼ҳ��*
	*/
AD:
	system("cls");
	printf("***����Ա��½***\n");
	while (1)
	{
		char Find1[100];
		char CheckID1[10], CheckPwd1[10];
		memset(Find1, '\0', 100); memset(CheckID1, '\0', 10); memset(CheckPwd1, '\0', 10);
		printf("�����������˺ţ�");
		scanf("%s", CheckID1);
		printf("�������������룺");
		scanf("%s", CheckPwd1);
		char Part1[] = "select LogID,Pwd from admin where (LogID=\'"; strcat(Find1, Part1); strcat(Find1, CheckID1);
		char Part2[] = "\') AND (Pwd=\'"; strcat(Find1, Part2); strcat(Find1, CheckPwd1); strcat(Find1, "\')");
		int flag;
		mysql_query(conn, Find1);
		res = mysql_store_result(conn);
		flag = mysql_num_rows(res);
		if (!flag)
		{
			printf("�˺����벻ƥ��!\n����������µ�¼");
			system("pause");
			system("cls");
		}
		else
		{
			printf("��½�ɹ�,2s����ת\n");
			Sleep(2000);
			system("cls");
			goto AI;
		}
	}
AI:
	printf("**************ͼ��ϵͳ����Ա��*************\n");
	printf("*                                         *\n");
	printf("*      1.�鿴����ͼ��    2.����ͼ��       *\n");
	printf("*      3.¼��ͼ��  4.ɾ��ͼ��             *\n");
	printf("*      5.�޸�ͼ����Ϣ  6.����������       *\n");
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
		printf("���\t����\t\tISBN\t\t����\t����\tʣ����\n");
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
/*ͼ����Ϣ����*/ 
	if (Cmd3 == 2)
	{
		char TotalAdminFind[150], AdminFind[150];
		printf("������Ҫ���ҵ����ݣ�������ISBN�����ߡ�������ɣ���\n");
		scanf("%s", AdminFind);

		strcpy(TotalAdminFind, "SELECT Name,ISBN,Writer,Subject,LeftNum FROM book WHERE (Name=\'");
		strcat(TotalAdminFind, AdminFind); strcat(TotalAdminFind, "\') OR (ISBN=\'");
		strcat(TotalAdminFind, AdminFind); strcat(TotalAdminFind, "\') OR (Writer=\'");
		strcat(TotalAdminFind, AdminFind); strcat(TotalAdminFind, "\') OR (Subject=\'"); strcat(TotalAdminFind, AdminFind); strcat(TotalAdminFind, "\')");

		int TAdminFind;
		TAdminFind = mysql_real_query(conn, TotalAdminFind, strlen(TotalAdminFind));
		if (TAdminFind)
		{
			printf("���޴���!\n");
			system("pause");
			system("cls");
			goto AI;
		}
		else
		{
			res = mysql_store_result(conn);
			if (mysql_num_rows(res))
			{
				printf("����\t\tISBN\t\t����\t����\tʣ����\n");
				while ((row = mysql_fetch_row(res)))
				{
					printf("%s\t%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3], row[4]);
				}
			}
			system("pause");
			goto AI;
		}
	}
/*ͼ����Ϣ¼��*/ 
	if (Cmd3 == 3)
	{
		char TotalUserIn[80], UserInName[80], UserInIS[80], UserInWri[80], UserInSub[80], UserInLef[80];
		printf("������������\n"); scanf("%s", UserInName);
		printf("������ISBN��\n"); scanf("%s", UserInIS);
		printf("���������ߣ�\n"); scanf("%s", UserInWri);
		printf("���������⣺\n"); scanf("%s", UserInSub);
		printf("������ʣ������\n"); scanf("%s", UserInLef);
		strcpy(TotalUserIn, "INSERT INTO book(NAME,ISBN,Writer,Subject,LeftNum) VALUES ");
		strcat(TotalUserIn, "(\""); strcat(TotalUserIn, UserInName); strcat(TotalUserIn, "\","); strcat(TotalUserIn, "\""); strcat(TotalUserIn, UserInIS);
		strcat(TotalUserIn, "\","); strcat(TotalUserIn, "\""); strcat(TotalUserIn, UserInWri); strcat(TotalUserIn, "\","); strcat(TotalUserIn, "\"");
		strcat(TotalUserIn, UserInSub); strcat(TotalUserIn, "\","); strcat(TotalUserIn, "\""); strcat(TotalUserIn, UserInLef); strcat(TotalUserIn, "\")");
		int t8;
		t8 = mysql_real_query(conn, TotalUserIn, strlen(TotalUserIn));
		if (t8)
		{
			printf("¼��ʧ��:%s\n", mysql_error(conn));
			system("pause");
			goto AI;
		}
		printf("¼��ͼ����Ϣ�ɹ���");
		system("pause");
		system("cls");
		goto AI;
	}
	if (Cmd3 == 4)
	{
		int t7;
		char TotalUserDelete[100], UserDelete[100];
		printf("������Ҫɾ��ͼ���ID��\n");
		scanf("%s", UserDelete);
		strcpy(TotalUserDelete, "DELETE from book WHERE ID=\'"); strcat(TotalUserDelete, UserDelete); strcat(TotalUserDelete, "\'");
		t7 = mysql_real_query(conn, TotalUserDelete, strlen(TotalUserDelete));
		if (t7)
		{
			printf("ɾ��ʧ��:%s\n", mysql_error(conn));
			goto AI;
		}
		printf("ɾ���ɹ�\n");
		system("pause");
		system("cls");
		goto AI;
	}
/*ͼ����Ϣ����*/ 
	if (Cmd3 == 5)
	{
		int t8;
		char UserRenewID[100], UserRenewName[100], UserRenewIS[100], UserRenewWri[100], UserRenewSub[100], UserRenewLef[100], TotalUserRenew[100];
		printf("������Ҫ����ͼ���ID��\n");scanf("%s", UserRenewID);
		printf("������Ҫ����ͼ������ƣ�\n");scanf("%s", UserRenewName);
		printf("������Ҫ����ͼ���ISBN��\n");scanf("%s", UserRenewIS);
		printf("������Ҫ����ͼ������ߣ�\n");scanf("%s", UserRenewWri);
		printf("������Ҫ����ͼ������⣺\n");scanf("%s", UserRenewSub);
		printf("������Ҫ����ͼ���ʣ������\n");scanf("%s", UserRenewLef);

		strcpy(TotalUserRenew, "UPDATE book SET Name=\'");strcat(TotalUserRenew, UserRenewName);strcat(TotalUserRenew, "\',ISBN=\'");strcat(TotalUserRenew, UserRenewIS);strcat(TotalUserRenew, "\',Writer=\'");
		strcat(TotalUserRenew, UserRenewWri);strcat(TotalUserRenew, "\',Subject=\'");strcat(TotalUserRenew, UserRenewSub);strcat(TotalUserRenew, "\',LeftNum=\'");strcat(TotalUserRenew, UserRenewLef);strcat(TotalUserRenew, "\' WHERE ID=\'");
		strcat(TotalUserRenew, UserRenewID);strcat(TotalUserRenew, "\'");
		mysql_query(conn, TotalUserRenew);

		printf("���³ɹ���\n");
		goto AI;
	}
}



