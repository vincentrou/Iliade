/* $Id: unit_id.cpp 48153 2011-01-01 15:57:50Z mordante $ */
/*
   Copyright (C) 2008 - 2011 by David White <dave@whitevine.net>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/
#include "unit_id.hpp"

#include <cassert>
#include <iostream>
#include <utilite/UtiLite.h>

namespace n_unit {
	id_manager id_manager::manager_;

	id_manager::id_manager() : next_id_(0), fake_id_(size_t(-1))
	{}

	id_manager& id_manager::instance()
	{
		return manager_;
	}

	size_t id_manager::next_id()
	{
		assert(next_id_ != fake_id_);
		ULOGGER_DEBUG("id: %d",next_id_ );
		return ++next_id_;
	}

	size_t id_manager::next_fake_id()
	{
		assert(next_id_ != fake_id_);
		ULOGGER_DEBUG("fake id: " ,fake_id_ );
		return --fake_id_;
	}

	size_t id_manager::get_save_id()
	{
		return next_id_;
	}

	void id_manager::set_save_id(size_t id)
	{
		clear();
		ULOGGER_DEBUG("set save id: ", id );
		next_id_ = id;
	}

	void id_manager::reset_fake()
	{
		fake_id_ = size_t(-1);
	}

	void id_manager::clear()
	{
		next_id_ = 0;
		reset_fake();
	}
}
