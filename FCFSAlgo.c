#include<stdio.h>
#include<stdlib.h>

int main(){
    int p;
    printf("Enter No. of Processes:");
    scanf("%d",&p);
    int arr[p][6];
    //arr[p][0]=Process
    //arr[p][1]=Arrival Time
    //arr[p][2]=Burst Time
    //arr[p][3]=Completion Time
    //arr[p][4]=Turn Around Time
    //arr[p][5]=Waiting Time

    //Taking User Input
    for(int i=0;i<p;i++){
        printf("Enter Details of Process %d\n",i+1);
        arr[i][0]=i+1;
        for(int j=1;j<6;j++){
            if(j==1){
                printf("Enter Arrival Time:");
                scanf("%d",&arr[i][1]);
            }
            else if (j==2){
                printf("Enter Burst Time:");
                scanf("%d", &arr[i][2]);
            }
            else{
                arr[i][j]=0;
            }
        }
    }

    //sorting on the Basis of Arrival Time
    for (int i = 0; i < p; i++)
    {
        for (int j = i + 1; j < p; j++)
        {
            if (arr[i][1] > arr[j][1])
            {
                for (int k = 0; k < 6; k++)
                {
                    int temp = arr[i][k];
                    arr[i][k] = arr[j][k];
                    arr[j][k] = temp;
                }
            }
        }
    }

    //Calculating Completion Time
    int completion = 0;
    for(int i=0;i<p;i++){
        if (completion<arr[i][1]){
            completion=arr[i][1];
        }
        completion=completion + arr[i][2];
        arr[i][3]=completion;
    }

    //Calculating Turn Around Time and Waiting Time
    for(int i=0;i<p;i++){
        arr[i][4]=arr[i][3]-arr[i][1];
        arr[i][5]=arr[i][4]-arr[i][2];
    }
   
    //Printing the Table
    printf("P\tAT\tBT\tCT\tTA\tWT\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<6;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    //Calculating Average Turn Around Time
    int avgTAT=0;
    int avgWT=0;
    for(int i=0;i<p;i++){
        avgTAT=arr[i][4];
        avgWT=arr[i][5];
    }
    printf("\tAverage Turn Around Time = %d\n\tAverage Waiting Time =%d\n",avgTAT/p,avgWT/p);

}