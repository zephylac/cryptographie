#include <stdlib.h>
#include <stdio.h>
#include <hill.h>

int main() {
  param_t * param = NULL ; 
  char * res = NULL;
  printf( "Debut du programme des test sur l'encodage de hill\n" ) ; 

  
  printf( "Test encogade\n" ) ;
  
  param = paramEncodage() ;

  printf("encodage de : ELECTION\n");

  res = encodage("ELECTION",8,param);

  printf("%s\n",res); 
  free(res);
  free(param->mat);
  free(param);
  printf( "Fin du programme des test sur l'encodage de hill\n" ) ; 
  

  return(0) ; 
}
