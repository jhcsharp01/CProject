#include <stdio.h>

//2차원 배열 : 배열의 요소가 배열인 형태를 의미합니다.
//ex) int iarray[] = {1,2,3,4,5};   1차원 배열
//ex) int iarray2[][] = { {1,2,3}, {4,5,6}, {7,8,9}}; 2차원 배열

//주로 for문을 이용해서 배열을 출력을 하게 되는데 그 기준으로 배열 만드는 방법
//자료형 배열명[세로열][가로열];

int main()
{
	int iArray2[3][4] =
	{
		{1,2,3,4}
		,
		{5,6,7,8}
		,
		{9,10,11,12}
	};

	for (int i = 0; i < 3; i++) //세로열 부분에 대한 반복
	{
		//세로열 작업을 진행하는 동안 반복시킬 가로열에 대한 반복
		for (int j = 0; j < 4; j++)
		{
			printf("%2d ", iArray2[i][j]);
		}
		printf("\n"); //띄어쓰기 진행(열 구분)
	}
	//i가 0일 때, j가 0부터 3까지 반복
	//i가 1일 때, j가 0부터 3까지 반복
	//i가 2일 때, j가 0부터 3까지 반복
	//작업 종료


	int value2[3][3]; //3 x 3 의 형태의 2차원 배열 선언
	int value = 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			value2[i][j] = value++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", value2[i][j]);
		}
		printf("\n");
	}


	//연습 문제
	//출력 예시를 참고하여, 이차원 배열 value3를 만드세요.
	//단, 배열 생성과 초기화를 동시에 진행하지 않습니다.
	// 
	//  값       인덱스
	//1 6 7    00 01 02
	//2 5 8    10 11 12
	//3 4 9    20 21 22

	int value3[3][3];
	value = 1;

	//작업
	for (int i = 0; i < 3; i++)
	{
		//i가 짝수인 경우에는 순서대로 값이 증가
		if (i % 2 == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				//1. 현재 값의 증가가 아래로 진행되고 있음. 따라서 i와 j의 대입 순서를 변경
				value3[j][i] = value++;
			}
		}
		else//i가 홀수인 경우라면 반대로 값이 증가하도록 설정
		{
			for (int j = 2; j >= 0; j--)
			{
				
				value3[j][i] = value++;
			}
		}
	}

	//출력
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", value3[i][j]);
		}
		printf("\n");
	}

	//도전 과제 1 난이도 하
<<<<<<< HEAD
	// 1 2 3     00 01 02
	// 6 5 4     10 11 12
	// 7 8 9     20 21 22

	int value4[3][3];
	value = 1;

	printf("\n과제 1\n");
	//패턴 구현
	//value4[i][j]라고 할 때, i가 짝수인 경우는 j가 순차적으로 증가할 때, 값이 추가합니다.
	//                       i가 홀수인 경우에는 j가 마지막 위치부터 첫번째 위치까지 값이 역순으로 증가합니다.
	for (int i = 0; i < 3; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				value4[i][j] = value++;
			}
		}
		else
		{
			for (int j = 2; j >= 0; j--)
			{
				value4[i][j] = value++;
			}
		}
	}
	//출력
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", value4[i][j]);
		}
		printf("\n");
	}

=======
	// 1 2 3
	// 6 5 4
	// 7 8 9
>>>>>>> 4457c4c037900706789612f7b504ed194168f330

	//도전 과제 3 난이도 상
	// 1 2 3
	// 8 9 4
	// 7 6 5
<<<<<<< HEAD
	int value5[3][3];
	value = 1;

	int top = 0;
	int bottom = 2;
	int left = 0;
	int right = 2;

	//배열의 길이만큼 반복 작업
	for (int arrays = 0; arrays < (sizeof(value5) / sizeof(int)) - 1; arrays++)
	{
		// -> 방향 구현
		for (int i = left; i <= right; i++)
		{
			value5[top][i] = value++;
		}
		top++;
		// 오른쪽 방향 구현
		for (int i = top; i <= bottom; i++)
		{
			value5[i][right] = value++;
		}
		right--;
		//아래 방향
		for (int i = right; i >= left; i--)
		{
			value5[bottom][i] = value++;
		}
		bottom--;
		//<- 방향 구현
		for (int i = bottom; i >= top; i--)
		{
			value5[i][left] = value++;
		}
		left++;
	}

	printf("\n과제 2\n");
	//출력
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", value5[i][j]);
		}
		printf("\n");
	}
=======




>>>>>>> 4457c4c037900706789612f7b504ed194168f330

	return 0;
}