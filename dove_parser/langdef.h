#pragma once

#include <wchar.h>
#include <string>
#include <map>
using namespace std;

#define SUPERCALLREP(x) inline ##x(const AbstractStructDef& def)\
										:AbstractStructDef(def)\
										{}

namespace ldef
{
	/* General base class */
	class AbstractStructDef
	{
	public:
		virtual bool validateNextChar(wchar_t c) = 0;
		virtual AbstractStructDef* delegateTo(wchar_t c) = 0;

		char* name;
	protected:
		AbstractStructDef(char* name);
	};

	class Text : public AbstractStructDef
	{
	public:
		Text();

		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class Block : public AbstractStructDef
	{
	public:
		Block();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	private:
		bool inBlockStatement;
	};

	class Expression : public AbstractStructDef
	{
	public:
		Expression();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class Name : public AbstractStructDef
	{
	public:
		Name();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class Type : public AbstractStructDef
	{
	public:
		Type();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class AccessModifier : public AbstractStructDef
	{
	public:
		AccessModifier();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class Class : public AbstractStructDef
	{
	public:
		Class();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class Member : public AbstractStructDef
	{
	public:
		Member();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class Method : public AbstractStructDef
	{
	public:
		Method();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class Constructor : public AbstractStructDef
	{
	public:
		Constructor();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class Variable : public AbstractStructDef
	{
	public:
		Variable();
		bool validateNextChar(wchar_t c);
		AbstractStructDef * delegateTo(wchar_t c);
	};

	class String : public AbstractStructDef
	{
	public:
		String();
		bool validateNextChar(char c);
		AbstractStructDef * delegateTo(char c);
	};

	class Number : public AbstractStructDef
	{
	public:
		Number();
		bool validateNextChar(char c);
		AbstractStructDef * delegateTo(char c);
	};

	void generateDefMap();

	map<string, AbstractStructDef*> defMap;
}

#define SUPERCALLREP//don't allow usage of this anywhere else