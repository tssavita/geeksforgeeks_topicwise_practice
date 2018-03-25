#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char ** argv) { 
    int n;
    cin>>n;
    unsigned char *pData;
    pData = (unsigned char *)&n;

    cout << (int)pData[0] << " " << (int)pData[1] << " " << (int)pData[2] << " " << (int)pData[3] << endl;
}
