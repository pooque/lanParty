#include "player.h"
void makePair_fromStack(stackTeams* stack,match_1v1** match)
{
    (*match)->t1=stack;
    (*match)->t2=stack->previous;
}
void set_Matches_fromStack(stackTeams* winners,match_1v1** firstMatch,stackTeams** lastMatch)
{
    (*firstMatch)=(match_1v1*)malloc(sizeof(match_1v1));
    stackTeams *aux=winners;

    makePair_fromStack(winners,&firstMatch);

    aux=aux->previous->previous;
    *lastMatch=*firstMatch;

    while(aux!=NULL)
    {
        match_1v1 *newMatch=(match_1v1*)malloc(sizeof(match_1v1));

        makePair_fromStack(winners,&newMatch);

        newMatch->next=NULL;
        (*lastMatch)->previous=newMatch;
        (*lastMatch)=newMatch;

        aux=aux->previous->previous;
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
void display_winners(stackTeams* Stack,FILE* out)
{
    int j=1;
    stackTeams *i=Stack;
    while(i!=NULL)
    {
        fprintf(out,"WINNERS OF ROUND NO:%d",j);
        fprintf(out,"%s\n",i->team->name_ofTeam);
        for(int k=0; k<33-strlen(i->team->name_ofTeam); k++)
            fprintf(out," ");
        fprintf(out,"%f\n",i->team->team_score);
        i=i->previous;
        j++;
    }
}
void create_Stack(match_1v1** match,stackTeams** winners,stackTeams** losers)
{
    printf("pula");
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
    //match_1v1 *aux=*match;
    printf("muie");
    int round=1;
    while((*n_ofTeams)>1)
    {
        display_matches(*match,out,round);
        printf(" displayed matches %d,",round);
        create_Stack(match,&winners,&losers);
        printf(" stacked them stacks");
        delete_stack(losers);
        printf(" pantene shampoo");
        //delete_matches(match);

        display_winners(*winners,out);

        match_1v1 *first_Match,*last_Match;

        set_Matches_fromStack(*winners,&first_Match,&last_Match);

        delete_stack(winners);

        round++;

        (*n_ofTeams)/=2;
    }
}
