#include<bits/stdc++.h>
#define pi acos(-1)

int main(){
	int n;
	double g;
	scanf("%d %lf", &n, &g);
	double resp = 0, v[100010];

	int d[100010], ang[100010];

	for(int i = 0; i < n; i++) scanf("%d %d", &d[i], &ang[i]);

	for(int i = n-1; i >=0; i--){
		double angulo = (double)ang[i];
		angulo = 2*pi*angulo/360.0;

		resp += d[i]*cos(angulo);

		v[i] = 2*g*resp;
	}

	for(int i = 0; i < n; i++){
		printf("%.10lf\n", sqrt(v[i]));
	}


}