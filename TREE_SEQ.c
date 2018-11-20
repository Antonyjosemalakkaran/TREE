#include<stdio.h>
#include<math.h>
int a[100];
int size;
void set()
{
	int i;
	for(i=0;i<(sizeof(a)/sizeof(a[1]));i++)
	{
		a[i]=-1;
	}
}
void buildtree(int i,int item)
{
	int newl,newr,ch1,ch2;
	if(i!=0)
	{
		a[i]=item;
		printf("IF NODE LEFT(1/2): ");
		scanf("%d",&ch1);
		if(ch1==1)
		{
			if(a[2*i]==-1)
				{printf("NODE LEFT: ");
				scanf("%d",&newl);
				buildtree(2*i,newl);
				}
			else
			buildtree(0,-1);
		}
		printf("IF NODE RIGHT (1/2): ");
		scanf("%d",&ch2);
		if(ch2==1)
		{
			if(a[2*i+1]==-1)
				{printf("NODE RIGHT: ");
				scanf("%d",&newr);
				buildtree((2*i)+1,newr);
				}
			else
			buildtree(0,-1);	
		}
		
	}
}
int search(int i,int key)
{
	int p;
	if(a[i]==key)
			return i;
	else
	{
	if((2*i)<=size)
		{
		p=search((2*i),key);
		if(p!=0)
			return p;}
	if((2*i+1)<=size)
		{
		p=search((2*i)+1,key);
		if(p!=0)
			return p;}
	return 0;
	}
}
void preorder(int root)
{
int pre;
pre=root;
if(a[pre]!=-1)
        {
        printf("%d ",a[pre]);
        preorder(2*pre);
        preorder((2*pre)+1);
        }
}
void main()
{
int num=1,root,height,i=0,l=0,j,k,count=0,mul,ser,found,cho,ele,ind,item1,item2,c1,c2,c,p,flag,s=0;
set();
printf("TREE\nENTER HEIGHT OF TREE:\n");
scanf("%d",&height);
size=pow(2,height)-1;
printf("\nENTER THE ELEMENTS OF TREE\n\n");
printf("Enter the no to insert to tree: ");
scanf("%d",&root);
buildtree(1,root);
printf("\nTREE\n");
preorder(1);
printf("\n--------------------------------------------------------------------------------------------------------------------");
while(c!=4)
{

printf("\n MENU\n1.SEARCH\n2.INSERT\n3.DELETE\n4.EXIT\n");
scanf("%d",&cho);
printf("--------------------------------------------------------------------------------------------------------------------\n");
switch(cho)
{
	case 1:
		{
		printf("\nSEARCH");
		printf("\nEnter the element to search: ");
		scanf("%d",&ser);
		found=search(1,ser);
		if(found!=0)
			printf("\nELEMENT FOUND AT %d",found);
		else
			printf("\nELEMENT NOT FOUND\n");
		printf("\nTREE\n");
		preorder(1);
		break;	
		}
	case 2:
		{
			printf("\nINSERT");
			printf("\nELEMENT TO INSERT AFTER: ");
			scanf("%d",&ele);
			s=search(1,ele);
			printf("%d",a[s]);
			if(s==0)
				{
				printf("\nSERACH UNSUCCESSFUL");
				break;}
			if((a[2*s]==-1)&&(a[2*s+1]==-1))
				{
					
					printf("\nINSERT AS LEFT(1/2):");
					scanf("%d",&c1);
					if(c1==1)
					{
						printf("\nENTER THE NO TO INSERT: ");
						scanf("%d",&item1);
						if(a[2*s]==-1)
							{
								a[2*s]=item1;
								size=2*size;
							}
						else
							printf("\nDESIRED INSERTION NOT POSSIBLE");
					}
					printf("\nINSERT AS RIGHT(1/2):");
					scanf("%d",&c2);
					if(c2==1)
					{
						printf("\nENTER THE NO TO INSERT: ");
						scanf("%d",&item2);
						if(a[2*s+1]==-1)
							{
								a[2*s+1]=item2;
								size=2*size+1;
							}
						else
							printf("\nDESIRED INSERTION NOT POSSIBLE");
					}
				}
			printf("\nNOT A LEAF NODE");
			printf("\nTREE\n");
			preorder(1);
			break;
		}
		case 3:
			{
			printf("\nDELETE");
			printf("\nELEMENT TO DELETE: ");
			scanf("%d",&ele);
			l=search(1,ele);
			if(l==0)
				{
				printf("\nSERACH UNSUCCESSFUL");
				break;}
			if((a[2*l]==-1)&&(a[(2*l)+1]==-1))
				{
				flag=1;
				a[l]=-1;
				}
			else
			{
				printf("\nNODE CONTAINING ITEM IS NODE LEAF NODE");
			}
			if(flag!=1)
				printf("\nNODE NOT EXIST NO DELETION");
			
			printf("\nTREE\n");
			preorder(1);
			break;
		}
		
			
}//switch
}//while

}//main
