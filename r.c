#include <stdio.h>
#include <string.h>


int main(){
  int i,j,k;
  unsigned char z[32]={0},inv[32]={0};;
  
static unsigned char  y0[32]={27,24,23,6,18,12,11,14,4,5,2,29,22,1,3,17,15,21,31,26,19,30,0,8,28,7,20,13,10,25,16,9};
  
unsigned char y1[32]={20,7,26,9,6,12,8,16,15,22,23,17,29,25,10,24,30,28,27,31,18,13,19,14,4,1,3,11,0,2,5,21};

  for(i=0;i<32;i++)
    inv[y0[i]]=i;

  while(1){
  for(i=0;i<32;i++)
    z[i]=y0[y1[inv[i]]];
  memcpy(y1,z,sizeof(unsigned char)*32);
  
  for(i=0;i<32;i++)
    printf("%d,",z[i]);
  printf("\n");
  }

  return 0;
}
