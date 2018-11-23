//		QUE 8 for SJF scheduling 

#include<iostream.h>
#include<conio.h>

void sort(int a[], int b[], int n);

void main()
{
	int a[10], b[10], c[10], n, i, c, temp;
	int tempa, t, time, wt[10], wtt[10], max, maxi, y=1;
	float awt=0.0, att=0.0, sw=0.0, st=0.0;
	clrscr();
	printf("Enter no. of processes: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		prcs[i] = i;

		printf("Enter arrival time for P%d: ", i);
		scanf("%d", &a[i]);
		printf("Enter burst time for P%d: ", i+1);
		scanf("%d", &b[i]);
		//wt[i] = 0;
		//wtt[i] = 0;
	}

	sort(a, b, n);

	c[1] = c[0]+b[]1];
	sw += (c[0]-a[1]);
	st += (c[1]-a[1]);
	sort(b, a, n);

	for(i=2; i<=n; i++)
		c[i] = c[i-1]+b[i];
	for(i=2; i<=n; i++)
	{
		sw += (c[i-1]-a[i]);
		st += (c[i]-a[i]);
	}
	awt = sw/n;
	att = st/n;

	printf("\nAvg. Waiting time= %f\nAvg. Turn around time= %f", awt, att);
	getch();
}

void sort(int a[], int b[], int n)
{
	int i, j, temp, t;
	for(i=2; i<=n; i++)
		for(j=i+1; j<=n; j++)
			if(a[i]>a[j])
			{
				a[i] = a[j];
				a[j] = temp;
				t = b[i];
				b[i] = b[j];
				b[j] = t;
			}
}