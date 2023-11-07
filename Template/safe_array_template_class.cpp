#include <iostream>

template<typename T> class SafeArray {
    private:
        T* data;
        unsigned int SIZE;
    public:
        SafeArray(): data(nullptr), SIZE(0) {}
        SafeArray(const SafeArray& _safeArray): data(_safeArray.data), SIZE(_safeArray.SIZE) {}
        SafeArray(T* _data, const unsigned int _SIZE): data(_data), SIZE(_SIZE) {}
        SafeArray& operator = (const SafeArray& _safeArray) {
            if (*this == &_safeArray) {
                return *this;
            } else {
                // set data
                delete [] this->data;
                this->data = new T[this->SIZE];

                // this is right, because if i do this:
                //  this->data = _safeArray.data, then current this->data member will refer to _safeArray.data address
                // the right thing is, current this->data member point to new address, then copy value from _safeArray
                memcpy(this->data, _safeArray.data, sizeof(*_safeArray.data)*_safeArray.SIZE);

                // set SIZE
                this->SIZE = _safeArray.SIZE;

                // return same object
                return *this;
            }
        }
        ~SafeArray() {
            delete [] this->data;
        }

        T& operator [] (const unsigned int _index) {
            if (_index < 0 || _index >= this->SIZE) {
                std::cout << "\nArray index out of bound!"; exit(1);
            } else {
                return this->data[_index];
            }
        }
};

int main() {
    SafeArray<float> safeArray(new float[10]{1.0F, 2.0F, 3.5F, 4.7F, 5.0F, 6.0F, 7.2F, 8.8F, 9.6F, 10.1F}, 10);

    std::cout << safeArray[6];
    return 0;
}