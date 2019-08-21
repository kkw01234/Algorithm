#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> arr;
vector<int> visited;
int bfs(int a, int b) {
	bool find = false;
	queue<int> q;
	visited[a] = true;
	q.push(a);
	int level = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int j = 0; j < qsize; j++) {
			int curr = q.front();
			q.pop();
			if (curr == b) {
				queue<int> empty;
				find = true;
				swap(q, empty);
				break;
			}
			for (int i = 0; i < arr[curr].size(); i++) {
				if (!visited[arr[curr][i]]) {
					
					visited[arr[curr][i]] = true;
					q.push(arr[curr][i]);
				}
			}
		}
		level++;
	}
	if (find)
		return level - 1;
	else
		return -1;
}

int main()
{
	int N, a, b, M, x, y;
	scanf("%d", &N);
	scanf("%d %d", &a, &b);
	scanf("%d", &M);
	arr.resize(N+1);
	visited.resize(N+1, 0);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	int result = bfs(a, b);
	printf("%d\n", result);
	
}
