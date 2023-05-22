#include "player.h"
void create_list_ofTeams(Team** first_team,FILE* in,FILE* out,int n_ofTeams)
{
    ///creeare prim element (echipa) a listei de echipe
    Team *team=(Team*)malloc(sizeof(Team));
    *first_team=team;

    read_n_ofPlayers(&team,in);

    read_name_ofTeam(&team,in);

    add_toTeam(team->n_ofPlayers,&team->player,in);
    team->team_score=AVG_score(team);

    team->next=NULL;
    ///creeare restul listei de echipe
    enter_Teams(first_team,n_ofTeams,in,out);
}
void read_n_ofPlayers(Team** team,FILE* in)
{
    ///citire numar de echipe
    fscanf(in,"%d",&(*team)->n_ofPlayers);
    fgetc(in);
}
void read_name_ofTeam(Team** team,FILE* in)
{
    ///citire nume echipa
    (*team)->name_ofTeam=(char*)malloc(33*sizeof(char));
    fgets((*team)->name_ofTeam,33*sizeof(char),in);
    (*team)->name_ofTeam[strlen((*team)->name_ofTeam)-1]='\0';
}
void add_toTeam(int n_ofPlayers,Player** first_player,FILE* in)
{
    ///citire jucatori + adaugare in lista
    Player *player=(Player*)malloc(sizeof(Player));
    read_dataAboutPlayer(&player,in);

    player->next=NULL;
    *first_player=player;

    for(int i=1; i<n_ofPlayers; i++)
    {
        Player* new_player=(Player*)malloc(sizeof(Player));

        fgetc(in);
        read_dataAboutPlayer(&new_player,in);

        add_P2toP1(first_player,&new_player);
    }
}
void read_dataAboutPlayer(Player** player,FILE* in)
{
    ///citire date despre jucator
    (*player)->firstName=(char*)malloc(33*sizeof(char));
    (*player)->secondName=(char*)malloc(33*sizeof(char));

    fscanf(in,"%s",(*player)->firstName);
    fscanf(in,"%s",(*player)->secondName);
    fscanf(in,"%d",&(*player)->points);
}
void add_P2toP1(Player** p1,Player** p2)
{
    (*p2)->next=(*p1);
    *p1=*p2;
}
void enter_Teams(Team** team,int n_ofTeams,FILE* in,FILE* out)
{
    ///inserare echipe in lista + calculare scor de echipa
    for(int i=1; i<n_ofTeams; i++)
    {
        Team *new_team=(Team*)malloc(sizeof(Team));

        read_n_ofPlayers(&new_team,in);

        read_name_ofTeam(&new_team,in);

        new_team->player=(Player*)malloc(sizeof(Player));
        add_toTeam(new_team->n_ofPlayers,&(new_team->player),in);
        new_team->team_score=AVG_score(new_team);

        new_team->next=(*team);
        (*team)=new_team;

    }
    Team *aux=*team;
    display_team(aux,out);
}
void display_team(Team* team,FILE* out)
{
    //int i=1;
    while(team!=NULL)
    {

        fprintf(out,"%s\n",team->name_ofTeam);
        //Player *player=team->player;
        /*while(player!=NULL)
        {
            fprintf(out,"%s %s %d\n",player->firstName,player->secondName,player->points);
            player=player->next;
        }*/
        //fprintf(out,"Average score: %.3f\n",team->team_score);
        //i++;
        team=team->next;
    }
}
