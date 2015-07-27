#pragma once

#include <map>
#include <string>
using namespace std;

class Intercontext
{
	//preprocessor
public:
	void storePreproc(string t, string r) { preproc.insert(t, r); }
	string translatePreproc(string t) { return preproc.at(t); }
private:
	map<string, string> preproc;

	//brackets
public:
	void storeBracket(long o, long c, char t);
	char getType(long b) { return bracketType.at(b); }
	char getClosing(long o) { return peerOpenToClose.at(o); }
	char getOpening(long c) { return peerCloseToOpen.at(c); }
private:
	map<long, long> peerOpenToClose;
	map<long, long> peerCloseToOpen;
	map<long, char> bracketType;
};