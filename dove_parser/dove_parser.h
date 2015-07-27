#pragma once

#ifdef DOVE_PARSER_EXPORT
#define PARSER_API __declspec(dllexport)
#else
#define PARSER_API __declspec(dllimport)
#endif