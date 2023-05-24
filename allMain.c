#include "player.h"
void task1(FILE* in,FILE* out,Team** first_team,int n)
{
    ///Cerinta 1 - creare lista
    create_list_ofTeams(first_team,in,out,n);
}
void task2(FILE* out,Team** first_team,int* n)
{
    ///Cerinta 2 - eliminat echipe
    purge_Teams(first_team,n);
}
void task3(FILE* out,Team* first_team,int *n,match_1v1** first_Match,match_1v1** last_Match,stackTeams* winners,stackTeams* losers,Team** top8)
{
    ///Cerinta 3 - matches + winners vs. losers
    set_Matches(first_team,first_Match,last_Match);
    purge_Matches(first_Match,&winners,&losers,n,out,top8);
}
void task4(FILE* out,Tree** root,Team** top8)
{
    ///CERINTA 4 - BST
    create_BST(root,top8);
    fprintf(out,"\n");
    fprintf(out,"TOP 8 TEAMS:\n");
    display_BST(*root,out);
}
void task5(FILE* out,Tree* root,Team** List)
{
    ///CERINTA 5 - AVL
    add_BST_toList(out,root,List);
    //display_List(out,*List);
    fprintf(out,"\nTHE LEVEL 2 TEAMS ARE:\n");
    Team *aux=findAt_m(*List,8);
    fprintf(out,"%s\n",aux->name_ofTeam);
    aux=findAt_m(*List,6);
    fprintf(out,"%s\n",aux->name_ofTeam);
    aux=findAt_m(*List,4);
    fprintf(out,"%s\n",aux->name_ofTeam);
    aux=findAt_m(*List,2);
    fprintf(out,"%s\n",aux->name_ofTeam);

}
