#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap named constructor called for " << _name << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

// Override attack method
void ScavTrap::attack(const std::string& target) {
    if (_energy_points > 0 && _hit_points > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_points--;
    } else if (_energy_points == 0) {
        std::cout << "ScavTrap " << _name << " is out of energy and cannot attack!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
    }
}

// ScavTrap specific method
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}