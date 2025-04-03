#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h> // For sleep

// ANSI colors and styles for terminal output
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define ITALIC      "\033[3m"
#define UNDERLINE   "\033[4m"
#define BLINK       "\033[5m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_WHITE    "\033[47m"

// Utility Functions
void clear_screen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
}

// Simple printing functions to avoid string concatenation issues
void print_header(const std::string& text) {
    std::cout << std::endl;
    std::cout << BOLD << CYAN << "╔═════════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║ " << YELLOW << std::setw(49) << std::left << text << CYAN << " ║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "╚═════════════════════════════════════════════════════╝" << RESET << std::endl;
}

void print_separator() {
    std::cout << CYAN << "--------------------------------------------------------" << RESET << std::endl;
}

void print_trap_info(const std::string& trap_type, const std::string& description) {
    std::cout << std::endl;
    std::cout << BOLD << BLUE << "[ " << trap_type << " ]" << RESET << std::endl;
    std::cout << ITALIC << description << RESET << std::endl;
}

void display_stats(const ClapTrap& trap, const std::string& type) {
    if (type == "ClapTrap") std::cout << BOLD << BLUE;
    else if (type == "ScavTrap") std::cout << BOLD << GREEN;
    else if (type == "FragTrap") std::cout << BOLD << MAGENTA;
    else std::cout << BOLD << YELLOW;

    std::cout << type << " " << trap.get_name() << RESET << ":" << std::endl;
    std::cout << "  ❤️  HP: " << trap.get_hit_points() << std::endl;
    std::cout << "  ⚡ Energy: " << trap.get_energy_points() << std::endl;
    std::cout << "  ⚔️  Attack: " << trap.get_attack_damage() << std::endl;
}

// Display health bar for Trap robots
void display_health_bar(const ClapTrap& trap, unsigned int max_hp, const std::string& name, const std::string& color_code) {
    int bar_width = 20;
    int fill_width = static_cast<int>((static_cast<double>(trap.get_hit_points()) / max_hp) * bar_width);

    std::cout << color_code << name << " [";
    for (int i = 0; i < bar_width; ++i) {
        if (i < fill_width) {
            std::cout << "█";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << trap.get_hit_points() << "/" << max_hp << RESET << std::endl;
}

// Display health bar for enemies (like EVIL-BOT)
void display_enemy_health_bar(unsigned int current_hp, unsigned int max_hp, const std::string& name, const std::string& color_code) {
    int bar_width = 20;
    int fill_width = static_cast<int>((static_cast<double>(current_hp) / max_hp) * bar_width);

    std::cout << color_code << name << " [";
    for (int i = 0; i < bar_width; ++i) {
        if (i < fill_width) {
            std::cout << "█";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "] " << current_hp << "/" << max_hp << RESET << std::endl;
}

// Game Class - Manages our robot battle simulation
class TrapBattleArena {
private:
    ClapTrap* clap;
    ScavTrap* scav;
    FragTrap* frag;

    // Enemy stats
    std::string enemy_name;
    unsigned int enemy_hp;
    unsigned int enemy_max_hp;

public:
    TrapBattleArena() : clap(NULL), scav(NULL), frag(NULL), enemy_name("EVIL-BOT"), enemy_hp(200), enemy_max_hp(200) {}

    ~TrapBattleArena() {
        // Cleanup is handled by the main function
    }

    void introduction() {
        clear_screen();
        print_header("WELCOME TO THE TRAP ROBOT ARENA");

        std::cout << BOLD << YELLOW << "The year is 2150. Hyperion Corporation's robots are battling for supremacy..." << RESET << std::endl;
        usleep(500000); // Pause for dramatic effect

        std::cout << "Three models of robots have emerged:" << std::endl;
        usleep(300000);

        // ClapTrap description
        print_trap_info("ClapTrap", "The basic model. Low HP and damage, but reliable. "
                                   "Perfect for small tasks and reconnaissance.");
        usleep(300000);

        // ScavTrap description
        print_trap_info("ScavTrap", "The defensive specialist. High HP and good damage. "
                                   "Equipped with Gate Keeping mode for defense.");
        usleep(300000);

        // FragTrap description
        print_trap_info("FragTrap", "The offensive powerhouse. High HP, energy, and damage. "
                                   "Known for its enthusiasm and positive attitude in battle.");
        usleep(300000);

        std::cout << BOLD << RED << "\nA rogue AI has created an EVIL-BOT that threatens the city!" << RESET << std::endl;
        std::cout << "Your mission: Deploy your robots to defeat it!" << std::endl;
        usleep(500000);

        std::cout << "\nPress Enter to continue..." << std::endl;
        std::cin.get();
    }

    void create_robots() {
        clear_screen();
        print_header("INITIALIZING ROBOT SEQUENCE");

        std::cout << YELLOW << "Booting up ClapTrap..." << RESET << std::endl;
        usleep(500000);
        clap = new ClapTrap("CT-137");
        clap->set_attack_damage(5);
        usleep(500000);

        std::cout << GREEN << "\nBooting up ScavTrap..." << RESET << std::endl;
        usleep(500000);
        scav = new ScavTrap("ST-249");
        usleep(500000);

        std::cout << MAGENTA << "\nBooting up FragTrap..." << RESET << std::endl;
        usleep(500000);
        frag = new FragTrap("FT-420");
        usleep(500000);

        print_separator();
        std::cout << BOLD << "All robots initialized successfully!" << RESET << std::endl;
        std::cout << "\nExplanation: " << ITALIC << "Notice how the constructors are called in sequence. Each derived class first calls its parent constructor before running its own initialization." << RESET << std::endl;

        std::cout << "\nInitial Stats:" << std::endl;
        display_stats(*clap, "ClapTrap");
        display_stats(*scav, "ScavTrap");
        display_stats(*frag, "FragTrap");

        std::cout << "\nPress Enter to continue..." << std::endl;
        std::cin.get();
    }

    void demonstrate_abilities() {
        clear_screen();
        print_header("ROBOT SPECIAL ABILITIES DEMONSTRATION");

        // Show ScavTrap's special ability
        std::cout << GREEN << "ScavTrap activating special ability..." << RESET << std::endl;
        usleep(500000);
        scav->guardGate();
        std::cout << "Explanation: " << ITALIC << "guardGate() is a special ability unique to ScavTrap." << RESET << std::endl;
        usleep(1000000);

        // Show FragTrap's special ability
        std::cout << MAGENTA << "\nFragTrap activating special ability..." << RESET << std::endl;
        usleep(500000);
        frag->highFivesGuys();
        std::cout << "Explanation: " << ITALIC << "highFivesGuys() is a special ability unique to FragTrap." << RESET << std::endl;
        usleep(1000000);

        // Show attack differences
        std::cout << BOLD << YELLOW << "\nDEMONSTRATING ATTACK PATTERNS:" << RESET << std::endl;
        usleep(500000);

        std::cout << BLUE << "ClapTrap attacking..." << RESET << std::endl;
        clap->attack("Training Dummy");
        usleep(500000);

        std::cout << GREEN << "\nScavTrap attacking..." << RESET << std::endl;
        scav->attack("Training Dummy");
        usleep(500000);

        std::cout << MAGENTA << "\nFragTrap attacking..." << RESET << std::endl;
        frag->attack("Training Dummy");
        usleep(500000);

        std::cout << "\nExplanation: " << ITALIC << "Notice how ScavTrap overrides the attack() method from ClapTrap with its own implementation, while FragTrap uses ClapTrap's implementation." << RESET << std::endl;

        std::cout << "\nPress Enter to continue to the battle!" << std::endl;
        std::cin.get();
    }

    void battle_sequence() {
        clear_screen();
        print_header("FINAL BATTLE: ROBOTS VS EVIL-BOT");

        std::cout << RED << "EVIL-BOT appears! It has " << enemy_hp << " hit points!" << RESET << std::endl;
        usleep(500000);

        int turn = 1;
        bool battle_over = false;

        while (!battle_over) {
            print_separator();
            std::cout << BOLD << "TURN " << turn << RESET << std::endl;
            print_separator();

            // Display current status
            std::cout << "Battle Status:" << std::endl;
            display_health_bar(*clap, 10, "ClapTrap", BLUE);
            display_health_bar(*scav, 100, "ScavTrap", GREEN);
            display_health_bar(*frag, 100, "FragTrap", MAGENTA);
            display_enemy_health_bar(enemy_hp, enemy_max_hp, "EVIL-BOT", RED);

            // Robot actions
            if (clap->get_hit_points() > 0) {
                std::cout << BLUE << "\nClapTrap " << clap->get_name() << " takes action!" << RESET << std::endl;
                clap->attack("EVIL-BOT");
                if (clap->get_energy_points() > 0) {
                    if (enemy_hp <= clap->get_attack_damage()) {
                        enemy_hp = 0;
                    } else {
                        enemy_hp -= clap->get_attack_damage();
                    }
                    std::cout << RED << "EVIL-BOT takes " << clap->get_attack_damage() << " damage!" << RESET << std::endl;
                }
                usleep(500000);
            }

            if (scav->get_hit_points() > 0) {
                std::cout << GREEN << "\nScavTrap " << scav->get_name() << " takes action!" << RESET << std::endl;
                if (turn % 3 == 0) {
                    scav->guardGate();
                    std::cout << GREEN << "ScavTrap defends the team, reducing incoming damage!" << RESET << std::endl;
                } else {
                    scav->attack("EVIL-BOT");
                    if (scav->get_energy_points() > 0) {
                        if (enemy_hp <= scav->get_attack_damage()) {
                            enemy_hp = 0;
                        } else {
                            enemy_hp -= scav->get_attack_damage();
                        }
                        std::cout << RED << "EVIL-BOT takes " << scav->get_attack_damage() << " damage!" << RESET << std::endl;
                    }
                }
                usleep(500000);
            }

            if (frag->get_hit_points() > 0) {
                std::cout << MAGENTA << "\nFragTrap " << frag->get_name() << " takes action!" << RESET << std::endl;
                if (turn % 4 == 0) {
                    frag->highFivesGuys();
                    std::cout << MAGENTA << "The team's morale is boosted!" << RESET << std::endl;
                    if (clap->get_hit_points() > 0) clap->beRepaired(2);
                    if (scav->get_hit_points() > 0) scav->beRepaired(5);
                    if (frag->get_hit_points() > 0) frag->beRepaired(5);
                } else {
                    frag->attack("EVIL-BOT");
                    if (frag->get_energy_points() > 0) {
                        if (enemy_hp <= frag->get_attack_damage()) {
                            enemy_hp = 0;
                        } else {
                            enemy_hp -= frag->get_attack_damage();
                        }
                        std::cout << RED << "EVIL-BOT takes " << frag->get_attack_damage() << " damage!" << RESET << std::endl;
                    }
                }
                usleep(500000);
            }

            // Check if EVIL-BOT is defeated
            if (enemy_hp <= 0) {
                enemy_hp = 0;
                std::cout << BOLD << GREEN << "\nVICTORY! EVIL-BOT has been defeated!" << RESET << std::endl;
                battle_over = true;
                break;
            }

            // EVIL-BOT's turn
            std::cout << RED << "\nEVIL-BOT attacks!" << RESET << std::endl;

            // Determine target and damage
            int target = (turn % 3) + 1;
            unsigned int damage = 10 + (turn * 2); // Increasing damage over time

            // Reduce damage if ScavTrap is in defense mode
            if (turn % 3 == 0) {
                damage = damage / 2;
                std::cout << GREEN << "ScavTrap's Gate Keeper mode reduces the damage!" << RESET << std::endl;
            }

            switch (target) {
                case 1:
                    std::cout << RED << "EVIL-BOT targets ClapTrap " << clap->get_name() << "!" << RESET << std::endl;
                    if (clap->get_hit_points() > 0) {
                        clap->takeDamage(damage);
                    } else {
                        std::cout << RED << "But ClapTrap is already down! EVIL-BOT misses!" << RESET << std::endl;
                    }
                    break;
                case 2:
                    std::cout << RED << "EVIL-BOT targets ScavTrap " << scav->get_name() << "!" << RESET << std::endl;
                    if (scav->get_hit_points() > 0) {
                        scav->takeDamage(damage);
                    } else {
                        std::cout << RED << "But ScavTrap is already down! EVIL-BOT misses!" << RESET << std::endl;
                    }
                    break;
                case 3:
                    std::cout << RED << "EVIL-BOT targets FragTrap " << frag->get_name() << "!" << RESET << std::endl;
                    if (frag->get_hit_points() > 0) {
                        frag->takeDamage(damage);
                    } else {
                        std::cout << RED << "But FragTrap is already down! EVIL-BOT misses!" << RESET << std::endl;
                    }
                    break;
            }

            // Check if all robots are defeated
            if (clap->get_hit_points() == 0 && scav->get_hit_points() == 0 && frag->get_hit_points() == 0) {
                std::cout << BOLD << RED << "\nDEFEAT! All robots have been destroyed!" << RESET << std::endl;
                battle_over = true;
                break;
            }

            // Random repair chance for a robot
            if (turn % 2 == 0) {
                int repair_target = (turn % 3) + 1;
                switch (repair_target) {
                    case 1:
                        if (clap->get_hit_points() > 0 && clap->get_hit_points() < 10) {
                            std::cout << BLUE << "\nClapTrap " << clap->get_name() << " finds a repair kit!" << RESET << std::endl;
                            clap->beRepaired(2);
                        }
                        break;
                    case 2:
                        if (scav->get_hit_points() > 0 && scav->get_hit_points() < 100) {
                            std::cout << GREEN << "\nScavTrap " << scav->get_name() << " finds a repair kit!" << RESET << std::endl;
                            scav->beRepaired(15);
                        }
                        break;
                    case 3:
                        if (frag->get_hit_points() > 0 && frag->get_hit_points() < 100) {
                            std::cout << MAGENTA << "\nFragTrap " << frag->get_name() << " finds a repair kit!" << RESET << std::endl;
                            frag->beRepaired(15);
                        }
                        break;
                }
            }

            turn++;
            std::cout << "\nPress Enter for next turn..." << std::endl;
            std::cin.get();
            clear_screen();
        }

        std::cout << "\nBattle complete! Press Enter to continue..." << std::endl;
        std::cin.get();
    }

    void conclusion() {
        clear_screen();
        print_header("MISSION DEBRIEFING");

        std::cout << YELLOW << "Congratulations on completing the TrapBot simulation!" << RESET << std::endl;
        std::cout << "\nKey concepts demonstrated in this exercise:" << std::endl;

        std::cout << "\n1. " << BOLD << "Inheritance Hierarchy:" << RESET << std::endl;
        std::cout << "   - ClapTrap is the base class" << std::endl;
        std::cout << "   - ScavTrap inherits from ClapTrap" << std::endl;
        std::cout << "   - FragTrap inherits from ClapTrap" << std::endl;

        std::cout << "\n2. " << BOLD << "Constructor/Destructor Chaining:" << RESET << std::endl;
        std::cout << "   - When creating a derived class, the base class constructor runs first" << std::endl;
        std::cout << "   - When destroying objects, the derived class destructor runs first, then the base" << std::endl;
        std::cout << "   - This ensures proper initialization and cleanup of resources" << std::endl;

        std::cout << "\n3. " << BOLD << "Different Attributes:" << RESET << std::endl;
        std::cout << "   - ClapTrap: 10 HP, 10 Energy, 0 Attack" << std::endl;
        std::cout << "   - ScavTrap: 100 HP, 50 Energy, 20 Attack" << std::endl;
        std::cout << "   - FragTrap: 100 HP, 100 Energy, 30 Attack" << std::endl;

        std::cout << "\n4. " << BOLD << "Special Abilities:" << RESET << std::endl;
        std::cout << "   - ScavTrap: guardGate()" << std::endl;
        std::cout << "   - FragTrap: highFivesGuys()" << std::endl;

        std::cout << "\n5. " << BOLD << "Method Overriding:" << RESET << std::endl;
        std::cout << "   - ScavTrap overrides the attack() method with its own implementation" << std::endl;
        std::cout << "   - FragTrap inherits attack() from ClapTrap without modifying it" << std::endl;

        std::cout << "\nYou will now see the objects being destroyed in reverse order of creation..." << std::endl;
        std::cout << "Press Enter to proceed to cleanup..." << std::endl;
        std::cin.get();
    }

    // Cleanup function
    void cleanup() {
        print_header("SHUTTING DOWN ROBOTS");

        // Delete in reverse order of creation to demonstrate destruction order
        std::cout << MAGENTA << "Shutting down FragTrap..." << RESET << std::endl;
        delete frag;
        usleep(500000);

        std::cout << GREEN << "Shutting down ScavTrap..." << RESET << std::endl;
        delete scav;
        usleep(500000);

        std::cout << BLUE << "Shutting down ClapTrap..." << RESET << std::endl;
        delete clap;
        usleep(500000);

        std::cout << BOLD << "\nAll robots shut down. Notice the destruction order!" << RESET << std::endl;
        std::cout << "Explanation: " << ITALIC << "Derived class destructors are called first, then the base class destructors." << RESET << std::endl;
    }
};

int main() {
    TrapBattleArena arena;

    arena.introduction();
    arena.create_robots();
    arena.demonstrate_abilities();
    arena.battle_sequence();
    arena.conclusion();
    arena.cleanup();

    print_header("END OF SIMULATION");
    std::cout << BOLD << YELLOW << "Thank you for exploring inheritance with the Trap robots!" << RESET << std::endl;

    return 0;
}