#pragma once

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

namespace send_pack_cpo
{
	void send_pack();

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
		if constexpr (requires { ::std::forward<decltype(target)>(target).send_pack(::std::forward<decltype(args)>(args)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).send_pack(::std::forward<decltype(args)>(args)...)) };
		else if constexpr (requires { send_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...); })
			return { choose::adl, noexcept(send_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...)) };
		else
			return { choose::none, true };
	}
}

struct send_pack_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... args)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(send_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).nothrow)
		requires (send_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy != send_pack_cpo::choose::none)
	{
		constexpr auto strategy = send_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy;
		if constexpr (strategy == send_pack_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).send_pack(::std::forward<decltype(args)>(args)...);
		else
		{
			using send_pack_cpo::send_pack;
			return send_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...);
		}
	}
};
inline constexpr send_pack_t send_pack{};

namespace receive_pack_cpo
{
	void receive_pack();

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
		if constexpr (requires { ::std::forward<decltype(target)>(target).receive_pack(::std::forward<decltype(args)>(args)...); })
			return { choose::member, noexcept(::std::forward<decltype(target)>(target).receive_pack(::std::forward<decltype(args)>(args)...)) };
		else if constexpr (requires { receive_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...); })
			return { choose::adl, noexcept(receive_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...)) };
		else
			return { choose::none, true };
	}
}

struct receive_pack_t
{
	constexpr
#if __cpp_static_call_operator
	static
#endif
	decltype(auto) operator()(auto&& target, auto&&... args)
#if !__cpp_static_call_operator
		const
#endif
		noexcept(receive_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).nothrow)
		requires (receive_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy != receive_pack_cpo::choose::none)
	{
		constexpr auto strategy = receive_pack_cpo::choice(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...).strategy;
		if constexpr (strategy == receive_pack_cpo::choose::member)
			return ::std::forward<decltype(target)>(target).receive_pack(::std::forward<decltype(args)>(args)...);
		else
		{
			using receive_pack_cpo::receive_pack;
			return receive_pack(::std::forward<decltype(target)>(target), ::std::forward<decltype(args)>(args)...);
		}
	}
};
inline constexpr receive_pack_t receive_pack{};

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
