#include <stdio.h>
#include <string.h>
#include <ctype.h>
int hash(char str[20]){
    int hashval=0;
    int length=strlen(str);
    for(int i=0;i<length;i++)
        hashval=10*hashval+(((int)(toupper(str[i])))-64);
    return hashval;
}
void rc(char text[20],char pat[20]){
    int pathash=hash(pat);
    char win[20];
    int iters=strlen(text)-strlen(pat)+1;
    int count=0;
    for (int i=0;i<iters;i++){
        strncpy(win,text+i,strlen(pat));
        win[strlen(pat)]='\0';
        if (pathash==hash(win)){
            count++;
            printf("Match at index %d\n",i);
        }
    }
    if (!count)
        printf("NO MATCHES");
}
int main(){
    char text[20]="ABCDEFBCECBC";
    char pat[20]="BCEF";
    rc(text,pat);
    return 0;
}