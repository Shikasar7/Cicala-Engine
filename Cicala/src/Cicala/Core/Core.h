#pragma once

#include<memory>

#ifdef  CC_PLATFORM_WINDOWS
#if CC_DYNAMIC_LINK
	#ifdef CC_BUILD_DLL
		#define CICALA_API __declspec(dllexport)
	#else
		#define CICALA_API __declspec(dllimport)
	#endif // DEBUG
#else
	#define CICALA_API
#endif
#else
	#error Cicala only support Windows.
#endif //  CC_PLATFORM_WINDOWS

#ifdef CC_DEBUG
	#define CC_ENABLE_ASSERTS
#endif


#ifdef CC_ENABLE_ASSERTS
	#define CC_ASSERT(x, ...) { if(!(x)) {CC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define CC_CORE_ASSERT(x, ...) { if(!(x)) {CC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define CC_ASSERT(x, ...)
	#define CC_CORE_ASSERT(x, ...)
#endif //like break point and debug


#define BIT(x) (1 << x)

#define CC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Cicala {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}