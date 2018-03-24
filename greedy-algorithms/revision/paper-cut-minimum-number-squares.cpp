#include <iostream>

using namespace std;

int max_squares_paper_cut(int length, int breadth) {
    if (breadth <= 0)
        return 0;
    return length / breadth + max_squares_paper_cut(breadth, length % breadth);
}

int main(int argc, char ** argv) {
    int length, breadth;
    cin>>length>>breadth;

    cout << max_squares_paper_cut(length, breadth);
}
