#include <iostream>
#include <climits>

using namespace std;

int max(int a, int b) {
    return a ^ ((a ^ b) & -(a < b));
}

int eggdropping(int eggs, int floors) {
    if (floors == 1 || floors == 0) 
        return floors;
    if (eggs == 1)
        return floors;

    int min_k_floor_droppings = INT_MAX, res;
    for (int i = 1; i <= floors; i++) {
        res = max(eggdropping(eggs - 1, i - 1), eggdropping(eggs, floors - i));
        if (res < min_k_floor_droppings)
            min_k_floor_droppings = res;
    }
    return min_k_floor_droppings + 1;
}

int main(int argc, char ** argv) {
    int eggs; 
    cin>>eggs;

    int floors;
    cin>>floors;

    cout << eggdropping(eggs, floors);
}
