#include<stdio.h>
using namespace std;

int main(){
	int n, tmp, min, max;

	while( ~scanf("%d", &n) ){
		min = 101;
		max = -1;
		while(n--){ 
			scanf("%d", &tmp);
			if (tmp > max) { 
				max = tmp;
			}
			if (tmp < min) { 
				min = tmp;
			}
		}
		printf("%d %d\n", max, min);		
	}
}