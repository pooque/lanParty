#include "player.h"
int main()
{
    int n;
    int *c=(int*)malloc(5*sizeof(int));
    FILE *in,*out,*cin;
    in=fopen("d.in","rt");
    out=fopen("r.out","wt");
    cin=fopen("c.in","rt");
    fscanf(in,"%d",&n);

    Team* first_team;
    match_1v1 *first_Match,*last_Match;
    stackTeams *winners=NULL,*losers=NULL;
    Team *top8;
    BST *root;

    for(int i=0;i<5;i++)
        fscanf(cin,"%d",&c[i]);
    if(c[0]==1)
        task1(in,out,&first_team,n);
    if(c[1]==1)
        task2(in,out,&first_team,&n);
    display_team(first_team,out);
    if(c[2]==1)
        task3(in,out,first_team,&n,&first_Match,&last_Match,winners,losers,&top8);
    if(c[3]==1)
        task4(out,&root,&top8);

    fclose(in);
    fclose(out);
    return 0;
}
