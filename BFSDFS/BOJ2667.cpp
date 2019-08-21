#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;
int arr[26][26];
int explore[26][26];
int dx[4] = { 1, -1 , 0, 0 };
int dy[4] = { 0,0,1,-1 };
int N,x;
vector<int> result;
void dfs(int x, int y, int& res) {
	explore[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (ax <0 || ay <0 || ax > N || ay > N) {
			continue;
		}
		if (arr[ax][ay] == 1 && !explore[ax][ay]) {
			res++;
			dfs(ax, ay, res);
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == '\n') {
				j--;
				continue;
			}
			arr[i][j] = arr[i][j] - '0';
		}

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int res = 0;
			if (arr[i][j] == 1 &&!explore[i][j]) {
				res++;
				dfs(i, j, res);
				if(res != 0)
					result.push_back(res);
			}
		}
	}
	printf("%d\n", result.size());
	sort(result.begin(),result.end());
	for (int i = 0; i < result.size(); i++) {
		printf("%d\n", result[i]);
	}

}