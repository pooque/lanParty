#include "player.h"
int main()
{
    FILE *in,*out;
    in=fopen("d.in","rt");
    out=fopen("r.out","wt");

    lanParty(in,out);

    fclose(in);
    fclose(out);
    return 0;
}
