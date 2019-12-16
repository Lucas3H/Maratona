#include<iostream>
#include<algorithm>

using namespace std;

struct Piloto{
	int posicaoNoGranPrix[101];
	int pontosNoSistema[101];
};

struct SistemaDePontuacao{
	int pontosNaPosicao[101];
};

int main(){
	int pilotos=1, granPrix=1;
	cin >> granPrix >> pilotos;
	
	while(pilotos != 0 && granPrix != 0){
		Piloto P[101];
		
		//Ler as posicoes dos pilotos
		for(int i=1; i<=granPrix; i++){

			for(int j=1; j<=pilotos; j++){
				
				int pos;
				cin >> pos;
				P[j].posicaoNoGranPrix[i]=pos;//O piloto de numero numeroPiloto ficou na posicao j no grandPrix i
							
			}
		}
		
		//Ler os Sistemas de Pontuacao
		int sistemas;
		cin>>sistemas;
		
		SistemaDePontuacao S[sistemas+1];
		
		for(int i=1; i<=sistemas; i++){
			int x;//x é o numero de caras que recebem pontuacao.
			cin>>x;
			
			for(int j=1; j<=pilotos; j++){
				if(j<=x){
					int y; // y é o numero de pontos que o jogador da posicao j ganha. 
					cin>>y;
					S[i].pontosNaPosicao[j]=y;
					P[j].pontosNoSistema[i]=0;
				}
				else{
					S[i].pontosNaPosicao[j]=0;
					P[j].pontosNoSistema[i]=0;
				}
			}
		}
		
		//Calcular as pontuacoes dos pilotos de acordo com os sistemas de pontuacao.
		
		for(int j=1; j<=sistemas; j++){
			int maior=0;
			
			for(int i=1; i<=pilotos; i++){
				for(int k=1; k<=granPrix; k++){
					P[i].pontosNoSistema[j]+=S[j].pontosNaPosicao[P[i].posicaoNoGranPrix[k]];				
				}
				
				if(P[i].pontosNoSistema[j]>maior){
					maior=P[i].pontosNoSistema[j];
				}			
			}
			
			for(int i=1; i<=pilotos; i++){
				if(P[i].pontosNoSistema[j]==maior){
					cout<<i<<" ";
				}
			}
			
			cout<<"\n";
		}
		
		cin >> granPrix >> pilotos;
	}
}
