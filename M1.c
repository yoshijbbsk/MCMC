#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double f(double x);

int main (void)
{
    int a,k,l,n;
    double x,y[10],all[4],dis[4];
    a=10;
    for (l= 0;  l<4; l++) {
    all[l]=0;
    dis[l]=0;
    srand((unsigned)time(NULL));

    for (k =0; k < 10; k++) {

        y[k]=0;

        for (n = 0; n < a; n++) {
        x= (double)rand()/RAND_MAX;
        y[k] += f(x);
        }
        y[k] =y[k]/a;

    }
    for (k = 0;  k< 10; k++) {
    all[l] += y[k]/10;
    dis[l] += sqrt((y[k]-all[l])*(y[k]-all[l])/(9*10));
    }
    printf("サンプル数%dの時\n推定値%f、精度%f\n",a,all[l],dis[l]);
    printf("%f\n",pow(dis[l],2)*90 );
    a = a*100;
    }
}

double f(double x)
{
    double t;
    t=4/(1+pow(x,2.0));
    return t;
}
