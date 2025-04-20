#include <stdio.h>
#define MAX_JOBS 5
#include <stdlib.h>
typedef struct {
    int id;
    int profit;
    int deadline;
} Job;

void swap(Job* a, Job* b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

// Sort jobs by descending profit and increasing deadline if tie
void sortJobs(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (jobs[i].profit < jobs[j].profit ||
               (jobs[i].profit == jobs[j].profit && jobs[i].deadline > jobs[j].deadline)) {
                swap(&jobs[i], &jobs[j]);
            }
        }
    }
}

int main() {
    Job jobs[MAX_JOBS] = {
        {1, 100, 2},
        {2, 80, 3},
        {3, 50, 1},
        {4, 45, 4},
        {5, 40, 4}
    };

    sortJobs(jobs, MAX_JOBS);

    int max_deadline = 0;
    for (int i = 0; i < MAX_JOBS; i++) {
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    int* slots=(int*)malloc(sizeof(int)*max_deadline);
    for (int i = 0; i < max_deadline; i++)
        slots[i] = -1;  

    int total_profit = 0;

    for (int i = 0; i < MAX_JOBS; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Jobs selected: ");
    for (int i = 0; i < max_deadline; i++) {
        if (slots[i] != -1)
            printf("JOB%d ", slots[i]);
    }
    printf("\nTotal Profit: %d\n", total_profit);

    return 0;
}
