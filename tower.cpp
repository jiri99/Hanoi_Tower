#include "tower.h"

#include <iostream>
#include <vector>

using namespace std;

Tower::Tower(int n) {
    vector<int> tower1;
    vector<int> tower2;
    vector<int> tower3;

    for(int i=0; i < n; i++){
        tower1.push_back(i+1);
        tower2.push_back(0);
        tower3.push_back(0);
    }

    tower.push_back(tower1);
    tower.push_back(tower2);
    tower.push_back(tower3);

    prev.from = 0;
    next.from = 0;
    prev.to = 0;
    next.to = 0;

    lenght = n;
}

bool Tower::possible(struct tah a) {
    int i = 0;
    int j = 0;
    do {
        i++;
    } while(i != lenght && tower[a.from][i] == 0);
    do {
        j++;
    } while(j != lenght && tower[a.to][j] == 0);
    if(j == lenght || tower[a.from][i] < tower[a.to][j]) {
        return true;
    }
    else {
        return false;
    }
};

bool Tower::start() {
    int i = 0;
    while (i < lenght && tower[0][i] == i + 1) {
        i++;
    }
    if (i == lenght) {
        return true;
    }
    else {
        return false;
    }
};

bool Tower::solved() {
    int i = 0;
    while (i < lenght && tower[2][i] == i + 1) {
        i++;
    }
    if (i == lenght) {
        return true;
    }
    else {
        return false;
    }
};

bool Tower::direct_step() {
    int num = lenght;
    int from = 0;
    int p = 0;
    bool value = false;
    while(tower[2][num-1] == num) {
        num--;
    }
    for(int i = lenght; i > num; i--) {
        if(tower[2][i-1] != i) {
            return value;
        }
    }
    cout << "num: " << num << endl;
    for(int j = 0; j < 2; j++) {
        if(tower[j][lenght-1] == num) {
            from = j;
        }
    }
    for(int k = 0; k < lenght; k++) {
        if(tower[from][k] == 0) {
            p++;
        }
    }
    if(p == lenght - 1 && tower[2][num - 1] == 0) {
        value = true;
        next.from = from;
        cout << "from: " << from << endl;
    }
    return value;
};


void Tower::move(struct tah a) {
    int i = 0;
    while (tower[a.from][i] == 0 && i < lenght) {
        i++;
    }
    int j = 0;
    while (tower[a.to][j] == 0 && j < lenght) {
        j++;
    }
    j--;
    tower[a.to][j] = tower[a.from][i];
    tower[a.from][i] = 0;
    prev.from = next.from;
    prev.to = next.to;
};

struct tah Tower::thinking() {
    if (start()) {
        next.from = 0;
        if (lenght % 2 == 0) {
            next.to = 2;
        }
        else {
            next.to = 1;
        }
        return next;
    }
    else if(direct_step()) {
        next.to = 2;
        return next;
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
                while (tower[i][l] == 0 && l < lenght) {
                    l++;
                }
                if (i != j && i != prev.to && b.from == 0 && b.to == 0 && tower[i][l] != 0) {
                    b.from = i;
                    b.to = j;
                    if (possible(b)) {
                        if (a.from == 0 && a.to == 0) {
                            cout << tower[b.from][l] << endl;
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
        int i = 0;
        while (tower[a.to][i] == 0 && i < lenght) {
            i++;
        }
        if (b.from != 0 || b.to != 0) {
            int j = 0;
            while (tower[b.to][j] == 0 && j < lenght) {
                j++;
            }
            if (tower[b.to][j] < tower[a.to][i]) {
                next.from = b.from;
                next.to = b.to;
            }
            else {
                next.from = a.from;
                next.to = a.to;
            }
        }
        else {
            next.from = a.from;
            next.to = a.to;
        }
        return next;
    }
};
