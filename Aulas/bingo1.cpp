#include<iostream>

using namespace std;

int main(){
    int n, b;
    scanf("%d %d", &n, &b);

    while(n != 0 && b != 0){
        int v[100];
        
        for(int i = 0; i < b; i++){
            scanf("%d", &v[i]);
        }

        int eh_possivel[100];
        /*
            eh_possivel[i] = 0, se i não pode ser anunciado
            eh_possivel[i] = 1, se i pode ser anunciado
        */

        for(int i = 0; i <= n; i++){
            eh_possivel[i] = 0;
        }

        for(int i = 0; i < b; i++){
            
            for(int j = 0; j < b; j++){
                
                if(v[i] > v[j]){
                    eh_possivel[ v[i] - v[j] ] = 1;
                }
                else{
                    eh_possivel[ v[j] - v[i] ] = 1;
                }
                
            }

        }




        int deu_certo = 1;
        /*
            deu_certo = 1, se todo mundo eh possivel
            deu_certo = 0, se nem todo mundo eh possivel
        */
        for(int contador = 0; contador <= n; contador++){
            if(eh_possivel[contador] == 0){
                deu_certo = 0;
                break;
            }
        }



        if(deu_certo == 1){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }



        scanf("%d %d", &n, &b);
    }
}