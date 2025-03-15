#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//파일 처리 방식
//open -> 작업 -> close

//작업 시 필요한 데이터
//1. 파일 포인터

int main()
{
	FILE* fp = NULL;

	fp = fopen("sample.txt", "w");
	//fopen(파일명.txt,파일모드);

	//파일이 비어있다면
	if (fp == NULL)
	{
		printf("파일 열기에 실패했습니다.\n");
	}
	else
	{
		printf("파일 열기에 성공했습니다.\n");
	}

	//파일 모드 종류
	//r : 읽기 (읽기 모드로 파일 염, 파일이 없을 경우 오류)
	//w : 쓰기 (파일이 없을 경우 파일 생성, 기존 파일 존재 시 기존 내용 삭제)
	//a : 추가 (파일이 있을 경우 데이터가 끝에 갱신 됨)

	fclose(fp); //파일 포인터 종료

	return 0;
}