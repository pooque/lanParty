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

typedef struct tree_BST_AVL
{
    Team *team;
    struct tree_BST_AVL *right,*left;
}Tree;

void task1(FILE* in,FILE* out,Team** first_team,int n);
void task2(FILE* out,Team** first_team,int* n);
void task3(FILE* out,Team* first_team,int *n,match_1v1** first_Match,match_1v1** last_Match,stackTeams* winners,stackTeams* losers,Team** top8);
void task4(FILE* out,Tree** root,Team** top8);
void task5(FILE* out,Tree* root,Team** List);

void create_list_ofTeams(Team** first_team,FILE* in,FILE* out,int n_ofTeams);
void read_n_ofPlayers(Team** team,FILE* in);
void read_name_ofTeam(Team** team,FILE* in);
void add_toTeam(int n_ofPlayers,Player** first_player,FILE* in);
void read_dataAboutPlayer(Player** player,FILE* in);
void add_P2toP1(Player** p1,Player** p2);
void enter_Teams(Team** team,int n_ofTeams,FILE* in,FILE* out);
void display_team(Team* team,FILE* out);

float AVG_score(Team* team);
float min_Score(Team* team);
int find_N_max(int x);
void purge_Teams(Team** team,int *n_ofTeams);
void delete_firstTeam(Team** team);
void delete_Team(Team** team);

void set_Matches(Team* team,match_1v1** firstMatch,match_1v1** lastMatch);
void makePair(Team* team,match_1v1** match);
void display_matches(match_1v1* match,FILE* out,int round);

void makePair_fromStack(stackTeams** stack,match_1v1** match);
void set_Matches_fromStack(stackTeams** winners,match_1v1** firstMatch,match_1v1** lastMatch);
void add_toStack(stackTeams** stack,Team* team);
void delete_matches(match_1v1** match);
void delete_stack(stackTeams** stack);
void add_toWhich(stackTeams** winners,stackTeams** losers,Team* toWinners,Team* toLosers);
void display_Stack(stackTeams* Stack,FILE* out);
void display_winners(stackTeams* Stack,FILE* out,int round);
void create_Stack(match_1v1** match,stackTeams** winners,stackTeams** losers);
void display_finalWinner(Team* team,FILE* out,int round);
void final_round(match_1v1** match,FILE* out,int round);
void purge_Matches(match_1v1** match,stackTeams** winners,stackTeams** losers,int *n_ofTeams,FILE* out,Team** top8);

void addTo_top8(Team** top8,stackTeams* winners);
void create_top8(Team** top8,stackTeams* team);

void display_BST(Tree* root,FILE* out);
void delete_fromTop(Team** top8);
void add_toTree(Tree** root,Team* top8);
void add_toLeaf(Tree** node,Team* top8);
void create_BST(Tree** root,Team** top8);

Team* findAt_m(Team* List,int m);
void add_toRoot(Tree** root,Team* List,int m);
void display_List(FILE* out,Team* List);
void add_toList(Team** List,Team* team);
void add_BST_toList(FILE* out,Tree* root,Team** List);
