#include <iostream>
#include <vector>
#include <queue>



using namespace std;
const int a[4] = { 0,0,1,-1 };
const int b[4] = { 1,-1,0,0 }; //0=>오른쪽 1=>왼쪽 2=>아래 3=> 위

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	vector<vector<int>> arr(N, vector<int>(M, 0));
	vector<vector<int>> dist(N, vector<int>(M, 0));
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {  
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}	
	}

	

	
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int hor = p.first + a[i]; 
			int ver = p.second + b[i];
			if (hor >= N || ver >= M || hor <0 || ver<0)
				continue;
			if (arr[hor][ver] == 0) {
				arr[hor][ver] = 1;
				q.push(make_pair(hor, ver));
				dist[hor][ver] = dist[p.first][p.second] + 1;
			}
		}
		
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			count = max(dist[i][j], count);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				count = -1;
				break;
			}
		}
		if (count == -1)
			break;
	}


	printf("%d", count);
}