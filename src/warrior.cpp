/*
 * warrior.cpp
 *
 *  Created on: 2011-07-19
 *      Author: vincentrou
 */

#include "warrior.hpp"

#include "unit_id.hpp"
#include <utilite/UtiLite.h>
#include <boost/assign.hpp>

//It is not bidirectionnal so need to iterate each time we search for a value...
//const std::map<Warrior::UNIT_TYPE,std::string> Warrior::c_type_map =
//		boost::assign::map_list_of(Warrior::HOPLITE, "Hoplite")(Warrior::ARCHER, "Archer")(Warrior::ELEPHANT, "Elephant");

//does not work...
//const Warrior::bimap_type Warrior::c_type_bimap =
//		boost::assign::map_list_of(Warrior::HOPLITE, "Hoplite")(Warrior::ARCHER, "Archer")(Warrior::ELEPHANT, "Elephant");

typedef boost::bimap<Warrior::UNIT_TYPE,std::string> bimap_type;
static bimap_type c_type_bimap;
typedef bimap_type::left_map::const_iterator left_const_iterator;
typedef bimap_type::right_map::const_iterator right_const_iterator;

static void InitMap() {
	if ( c_type_bimap.size() == 0 ) {
		c_type_bimap.insert( bimap_type::value_type( Warrior::HOPLITE, "Hoplite" ) );
		c_type_bimap.insert( bimap_type::value_type( Warrior::ARCHER, "Archer" ) );
		c_type_bimap.insert( bimap_type::value_type( Warrior::ELEPHANT, "Elephant" ) );
		c_type_bimap.insert( bimap_type::value_type( Warrior::CHAR, "Char" ) );
		c_type_bimap.insert( bimap_type::value_type( Warrior::CATAPULTE, "Catapulte" ) );
		c_type_bimap.insert( bimap_type::value_type( Warrior::BALISTE, "Baliste" ) );
		c_type_bimap.insert( bimap_type::value_type( Warrior::CHEVAL_DE_TROIE, "Cheval de Troie" ) );
		c_type_bimap.insert( bimap_type::value_type( Warrior::HERSE, "Herse" ) );
	}
}

/** Exemple of utilisation of bimap
right_const_iterator r_it = c_type_bimap.right.find("Hoplite");
ULOGGER_DEBUG("id type : %d", r_it->second);
left_const_iterator l_it = c_type_bimap.left.find(Warrior::HOPLITE);
ULOGGER_DEBUG("name type : %s", l_it->second.c_str());
**/

void operator >> (const YAML::Node& node, std::vector<std::string>& v) {
	v.resize(node.size());
	for(unsigned i =0;i<node.size();i++){
		node[i] >> v[i];
	}
}

void operator >> (const YAML::Node& node, std::vector<Warrior::UNIT_TYPE>& v) {
	std::vector<std::string> v_temp(node.size());
	v.resize(node.size());
	for(unsigned i =0;i<node.size();i++){
		node[i] >> v_temp[i];
		right_const_iterator r_it = c_type_bimap.right.find(v_temp[i]);
		if(r_it != c_type_bimap.right.end())
		{
			v[i] = r_it->second;
		}
		else
			ULOGGER_WARN("Unit type \'%s\' not known", v_temp[i].c_str());
	}
}

Warrior::Warrior(void):
army_point_(0),
protected_(false),
state_(HOME),
nb_max_defended_(0),
speciality_(NONE)
{
	InitMap();
	id_ = n_unit::id_manager::instance().next_id();
}

Warrior::~Warrior(void)
{
}

bool Warrior::fill_warrior(const YAML::Node& node)
{
	//Setting global type for warrior
	std::string type_name;
	node["type"] >> type_name;
	ULOGGER_DEBUG("name type %s", type_name.c_str());
	right_const_iterator r_it = c_type_bimap.right.find(type_name);
	if(r_it != c_type_bimap.right.end())
	{
		type_ = r_it->second;
		ULOGGER_DEBUG("define type %d", r_it->second);
		node["type"] >> type_name_;
		node["point"] >> army_point_;

		node["attack"] >> attack_type_;
		node["defend"] >> defend_type_;
		node["max_defended"] >> nb_max_defended_;
		return true;
	}
	else
	{
		ULOGGER_WARN("Unit not known by the game...");
		return false;
	}

}

int Warrior::get_id(void) const
{
	return id_;
}
void Warrior::set_id(const int id)
{
	id_ = id;
}

void Warrior::set_army_point(const int value)
{
	army_point_ = value;
}

int Warrior::get_army_point() const
{
	return army_point_;
}

bool Warrior::is_protected() const
{
	return protected_;
}
