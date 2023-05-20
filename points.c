#include "player.h"
float AVG_score(Team* team)
{
    Player* aux=team->player;
    float S=0,k=0;
    while(aux!=NULL)
    {
        S+=aux->points;
        k++;
        aux=aux->next;
    }
    return S/k;
}
float min_Score(Team* team)
{
    Team* aux=team;
    float score=aux->team_score;
    while(aux!=NULL)
    {
        if(aux->team_score < score)
            score=aux->team_score;
        aux=aux->next;
    }
    return score;
}
int find_N_max(int x)
{
    int N;
    for(N=1; N*2<x; N*=2);
    return N;
}
void purge_Teams(Team** team,int *n_ofTeams)
{
    int N_MAX = find_N_max(*n_ofTeams);
    while(*n_ofTeams != N_MAX)
    {
        float P_MIN=min_Score(*team);
        while(((*team)!=NULL) && ((*team)->team_score == P_MIN) && (*n_ofTeams != N_MAX))
        {
            delete_firstTeam(team);
            (*n_ofTeams)--;

        }
        Team *aux=*team;
        while(aux->next != NULL && (*n_ofTeams != N_MAX))
        {
            if(aux->next->team_score == P_MIN)
            {
                delete_Team(&aux);
                (*n_ofTeams)--;
            }
            else
                aux=aux->next;
        }
    }
}
void delete_firstTeam(Team** team)
{
    Team* aux=*team;
    aux=aux->next;
    free(aux);
}
void delete_Team(Team** team)
{
    Team* aux=*team;
    aux->next=aux->next->next;
    free(aux);
}
