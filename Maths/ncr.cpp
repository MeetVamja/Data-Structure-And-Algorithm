#include <iostream>
#include <cmath>
using namespace std;

// Calculates the binomial coefficient nCr using logarithmic formula
int nCr(int n, int r) {
    // Invalid case
    if (r > n) return 0;  
    // Base cases
    if (r == 0 || n == r) return 1;    

    double res = 0;
    for (int i = 0; i < r; i++) {
        // log(n!) - log(r!) - log((n-r)!)
        res += log(n - i) - log(i + 1);  
    }

    return (int)round(exp(res));
}

int main() {
    int n = 5;
    int r = 2;
    cout << nCr(n, r) << endl; 
    return 0;
}
