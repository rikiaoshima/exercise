#include<stdio.h>
#include<math.h>

int flag[10000]={0};

long pow2(int base,int exp){
        int i;
        long ans;

        ans = 1;

        for(i=0;i<exp;i++){
                ans =ans * base;
        }

        return ans;
}


int exponent1(int e,int G){
        int j,max_ex=0;

        for(j=1;j<=sqrt(G);j++){
                if( G % pow2(e,j) != 0){
                        break;
                }
                max_ex=j;
        }
        return max_ex;
}

void times(int k){
        int i;

        for(i=2;i*k<10000;i++){
                flag[i*k]=1;
        }
}


int compute(int p[],int e[],int l,int g,long G){
        int i,f,j,exp=1;

        int temp=1;
        long sum_g=1;

        for(f=1;f<=G;f++){

                e[l]=e[l]-f;

                for(i=0;p[i]!='\0';i++){
                        exp*=pow2(p[i],e[i]);
                }

                sum_g=pow2(g,exp);
                e[l]+=f;
                exp=1;

                if(sum_g%(G+1)!=1){
                        return f-1;
                }
                
        }

        return f-1;
}


int main(void){
        int g,i,j=0;
        long G;
        int e[10000],prime[10000];

        printf("g:");
        scanf("%d",&g);
        printf("mod G:");
        scanf("%ld",&G);

        G=G-1;

        for(i=2;i<G;i++){
                if(G%i==0){
                        if(flag[i]==0){
                               
                                prime[j]=i;
                                e[j]=exponent1(i,G);
                                printf("%d個目(素数,指数):(%d,%d)\n",j+1,prime[j],e[j]);
                                times(i);
                                j++;

                        }
                }
        }
        int l,count[10000],order_g=1,temp[100],exp_2=1;


        for(l=0;prime[l]!='\0';l++){
                count[l]=compute(prime,e,l,g,G);

                temp[l]=e[l]-count[l];

        }
        for(l=0;prime[l]!='\0';l++){
                order_g*=pow2(prime[l],temp[l]);
        }

        if(prime[0]=='\0'){
                printf("order_g: %ld\n",G);
                return 0;
        }

        printf("order_g: %d\n",order_g);

        return 0;
}
