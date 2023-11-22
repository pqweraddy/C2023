#include <stdio.h>
int main(){
    int xa,ya,ra,xb,yb,rb;
    scanf("%d%d%d%d%d%d",&xa,&ya,&ra,&xb,&yb,&rb);
    int x,y;
    ra=ra*ra;
    rb=rb*rb;
    while(scanf("%d%d",&x,&y)!=EOF){
        int dx1=(x-xa)*(x-xa);
        int dx2=(x-xb)*(x-xb);
        int dy1=(y-ya)*(y-ya);
        int dy2=(y-yb)*(y-yb);
        int d1=dx1+dy1;
        int d2=dx2+dy2;
        if(d1>ra&&d2>rb) printf("Out");
        else if (d1<ra||d2<rb) printf("In");
        else printf("On");
        printf("\n");
    }
    return 0;
}
