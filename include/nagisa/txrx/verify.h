#pragma once

#include <expected>

#include "./trait.h"
#include "./exact.h"

#include "./environment.h"
#include "_port/forward.h"

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
};

NAGISA_BUILD_LIB_DETAIL_END

NAGISA_BUILD_LIB_BEGIN


NAGISA_BUILD_LIB_END

#include <nagisa/build_lib/destruct.h>
