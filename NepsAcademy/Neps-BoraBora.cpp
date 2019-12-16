#include <bits/stdc++.h>

using namespace std;

bool ordenacao(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return a.second > b.second;
	else return a.first > b.first;
}

int main(){
	int jog, mao, n;
	cin >> jog >> mao >> n;

	while(jog + mao + n > 0){
		vector<pair<int, int>> baralho;

		for(int i = 0; i < n; i++){
			int a, b;
			char c;

			cin >> a >> c;

			if(c == 'C') b = 0;
			else if(c == 'D') b = 1;
			else if(c == 'H') b = 2;
			else if(c == 'S') b = 3;

			baralho.push_back(make_pair(a,b));
		}


		vector<pair<int, int>> v[10];

		for(int i = 0; i < jog; i++){

			for(int j = 0; j < mao; j++){
				v[i].push_back(baralho[0]);

				baralho.erase(baralho.begin(), baralho.begin() + 1);
			}

			sort(v[i].begin(), v[i].end(), ordenacao);
		}

		int sentido;

		pair<int, int> mesa = baralho[0];
		baralho.erase(baralho.begin(), baralho.begin()+1);

		int turno = 0, tem = 1, bar = baralho.size();

		if(mesa.first == 12){
			sentido = -1;
			turno = 1;
		}
		else {
			turno = jog - 1;
			sentido = 1;
		}
		do{

			if(turno + sentido >= 0 && turno + sentido < jog) turno = (turno + sentido);
			else if(turno+sentido >= jog) turno = turno + sentido - jog;
			else turno =  turno + sentido + jog;

			if(tem == 1){
//				if(mesa.first == 11) cout << "Jogador " << turno + 1 << " perdeu a vez!" << endl;
				if(mesa.first == 7){
//					cout << "Jogador " << turno+1 << " comprou a carta " << baralho[0].first << " " << baralho[0].second << endl;
					v[turno].push_back(baralho[0]);
					baralho.erase(baralho.begin(), baralho.begin()+1);
//					cout << "Jogador " << turno+1 << " comprou a carta " << baralho[0].first << " " << baralho[0].second << endl;
					v[turno].push_back(baralho[0]);
					baralho.erase(baralho.begin(), baralho.begin()+1);
					bar-=2;

					sort(v[turno].begin(), v[turno].end(), ordenacao);
				}
				else if(mesa.first == 1){
//					cout << "Jogador " << turno+1 << " comprou a carta " << baralho[0].first << " " << baralho[0].second << endl;
					v[turno].push_back(baralho[0]);
					baralho.erase(baralho.begin(), baralho.begin()+1);
					bar--;

					sort(v[turno].begin(), v[turno].end(), ordenacao);
				}

				if(mesa.first == 11 || mesa.first == 7 || mesa.first == 1){
					if(turno + sentido >= 0 && turno + sentido < jog) turno = (turno + sentido);
					else if(turno+sentido >= jog) turno = turno + sentido - jog;
					else turno =  turno + sentido + jog;
				}
			}

//			cout << "Jogador " << turno + 1 << " /mesa: " << mesa.first << " " << mesa.second << endl;
			tem = 0;

			for(int i = 0; i < v[turno].size(); i++){
				if(v[turno][i].first == mesa.first || v[turno][i].second == mesa.second){
//					cout << "Jogador " << turno+1 << " descartou a carta " << v[turno][i].first << " " << v[turno][i].second << endl;
					mesa = v[turno][i];
					v[turno].erase(v[turno].begin()+i, v[turno].begin()+i+1);
					tem = 1;
					break;
				}
			}

			if(tem == 0){
				if(baralho[0].first == mesa.first || baralho[0].second == mesa.second){
//					cout << "Jogador " << turno+1 << " comprou a carta " << baralho[0].first << " " << baralho[0].second << " e a descartou!" << endl;
					mesa = baralho[0];
					baralho.erase(baralho.begin(), baralho.begin()+1);
					bar--;

					tem = 1;
				}
				else{
//					cout << "Jogador " << turno+1 << " comprou a carta " << baralho[0].first << " " << baralho[0].second << endl;
					v[turno].push_back(baralho[0]);
					baralho.erase(baralho.begin(), baralho.begin()+1);
					bar--;

					sort(v[turno].begin(), v[turno].end(), ordenacao);
				}
			}

			
/*			for(int j = 0; j < jog; j++){
				cout << "Jogador " << j+1 << endl;
				for(int i = 0; i < v[j].size(); i++){
					cout << v[j][i].first << " " << v[j][i].second << endl;
				}
			}
*/			
			if(tem == 1 && mesa.first == 12){
//				cout << "Mudou o sentido!" << endl;
				sentido = -sentido;
			}

		}while(v[turno].size() /*!= 0 && bar > 0*/);

		cout << turno + 1<< endl;
		cin >> jog >> mao >> n;
	}

	return 0;
}