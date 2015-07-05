/*
 * warrior.hpp
 *
 *  Created on: 2011-07-19
 *      Author: vincentrou
 */

/**
 * @file warrior.hpp
 * @brief Define the warrior attribute and permit to instantiate it,
 */
#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_


#include <vector>
#include <map>
#include <boost/bimap.hpp>
#include <string>
#include "yaml-cpp/yaml.h"

/**
 * @class Warrior warrior.hpp
 * @brief class to describe a warrior in Iliade
 */

class Warrior
{
public:
	Warrior();

	~Warrior();

	bool fill_warrior(const YAML::Node& node);

	int get_id() const;
	void set_id(const int id);

	enum UNIT_TYPE{HOPLITE,ARCHER,ELEPHANT,CHAR,
		CATAPULTE, BALISTE, CHEVAL_DE_TROIE, HERSE};
	//static const std::map<UNIT_TYPE,std::string> c_type_map;
	/* not handy for search the name
	const char* const c_type_names =
	{
			"Hoplite",
			"Archer",
			"Elephant"
	};*/
	void set_type(const UNIT_TYPE type) { type_ = type; }
	void set_type_name(const std::string name) { type_name_ = name; }
	UNIT_TYPE get_type()const { return type_; }
	std::string get_type_name() const { return type_name_; }

	void set_army_point(const int value);
	int get_army_point() const;
	bool is_protected() const;

	enum STATE{HOME, BATTLE, DEAD};
	STATE state() const {return state_;}
	void state(const STATE state){ state_ = state; }

	void set_attack_type(const std::vector<UNIT_TYPE> types) { attack_type_ = types; };
	void set_defend_type(const std::vector<UNIT_TYPE> types) { defend_type_ = types; };

	void set_max_defended(int nb) { nb_max_defended_ = nb; }

	enum SPECIALITY{NONE, CHARGE, HIDE, MULTIPLICATOR, PHALANGE};

private:
	int id_;
	UNIT_TYPE type_;
	std::string type_name_;
	int army_point_;
	bool protected_;
	/**
	 * @var state_
	 * @brief define if a warrior is played or not
	 */
	STATE state_;
	std::vector<UNIT_TYPE> attack_type_;
	std::vector<UNIT_TYPE> defend_type_;
	int nb_max_defended_;
	std::vector<Warrior> defended_warrior_;
	/**
	 * @var speciality_
	 * @brief speciality of a unit (hide, multiplicator, defense against chariot, phalange, fast attack...)
	 */
	int speciality_;

};


#endif /* WARRIOR_HPP_ */
