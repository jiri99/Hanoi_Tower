#include "tower.h"

#include <iostream>
#include <vector>
#include <math.h>

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

    next.from = 0;
    next.to = 0;

    lenght = n;
    total_moves = pow(2,n)-1;
    actual_move = 1;

    A = 0;
    B = 1;
    C = 2;
    if (n % 2 == 0) {
        B = 2;
        C = 1;
    }
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

int Tower::find_upper(int index) {
    int i = 0;
    while(tower[index][i] == 0) {
        i++;
    }
    if(i==lenght) {
        return lenght;
    }
    else {
        return tower[index][i];
    }
}

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
};


struct tah Tower::thinking() {
    if(actual_move % 3 == 1) {
        if(find_upper(A) > find_upper(C)) {
            next.from = C;
            next.to = A;
        }
        else {
            next.from = A;
            next.to = C;
        }
    }
    else if(actual_move % 3 == 2) {
        if(find_upper(A) > find_upper(B)) {
            next.from = B;
            next.to = A;
        }
        else {
            next.from = A;
            next.to = B;

        }
    }
    else {
        if(find_upper(B) > find_upper(C)) {
            next.from = C;
            next.to = B;
        }
        else {
            next.from = B;
            next.to = C;
        }
    }
    actual_move++;
    return next;
}
