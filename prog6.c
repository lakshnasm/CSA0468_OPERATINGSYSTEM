#include <stdio.h>

int main()
{
    int n, bt[20], pr[20], rt[20];
    int complete=0, time=0;
    int shortest, min;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Priority P%d: ",i+1);
        scanf("%d",&pr[i]);

        rt[i]=bt[i];
    }

    while(complete!=n)
    {
        min=9999;
        shortest=-1;

        for(int i=0;i<n;i++)
        {
            if(rt[i]>0 && pr[i]<min)
            {
                min=pr[i];
                shortest=i;
            }
        }

        rt[shortest]--;
        time++;

        if(rt[shortest]==0)
            complete++;
    }

    printf("Preemptive Priority Scheduling Completed\n");

    return 0;
}
