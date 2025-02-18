#include<stdio.h>
void swap(int *a,int *b) 
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
 {
    int n,i,j;
    double atat=0,awt=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int bt[n],wt[n],tat[n],pqueue[n];
    for(i=0;i<n;i++) 
    {
        printf("Enter burst time for Process %d: ",i+1);
        scanf("%d",&bt[i]);
        pqueue[i]=i+1; 
        printf("\n");
    }
    for(i=0;i<n;i++) 
    {
        for(j=0;j<n-i-1; j++)
         {
            if(bt[j]>bt[j+1]) 
            {
                swap(&bt[j],&bt[j+1]);
                swap(&pqueue[j],&pqueue[j+1]);
            }
        }
    }
    wt[0]=0; 
    for(i=1;i<n;i++)
     {
       wt[i]=wt[i-1]+bt[i-1];
     }
    for(i=0;i<n;i++) 
    {
      tat[i]=wt[i]+bt[i];
    }
    for(i=0;i<n;i++) 
    {
       awt += wt[i];
       atat += tat[i];
    }
    awt /= n;
    atat /= n;
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", pqueue[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f",awt);
    printf("\nAverage Turnaround Time: %.2f\n",atat);
    printf("\n");
    printf("------------------------------\n");
    printf("|");
    for (i = 0; i < n; i++)
    {
        printf(" P%d\t|", pqueue[i]);
    }
    printf("\n------------------------------\n");
    printf("0\t");
    int ctime = 0;
    for (i = 0; i < n; i++)
    {
       ctime += bt[i];
       printf("%d\t", ctime);
    }
    printf("\n");
}
