#include <iostream>
#include <memory>

namespace DPattern {
    class Singleton {
        private:
            int id;

            Singleton() {
                std::cout << "Singleton::Singleton: " << this << std::endl;
            }

        public:

            ~Singleton() {
                std::cout << "Singleton::~Singleton: " << this << std::endl;
            }

            static Singleton& instance() {
                static std::unique_ptr<Singleton> mSingleton(new Singleton());
                return *mSingleton; // because mSingleton is a pointer, so *mSingleton is the heap reference
            }

            // default copy and move constructor is deleted / not allowed
            Singleton(const Singleton& instance) = delete;
            Singleton(Singleton&& instance) = delete;
            Singleton& operator=(const Singleton& instance) = delete;
            Singleton& operator=(Singleton&& instance) = delete;

            void setId(int&& id_) {
                this->id = id_;
            }

            void printInfo() const {
                std::cout << "mem addr: " << this << " , Id: " << this->id << std::endl;
            }
    };

    Singleton& Singleton() {
        return Singleton::instance();
    }
}

int main(int argc, char* argv[]) {

    auto& singl1 = DPattern::Singleton();

    singl1.setId(10);
    singl1.printInfo();

    auto& singl2 = DPattern::Singleton();

    singl2.printInfo();

    return 0;
}