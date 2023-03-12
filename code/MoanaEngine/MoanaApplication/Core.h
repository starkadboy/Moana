#pragma once
#ifdef MOA_WINDOWS
	#ifdef MOA_ENGINE_DLL
		#define MOA_API_IE 
	#else
		#define MOA_API_IE
	#endif
#endif

//#define MOA_NO_ASSERTS