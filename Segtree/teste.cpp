#include<bits/stdc++.h>
#define MAX 10010

using namespace std;

int main(){
    int n = 1, b = 1, v[MAX], bolas[MAX], certo = 1;
    for(int i = 0; i < MAX; i++) v[i] = 0;
    cin >> n >> b;

    while(n != 0 || b != 0)
    {
        certo = 1;
        for(int i = 0; i < b; i++)
        {
            cin >> bolas[i];
        }
        for(int i = 0; i < b; i++)
        {
            for(int j = i; j < b; j++)
            {
                v[abs(bolas[i]-bolas[j])] = 1;
            }
        }

        for(int i = 0; i <= n && certo; i++){
            certo = v[i];
        }

        if(!certo) cout << "N" << endl;
        else cout << "Y" << endl;
        for(int i = 0; i <= n; i++) v[i] = 0;
        cin >> n >> b;
    }


    return 0;
}
