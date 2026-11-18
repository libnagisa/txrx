#pragma once

#include <expected>

#if !__has_include(<stdexec/execution.hpp>)
#	error "nagisa.txrx verify_port requires the stdexec library"
#endif
#include <stdexec/execution.hpp>

#include "./port.h"
#include "./trait.h"
#include "./exact.h"

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

template<class Port, class Computer, class Checker>
struct verify_port : forward_port<Port>
{
	using base_type = forward_port<Port>;
	using self_type = verify_port;
#ifdef _MSC_VER
	[[msvc::no_unique_address]]
#else
	[[no_unique_address]]
#endif
	Computer _computer;

#ifdef _MSC_VER
	[[msvc::no_unique_address]]
#else
	[[no_unique_address]]
#endif
	Checker _checker;

	constexpr decltype(auto) outgoing_pack(this auto&& self, auto&&... args)
		noexcept(noexcept(::std::forward<decltype(self)>(self).self_type::_computer(::std::forward<decltype(self)>(self).base_type::outgoing_pack(::std::forward<decltype(args)>(args)...))))
		requires requires {
			::std::forward<decltype(self)>(self).self_type::_computer(::std::forward<decltype(self)>(self).base_type::outgoing_pack(::std::forward<decltype(args)>(args)...));
		}
	{
		return ::std::forward<decltype(self)>(self).self_type::_computer(::std::forward<decltype(self)>(self).base_type::outgoing_pack(::std::forward<decltype(args)>(args)...));
	}

	constexpr decltype(auto) receive(this auto&& self, auto&&... packs)
	{
		return ::std::forward<decltype(self)>(self).base_type::receive(::std::forward<decltype(packs)>(packs)...)
			| ::stdexec::then(::std::forward<decltype(self)>(self).self_type::_checker);
	}
};

NAGISA_BUILD_LIB_DETAIL_END

NAGISA_BUILD_LIB_BEGIN


NAGISA_BUILD_LIB_END

#include <nagisa/build_lib/destruct.h>
