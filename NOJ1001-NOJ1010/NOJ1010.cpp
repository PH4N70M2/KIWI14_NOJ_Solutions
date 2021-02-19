#include<stdio.h>

using namespace std;

int main() {
//	int arr[11] = {0};
	// log2(1000) < 10
	// But there is no need to simulate the sequence...
	int f[1001] = {0};

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		f[i]++;
		for (int j = 1; j <= i/2; j++) {
			f[i] += f[j];
		}
	}

	printf("%d", f[n]);

}
/*
    It is not difficult to work out the formula.
    f(n) = 1 + f(1) + ... + f(n/2)
	Use iteration to save time and space.
 */