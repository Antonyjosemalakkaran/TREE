#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*lc;
	int data;
	struct node*rc;
}*root,*ptr,*newnode,*par;
struct node* getnode(int key)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->lc=NULL;
	newnode->rc=NULL;
return newnode;	
}
struct node* find(int item)
{
	struct node*loc,*ptr,*save;
	if(root==NULL)
	{
		loc=NULL;
		par=NULL;
		return loc;
	}
	if(root->data==item)
	{
		loc=root;
		par=NULL;
		return loc;
	}
	if(item<root->data)
	{
		ptr=root->lc;
		save=root;
	}
	else
	{
		ptr=root->rc;
		save=root;
	}
	while(ptr!=NULL)
	{
		if(item==ptr->data)
		{
			loc=ptr;
			par=save;
			return loc;
		}
		else
		{
			if(item<ptr->data)
			{
				save=ptr;
				ptr=ptr->lc;
			}
			else
			{
				save=ptr;
				ptr=ptr->rc;
			}
		}
	}
	loc=NULL;
	par=save;
	return loc;
}
struct node* insert(struct node*ptr,int item)
{
	if(ptr==NULL)
	return getnode(item);
	else{
	if(item<ptr->data)
	{
	ptr->lc=insert(ptr->lc,item);
	}
	else if(item>ptr->data)
	{
	ptr->rc=insert(ptr->rc,item);
	}
	}
}
void preorder(struct node*ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->lc);
		preorder(ptr->rc);
	}
}
void inorder(struct node*ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lc);
		printf("%d ",ptr->data);
		inorder(ptr->rc);
	}
}
void inorder2(struct node*ptr,int h)
{int i=1;
	if(i!=h)
	{	i++;
		inorder(ptr->lc);
		printf("%d ",ptr->data);
		inorder(ptr->rc);
	}
}
void postorder(struct node*ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lc);
		postorder(ptr->rc);
		printf("%d ",ptr->data);
	}
}
int max(int item1,int item2)
{
	if(item1>=item2)
		return item1;
	else
		return item2;
}
int height(struct node*tree)
{
	if(tree==NULL)
		return 0;
	else
		return (max(height(tree->lc),height(tree->rc))+1);
}
struct node* mirror(struct node*tree)
{
	struct node*temp;
	if(tree!=NULL)
	{
		mirror(tree->lc);
		mirror(tree->rc);
		temp=tree->lc;
		tree->lc=tree->rc;
		tree->rc=temp;
	}
	return tree;
}

void casea(struct node*loc,struct node*par)
{
	struct node*child;
	if((loc->lc==NULL)&&(loc->rc==NULL))
	{
	child=NULL;	
	}
	else if((loc->lc)!=NULL)
		child=loc->lc;
	else 
		child=loc->rc;
	if(par!=NULL)
	{
		if(loc==par->lc)
			par->lc=child;
		else
			par->rc=child;
	}
	else
		root=child;
}

void caseb(struct node*loc,struct node*par)
{
	struct node*suc,*parsuc,*save,*ptr;
	ptr=loc->rc;
	save=loc;
	while(ptr->lc!=NULL)
	{
	save=ptr;
	ptr=ptr->lc;	
	}
	suc=ptr;
	parsuc=save;
	casea(suc,parsuc);
	if(par!=NULL)
	{
		if(loc==par->lc)
			par->lc=suc;
		else
			par->rc=suc;
	}
	else
		root=suc;
	suc->lc=loc->lc;
	suc->rc=loc->rc;
}
void del(int item)
{
	struct node*loc;
	loc=find(item);
	if(loc==NULL)
	{
		printf("ITEM NOT FOUND TO DELETEE");
	}
	if((loc->lc!=NULL)&&(loc->rc!=NULL))
	{
		caseb(loc,par);
	}
	else
	{
		casea(loc,par);
	}
	free(loc);
}
int totalnode(struct node*tree)
{
	if(tree==NULL)
		return 0;
	else
		return (totalnode(tree->lc)+1+totalnode(tree->rc));
}
int externalnode(struct node*tree)
{
	if(tree==NULL)
		return 0;
	else if(tree->lc==NULL&&tree->rc==NULL)
		return 1;
	else
		return (externalnode(tree->lc)+externalnode(tree->rc));
}
int internalnode(struct node*tree)
{
	if(tree==NULL)
		return 0;
	else if(tree->lc==NULL&&tree->rc==NULL)
		return 0;
	else
		return (internalnode(tree->lc)+1+internalnode(tree->rc));
}
void main()
{
int i,j,ele,ch,h=0;
printf("\nENTER THE ROOT ELEMENT\n");
scanf("%d",&ele);
root=getnode(ele);
while(ele!=-1)
{
printf("\nENTER THE ELEMENTS TO INSERT: \n");
scanf("%d",&ele);
if(ele==-1)
continue;
insert(root,ele);	
}
	
printf("\n BST TREE TREAVERSALS \n");
printf("\nPREORDER\n");
preorder(root);	
printf("\nINORDER\n");
inorder(root);	
printf("\nPOSTORDER\n");
postorder(root);

while(ch!=6)
{
printf("\nMENU 1.INSERTION 2.DELETION 3.SEARCH 4.HEIGHT OF TREE 5.MIRROR IMAGE");
scanf("%d",&ch);
switch(ch)
{
	case 1:
		{
			printf("ENTER THE ELEMENT TO INSERT: ");
			scanf("%d",&ele);
			insert(root,ele);
			printf("\n TREE \n");
			inorder(root);
			break;
		}
	case 2:
		{
			printf("ENTER THE ELEMENT TO INSERT: ");
			scanf("%d",&ele);
			del(ele);
			printf("\nPREORDER\n");
			preorder(root);	
			printf("\nINORDER\n");
			inorder(root);	
			break;
		}
	case 3:
		{
		printf("ENTER THE ELEMENT TO SEARCH: ");
		scanf("%d",&ele);
		if(find(ele)!=NULL)
			printf("ELEMENT FOUND");
		else
			printf("ELEMENT NOT FOUND");
		break;	
		}
	case 4:
		{
			printf("\nheight of tree\n");
			printf("%d",height(root));
			printf("\ntotal node of tree\n");
			printf("%d",totalnode(root));
			printf("\ninternal of tree\n");
			printf("%d",internalnode(root));
			printf("\nexternal of tree\n");
			printf("%d",externalnode(root));
			printf("ENTR THE NO OF HEIGHT: ");
			scanf("%d",&h);
			inorder2(root,h);
			break;
		}
	case 5:
		{
			mirror(root);
			printf("\nPREORDER\n");
			preorder(root);	
			printf("\nINORDER\n");
			inorder(root);
			
			break;
		}
	 
}//switch
}//while		
	
}//main
