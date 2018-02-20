#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int t;
float func(float value,int n)//equation  func function will take t = 4
{
    float function_output=pow(value,3)-n;
    return function_output; 
    t=t+4;
}
void secant(int number,int n,float approx1,float approx2)//parameters are number of iterations,first approx to be given,second approx to be given
{                                                        // secant function will take t = 24n+17
    int i;
    float x0,x1,x2,y1,y0;
    float f,e;
    float real_value;
    x0=approx1;
    x1=approx2;  //t = 2 for assigning value in x0,x1
    real_value=pow(number,0.3333);//real root of x^3-n=0 and t = 2
    y0=func(x0,number);     // t -> 5
    y1=func(x1,number);     // t -> 5
    
    for(i=0;i<n;i++)//calculating using secant method  t=3   this loop take t= 3+ n(7+5+4+8) = 24n+3
    {
        
        x2 = x1-((x1-x0)*y1/(y1-y0));//formula   t=7
        
        
        e=((x2-x1)/x2)*100;     //t=5
        if(e<0)   // t=4
        {
            e=e*-1;
            t=t+4;
        }
        printf("%f %f\n",x0,x1);
        printf("Estimate after iteration %d is %.9f\n",i+1,x2);
        printf("The error  of this value is %.9f\n",e);
        
        
        
        
        x0=x1;
        x1=x2;
        y0=y1;
        y1=func(x2,number);
        t=t+8;
        
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
