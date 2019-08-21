#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int arr3[3][100001]; //받는 값
int result[3][100001]; //결과값
vector <int> answer;
int main()
{
	int T;
	scanf("%d", &T);
	for (int k = 0; k < T; k++) {
		int N;
		scanf("%d", &N);

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				scanf_s("%d", &arr3[i][j]);
			}
		}



		//Base cae
		result[0][0] = 0;
		result[1][0] = 0;
		result[0][1] = arr3[0][1];//처음부분
		result[1][1] = arr3[1][1];

		
		for (int i = 2; i <= N; i++) {
			result[0][i] = max(result[1][i - 1], result[1][i - 2]) + arr3[0][i]; // 한칸전 대각선 뗐을 경우, 두칸전 대각선 뗐을 경우 비교 후 더하기
			result[1][i] = max(result[0][i - 1], result[0][i - 2]) + arr3[1][i];

		}
		answer.push_back(max(result[0][N], result[1][N]));
	}

	for (int ans : answer) {
		printf("%d\n", ans);
	}