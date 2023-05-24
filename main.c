#include "player.h"
int main(int argc, char *argv[])
{
    int n,m=8;
    int *c=(int*)malloc(5*sizeof(int));
    FILE *in,*out,*cin;
    cin=fopen(argv[1],"rt");
    in=fopen(argv[2],"rt");
    out=fopen(argv[3],"wt");
    
    fscanf(in,"%d",&n);

    Team* first_team;
    match_1v1 *first_Match,*last_Match;
    stackTeams *winners=NULL,*losers=NULL;
    Team *top8,*List=NULL;
    Tree *root;

    for(int i=0;i<5;i++)
        fscanf(cin,"%d",&c[i]);
    if(c[0]==1)
        task1(in,out,&first_team,n);
    if(c[1]==1)
        task2(out,&first_team,&n);
    display_team(first_team,out);
    if(c[2]==1)
        task3(out,first_team,&n,&first_Match,&last_Match,winners,losers,&top8);
    if(c[3]==1)
        task4(out,&root,&top8);
    if(c[4]==1)
        task5(out,root,&List);
    fclose(in);
    fclose(out);
    return 0;
}
