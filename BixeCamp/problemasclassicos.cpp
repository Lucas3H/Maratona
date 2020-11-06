// Orientacao de triangulos:
/*
    Da para ver se um ponto está à direita ou à esquerda de uma determinada reta.

    A.
                  .B





       C.

       Se A -> B -> C -> A é o sentido horário, o det(Pa, Pb, Pc) > 0;
                           é p sentido anti horario, o det(Pa,Pb, Pc) < 0;
                           são colineares, o det é 0;
*/

// Contagem de inversões:
/*
        Usa-se o merge_sort:

        Quebrar o vetor V em dois, pela metade, digamos v1 e v2;
        ordeno v1 e v2 e aí monto o V usando dois ponteiros;

int inv_count(vector<int> &v){

        if(v.size() == 1) return 0;
        int mid = (v.size()/2);

        vector<int> v1, v2;

        for(int i = 0; i < mid; i++)v1.pb(v[i]);
        for(int i = mid; i < v.size(); i++) v2.pb(v[i]);

        int resp = 0;
        resp += inv_count(v1) + inv_count(v2);

        v1.pb(INF);
        v2.pb(INF);

        int i1 = 0, i2 = 0;

        for(int i = 0; i < v.size(); i++){
              if(v1[i1] <= v2[i2]) v[i] = v1[i1++];
              else{
                    v[i] = v2[i2++];
                    inv += v1.size() - i1 - 1;
             }
        }

        return inv;

*/

//LIS
/*
int lis(vector<int> v){
      int n = v.size();

      vector<int> aux(n+1, INF);
      aux[0] = -INF;

      for(int i = 0. i < n; i++){
            int j = upper_bound(aux.begin(), aux.end(), v[i]) - aux.begin();

            if(v[i] < aux[j]) aux[j] = v[i];
      }

      for(int i = n; i >= 0; i--) {
          if(aux[i] < INF) return i;
      }
}

*/

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

int main(){
	   ios::sync_with_stdio(false);


}
