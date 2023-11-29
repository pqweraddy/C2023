#include <stdio.h>
#include "Turing_Machine.h"
void Turing_Machine(int *head, int K){
    int tpval,nx,st=0;
    while(K--){
        if(st==0){
            st=(*head%2?1:2);
            head++;
        } else if(st==1){
            (*head)++;
            (*head)%=4;
            if(*head%2==1){
                st=2;
                head--;
            } else {
                st=0;
                head++;
            }
        } else {
            (*head)+=2;
            (*head)%=4;
            if(*head==2) st=1;
            else if(*head==1) st=0;
            else if(*head==3) {
                head--;
                st=0;
            } else {
                head++;
                st=1;
            }
        }
    }
 
}
