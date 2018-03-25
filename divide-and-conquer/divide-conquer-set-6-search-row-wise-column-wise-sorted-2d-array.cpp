#include <iostream>

using namespace std; 

class mat_xy {
    public:
        int x;
        int y;
        mat_xy(): x(-1), y(-1) {}
};

mat_xy search(int **matrix, int find, int rstart, int rend, int cstart, int cend) {
    int rmid = rstart + (rend - rstart) / 2; 
    int cmid = cstart + (cend - cstart) / 2;

    mat_xy xy; 

    if (matrix[rmid][cmid] == find) {
        xy.x = rmid;
        xy.y = cmid;
        return xy;
    }
    else {
        if (rmid != rend || cmid != cstart) 
            search(matrix, find, rstart, rmid, cmid, cend);

        if (rstart == rend && (cstart + 1 == cend)) {
            if (matrix[rstart][cend] == find) {
                xy.x = rstart;
                xy.y = cend;
                return xy;
            }
        }

        if (matrix[rmid][cmid] < find) {
            if ((rmid + 1) <= rend)
                search(matrix, find, rmid + 1, rend, cstart, cend);
        }
        else {
            if ((cmid - 1) >= cstart)
                search(matrix, find, rstart, rend, cstart, cmid - 1);
        }
    }
}

int main(int argc, char ** argv) {
    int rows;
    int columns;
    cin>>rows>>columns;

    int **matrix = new int*[rows];
    for (int i = 0; i < columns; i++) {
        matrix[i] = new int[columns];
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin>>matrix[i][j];


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    int find;
    cout << "Enter element to be searched";
    cin>>find;

    mat_xy xy = search(matrix, find, 0, rows, 0, columns);
    cout << xy.x << " " << xy.y;
}
