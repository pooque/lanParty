#include "player.h"
//void display
void display_BST(BST* root,FILE* out)
{
    if(root)
    {
        display_BST(root->right,out);
        fprintf(out,"%s",root->team->name_ofTeam);
        for(int i=0;i<33-strlen(root->team->name_ofTeam);i++)
            fprintf(out," ");
        fprintf(out,"-");
        fprintf(out,"%.2f\n",root->team->team_score);
        display_BST(root->left,out);
    }
}
void delete_fromTop(Team** top8)
{
    Team *aux=*top8;
    (*top8)=(*top8)->next;
    free(aux);
}
void add_toTree(BST** root,Team** top8)
{
    if(*root)
    {
        if((*top8)->team_score == (*root)->team->team_score)
        {
            if(strcmp((*top8)->name_ofTeam,(*root)->team->name_ofTeam)<0)
                add_toTree(&(*root)->left,top8);
            else
                add_toTree(&(*root)->right,top8);
        }
        else
            if((*top8)->team_score < (*root)->team->team_score)
            add_toTree(&(*root)->left,top8);
        else
            add_toTree(&(*root)->right,top8);
    }
    else
        add_toLeaf(root,top8);
}
void add_toLeaf(BST** node,Team** top8)
{
    BST *newNode=(BST*)malloc(sizeof(BST));
    newNode->team=*top8;
    newNode->left=newNode->right=NULL;
    delete_fromTop(top8);
    (*node)=newNode;
}
void create_BST(BST** root,Team** top8)
{
    *root=NULL;
    while((*top8)!=NULL)
    {
        add_toTree(root,top8);
    }
}
