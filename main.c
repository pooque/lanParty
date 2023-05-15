#include "player.h"
int main()
{
    FILE *in,*out;
    in=fopen("d.in","rt");
    out=fopen("r.out","wt");

    //Cerinta 1 - creare lista
    Team* first_team;
    create_list_ofTeams(&first_team,in,out);

    //Cerinta 2 -

    fclose(in);
    fclose(out);
    return 0;
}
