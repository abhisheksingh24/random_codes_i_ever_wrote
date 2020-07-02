#include<bits/stdc++.h>

using namespace std;

//returns the value of functio=n at x
double f(double x) { 
    return 0.4 * sqrt(x) + 0.06 * cbrt(x * x) -  60.5; 
} 
  
// Derivative of the above function 
double df(double x) { 
    return 0.2 / sqrt(x) + 0.04 / cbrt(x); 
} 
  
// Netwon Raphson method to find the root 
double newtonRaphson(double x, int* iter, double EPSILON) { 
    double h, error; 
    while (true) {
        error = abs(f(x));
        if(error <= EPSILON) break; 
        h = f(x) / df(x); 
        // x(i+1) = x(i) - f(x) / f'(x)   
        x = x - h; 
        (*iter)++;
    } 
  
    return x;
}

int main(){
    int iter = 0;
    const double EPSILON = 0.000001;
    double initialGuess = 1;
    double x = newtonRaphson(initialGuess, &iter, EPSILON);
    cout << "Root = " << x << endl;
    cout << "Maximum error = " << EPSILON << endl;
    cout << "It took " << iter << " iterations" << endl;
}