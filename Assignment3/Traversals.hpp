#ifndef TRAVERSALS_HPP
#define TRAVERSALS_HPP

#include "Node.hpp"
#include "Queue.hpp"
#include <iostream>

class Traversals {

    public:
    static void DFS(Node* vertex);
    static void BFS(Node* vertex);
};

#endif