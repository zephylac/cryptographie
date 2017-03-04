#include <stdlib.h>
#include <stdio.h>
#include <hill.h>

int main() {
  param_t * param = NULL ; 
  printf( "Debut du programme des test sur l'encodage de hill\n" ) ; 

  
  printf( "Test encogade\n" ) ;
  
  param = paramEncodage() ;

  printf("encodage de : ELECTION\n");

  encodage("ELECTION",8,param);

  printf( "Fin du programme des test sur l'encodage de hill\n" ) ; 
  

  return(0) ; 
}
