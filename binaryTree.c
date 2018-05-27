#include<stdio.h>
#include<stdlib.h>


struct arvore{

  int info;
  struct arvore *dir, *esq;
};

typedef struct arvore Arvore;

int insere(int N, struct arvore **raiz);
void EmOrdem(struct arvore *raiz);
void PreOrdem(struct arvore *raiz);
void PosOrdem(struct arvore *raiz);
int buscar(int N, struct arvore *raiz);
int maiorValor(struct arvore *raiz);
int menorValor(struct arvore *raiz);


int main(){


int opcao = 0;
int n = 0;
Arvore* no = NULL;

while(opcao != -1){

  printf("\nMENU\n");
  printf("\n 1 - Inserir elemento arvore \n 2 - Imprimir arvore em ordem \n 3 - Imprimir arvore em pre-ordem \n 4 - Imprimir arvore em pos-ordem \n 5 - Buscar elemento arvore \n 6 - Maior valor \n 7 - Menor valor \n 8 - Sair \n");
  
  scanf("%d",&opcao);

  if(opcao == 1){

    printf("\n Digite o elemento para inserir: \n");
    
    scanf("%d",&n);

    insere(n,&no);
  }


  if(opcao == 2){

    EmOrdem(no);
  }


  if(opcao == 3){

    PreOrdem(no);
  }

  if(opcao == 4){

    PosOrdem(no);
  }

  if(opcao == 5){

    printf("\n Digite o elemento que deseja buscar: \n");
    
    scanf("%d",&n);

    buscar(n,no);
  }

  if(opcao == 6){

    maiorValor(no);
  }

  if(opcao == 7){

    menorValor(no);
  }

  if(opcao == 8){

    return(0);
  }


}//fecha while



}



int insere(int N, struct arvore **raiz){

if(*raiz == NULL){

  (*raiz) = (struct arvore *) malloc (sizeof(struct arvore));

  if(*raiz == NULL){
    
    printf("\n Heap Overflow! \n");

    return(-1);
  }

  (*raiz)->info = N;
  (*raiz)->esq= NULL; 
  (*raiz)->dir = NULL;

  printf("\n Insercao OK \n");

  return(1);

}


  if(N == (*raiz)-> info){ //Se a raiz for igual ao elemento que se está inserindo
   
    printf("\n Elemento ja existente \n");

    return(0);

  }

  if(N < (*raiz)->info){ //Se o numero que sera inserido for menor que raiz, entao insere esquerda

    return(insere(N,&(*raiz)->esq));

  }
	 
  return(insere(N,&(*raiz)->dir));

}


void EmOrdem(struct arvore *raiz){
  
  if(raiz){

    EmOrdem(raiz->esq);
    printf("%d ",raiz->info);
    EmOrdem(raiz->dir);

  }
}


void PreOrdem(struct arvore *raiz){
  
  if(raiz){
    
    printf("%d ",raiz->info);
    PreOrdem(raiz->esq);
    PreOrdem(raiz->dir);

  }
}

void PosOrdem(struct arvore *raiz){
  
  if(raiz){
    
    PosOrdem(raiz->esq);
    PosOrdem(raiz->dir);
    printf("%d ",raiz->info);

  }
}


int buscar(int N, struct arvore *raiz){

  if(raiz == NULL){
      
    printf("\nArvore nao possui o elemento!\n");
 
    return(-1);
    
  }

  if(raiz->info == N){
  
    printf("\n Elemento presente na arvore! \n");	
  
    return(0);

  }

  if(raiz->info > N){
   
    return(buscar(N,raiz->esq));

  }

    return(buscar(N,raiz->dir));

}


int maiorValor(struct arvore *raiz){


  if(raiz == NULL){

   printf("\n Arvore vazia! \n"); 
  
   return (-1);
  }
   
  if(raiz->dir == NULL && raiz->esq != NULL || raiz->dir == NULL && raiz->esq == NULL ){


    printf("%d",raiz->info);
  }

  if(raiz->dir != NULL){
    
   return(maiorValor(raiz->dir));
  }
  
}


int menorValor(struct arvore *raiz){

  if(raiz == NULL){

   printf("\n Arvore vazia! \n"); 
  
   return (-1);
  }
   
  if(raiz->dir != NULL && raiz->esq == NULL || raiz->dir == NULL && raiz->esq == NULL ){

    printf("%d",raiz->info);
  }

  if(raiz->esq != NULL){
    
   return(menorValor(raiz->esq));
  }


}
