#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct user
{
	char id[40]; //ex) sample12@naver.com
	char pw[50]; //ex) koreaedu1384!@
	char gender; // 'M' , 'F'
};
//���� ����ü user�� �̿��� ������ ���� ��� ȭ���� �ϼ��ϼ���.

//���̵� �Է����ּ��� : sample12@naver.com
//��й�ȣ�� �Է����ּ��� : koreaedu1384!@
//������ �Է����ּ���(M,F) : M
//���̵� �Է����ּ��� : sample13@naver.com
//��й�ȣ�� �Է����ּ��� : koreaedu1384!@
// //������ �Է����ּ���(M,F) : F
//���̵� �Է����ּ��� : sample14@naver.com
//��й�ȣ�� �Է����ּ��� : koreaedu1384!@
//������ �Է����ּ���(M,F) : M

//���� ���̺� 
//=======================================
//1. sample12@naver.com koreaedu1384!@  M
//2. sample13@naver.com koreaedu1384!@  F
//3. sample14@naver.com koreaedu1384!@  M
//=======================================
int main()
{
	//���� �������� �ݺ� -> �迭 + for�� �����ϱ� �ʹ� ����.
	struct user table[3];

	//�迭�� ������ŭ �ݺ� �õ�
	for (int i = 0; i < 3; i++)
	{
		printf("���̵� �Է����ּ��� :");
		scanf("%s", table[i].id);
		//id�� char[] ���� & ���� �ʴ´�.
		getchar();

		//���� ���� ����/ ���� �Է�? getchar()

		printf("��й�ȣ�� �Է����ּ��� : ");
		scanf("%s", table[i].pw);
		getchar();

		printf("������ �Է����ּ���(M,F) :");
		scanf("%c", &table[i].gender);
		//gender�� char ���� & ����.
		getchar();
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d. %s %s %c \n", i + 1, table[i].id, table[i].pw, table[i].gender);
	}


	return 0;
}