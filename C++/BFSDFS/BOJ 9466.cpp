#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;
int student[100001] = { 0 };
int visited[100001] = { 0 };
int finished[100001] = { 0 };
int result = 0;
int cycle = 0;
void dfs(int index) {
	visited[index] = 1;
	int next = student[index];
	if (visited[next]) {
		if (!finished[next]) {
			int temp = next;
			while (temp != index) {
				cycle++;
				temp = student[temp];
			}
			cycle++;
		}
	}
	else dfs(next);
	finished[index] = 1;
}



int main()
{
	int T;
	int n;
	scanf("%d", &T);
	for (int idx = 0; idx < T; idx++) {
		memset(student, 0, sizeof(student));
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		result = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &student[i]);
		}
		cycle = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				dfs(i);
		}
		
		printf("%d\n", n - cycle);
	}
	
	

}