#include <iostream>

class Node {
private:
    int data;
    std::string class_name;
public:
    Node(): data{0} {
        std::cout << "address: " << this << std::endl;
    }
    Node(int _data, std::string&& _class_name): data{_data}, class_name{_class_name} {
        std::cout << "address: " << this << ", name: " << this->class_name << std::endl;
    }
    ~Node() { std::cout << "this: " << this->class_name << " has been deleted" << std::endl; }

    static void check(Node** pnode) {
        std::cout << "pnode: " <<  (*pnode) << std::endl;
    }

    int getData() const {
        return this->data;
    }
};

int main(int argc, char* argv[]) {
    Node* a = new Node(1, "A");
    Node* b = new Node(2, "B");

    Node::check(&a);

    // how to dereference pointer class object
    std::cout << (*(a)).getData() << std::endl;

    delete b;
    delete a;

    return 0;
}