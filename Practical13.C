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
