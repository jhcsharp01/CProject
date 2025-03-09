#include <stdio.h>
//백트래킹(Backtracking)
//모든 경우의 수를 시도하면서, 조건을 만족하지 않는 경우
//다시 되돌아 가서 다른 경로를 시도하는 방식의 풀이
//해당 방식의 구현은 주로, 자기 자신을 다시 호출하는 재귀식 설계로
//구현되는 경우가 많습니다.
//동작 과정
//1. 선택 : 가능한 수를 하나 선택합니다.
//2. 검증 : 선택된 수가 조건을 만족하는지 확인합니다.
//3. 재귀 호출 : 조건을 만족했을 경우 다음 단계로 진행합니다.
//4. 백트래킹  : 조건을 만족하고 잇지 않을 경우 선택을 취소하고 이전 단계로 돌아갑니다.

// == 구현 시작 == 
//1. 숫자 사용 여부에 대한 배열을 작성
int used[9];
//2. 수열을 담을 배열을 작성 
int path[9];

//3. 함수 설계
//N : 범위
//M : 선택된 수 개수
//depth :  현재까지 선택된 수의 개수
//path : 현재까지 선택된 수열을 담은 배열
void Backtracking(int N, int M, int depth, int path[])
{
	//4. 조건) 현재까지 선택된 수가 M과 동일한 경우의 작업
	if (depth == M)
	{
		//설정된 결과 값 출력
		for (int i = 0; i < M; i++)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}
	//5. 일반적인 경우 진행할 작업
	//현재 문제에서는 1부터 N까지의 범위를 사용하고 있습니다.
	for (int i = 1; i <= N; i++)
	{
		//6. used[i]가 사용되지 않은 상태라면(used[i]의 값이 0인 경우)
		if (!used[i])
		{
			used[i] = 1; //사용 중이라고 설정하겠습니다. (C 프로그래밍에서 1은 true, 0은 false를 의미합니다.)
			path[depth] = i; //현재의 i 값을 작업 순서(depth)에 있는 path에 등록합니다.

			//7. 백트래킹 작업(다음 단계로 넘어가기)
			//depth(진행순서)의 값을 1 증가시켜서, 다시 함수(backtracking)을 호출하는 작업을 진행합니다.
			Backtracking(N, M, depth + 1, path);
			//8. 위의 작업이 마무리되면 사용했던 used[i]를 다시 0으로 만들어서 비사용 처리 진행
			used[i] = 0;
		}
	}
}

int main()
{
	int N, M;

	scanf_s("%d %d", &N, &M); //N과 M을 순서대로 입력(띄어쓰기나 Enter 기준)

	Backtracking(N, M, 0, path);
	//배열의 시작 값이 0이기 때문에 depth는 0을 넣어서 순차적으로 작업이 진행될 것입니다.


	//해당 문제의 작업 순서
	//1. scanf에 의해 N과 M이 결정됩니다. ex) 3 2
	//2. Backtracking(3,2,0,path) 호출이 진행됩니다.
	//3. 내부에서 M과 depth(0)은 서로 같지 않음. 반복문 실행
	//   i = 1, used[1] = 1 , path[0] = 1
	//   Backtracking(3,2,1,path)
	//		조건 상 현재 used[1]은 1로 사용되고 있음, 따라서 i = 1은 패스
	//		i = 2, used[2] = 1, path[1] = 2
	//		Backtracking(3,2,2,path)
	//		M과 depth가 동일하기 때문에 전체 출력하고 작업 종료   결과 : 1 2 출력
	//		used[2] = 0
	//	i = 3, used[3] = 1, path[1] = 3
	//	Backtracking(3,2,2,path)  --->  1 3 출력 used[3] = 0
	//  used[1] = 0, depth = 0
	//1차 작업 종료 다음 반복문으로 이동합니다.

	// i = 2일 경우
	// used[2] = 1 , path[0] = 2
	//	Backtracking(3,2,1,path)
	//  i = 1, used[1] = 1, path[1] = 1
	//  Backtracking(3,2,2,path)  -->  2 1
	//  i = 3, used[3] = 1, path[1] = 3
	//	Backtracking(3,2,2,path) --> 2 3
	//  used[2] = 0
	// 2차 작업 종료

	//i = 3일 경우
	// used[3] = 1 , path[0] = 3
	// Backtracking(3,2,1,path)
	// i = 1 path[1] = 1
	// Backtracking(3,2,2,path) --> 3 1
	// i = 2 path[1] = 2
	// Backtracking(3,2,2,path) --> 3 2
	//작업 종료
	
	return 0;
}