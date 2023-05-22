#include "player.h"
void lanParty(FILE* in,FILE* out)
{
    int n;
    fscanf(in,"%d",&n);

    ///Cerinta 1 - creare lista
    Team* first_team;
    create_list_ofTeams(&first_team,in,out,n);

    ///Cerinta 2 - eliminat echipe
    purge_Teams(&first_team,&n);

    ///Cerinta 3 - matches + winners vs. losers
    match_1v1 *first_Match,*last_Match;
    set_Matches(first_team,&first_Match,&last_Match);

    stackTeams *winners=NULL,*losers=NULL;
    Team *top8;
    purge_Matches(&first_Match,&winners,&losers,&n,out,&top8);

    ///CERINTA 4 - BST
    BST *root;
    create_BST(&root,&top8);
    fprintf(out,"\n");
    display_BST(root,out);
}
