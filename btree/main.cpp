#include <iostream>
#include <string>
#include "Node.h"

int
main()
{
    std::cout << "Hello, World!" << std::endl;
    std::string test = "blaahhahahaha";
    unsigned long order = 5;
    auto main_node = Node(order, 0, &test);
    main_node.push(new Node(order, 1, &test));
    main_node.push(new Node(order, 4, &test));
    main_node.push(new Node(order, 1, &test));
    main_node.push(new Node(order, 5, &test));
    main_node.push(new Node(order, 6, &test));
    main_node.push(new Node(order, 1, &test));

    main_node.print("-");

    return 0;
}