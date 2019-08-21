//다익스트라 알고리즘 적용
#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int V, E; //정점, 간선
	int K;//시작정점
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	vector<vector<pair<int,int>>> arr(E);
	vector<int> length(V + 1, -1);
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		arr[u].push_back(make_pair(v, w));

	}

	pq.push(make_pair(0, K));
	length[K] = 0;


	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		if (length[vertex] != -1&&length[vertex] < cost) {
			continue;
		}
		for (int i = 0; i < arr[vertex].size(); i++) {
			int n = arr[vertex][i].first;
			int distance = cost + arr[vertex][i].second;

			if (length[n] == -1||length[n] > distance) {
				length[n] = distance;
				pq.push(make_pair(distance,n));
			}
		}


	}
	for (int i = 1; i < V + 1; i++) {
		if (length[i] == -1) {
			printf("INF\n");
		}
		else
			printf("%d\n", length[i]);
	}

}