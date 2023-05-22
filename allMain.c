#include "player.h"
void lanParty(FILE* in,FILE* out)
{
    int n;
    fscanf(in,"%d",&n);
    //fprintf(out,"Aveti %d echipe.\n",n);

    ///Cerinta 1 - creare lista
    Team* first_team;
    create_list_ofTeams(&first_team,in,out,n);
    /*while(first_team!=NULL)
    {
        printf("\n%s",first_team->name_ofTeam);
        first_team=first_team->next;
    }*/
    printf("1");

    ///Cerinta 2 - eliminat echipe
    purge_Teams(&first_team,&n);
    printf("2");

    ///Cerinta 3 - matches + winners vs. losers
    match_1v1 *first_Match,*last_Match;
    set_Matches(first_team,&first_Match,&last_Match);
    printf("3");

    stackTeams *winners=NULL,*losers=NULL;
    Team *top8;
    purge_Matches(&first_Match,&winners,&losers,&n,out,&top8);
    printf("4");

    ///CERINTA 4 - BST
    BST *root;
    create_BST(&root,&top8);
    fprintf(out,"\n");
    display_BST(root,out);
    printf("5");
}
