#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string _name;
    unsigned int _hit_points;
    unsigned int _energy_points;
    unsigned int _attack_damage;

public:
    //  Canonical Form: default constructor, copy constructor, assignment operator, destructor
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    // Member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Setters & getters
    void set_attack_damage(unsigned int amount);
    unsigned int get_hit_points() const;
    unsigned int get_energy_points() const;
    unsigned int get_attack_damage() const;
    std::string get_name() const;
};

#endif