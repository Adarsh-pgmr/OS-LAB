#include<stdio.h>

 int main()

{

    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp,at[20],s,tt,pt[20];

    float avg_wt,avg_tat;

    printf("Enter number of process:");

    scanf("%d",&n);

    printf("Enter priority (less number has high prority):\n");

    for(i=0;i<n;i++)

    {

        printf("p%d:",i+1);

        scanf("%d",&pt[i]);

        p[i]=i+1;         

    }

    

     for(i=0;i<n;i++)

    {

        s=i;

        for(j=i+1;j<n;j++)

        {

            if(pt[j]<pt[s])

                s=j;

        }

  

        tt=at[i];

        at[i]=at[s];

        at[s]=tt;

  

        tt=p[i];

        p[i]=p[s];

        p[s]=tt;

        

    }   

    printf("Enter Arrival Time:\n");

    for(i=0;i<n;i++)

    {

        printf("p%d:",i+1);

        scanf("%d",&at[i]);

        p[i]=i+1;         

    } 

    printf("Enter Burst Time:\n");

    for(i=0;i<n;i++)

    {

        printf("p%d:",i+1);

        scanf("%d",&bt[i]);

        p[i]=i+1;         

    }   

    wt[0]=0;            

  

   

    for(i=1;i<n;i++)

    {

        wt[i]=0;

        for(j=0;j<i;j++)

            wt[i]+=bt[j];

  

        total+=wt[i];

    }

  

    avg_wt=(float)total/n;      

    total=0;

  

   printf("\nProcess\t\tArrival time\tBurst Time\t\tPriority\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)

    {

        tat[i]=wt[i] - at[i];   

        total+=tat[i];

       printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i],at[i],pt[i],bt[i],wt[i],tat[i]);

    }

  

    avg_tat=(float)total/n;    

    printf("\nAverage Waiting Time=%f",avg_wt);

    printf("\nAverage Turnaround Time=%f\n",avg_tat);

}