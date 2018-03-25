#include <iostream>
#include <climits>

using namespace std; 

int min(int a, int b) {
    return b ^ ((a ^ b) & (-(a < b)));
}

bool is_possible(int *arr, int n, int students, int current_min) {
    int current_sum = 0, current_students = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > current_min)
            return false;

        if (arr[i] + current_sum > current_min) {
            current_students++;
            current_sum = arr[i];
            if (current_students > students)
                return false; 
        }
        else 
            current_sum += arr[i];
    }
    return true;
}

int pages_per_head(int *arr, int n, int students) {
    if (students <= 0 || n < students)
        return -1;

    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += arr[i];

    int start = 0, end = sum, result = INT_MAX; 
    for (int i = 0; i < n; i++) {
        int mid = (start + end) / 2;
        if (is_possible(arr, n, students, mid)) {
            result = min(result, mid);
            end = mid - 1;
        }
        else 
            start = mid + 1;
    }
    return result;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    int students;
    cin>>students;

    cout << pages_per_head(arr, n, students);
}
