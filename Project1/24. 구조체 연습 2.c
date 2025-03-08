#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct user
{
	char id[40]; //ex) sample12@naver.com
	char pw[50]; //ex) koreaedu1384!@
	char gender; // 'M' , 'F'
};
//위의 구조체 user를 이용해 다음과 같은 출력 화면을 완성하세요.

//아이디를 입력해주세요 : sample12@naver.com
//비밀번호를 입력해주세요 : koreaedu1384!@
//성별을 입력해주세요(M,F) : M
//아이디를 입력해주세요 : sample13@naver.com
//비밀번호를 입력해주세요 : koreaedu1384!@
// //성별을 입력해주세요(M,F) : F
//아이디를 입력해주세요 : sample14@naver.com
//비밀번호를 입력해주세요 : koreaedu1384!@
//성별을 입력해주세요(M,F) : M

//유저 테이블 
//=======================================
//1. sample12@naver.com koreaedu1384!@  M
//2. sample13@naver.com koreaedu1384!@  F
//3. sample14@naver.com koreaedu1384!@  M
//=======================================
int main()
{
	//같은 데이터의 반복 -> 배열 + for문 접근하기 너무 좋다.
	struct user table[3];

	//배열의 개수만큼 반복 시도
	for (int i = 0; i < 3; i++)
	{
		printf("아이디를 입력해주세요 :");
		scanf("%s", table[i].id);
		//id는 char[] 따라서 & 쓰지 않는다.
		getchar();

		//문장 다음 문자/ 문장 입력? getchar()

		printf("비밀번호를 입력해주세요 : ");
		scanf("%s", table[i].pw);
		getchar();

		printf("성별을 입력해주세요(M,F) :");
		scanf("%c", &table[i].gender);
		//gender는 char 따라서 & 쓴다.
		getchar();
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d. %s %s %c \n", i + 1, table[i].id, table[i].pw, table[i].gender);
	}


	return 0;
}