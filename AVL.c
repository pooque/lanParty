#include "player.h"
Team* findAt_m(Team* List,int m)
{
    int k=1;
    while(k<m)
    {
        List=List->next;
        k++;
    }
    return List;
}
void add_toRoot(Tree** root,Team* List,int m)
{
    Tree *newNode=(Tree*)malloc(sizeof(Tree));
    newNode->team=findAt_m(List,m/2);
    newNode->right=newNode->left=NULL;
    (*root)=newNode;
}
/*void create_AVL(Tree** root,Team* List,int m)
{
   add_toRoot(root,List,m);
   List=List->next;

   add_toRoot(&(*root)->left,)
}*/
void display_List(FILE* out,Team* List)
{
    fprintf(out,"\n");
    while(List!=NULL)
    {
        fprintf(out,"%s\n",List->name_ofTeam);
        List=List->next;
    }
}
void add_toList(Team** List,Team* team)
{
    Team *newNode=(Team*)malloc(sizeof(Team));
    newNode=team;
    newNode->next=(*List);
    (*List)=newNode;
}
void add_BST_toList(FILE* out,Tree* root,Team** List)
{
    if(root)
    {
        add_BST_toList(out,root->right,List);
        add_toList(List,root->team);
        add_BST_toList(out,root->left,List);
    }
}
