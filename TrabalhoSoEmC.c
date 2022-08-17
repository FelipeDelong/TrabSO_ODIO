#include<stdio.h>
#include<stdlib.h>

int vetor1 [100];
int vetor2 [100];
int vetor3 [100];
int vetor4 [100];
int Processo=1;
int UltimoProcesso=0;


//////////////////////////
//Adiciona Processo - FIRST FIT
void AddProcessoFF(int resp){

 int tamanho=resp;
 int contador= 0;
 int inicio=0, final=1;


 for(int i=0; i<100; i++){
  
  if (vetor1[i] == 0){
  
  if (inicio==0){
  inicio=i;
  }
  
  contador++;
 
    if (contador == tamanho){
    final = i;
    break;
    }
 
  } else {
 inicio=0;
 contador=0;
   }
   
 }
 
 if(tamanho==1 && vetor1[0]==0){
   vetor1[0]=Processo;
   return;
  }
 
  if (final == 0 || tamanho>contador){
  printf ("\n Nao foi possivel adicionar o Processo. Memoria insuficiente\n");
  return;
  }
  
  if (inicio==1 && vetor1[0]==0){
  vetor1[0]=Processo;
  }
 
  for(int i=inicio; i<=final; i++){
   vetor1[i]=Processo;
  }
}


///////////////////////////
// Adiciona Processo - Best Fit
void AddProcessoBF(int resp){

int vetorCoordenada[200];
int num=0;
int menor=100, atual=-1;
int gordura=0;

 int contador= 0;
 int inicio=-1, final=-1;
 int resposta=resp;
 int gatilho=0;
 
  for (int p=0; p<100; p++){
   vetorCoordenada[p]=-1;
  }
 
 
 
 
 
 
 for(int i=0; i<100; i++){
  
  if (vetor2[i] == 0){
  
  if(inicio==-1){
  inicio=i;
  }
  
  contador++;
  if (contador>resposta){
  gordura++;
  }
  
  //Código muda a partir daqui
 
    if (contador >= resposta || i==99){
    
    final = i;
    
    //numero maximo
     if (i==99){
     
    vetorCoordenada[num]=inicio;
    vetorCoordenada[num+1]=final;    
         
     }
    //numero maximo - final 
     
    }
 
  } else {
  
      if(final !=-1){
      
    vetorCoordenada[num]=inicio;
    vetorCoordenada[num+1]=final;
    
    num=num+2;
    }
    
    
 //Zera o inicio e final
 contador=0;
 inicio=-1;
 final=-1;
 gordura=0;
    
   }
   
  }
  
  
  
  for(int g=0; g<100; g=g+2){
  
  atual= vetorCoordenada[g+1] - vetorCoordenada[g];

  
  //nao ta entrando no if
  if (atual < menor && atual != 0){
  menor= atual;
  inicio= vetorCoordenada[g];
  final= vetorCoordenada[g+1];

  }
  
  
  
  }
  
  //Memoria não é grande o suficiente
  if(resposta > menor+gordura){
  printf("\nNao foi possivel adicionar o Processo. Memoria Insuficiente");
  return;
  }
  //
  
  
  //Definir o espaço além do necessário
  gordura= menor-resposta;
  
  
  
  for (int d=inicio; d<final-gordura; d++){
   vetor2[d]=Processo;
  }
  
}



/////////////////////////////
// Adiciona Processo - Worst Fit
void AddProcessoWF(int resp){


int vetorCoordenada[200];
int num=0;
int menor=100, atual=-1;
int gordura=0;

 int contador= 0;
 int inicio=-1, final=-1;
 int resposta=resp;
 int gatilho=0;
 
  for (int p=0; p<100; p++){
   vetorCoordenada[p]=-1;
  }
 
 
 
 
 
 
 for(int i=0; i<100; i++){
  
  if (vetor3[i] == 0){
  
  if(inicio==-1){
  inicio=i;
  }
  
  contador++;
  if (contador>resposta){
  gordura++;
  }
  
  //Código muda a partir daqui
 
    if (contador >= resposta || i==99){
    
    final = i;
    
    //numero maximo
     if (i==99){
     
    vetorCoordenada[num]=inicio;
    vetorCoordenada[num+1]=final;    
         
     }
    //numero maximo - final 
     
    }
 
  } else {
  
      if(final !=-1){
      
    vetorCoordenada[num]=inicio;
    vetorCoordenada[num+1]=final;
    
    num=num+2;
    }
    
    
 //Zera o inicio e final
 contador=0;
 inicio=-1;
 final=-1;
 gordura=0;
    
   }
   
  }
  
  
  
  for(int g=0; g<100; g=g+2){
  
  atual= vetorCoordenada[g+1] - vetorCoordenada[g];

  
  //nao ta entrando no if
  if (atual < menor && atual != 0){
  menor= atual;
  inicio= vetorCoordenada[g];
  final= vetorCoordenada[g+1];

  }
  
  
  
  }
  
  //Memoria não é grande o suficiente
  if(resposta > menor+gordura){
  printf("\nNao foi possivel adicionar o Processo. Memoria Insuficiente");
  return;
  }
  //
  
  
  //Definir o espaço além do necessário
  gordura= menor-resposta;
  
  
  
  for (int d=inicio; d<final-gordura; d++){
   vetor3[d]=Processo;
  }

}




//////////////////////////////////
// Adicona Processo - Circular Fit
void AddProcessoNF(int resp){

 int tamanho=resp;
 int contador= 0;
 int inicio=0, final=1;
 int novoInicio;
 
 printf("Ultimo Processo: %d", UltimoProcesso);

 novoInicio= 100-UltimoProcesso;

 for(int i=UltimoProcesso; i<100; i++){
  
  if (vetor4[i] == 0){
  
  if (inicio==0){
  inicio=i;
  }
  
  contador++;
 
    if (contador == tamanho){
    final = i;
    break;
    }
 
  } else {
 inicio=0;
 contador=0;
   }
   
 }
 
 if(tamanho==1 && vetor4[0]==0){
   vetor4[0]=Processo;
   
   UltimoProcesso=final;
   
   return;
  }
 
  if (final == 0 || tamanho>contador){
  printf ("\n Nao foi possivel adicionar o Processo. Memoria insuficiente\n");
  return;
  }
  
  printf ("\nCircular FIT:");
  printf ("\nResp %d", resp);
  printf ("\nContador: %d", contador);
  printf ("\nInicio: %d", inicio);
  printf ("\nFinal: %d\n", final);
  
 
  for(int i=inicio; i<=final; i++){
   vetor4[i]=Processo;
  }
  
  UltimoProcesso=final;


}







//Remove Processo
void RemoveProcesso(){
	int pid;
	int tem1=0, tem2=0, tem3=0, tem4=0;
	
	printf("\nQual Processor gostaria de remover? ");
	scanf("%d", &pid);
	
	//FF
	for(int i=0; i<100; i++){
	 if(vetor1[i]==pid){
	 tem1=1;
	 }
	}
	
	if (tem1==1){
	for(int i=0; i<100; i++){
	 if(vetor1[i]==pid){
	  vetor1[i]=0;
	  }
	 }
	} else {
	printf ("\nFirst Fit - PID de Processo não encontrado.\n");
	}
	
	
	//BF
	for(int i=0; i<100; i++){
	 if(vetor2[i]==pid){
	 tem2=1;
	 }
	}
	
	if (tem2==1){
	for(int i=0; i<100; i++){
	 if(vetor2[i]==pid){
	  vetor2[i]=0;
	  }
	 }
	} else {
	printf ("\nBest Fit - PID de Processo não encontrado.\n");
	}
	
	//WF
	for(int i=0; i<100; i++){
	 if(vetor3[i]==pid){
	 tem3=1;
	 }
	}
	
	if (tem3==1){
	for(int i=0; i<100; i++){
	 if(vetor3[i]==pid){
	  vetor3[i]=0;
	  }
	 }
	} else {
	printf ("\nWorst Fit - PID de Processo não encontrado.\n");
	}
	
	//CF
	for(int i=0; i<100; i++){
	 if(vetor4[i]==pid){
	 tem4=1;
	 }
	}
	
	if (tem4==1){
	for(int i=0; i<100; i++){
	 if(vetor4[i]==pid){
	  vetor4[i]=0;
	  }
	 }
	} else {
	printf ("\nCircular Fit - PID de Processo não encontrado.\n");
	}
	 

}



//Imprime Memória
void ImprimeMemoria(){
 int i,j;
 
  printf ("Memoria First Fit:\n");
  for(j=0; j<100; j++){
    printf("%d", vetor1[j]); 
  }
  printf("\n\n");
  
  printf ("Memoria Best Fit:\n");
    for(j=0; j<100; j++){
    printf("%d", vetor2[j]); 
  }
  printf("\n\n");
  
  printf ("Memoria Worst Fit:\n");
    for(j=0; j<100; j++){
    printf("%d", vetor3[j]); 
  }
  printf("\n\n");
  
  printf ("Memoria Circular Fit:\n");
    for(j=0; j<100; j++){
    printf("%d", vetor4[j]); 
  }
  printf("\n\n");


}






int main(){

 vetor1[17]= -1;

 int option = 1, tamanho;

 while (option != 5){
 
 printf("\nOpção 1 - Inserir Novo Processos na memória\n");
 printf("Opção 2 - Remover um processo da memória\n");
 printf("Opção 3 - Estado da memória\n");
 printf("Opção 4 - Terminar Programa\n");
 
 printf("O que gostaria de fazer?\n");
 scanf ("%d", &option);
 

 
   switch (option){
    case 1 :
    
     printf("\n Qual será o tamanho da memoria?\n");
     scanf("%d", &tamanho);
    
     AddProcessoFF(tamanho);
     AddProcessoBF(tamanho);
     AddProcessoWF(tamanho);
     AddProcessoNF(tamanho);
     
     Processo++;
    break;
     
    case 2 :
    
    RemoveProcesso();
     
    break; 
   
   case 3 :
   
     ImprimeMemoria();
    
   break;
   
   case 4 :
    exit(-1);
   break;
   
   }
   
 	
 }

}






