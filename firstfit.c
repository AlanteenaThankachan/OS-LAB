#include<stdio.h>
void main()
{
 int memblk,limit,i,j;
 printf("Enter the no.of memory block \n");
 scanf("%d",&memblk);
 printf("Enter the no.of process \n");
 scanf("%d",&limit);
 struct memory
 {
  int size,alloc;
 }
 m[memblk];
 struct process
 {
   int psize,flag;
 }
 p[limit];
 printf("Enter the size of the memory block\n");
 for(i=0;i<memblk;i++)
 {
  printf("Enter the size of %d memory block = ",i);
  scanf("%d",&m[i].size);
  m[i].alloc=0;
 }
 printf("\n\nEnter the size of the processes \n");
 for(i=0;i<limit;i++)
 {
 printf("Enter the size of the %d process = ",i);
   scanf("%d",&p[i].psize);
   p[i].flag=0;
 }
 printf("\nPROCESS\tPROCESS SIZE\tBLOCKS\t\n");
 for(i=0;i<limit;i++)
 {
  for(j=0;j<memblk;j++)
  {
    if(p[i].flag==0)
    {
      if(p[i].psize<=m[j].size)
      {
        if(m[j].alloc==1)
        {
          continue;
        }
        else
        {
          m[j].alloc=1;
          p[i].flag=1;
          printf("\n%d\t%d\t\t%d\n",i,p[i].psize,m[j].size);
        }
      }
    }
  }
}
for(i=0;i<limit;i++)
{
  if(p[i].flag==0)
  {
   printf("There is no space for %d process\n",p[i].psize);
  }
 }
}





