#pragma once

#include "./send.h"
#include "./receive.h"

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

template<class Port>
struct forward_port
{
#ifdef _MSC_VER
	[[msvc::no_unique_address]]
#else
	[[no_unique_address]]
#endif
	Port _port;

	constexpr decltype(auto) outgoing_pack(this auto&& self, auto&&... args)
		noexcept(noexcept(details::outgoing_pack(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(args)>(args)...)))
		requires requires { details::outgoing_pack(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(args)>(args)...); }
	{
		return details::outgoing_pack(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(args)>(args)...);
	}

	constexpr decltype(auto) send(this auto&& self, auto&&... packs)
		noexcept(noexcept(details::send(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...)))
		requires requires { details::send(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...); }
	{
		return details::send(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...);
	}

	constexpr decltype(auto) send_range(this auto&& self, auto&&... packs)
		noexcept(noexcept(details::send_range(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...)))
		requires requires { details::send_range(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...); }
	{
		return details::send_range(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...);
	}

	constexpr decltype(auto) receive(this auto&& self, auto&&... packs)
		noexcept(noexcept(details::receive(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...)))
		requires requires { details::receive(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...); }
	{
		return details::receive(::std::forward<decltype(self)>(self).forward_port::_port, ::std::forward<decltype(packs)>(packs)...);
	}
};

NAGISA_BUILD_LIB_DETAIL_END

