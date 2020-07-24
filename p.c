#include <stdio.h>
#include <stdlib.h>
#include "sha3.c"


#define O 32
#define MAX 4

short x[5][O];
short t[256][O];
short W[O];

unsigned char X[O],X1[O];  

void mkcycle(){
  int i,j,r,rr,vv,pko,flg,flg2,l,n,ll,jj,flg3,cnt2,v,cnt3=0,ii;
  unsigned short cnt,k,count=0,kk,count2=0;;
  unsigned long long int o;
  unsigned char p[43]={/*2,*/3,5,7,/*11,13,*/17,19,/*23,*/29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,149,151,157,163,167,173,179,181,191,193};
  //{2,13,17};
  n=0;
  for(i=0;i<MAX;i++)
    n+=p[i];
  printf("%d\n",n);
  //   exit(1);

  scanf("%llu",&o);
  srand(o);

 a3:
  for(j=0;j<3;j++){
    
    cnt=0;
    
    count2=0;
    for(i=0;i<O;i++)
      x[j][i]=-1;
    

    printf("aa");
    cnt=0;
    pko=0;
    
    for(i=0;i<MAX;i++){
      count=0;
      flg=0;
      
      while(count<p[i]){
	
	printf("cx=%d %d\n",count,i);
	if(i==O){
	  cnt3=0;
	  for(ii=0;ii<O;ii++){
	    if(x[j][ii]==-1)
	      cnt3++;
	  }
	  printf("-1,%d\n%d",cnt3);
	  if(cnt3==0)
	    break;
	}
	
	if(count==0){
	  do {
	    kk=rand()%O;}while(x[j][kk]>=0);
	  
	  pko=kk;
	  printf("pko=%d\n",kk);
	  flg=1;
	}
	  	
	if(x[j][kk]==-1){
	  
	  do{
	    printf("aa");
	    flg2=0;
	    do{
	      printf("bb");
	    k=rand()%O;
	    }while(k==pko);
	    for(l=0;l<O;l++){
	      if(x[j][l]==k)
		flg2=1;
	    }
	    if(flg2==0 && kk!=k && x[j][kk]==-1)
	      x[j][kk]=k;
	    
	  }while(kk==k || flg2==1 || k==pko);
	} else {
	  do{
	    kk=rand()%O;
	    printf("cc");
	  }while(kk==pko);
	  
	  do{
	    flg2=0;
	      
	      k=rand()%O;
	    for(l=0;l<O;l++){
	      if(x[j][l]==k)
		flg2=1;
	    }
	    if(flg2==0 && kk!=k && x[j][kk]==-1 && k!=pko){
	      x[j][kk]=k;
	      count++;
	    }
	    if(count==p[i]-1)
	      break;
	    printf("ee");
	  }while(flg2==1 || kk==k || k==pko);
	  
	}
	
	
	
	  if(flg2==0 && kk!=k){
	    flg2=0;
	    if(x[j][kk]==-1){
	      for(l=0;l<O;l++){
		if(x[j][l]==k)
		  flg2=1;
	      }
	      if(flg2==0){
		x[j][kk]=k;
		count++;
	      }
	    }
	    while(x[j][kk]>-1)
	      kk=rand()%O;
	    if(k!=pko)
	    kk=k;
	    count++;
	    cnt++;
	  } else if(flg2==1 || kk==k) {
	    kk=rand()%O;

	    do{
	      flg2=0;
	      printf("ff");
	      k=rand()%O;
	      for(ll=0;ll<O;ll++){
		if(x[j][ll]==k)
		  flg2=1;
	      }while(flg2==1 ||k==pko || kk==k);
	      
	      if(flg2==0 && k!=pko && kk!=k){
		x[j][kk]=k;
		count++;
		kk=k;
	      }
	      
	    }while(flg2==1);
	  }
	  printf("loop=%d,%d\n",k,kk);
	  	 
	  if(count==p[i]-1 && pko!=kk){
	    flg2=0;
	    for(l=0;l<O;l++){
	      if(x[j][l]==pko)
		flg2=1;
	    }
	    if(flg2==0){
	    x[j][kk]=pko;
	    count++;
	    cnt++;
	    }
	  }
	  
      
      printf("count=%d\n",cnt);
      printf("i=%d\n",i);
      if(count-1==p[i]){
	x[j][k]=pko;
	cnt++;
	
      }
	printf("%d\n",cnt3);
      }
    }

    
  printf("cnt=%d\n",cnt);

  for(i=0;i<O;i++){
        if(x[j][i]==-1)
	  goto a3;
  }
  
  }
  
}



void random_permutation(unsigned char* a){
	int i,j,x;
	for(i = 0; i < O; i++){
		a[i] = i;
	}
	for(i = 0; i < O - 2; i++){
		j = (rand() % (O-1-i)) + i + 1;

		x = a[j];
		a[j] = a[i];
		a[i] = x;
	}
	if(a[O-1] == O-1){
		a[O-1] = a[O-2];
		a[O-2] = O - 1;
	}


}



int make_permutation(int num_primes, int perm[]){
  unsigned char p[33]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137};
  perm[0] = 1;
  perm[1] = 0;
  perm[2] = 3;
  perm[3] = 4;
  perm[4] = 2;
  perm[5] = 6;
  perm[6] = 7;
  perm[7] = 8;
  perm[8] = 9;
  perm[9] = 5;
  return 10;
}


void print_array(int len, int array[]){
  int i;
  printf("[");
  for(i = 0; i<len; i++){
    printf("%d,", array[i]);
  }
  printf("]\n");
}


void arr2mat(short m[O]){
  int i,j,k;
  short M[O][O]={0};

  for(i=0;i<O;i++)
    M[i][m[i]]=1;
}


void mat2arr(short M[O][O]){
  int i,j,k,count=0;
  short m[O];

  for(i=0;i<O;i++){
    for(j=0;j<O;j++){
      if(M[i][j]==1)
	m[i]=j;
    }
  }
    
}



void beki(unsigned long long int c){
  int i,j,k,count=0;
  short o[O];



  for(i=0;i<O;i++)
    W[i]=i;

      
    while(c>0){

      if(c%2==0){
	c= c>>1;
	count++;
      } else {
	for(i=0;i<O;i++)
	  o[i]=W[t[count][i]];
	for(i=0;i<O;i++)
	  W[i]=o[i];
	c= c>>1;
	count++;
      }
    }

}



void chickle(){
  int i,j,k,flg=0;

  for(i=0;i<3;i++){
    for(j=0;j<O;j++){
      k=x[i][j];
      if(k!=j)
	printf("(");
      printf("%d,",x[i][j]);
      if(k==j)
	printf(")\n");
    }
      
  }
}


void table(short a[O]){
  int i,j,count=0,count2=0;
  short w[O],v[O],e[O],m[O],s[O];

    
    for(i=0;i<O;i++){
      v[i]=i;
      e[i]=i;
      
    }
    for(i=0;i<O;i++){
    t[0][i]=v[i];
    t[1][i]=v[a[i]];
    w[i]=x[0][i];
    s[i]=x[1][i];
    m[i]=x[2][i];
    }
    printf("\n");
    count=2;
    i=0;
    while(count<256){
      
      for(i=0;i<O;i++){
      v[i]=w[a[i]];
      }
      

      for(i=0;i<O;i++)
	a[i]=v[i];
      for(i=0;i<O;i++)
	t[count][i]=v[i];
      count++;
    }
}


void print_perm(){
  int i;

  
  mkcycle();
  //random_permutation(X);
  //random_permutation(X1);
  for(i=0;i<O;i++){
    X[i]=x[0][i];
    X1[i]=x[1][i];
  }
  
  for(i=0;i<O;i++)
    printf("%d,",X[i]);
  printf("\n");
  for(i=0;i<O;i++)
    printf("%d,",X1[i]);
  printf("\n");


}



/*
void main(){
  unsigned char inv_X[O],A[O],X[O],tmp[O],X1[O],X2[O];
  int i,j;
  short B[O],C[O],C1[O],C2[O],CC[O],C3[O],C4[O],Z[O],D[O];
  unsigned long long int a,b,r,a2;
  
  mkcycle();
  //random_permutation(X);
  //random_permutation(X1);
  for(i=0;i<64;i++){
    X[i]=x[0][i];
    X1[i]=x[1][i];
  }
  
  for(i=0;i<O;i++)
    printf("%d,",X[i]);
  printf("\n");
  for(i=0;i<O;i++)
    printf("%d,",X1[i]);
  printf("\n");
  
  exit(1);
  
  
  for(i=0;i<O;i++)
    inv_X[x[0][i]]=i;
  
  for(i=0;i<O;i++){
    A[i]=x[0][i];
    B[i]=x[1][i];
    C[x[0][i]]=i;
    D[i]=x[2][i];
  }
  
  srand(clock());
  printf("\n");
  //  exit(1);
  for(i=0;i<O;i++){
    W[i]=A[B[C[i]]];
    Z[i]=A[D[C[i]]];
  }
  printf("koukaikagi:\n");
  for(i=0;i<O;i++)
    printf("%d,",W[i]);
  printf("\n");
  
  
  a=rand()%O;
 
  table(W);
  beki(a);
  printf("\nkotae=\n");
  for(i=0;i<O;i++)
    printf("%d,",W[i]);
  printf("\n");
  return;
  
}
*/

