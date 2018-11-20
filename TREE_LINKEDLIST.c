#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node*lc;
int data;
struct node*rc;
}*root=NULL,*ptr=NULL,*rcptr=NULL,*lcptr=NULL,*newnode,*pre,*ele,*parent,*pre1;
struct node* getnode()
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->rc=NULL;
newnode->lc=NULL;
return newnode;
}
void buildtree(struct node*ptr,int item)
{
int ch,newl,newr;
if(ptr!=NULL)
{
        ptr->data=item;
        printf("NODE HAS LEFT SUBTREE(1/2): ");
        scanf("%d",&ch);
        if(ch==1)
                {
                lcptr=getnode();
                ptr->lc=lcptr;
                printf("ENTER THE NO TO INSERT: ");
                scanf("%d",&newl);
                buildtree(ptr->lc,newl);}
        else
                {
                lcptr=NULL;
                ptr->lc=NULL;
                buildtree(lcptr,0);
                }
        printf("NODE HAS RIGHT SUBTREE(1/2): ");
        scanf("%d",&ch);
        if(ch==1)
                {
                rcptr=getnode();
                ptr->rc=rcptr;
                printf("ENTER THE NO TO INSERT: ");
                scanf("%d",&newr);
                buildtree(ptr->rc,newr);}
        else
                {
                rcptr=NULL;
                ptr->rc=NULL;
                buildtree(rcptr,0);
                }
}
}
int preorder(struct node*ptr)
{
if(ptr!=NULL)
        {
        printf("%d ",ptr->data);
        preorder(ptr->lc);
        preorder(ptr->rc);
        }
else
    return 0;
}
struct node* search(struct node*ptr,int key)
{
struct node*found=NULL;
if(ptr==NULL)
        return NULL;
if(ptr->data==key)
        return ptr;
pre=ptr;
found=search(ptr->lc,key);
if(found!=NULL)
        return found;
pre=ptr;
found=search(ptr->rc,key);
if(found!=NULL)
        return found;
return NULL;
}
struct node* psearch(struct node*ptr,int key)
{
        struct node*found=NULL;
        if(ptr==NULL)
                return NULL;
        if(ptr->data==key)
                return NULL;
        if((ptr->lc!=NULL)&&(ptr->lc->data==key))
                return ptr;
        if((ptr->rc!=NULL)&&(ptr->rc->data==key))
                return ptr;
        if (((found=psearch(ptr->lc, key))!=NULL) || ((found=psearch(ptr->rc, key) )!=NULL))
        {
                return found;
        }
return NULL;
}
void main()
{
int i,j,cho=0,num=0,l=0,ser,c1,item,c2,item1;
printf("ENTER THE TREE\n");
root=getnode();
printf("\nENTER THE NO TO INSERT: ");
scanf("%d",&num);
buildtree(root,num);
printf("\nTREE \n");
preorder(root);
while(cho!=4)
{
printf("\nMENU\n1.INSERT NEWNODE\n2.DELETE A SPECIFIED NODE\n3.SEARCH A SPECIFIED NODE\n4.EXIT\n");
scanf("%d",&cho);

switch(cho)
{
case 1:
        {
        struct node*l;
        struct node*new;
        printf("ENTER THE ELEMNET TO INSERT AFTER:");
        scanf("%d",&ser);
        l=search(root,ser);
        if(l==NULL)
                printf("SEARCH UNSUCCESSFUL");
        if((l->lc==NULL)||(l->rc==NULL))
                {
                printf("INSERT LEFT(1/2): ");
                scanf("%d",&c1);
                if(c1==1)
                {
                        if(l->lc==NULL)
                        {
                        new=getnode();
                        printf("ENTER THE ELEMENT TO INSERT: ");
                        scanf("%d",&item);
                        new->data=item;
                        l->lc=new;}
                }
                else
                        printf("INSERTION NOT POSSIBLE LEFT CHILD");
                printf("INSERT RIGHT(1/2): ");
                scanf("%d",&c2);
                if(c2==1)
                {
                        if(l->rc==NULL)
                        {
                        new=getnode();
                        printf("ENTER THE ELEMENT TO INSERT: ");
                        scanf("%d",&item);
                        new->data=item;
                        l->rc=new;}
                }
                else
                        printf("INSERTION NOT POSSIBLE AS RIGHT CHILD");
                }
        else
                printf("NODE IS NOT LEAF NODE");
        printf("\nTREE\n");
        preorder(root);
        break;
        }
case 2:
       {
                                        struct node*ptr1,*ptr2,*loc;
                                        if(root==NULL)
                                        {printf("Tree Is Empty");
                                                break;}
                                        printf("Enter the Element To Be Deleted:");
                                        scanf("%d",&item1);
                                        parent=psearch(root,item1);
                                        //printf("%d",parent->data);
                                        if(parent!=NULL)
                                        {
                                                if(parent->lc->data==item1)
                                                {
                                                        if((parent->lc->lc==NULL)&&(parent->lc->rc==NULL))
                                                        {
                                                                //printf("%d",parent->lc->data);;
                                                                free(parent->lc);
                                                                parent->lc=NULL;
                                                        }
                                                        else
                                                            printf("Element is Not A Leaf Node,Deletion not Possible\n");
                                                }
                                                else
                                                {
                                                        if(parent->rc->data==item1)
                                                        {
                                                                if((parent->rc->lc==NULL)&&(parent->rc->rc==NULL))
                                                                {
                                                                        //printf("%d",parent->rc->data);
                                                                        free(parent->rc);
                                                                        parent->rc=NULL;
                                                                }
                                                        else
                                                            printf("Element is Not a Leaf Node,Deletion not Possible\n");
                                                        }
                                                }
                                        }
                                        else
                                        {
                                        if(root->data==item1)
                                        {
                                        printf("Can't Delete the Root Node");
                                        }
                                        else
                                                printf("NOde With Valuew '%d' Doesn't Exist",item1);
                                        }
                                        printf("\nTREE\n");
                                        preorder(root);
                                        break;
                                        }
case 3:
        {
        printf("ENTER THE ELEMNET TO SEARCH:");
        scanf("%d",&ser);
        ele=search(root,ser);
        if(ele!=NULL)
                printf("ELEMENT FOUND");
        else
                printf("ELEMENT NOT FOUND");
        break;
        }
}//switch
}//while
}//main

