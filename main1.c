#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float func(float value,int n)//equation
{
    float function_output=pow(value,3)-n;
    return function_output; 
}
void secant(int number,int n,float approx1,float approx2)//parameters are number of iterations,first approx to be given,second approx to be given
{
    int i;
    float x0,x1,x2,y1,y0;
    float f,e;
    float real_value;
    x0=approx1;
    x1=approx2;
    real_value=pow(number,0.3333);//real root of x^3-n=0
    y0=func(x0,number);
    y1=func(x1,number);
    
    for(i=0;i<n;i++)//calculating using secant method
    {
        
        x2 = x1-((x1-x0)*y1/(y1-y0));//formula
        
        
        e=((x2-x1)/x2)*100;
        if(e<0)
        {
            e=e*-1;
        }
        printf("%f %f\n",x0,x1);
        printf("Estimate after iteration %d is %.9f\n",i+1,x2);
        printf("The error  of this value is %.9f\n",e);
        
        
        
        
        x0=x1;
        x1=x2;
        y0=y1;
        y1=func(x2,number);
        
    }
    
}
int main()
{
    int number,n;
    float x1,x0;
    printf("Enter the constant in the function ,number of iterations,first approximation/guess,second approximation/guess:\n");
    scanf("%d %d %f %f",&number,&n,&x0,&x1);
    secant(number,n,x0,x1);
    

}