#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define L 64


int main (void)
{
    int i,j,k,v,m,l;
    double w,min,r,n;
    FILE *fout,*fout2;
    fout = fopen("output1.txt", "w");
    fout2 = fopen("output2.txt", "w");
    srand((unsigned)time(NULL));

    int a[L][L];
    for (l = 0; l <=1; l++) {

    m=0;
    v=0;
    w=0;
    for (i = 0;  i< L; i++) {
        for ( j = 0; j < L; j++) {
            a[i][j]=1;
            m+= a[i][j];
        }
    }
    n=(double)m/(L*L);
    if(l==0)fprintf(fout,"0 %f\n",n );
    if(l==1)fprintf(fout2,"0 %f\n",n );

    /*出力m*/

    for ( k = 1; k <= 1000; k++) {
        m=0;
        for (i  = 0;  i< L; i++) {
            for ( j = 0; j < L; j++) {

                v=a[i][j]*(a[(i+1)%L][j]+a[i][(j+1)%L]+a[i][(j+63)%L]+a[(i+63)%L][j]);
                if(l ==0){
                    /*メトロポリス法*/
                    w=pow(sqrt(2)+1,-v);
                    if(w>1){min=1;}
                    else{min=w;}
                    r=(double)rand()/RAND_MAX;
                    if(r<=min){a[i][j]=-a[i][j];}
                }
                /*熱浴法*/
                if(l ==1){
                    w=1/(pow(sqrt(2)+1,v)+1);
                    if(w>1){min=1;}
                    else{min=w;}
                    r=(double)rand()/RAND_MAX;
                    if(r<=min){a[i][j]=-a[i][j];}
                }
                m+=a[i][j];
                v=0;

            }
        }
        if (m<0) {m=-m;}
        n=(double)m/(L*L);
        /*M出力*/
        if(l==0)fprintf(fout, "%d %f\n",k,n );
        if(l==1)fprintf(fout2, "%d %f\n",k,n );
    }
    if(l==0)fclose(fout);
    if(l==1)fclose(fout2);
    }
    return 0;
}
