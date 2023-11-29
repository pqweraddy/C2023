#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long pow(int a){
    long long sum=1;
    while(a--)sum*=1000;
    return sum;
}
 
int main(){
    char hun[2][10]={"\0"," hundred "};
    char in[7][15]={"\0"," thousand"," million"," billion"," trillion"," quadrillion"," quintillion"};
    char teen[100][10]={"\0","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char ty[10][10]={"\0","\0","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    char j[2][2]={"\0","-"};
    long long n;
    scanf("%lld",&n);
    int best=0;
    long long test=n;
    while(test>=1000){
            best++;
            test/=1000;
    }
    //printf("%d",best);
    int a=best;
    for(;best>=0;best--){
        test=n;
        test/=pow(best);
        //printf("a%llda",test);
        if(test==0) continue;
        //printf("b%db",pow(a-best));
        if(test>1&&pow(a-best)!=1) test%=1000;
        //printf("/%lld/",test);
        if(best!=a) printf(" ");
        printf("%s%s%s%s%s",teen[test/100],hun[(test>=100)],
            ty[(test/10)%10],j[((test/10)%10)>1],teen[(((test/10)%10)>1?test%10:test%100)] );
        printf("%s",in[best]);
    }
}
