#include "player.h"
void makePair_fromStack(stackTeams** stack,match_1v1** match)
{
    (*match)->t1=(*stack);
    (*match)->t2=(*stack)->previous;

    stackTeams *aux=*stack;
    (*stack)=(*stack)->previous->previous;
    free(aux);
}
void set_Matches_fromStack(stackTeams** winners,match_1v1** firstMatch,match_1v1** lastMatch)
{
    match_1v1 *newMatch=(match_1v1*)malloc(sizeof(match_1v1));
    makePair_fromStack(winners,&newMatch);
    newMatch->next=NULL;

    *firstMatch=newMatch;
    *lastMatch=*firstMatch;

    while(winners!=NULL)
    {
        match_1v1 *newMatch=(match_1v1*)malloc(sizeof(match_1v1));
        makePair_fromStack(winners,&newMatch);

        newMatch->next=NULL;
        (*lastMatch)->next=newMatch;
        (*lastMatch)=newMatch;

        //aux=aux->previous->previous;
    }

}
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
    match_1v1 *aux=*match;
    (*match)=(*match)->next;
    free(aux);
}
void delete_stack(stackTeams** stack)
{
    while((*stack)!=NULL)
    {
        printf(" SEARAHAGIALERGA");
        stackTeams *aux=(*stack);
        (*stack)=(*stack)->previous;
        //if(aux!=NULL)
        free(aux);
    }
}
void add_toWhich(stackTeams** winners,stackTeams** losers,Team* toWinners,Team* toLosers)
{
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
void display_winners(stackTeams* Stack,FILE* out,int round)
{
    printf("WINNERS OF ROUND NO:%d\n",round);
    stackTeams *i=Stack;
    while(i!=NULL)
    {

        printf("%s",i->team->name_ofTeam);
        for(int k=0; k<33-strlen(i->team->name_ofTeam); k++)
            printf(" ");
            printf("- ");
        printf("%.2f\n",i->team->team_score);
        i=i->previous;

    }
}
void create_Stack(match_1v1** match,stackTeams** winners,stackTeams** losers)
{

    while((*match)!=NULL)
    {
        if((*match)->t1->team_score >= (*match)->t2->team_score)
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
        printf(" cupcak");
    }

    //match_1v1 *aux=(*match);
    //aux=aux->next;

    printf(" CHINESE");
    //display_Stack(*winners);
    //printf("\n\n");
    //display_Stack(*losers);
}
void purge_Matches(match_1v1** match,stackTeams** winners,stackTeams** losers,int *n_ofTeams,FILE* out)
{
    int round=1;
    match_1v1 *first_Match=*match,*last_Match;

    while((*n_ofTeams)>1)
    {
        *winners=NULL;
        *losers=NULL;
        display_matches(first_Match,out,round);
        create_Stack(&first_Match,winners,losers);
        //delete_stack(losers);
        //delete_matches(match);
        printf("\n");
        display_winners(*winners,out,round);
        printf("\n");


        set_Matches_fromStack(winners,&first_Match,&last_Match);
        printf(" CANDieiSALARIUmyLOVE");
        //delete_stack(winners);
        round++;
        //printf("round s-a facut %d ",round);

        (*n_ofTeams)/=2;
        //printf("avem %d echipe ",*n_ofTeams);
    }
}
