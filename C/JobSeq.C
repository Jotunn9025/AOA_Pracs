#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct{
    int id;
    int profit;
    int deadline;
} Job;
void swap(Job*a, Job*b){
    Job temp=*a;
    *a=*b;
    *b=temp;
}
int * JobSequence(Job arr[],int n){
    for (int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if (arr[i].profit<arr[j].profit ||(arr[i].profit==arr[j].profit && arr[i].deadline<arr[j].deadline))
                swap(&arr[i],&arr[j]);
    int maxdeadline=-1;
    for(int i=0;i<n;i++){
        maxdeadline=maxdeadline>arr[i].deadline?maxdeadline:arr[i].deadline;
    }            
    int* jobsAccepted=(int*)malloc(sizeof(int)*maxdeadline);
    for(int i=0;i<maxdeadline;i++){
        jobsAccepted[i]=-1;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if (count==maxdeadline)
            break;
        int curdeadline=arr[i].deadline;
        while (jobsAccepted[curdeadline-1]!=-1 && curdeadline>0){
            curdeadline--;
        }
        if (curdeadline>0 && jobsAccepted[curdeadline-1]==-1){
            jobsAccepted[curdeadline-1]=arr[i].id;
        }
    }
    return jobsAccepted;
}
int main() {
    Job jobs[] = {
        {1, 100, 2},
        {2, 50, 1},
        {3, 10, 3},
        {4, 15, 2},
        {5, 27, 1},
        {6, 30, 3}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    int* result = JobSequence(jobs, n);

    printf("Selected Job IDs:\n");
    for (int i = 0; i < 3; i++) { 
        if (result[i] != -1)
            printf("Slot %d -> Job ID %d\n", i, result[i]);
    }

    free(result);
    return 0;
}
