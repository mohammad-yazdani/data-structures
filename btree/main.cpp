#include <iostream>
#include <string>
#include <Node.h>

int
main()
{
    std::cout << "Hello, World!" << std::endl;

    unsigned int order = 5;



    std::string data = "data";
    auto main_node = Node(0, &data);
    auto test_node = new Node(7, &data);
    std::cout << main_node.push(test_node) << std::endl;

    //main_node.print("-", true);
    std::cout << std::endl;

    test_node->split();

    test_node->print("-", false);
    std::cout << std::endl;
    test_node->pop();
    delete test_node;

    return 0;
}