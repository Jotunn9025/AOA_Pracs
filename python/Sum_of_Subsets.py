m=17
S=[2,7,8,9,15]
target=17
subset=[]
def SoS(curr_sum,rem_sum,target,subset,i):
    if curr_sum==target:
        print(subset)
        return
    elif(curr_sum+rem_sum<target):
        return
    elif(curr_sum>target):
        return
    subset.append(S[i])
    SoS(curr_sum+S[i],rem_sum-S[i],target,subset,i+1)
    subset.pop()
    SoS(curr_sum,rem_sum-S[i],target,subset,i+1)
SoS(0,sum(S),target,subset,0)