
/*
########################################################################
#                                                                      #
# Collector: Tag based file management for Linux                       #
#                                                                      #
# Copyright 2015 Brendan Whitfield (bcw7044@rit.edu)                   #
#                                                                      #
########################################################################
#                                                                      #
# filestore.h                                                          #
#                                                                      #
# This file is part of Collector                                       #
#                                                                      #
# Collector is free software: you can redistribute it and/or modify    #
# it under the terms of the GNU General Public License as published by #
# the Free Software Foundation, either version 2 of the License, or    #
# (at your option) any later version.                                  #
#                                                                      #
# Collector is distributed in the hope that it will be useful,         #
# but WITHOUT ANY WARRANTY; without even the implied warranty of       #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        #
# GNU General Public License for more details.                         #
#                                                                      #
# You should have received a copy of the GNU General Public License    #
# along with Collector.  If not, see <http://www.gnu.org/licenses/>.   #
#                                                                      #
########################################################################
*/

#pragma once

#include <unordered_map>

#include <filestore/types.h>


//map strings to TagEntry
//primary data structure for the filestore
typedef std::unordered_map<Tag, TagEntry*> TagMap;


class FileStore
{
	public:
		FileStore();
		~FileStore();

		//primary accessors
		Selection* select(Selector* selector);
		void operation(Operation* operation);

	private:
		FileVector files;
		TagMap tags;

		bool has_tag(const Tag & tag);
		void insert_file(File* file);

		void add_tag(Selection* const selection, const Tag & tag);
		void remove_tag(Selection* const selection, const Tag & tag);
};
