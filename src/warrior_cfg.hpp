/*
 * warrior_cfg.hpp
 *
 *  Created on: 2011-07-26
 *      Author: vincentrou
 */

#ifndef WARRIOR_CFG_HPP_
#define WARRIOR_CFG_HPP_

#include "yaml-cpp/yaml.h"
#include "warrior.hpp"
#include <string>

class WarriorCfg
{
public:
	WarriorCfg(std::string path);
	~WarriorCfg();

	enum ID_TYPE{ HOPLITE_1, HOPLITE_2, HOPLITE_3, HOPLITE_4, ARCHER, ELEPHANT, CHAR,
			 CATAPULTE, BALISTE, CHEVAL_DE_TROIE, HERSE, NB_ID_TYPE};
	Warrior warrior_generation(ID_TYPE type);
	Warrior warrior_generation();
	static ID_TYPE random_type();

private:
	/**
	 * @var doc_
	 * @brief dicionnary of units in yaml format saved when the game open
	 */
	YAML::Node doc_;
};

#endif /* WARRIOR_CFG_HPP_ */
