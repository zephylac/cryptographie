#ifndef _HILL_H_
#define _HILL_H_

typedef struct param_s{
	int m;
	int * mat;
}param_t;
/*
 * FONCTIONS
 */
extern param_t * paramEncodage();
extern char * encodage( char * chaine, int taille , param_t * param);

#endif
