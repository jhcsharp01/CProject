#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef void (*server_connection)(char* id, int pw);
void connect_SERVER(server_connection callback);
void setting(server_connection fp);
void OnLogin(char* id, int pw);
void on_server_connected();
void on_server_disconnected();
void Login();

char uid[] = "abc1234"; //Ȯ�ο� ���̵�
int  upass = 123456;    //Ȯ�ο� ��й�ȣ
server_connection sc = NULL; //���� ���� ����
int main()
{
	Login();
	connect_SERVER(sc);
	return 0;
}
void connect_SERVER(server_connection callback)
{
	if (callback)
		on_server_connected();
	else
		on_server_disconnected();
}
void on_server_connected()
{
	printf("������ ������ �����߽��ϴ�!");
}
void on_server_disconnected()
{
	printf("���̵� �Ǵ� ��й�ȣ�� �߸�����ϴ�.");
}
void Login()
{
	char name[20]; //���α׷����� ����� ���̵� �̸�
	int pw;        //���α׷����� ����� ��й�ȣ

	printf("���̵� �Է��մϴ�. ");
	scanf("%s", name);
	printf("��й�ȣ�� �Է��մϴ�. ");
	scanf("%d", &pw);	

	setting(OnLogin);
	sc(name,pw);
}
void setting(server_connection fp)
{
	sc = fp;
}
void OnLogin(char* id, int pw)
{
	//strcmp(����,����) == 0�� �� ������ ���� ������ Ȯ���ϴ� �ڵ�
	if (strcmp(uid,id) == 0 && upass == pw)
	{
		printf("success");
	}
	else
	{
		sc = NULL;
		printf("fail");
	}
}