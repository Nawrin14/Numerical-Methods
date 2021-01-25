#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){

    int n;
    double p, q, sum_x=0, sum_y=0, sum_xsqr=0, sum_xy=0, a, b;
    vector<double>x, y, x_sqr, xy;
    cout<<"Enter the number of data points: ";
    cin>>n;

    cout<<endl<<"Enter the independent variable values (x) : "<<endl;
    for(int i=0;i<n;i++){
        cin>>p;
        x.push_back(p);
    }

    cout<<endl<<"Enter the dependent variable values (y) : "<<endl;
    for(int i=0;i<n;i++){
        cin>>q;
        y.push_back(q);
    }

    for(int i=0;i<n;i++){
        x_sqr.push_back(pow(x[i],2));
        xy.push_back(x[i]*y[i]);
    }

    for(int i=0;i<n;i++){
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xsqr+=x_sqr[i];
        sum_xy+=xy[i];
    }

    b=(n*sum_xy-sum_x*sum_y)/(n*sum_xsqr-pow(sum_x,2));
    a=(sum_y-b*sum_x)/n;

    cout<<endl<<"x\t\t\ty\t\t\tx^2\t\t\txy"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;

    for(int i=0;i<n;i++){
        cout<<x[i]<<"\t\t\t"<<y[i]<<"\t\t\t"<<x_sqr[i]<<"\t\t\t"<<xy[i]<<endl;
    }

    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<sum_x<<"\t\t\t"<<sum_y<<"\t\t\t"<<sum_xsqr<<"\t\t\t"<<sum_xy<<endl;

    cout<<endl<<"The equation of the straight line is: "<<a<<"+"<<b<<"x"<<endl;
}
