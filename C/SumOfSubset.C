#include<stdio.h>
void sos(int s[],int i,int currsum,int remsum,int target,int subset[],int subsetindex){
    if (currsum==target){// if reach target
    for(int j=0;j<subsetindex;j++)
        printf("%5d",subset[j]);
    printf("\n");
    return;
    }
    else if (currsum>target)//if overshot
        return;
    else if (currsum+remsum<target)//if cant reach
        return;
    subset[subsetindex++]=s[i];
    sos(s,i+1,currsum+s[i],remsum-s[i],target,subset,subsetindex);//check with next element
    subsetindex--;
    sos(s,i+1,currsum,remsum-s[i],target,subset,subsetindex);//check without next element
}
int main(){
    int s[10]={2,7,8,9,15};
    int subset[10]={0};
    int remsum=0;
    for (int i=0;i<5;i++){
        remsum+=s[i];
    }
    sos(s,0,0,remsum,17,subset,0);
    return 0;
}