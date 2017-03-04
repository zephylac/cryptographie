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
		printf("%i|",tab[i]);
	}
	printf("\n");
	return tab;
}

static int * etape2(int * tab, int taille, int m, int * mat){
	int * tab2 = malloc(sizeof(int)*(taille));
	int i,j,k,l,temp;
	for(i = 0; i < taille; i+= m){
		for(k = 0; k < m ; k++){
			temp = 0;
			for(j = i, l = m*k; j < i + m; l++, j++){
				temp += mat[l] * tab[j];
			}	
			tab2[i+(k%2)] = temp%26;
			printf("%i:%i | ",i+(k%2),tab2[i+(k%2)]);
		}
	}
	printf("\n");	
	for(i=0;i<taille;i++){
		printf("%i",tab[i]);
	}
	printf("\n");	

	return tab2;
}

static char * etape4(int * tab2,int taille){
	char * chaine2 = malloc(sizeof(char)*(taille+1));
	int i;
	for(i=0;i<taille;i++){
		chaine2[i] = int2char(tab2[i]);
	}
	chaine2[i] = '\0';
	printf("%s\n",chaine2);
	return chaine2;
}

extern void encodage( char * chaine, int taille, param_t * param){
	char * res = NULL;
	int * tab = NULL;
	int * tab2 = NULL;
	printf("%c\n",int2char(3));

	tab = etape1(chaine,taille);
	tab2 = etape2(tab,taille,(param->m),(param->mat));
	
	res = etape4(tab2,taille);	
	
	free(tab2);
	free(tab);
	free(res);
	free(param->mat);
	free(param);
}
