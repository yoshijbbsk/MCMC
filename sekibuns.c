#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x);
double q(double x);

int main (void)
{
    int a =0;
    int b =1;
    double h,x,E;

    for (int n =5; n <= 50000; n=n*10) {
        E=0;
        h= (double)(b-a)/(2*n);
        x=h*(f(1)+f(0)+4*f(h))/3;
        printf("%d\n", 2*n);
        for (int i = 1; i <= n-1; i++) {
            x += h*(2*f(2*i*h)+4*f((2*i+1)*h))/3;
            E += fabs(pow(h,5)*q(2*i*h)/90);
        }
            printf("値は%.10f\n誤差は%e\n", x,M_PI-x);
        }
}

double f(double x)
{
    double t;
    t=4/(1+pow(x,2.0));
    return t;
}

double q(double x)
{
    double t;
    t=-96*x*(x*x-1)/pow(x*x+1,4);
    return t;
}
