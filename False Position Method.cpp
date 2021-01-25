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

//The False Position Method implementation
double false_position()
{
    double p,q,r,previous_root,new_root;
    //x1 and x2 are the initial guesses
    double x1 = maximum_abs_root, x2 = (-1)*maximum_abs_root;

    //Iteratively finding the right initial guesses from the maximum absolute root
    while(func(x1)*func(x2)>0)
    {
        x2=x2+0.5;
        x1=x1-0.5;
    }

    if(func(x1)*func(x2)>0)
    {
        cout<<endl<<"Initial guesses are wrong!"<<endl;
    }

    else
    {
        do
        {
            previous_root = new_root;
            new_root = x1-(func(x1)*(x2-x1))/(func(x2)-func(x1));

            if(func(new_root)==0.0)
                break;
            else if(func(x1)*func(new_root)<0)
                x2 = new_root;
            else
                x1 = new_root;
        }
        while(fabs(previous_root-new_root)>error);

        return new_root;
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

    double falsePosition_root = false_position();

    cout<<endl<<"The root found by the False Position Method is "<<setprecision(6)<<falsePosition_root<<endl;

}

