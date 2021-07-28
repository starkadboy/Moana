#pragma once
#ifdef MOA_WINDOWS
	#ifdef MOA_ENGINE_DLL
		#define MOA_API_IE __declspec(dllexport)
	#else
		#define MOA_API_IE __declspec(dllimport)
	#endif
#endif

//#define MOA_NO_ASSERTS