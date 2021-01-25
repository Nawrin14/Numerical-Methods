#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double x[100],y[100][100],x_unknown,y_unknown=0,sum;
    cout<<"Enter the number of data points: ";
        cin>>n;
    cout<<endl<<"Enter the x values: "<<endl;
    for(int i=0; i<n; i++)
        cin>>x[i];
    cout<<endl<<"Enter the f(x) values: "<<endl;
    for(int i=0; i<n; i++)
        cin>>y[i][0];

    cout<<endl<<"Enter x for the unknown value: "<<endl;
    cin>>x_unknown;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)

            y[j][i]=(y[j+1][i-1]-y[j][i-1])/(x[i+j]-x[j]);
    }

    cout<<endl<<"The divide difference table is: "<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
            cout<<y[i][j]<<"\t\t";

        cout<<endl;
    }

    y_unknown=y[0][0];
    for(int i=1; i<n; i++)
    {
        sum=1;
        for(int j=0; j<i; j++)
        {
            sum*=x_unknown-x[j];
        }
        y_unknown+=sum*y[0][i];
    }

    cout<<endl<<"f(x) = "<<y_unknown<<" for x = "<<x_unknown<<endl;

}
