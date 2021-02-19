#include<cmath>
#include<iostream>
using namespace std;

template <typename TYPE>
void chain_op(TYPE* p, int n){
	for (int i=1; i<=n; i++) {
		cin>>p[i];
	}
	for (int i=n; i; i--) {
		cout<<p[i]<<' ';
	}
	cout<<'\n';

	TYPE tgt;
	cin>>tgt;
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		while ( fabs(p[i] - tgt)<=1e-6 ) {
			for (int j=i; j<=n; j++) {
				p[j]=p[j+1];
			}
			cnt++;
		}
	}
	for (int i=n-cnt; i; i--) {
		cout<<p[i]<<' ';
	}
	cout<<'\n';
}


int main(){
	int n;

	cin>>n;
	int* p1 = (int*)calloc(n+1, sizeof(int));
	chain_op(p1, n);
	free(p1);

	cin>>n;
	char* p2 = (char*)calloc(n+1, sizeof(char));
	chain_op(p2, n);
	free(p2);

	cin>>n;
	double* p3 = (double*)calloc(n+1, sizeof(double));
	chain_op(p3, n);
	free(p3);
}
