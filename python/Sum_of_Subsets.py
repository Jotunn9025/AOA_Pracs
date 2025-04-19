m=17
S=[2,7,8,9,15]
target=17
subset=[]
def SoS(curr_sum,rem_sum,target,subset,i):#recursive function to print subsets 
    if curr_sum==target:#if currsum is equivalent to target 
        print(subset)
        return
    elif(curr_sum+rem_sum<target):# if we cant reach target backtrack
        return
    elif(curr_sum>target):#if we overshot backtrack
        return
    subset.append(S[i])#add the enxt element
    SoS(curr_sum+S[i],rem_sum-S[i],target,subset,i+1)
    subset.pop()#dont add the next element
    SoS(curr_sum,rem_sum-S[i],target,subset,i+1)
SoS(0,sum(S),target,subset,0)# basecase start