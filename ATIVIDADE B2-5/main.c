// NO TABULEIRO DE XADREZ FAZER O XEQUE PASTOR
//Refatorando para modularizar código
#include <stdio.h>
#include <string.h>

#define LINHA 8 
#define COLUNA 8 
#define CARACTERE 4 
char *ponteiroTabuleiro;
int jogada=1;  

void mostrarTabuleiro(char tabuleiro[LINHA][COLUNA][CARACTERE]){
   printf("\n   a   b   c   d   e   f   g   h\n");
    printf("  -------------------------------\n");

    for (int i = 7; i >= 0; i--) {
        printf("%d|", i+1);
        for (int j = 0; j < 8; j++) {
            printf("%s ", tabuleiro[i][j]);
        }
        printf("\n");
    }
  
}

void partida(int jogada, char tabuleiro[LINHA][COLUNA][CARACTERE]){

if(jogada == 1){
  printf("\n Jogada #1:\n"); 
  printf("\n Brancas jogam Peão do Rei (PB5) E4:\n"); 
  ponteiroTabuleiro = &tabuleiro[1][4][0]; //PB5
  strcpy(tabuleiro[3][4], ponteiroTabuleiro);
  strcpy(ponteiroTabuleiro, "...");
  mostrarTabuleiro(tabuleiro);
  printf("\n Pretas jogam Peão do Rei (PP5) E5 :\n");
  ponteiroTabuleiro = &tabuleiro[6][4][0]; //PP5
  strcpy(tabuleiro[4][4], ponteiroTabuleiro);
  strcpy(ponteiroTabuleiro, "...");
  mostrarTabuleiro(tabuleiro);
  jogada++; 
}
  if(jogada == 2){
    printf("\n -------------------------------------------\n");
     printf("\n Jogada #2:\n");
     printf("\n Brancas jogam Bispo do rei (BB2) C4:\n");
     
    ponteiroTabuleiro = &tabuleiro[0][5][0]; //BB2
    strcpy(tabuleiro[3][2], ponteiroTabuleiro);
    strcpy(ponteiroTabuleiro, "...");
    mostrarTabuleiro(tabuleiro);
    printf("\n Pretas jogam Cavalo da Dama (CP1) C6:\n");
    ponteiroTabuleiro = &tabuleiro[7][1][0];
    strcpy(tabuleiro[5][2], ponteiroTabuleiro);
    strcpy(ponteiroTabuleiro, "...");

    mostrarTabuleiro(tabuleiro);
    jogada++; 
  }
  if(jogada == 3){
    printf("\n -------------------------------------------\n");
    printf("\n Jogada #3:\n");
     printf("\n Brancas jogam Dama(DB1) H5 :\n");

    ponteiroTabuleiro = &tabuleiro[0][3][0]; 
    strcpy(tabuleiro[4][7], ponteiroTabuleiro);
    strcpy(ponteiroTabuleiro, "...");
    mostrarTabuleiro(tabuleiro);
    printf("\n Pretas jogam Cavalo do Rei(CP2) F6 \n");
    ponteiroTabuleiro = &tabuleiro[7][6][0];
    strcpy(tabuleiro[5][5], ponteiroTabuleiro);
    strcpy(ponteiroTabuleiro, "...");

    mostrarTabuleiro(tabuleiro);
    jogada++; 
  }
  if(jogada == 4){
    printf("\n -------------------------------------------\n");
    printf("\n  Jogada #4: Xeque Mate :\n");
     printf("\n Brancas capturam Peão do Rei |F7| e dão Xeque Mate :\n");

    ponteiroTabuleiro = &tabuleiro[4][7][0]; //DB1
    strcpy(tabuleiro[6][5], ponteiroTabuleiro);
    strcpy(ponteiroTabuleiro, "...");
    mostrarTabuleiro(tabuleiro);
    jogada++; 
  }else{
    jogada = 0;
  }

 
}

int main() {
  char tabuleiro[LINHA][COLUNA][CARACTERE] = {
      {"TB1", "CB1", "BB1", "DB1", "RB1", "BB2", "CB2", "TB2"},
      {"PB1", "PB2", "PB3", "PB4", "PB5", "PB6", "PB7", "PB8"},
      {" x ", " x ", " x ", " x ", " x ", " x ", " x ", " x "},
      {" x ", " x ", " x ", " x ", " x ", " x ", " x ", " x "},
      {" x ", " x ", " x ", " x ", " x ", " x ", " x ", " x "},
      {" x ", " x ", " x ", " x ", " x ", " x ", " x ", " x "},
      {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"},
      {"TP1", "CP1", "BP1", "DP1", "RP1", "BP2", "CP2", "TP2"},
  };

do{
 
 
  partida(jogada, tabuleiro);
  
} while(jogada == 0 );
    return 0;
}
