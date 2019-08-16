#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;
int result = 0;
int tb[4] = { 1,-1,0,0 }; //상하
int lf[4] = { 0,0,1,-1 }; //좌우
int T, M, N, K;
int arr[50][50] = { 0 };
int explore[50][50] = { 0 };
void dfs(int i, int j) {

	for (int k = 0; k < 4; k++) {
		int dx = i + tb[k];
		int dy = j + lf[k];
		if (dx >= 0 && dy >= 0 && dx < M && dy < N) {
			if (arr[dx][dy] == 1 && explore[dx][dy] == 0) {
				explore[dx][dy] = 1;
				dfs(dx, dy);
			}
		}
	}

}



int main()
{

	scanf("%d", &T);

	int x, y;
	for (int a = 0; a < T; a++) {
		scanf("%d %d %d", &M, &N, &K);
		memset(arr, 0, sizeof(arr));
		memset(explore, 0, sizeof(explore));
		result = 0;
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1 && explore[i][j] == 0) {
					result++;
					explore[i][j] = 1;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", result);
	
	}

}
