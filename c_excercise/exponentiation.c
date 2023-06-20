#include<stdio.h>

long pow1(long base,long exponent){
	long basic=base;
	for(int i=1;i<exponent;i++){
		base=base*basic;
	}
	printf("%ld\n",base);
	printf("count_pow:%ld\n",exponent-1);
}


long main(void){
	long long i,base,exponent,result=1,count=0;;
	scanf("%lld %lld",&base,&exponent);

	pow1(base,exponent);

	while(exponent>0){
		if(exponent%2==1){
			result = result*base;
		}
		base=base*base;
		exponent=exponent/2;
		count++;
	}

	printf("%lld\n",result);
	printf("count:%lld\n",count);
	return 0;
}

