#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;
int a[4] = { 1,-1,0,0 };
int b[4] = { 0,0,1,-1 };
int main()
{	
	int N, M;
	scanf("%d %d", &N,&M);
	vector <vector<int>>arr(N, vector<int>(M, 0));
	vector <vector<int>>dist(N, vector<int>(M, 0));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < M; j++) {
			arr[i][j] = (st.at(j)-'0');
		}
	}
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair <int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a1 = p.first + a[i];
			int b1 = p.second + b[i];
			if (a1 >= N || b1 >= M || a1 < 0 || b1 < 0)
				continue;
			if (arr[a1][b1] == 1) {
				arr[a1][b1] = -1;
				q.push(make_pair(a1, b1));
				dist[a1][b1] = dist[p.first][p.second]+1;
			}
		}
	}
	

	printf("%d", dist[N-1][M-1]+1);

}

