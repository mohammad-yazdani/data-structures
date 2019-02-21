#include <iostream>
#include <string>
#include <BPTree.h>

int
main()
{
    std::cout << "Hello, World!" << std::endl;

    unsigned int order = 5;
    auto tree = BPTree(order);

    std::string data = "data";

    for (int i = 0; i < order; i++) {
        tree.add(new Vertex(static_cast<unsigned long>(i), &data));
    }

    tree.add(new Vertex(static_cast<unsigned long>(12), &data));
    tree.add(new Vertex(static_cast<unsigned long>(6), &data));

    return 0;
}