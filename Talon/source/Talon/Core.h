#pragma once

#ifdef TALON
#define TALON_API __declspec(dllexport)
#else
#define TALON_API __declspec(dllimport)
#endif

#ifdef TALON
#define TALON_2_API __declspec(dllexport)
#elif defined _WINDLL
#define TALON_2_API __declspec(dllimport, dllexport)
#else
#define TALON_2_API __declspec(dllimport)
#endif