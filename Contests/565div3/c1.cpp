#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back

typedef pair<int,int> pii;

typedef pair<int, int> ponto;

#define mem(v, k) memset(v, k, sizeof(v));

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);

#define ll long long

#define MAXN 500010

int lis(vector<int> v){
    vector<int> pilha;
    int resp = 0;
    fr(i, v.size()){
        auto j = lower_bound(pilha.rbegin(), pilha.rend(), v[i]) - pilha.begin();

        if(j == pilha.size()-1 && v[i] == 1) pilha.pb(1);
        else if(j == pilha.size()-1) resp++;
        else{
            if(pilha[j+1] == v[i] - 1) pilha[j+1] = v[i];
            else resp++;
        }
    }

    return resp;
}

int main(){
	   ios::sync_with_stdio(false);
     int n;
     cin >> n;

     int a[MAXN];
     vector<int> v;

     int b = -1, c = -1, d = -1, e = -1;

     fr(i, n) cin >> a[i];
     fr(i, n){
        if(a[i] == 4) v.pb(1);
        else if(a[i] == 8) v.pb(2):

        else if(a[i] == 15) v.pb(3):

        else if(a[i] == 16) v.pb(4):

        else if(a[i] == 23) v.pb(5):

        else if(a[i] == 42) v.pb(6):
     }

     cout << lis(v) << endl;
}
