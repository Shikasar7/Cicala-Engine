#pragma once

#ifdef  CC_PLATFORM_WINDOWS
	#ifdef CC_BUILD_DLL
		#define CICALA_API __declspec(dllexport)
	#else
		#define CICALA_API __declspec(dllimport)
	#endif // DEBUG
#else
	#error Cicala only support Windows.
#endif //  CC_PLATFORM_WINDOWS
