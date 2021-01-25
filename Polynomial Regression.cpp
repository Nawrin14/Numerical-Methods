#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){

    int p,n;
    double x[100],y[100];
    cout<<"Enter the number of data points: ";
    cin>>p;

    cout<<"Enter the independent variable values (x): ";
    for(int i=0;i<p;i++)
        cin>>x[i];

    cout<<"Enter the dependent variable values (y): ";
    for(int i=0;i<p;i++)
        cin>>y[i];

    cout<<"Enter the degree of polynomial: ";
    cin>>n;

    double x_values[2*n+1];
    for(int i=0;i<2*n+1;i++){
        x_values[i]=0;
        for(int j=0;j<p;j++)
            x_values[i]+=pow(x[j],i);
    }

    double y_values[n+1];
    for(int i=0;i<n+1;i++){
        y_values[i]=0;
        for(int j=0;j<p;j++)
            y_values[i]+=pow(x[j],i)*y[j];
    }

    double matrix[n+1][n+2], coeff[n+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            matrix[i][j]=x_values[i+j];
        }
        matrix[i][n+1]=y_values[i];
    }

    n++;
    cout<<endl<<"The equations are: "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++)
            cout<<matrix[i][j]<<"\t\t";

        cout<<endl<<endl;
    }

    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            double a=matrix[k][i]/matrix[i][i];

            for(int j=0;j<=n;j++){
                matrix[k][j]-=a*matrix[i][j];
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        coeff[i]=matrix[i][n];
        for(int j=0;j<n;j++){
            if(j!=i)
                coeff[i]-=matrix[i][j]*coeff[j];
        }
        coeff[i]/=matrix[i][i];
    }

    cout<<"The polynomial regression equation is: ";

    for(int i=0;i<n;i++){
        cout<<coeff[i]<<"x^"<<i;
        if(i!=n-1)
            cout<<"+";
    }

    cout<<endl;
}
