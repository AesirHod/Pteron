#pragma once

#ifdef PTERON
	#define PTERON_API __declspec(dllexport)
#else
	#define PTERON_API __declspec(dllimport)
#endif
