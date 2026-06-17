#include <stdio.h>

int main()
{
    int n, bt[20], rem[20];
    int tq, i, complete=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);
        rem[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    while(complete<n)
    {
        complete=0;

        for(i=0;i<n;i++)
        {
            if(rem[i]>0)
            {
                if(rem[i]>tq)
                {
                    printf("P%d executed for %d units\n",i+1,tq);
                    rem[i]-=tq;
                }
                else
                {
                    printf("P%d completed\n",i+1);
                    rem[i]=0;
                }
            }

            if(rem[i]==0)
                complete++;
        }
    }

    return 0;
}
