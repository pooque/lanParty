#include "player.h"
void addTo_top8(Team** top8,stackTeams* winners)
{
    if(winners!=NULL)
    {
        Team *newTeam=(Team*)malloc(sizeof(Team));

        newTeam->name_ofTeam=winners->team->name_ofTeam;
        newTeam->team_score=winners->team->team_score;

        newTeam->next=NULL;

        if((*top8)!=NULL)
            (*top8)->next=newTeam;

        (*top8)=newTeam;
        addTo_top8(top8,winners->previous);
    }
}
void create_top8(Team** top8,Team* team)
{
    addTo_top8(top8,team);
}
