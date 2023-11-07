#include <iostream>
#include <vector>

class Player {
private:
    // private data members
    unsigned int *id;
    unsigned int health;
    unsigned int level;

public:
    // constructors
    Player(unsigned int _id=0, unsigned int _hp=100,  unsigned int _lvl=1);
    Player(const Player& source);
    Player(Player&& source) noexcept;


    // destructors
    ~Player();

    unsigned int getId() const;
    unsigned int getHealth() const;
    unsigned int getLevel() const;
};

Player::Player(unsigned int _id, unsigned int _hp, unsigned int _lvl)
    : health{_hp}, level{_lvl} {

    this->id = new unsigned int;
    *(this->id) = _id;

    std::cout << "Constructor for: " << *(this->id) << ", var_addres: (" << this->id << ") ins_address: " << this << std::endl;
}

Player::Player(const Player& source)
    : Player{*(source.id), source.health, source.level} {
    std::cout << "Copy Constructor for: " << *(this->id )<< ", var_addres: (" << this->id << ") ins_address: " << this << std::endl;
}

Player::Player(Player&& source) noexcept
    : id{source.id}, health{source.health}, level{source.level} {
    source.id = nullptr;
    std::cout << "Move Constructor for: " << *(this->id )<< ", var_addres: (" << this->id << ") ins_address: " << this << std::endl;
}

Player::~Player() {
    if (this->id != nullptr) {
        std::cout << "this id: " << *(this->id) << ", var_address: (" << this->id << ") has been deleted, ins_address: " << this << std::endl;
    } else {
        std::cout << "nullptr is deleted from: " << this << std::endl;
    }
    delete id;
}

unsigned int Player::getId() const {
    return *(this->id);
}

unsigned int Player::getHealth() const {
    return this->health;
}

unsigned int Player::getLevel() const {
    return this->level;
}

// dangerous function
void displayData(const Player& p) {
    std::cout << "id: " << p.getId() << "\n"
              << "health: " << p.getHealth() << "\n"
              << "level: " << p.getLevel() << "\n";
}

int main(int argc, char* argv[]) {

    // example 1
    // Player hero {2};
    // displayData(hero); // hero.id is destroyed here
    // std::cout << "Hero id: " << hero.getId() << std::endl; 

    // example 2
    std::vector<Player> pvector;

    pvector.push_back(Player{1}); // Player{1} is r-value

    // std::cout << "pvector[0] id: " << pvector[0].getId() << std::endl;

    return 0;
}