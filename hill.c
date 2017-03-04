#include <stdio.h>
#include <stdlib.h>

int char2int(char car){
	if (car >= 'a' && car <= 'z') return car - 'a';
	else if (car >= 'A' && car <= 'Z') return car - 'A';
	return -1;
}

char int2char(int value){
	return value + 'A';
}

int * etape1(char * chaine, int taille){
	int * tab = malloc(sizeof(int)*taille);
	int i;
	for(i=0;i<taille;i++){
		tab[i] = char2int(chaine[i]);
	}
	free(chaine);
	return tab;
}

int * etape2(int * tab, int taille, int m, int * mat){
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

char * etape4(int * tab2,int taille){
	char * chaine2 = malloc(sizeof(char)*taille);
	int i;
	for(i=0;i<taille;i++){
		chaine2[i] = int2char(tab2[i]);
	}
	free(tab2);
	return chaine2;
}

char * encodage( char * chaine, int taille , int m, int * mat){
	return etape4(etape2(etape1(chaine,taille),taille,m,mat),taille);
}

int main(){
	
	return 1;
}
