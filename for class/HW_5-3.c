#include <stdio.h>
#include <math.h>

//簡化分數(找最大公因數除掉分數)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int i,n;
    double PI =3.14159265358979323846;
    printf("n = ");
    scanf("%d",&n);

    //求X*PI
    for(i=0;i<=n*2;i++)
    {
        double x = i*1.0/n*PI;

        //化簡分數
        int Irreducible_fraction_num=gcd(i,n); //化簡基準
        int numerator = i/Irreducible_fraction_num;//化簡分子
        int denominator = n/Irreducible_fraction_num;//化簡分母

        if(numerator==0)
        {
            printf("x = 0 PI, sin(x) = %f, cos(x) = %f\n",sin(x),cos(x));
        }
        else if(numerator%denominator==0)
        {
            printf("x = %d PI, sin(x) = %f, cos(x) = %f\n",numerator/denominator,sin(x),cos(x));
        }
        else
        {
            printf("x = %d/%d PI, sin(x) = %f, cos(x) = %f\n",numerator,denominator,sin(x),cos(x));
        }
    }
    return 0;
}
