#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <vector>

using namespace std;

struct tah {
    int from;
    int to;
};

class Tower
{
public:
    vector<vector<int>> tower;

    struct tah next;

    int lenght;
    int total_moves;
    int actual_move;

    int A;
    int B;
    int C;

    Tower(int n);
    ~Tower() {};

    bool possible(struct tah a);
    bool solved();
    int find_upper(int index);

    void move(struct tah a);
    struct tah thinking();
};


#endif // TOWER_H
