#include <iostream>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;
const int a[6] = { 1,0,0,-1,0,0 }; //x
const int b[6] = { 0,1,0,0,-1,0 }; //y
const int c[6] = { 0,0,1,0,0,-1 }; //z
int main()
{
	
	int M, N, H;
	scanf("%d %d %d", &M, &N, &H);

	vector<vector<vector<int>>> arr(H,vector<vector<int>>(N,vector<int>(M,0)));
	queue<tuple<int, int, int>> q;
	vector<vector<vector<int>>> dist(H, vector<vector<int>>(N, vector<int>(M, 0)));

	for (int i = 0; i< H; i++) {//z
		for (int j = 0; j < N; j++) { //y
			for (int k = 0; k < M; k++) {//x
				scanf("%d",&arr[i][j][k]);
				if (arr[i][j][k]==1) {
					q.push(make_tuple(i,j,k));
				}
			}
		}
	}

	while (!q.empty()) {
		tuple<int, int, int> t = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int	a1 = get<2>(t)+a[i]; //x
			int b1 = get<1>(t)+b[i]; //y
			int c1 = get<0>(t)+c[i]; //z
			if (a1>=M || b1>=N || c1>=H || a1<0 || b1<0 || c1<0) {
				continue;
			}
			if (arr[c1][b1][a1] == 0) {
				arr[c1][b1][a1] = 1;
				q.push(make_tuple(c1, b1, a1));
				dist[c1][b1][a1] = dist[get<0>(t)][get<1>(t)][get<2>(t)]+1;
			}

		}


	}

	int count = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				count = max(dist[i][j][k], count);
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0) {
					count = -1;
					break;
				}
			}
			
			if (count == -1)
				break;
		}
		if (count == -1)
			break;
	}

	printf("%d", count);
}

