/*
 * warrior_cfg.cpp
 *
 *  Created on: 2011-07-26
 *      Author: vincentrou
 */

#include "warrior_cfg.hpp"

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <utilite/UtiLite.h>

void operator >> (const YAML::Node& node, std::vector<float>& v) {
	v.resize(node.size());
	for(unsigned i =0;i<node.size();i++){
		node[i] >> v[i];
	}
}

WarriorCfg::WarriorCfg(std::string path)
{
	//load choosen yaml
	ULOGGER_INFO("unit path : %s",path.c_str());
	std::ifstream fin(path.c_str());
	if(fin.is_open() == false){
		ULOGGER_WARN("File for units conf is not open : %s",path.c_str());
	}
	YAML::Parser parser(fin);

	parser.GetNextDocument(doc_);
	ULOGGER_DEBUG("nb different units : %d", doc_.size());

	//Initiate random generation of ID
	srand(time(NULL));
}

WarriorCfg::~WarriorCfg(){
}

Warrior WarriorCfg::warrior_generation(ID_TYPE type)
{
	Warrior unit;

	int id_type;
	doc_[(int)type]["id_type"] >> id_type;
	if( id_type == type)
	{
		//doc_[type]["point"] >> ;
		//Setting global type for warrior
		/*if(doc_[type]["type"].compare("Hoplite") == 0)
		{
			unit.set_type(Warrior::HOPLITE);
			ULOGGER_DEBUG("define Hoplite type");
		}
		unit.set_type_name(doc_[type]["type"]);
		unit.set_army_point(doc_[type]["point"]);
		unit.set_attack_type(doc_[type]["attack"]);
		unit.set_defend_type(doc_[type]["defend"]);
		unit.set_max_defended(doc_[type]["max_defended"]);*/
		unit.fill_warrior(doc_[(int)type]);
		ULOGGER_DEBUG("unit generated : %d", id_type);
	}
	else
	{
		ULOGGER_WARN("Id type not correspond with id type in file");
	}

	return unit;
}

Warrior WarriorCfg::warrior_generation(){
	return this->warrior_generation(WarriorCfg::random_type());
}

WarriorCfg::ID_TYPE WarriorCfg::random_type()
{
	int id = rand()%WarriorCfg::NB_ID_TYPE;
	return (WarriorCfg::ID_TYPE) id;
}

