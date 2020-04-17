#include<stdio.h>
void main()
{
    int bt[20],p[20],ct[10],i,j,n,pos,temp;
    float atat,at[20],tat[20];
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("\nP%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
    printf("\nEnter arrival time of processes:");
    for(i=0;i<n;i++)
    {
     printf("\nP%d:",i+1);
     scanf("%f",&at[i]);
    }
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos]&&at[i])
                pos=j;
		
 	    }
 	    
 	  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
	
          

    	
    }
    
     ct[0]=bt[0]+at[0];
     for(i=1;i<n;i++)
     {
      ct[i]=ct[i-1]+bt[i];
     }
    for(i=0;i<n;i++)
    {
      tat[i]=ct[i]-at[i];
      atat=atat+tat[i];
    }
     printf("Process    Burst_Time \n");
     for(i=0;i<n;i++)
     {
      printf("P%d         %d	             \n",p[i],bt[i]);
     }
     atat=atat/n; 
     printf("\nAverage Turnaround Time=%f\n",atat);
}
