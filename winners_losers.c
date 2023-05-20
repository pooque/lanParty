#include "player.h"
void add_toStack(stackTeams** stack,Team* team)
{
    ///adaugat in stack
    stackTeams *newWinner=(stackTeams*)malloc(sizeof(stackTeams));
    newWinner->team=team;
    newWinner->previous=(*stack);
    (*stack)=newWinner;
}
void delete_matches(match_1v1** match)
{
    while((*match)!=NULL)
    {
        match_1v1 *aux=*match;
        (*match)=(*match)->next;
        free(aux);
    }
}
void delete_stack(stackTeams** stack)
{
    while((*stack)!=NULL)
    {
        stackTeams *aux=(*stack);
        (*stack)=(*stack)->previous;
        free(aux);
    }
}
void add_toWhich(stackTeams** winners,stackTeams** losers,Team* toWinners,Team* toLosers)
{
    ///functie discriminant - in care stack se pune
    add_toStack(winners,toWinners);
    add_toStack(losers,toLosers);
}
void display_Stack(stackTeams* Stack)
{
    stackTeams *i=Stack;
    while(i!=NULL)
    {
        printf("%s\n",i->team->name_ofTeam);
        i=i->previous;
    }
}
void create_Stack(match_1v1* match,stackTeams** winners,stackTeams** losers)
{
    if(match->t1->team_score >= match->t2->team_score)
    {
        match->t1->team_score++;
        add_toWhich(winners,losers,match->t1,match->t2);
    }
    else
    {
        match->t2->team_score++;
        add_toWhich(winners,losers,match->t2,match->t1);
    }

    match_1v1 *aux=match;
    aux=aux->next;

    while(aux!=NULL)
    {
        if(aux->t1->team_score >= aux->t2->team_score)
        {
            aux->t1->team_score++;
            add_toWhich(winners,losers,aux->t1,aux->t2);
        }
        else
        {
            aux->t2->team_score++;
            add_toWhich(winners,losers,aux->t2,aux->t1);
        }
        aux=aux->next;
    }

    display_Stack(*winners);
    printf("\n\n");
    display_Stack(*losers);
}
//void purge_Matches()
