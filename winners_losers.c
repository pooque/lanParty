#include "player.h"
void makePair_fromStack(stackTeams** stack,match_1v1** match)
{
    ///apelata pe stiva de winners; creeaza perechi intre castigatorii anteriori
    (*match)->t1=(*stack)->team;
    (*match)->t2=(*stack)->previous->team;
    ///se elibereaza stiva de winners
    stackTeams *aux=*stack;
    (*stack)=(*stack)->previous->previous;
    free(aux->previous);
    free(aux);
}
void set_Matches_fromStack(stackTeams** winners,match_1v1** firstMatch,match_1v1** lastMatch)
{
    ///creeaza meciuri intre castigatorii anteriori
    match_1v1 *newMatch=(match_1v1*)malloc(sizeof(match_1v1));
    makePair_fromStack(winners,&newMatch);
    newMatch->next=NULL;

    *firstMatch=newMatch;
    *lastMatch=*firstMatch;

    while(*winners!=NULL)
    {
        match_1v1 *newMatch=(match_1v1*)malloc(sizeof(match_1v1));
        makePair_fromStack(winners,&newMatch);

        newMatch->next=NULL;
        (*lastMatch)->next=newMatch;
        (*lastMatch)=newMatch;
    }
}
void add_toStack(stackTeams** stack,Team* team)
{
    ///adauga echipe intr-o stiva (de winners, sau losers)
    stackTeams *newWinner=(stackTeams*)malloc(sizeof(stackTeams));
    newWinner->team=team;
    newWinner->previous=(*stack);
    (*stack)=newWinner;
}
void delete_matches(match_1v1** match)
{
    ///sterge meci din coada
    match_1v1 *aux=*match;
    (*match)=(*match)->next;
    free(aux);
}
void delete_stack(stackTeams** stack)
{
    ///sterge intreaga stiva
    while((*stack)!=NULL)
    {
        stackTeams *aux=(*stack);
        (*stack)=(*stack)->previous;
        free(aux);
    }
}
void add_toWhich(stackTeams** winners,stackTeams** losers,Team* toWinners,Team* toLosers)
{
    ///adaugare echipa in stiva corespunzatoare
    add_toStack(winners,toWinners);
    add_toStack(losers,toLosers);
}
void display_Stack(stackTeams* Stack,FILE* out)
{
    ///afisare stiva
    stackTeams *i=Stack;
    while(i!=NULL)
    {
        fprintf(out,"%s\n",i->team->name_ofTeam);
        i=i->previous;
    }
}
void display_winners(stackTeams* Stack,FILE* out,int round)
{
    ///afisare castigatorii rundei curente (nume echipa + punctaj)
    fprintf(out,"WINNERS OF ROUND NO:%d\n",round);
    stackTeams *i=Stack;
    while(i!=NULL)
    {
        fprintf(out,"%s",i->team->name_ofTeam);
        for(int k=0; k<34-strlen(i->team->name_ofTeam); k++)
            fprintf(out," ");
        fprintf(out,"-  ");
        fprintf(out,"%.2f\n",i->team->team_score);
        i=i->previous;
    }
}
void create_Stack(match_1v1** match,stackTeams** winners,stackTeams** losers)
{
    ///adaugarea fiecarei echipe in stiva corespunzatoare + eliberarea cozii de meciuri
    while((*match)!=NULL)
    {
        if((*match)->t1->team_score > (*match)->t2->team_score)
        {
            (*match)->t1->team_score++;
            add_toWhich(winners,losers,(*match)->t1,(*match)->t2);
            delete_matches(match);
        }
        else
        {
            (*match)->t2->team_score++;
            add_toWhich(winners,losers,(*match)->t2,(*match)->t1);
            delete_matches(match);
        }
    }
}
void display_finalWinner(Team* team,FILE* out,int round)
{
    ///afisare final winner
    fprintf(out,"\nWINNERS OF ROUND NO:%d\n",round);
    fprintf(out,"%s",team->name_ofTeam);
    for(int k=0; k<34-strlen(team->name_ofTeam); k++)
        fprintf(out," ");
    fprintf(out,"-  ");
    fprintf(out,"%.2f\n",team->team_score);
}
void final_round(match_1v1** match,FILE* out,int round)
{
    ///outcome-ul ultimei runde
    round++;
    display_matches(*match,out,round);
    if((*match)->t1->team_score > (*match)->t2->team_score)
    {
        (*match)->t1->team_score++;
        display_finalWinner((*match)->t1,out,round);
    }
    else
    {
        (*match)->t2->team_score++;
        display_finalWinner((*match)->t2,out,round);
    }
}
void purge_Matches(match_1v1** match,stackTeams** winners,stackTeams** losers,int *n_ofTeams,FILE* out,Team** top8)
{
    ///gasire final winner + top 8
    int round=1;

    match_1v1 *first_Match=*match,*last_Match;

    (*n_ofTeams)/=2;
    while((*n_ofTeams)>1)
    {
        *winners=NULL;
        *losers=NULL;

        display_matches(first_Match,out,round);
        create_Stack(&first_Match,winners,losers);

        if((*n_ofTeams)==8)
        {
            *top8=NULL;
            addTo_top8(top8,*winners);
            //display_top8(*top8);
        }
        fprintf(out,"\n");
        display_winners(*winners,out,round);

        set_Matches_fromStack(winners,&first_Match,&last_Match);

        if((*n_ofTeams)==2)
            final_round(&first_Match,out,round);
        round++;

        (*n_ofTeams)/=2;
    }
}
