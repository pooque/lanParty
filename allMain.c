#include "player.h"
void lanParty(FILE* in,FILE* out)
{
    int n;
    fscanf(in,"%d",&n);
    fprintf(out,"Aveti %d echipe.\n",n);

    //Cerinta 1 - creare lista
    Team* first_team;
    create_list_ofTeams(&first_team,in,out,n);

    //Cerinta 2 - eliminat echipe
    purge_Teams(&first_team,&n);
    display_team(first_team,out);

    //Cerinta 3
    match_1v1 *first_Match,*last_Match;
    set_Matches(first_team,&first_Match,&last_Match);
    display_matches(first_Match,out);

    stackTeams *winners=NULL,*losers=NULL;
    create_Stack(first_Match,&winners,&losers);
}
