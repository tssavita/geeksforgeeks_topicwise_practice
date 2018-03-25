#include <iostream>
#include <cstdio>

// Source - https://www.geeksforgeeks.org/program-to-count-number-of-set-bits-in-an-big-array/

#define SIZE (1 << 16)

#define GROUPA(x) x, x + 1, x + 1, x + 2
#define GROUPB(x) GROUPA(x), GROUPA(x + 1), GROUPA(x + 1), GROUPA(x + 2)
#define GROUPC(x) GROUPB(x), GROUPB(x + 1), GROUPB(x + 1), GROUPB(x + 2)
#define META_LOOKUP(PARAMETER) \
    GROUP_##PARAMETER(0), \
    GROUP_##PARAMETER(1), \
    GROUP_##PARAMETER(1), \
    GROUP_##PARAMETER(2)  \

using namespace std; 

int num_bits_set(int *arr, int arr_size) {
    int count = 0;
    static unsigned char const lookup[] = { META_LOOKUP(C) };

    unsigned char *pdata = NULL;

    for (int i = 0; i < arr_size; i++) {
        pdata = (unsigned char *)&arr[i];

        count += lookup[pdata[0]];
        count += lookup[pdata[1]];
        count += lookup[pdata[2]];
        count += lookup[pdata[3]];
    }

    return count;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % SIZE;
    }

    cout << num_bits_set(arr, SIZE);
}
