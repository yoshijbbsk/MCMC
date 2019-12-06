#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main (void)
{
    int i,j,k,v,m,l,L,p,q;
    double w,min,r,n,x,y,z;

    srand((unsigned)time(NULL));
    for (L = 12; L <=64 ; L=L+4) {
    for (p = 1; p <=12 ; p++) {

        z=(double)1.2+p*0.3/12;
    y=0;

    int a[L][L];
    for (q = 0; q < 10; q++) {
    x=0;
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

    for ( k = 1; k <= 10000; k++) {
        m=0;
        for (i  = 0;  i< L; i++) {
            for ( j = 0; j < L; j++) {

                v=a[i][j]*(a[(i+1)%L][j]+a[i][(j+1)%L]+a[i][(j+L-1)%L]+a[(i+L-1)%L][j]);

                    w=pow(z+1,-v);
                    if(w>1){min=1;}
                    else{min=w;}
                    r=(double)rand()/RAND_MAX;
                    if(r<=min){a[i][j]=-a[i][j];}


                m+=a[i][j];
                v=0;

            }
        }
        if (m<0) {m=-m;}
        n=(double)m/(L*L);
        if (k>1000)x+=n;

    }
    y+=x/9000;
    }
    printf("%f,",y/10 );
    }
    printf("\n");
}
    return 0;
}
