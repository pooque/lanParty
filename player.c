#include "player.h"
void create_list_ofTeams(Team** first_team,FILE* in,FILE* out)
{
    int n;
    fscanf(in,"%d",&n);
    fprintf(out,"Aveti %d echipe.\n",n);

    Team *team=(Team*)malloc(sizeof(Team));
    *first_team=team;

    read_n_ofPlayers(&team,in);

    read_name_ofTeam(&team,in);

    add_toTeam(team->n_ofPlayers,&team->player,in);
    team->team_score=AVG_score(team);

    team->next=NULL;

    enter_Teams(first_team,n,in,out);
}
void read_n_ofPlayers(Team** team,FILE* in)
{
    fscanf(in,"%d",&(*team)->n_ofPlayers);
    fgetc(in);
}
void read_name_ofTeam(Team** team,FILE* in)
{
    (*team)->name_ofTeam=(char*)malloc(33*sizeof(char));
    fgets((*team)->name_ofTeam,33*sizeof(char),in);
}
void add_toTeam(int n_ofPlayers,Player** first_player,FILE* in)
{
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
    while(team!=NULL)
    {
        fprintf(out,"\n%d %s",team->n_ofPlayers,team->name_ofTeam);
        Player *player=team->player;
        while(player!=NULL)
        {
            fprintf(out,"%s %s %d\n",player->firstName,player->secondName,player->points);
            player=player->next;
        }
        fprintf(out,"Average score: %.3f\n",team->team_score);
        team=team->next;
    }
}
