#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  //inizializzo le variabili
  char plaintext_M[128];
  char chiave[128];
  char text_C[128];
  time_t beta;
  int scelta;

  srand((unsigned)time(&beta));
  printf("Inserire una stringa iniziale di max 128 caratteri: ");
  fgets(plaintext_M, 128, stdin);

  //Inserzione del menù di scelta

  printf("Menù:\n");
  printf("1. Digita 1 per inserire manualmente la chiave di cifratura (max 128).\n");
  printf("2. Digita 2 per generare una chiave casuale.\n");
  printf("0. Esci dal programma.\n");
  do {
    printf("Scelta: ");
    scanf("%d",&scelta);
    getchar();  //pulizia del buffer
    switch(scelta)
    {
      case 1:
      //istruzioni scelta 1
      printf("Inserisci la chiave di cifratura: ");
      do {
            fgets(chiave, 128, stdin);
            if(strlen(chiave)<strlen(plaintext_M)){
              printf("La chiave non può essere minore della stringa: ");
            }
      }while(strlen(chiave)<strlen(plaintext_M));

      printf("La stringa cifrata in esadecimale è: ");
      for(int beta =0; beta<strlen(plaintext_M); beta++)
      {
        text_C[beta]=plaintext_M[beta] ^ chiave[beta]; //c = m XOR k
        printf("%x", text_C[beta]);
      }
      printf("\nLa stringa decifrata è: ");
      for(int beta =0; beta<strlen(plaintext_M)-1; beta++)
      {
        plaintext_M[beta]=text_C[beta] ^ chiave[beta];
        printf("%c", plaintext_M[beta]);
      }
      printf("\n");
      break;

      case 2:
      //istruzioni scelta 2
      printf("La chiave generata è: ");
      for(int beta = 0; beta<strlen(plaintext_M)-1; beta++)
      {
        chiave[beta]=(33+rand()%93); //filtro i caratteri speciali
        printf("%c", chiave[beta]);
      }
      printf("\nLa stringa cifrata in esadecimale è: ");
      for(int beta = 0; beta<strlen(plaintext_M)-1; beta++)
      {
        text_C[beta]=plaintext_M[beta] ^ chiave[beta];
        printf("%x", text_C[beta]);
      }
      printf("\nLa stringa decifrata è: ");
      for(int beta =0; beta<strlen(plaintext_M)-1; beta++)
      {
        plaintext_M[beta]=text_C[beta] ^ chiave[beta];
        printf("%c", plaintext_M[beta]);
      }
      printf("\n");
      break;

      case 0: printf("Programma terminato.\n");
      break;
      default: printf("Scelta non consentita.\n");
    }
  }while(scelta!=0);
  return 0;
}
