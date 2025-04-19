class Job:
    def __init__(self,id,profit,deadline):
        self.id=id
        self.profit=profit
        self.deadline=deadline
    
def JobSequencing(jobList):
    n=len(jobList)
    for i in range(n-1):#bubble sorting jobs
        for j in range(i+1,n):
            if jobList[i].profit<jobList[j].profit:#if worth less
                jobList[i],jobList[j]=jobList[j],jobList[i]
            elif jobList[i].profit==jobList[j].profit and jobList[i].deadline>jobList[j].deadline:#if deadline of i is after j 
                jobList[i],jobList[j]=jobList[j],jobList[i]
    max_deadline = max(job.deadline for job in jobList)
    jobsAccepted = [None] * max_deadline
    total_profit = 0
    for job in jobList:
        for slot in range(job.deadline-1,-1,-1):# from job.deadline-1 to 0(as -1 not inclusive) backwards check if slot is free
            if jobsAccepted[slot] is None:
                jobsAccepted[slot]=job.id
                total_profit+=job.profit
                break#dont assign a job more than once
    
    print(f"Jobs {[job for job in jobsAccepted if job is not None]}")
    print(f"Total Profit:{total_profit}")

jobs = [Job('a', 100, 2), Job('b', 19, 1), Job('c', 27, 2), Job('d', 25, 1), Job('e', 15, 3)]
JobSequencing(jobs)