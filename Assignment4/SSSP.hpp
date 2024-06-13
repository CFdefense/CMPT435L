#ifndef SSSP_HPP
#define SSSP_HPP

#include "Node.hpp"
#include <climits>
class SSSP {

    public:
    static bool bellmanFord(Node* source, std::vector<Node>& nodeList);

    private:
    static void relax(Node* curr, Node* dest, int weight);
    static void INIT(std::vector<Node>& nodeList, Node* source);

};



#endif