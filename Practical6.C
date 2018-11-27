//		QUE 6 for FCFS acheduling 

//#include<iostream.h>
//#include<conio.h>
#include <stdio.h>

void main()
{
	int i, j, n, at, bt, temp, temp1, temp2, awt[50], c, c_loc, k, t2, x;
	float awtime, att[50], burst, attime, a_wait;
	int mat[50][3];
//	clrscr();
	printf("Enter no. of processes: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		mat[i][0] = i+1;
		printf("Enter arrival and burst time for %d process: ", i+1);
		for(j=1; j<3; j++)
		{
			printf("%d", &x);
			mat[i][j] = x;
		}			
	}
	
	printf("\nProcess\tArrival Time\tBurst Time\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<3; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
	
	printf("\nAfter sorting processes acc. to arrival time: \n");
	for(i=0; i<n-1; i++)
	{
		c = mat[i][1];
		c_loc = i;
		for(j=i+1; j<n; j++)
		{
			if(mat[j][1] < c)
			{
				c = mat[j][1];
				c_loc = j;
			}
		}
		if(i != c_loc)
		{
			temp = mat[c_loc][1];
			mat[c_loc][1] = mat[i][1];
			mat[i][1] = temp;
			temp1 = mat[c_loc][2];
			mat[c_loc][2] = mat[i][2];
			mat[i][2] = temp1;
			temp2 = mat[c_loc][0];
			mat[c_loc][0] = mat[i][0];
			mat[i][0] = temp2;
		}
	}

	printf("\nProcess\tArrival Time\tBurst Time\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<3; j++)
			scanf("%d\t", mat[i][j]);
		printf("\n");
	}

	awt[0] = 0;
	mat[0][1];
	for(i=0; i<n-1; i++)
	{
		awt[i+1] = a_wait+(mat[i][2] - mat[i+1][1]);
		a_wait += mat[i][2];
	}

	for(i=0; i<n; i++)
		awtime += awt[i];
	awtime /= n;
	printf("\nAvg. waiting time= %f", awtime);
	att[0] = mat[0][2]-mat[0][1];
	burst = mat[0][2];

	for(i=0; i<n-1; i++)
	{
		burst += mat[i][2];
		att[i] = (burst - mat[i][1]);
	}

	for(i=0; i<n-1; i++)
		attime += att[i];
	attime /= n;

	printf("\nAvg. turnaround time: %f", attime);
//	getch();
}
