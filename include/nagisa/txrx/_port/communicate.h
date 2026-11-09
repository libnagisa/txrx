#pragma once

#include "./environment.h"


NAGISA_BUILD_LIB_DETAIL_BEGIN

namespace communicate_cpo
{
	void communicate();

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

	constexpr choice_result choice(auto&& target, auto&&... packs) noexcept
	{
		if constexpr (requires { ::std::forward<decltype(target)>(target).communicate(::std::forward<decltype(packs)>(packs)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).communicate(::std::forward<decltype(packs)>(packs)...)) };
		else if constexpr (requires { communicate(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...); })
			return { choose::adl, noexcept(communicate(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...)) };
		else
			return { choose::none, true };
	}
}

struct communicate_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... packs)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(communicate_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).nothrow)
		requires (communicate_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy != communicate_cpo::choose::none)
	{
		constexpr auto strategy = communicate_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy;
		if constexpr (strategy == communicate_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).communicate(::std::forward<decltype(packs)>(packs)...);
		else
		{
			using communicate_cpo::communicate;
			return communicate(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...);
		}
	}
};
inline constexpr communicate_t communicate{};

namespace communicate_range_cpo
{
	void communicate_range();

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

	constexpr choice_result choice(auto&& target, auto&&... packs) noexcept
	{
		if constexpr (requires { ::std::forward<decltype(target)>(target).communicate_range(::std::forward<decltype(packs)>(packs)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).communicate_range(::std::forward<decltype(packs)>(packs)...)) };
		else if constexpr (requires { communicate_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...); })
			return { choose::adl, noexcept(communicate_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...)) };
		else
			return { choose::none, true };
	}
}

struct communicate_range_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... packs)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(communicate_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).nothrow)
		requires (communicate_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy != communicate_range_cpo::choose::none)
	{
		constexpr auto strategy = communicate_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy;
		if constexpr (strategy == communicate_range_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).communicate_range(::std::forward<decltype(packs)>(packs)...);
		else
		{
			using communicate_range_cpo::communicate_range;
			return communicate_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...);
		}
	}
};
inline constexpr communicate_range_t communicate_range{};

NAGISA_BUILD_LIB_DETAIL_END
