#include <iostream>
#define MAX 100000

using namespace std;

int main(){
	int n, x = -MAX;
    int fita[10010], cor[10010];
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> fita[i];
    
    for(int i = 1; i <= n; i++){
    	if(fita[i] == 0){
        	x = i;
            cor[i] = 0;
        }
       	cor[i] = i - x;
    }
    
    x = MAX;
    
    for(int i = n; i >= 1; i--){
    	if(fita[i] == 0){
        	x = i;
            cor[i] = 0;
        }
       	if(cor[i] > x - i) cor[i] = x - i;
        
        if(cor[i] > 9) cor[i] = 9;
    }
    
    for(int i = 1; i <= n; i++) cout << cor[i] << " ";
    
    cout << endl;
    
    return 0;
}
