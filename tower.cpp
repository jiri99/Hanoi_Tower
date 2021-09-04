#include "tower.h"

#include <iostream>
#include <vector>

using namespace std;

Tower::Tower(int n)
{
    vector<vector<int>> tower;

    vector<int> tower1;
    vector<int> tower2;
    vector<int> tower3;

    for(int i=1; i < n; i++){
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
}

bool Tower::possible(struct tah a) {
    for (int i = 0; i < tower.size(); i++) {
        for (int j = 0; j < (tower[0].size() - 1); j++) {
            if (!(tower[i][j] <= tower[i][j + 1])) {
                return false;
            }
        }
    }
    return true;
};

bool Tower::start() {
    int i = 0;
    while (tower[0][i] == i + 1 && i < tower[0].size()) {
        i++;
    }
    if (i == tower[0].size()) {
        return true;
    }
    else {
        return false;
    }
};

bool Tower::solved() {
    int i = 0;
    while (tower[2][i] == i + 1 && i < tower[0].size()) {
        i++;
    }
    if (i == tower[0].size()) {
        return true;
    }
    else {
        return false;
    }
};

void Tower::move(struct tah a) {
    int i = 0;
    while (tower.at(a.from).at(i) == 0 && i < tower[0].size()) {
        i++;
    }
    int j = 0;
    while (tower[a.to][j] == 0 && j < (tower[0].size())) {
        j++;
    }
    j--;
    tower[a.to][j] = tower[a.from][i];
    tower[a.from][i] = 0;
};

struct tah Tower::thinking() {
    if (start()) {
            next.from = 0;
            if (tower[0].size() % 2 == 0) {
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
                    while (tower[i][l] == 0 && l < tower[0].size()) {
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
            cout << a.from << endl;
            cout << a.to << endl;
            cout << b.from << endl;
            cout << b.to << endl;
            int i = 0;
            while (tower[a.to][i] == 0 && i < tower[0].size()) {
                i++;
            }
            if (b.from != 0 || b.to != 0) {
                int j = 0;
                cout << "Hi" << endl;
                while (tower[b.to][j] == 0 && j < tower[0].size()) {
                    j++;
                }
                if (tower[b.to][j] < tower[a.to][i]) {
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
};

void Tower::paint() {

};
