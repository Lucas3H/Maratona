#include<bits/sdtc++.h>

using namespace std;

int v[MAXN];
int n;

int busca_binaria(int x){
    int ini = 0, fim = n, meio;

    while(ini < fim - 1){
        meio = (ini + fim)/2;

        if(v[meio] == x){
            return meio;
        }
        else if(v[meio] > x){
            fim = meio;
        }
        else{/*ini = meio*/
            ini = meio;
        }
    }

    return -1;
}

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v, v + n);

    int x;

    while(true){
        cin >> x;

        cout << busca_binaria(x) << endl;
    }
}