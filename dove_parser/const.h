#ifndef _CONST_H
#define _CONST_H

#include <wchar.h>
#include <map>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
// const.h
//
// defines general constants of the language
// like valid characters for the general
// language (not that this doesn't affect stringliterals, which
// are implemented as unicode in general). Furthermore this header
// provides priorityinformation for operators
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
// char sets
//
// charsets used by the language
// here the charsets for names, numbers, etc. are defined
//////////////////////////////////////////////////////////////////////////////////////////////////

const wchar_t valid[]{
	//alphabet lowercase
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	//alphabet uppercase
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P', 'Q','R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	//numbers
	'1', '2', '3', '4', '5','6', '7', '8', '9', '0',
	//operators
	'+', '-', '*', '/', '^', '&', '|', '#', '!', '@', '%', '~',
	//miscellaneous
	'�', '$', ' ', '\t', '\\', '?', ':', '.' , ',',
	//brackets
	'[', ']', '(', ')', '{', '}',
	//delimiters
	'\'', '\"', '\n', '\r', ';'
};

const wchar_t num[]{
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

const wchar_t lowercase[]{
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

const wchar_t uppercase[]{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// operators
//
// this part defines all operators and their respective priority in the language
//////////////////////////////////////////////////////////////////////////////////////////////////

struct opRep {
	opRep(string rep, bool prefix, bool unary) {
		this->rep = rep;
		this->prefix = prefix;
		this->unary = unary;
	};

	string rep;
	bool prefix;
	bool unary;
};

typedef pair<opRep, int> OPtoPRIO;

const map<opRep, int> createMap()
{
	map<opRep, int> res;

	res.insert(OPtoPRIO(opRep("(", true, true), 1));
	res.insert(OPtoPRIO(opRep("[", true, true), 1));
	res.insert(OPtoPRIO(opRep(".", true, false), 1));
	res.insert(OPtoPRIO(opRep("++", false, true), 1));
	res.insert(OPtoPRIO(opRep("--", false, true), 1));

	res.insert(OPtoPRIO(opRep("--", true, true), 2));
	res.insert(OPtoPRIO(opRep("++", true, true), 2));
	res.insert(OPtoPRIO(opRep("+", true, true), 2));
	res.insert(OPtoPRIO(opRep("-", true, true), 2));
	res.insert(OPtoPRIO(opRep("~", true, true), 2));
	res.insert(OPtoPRIO(opRep("!", true, true), 2));

	res.insert(OPtoPRIO(opRep("*", false, false), 3));
	res.insert(OPtoPRIO(opRep("/", false, false), 3));
	res.insert(OPtoPRIO(opRep("%", false, false), 3));

	res.insert(OPtoPRIO(opRep("+", false, false), 4));
	res.insert(OPtoPRIO(opRep("-", false, false), 4));

	res.insert(OPtoPRIO(opRep(">>", false, false), 5));
	res.insert(OPtoPRIO(opRep("<<", false, false), 5));
	res.insert(OPtoPRIO(opRep(">>>", false, false), 5));

	res.insert(OPtoPRIO(opRep("<=", false, false), 6));
	res.insert(OPtoPRIO(opRep(">=", false, false), 6));
	res.insert(OPtoPRIO(opRep("<", false, false), 6));
	res.insert(OPtoPRIO(opRep(">", false, false), 6));

	res.insert(OPtoPRIO(opRep("==", false, false), 7));
	res.insert(OPtoPRIO(opRep("!=", false, false), 7));

	res.insert(OPtoPRIO(opRep("&", false, false), 8));

	res.insert(OPtoPRIO(opRep("^", false, false), 9));

	res.insert(OPtoPRIO(opRep("|", false, false), 10));

	res.insert(OPtoPRIO(opRep("&&", false, false), 11));

	res.insert(OPtoPRIO(opRep("||", false, false), 12));

	res.insert(OPtoPRIO(opRep("?:", false, false), 13));

	res.insert(OPtoPRIO(opRep("=", false, false), 14));
	res.insert(OPtoPRIO(opRep("+=", false, false), 14));
	res.insert(OPtoPRIO(opRep("-=", false, false), 15));
	res.insert(OPtoPRIO(opRep("*=", false, false), 15));
	res.insert(OPtoPRIO(opRep("/=", false, false), 15));
	res.insert(OPtoPRIO(opRep("%=", false, false), 15));
	res.insert(OPtoPRIO(opRep("<<=", false, false), 16));
	res.insert(OPtoPRIO(opRep(">>=", false, false), 15));
	res.insert(OPtoPRIO(opRep(">>>=", false, false), 15));
	res.insert(OPtoPRIO(opRep("^=", false, false), 15));
	res.insert(OPtoPRIO(opRep("&=", false, false), 15));
	res.insert(OPtoPRIO(opRep("|=", false, false), 15));

	return res;
}

const map<opRep, int> mp = createMap();

//////////////////////////////////////////////////////////////////////////////////////////////////
// special characters
//
// a list of special characters and their meaning
//////////////////////////////////////////////////////////////////////////////////////////////////

char* lineDelimiter = "\r\n";

char concatLines = '\\';

char preproc = '#';

char stringDelimiter = '"';

char* empty = " \n\r\b\t";

#endif