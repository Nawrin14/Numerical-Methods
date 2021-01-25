#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double error, largest_possible_root;
double a0,a1,a2,a3;

//returns the value of the polynomial for a certain x
double func(double x)
{

    return a3*pow(x,3)+a2*pow(x,2)+a1*x+a0;

}

//returns the differential of the polynomial for a certain x
double func_differentiation(double x)
{

    return 3*a3*x*x+2*a2*x+a1;

}

//The Newton-Raphson Method implementation
double Newton_Raphson()
{
    double x0;
    //x1 is the initial guess
    double x1 = largest_possible_root;

    do
    {
        x0 = x1;
        x1 = x0-(func(x0)/func_differentiation(x0));
    }
    while(fabs((x1-x0)/x1)>error);

    return x1;

}

int main()
{
    //The equation is a 3rd degree polynomial of the form a3*x^3+a2*x^2+a1*x+a0 = 0
    cout<<"Enter the coefficients:"<<endl;
    cout<<"a0 : ";
    cin>>a0;
    cout<<"a1 : ";
    cin>>a1;
    cout<<"a2 : ";
    cin>>a2;
    cout<<"a3 : ";
    cin>>a3;

    //The result is correct till 5 significant digits
    error = 0.5*pow(10, 2-5);

    largest_possible_root = -(a2/a3);

    double NewtonRaphson_root = Newton_Raphson();

    cout<<endl<<"The root found by the Newton Raphson Method is "<<setprecision(6)<<NewtonRaphson_root<<endl;

}
