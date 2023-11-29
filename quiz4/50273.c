#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[101][1000];
    int n=0;
    char test[1000];
    while(scanf("%s",&s[n])!=EOF){
        n++;
    }
    int sum=0;
    int firstto,firstfrom;
    int from,to;
    int check=0;
    int l0=strlen(s[0]),l1=strlen(s[1]);
    for(int i=0;i<l0;i++){
        for(int j=0;j<l1;j++){
            if(s[0][i]==s[1][j]){
                check=1;
                firstto=i;
                from=j;
                break;
            }
        }
        if(check) break;
    }
    for(int i=1;i<n-1;i++){
        check=0;
        l0=strlen(s[i]),l1=strlen(s[i+1]);
        //printf("/%c %c/",s[i][5],s[i+1][1]);
        for(int j=0;j<l0;j++){
            for(int k=0;k<l1;k++){
                if(s[i][j]==s[i+1][k]){
                    check=1;
                    sum+=(j-from);
                    from=k;
                    break;
                }
            }
            if(check) break;
        }
    }
 
    l0=strlen(s[0]),l1=strlen(s[n-1]);
    check=0;
    for(int i=0;i<l0;i++){
        for(int j=0;j<l1;j++){
            if(s[0][i]==s[n-1][j]){
                //printf("/%d %d/",i,j);
                check=1;
                sum+=(j-from);
                firstfrom=i;
                break;
            }
        }
        if(check) break;
    }
    sum+=(firstto-firstfrom);
    printf("%d",sum);
    return 0;
}
