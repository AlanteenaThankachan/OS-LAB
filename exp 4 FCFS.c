#include <stdio.h>
void main()
{
     int n,i,j;
     double avg_wait=0,avg_tt=0;
     printf("Enter the number of processes: ");
     scanf("%d",&n);
     int bt[n],wt[n],tt[n];
     printf("Enter the burst time of the processes\n");
     for(i=0;i<n;i++)
     {
      printf("P%d Burst time: ",(i+1));
      scanf("%d",&bt[i]);
     }
     wt[0]=0;
     for(i=0;i<n;i++)
     {
      wt[i]=wt[i-1]+bt[i-1];
      avg_wait=avg_wait+wt[i];
     }
     avg_wait=avg_wait/n;
     for(i=0;i<n;i++)
     {
      tt[i]=wt[i]+bt[i];
      avg_tt=avg_tt+tt[i];
     }
     avg_tt=avg_tt/n;
     printf("Process\tBurst time\tWait time\tTurn around time\n");
     for(i=0;i<n;i++)
     {
       printf("P%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tt[i]);
     }
     printf("\n");
     printf("Average waiting time: %.2f\nAverage turn around time: %.2f\n",avg_wait,avg_tt);
     printf("\n");
     printf(" ");
     for(i=0;i<n;i++)
     {
       printf("---------");
     }
     printf("\n |  ");
     for(i=0;i<n;i++)
     {
       printf(" P%d  | ",i+1);
     }
     printf("\n |  ");
     for(i=0;i<n;i++)
     {
       printf("---------");
     }
     printf("\n0\t");
     int current_time=0;
     for(i=0;i<n;i++)
     {
       current_time=current_time+bt[i];
       printf("%d\t",current_time);
     }
     printf("\n");
}






