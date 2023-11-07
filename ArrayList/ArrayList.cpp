#include <iostream>

template <class T>
class ArrayElement {
private:
    T* data;
    ArrayElement* next;
public:
    ArrayElement(): data {nullptr}, next{nullptr} {}

    ~ArrayElement() {
        delete data;
        delete next;
    }

    void push(T&& data, ArrayElement** head, ArrayElement** tail, unsigned int& length) {
        ArrayElement* newElement = new ArrayElement();

        newElement->data = data;
        data = nullptr;

        newElement->next = nullptr;

        if (length == 0) {
            (*head) = newElement;
        }

        if ((*tail) != nullptr) {
            (*tail)->next = newElement;
        }

        (*tail) = newElement;
        length++;
    }

    void clear(ArrayElement** head) {
        ArrayElement* current = (*head)
        ArrayElement* prev = nullptr;

        while(current->next != nullptr) {
            
            std::cout << current->data
            prev = current;
            current = current->next;

            delete prev;
        }

        delete current;

        std::cout << "All data has been deleted!" << std::endl;
    }
};

template <class T>
class ArrayList {
private:
    char* buffer;
    ArrayElement* head;
    ArrayElement* tail;
public:
    unsigned int length;

    ArrayList(): buffer{nullptr}, head{nullptr}, tail{nullptr} {}

    ~ArrayList() {
        delete [] buffer;
        delete head;
        delete tail;
    }
};

int main(int argc, char* argv[]) {

    return 0;
}