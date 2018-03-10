#include <iostream>
#include <climits>
#include <cstdio>
#include <cstdlib>

using namespace std;

int ugly_numbers(int n) {
    int ugly_num[n+1];

    for (int i = 0; i <= n; i++)
        ugly_num[i] = 0;

    int div[3] = {2, 3, 5};
    for (int i = 0; i <= n; i++) {
        if (i == 0)
            ugly_num[0] = 0;
        else if ((i == 1) || (i == 2) || (i == 3) || (i == 5)) 
            ugly_num[i] = 1;
        else {
            for (int j = 0; j < 3; j++) {
                if (i % div[j] == 0)
                    ugly_num[i] |= ugly_num[i/div[j]];
                    if (ugly_num[i])
                        break;
            }
        }
        cout << i << " " << ugly_num[i] << endl;
    }
    return ugly_num[n];
}

int main(int argc, char ** argv) {
    int num;
    cin>>num;

    cout << ugly_numbers(num);
}
