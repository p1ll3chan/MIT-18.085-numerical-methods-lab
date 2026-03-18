#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 100;

    vector<double> c(n+2);
    vector<double> f(n+1);

    vector<double> a(n+1), b(n+1), d(n+1);

    // stiffness
    for(int i=1;i<=101;i++)
        c[i] = 1;

    // force
    for(int i=1;i<=n;i++)
        f[i] = 0.1;

    // build matrix
    for(int i=1;i<=n;i++){

        a[i] = -c[i];
        b[i] = c[i] + c[i+1];
        d[i] = -c[i+1];
    }

    // Thomas Algorithum is the fastest method of sovling tridiagonal matrix.
    // A special optima version of Gaussian elimination.\
    // Thomas Algorithum => Forward Elimiantion + Backward Substitution

    // forward elimination
    for(int i=2;i<=n;i++){
        double m = a[i] / b[i-1];  // Eleimatin of X1 from the equation 2
        b[i] -= m * d[i-1];   // Subtract that value from the equation 1
        f[i] -= m * f[i-1];   // Update the force vector along with int
    }

    // Backward Substitution 
    vector<double> x(n+1);

    x[n] = f[n] / b[n];

    for(int i=n-1;i>=1;i--)
        x[i] = (f[i] - d[i]*x[i+1]) / b[i];   // intially a[i]=0 & b[i]*x[i] + d[i]*x[i+1] = f[i]

    for(int i=1;i<=n;i++)
        cout << i << " " << x[i] << endl;
}

// Pending Work
/* 
    We still haven't made the solution output for those 4 Cases !
*/
//Doubts

/*
    * How is the code line -> 41 - 49 works
    * What is the reverse loop in use here for the Back Substitution
*/