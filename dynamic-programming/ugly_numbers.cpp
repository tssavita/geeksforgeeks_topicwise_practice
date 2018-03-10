#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

bool isUgly(int num, int remainder) {
    cout << num << " " << remainder << endl;
    if (num == 0)
        return false;
    else if (remainder != 0 && remainder!= INT_MAX) 
        return false;
    else if ((num == 2 || num == 3 || num == 5) && (remainder == 0))
        return true;
    else 
        isUgly(num/2, num%2) || isUgly(num/3, num%3) || isUgly(num/5, num%5);
}

int main(int argc, char ** argv) {
    int num; 
    cin>>num;

    cout << isUgly(num, INT_MAX);
}
