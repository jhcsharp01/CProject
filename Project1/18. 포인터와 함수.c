#include <stdio.h>
//포인터와 함수를 사용하는 방법
//1.Call by reference
//return을 쓰지 않고, 함수 작업 내에서 실제의 값의 변경을 진행할 수 있습니다.
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//2.배열 포인터(1차원 배열)
//포인터는 주소이기에, 1차원 배열에 대한 전달 값을 처리할 수 있습니다.
void printArray(int* p, int size) //배열은 매개변수로 받을 경우, 길이를 따로 전달해줘야 합니다.
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(p + i));
		//*(포인터 변수명 + 숫자)는 현재 포인터 기준으로 숫자만큼의 간격을 이동한 위치를 표현
	}
	printf("\n");
}
//3. 배열 포인터(2차원 배열)
//   자료형 (*포인터변수명)[가로열의 길이]
//   2차원 배열이기 때문에, 열과 행에 대한 크기를 각각 전달해줘야 합니다.
void print2Array(int (*p)[3], int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//4. 함수 포인터(함수의 이름을 전달해서, 그 기능을 사용할 수 있습니다.)
//   이때 포인터는 함수의 반환 형태와 동일하게 잡아줍니다.
//   장점 : 하나의 이름으로 함수를 돌려쓰는 것이 가능합니다.
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}

int main()
{
	int a = 10;
	int b = 7;
	Swap(&a, &b);
	printf("a = %d b = %d\n", a, b);

	int iarray[] = { 1,2,3,4,5 };

	printArray(iarray, 5); //배열에 대한 전달 시, 배열의 이름만 전달합니다.(배열의 이름 == 배열의 주소)

	int iarray2[2][3] = { {1,2,3} , {4,5,6} };

	print2Array(iarray2, 2, 3);
	
	//함수 포인터 선언
	//자료형 (*포인터명)(매개변수 데이터 형태)
	
	//NULL 포인터 : 현재 따로 가리키는 값이 없는 경우 써주는 값
	//포인터는 값이 있든 없든 그 위치를 가리키기 때문에, 지정을 안해주면 잘못된 값을 접근할 위험이 있음.
	int (*ptr)(int, int) = NULL;

	ptr = add; //함수의 이름 == 함수의 주소이므로, 이름을 전달해주면 ptr에 함수 add의 위치가 전달됩니다.
	printf("%d + %d = %d\n", a, b, ptr(a, b)); //ptr을 함수처럼 사용하면, add가 호출됩니다.

	ptr = sub; //다른 함수로 설정을 변경합니다.
	printf("%d - %d = %d\n", a, b, ptr(a, b)); //sub 호출

	return 0;
}