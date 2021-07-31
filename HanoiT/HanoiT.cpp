#include <stdio.h>
#include <iostream>
#include <vector>
//#include <QtGui>
#include <QObject>
#include <QString>

using namespace std;

//vector<int>
struct tah {
    int from;
    int to;
};






void print(vector<vector<int>> matrix) {
    for (int j = 0; j < matrix[0].size(); j++)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool solved(vector<vector<int>> matrix) { //vyhodnotí, jestli je řešení konečné, vrací 0 nebo 1
    int i = 0;
    while (matrix[2][i] == i + 1 && i < matrix[0].size()) {
        i++;
    }
    if (i == matrix[0].size()) {
        return true;
    }
    else {
        return false;
    }
}

bool start(vector<vector<int>> matrix) { //vyhodnotí, jestli jsou věže v původním postavení
    int i = 0;
    while (matrix[0][i] == i + 1 && i < matrix[0].size()) {
        i++;
    }
    if (i == matrix[0].size()) {
        return true;
    }
    else {
        return false;
    }
}

bool possible(vector<vector<int>> matrix) { //vyhodnotí, jestli jsou věže v původním postavení
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < (matrix[0].size() - 1); j++) {
            if (!(matrix[i][j] <= matrix[i][j + 1])) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> move(vector<vector<int>> matrix, struct tah a) {
    int i = 0;
    while (matrix[a.from][i] == 0 && i < matrix[0].size()) {
        i++;
    }
    int j = 0;
    while (matrix[a.to][j] == 0 && j < (matrix[0].size())) {
        j++;
    }
    j--;
    matrix[a.to][j] = matrix[a.from][i];
    matrix[a.from][i] = 0;
    return matrix;
}

struct tah thinking(vector<vector<int>> matrix, struct tah last) {
    struct tah next;
    if (start(matrix)) {
        next.from = 0;
        if (matrix[0].size() % 2 == 0) {
            next.to = 2;
            return next;
        }
        else {
            next.to = 1;
            return next;
        }
    }
    else {
        struct tah a;
        struct tah b;
        a.from = 0;
        b.from = 0;
        a.to = 0;
        b.to = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int l = 0;
                while (matrix[i][l] == 0 && l < matrix[0].size()) {
                    l++;
                }
                if (i != j && i != last.to && b.from == 0 && b.to == 0 && matrix[i][l] != 0) {
                    b.from = i;
                    b.to = j;
                    if (possible(move(matrix, b))) {
                        if (a.from == 0 && a.to == 0) {
                            cout << matrix[b.from][l] << endl;
                            a.from = b.from;
                            a.to = b.to;
                            b.from = 0;
                            b.to = 0;
                        }
                    }
                    else {
                        b.from = 0;
                        b.to = 0;
                    }

                }
            }
        }
        cout << a.from << endl;
        cout << a.to << endl;
        cout << b.from << endl;
        cout << b.to << endl;
        int i = 0;
        while (matrix[a.to][i] == 0 && i < matrix[0].size()) {
            i++;
        }
        if (b.from != 0 || b.to != 0) {
            int j = 0;
            cout << "Hi" << endl;
            while (matrix[b.to][j] == 0 && j < matrix[0].size()) {
                j++;
            }
            if (matrix[b.to][j] < matrix[a.to][i]) {
                next.from = b.from;
                next.to = b.to;
                cout << "Im here" << endl;
            }
            else {
                next.from = a.from;
                next.to = a.to;
                cout << "And not here" << endl;
            }
        }
        else {
            next.from = a.from;
            next.to = a.to;
        }
        return next;
    }
}


int main() {
    //int matrix[4][3];
    vector<vector<int>> matrix{ {0,0,0,4},{0,0,1,3},{0,0,0,2} };
    //int size = (sizeof(matrix)/sizeof(matrix[0]));

    /*for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = 0;
        }
        cout << endl;
    }

    //cout << solved(matrix, size) << endl;*/




    /*
    struct tah r;
    r.from = 2;
    r.to = 1;

    //while(!solved(matrix))

    for(int i = 0; i < 15; i++) {
        r = thinking(matrix, r);
        matrix = move(matrix, r);
        print(matrix);
        cout << endl;
    }*/




    QApplication app(argc, argv);
    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget"));
    return app.exec();




    /*cout << m.from << ", " << m.to << endl;

    cout << possible(matrix,size) << endl;*/

    //print(matrix);

    return 0;
}























