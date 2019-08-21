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
int N,M,K;
int ax, ay, bx, by;
vector<int> result;
void dfs(int x, int y, int& res) {
	explore[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx <0 || cy <0 || cx > M-1 || cy > N-1) {
			continue;
		}
		if (arr[cx][cy] == 0 && !explore[cx][cy]) {
			res++;
			dfs(cx, cy, res);
		}
	}
}

int main()
{
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &ax, &ay, &bx, &by);
		for (int j = ay; j < by; j++) {
			for (int k = ax; k < bx; k++) {
				arr[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int res = 0;
			if (arr[i][j] == 0 && !explore[i][j]) {
				res++;
				dfs(i, j, res);
				result.push_back(res);
			}
		}
		
	}
	printf("%d\n", result.size());
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
}