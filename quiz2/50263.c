#include "image2column.h"
void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH]){
    int col=0;
    for(int i=0;i<=h-k;i++){//original
        for(int j=0;j<=w-k;j++){
            int row=0;
            for(int x=i;x<i+k;x++){
                for(int y=j;y<j+k;y++){
                    colMatrix[row][col]=imgMatrix[x][y];
                    row++;
                }
            }
            col++;
        }
    }
    return;
}
