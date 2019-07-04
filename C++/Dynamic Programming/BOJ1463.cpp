#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//BOJ 1463

int arr[1000001];
int main()
{
	int n, count = 0, num = 2;
	scanf("%d", &n);
	arr[1] = 0;
	while (n!=1) { //1일경우는 바로 종료시켜준다.
		if (num % 3 == 0 && num % 2 == 0) {
			arr[num] = min(arr[num / 3], min(arr[num / 2], arr[num - 1])) + 1;
		}
		//종료조건
		else if (num % 2 == 0) { //짝수일때
			arr[num] = min(arr[num/2],arr[num-1]) +1;
		}
		else if (num % 3 == 0) { //3의 배수일때
			arr[num] = min(arr[num / 3],arr[num-1]) + 1;
		}
		else
			arr[num] = arr[num - 1] + 1;
		
		if (num == n) {
			break;
		}	
		num++;
	}

	printf("%d", arr[num]);
	return 0;
}