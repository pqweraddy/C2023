#include "count_collision.h"
void count_collision(int *ptr[], int A[], int n, int a, int b, int c){
    int f;
    for(int i=0;i<c;i++) A[i]=0;
    for(int i=0;i<n;i++){
        f=((a*i)+b)%c;
        ptr[i]=&A[f];
        A[f]++;
    }
    for(int i=0;i<c;i++){
        if(A[i]!=0)A[i]--;
    }
}
