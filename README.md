# 🤖 C++ Module 03: Inheritance Adventure! 🤖

<div align="center">
  <img src="https://img.shields.io/badge/language-C%2B%2B-blue" alt="Language">
  <img src="https://img.shields.io/badge/standard-C%2B%2B98-orange" alt="Standard">
  <img src="https://img.shields.io/badge/status-completed-brightgreen" alt="Status">
  <img src="https://img.shields.io/badge/score-100%2F100-success" alt="Score">
</div>

## 🎮 Welcome to the Robot Warfare Simulation

This project implements a hierarchy of combat robots with different capabilities, demonstrating key object-oriented programming concepts, particularly **inheritance**. Follow the journey of ClapTrap and its evolved variants as they battle for supremacy!

## 🔧 Key Features

- **Inheritance Hierarchy**: Base and derived classes with proper implementation
- **Constructor/Destructor Chaining**: Witness the creation and destruction sequence
- **Visual Combat System**: Colorful terminal output with health bars and battle animations
- **Resource Management**: Energy and hit points system with realistic constraints
- **Robot Customization**: Different robot types with unique abilities and strengths

## 🤖 The Robot Family

| Robot Type   | HP  | Energy | Attack | Special Ability    |
| ------------ | --- | ------ | ------ | ------------------ |
| **ClapTrap** | 10  | 10     | 0      | Basic operations   |
| **ScavTrap** | 100 | 50     | 20     | Gate keeper mode   |
| **FragTrap** | 100 | 100    | 30     | High fives request |

## 📂 Project Structure

```
cpp-03/
├── ex00/ - Basic ClapTrap Implementation
│   ├── ClapTrap.hpp - Main robot class definition
│   ├── ClapTrap.cpp - Implementation of ClapTrap functionality
│   ├── main.cpp - Interactive testing environment
│   └── Makefile - Build automation
│
├── ex01/ - ScavTrap Derived Class
│   ├── ClapTrap files from ex00
│   ├── ScavTrap.hpp - ScavTrap derived class definition
│   ├── ScavTrap.cpp - Implementation with specialized behavior
│   └── main.cpp - Extended tests showing inheritance
│
└── ex02/ - FragTrap Derived Class
    ├── All files from ex01
    ├── FragTrap.hpp - FragTrap derived class definition
    ├── FragTrap.cpp - Implementation with specialized behavior
    └── main.cpp - Complete robot battle simulation
```

## 🚀 How to Run

```bash
# Clone this repository
git clone https://github.com/yourusername/cpp-03.git
cd cpp-03

# For each exercise
cd ex00
make        # Compile the program
./claptrap  # Run ClapTrap demo

cd ../ex01
make        # Compile the program
./scavtrap  # Run ScavTrap demo

cd ../ex02
make        # Compile the program
./fragtrap  # Run full robot battle simulation
```

## 🎮 Gameplay Examples

The ex02 demo provides a complete interactive experience:

1. **Robot Initialization**: Watch as robots boot up with constructor sequence
2. **Special Abilities Demo**: See each robot's unique capabilities
3. **Combat Simulation**: Epic battle against the evil EVIL-BOT!
4. **Resource Management**: Experience energy depletion and hit point damage
5. **Robot Shutdown**: Observe proper destruction sequence

## 💡 Key Concepts Demonstrated

- **Inheritance**: Class hierarchy allowing code reuse and specialization
- **Constructors & Destructors**: Proper initialization and cleanup sequence
- **Method Overriding**: Specialized behavior in derived classes
- **Resource Management**: Energy points and hit points systems
- **Object-Oriented Design**: Encapsulation, inheritance, and code organization

## 🎓 Educational Value

This project excellently demonstrates:

- How inheritance can reduce code duplication
- The importance of constructor/destructor chaining
- Best practices for C++ class design
- Proper implementation of Orthodox Canonical Form

## 📝 Implementation Notes

- Compiled with C++ standard C++98
- Strict compliance with the Orthodox Canonical Form
- All classes include appropriate constructors, destructors, and operators
- No memory leaks, properly managed resources
- Clean code with clear organization and naming

## 👾 Combat Mechanics

```
╔═════════════════════════════════════════════════════╗
║ COMBAT SIMULATION                                 ║
╚═════════════════════════════════════════════════════╝

CT-1337
❤️  HP: [████████████████████] 10/10
⚡ Energy: [████████████████████] 10/10
⚔️  Attack: 5

Target Dummy
❤️  HP: [████████████████████] 20/20
```

Each robot can:

- **Attack**: Deal damage based on attack power, costing 1 energy
- **Take Damage**: Reduce hit points when attacked
- **Repair**: Restore hit points, costing 1 energy

When resources are depleted:

- A robot with 0 energy cannot attack or repair
- A robot with 0 hit points cannot perform any actions

## 🎬 Final Notes

This project showcases the power of inheritance in C++ and provides a fun, interactive way to understand complex OOP concepts. The colorful visual output and battle simulation make learning these concepts engaging and memorable!

---

<div align="center">
  <i>Created with ❤️ for 42 School</i>
</div>
