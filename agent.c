#include "agent.h"



enum
{
	EID,
	ENOM,
	EPRENOM,
	EJJ,
	EMM,
	EAA,
	ESEXE,
	EPOSTE,
	COLUMNS
};


void afficheragent(GtkTreeView *liste)
{
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter ;
    GtkListStore *store;
    agent a;
    store=NULL;
    FILE *f;
    store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
    if(store==NULL){
        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Id Agent",renderer,"text",EID,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
        gtk_tree_view_append_column(liste,column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
        gtk_tree_view_append_column(liste,column); 

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJJ,NULL);
        gtk_tree_view_append_column(liste,column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EMM,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EAA,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
        gtk_tree_view_append_column(liste,column);
	
	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Poste",renderer,"text",EPOSTE,NULL);
        gtk_tree_view_append_column(liste,column);

    }
          
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
    f=fopen("agent.txt","r");
    if(f==NULL){return;}
    else
    {
                 f=fopen("agent.txt","a+");
         while(fscanf(f,"%s %s %s %d %d %d %s %s\n",a.idag, a.nom_ag, a.prenom_ag, &a.age.jj, &a.age.mm, &a.age.aa, a.sexe,a.poste)!=EOF)
         {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,0,a.idag,1,a.nom_ag,2,a.prenom_ag,3,a.age.jj,4,a.age.mm,5,a.age.aa,6,a.sexe,7,a.poste,-1);
         }
     fclose(f);
     gtk_tree_view_set_model(liste,GTK_TREE_MODEL(store));
     g_object_unref(store);
    }

}
int ajoutagent(agent a) {
    FILE *f;
 f= fopen("agent.txt", "a+");
    if (f != NULL) {
        fprintf(f, "%s %s %s %d %d %d %s %s\n",a.idag, a.nom_ag, a.prenom_ag, a.age.jj, a.age.mm, a.age.aa, a.sexe,a.poste);
        fclose(f);
        return 1;
    } else {
        return 0;
    }
}
int modiferagent(agent a) {
    int tr = 0;
    agent b;
    FILE *f = fopen("agent.txt", "r");
    FILE *f2 = fopen("new.txt", "a+");
   if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %s %d %d %d %s %s\n",b.idag, b.nom_ag, b.prenom_ag, &b.age.jj, &b.age.mm, &b.age.aa, b.sexe,b.poste)!=EOF)
{
if(strcmp(b.idag,a.idag)==0)
        
	fprintf(f2,"%s %s %s %d %d %d %s %s\n",a.idag, a.nom_ag, a.prenom_ag, a.age.jj, a.age.mm, a.age.aa, a.sexe,a.poste);
else

  	fprintf(f2,"%s %s %s %d %d %d %s %s\n",b.idag, b.nom_ag, b.prenom_ag, b.age.jj, b.age.mm, b.age.aa, b.sexe,b.poste);

}
        fclose(f);
        fclose(f2);
remove("agent.txt");
rename("new.txt", "agent.txt");
        return 1;
    }

}


int supprimeragent(char idag[]) {
    int tr = 0;
    agent D;
    FILE *f = fopen("agent.txt", "r");
    FILE *f2 = fopen("new.txt", "a+");
     if(f==NULL || f2==NULL)
return 0;
else
    {
        while (fscanf(f, "%s %s %s %d %d %d %s %s\n",D.idag, D.nom_ag, D.prenom_ag, &D.age.jj, &D.age.mm, &D.age.aa, D.sexe,D.poste) != EOF) {
            if (strcmp(D.idag, idag) == 0) 
                tr = 1;
             else 
                fprintf(f2, "%s %s %s %d %d %d %s %s\n",D.idag, D.nom_ag, D.prenom_ag, D.age.jj, D.age.mm, D.age.aa, D.sexe,D.poste);
            
        }
    
    fclose(f);
    fclose(f2);
    remove("agent.txt");
    rename("new.txt", "agent.txt");
    if(tr==1)
        return 1;
else
	return 0;
    }

}

agent* chercheragent(char idag[]) {
    agent* D = malloc(sizeof(agent));
    int t = 0;
    FILE* f = fopen("agent.txt", "r");

    if (f == NULL)
        return NULL;
    else {
        while (fscanf(f, "%s %s %s %d %d %d %s %s\n",D->idag, D->nom_ag, D->prenom_ag, &D->age.jj, &D->age.mm, &D->age.aa, D->sexe,D->poste) != EOF) {
            if (strcmp(D->idag, idag) == 0){
                t = 1;
		break;}
        }

        fclose(f);

        if (t == 1)
            return D;
        else {
            free(D);  
            return NULL;
        }
 
    }}





