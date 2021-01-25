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

//The Bisection Method implementation
double bisection()
{
    double root;
    //a and b are the initial guesses
    double a = maximum_abs_root, b = (-1)*maximum_abs_root;

    //Iteratively finding the right initial guesses from the maximum absolute root
    while(func(a)*func(b)>0)
    {
        b=b+0.5;
        a=a-0.5;
    }

    if(func(a)*func(b)>0)
    {
        cout<<endl<<"Initial guesses are wrong!"<<endl;
    }

    else
    {
        do
        {
            root = (a+b)/2;
            if(func(root)==0.0)
                break;
            else if(func(a)*func(root)<0)
                b = root;
            else
                a = root;
        }
        while(fabs((b-a)/b)>error);

        return root;
    }
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

    double bisection_root = bisection();

    cout<<endl<<"The root found by the Bisection Method is "<<setprecision(6)<<bisection_root<<endl;

}
