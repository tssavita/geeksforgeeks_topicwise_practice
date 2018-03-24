#include <iostream>
#include <climits>

using namespace std; 

void min_sum_digits(int sum, int digits) {

    sum -= 1;
    int result[digits], i = digits - 1;

    if (sum <= 0 || digits <= 0)
        return;

    if (sum > 9 * digits)
        return;

    while (i > 0) {
        if (sum > 9) {
            result[i] = 9;
            sum -= 9;
        }
        else {
            result[i] = sum;
            sum = 0;
        }
        i--;
    }

    result[0] = sum + 1;

    for (int i = 0; i < digits; i++)
        cout << result[i];
}

int main(int argc, char ** argv) {
    int sum, digits;
    cin>>sum>>digits;

    min_sum_digits(sum, digits);
}
