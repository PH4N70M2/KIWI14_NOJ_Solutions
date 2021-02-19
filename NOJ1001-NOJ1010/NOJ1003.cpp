#include<cstdio>

int f;

int Fibonacci(int n){
	int a=1,b=1,c;

	if(n>2){
		for(int i=1;i<=n-2;i++){
			c=a+b;
			a=b;b=c;
		}
	}
	else 
		if(n) 
			c=1;
		else 
			c=0;

	return c;
}

int main(){
	int n;
	scanf("%d", &n);

	printf("%d", Fibonacci(n));
}