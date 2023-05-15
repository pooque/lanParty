#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct Player
{
    char* firstName;
    char* secondName;
    int points;
    struct Player *next;
}Player;
typedef struct team_ofPlayers
{
    int n_ofPlayers;                //number of players per team
    float team_score;                 //score of team (avg of points of each player)
    char* name_ofTeam;              //name of team
    struct Player *player;          //player
    struct team_ofPlayers* next;
}Team;

void create_list_ofTeams(Team** first_team,FILE* in,FILE* out);

float AVG_score(Team* team);
int min_Score(Team* team);
