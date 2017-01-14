#include <iostream>
#include <math.h>

using namespace std;

const int N=10;
const double eps=0.00000001;

double eval(double x, const double *c) {
    return c[0] * sin(c[1] * x + c[2]) + c[3] * exp(c[4] * x + c[5]) + c[6] * fabs(c[7] * x + c[8]) + c[9];
}

double binSearch(const double p, const double q, const double *coefficients) {
    double left = p;
    double right = q;
    double middle = 0;
    while (fabs(right - left) > eps) {
        double leftValue = eval(left, coefficients);
        middle = (left + right) / 2.0;
        double exprValue = eval(middle, coefficients);
        if (exprValue == 0) {
            break;
        } else if (leftValue * exprValue <= 0) {
            right = middle;
        } else {
            left = middle;
        }
    }
    return middle;
}

int main() {
    cout.precision(8);
    cout.setf(ios::fixed);
    double p, q;
    double coefficients[N];
    cin >> p >> q;
    for (int i = 0; i < N; i++) {
        cin >> coefficients[i];
    }
    cout << binSearch(p, q, coefficients)<< endl;
    return 0;
}
