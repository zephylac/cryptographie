#include <stdio.h>
#include <stdlib.h>
#include <hill.h>





extern param_t * paramEncodage(){
	int i, j;
	param_t * param = malloc(sizeof(param_t));
	
	printf("Veuillez choisir le nombre de combinaison(s) linéaire(s) : ");
	scanf("%i",(&(param)->m));
	
	int * mat = malloc(sizeof(int)*(param->m)*2);
	printf("Matrice d'encodage\n");
	for(i=0,j=0; i < (param->m) * 2;i++,j++){
		if(j>1){
			j = 0;
		}
		printf("Case[%i][%i] : ",i,j);
		scanf("%i",(&mat[i]));

	}
	param -> mat = mat;
	return param;
}


static int char2int(char car){
	if (car >= 'a' && car <= 'z') return car - 'a';
	else if (car >= 'A' && car <= 'Z') return car - 'A';
	return -1;
}

static char int2char(int value){
	return value + 'A';
}

static int * etape1(char * chaine, int taille){
	int * tab = malloc(sizeof(int)*taille);
	int i;
	for(i=0;i<taille;i++){
		tab[i] = char2int(chaine[i]);
	}
	free(chaine);
	return tab;
}

static int * etape2(int * tab, int taille, int m, int * mat){
	int * tab2 = malloc(sizeof(int)*taille*m);
	int i,j;
	for(i = 0; i < taille; i+=m){
		for(j = 0; j <= m ; j+=2){
			tab2[i]	= (mat[j] * tab[i] + mat[j+1] * tab[i+1])%26;
		}
	}
	free(tab);
	return tab2;
}

static char * etape4(int * tab2,int taille){
	char * chaine2 = malloc(sizeof(char)*taille);
	int i;
	for(i=0;i<taille;i++){
		chaine2[i] = int2char(tab2[i]);
	}
	free(tab2);
	return chaine2;
}

extern char * encodage( char * chaine, int taille, param_t * param){
	return (etape4(etape2(etape1(chaine,taille),taille,((param)->m),((param)->mat)),taille));
}
