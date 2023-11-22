#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a=0;
    int x,y,w,h;
    scanf("%d%d%d%d",&x,&y,&w,&h);
    a+=h*w;
    for(int i=0;i<n-1;i++){
        int xu=x+w;
        int yu=y+h;
        scanf("%d%d%d%d",&x,&y,&w,&h);
        a+=h*w;
        int nw=x-xu;
        int nh=y-yu;
        a-=nw*nh;
    }
    printf("%d",a);
    return 0;
}
