#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//C언어에서의 배열
//자료형 배열명[길이];

//배열에 값(요소 : element)을 넣는 방법
//배열명[인덱스] = 값;
//인덱스의 범위 = 0부터 배열의 길이 -1까지의 범위

//배열의 길이를 구하는 방법
// sizeof(배열명) / sizeof(자료형);

//배열의 크기를 구하는 방법
// sizeof(배열명);

int main()
{
	int iArray[5]; // 0 ~ 4
	iArray[0] = 1; //iArray의 0번째 요소는 1이 됩니다.
	iArray[1] = 2;
	iArray[2] = 3;
	iArray[3] = 4;
	iArray[4] = 5;
	printf("배열 iArray가 가지고 있는 요소 : ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", iArray[i]);
	}	
	printf("\n");
	int size = sizeof(iArray);
	printf("배열의 크기 : %d byte\n", size);
	int length = sizeof(iArray) / sizeof(int);
	printf("배열의 길이 : %d\n", length);
	printf("배열의 이름 : %p\n", iArray);
	//배열은 같은 형태의 데이터를 묶어서 따로 관리하는 데이터입니다.
	//각 배열의 요소는 일정한 간격으로 주소를 가지게 됩니다.
	//배열의 첫번째 요소의 주소는 배열의 시작 주소입니다. 배열의 시작 주소는 배열의 이름입니다.
	//배열은 선언과 동시에 데이터를 저장할 연속적인 메모리 저장 공간을 가지게 됩니다.
	//배열은 지정되는 값으로, 주소에 대한 변경을 진행할 수 없습니다.(수정 불가능한 데이터)

	return 0;
}