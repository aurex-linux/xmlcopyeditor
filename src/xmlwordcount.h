/*
 * Copyright 2005-2007 Gerald Schmidt.
 *
 * This file is part of Xml Copy Editor.
 *
 * Xml Copy Editor is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * Xml Copy Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Xml Copy Editor; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef XML_WORD_COUNT_H
#define XML_WORD_COUNT_H

#include <string>
#include <memory>
#include "wrapexpat.h"

struct WordCountData : public ParserData
{
	std::string buffer;
	size_t wordCount;
};

class XmlWordCount : public WrapExpat
{
	public:
		XmlWordCount ( const char *encoding = NULL );
		virtual ~XmlWordCount();

		int getWordCount();
	private:
		std::auto_ptr<WordCountData> wcd;
		static void XMLCALL characterdata ( void *data, const XML_Char *s, int len );
		static void XMLCALL end ( void *data, const XML_Char *el );
};

#endif
