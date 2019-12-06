#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x);
double g(double x);

int main (void)
{
    int a =0;
    int b =1;
    double h,x,E;

    for (int n =10; n <= 100000; n=n*10) {
        x=0;
        E=0;
        h= (double)(b-a)/n;
        printf("n=%dの時\n", n);
        for (int i = 0; i <= n-1; i++) {
            x += h*(f(i*h)+f((i+1)*h))/2;
            E += fabs(pow(h,3)*g(i*h)/12);
        }
            printf("値は%.10f\n誤差は%e\n誤差の予想は%e\n", x,M_PI-x,E );
        }
}

double f(double x)
{
    double t;
    t=4/(1+pow(x,2.0));
    return t;
}
double g(double x)
{
    double t;
    t=(24*x*x-8)/pow(x*x+1,3);
    return t;
}
