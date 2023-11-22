#include<stdio.h>
#include<stdlib.h>
 
//int printarr(int ar[200][200],int n,int m){
 
//}
 
 
 
int main() {
    int n,m,l,w;
    scanf("%d%d%d%d",&n,&m,&l,&w);
    int ar[200][200]={0};
    int ec[l][w];
    int x,y;
    scanf("%d%d",&y,&x);
    int s,k;
    scanf("%d%d",&s,&k);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
                scanf("%d",&ar[i][j]);
        }
    }
    int nx,ny;
    //printarr(ar,n,m);
    int from;
    int dx,dy;
    int tmp[200][200];
    for(int t=0;t<=k;t++){
        nx=x-(t*s);
        ny=y-(t*s);
        int tx=nx+l-1;
        int ty=ny+w-1;
        //printf("%d,%d,%d,%d\n",nx,tx,ny,ty);
        if(tx<0&&ty<0) return 0;
        if(((nx<0&&tx<0)||(tx>=n&&nx>=n)||(ny<0&&ty<0))||(ny>=m&&ty>=m)) continue;
        else {
            int xfrom=(nx>=0?nx:0);
            int xto=(tx<=n-1?tx:n-1);
 
            int yfrom=(ny>=0?ny:0);
            int yto=(ty<=m-1?ty:m-1);
 
            //printf("y");
            for(int i=xfrom;i<=xto;i++){
                for(int j=yfrom;j<=yto;j++){
                    ec[i-xfrom][j-yfrom]=ar[i][j];
                    ar[i][j]=0;
                }
            }
            for(int i=n-1;i>=0;i--){
                printf("%d",ar[i][0]);
                for(int j=1;j<m;j++) printf(" %d",ar[i][j]);
                printf("\n");
            }
            printf("\n");
            for(int i=xfrom;i<=xto;i++){
                for(int j=yfrom;j<=yto;j++){
                    ar[i][j]=ec[i-xfrom][j-yfrom];
                }
            }
        }
    }
    return 0;
}
