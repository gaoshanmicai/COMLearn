#include<stdlib.h>
#include<stdio.h>
#include"doubly_linked_list_node.h"

int dll_insert(Node *rootp,int value)
{
    Node *this;
    Node *next;
    Node *newnode;

    for(this = rootp;(next = this->fwd)!=NULL;this = next)
    {
        if(next->value == value)
            return 0;
        if(next->value > value)
            break;
    }
    newnode = (Node*)malloc(sizeof(Node));
    if(newnode==NULL)
        return -1;
    newnode->value = value;

    if(next !=NULL)
    {
        if(this !=rootp){
            newnode->fwd = next;
            this->fwd = newnode;
            newnode->bwd = this;
            next->bwd = newnode;
        }
        else{
            newnode->fwd = next;
            rootp->fwd = newnode;
            newnode->bwd = NULL;
            next->bwd = newnode;
        }
    }

    else{
        if(this !=rootp){
            newnode->fwd = NULL;
            this->fwd = newnode;
            newnode->bwd = this;
            rootp->bwd = newnode;
        }
        else{
            newnode->fwd = NULL;
            rootp->fwd = newnode;
            newnode->bwd = NULL;
            rootp->bwd = newnode;
        }
    }

    return 1;
}

int dlinklenCount(Node *rootp)
{
    int countLen =0;
    if(rootp ==NULL)
        return 0;
    for(;rootp!=NULL; rootp = rootp->fwd)
    {
        countLen++;

    }

    return countLen;

}

Node * dlinkSearchValue(Node *rootp,int value)
{
    Node *spt;
    if(rootp==NULL)
        return NULL;
    
    for(spt = rootp ;spt!=NULL;spt =spt->fwd)
    {
        if(spt->value == value)
            return spt;

    }
    return NULL;
}


int print_linklist(Node *rootp)
{
    Node *this;
    Node *next;
    Node *newnode;

    for(this = rootp;(next = this->fwd)!=NULL;this = next)
    {
        
        printf("the root value =%d\n",this->value);
    }
    return 0;

}