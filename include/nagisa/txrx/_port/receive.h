#pragma once

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

namespace receive_cpo
{
	void receive();

	enum class choose
	{
		member,
		adl,
		none,
	};
	struct choice_result
	{
		choose strategy;
		bool nothrow;
	};

	constexpr choice_result choice(auto&& target, auto&&... args) noexcept
	{
		if constexpr (requires { ::std::forward<decltype(target)>(target).receive(::std::forward<decltype(args)>(args)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).receive(::std::forward<decltype(args)>(args)...)) };
		else if constexpr (requires { receive(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...); })
			return { choose::adl, noexcept(receive(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...)) };
		else
			return { choose::none, true };
	}
}

struct receive_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... args)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(receive_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).nothrow)
		requires (receive_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy != receive_cpo::choose::none)
	{
		constexpr auto strategy = receive_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy;
		if constexpr (strategy == receive_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).receive(::std::forward<decltype(args)>(args)...);
		else
		{
			using receive_cpo::receive;
			return receive(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...);
		}
	}
};
inline constexpr receive_t receive{};

NAGISA_BUILD_LIB_DETAIL_END
