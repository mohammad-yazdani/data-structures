#include <iostream>
#include <string>
#include <Node.h>

int
main()
{
    std::cout << "Hello, World!" << std::endl;

    unsigned int order = 5;
    auto main_node = Node(order, 0);
    std::cout << main_node.push(new Node(order, 1)) << std::endl;
    std::cout << main_node.push(new Node(order, 3)) << std::endl;
    std::cout << main_node.push(new Node(order, 123)) << std::endl;
    std::cout << main_node.push(new Node(order, 2)) << std::endl;
    std::cout << main_node.push(new Node(order, 4)) << std::endl;
    std::cout << main_node.push(new Node(order, 4)) << std::endl;

    auto test_node = new Node(order, 7);
    std::cout << main_node.push(test_node) << std::endl;

    std::cout << main_node.push(new Node(order, 5)) << std::endl;
    std::cout << main_node.push(new Node(order, 45)) << std::endl;
    std::cout << main_node.push(new Node(order, 6)) << std::endl;

    //main_node.print("-", true);
    std::cout << std::endl;

    test_node->split();

    test_node->print("-", false);
    std::cout << std::endl;

    return 0;
}