#include<stdio.h>

#define F(x) x*x*x

using namespace std;

int main() {
	int n;
	int a, b, c, d;
	scanf("%d", &n);
	for (a = 3; a <= n; a++) {
		for (b = 2; b <= a; b++) 
			for (c = b; c <= a; c++) 
				for (d = c; d <= a; d++) {
					if (F(a) == F(b)+F(c)+F(d)) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					}
				}
	}
}