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

namespace transceive_pack_cpo
{
	void transceive_pack();

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
		if constexpr (requires { ::std::forward<decltype(target)>(target).transceive_pack(::std::forward<decltype(args)>(args)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).transceive_pack(::std::forward<decltype(args)>(args)...)) };
		else if constexpr (requires { transceive_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...); })
			return { choose::adl, noexcept(transceive_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...)) };
		else
			return { choose::none, true };
	}
}

struct transceive_pack_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... args)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(transceive_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).nothrow)
		requires (transceive_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy != transceive_pack_cpo::choose::none)
	{
		constexpr auto strategy = transceive_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy;
		if constexpr (strategy == transceive_pack_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).transceive_pack(::std::forward<decltype(args)>(args)...);
		else
		{
			using transceive_pack_cpo::transceive_pack;
			return transceive_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...);
		}
	}
};
inline constexpr transceive_pack_t transceive_pack{};

NAGISA_BUILD_LIB_DETAIL_END
