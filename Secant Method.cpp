#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double error, maximum_abs_root;
double a0,a1,a2,a3;

//returns the value of the polynomial for a certain x
double func(double x)
{

    return a3*pow(x,3)+a2*pow(x,2)+a1*x+a0;

}

//The Secant Method implementation
double secant()
{
    double x3;
    //x1 and x2 are the initial guesses
    double x1 = maximum_abs_root, x2 = (-1)*maximum_abs_root;

    do
    {
        x3 = (func(x2)*x1-func(x1)*x2)/(func(x2)-func(x1));

        x1=x2;
        x2=x3;

    }
    while(fabs((x2-x1)/x2)>error);

    return x3;

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

    double value = ((a2/a3)*(a2/a3))-(2*(a1/a3));
    maximum_abs_root = fabs(sqrt(value));

    double secant_root = secant();

    cout<<endl<<"The root found by the Secant Method is "<<setprecision(6)<<secant_root<<endl;
}

