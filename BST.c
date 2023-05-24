#include "player.h"
//void display
void display_BST(Tree* root,FILE* out)
{
    if(root!=NULL)
    {
        display_BST(root->right,out);
        fprintf(out,"%s",root->team->name_ofTeam);
        for(int i=0;i<34-strlen(root->team->name_ofTeam);i++)
            fprintf(out," ");
        fprintf(out,"-  ");
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
void add_toTree(Tree** root,Team* top8)
{
    if(*root)
    {
        if(top8->team_score == (*root)->team->team_score)
        {
            if(strcmp(top8->name_ofTeam,(*root)->team->name_ofTeam)<0)
                add_toTree(&(*root)->left,top8);
            else
                add_toTree(&(*root)->right,top8);
        }
        else
            if(top8->team_score < (*root)->team->team_score)
            add_toTree(&(*root)->left,top8);
        else
            add_toTree(&(*root)->right,top8);
    }
    else
        add_toLeaf(root,top8);
}
void add_toLeaf(Tree** node,Team* top8)
{
    Tree *newNode=(Tree*)malloc(sizeof(Tree));
    newNode->team=top8;
    newNode->left=newNode->right=NULL;
    (*node)=newNode;
}
void create_BST(Tree** root,Team** top8)
{
    *root=NULL;
    Team *aux=*top8;
    while(aux!=NULL)
    {
        add_toTree(root,aux);
        aux=aux->next;
    }
}
