#include <iostream>

using namespace std;

void smallest_num(int digi_sum, int digi_num) {
    if (digi_sum == 0) {
        (digi_num == 0) ? cout << 0 : cout << "Not possible";
    }

    if (digi_sum > digi_num * 9) {
        cout << "Not possible";
    }

    int result[digi_num];
    digi_sum -= 1;
    for (int i = digi_num - 1; i > 0; i--) {
        if (digi_sum > 9) {
            result[i] = 9;
            digi_sum -= 9;
        }
        else {
            result[i] = digi_sum; 
            digi_sum -= digi_sum;
        }
    }

    result[0] = digi_sum + 1;

    for (int i = 0; i < digi_num; i++)
        cout << result[i];
    cout << endl;
}

int main(int argc, char ** argv) {
    int digi_sum;
    int digi_num;
    cin>>digi_sum;
    cin>>digi_num;
    smallest_num(digi_sum, digi_num);
}
