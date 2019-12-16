#include <iostream>
#define MAXN 100000


using namespace std;

int main(){
	int n;
	int s[MAXN];
	int v[10];
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> s[i];
		
		while (true){
			if(s[i] < 10){
				v[s[i]]++;
				break;
			}
			
			v[s[i]%10]++;
			s[i]/=10;	
		}
	}
	
	for(int i=0; i<10 ; i++) cout << i << " - " << v[i] << endl;
	
	return 0;
}
