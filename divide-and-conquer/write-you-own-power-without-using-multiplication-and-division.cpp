#include <iostream>

using namespace std;

int raise(int base, int power) {
    if (power == 0)
        return 1;

    int answer = base;
    int increment = base;
    for (int i = 1; i < power; i++) {
        for (int j = 1; j < base; j++) {
            answer += increment;
        }
        increment = answer;
    }

    return answer;
}

int main(int argc, char ** argv) {
    int base;
    cin>>base;
    
    int power;
    cin>>power;

    cout << raise(base, power);
}
