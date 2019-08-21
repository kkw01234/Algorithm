#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;
int arr[101][101];
int explore[101][101];
int dx[4] = { 1, -1 , 0, 0 };
int dy[4] = { 0,0,1,-1 };
int N, M, K;
int result = 0;
int dfs(int x, int y, int res) {
	explore[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (ax <0 && ay <0 && ax > N-1 && ay > M-1) {
			continue;
		}
		if (arr[ax][ay] == 1 && !explore[ax][ay]) {
			res++;
			res = dfs(ax, ay, res);
		}
	}
	return res;
}



int main()
{
	int x,y;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int res=0;
			if(!explore[i][j]) res = dfs(i, j,res);
			if (res > result) {
				result = res;
			}
		}
	}
	printf("%d\n", result);
}
