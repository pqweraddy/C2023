#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int n;
    scanf("%d",&n);
    int ar[50000][2];
    for(int i=0;i<n;i++){
        scanf("%d%d",&ar[i][0],&ar[i][1]);
    }
    int x,y;
    scanf("%d%d",&x,&y);
    int ans[50000]={0};
    int ansn=0;
    int ansd=100000000;
    int d;
    for(int i=0;i<n;i++){
        int dx=(x-ar[i][0])*(x-ar[i][0]);
        int dy=(y-ar[i][1])*(y-ar[i][1]);
        d=dx+dy;
        if(d<ansd){
            ansd=d;
            ans[0]=i;
            ansn=1;
        } else if(d==ansd){
            ans[ansn]=i;
            ansn++;
        }
    }
    for(int i=0;i<ansn;i++) printf("%d\n",ans[i]);
    return 0;
}
