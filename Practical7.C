//		QUE 7 for Round Robin scheduling 

#include<iostream.h>
#include<conio.h>

void main()
{
	int prcs[10], n, i, arv[10], brst[10], temp, tempb, tempp, sumb, j;
	int tempa, t, time, wt[10], wtt[10], max, maxi, y=1;
	float st=0.0, tt=0.0, wt=0.0;
	clrscr();
	printf("Enter no. of processes: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		prcs[i] = i;

		printf("Enter arrival time for P%d: ", i);
		scanf("%d", &arv[i]);
		printf("Enter burst time for P%d: ", i+1);
		scanf("%d", &brst[i]);
		wt[i] = 0;
		wtt[i] = 0;
	}
	
	printf("\nEnter time slice: ");
	scanf("%d", &time);

	printf("\nProcess\tArrival Time\tBurst Time\n");
	for(i=0; i<n; i++)
	{
		printf("P%d\t %d\t\t %d\n", prcs[i], arv[i], brst[i]);
		printf("\n");
	}
	
	printf("\nAfter sorting processes acc. to arrival time: \n");
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1; j++)
			if(arv[j]>arv[j+1])
			{
				tempa = arv[j];
				arv[j] = arv[j+1];
				arv[j+1] = tempa;
				tempb = brst[j];
				brst[j] = brst[j+1];
				brst[j+1] = tempb;				
				tempp = prcs[j];
				prcs[j] = prcs[j+1];
				prcs[j+1] = tempp;
			}
	}

	max  = brst[0];
	maxi = 0;

	for(i=0; i<n; i++)
	{
		if(max<brst[i])
		{
			max  = brst[i];
			maxi = i;
		}
	}

	while(y>0)
		for(i=0; i<n; i++)
		{
			if(brst[i]>0)
			{
				if(brst[i]>time)
				{
					brst[i] -= time;
					st += time;
					wt[i] += time;
				}
				else
				{
					wtt = st-wt[i];
					st += brst[i];
					printf("\nwtt of %d is %d", i, wtt[i]);
					wat = wat+wtt[i]-arv[i];
					tt = tt+st-arv[i];
					printf("\nfor %d, aiting time is %f\nturn around time is %f", i, wat/n, tt/n);
					brst[i] = 0;
				}
				if(burst[maxi]==0)
					y=0;
			}
		}

	printf("\nWaiting time= %f\nTurn around time= %f", wat/n, tt/n);
	getch();
}