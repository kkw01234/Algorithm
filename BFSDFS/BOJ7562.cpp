#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, I;
vector<vector<int>> visited;

int dx[8] = {1,2,1,2,-1,-2,-1,-2};
int dy[8] = {2,1,-2,-1,-2,-1,2,1};
int bfs(pair<int, int> a, pair<int, int> b) {
	queue<pair<int,int>> q;
	q.push(a);
	int level = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == b.first && y == b.second) {
				queue<pair<int, int>> temp;
				swap(q, temp);
				break;
			}
			for (int i = 0; i < 8; i++) {
				if (x + dx[i] < 0 || y + dy[i]<0 || x + dx[i] > I - 1 || y + dy[i] > I - 1) {
					continue;
				}
				
				if (!visited[x + dx[i]][y + dy[i]]) {
					visited[x + dx[i]][y + dy[i]] = 1;
					q.push(make_pair(x + dx[i], y + dy[i]));
				}

			}
		}
		level++;
	}
	return level - 1;
}

int main()
{
	scanf("%d", &N);

	for (int tcase = 0; tcase < N; tcase++) {
		pair<int, int> start, end;
		scanf("%d", &I);
		visited.clear();
		for (int i = 0; i < I; i++) {
			vector<int> a;
			a.resize(I, 0);
			visited.push_back(a);
		}
		scanf("%d %d", &start.first, &start.second);
		scanf("%d %d", &end.first, &end.second);
		int result = bfs(start, end);
		printf("%d\n", result);
	}
	
	
	
}
