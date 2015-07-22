#pragma once

#include <string>
#include <map>
using namespace std;

map<string, AbstractStructDef> defMap;

void generateDefMap();

class AbstractStructDef 
{
public:
	virtual bool validateNextChar(char c) = 0;

	char* name;
protected:
	AbstractStructDef(char* name);
};

class Text : public AbstractStructDef
{
public:
	Text();
};

class Block : public AbstractStructDef
{
public:
	Block();
};

class Expression : public AbstractStructDef
{
public:
	Expression();
};

class Name : public AbstractStructDef
{
public:
	Name();
};

class Type : public AbstractStructDef
{
public:
	Type();
};

class AccessModifier : public AbstractStructDef
{
public:
	AccessModifier();
};