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
int min_Score(Team* team)
{
    Player* aux=team->player;
    int score=INT_MAX;
    while(aux!=NULL)
    {
       if(aux->points < score)
            score=aux->points;
       aux=aux->next;
    }
    return score;
}
int find_N_max(int x)
{
    int N=2;
    while(N<=x)
        N*=2;
    return N;
}
void purge_Teams(Team** team,int n_ofTeams)
{
    int N_MAX=find_N_max(n_ofTeams);
    Team* aux=*team;
    while(n_ofTeams != N_MAX)
    {
        float P_MIN=min_Score(aux);
        if((*team)->team_score == P_MIN)
        while(aux->next != NULL)
        {

        }
    }
}
void delete_Team(Team** team)
{
    Team* aux=*team;
    aux->next=aux->next->next;
    free(aux);
}

[x]->[y]->[z]->[t]->NULL
