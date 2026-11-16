#pragma once

#include "./pack.h"
#include "./communicate.h"

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

inline constexpr struct send_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... args)
#if !__cpp_static_call_operator
		const
#endif
	{
		return communicate(
			::std::forward<decltype(target)>(target)
			, outgoing_pack(
				::std::forward<decltype(target)>(target)
				, ::std::forward<decltype(args)>(args)...
			)
		);
	}
} send{};

inline constexpr struct receive_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... args)
#if !__cpp_static_call_operator
		const
#endif
	{
		return communicate(
			::std::forward<decltype(target)>(target)
			, incoming_pack(
				::std::forward<decltype(target)>(target)
				, ::std::forward<decltype(args)>(args)...
			)
		);
	}
} receive{};

NAGISA_BUILD_LIB_DETAIL_END

