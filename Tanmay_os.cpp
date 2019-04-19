#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int burstT[50],arrivalT[50],n,n2,n3,i,j,buffer,p[50],startT[50],endT[50],waitT[50],ta[50],te[50];
    int total_wt=0,total_at=0;
    float avg_wt,avg_ta;
    char name[20][20],t[10];
    //Level 1 code
    printf("Enter the number of process in Level 1:");
    scanf("%d",&n);n2=n;
    for(i=0; i<n; i++)
    {
		printf("Enter name of process : ");
 		scanf("%s",&name[i]);
 		
		printf("Enter process %d Arrival time: ",i+1);
		scanf("%d",&arrivalT[i]);
		
		printf("Enter process %d burst time: ",i+1);
		scanf("%d",&burstT[i]);

		printf("Enter process %d priority: ",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        {
            if(p[i]<p[j])
            {
                buffer=p[i];
                p[i]=p[j];
                p[j]=buffer;
                buffer=arrivalT[i];
                arrivalT[i]=arrivalT[j];
                arrivalT[j]=buffer;
                buffer=burstT[i];
                burstT[i]=burstT[j];
                burstT[j]=buffer;
                startTrcpy(t,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            startT[i]=arrivalT[i];
            waitT[i]=startT[i]-arrivalT[i];
            endT[i]=startT[i]+burstT[i];
            ta[i]=endT[i]-arrivalT[i];
        }
        else
        {
            startT[i]=endT[i-1];
            waitT[i]=startT[i]-arrivalT[i];
            endT[i]=startT[i]+burstT[i];
            ta[i]=endT[i]-arrivalT[i];
        }
        total_wt+=waitT[i];
    }
    
    // Level 2 code

     int buffer2=0 , k,time_stamp;
     int aw; float avg_wt2;
     int burstT2[50],waitT2[50],te2[50],rt2[50],arrivalT2[50];j=0;
     char name2[10][10];
     printf("\nenter number of process in Level2:\t");
     scanf("%d",&n3);
    for(i=0;i<n3;i++)
      {
      	 printf("Enter name of process : ");
 		 scanf("%s",&name2[i]);
          printf("%d  \nbrust time : ");
          scanf("%d",&burstT2[i]);
          printf("ariavl time : ");
          scanf("%d",&arrivalT2[i]);
          te2[i]=0;     waitT2[i]=0;
      }
    for(i=0;i<n3;i++)
      {
        for(j=i+1;j<n3;j++)
         {
             if(arrivalT2[i]>arrivalT2[j])      //sorting according to arrival time
               {
                    buffer2=arrivalT2[i];                                          
                    arrivalT2[i]=arrivalT2[j];
                    arrivalT2[j]=buffer;
                    buffer=burstT2[i];
                    burstT2[i]=burstT2[j];
                    burstT2[j]=buffer;
              }
         }
     }
    printf("\n enter time quantum : ");
    scanf("%d",&time_stamp); int q=0;
    printf("\nprocess  :")  ;
    for(i=0;i<n3;i++)
     {
       printf("  %d",i+1);
      }
    printf("\nBrustartT time : ");
    for(i=0;i<n3;i++)
       {
         printf("  %d",burstT2[i]); rt2[i]=burstT2[i];
        }
    printf("\nArrival time :");
    for(i=0;i<n;i++)
      {
          printf(" %d",arrivalT2[i]);
      }
    j=0;

    while(j<=n)
       {
          j++;
          for(i=0;i<n3;i++)
            {
              if(rt2[i]==0)  continue;
                   if(rt2[i]>time_stamp)
                     {
                        q=q+time_stamp;
                        rt2[i]=rt2[i]-time_stamp;
                        te2[i]=te2[i]+1;
                     }
                  else
                    {
                       waitT2[i]=q-te2[i]*time_stamp;
                       q=q+rt2[i]; 
                       rt2[i]=rt2[i]-rt2[i];
                    }
            }
       }                                   //end of while     
    avg_wt2=0;
    printf("\n Process   Waitnig time");
    for(i=0;i<n3;i++)
       {
                       waitT2[i]=waitT2[i]-arrivalT2[i];
                       avg_wt2=avg_wt2+waitT2[i];
        }
		int tat[10];
        for(i=0;i<n;i++)
        {
        	tat[i]=waitT[i]+burstT[i];	
		}
		int tat2[10];
		for(i=0;i<n3;i++)
		{
			tat2[i]=waitT2[i]+burstT2[i];
		}
		printf("\nPname\tArrival time\tBurst time\tpriority\tTAtime\t\tWaiting time");
    	for(i=0;i<n;i++)
		{
       		printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",name[i],arrivalT[i],burstT[i],p[i],ta[i],waitT[i]);
       	}
       	for(i=0;i<n3;i++)
		{
			printf("\n%s\t%5d\t\t%5d\t\t\t\t%5d\t\t%5d",name2[i],arrivalT2[i],burstT2[i],ta[i]);
		}
	for(i=0;i<n;i++) // sum of TAT
	{
		total_at=total_at+tat[i];
	}
	for(i=0;i<n3;i++)
	{
		total_at=total_at+tat2[i];
	}
    aw=avg_wt2+total_wt;
    float total=(float)aw/(n2+n3);
    float total2=(float)total_at/(n2+n3);
    printf("\nTotal TAtime : %d",total_at);
    printf("\nTotal waiting time : %d",aw);
    printf("\n Avg TAtime %f: ",total2);
    printf("\n Avg wainting time %f: ",total);
    getch();
    
}

