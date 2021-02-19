#include<stdio.h>
using namespace std;

int main() {
	
	int n;
	scanf("%d", &n);

	int arr[302] = {0};
	arr[0] = 1;

	int inc;
	int i;

	while (n--) {
		inc = 0;
		for (i = 0; i < 302; i++) {
			arr[i] <<= 1;
			arr[i] += inc;
			inc = arr[i] / 10;
			arr[i] %= 10;
		}
	}

	for (i = 301; !arr[i]; i--);
	
	do {
		printf("%d", arr[i]);
	} while(i--);

}
	/* 
		lg(2) == 0.30102, 
		lg(2^1000) == 1000*lg(2) == 301.2, 
		thus, the number can take up 302 digits at most
	 */
