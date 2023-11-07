#include <iostream>
#include <math.h>

class Node {
private:
    int data;
    Node* next;
    Node* prev;
public:
    static unsigned int length;
    static Node* head;
    static Node* tail;

    Node(): data(0), next(NULL), prev(NULL) {}
    ~Node() {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;

        if (head == NULL && tail == NULL) {
            tail = newNode;
            head = newNode;
        } else {
            head->prev = newNode;
            head = newNode;
        }
        length += 1;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = tail;
        newNode->next = NULL;

        if (head == NULL && tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length += 1;
    }

    void insertAt(unsigned int pos, int data) {
        if (length < 2) {
            std::cout << "At least, the Linkedlist length is greater than or equal to 2!" << std::endl;
        } else {
            // at least this is more faster than if we tend to start it from head or tail randomly
            if (pos < ceil((length / 2))) {
                Node* current = head;

                unsigned int iter = 1;
                while (iter < pos && current->next != NULL) {
                    current = current->next;
                    ++iter;
                }

                Node* newNode = new Node();
                newNode->data = data;
                newNode->next = current->next;
                newNode->prev = current;

                if (current->next != NULL) {
                    current->next->prev = newNode;
                }
                current->next = newNode;

            } else {
                Node* current = tail;

                unsigned int iter = length;
                while (iter >= pos && current->prev != NULL) {
                    current = current->prev;
                    iter--;
                }

                Node* newNode = new Node();
                newNode->data = data;
                newNode->next = current->next;
                newNode->prev = current;

                if (current->next != NULL) {
                    current->next->prev = newNode;
                }

                current->next = newNode;
            }
        }
        length += 1;
    }

    void deleteAtBeginning() {
        if (length > 0) {
            Node* prev_head = head;

            if (prev_head->next != NULL) {

                prev_head->next->prev = NULL;
                head = prev_head->next;

                length = length - 1;
                delete prev_head;
            } else {

                length = length - 1;
                delete prev_head;

                head = NULL;
                tail = NULL;
            }
        } else {
            std::cout << "Linkedlist is empty!" << std::endl;
        }
    }

    void deleteAtEnd() {
        if (length > 0) {
            Node* prev_tail = tail;

            if (prev_tail->prev != NULL) {

                prev_tail->prev->next = NULL;
                tail = prev_tail->prev;

                length = length - 1;
                delete prev_tail;

            } else {

                length = length - 1;
                delete prev_tail;
                
                head = NULL;
                tail = NULL;
            }
        } else {
            std::cout << "Linkedlist is empty!" << std::endl;
        }
    }

    void deleteAllNodes() {
        if (length > 0) {
            Node* current = head;
            while (current->next != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            delete current;

            head = NULL;
            tail = NULL;
            length = 0;
        } else {
            std::cout << "Linkedlist is empty!" << std::endl;
        }
    }

    void display() {
        
        std::cout << "================== LINKED LIST ==================" << std::endl;

        Node* current = head;

        if (head == NULL && tail == NULL && length == 0) {
            std::cout << "\nLinked List is Empty!" << std::endl;
        } else {
            while (current->next != NULL) {
                std::cout << current->data << std::endl;
                current = current->next;
            }
            std::cout << current->data << std::endl;
        }
    }
};

unsigned int Node::length = 0;
Node* Node::head = NULL;
Node* Node::tail = NULL;

int main(int argc, char* argv[]) {

    Node* linkedList = new Node();

    linkedList->insertAtBeginning(5);
    linkedList->insertAtBeginning(3);
    linkedList->deleteAtBeginning();
    linkedList->insertAtEnd(6);
    linkedList->insertAtEnd(8);
    linkedList->insertAtBeginning(1);
    linkedList->insertAtEnd(9); // -> 1 5 6 8 9
    linkedList->insertAt(2, 4); // -> 1 4 5 6 8 9
    linkedList->insertAt(5, 7); // -> 1 4 5 6 7 8 9
    linkedList->display();
    linkedList->deleteAllNodes(); // empty linked list
    linkedList->display();

    return 0;
}