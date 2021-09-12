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

    struct tah prev;
    struct tah next;

    int lenght;

    Tower(int n);
    ~Tower() {};

    bool possible(struct tah a);
    bool start();
    bool solved();
    bool direct_step();

    void move(struct tah a);
    struct tah thinking();
    void paint();
};


#endif // TOWER_H
