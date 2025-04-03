#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iomanip>

// ANSI colors for terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Utility function to display a separator line
void display_separator() {
    std::cout << CYAN << "+-------------------------------------------------+" << RESET << std::endl;
}

// Function to display a section header
void display_section(const std::string& title) {
    display_separator();
    std::cout << CYAN << "| " << BOLD << std::setw(47) << std::left << title << RESET << CYAN << " |" << RESET << std::endl;
    display_separator();
}

// Function to display stats for a ClapTrap or ScavTrap
void display_stats(const ClapTrap& trap) {
    std::cout << BOLD << "Stats for " << BLUE << trap.get_name() << RESET << ":" << std::endl;
    std::cout << "- Hit points: " << GREEN << trap.get_hit_points() << RESET << std::endl;
    std::cout << "- Energy points: " << YELLOW << trap.get_energy_points() << RESET << std::endl;
    std::cout << "- Attack damage: " << RED << trap.get_attack_damage() << RESET << std::endl;
}

// Display a health bar
void display_health_bar(const std::string& name, unsigned int health, unsigned int max_health) {
    int bar_width = 20;
    int fill_width = static_cast<int>((static_cast<double>(health) / max_health) * bar_width);

    std::cout << name << " [";
    for (int i = 0; i < bar_width; ++i) {
        if (i < fill_width) {
            std::cout << GREEN << "#" << RESET;
        } else {
            std::cout << ".";
        }
    }
    std::cout << "] " << GREEN << health << RESET << "/" << max_health << std::endl;
}

int main() {
    // Test constructors and inheritance
    display_section("Construction and Inheritance Test");

    std::cout << "Creating a ClapTrap..." << std::endl;
    ClapTrap clap("CT-001");

    std::cout << "\nCreating a ScavTrap..." << std::endl;
    ScavTrap scav("ST-001");

    std::cout << "\nInitial stats:" << std::endl;
    std::cout << BLUE << "ClapTrap: " << RESET << std::endl;
    display_stats(clap);

    std::cout << "\n" << BLUE << "ScavTrap: " << RESET << std::endl;
    display_stats(scav);

    // Test specific functionalities
    display_section("Testing Basic Functionalities");

    std::cout << "Setting attack damage for ClapTrap..." << std::endl;
    clap.set_attack_damage(5);

    std::cout << "\nClapTrap attacking..." << std::endl;
    clap.attack("Target Dummy");

    std::cout << "\nScavTrap attacking..." << std::endl;
    scav.attack("Target Dummy");

    std::cout << "\nTesting ScavTrap's guardGate function..." << std::endl;
    scav.guardGate();

    // Test damage and repair
    display_section("Damage and Repair Test");

    std::cout << "ClapTrap takes damage..." << std::endl;
    clap.takeDamage(3);
    display_stats(clap);

    std::cout << "\nClapTrap repairs itself..." << std::endl;
    clap.beRepaired(2);
    display_stats(clap);

    std::cout << "\nScavTrap takes damage..." << std::endl;
    scav.takeDamage(25);
    display_stats(scav);

    std::cout << "\nScavTrap repairs itself..." << std::endl;
    scav.beRepaired(10);
    display_stats(scav);

    // Test ScavTrap's higher durability
    display_section("Testing ScavTrap Durability");

    std::cout << "Creating a new ClapTrap and ScavTrap for durability test..." << std::endl;
    ClapTrap clap_test("CT-Fragile");
    ScavTrap scav_test("ST-Durable");

    std::cout << "\nInitial stats:" << std::endl;
    display_stats(clap_test);
    display_stats(scav_test);

    std::cout << "\nBoth take 10 damage:" << std::endl;
    clap_test.takeDamage(10);
    scav_test.takeDamage(10);

    std::cout << "\nAfter damage:" << std::endl;
    display_stats(clap_test);
    display_stats(scav_test);

    std::cout << "\nAttempting actions after damage:" << std::endl;
    clap_test.attack("Target");
    scav_test.attack("Target");
    clap_test.beRepaired(5);
    scav_test.beRepaired(5);

    // Test energy depletion
    display_section("Energy Depletion Test for ScavTrap");

    ScavTrap energy_test("ST-Energy");
    std::cout << "Initial energy: " << energy_test.get_energy_points() << std::endl;

    std::cout << "\nAttacking repeatedly to deplete energy..." << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << "\nAttack " << (i + 1) << ":" << std::endl;
        energy_test.attack("Energy Target");
        std::cout << "Remaining energy: " << YELLOW << energy_test.get_energy_points() << RESET << std::endl;
    }

    // Test copy construction and assignment
    display_section("Copy Construction and Assignment Test");

    std::cout << "Creating a ScavTrap..." << std::endl;
    ScavTrap original("Original");
    original.takeDamage(20);

    std::cout << "\nCopying via copy constructor..." << std::endl;
    ScavTrap copy(original);

    std::cout << "\nCopying via assignment operator..." << std::endl;
    ScavTrap assigned = original;

    std::cout << "\nStats after copying:" << std::endl;
    std::cout << BLUE << "Original: " << RESET << std::endl;
    display_stats(original);
    std::cout << BLUE << "\nCopy: " << RESET << std::endl;
    display_stats(copy);
    std::cout << BLUE << "\nAssigned: " << RESET << std::endl;
    display_stats(assigned);

    // End of tests
    display_section("End of Tests");
    std::cout << BOLD << "All objects will now be destroyed in reverse order of creation:" << RESET << std::endl;

    return 0;
}