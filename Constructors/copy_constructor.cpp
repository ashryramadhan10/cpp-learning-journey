#include <iostream>

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
    : Player{*source.id, source.health, source.level} { // copy constructor
    std::cout << "Copy Constructor for: " << *(this->id )<< ", var_addres: (" << this->id << ") ins_address: " << this << std::endl;
}

Player::~Player() {
    std::cout << "this id: " << *(this->id) << ", var_address: (" << this->id << ") has been deleted, ins_address: " << this << std::endl;
    delete this->id;
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

void displayData(Player p) {
    std::cout << "id: " << p.getId() << "\n"
              << "health: " << p.getHealth() << "\n"
              << "level: " << p.getLevel() << "\n";
}

int main(int argc, char* argv[]) {

    Player hero {2};
    Player anotherHero {hero};

    displayData(hero); // hero.id is destroyed here

    std::cout << "Hero id: " << hero.getId() << std::endl;
    std::cout << "Anotherhero id: " << anotherHero.getId() << std::endl;

    return 0;
}