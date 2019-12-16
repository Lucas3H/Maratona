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

#define MAXN 100010

map<string, string> pai;
mpa<string, int> peso_pai;
map<string, string> anto;
mpa<string, int> peso_anto;

string find_pai(string x){
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

string find_anto(string x){
    if(anto[x] == x) return x;
    else return anto[x] = find(anto[x]);
}

void join_pai(string a, string b){
    a = find_pai(a);
    b = find_pai(b);

    if(a == b) return;

    if(peso_pai[a] < peso_pai[b]) swap(a, b);

    pai[b] = a;
    peso_pai[a] += peso_pai[b];
}

void join_anto(string a, string b){
    string synA = find_pai(a), synB = find_pai(b);

    if(anto[synA] != synA){
        join_pai(anto[synA], synB);
    }
    else{
        anto[synA] = synB;
    }

    if(anto[synB] != synB){
        join_pai(anto[synB], synA);
    }
    else{
        anto[synB] = synA;
    }
}

int main(){
		ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    fr(i, n){
        string s;
        cin >> s;
        pai[s] = s;
        peso_anto[s] = 1;
        anto[s] = s;
        peso_pai[s] = 1;
    }

    fr(i, m){
        int x;
        string a, b;
        cin >> x >> a >> b;

        if(x == 1){
            string synA = find_pai(a), synB = find_pai(b);
            string antA = find_pai(anto[synA]), antB = find_pai(anto[synB]);

            if((anto[synA] != synA && antA == synB) || (anto[synB] != synB && synA == antB)){
                cout << "NO" << endl;
                continue;
            }

            cout << "YES" << endl;
            join_pai(a, b);
        }
        else{
            string synA = find_pai(a), synB = find(b);

            if(synA == synB){
                cout << "NO" << endl;
                continue;
            }

            cout << "YES" << endl;
            join_anto(a, b)
        }
    }
}
