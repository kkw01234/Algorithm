#include <cstdio>
#include <vector>
#include<stdlib.h>
using namespace std;
//분할정복 이용
int count1[3] = { 0,0,0 };
int **arr;
void divide(int mini, int minj, int n) {
	if (n == 1) {
		count1[arr[mini][minj]+1]++;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[mini][minj] != arr[mini+i][minj+j]) {
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						divide( mini + n / 3 * x, minj + n / 3 * y, n / 3);
					}
					
				}
				return;
			}
		}
	
	}
	count1[arr[mini][minj] + 1]++;
	return;
	
	//분할

	
}

int main()
{
	int n;
	scanf("%d", &n);
	
	arr = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
		
	}


	divide(0, 0,n);

	printf("%d\n%d\n%d\n", count1[0], count1[1], count1[2]);
	
	return 0;
}
