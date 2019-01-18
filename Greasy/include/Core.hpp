#ifndef H_CORE
#define H_CORE

#if GR_WINDOWS
	#if GR_DLLEXPORT
		#define API __declspec(dllexport)
	#else
		#define API __declspec(dllimport)
	#endif
#else
	#define API
#endif

#if defined GR_WINDOWS && defined GR_DEBUG
	#define DEBUG
#else
	#define NDEBUG
#endif

#endif