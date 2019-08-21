#include <cstdio>
#include <vector>
using namespace std;
int N1;
int N2;
int M1;
int M2;

int main()
{
	
	scanf("%d %d", &N1, &M1);
	vector<vector<int>> arr1(N1, vector<int>(M1, 0));
	int x;
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < M1; j++) {
			scanf("%d", &x);
			arr1[i][j] = x;
		}
	}
	scanf("%d %d", &N2, &M2);
	vector<vector<int>> arr2(N2, vector<int>(M2, 0));
	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < M2; j++) {
			scanf("%d", &x);
			arr2[i][j] = x;
		}
	}
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < M2; j++) {
			int sum = 0;
			for (int k = 0; k < M1; k++) {
				sum+= arr1[i][k] * arr2[k][j];
			}
			printf("%d ", sum);
		}
		printf("\n");
	}
}
