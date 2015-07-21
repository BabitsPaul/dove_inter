#ifndef _CONST_H
#define _CONST_H

#include <map>
#include <string>
using namespace std;

const char valid[]{
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
		'§', '$', ' ', '\t', '\\',
		//brackets
		'[', ']', '(', ')', '{', '}',
		//delimiters
		'\'', '\"', '\n'
};

const char num[]{
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

const char lowercase[]{
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
		'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

const char uppercase[]{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
		'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

struct opRep {
	opRep(string rep , bool prefix , bool unary) {
		this->rep = rep;
		this->prefix = prefix;
		this->unary = unary;
	};

	string rep;
	bool prefix;
	bool unary;
};

typedef pair<opRep, int> OPtoPRIO;

const map<opRep , int> createMap()
{
	map<opRep , int> res;

	res.insert(OPtoPRIO(opRep("(", true, true) , 1));
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

	res.insert(OPtoPRIO(opRep("&&", false, false) ,  11));

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

const map<opRep , int	> mp = createMap();

#endif