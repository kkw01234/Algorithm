#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;
char arr[101][101];
int notWeak[101][101];
int colorWeak[101][101];
int dx[4] = { 1, -1 , 0, 0 };
int dy[4] = { 0,0,1,-1 };
int N;

vector<int> result;
void dfs(int x, int y, char ch) {
	notWeak[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx <0 || cy <0 || cx > N - 1 || cy > N - 1) {
			continue;
		}
		if (arr[cx][cy] == ch && !notWeak[cx][cy]) {
			dfs(cx, cy, ch);
		}
	}
}
void dfs2(int x, int y, char ch) {
	colorWeak[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (cx <0 || cy <0 || cx > N - 1 || cy > N - 1) {
			continue;
		}
		if ((ch == 'R' || ch == 'G') && (arr[cx][cy] == 'R' || arr[cx][cy] == 'G')) { // R or G
			if (!colorWeak[cx][cy]) {
				dfs2(cx, cy, ch);
			}
		}
		else { //B
			if (arr[cx][cy] == ch && !colorWeak[cx][cy]) {
				dfs2(cx, cy, ch);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == '\n') {
				j--;
				continue;
			}
		}
	}
	int notperson=0;
	int weakperson=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!notWeak[i][j]) {
				notperson++;
				dfs(i, j, arr[i][j]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!colorWeak[i][j]) {
				weakperson++;
				dfs2(i, j, arr[i][j]);
			}
		}
	}
	printf("%d %d", notperson, weakperson);
}