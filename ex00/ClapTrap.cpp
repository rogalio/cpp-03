#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap named constructor called for " << _name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

// Member function: attack
void ClapTrap::attack(const std::string& target) {
    if (_energy_points > 0 && _hit_points > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attack_damage << " points of damage!" << std::endl;
        _energy_points--;
    } else if (_energy_points == 0) {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
    }
}

// Member function: takeDamage
void ClapTrap::takeDamage(unsigned int amount) {
    if (_hit_points > 0) {
        if (amount >= _hit_points) {
            _hit_points = 0;
            std::cout << "ClapTrap " << _name << " takes " << amount
                      << " damage and is destroyed!" << std::endl;
        } else {
            _hit_points -= amount;
            std::cout << "ClapTrap " << _name << " takes " << amount
                      << " damage and has " << _hit_points << " hit points left!" << std::endl;
        }
    } else {
        std::cout << "ClapTrap " << _name << " is already destroyed and cannot take more damage!" << std::endl;
    }
}

// Member function: beRepaired
void ClapTrap::beRepaired(unsigned int amount) {
    if (_energy_points > 0 && _hit_points > 0) {
        _hit_points += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount
                  << " hit points and has now " << _hit_points << " hit points!" << std::endl;
        _energy_points--;
    } else if (_energy_points == 0) {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot repair itself!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is out of hit points and cannot repair itself!" << std::endl;
    }
}

// Setters & getters
void ClapTrap::set_attack_damage(unsigned int amount) {
    _attack_damage = amount;
    std::cout << "ClapTrap " << _name << " now has " << _attack_damage << " attack damage!" << std::endl;
}

unsigned int ClapTrap::get_hit_points() const {
    return _hit_points;
}

unsigned int ClapTrap::get_energy_points() const {
    return _energy_points;
}

unsigned int ClapTrap::get_attack_damage() const {
    return _attack_damage;
}

std::string ClapTrap::get_name() const {
    return _name;
}