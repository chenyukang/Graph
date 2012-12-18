
#include "test.h"
#include "bit_array.h"
#include <vector>
#include <assert.h>
using namespace std;


class Graph {
public:
    Graph() {}
    void addRelation(int a, int b) {
        int max = a > b ? a : b;
        max++;
        if(max > sons_table.size()) {
            sons_table.resize(max);
            fathers_table.resize(max);
            assert(sons_table.size() == fathers_table.size());
        }

        init();
        vector<int> fathers = fathers_table[a].getNonZeroBits();
        for(vector<int>::iterator it = fathers.begin();
            it != fathers.end(); ++it) {
            sons_table[*it].addSon(sons_table[b]);
            fathers_table[b].addFather(*it);
        }
    }

    void getSons(int a) {
        assert(sons_table.size() >= a);
        vector<int> sons = sons_table[a].getNonZeroBits();
        for(vector<int>::iterator it = sons.begin();
            it != sons.end(); ++it) {
            if( *it != a) 
                std::cout<<"son: "<< *it << std::endl;
        }
    }

    void getFathers(int a) {
        assert(fathers_table.size() >= a);
        vector<int> fathers = fathers_table[a].getNonZeroBits();
        for(vector<int>::iterator it = fathers.begin();
            it != fathers.end(); ++it) {
            if(*it != a)
                std::cout<<"father: "<< *it << std::endl;
        }
    }

    
private:
    void init() {
        int num = sons_table.size();
        for(int k =0; k < sons_table.size(); ++k) {
            sons_table[k].setNum(num);
            sons_table[k].set(k);
            fathers_table[k].setNum(num);
            fathers_table[k].set(k);
        }
    }
    
private:
    vector<Array> sons_table;
    vector<Array> fathers_table;
};

    
int main() {
    Graph* g = new Graph();
    g->addRelation(1, 2);
    g->getSons(1);
    g->getFathers(2);
    g->addRelation(2, 3);
    g->getSons(1);
    g->getFathers(3);
    g->addRelation(3, 4);
    g->getFathers(4);
    g->getSons(1);
    g->addRelation(7, 8);
    g->getSons(7);
    g->addRelation(1000, 10001);
    g->getFathers(10001);
    g->getSons(1000);
    g->addRelation(8, 1000);
    g->getSons(1);
    delete(g);
    printf("finshed\n");
    return 0;
}


     
