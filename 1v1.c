#include "player.h"
void set_Matches(Team* team,match_1v1** firstMatch,match_1v1** lastMatch)
{
    (*firstMatch)=(match_1v1*)malloc(sizeof(match_1v1));

    Team *aux=team;

    makePair(team,firstMatch);

    (*firstMatch)->next=NULL;

    aux=aux->next->next;
    *lastMatch=*firstMatch;
    while(aux!=NULL)
    {
        match_1v1 *newMatch=(match_1v1*)malloc(sizeof(match_1v1));

        makePair(aux,&newMatch);

        newMatch->next=NULL;
        (*lastMatch)->next=newMatch;
        (*lastMatch)=newMatch;

        aux=aux->next->next;
    }
}
void makePair(Team* team,match_1v1** match)
{
    (*match)->t1=team;
    (*match)->t2=team->next;
}
void display_matches(match_1v1* match,FILE* out)
{
    fprintf(out,"\n");
    match_1v1 *aux=match;
    while(aux!=NULL)
    {
        int x=strlen(aux->t1->name_ofTeam),y=strlen(aux->t2->name_ofTeam);
        fprintf(out,"%s",aux->t1->name_ofTeam);
        for(int i=0;i<33-x;i++)
            fprintf(out," ");
        fprintf(out,"-");
        for(int i=0;i<33-y;i++)
            fprintf(out," ");
        fprintf(out,"%s\n",aux->t2->name_ofTeam);
        aux=aux->next;
    }
}
