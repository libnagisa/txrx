#pragma once

#include "./range.h"

#include "./environment.h"


NAGISA_BUILD_LIB_DETAIL_BEGIN

namespace send_cpo
{
	void send();

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

	constexpr choice_result choice_single(auto&& target, auto&& packs) noexcept
	{
		if constexpr (requires { ::std::forward<decltype(target)>(target).send(::std::forward<decltype(packs)>(packs)); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).send(::std::forward<decltype(packs)>(packs))) };
		else if constexpr (requires { send(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)); })
			return { choose::adl, noexcept(send(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs))) };
		else
			return { choose::none, true };
	}
}

struct send_single_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&& packs)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(send_cpo::choice_single(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)).nothrow)
		requires (send_cpo::choice_single(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)).strategy != send_cpo::choose::none)
	{
		constexpr auto strategy = send_cpo::choice_single(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)).strategy;
		if constexpr (strategy == send_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).send(::std::forward<decltype(packs)>(packs));
		else
		{
			using send_cpo::send;
			return send(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs));
		}
	}
};
inline constexpr send_single_t send_single{};

namespace send_cpo
{
	constexpr choice_result choice_range(auto&& target, auto&& packs) noexcept
	{
		if constexpr (requires { ::std::forward<decltype(target)>(target).send(range, ::std::forward<decltype(packs)>(packs)); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).send(range, ::std::forward<decltype(packs)>(packs))) };
		else if constexpr (requires { send(range, ::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)); })
			return { choose::adl, noexcept(send(range, ::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs))) };
		else
			return { choose::none, true };
	}
}

struct send_range_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&& packs)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(send_cpo::choice_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)).nothrow)
		requires (send_cpo::choice_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)).strategy != send_cpo::choose::none)
	{
		constexpr auto strategy = send_cpo::choice_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)).strategy;
		if constexpr (strategy == send_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).send(range, ::std::forward<decltype(packs)>(packs));
		else
		{
			using send_cpo::send;
			return send(::std::forward<decltype(target)>(target), range, ::std::forward<decltype(packs)>(packs));
		}
	}
};
inline constexpr send_range_t send_range{};

struct send_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&& pack)
#if !__cpp_static_call_operator
		const
#endif

	{
		if constexpr (requires{ send_single(::std::forward<decltype(target)>(target), ::std::forward<decltype(pack)>(pack)); })
			return send_single(::std::forward<decltype(target)>(target), ::std::forward<decltype(pack)>(pack));
		else if constexpr (requires{ send_range(::std::forward<decltype(target)>(target), ::std::views::single(::std::forward<decltype(pack)>(pack))); })
			return send_range(::std::forward<decltype(target)>(target), ::std::views::single(::std::forward<decltype(pack)>(pack)));
	}

	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, range_t, auto&& packs)
#if !__cpp_static_call_operator
		const
#endif

	{
		if constexpr (requires{ send_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)); })
			return send_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs));
		else if constexpr (requires{ send_single(::std::forward<decltype(target)>(target), ::std::declval<::std::ranges::range_reference_t<decltype(packs)>>()); })
		{

		}
	}
};
inline constexpr send_t send{};

NAGISA_BUILD_LIB_DETAIL_END
