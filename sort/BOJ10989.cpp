#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int list[10001];
int main() //countingsort
{
	scanf("%d", &n);

	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		list[x]++;
	}
	int count = 0;
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < list[i]; j++) {
			printf("%d\n", i);
			count++;
		}
		if (count == n)
			break;
	}
}