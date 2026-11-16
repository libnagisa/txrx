#pragma once

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

template<class T>
inline constexpr auto localized_v = ::std::size_t(0);

inline constexpr auto infinite_error = ::std::numeric_limits<::std::size_t>::max();

inline constexpr struct bottom_t{
    constexpr bool operator==(bottom_t const&) const noexcept = default;
} bottom{};

NAGISA_BUILD_LIB_DETAIL_END
