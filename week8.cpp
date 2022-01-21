#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef phonedb elementtype;
typedef struct node node;
struct node{
  elementtype element;
  node *prev;
  node *next;
};
node *root=NULL, *cur=NULL, *tail=NULL;
node *makenewnode(elementtype e){
  node *new=(node*)malloc(sizeof(node));
  new->element=e;
  new->next=NULL;
  new->prev=NULL;
  return new;
}
void insertathead(elementtype e){
  node *new=makenewnode(e);
  if(root==NULL){
    root=new;
    tail=new;
    cur=root;
  }else{
    new->next=root;
    root->prev=new;
    new->prev=NULL;
    root=new;
    cur=root;
  }
}
void insertatlast(elementtype e){
  node *new=makenewnode(e);
  if(root==NULL){
    root=new;
    tail=new;
    cur=root;
  } else{
    tail->next=new;
    new->prev=tail;
    new->next=NULL;
    tail=new;
  }
}
void insertatpos(elementtype e, int n){
  if(root==NULL){
    insertathead(e);
    return;
  }
  if(n==0){
    insertathead(e);
    return;
  }
  node *p;
  int i;
  node *new=makenewnode(e);
  for(p=root, i=1;p!=NULL&&i<n;p=p->next,i++);
  if(p==NULL){
    insertatlast(e);
    return;
  }
