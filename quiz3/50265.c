#include "calRectArea.h"
int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[]){
   int ar,ac,br,bc;
   int diffl,diffr;
   diffl=ptrLeft[0]-ptrMat;
   diffr=ptrRight[0]-ptrMat;
   //printf("%d %d\n",diffl,diffr);
   int lc=diffl%N;
   int lr=diffl/N;
   int rc=diffr%N;
   int rr=diffr/N;
   //printf("%d %d %d %d\n",lr,lc,rr,rc);
   int sum=(rc-lc+1)*(rr-lr+1);
   int nlr,nlc,nrr,nrc;
   for(int i=1;i<M;i++){
       diffl=ptrLeft[i]-ptrMat;
       diffr=ptrRight[i]-ptrMat;
       nlc=diffl%N;
       nlr=diffl/N;
       nrc=diffr%N;
       nrr=diffr/N;
       //printf("%d %d %d %d\n",nlc,nlr,nrc,nrr);
       sum+=(nrr-nlr+1)*(nrc-nlc+1);
       //printf("%d\n",(rr-nlr)*(rc-nlc));
       sum-=(rr-nlr+1)*(rc-nlc+1);
       rr=nrr;
       rc=nrc;
   }
   return sum;
}
