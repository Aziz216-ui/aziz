#ifndef DONATION_MANAGEMENT
#define DONATION_MANAGEMENT
#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
typedef struct
{int jj,mm,aa;
}Date;
typedef struct {

char idag[50];
char nom_ag[50];
char prenom_ag[50];
char sexe[10];
char poste[50];
Date age;
}agent;
int ajoutagent(agent a);
int modiferagent(agent a);
int supprimeragent(char idag[]);
agent* chercheragent(char idag[]);
void afficheragent(GtkTreeView *liste);


#endif
