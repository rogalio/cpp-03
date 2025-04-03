#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() {
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap default constructor called - ready to frag!" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap named constructor called for " << _name << " - locked and loaded!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called - making a clone!" << std::endl;
}

// Assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignment operator called - copying fragging capabilities!" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << _name << " - shutting down fragging systems..." << std::endl;
}

// Special ability
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " enthusiastically requests a high five! ✋" << std::endl;
}