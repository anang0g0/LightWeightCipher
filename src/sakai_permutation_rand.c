#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 64
#define BIT_VERSION 0

typedef union {
	unsigned char x[N];
	unsigned int d[N/4];
	unsigned long long int u[N/8];
} arr;

void random_permutation(unsigned char* a){
	int i,j,x;
	for(i = 0; i < N; i++){
		a[i] = i;
	}
	for(i = 0; i < N - 2; i++){
		// rand from i+1 to N-1
		j = (rand() % (N-1-i)) + i + 1;

		// swap a[i] and a[j]
		x = a[j];
		a[j] = a[i];
		a[i] = x;
	}
	if(a[N-1] == N-1){
		a[N-1] = a[N-2];
		a[N-2] = N - 1;
	}
}

unsigned int toInt(unsigned char * a){
	unsigned int i = 0, s = 1, ret = 0;
	for(i=0; i < N; i++){
		ret += s * a[i];
		s *= 2;
		ret << 1;
	}
	return ret;
}

void keygen(arr a){
	unsigned char key[N]={0};
	int i;
	FILE *fp;

	for(i=0;i<32;i++)
	key[i]=a.x[i]^rand()%256;
	fp=fopen("sec.key","wb");
	fwrite(key,1,N,fp);
	fclose(fp);
}

arr p_rand(arr tt){
	static unsigned char a[N];
	FILE *fp;
	unsigned long long int u64=0;
	arr xx={0};


	/*{
		1,2,3,5,7,11,13,17,
		19,23,29,31,33,37,39,41,
		143,151,157,159,161,167,171,175,
		212,85,1,0,0,0,0,0,
	};
*/

	static unsigned char x[N];
	static unsigned char y[N];
	static unsigned char inv_x[N];
	static unsigned char first = 1;

	static unsigned char tmp[N];
	int i;

	if(first){
		first = 0;
		fp=fopen("sec.key","rb");
		fread(a,1,32,fp);
		fclose(fp);

		random_permutation(x);
		random_permutation(y);

		for(i=0;i<N;i++){
			inv_x[x[i]]=i; 
		}		
	}
	for(i=0;i<32;i++)
	a[i]^=tt.x[i];
	// a ^= a * y
	memcpy(tmp, a, sizeof(tmp)); 	// tmp = a;
	for(i=0;i<N;i++){ 
		a[i] ^= tmp[y[i]];
	}
	for(i=0;i<8;i++){
		xx.x[i]^=a[i];
	}

	// y = x * y * ~x
	for(i=0;i<N;i++) {
		tmp[i]=x[y[inv_x[i]]];
	}
	memcpy(y, tmp, sizeof(tmp));



	return xx; //toInt(a);
}

int main(int argc,char *argv[]){ 
	//FILE *fp = fopen("README.md","rb");
	FILE *fp = fopen(argv[1],"rb");
	FILE *op = fopen(argv[2],"wb");
	int i,j=0,c;
	unsigned char pass[32]={0};
	unsigned char buf[8]={0};
	char uu[32]={0};
	unsigned long long int ux=0;
	arr t={0};
	
	scanf("%s",&t.x);
	printf("%llu %llu\n",t.u[0],t.u[1]);

	srand(t.d[0]^t.d[1]|t.d[2]&t.d[3]);

	if(*argv[1]=='k'){
	keygen(t);
	exit(1);
	}
	while((c=fread(buf,1,8,fp))>0){
		
		arr a = p_rand(t);
		for(i=0;i<8;i++){
		buf[i]^=a.x[i]; //rand()%256;
		}

		//printf("%llu\n",a);
		//uu^=a;

		fwrite(buf,1,c,op);
/*
		if(op){
			fprintf(op, "%llu\n", uu);
		}else{
			printf("%llu\n", uu);
		}
*/
		j++; 
	} 


	return 0;
} 
