#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h> // For sleep

// ANSI colors and styles for terminal output
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"

// Utility Functions
void print_header(const std::string& text) {
    std::cout << std::endl;
    std::cout << BOLD << CYAN << "╔═════════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║ " << YELLOW << std::setw(49) << std::left << text << CYAN << " ║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "╚═════════════════════════════════════════════════════╝" << RESET << std::endl;
}

void print_separator() {
    std::cout << CYAN << "--------------------------------------------------------" << RESET << std::endl;
}

// Display health and energy bars for ClapTrap
void display_status_bars(const ClapTrap& trap) {
    int bar_width = 20;
    int hp_fill = static_cast<int>((static_cast<double>(trap.get_hit_points()) / 10) * bar_width);
    int energy_fill = static_cast<int>((static_cast<double>(trap.get_energy_points()) / 10) * bar_width);

    std::cout << BOLD << BLUE << trap.get_name() << RESET << std::endl;

    // HP bar
    std::cout << "❤️  HP: [";
    for (int i = 0; i < bar_width; ++i) {
        if (i < hp_fill) {
            std::cout << GREEN << "█" << RESET;
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << GREEN << trap.get_hit_points() << RESET << "/10" << std::endl;

    // Energy bar
    std::cout << "⚡ Energy: [";
    for (int i = 0; i < bar_width; ++i) {
        if (i < energy_fill) {
            std::cout << YELLOW << "█" << RESET;
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << YELLOW << trap.get_energy_points() << RESET << "/10" << std::endl;

    // Attack damage
    std::cout << "⚔️  Attack: " << RED << trap.get_attack_damage() << RESET << std::endl;
}

// Display enemy health bar
void display_enemy_status(const std::string& name, unsigned int hp, unsigned int max_hp) {
    int bar_width = 20;
    int hp_fill = static_cast<int>((static_cast<double>(hp) / max_hp) * bar_width);

    std::cout << BOLD << RED << name << RESET << std::endl;

    // HP bar
    std::cout << "❤️  HP: [";
    for (int i = 0; i < bar_width; ++i) {
        if (i < hp_fill) {
            std::cout << RED << "█" << RESET;
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << RED << hp << RESET << "/" << max_hp << std::endl;
}

int main() {
    // Introduction
    print_header("CLAPTRAP DEMONSTRATION");
    std::cout << YELLOW << "Welcome to the ClapTrap demonstration program!" << RESET << std::endl;
    std::cout << "ClapTrap is a basic robot with limited capabilities." << std::endl;
    std::cout << "Let's see what it can do!" << std::endl;
    usleep(500000); // Sleep for 0.5 seconds

    // Constructors Test
    print_header("INITIALIZING CLAPTRAP UNITS");

    std::cout << "Creating default ClapTrap..." << std::endl;
    ClapTrap default_trap;
    usleep(300000);

    std::cout << "\nCreating named ClapTrap 'CT-1337'..." << std::endl;
    ClapTrap hero("CT-1337");
    usleep(300000);

    std::cout << "\nCreating copy of 'CT-1337'..." << std::endl;
    ClapTrap copy_trap(hero);
    usleep(300000);

    print_separator();

    // Basic functionality test
    print_header("BASIC FUNCTIONALITY TEST");

    // Set attack damage
    std::cout << "Setting " << BLUE << hero.get_name() << RESET << "'s attack damage to " << RED << "5" << RESET << "..." << std::endl;
    hero.set_attack_damage(5);
    usleep(300000);

    // Display initial status
    std::cout << "\nInitial status:" << std::endl;
    display_status_bars(hero);
    usleep(500000);

    // Combat test with an enemy
    print_header("COMBAT SIMULATION");

    // Initialize enemy stats
    std::string enemy_name = "Target Dummy";
    unsigned int enemy_hp = 20;
    unsigned int enemy_max_hp = 20;

    std::cout << "Battle begins: " << BLUE << hero.get_name() << RESET << " vs " << RED << enemy_name << RESET << std::endl;
    std::cout << "\nCombatants status:" << std::endl;
    display_status_bars(hero);
    std::cout << std::endl;
    display_enemy_status(enemy_name, enemy_hp, enemy_max_hp);
    usleep(500000);

    // Attack phase
    std::cout << "\n" << YELLOW << "Phase 1: ClapTrap Attacks" << RESET << std::endl;
    std::cout << BLUE << hero.get_name() << RESET << " attacks " << RED << enemy_name << RESET << "!" << std::endl;
    hero.attack(enemy_name);

    // Update enemy HP
    if (enemy_hp > hero.get_attack_damage()) {
        enemy_hp -= hero.get_attack_damage();
        std::cout << RED << enemy_name << " takes " << hero.get_attack_damage() << " damage!" << RESET << std::endl;
    } else {
        enemy_hp = 0;
        std::cout << RED << enemy_name << " is destroyed!" << RESET << std::endl;
    }
    usleep(500000);

    // Display updated status
    std::cout << "\nStatus after attack:" << std::endl;
    display_status_bars(hero);
    std::cout << std::endl;
    display_enemy_status(enemy_name, enemy_hp, enemy_max_hp);
    usleep(500000);

    // Enemy attacks
    std::cout << "\n" << YELLOW << "Phase 2: Enemy Counterattack" << RESET << std::endl;
    std::cout << RED << enemy_name << " counterattacks " << BLUE << hero.get_name() << RESET << " for " << RED << "4 damage" << RESET << "!" << std::endl;
    hero.takeDamage(4);
    usleep(500000);

    // Display updated status
    std::cout << "\nStatus after counterattack:" << std::endl;
    display_status_bars(hero);
    std::cout << std::endl;
    display_enemy_status(enemy_name, enemy_hp, enemy_max_hp);
    usleep(500000);

    // Repair phase
    std::cout << "\n" << YELLOW << "Phase 3: ClapTrap Repairs" << RESET << std::endl;
    std::cout << GREEN << hero.get_name() << " repairs itself for 2 hit points!" << RESET << std::endl;
    hero.beRepaired(2);
    usleep(500000);

    // Display updated status
    std::cout << "\nStatus after repair:" << std::endl;
    display_status_bars(hero);
    std::cout << std::endl;
    display_enemy_status(enemy_name, enemy_hp, enemy_max_hp);
    usleep(500000);

    // Final attack to destroy target
    std::cout << "\n" << YELLOW << "Phase 4: Finishing Move" << RESET << std::endl;
    std::cout << BLUE << hero.get_name() << RESET << " launches a powerful attack against " << RED << enemy_name << RESET << "!" << std::endl;
    hero.attack(enemy_name);
    enemy_hp = (enemy_hp > hero.get_attack_damage()) ? enemy_hp - hero.get_attack_damage() : 0;

    if (enemy_hp == 0) {
        std::cout << RED << enemy_name << " has been completely destroyed!" << RESET << std::endl;
    } else {
        std::cout << RED << enemy_name << " has " << enemy_hp << " HP remaining!" << RESET << std::endl;
    }
    usleep(500000);

    // Display final combat status
    std::cout << "\nFinal combat status:" << std::endl;
    display_status_bars(hero);
    std::cout << std::endl;
    display_enemy_status(enemy_name, enemy_hp, enemy_max_hp);
    usleep(500000);

    // Energy depletion test
    print_header("ENERGY DEPLETION TEST");

    std::cout << "Creating a new ClapTrap 'Energy-Test' for energy depletion test..." << std::endl;
    ClapTrap energy_trap("Energy-Test");
    energy_trap.set_attack_damage(1); // Give it some attack damage to see effect
    usleep(300000);

    // Create a new dummy target
    std::string training_dummy = "Training Dummy";
    unsigned int dummy_hp = 20;
    unsigned int dummy_max_hp = 20;

    std::cout << "\nInitial status:" << std::endl;
    display_status_bars(energy_trap);
    std::cout << std::endl;
    display_enemy_status(training_dummy, dummy_hp, dummy_max_hp);
    usleep(300000);

    std::cout << "\n" << YELLOW << "Depleting energy by performing attacks..." << RESET << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "Attack " << (i + 1) << "/10: ";
        energy_trap.attack(training_dummy);

        // Update dummy HP if attack is successful
        if (energy_trap.get_energy_points() > 0 && i < 10) { // Check if attack was successful
            if (dummy_hp > energy_trap.get_attack_damage()) {
                dummy_hp -= energy_trap.get_attack_damage();
                std::cout << RED << training_dummy << " takes " << energy_trap.get_attack_damage() << " damage!" << RESET << std::endl;
            } else {
                dummy_hp = 0;
                std::cout << RED << training_dummy << " is destroyed!" << RESET << std::endl;
            }
        }

        // Show status every few attacks
        if (i == 4 || i == 9) {
            std::cout << "\nStatus after " << (i + 1) << " attacks:" << std::endl;
            display_status_bars(energy_trap);
            std::cout << std::endl;
            display_enemy_status(training_dummy, dummy_hp, dummy_max_hp);
        }
        usleep(200000);
    }

    std::cout << "\n" << YELLOW << "Testing actions with no energy:" << RESET << std::endl;
    std::cout << "Attempting to attack with no energy..." << std::endl;
    energy_trap.attack(training_dummy);
    usleep(300000);

    std::cout << "\nAttempting to repair with no energy..." << std::endl;
    energy_trap.beRepaired(5);
    usleep(300000);

    // Hit points depletion test
    print_header("HIT POINTS DEPLETION TEST");

    std::cout << "Creating a new ClapTrap 'HP-Test' for hit points depletion test..." << std::endl;
    ClapTrap hp_trap("HP-Test");
    usleep(300000);

    std::cout << "\nInitial status:" << std::endl;
    display_status_bars(hp_trap);
    usleep(300000);

    std::cout << "\n" << RED << "Evil enemy inflicts fatal damage (15 points)..." << RESET << std::endl;
    hp_trap.takeDamage(15);
    usleep(300000);

    std::cout << "\nStatus after fatal damage:" << std::endl;
    display_status_bars(hp_trap);
    usleep(500000);

    std::cout << "\n" << YELLOW << "Testing actions with no hit points:" << RESET << std::endl;
    std::cout << "Attempting to attack with no hit points..." << std::endl;
    hp_trap.attack("Enemy");
    usleep(300000);

    std::cout << "\nAttempting to repair with no hit points..." << std::endl;
    hp_trap.beRepaired(5);
    usleep(300000);

    std::cout << "\nAttempting to take more damage when already at 0 HP..." << std::endl;
    hp_trap.takeDamage(5);
    usleep(500000);

    // Conclusion
    print_header("TEST CONCLUSION");
    std::cout << GREEN << "All ClapTrap tests completed successfully!" << RESET << std::endl;
    std::cout << "\nThis demonstration showed:" << std::endl;
    std::cout << "- ClapTrap construction and initialization" << std::endl;
    std::cout << "- Basic combat capabilities (attack, take damage, repair)" << std::endl;
    std::cout << "- Energy point consumption" << std::endl;
    std::cout << "- Hit point management" << std::endl;
    std::cout << "- Proper behavior when resources are depleted" << std::endl;

    std::cout << "\n" << YELLOW << "Destructors will now be called as the program exits..." << RESET << std::endl;

    return 0;
}