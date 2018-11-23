//		FIRST/ BEST/ WORST FIT Algo.

#include<conio.h>
#include <stdio.h>
void main()
{
	int sb,sp,p[10],b[10],i,j;

	clrscr();
	printf("enter the no. of blocks:\t");
	scanf("%d",&sb);
	printf("enter the sizes of block:\t");
	for(i=0;i<sb;i++)
		scanf("%d",&b[i]);

	printf("enter the no. of processes:\t");
	scanf("%d", &sp);
	printf("enter the size of processes:\t");
	for(i=0;i<sp;i++)
		scanf("%d",&p[i]);

	printf("processes and blocks entered values\n");
	for(i=0;i<sp;i++)
		printf("process%d\t%d\n",i,p[i]);
	for(i=0;i<sb;i++)
		printf("block%d\t %d\n",i,b[i]);


	int choice;

	menu:
	clrscr();
	  
	  printf("\nMENU (Choose the Algo) \n");
	  printf("\n 1. First Fit ");
	  printf("\n 2. Best Fit ");
	  printf("\n 3. Worst Fit ");
	  printf("\n\n* Enter Your Choice: ");
	  
	  scanf("%d", &choice);

	 switch(choice)
	 {

		case 1: goto First;
			 	break;

		case 2: goto Best;
				break;

		case 3: goto Worst;
				break;

		default :  printf("\n Sorry! Wrong choice!!");

     }

  First:	
	{
	  for(i=0;i<sp;i++)
		for(j=0;j<sb;j++)
			if(p[i]<=b[j])
			{	printf("the process%dalloted block%d\n",i, j);
				p[i]=10000;
				b[j]=0;
			}

	}
  goto NoAlloc;

  Best:
  	{
  	  for(i=0;i<sp;i++)
	  {
		j=selbest(p[i].b,sb);
		if(j!=-1)
		{
			printf("process%d is allocated block%d\n",i,j);
			p[i]=10000;
			b[i]=0;
		}

	  }
  	}
  goto NoAlloc;
  
  Worst:
	{
	  for(i=0;i<sp;i++)
	  {
		j=selworst(p[i].b,sb);	// this fun
		if(j!=-1)
		{
			printf("process%d is allocated block%d\n",i,j);
			p[i]=10000;
			b[i]=0;
		}

	  }
	}


  NoAlloc:
	for(i=0;i<sp;i++)
	{
		if(p[i]!=10000)
			printf("the process %d does not get any block\n",i);
	}
	getch();
}

//------------------------------------------------------------//
/*
//		WORST FIT Algo.

#include<conio.h>
#Include<stdio.h>
void main()
{
	int sb, sp, p[10],b[10],i,j;
	clrscr();
	printf("enter the no. of blocks:\t");
	scanf("%d",&sb);
	printf("enter the sizes of block:\t");
	for(i=0;i<sb;i++)
		scanf("%d",&b[i]);

	printf("enter the no. of processes:\t");
	scanf("%d", &sp);
	printf("enter the size of processes:\t");
	for(i=0;i<sp;i++)
		scanf("%d",&p[i]);

	printf("processes and blocks entered values\n");
	for(i=0;i<sp;i++)
		printf("process%d\t%d\n",i,p[i]);
	for(i=0;i<sb;i++)
		printf("block%d\t %d\n",i,b[i]);
//----------------------	only difffers fun
	for(i=0;i<sp;i++)
	{
		j=selworst(p[i].b,sb);	// this fun
		if(j!=-1)
		{
			printf("process%d is allocated block%d\n",i,j);
			p[i]=10000;
			b[i]=0;
		}

	}
//----------------------	this block only


	for(i=0;i<sp;i++)
	{
		if(p[i]!=10000)
			printf("the process %d does not get any block\n",i);
	}
	getch();
}

int selworst(into,int b[10],int b)
{
	int k=0,ar[10],arin[10],max,i,j,index;
	for(i=0;i<bi;i++)
	{
		if(p<=b[i])
		{
			ar[k]=b[i];
			arin[k]=i;
			k++;
		}
	}

	if(k==0)
		return -1;
	else
	{
		max = ar[0];
		index=arin[0];
	}

	for(i=0;i<k;i++)
	{
		if(max<ar[i])
		{
			max=ar[i]:
			index=arin[i];
			return index;
		}
	}
}


///		BEST FIT Algo.

#include<conio.h>
#include<stdio.h>
vold main()
{
	int sb,sp,p[10],b[10],i,j;
	clrscr();
	
	printf("enter the no. of blocks:\t");
	scanf("%d",&sb);
	printf("enter the sizes of block:\t");
	for(i=0;i<sb;i++)
		scanf("%d",&b[i]);

	printf("enter the no. of processes:\t");
	scanf("%d", &sp);
	printf("enter the size of processes:\t");
	for(i=0;i<sp;i++)
		scanf("%d",&p[i]);

	printf("processes and blocks entered values\n");
	for(i=0;i<sp;i++)
		printf("process%d\t%d\n",i,p[i]);
	for(i=0;i<sb;i++)
		printf("block%d\t %d\n",i,b[i]);

	for(i=0;i<sp;i++)
	{
		j=selbest(p[i].b,sb);
		if(j!=-1)
		{
			printf("process%d is allocated block%d\n",i,j);
			p[i]=10000;
			b[i]=0;
		}

	}

	for(i=0;i<sp;i++)
	{
		if(p[i]!=10000)
			printf("the process %d does not get any block\n",i);
	}
	getch();
}

intselbest(int p, int b[10], int bi)
{
	int k=0, ar[10],arin[10],min,i,j,index;

	for(i=0;i<bi;i++)
	{	if(p<=b[i])
		{
			ar[k]=b[i];
			arin[k]=i,
			k++;
		}
	}
	if(k==0)
		return -1;
	else
	{
		min=ar[0];
		index=arin[0];
		for(i=0;i<k;i++)
		{
			if(min>ar[i])
			{
				min=ar[i];
				index=arin[i];
			}
		}

		return index;
	}
}

	*/