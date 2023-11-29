#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
int check(char *s){
    return((strcmp(s,"if")&&strcmp(s,"else")&&strcmp(s,"while")&&strcmp(s,"for")&&strcmp(s,"switch")
           &&strcmp(s,"case")&&strcmp(s,"void")&&strcmp(s,"int")&&strcmp(s,"float")&&strcmp(s,"char")&&strcmp(s,"break")&&strcmp(s,"return")));
 
}
 
int cheval(char *s){
    int l=strlen(s);
    if(!( isalpha(s[0]) ||s[0]=='_'))return 0;
    for(int i=0;i<l;i++){
        if(!((isdigit(s[0]))|| isalpha(s[0]) ||s[0]=='_'))return 0;
    }
    return 1;
}
 
int main(){
    char s[1000];
    char *dil="(){}[], ;?:!*&+-*/%&|<>=\n";
    int cnt[31]={0};
    char in[31][31];
    int num=0;
    int l=10;
    while(fgets(s,1000,stdin)!=NULL){
    //while(l--){
        //fgets(s,1000,stdin);
        char *tok=strtok(s,dil);
        while(tok!=NULL){
            //printf("%s %d %d\n",tok,check(tok),cheval(tok));
            if(check(tok)&&cheval(tok)){
                int check=0;
                for(int i=0;i<num;i++){
                    if(strncmp(tok,in[i],24)==0) {
                        check=1;
                        cnt[i]++;
                        break;
                    }
                }
                if(check==0){
                    strncpy(in[num],tok,24);
                    cnt[num]++;
                    num++;
                }
            }
            tok=strtok(NULL,dil);
        }
    }
    for(int i=0;i<num;i++) {
            int len=(24>strlen(in[i])?strlen(in[i]):24);
        for(int j=0;j<len;j++) printf("%c",in[i][j]);
            printf(" %d\n",cnt[i]);
    }
    return 0;
}
