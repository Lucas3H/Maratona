// 
#include<bits/stdc++.h>

using namespace std;

#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define frm(i, n) for(int i = n-1; i >= 0; i--)

#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double, double> ponto;
typedef vector<vector<ll>> matrix;

#define mem(v, k) memset(v, k, sizeof(v));

#define db cout << "Debug" << endl;

#define mp make_pair
#define pq priority_queue

#define mx(a, b) a = max(a, b);
#define mod(a, b) a = a%b;

#define MAXN 10010
#define MOD 1000000007
#define MAXL 30
#define ROOT 1
#define INF 987654321

/*
	A ideia principal é um guloso.
	Ou seja, devo ter em mente que devo pegar a vaca que me da mais galões.

	A primeira ideia iterar sobre o tempo e ir pegando a vaca que me da mais galoes que ainda não foi utilizada(Essa estrategia é quebrada pelo próprio exemplo do enunciado).

	Ao invés disso, vou iterar sobre as vacas, da que me da mais galões para a que me da menos, e ir marcando para cada vaca o tempo em que ela será ordenhada. Aqui vem o guloso de novo:
		
		Para cada vaca, o tempo que ela será ordenhada será o maior possível.
		
		(A lógica por trás é: se essa vaca já será ordenhada, vou colocá-la no maior tempo possível para que libere as primeiras posições para as próximas vacas, caso haja alguma com deadline pequeno). 

	Então se há o deadline da vaca I for 5 e as posições 6, 5, 4 já foram marcadas por vacas anteriores(Ou seja, vacas que dão mais galões que a vaca I), então eu vou marcar para a vaca I a posição 3.

	Se o deadline de uma vaca J for d e as posições 1, 2, 3, ..., d já foram marcadas, então ela não sera ordenhada. Sei que as vacas que estão nas posições 1, 2, 3, ..., d dão mais galões que a vaca J e estão no maior tempo possível. Então, pra colocar essa vaca J, eu teria que abrir mão de uma vaca que dá mais galões do que a vaca J, o que não é o ideal>

	Por que isso dá certo?

	Tome a configuração máxima, ou seja aquela que me da mais galões.

	Vamos primeiro ver o guloso de colocar a vaca no maior tempo possível:
		Seja V1 uma vaca que foi ordenhada, que dá G1 galões, D1 seja o seu deadline e ela foi marcada
		para o tempo T1. Defina V2, G2, D2, T2 da mesma maneira.
		
		Suponha agora que G1 > G2 e T1 < T2 <= D1(Ou seja, V1 da mais galões, mas V2 foi marcada em um tempo
		depois, mas antes do deadline D1).

		Então, se eu trocar os tempos de V1 e V2(Ou seja, V1 será ordenhada no tempo T2 e V2 no tempo T1), 
		vai dar na mesma, pois V1 foi ordenhada antes do seu deadline(T2 <= D1) e o tempo de V2 só diminuiu
		(Se dava antes, então com certeza da depois da troca).

	Agora vamos ver o guloso de pegar sempre as vacas que dão mais galões:
		Suponha que V1 não foi ordenhada, mas V2 foi.
		Ademais suponha que G1 > G2 e V2 <


*/
int n;
set<int> freePos;
pq<pii> fila;
int d, g;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	
	frr(i, n){
		cin >> g >> d;
		fila.push(mp(g, -d));
	}

	frr(i, MAXN){
		freePos.insert(-i);
	}

	int ans = 0;

	frr(i, n){
		auto x = freePos.lower_bound(fila.top().s);

		if(x != freePos.end()){
			ans += fila.top().f;
			freePos.erase((*x));
		}

		fila.pop();
	}

	cout << ans << endl;
}
