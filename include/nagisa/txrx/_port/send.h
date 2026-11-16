#pragma once

#include "./environment.h"


NAGISA_BUILD_LIB_DETAIL_BEGIN


namespace outgoing_pack_cpo
{
	void outgoing_pack();

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
		if constexpr (requires { ::std::forward<decltype(target)>(target).outgoing_pack(::std::forward<decltype(args)>(args)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).outgoing_pack(::std::forward<decltype(args)>(args)...)) };
		else if constexpr (requires { outgoing_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...); })
			return { choose::adl, noexcept(outgoing_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...)) };
		else
			return { choose::none, true };
	}
}

struct outgoing_pack_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... args)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(outgoing_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).nothrow)
		requires (outgoing_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy != outgoing_pack_cpo::choose::none)
	{
		constexpr auto strategy = outgoing_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy;
		if constexpr (strategy == outgoing_pack_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).outgoing_pack(::std::forward<decltype(args)>(args)...);
		else
		{
			using outgoing_pack_cpo::outgoing_pack;
			return outgoing_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...);
		}
	}
};
inline constexpr outgoing_pack_t outgoing_pack{};

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

	constexpr choice_result choice(auto&& target, auto&&... packs) noexcept
	{
		if constexpr (requires { ::std::forward<decltype(target)>(target).send(::std::forward<decltype(packs)>(packs)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).send(::std::forward<decltype(packs)>(packs)...)) };
		else if constexpr (requires { send(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...); })
			return { choose::adl, noexcept(send(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...)) };
		else
			return { choose::none, true };
	}
}

struct send_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... packs)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(send_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).nothrow)
		requires (send_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy != send_cpo::choose::none)
	{
		constexpr auto strategy = send_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy;
		if constexpr (strategy == send_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).send(::std::forward<decltype(packs)>(packs)...);
		else
		{
			using send_cpo::send;
			return send(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...);
		}
	}
};
inline constexpr send_t send{};

namespace send_range_cpo
{
	void send_range();

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
		if constexpr (requires { ::std::forward<decltype(target)>(target).send_range(::std::forward<decltype(packs)>(packs)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).send_range(::std::forward<decltype(packs)>(packs)...)) };
		else if constexpr (requires { send_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...); })
			return { choose::adl, noexcept(send_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...)) };
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
	decltype(auto) operator()(auto&& target, auto&&... packs)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(send_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).nothrow)
		requires (send_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy != send_range_cpo::choose::none)
	{
		constexpr auto strategy = send_range_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...).strategy;
		if constexpr (strategy == send_range_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).send_range(::std::forward<decltype(packs)>(packs)...);
		else
		{
			using send_range_cpo::send_range;
			return send_range(::std::forward<decltype(target)>(target), ::std::forward<decltype(packs)>(packs)...);
		}
	}
};
inline constexpr send_range_t send_range{};

NAGISA_BUILD_LIB_DETAIL_END
