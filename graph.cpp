
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
            std::cout<<"son: "<< *it << std::endl;
        }
    }
    
private:
    vector<Array> sons_table;
    vector<Array> fathers_table;
};

    
int main() {
    Graph* g = new Graph();
    
    delete(g);
    return 0;
}


     
