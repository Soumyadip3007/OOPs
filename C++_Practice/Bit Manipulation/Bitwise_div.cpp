#include <iostream>
using namespace std;

int bitwiseDivide(int dividend, int divisor) {
    if (divisor == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }

    int quotient = 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    while (dividend >= divisor) {
        int tempDivisor = divisor, multiple = 1;
        while (dividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            multiple <<= 1;
        }
        dividend -= tempDivisor;
        quotient += multiple;
    }

    return sign * quotient;
}

int main() {
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    try {
        int result = bitwiseDivide(dividend, divisor);
        cout << "Quotient: " << result << endl;
    } catch (const exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}