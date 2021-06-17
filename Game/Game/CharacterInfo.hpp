#ifndef CHARACTER_INFO_H_
#define CHARACTER_INFO_H_

#include <string>

// Structure that holds a character's stats
// All are stored as integers, they will never
// go past the 2,147,483,647 int max.
// I think we can display these as 1% of what they are in the code however
typedef struct character_stats
{
	int hp;		// Health Points
	int mp;		// Mana Points / Skill Points
	int str;	// Strength
	int vit;	// Vitality
	int intel;	// Intelligence
	int wis;	// Wisdom
	int agi;	// Agility
	/*int cha;	// Charisma*/
	int luk;	// Luck

} stats;

typedef struct character_equipment
{

} equipment;

typedef struct character_class
{
	std::string name;				// String name of the class
	stats level_up_modifier;		// The modifiers added to the current stats upon level up
	std::string class_description;	// The description of the class (lore or such)


} char_class;

class CharacterInfo
{
	std::string name;	// The character's name
	stats current_stats;	// The player's current stats
};

namespace CharacterInfo //???
{

}

#endif // !CHARACTER_INFO_H_