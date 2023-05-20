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
    int n_ofPlayers;
    float team_score;
    char* name_ofTeam;
    struct Player *player;
    struct team_ofPlayers* next;
}Team;

typedef struct matches_betweenTeams
{
	Team *t1,*t2;
	struct matches_betweenTeams *next;
}match_1v1;

typedef struct stack_ofTeams
{
	Team* team;
	struct stack_ofTeams *previous;
}stackTeams;

void lanParty(FILE* in,FILE* out);

void create_list_ofTeams(Team** first_team,FILE* in,FILE* out,int n_ofTeams);

float AVG_score(Team* team);
float min_Score(Team* team);
void purge_Teams(Team** team,int *n_ofTeams);

void set_Matches(Team* team,match_1v1** firstMatch,match_1v1** lastMatch);
void display_matches(match_1v1* match,FILE* out,int round);

void create_Stack(match_1v1** match,stackTeams** winners,stackTeams** losers);
void purge_Matches(match_1v1** match,stackTeams** winners,stackTeams** losers,int *n_ofTeams,FILE* out);
