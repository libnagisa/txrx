#pragma once

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN


namespace incoming_pack_cpo
{
	void incoming_pack();

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
		if constexpr (requires { ::std::forward<decltype(target)>(target).incoming_pack(::std::forward<decltype(args)>(args)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).incoming_pack(::std::forward<decltype(args)>(args)...)) };
		else if constexpr (requires { incoming_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...); })
			return { choose::adl, noexcept(incoming_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...)) };
		else
			return { choose::none, true };
	}
}

struct incoming_pack_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... args)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(incoming_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).nothrow)
		requires (incoming_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy != incoming_pack_cpo::choose::none)
	{
		constexpr auto strategy = incoming_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy;
		if constexpr (strategy == incoming_pack_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).incoming_pack(::std::forward<decltype(args)>(args)...);
		else
		{
			using incoming_pack_cpo::incoming_pack;
			return incoming_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...);
		}
	}
};
inline constexpr incoming_pack_t incoming_pack{};

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

	constexpr choice_result choice(auto&& target, auto&&... packs) noexcept
	{
		if constexpr (requires { ::std::forward<decltype(target)>(target).receive(::std::forward<decltype(packs)>(packs)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).receive(::std::forward<decltype(packs)>(packs)...)) };
		else if constexpr (requires { receive(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...); })
			return { choose::adl, noexcept(receive(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...)) };
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
	decltype(auto) operator()(auto&& target, auto&&... packs)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(receive_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).nothrow)
		requires (receive_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy != receive_cpo::choose::none)
	{
		constexpr auto strategy = receive_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy;
		if constexpr (strategy == receive_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).receive(::std::forward<decltype(packs)>(packs)...);
		else
		{
			using receive_cpo::receive;
			return receive(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...);
		}
	}
};
inline constexpr receive_t receive{};


namespace receive_range_cpo
{
	void receive_range();

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
		if constexpr (requires { ::std::forward<decltype(target)>(target).receive_range(::std::forward<decltype(packs)>(packs)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).receive_range(::std::forward<decltype(packs)>(packs)...)) };
		else if constexpr (requires { receive_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...); })
			return { choose::adl, noexcept(receive_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...)) };
		else
			return { choose::none, true };
	}
}

struct receive_range_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... packs)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(receive_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).nothrow)
		requires (receive_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy != receive_range_cpo::choose::none)
	{
		constexpr auto strategy = receive_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy;
		if constexpr (strategy == receive_range_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).receive_range(::std::forward<decltype(packs)>(packs)...);
		else
		{
			using receive_range_cpo::receive_range;
			return receive_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...);
		}
	}
};
inline constexpr receive_range_t receive_range{};

NAGISA_BUILD_LIB_DETAIL_END
