#include <iostream>

using namespace std;

struct REG{
  int id;
  char nome[30];
  char capital[30];
  char sigla[3];
  int populacao;
    
};

void mostra_registro(REG reg){
    printf("\nID.......: %d", reg.id);
    printf("\nNome.......: %s", reg.nome);    
    printf("\nCapital.......: %s", reg.capital);    
    printf("\nSigla.......: %s", reg.sigla);
    printf("\nPopulacao.......: %d", reg.populacao);  
    
}

int le_arquivoB(REG v[], int tam){
    int i = 0;
    FILE *arq;
    arq = fopen("Estado2.dat","rb"); // estado2.dat esta no teams
    
    if(arq==NULL){
        printf("\nO arquivo não foi aberto");
    }else{
        for(; !feof(arq) and 1<tam;i++){
            fread(&v[i],sizeof(REG),1,arq);
            if(feof(arq))
            i--;
        }
        fclose(arq);
    }
    
    return 1;
    
}

int main(){
    
  REG est[30];
  int tam = le_arquivoB(est,27);
  
  for(int i=0; i<tam;i++){
      mostra_registro(est[i]);
  }
    
    
}
