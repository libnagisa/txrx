#pragma once

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

inline constexpr struct get_authentic_t
{

} get_authentic{};

template<class T>
concept authentic_port = requires(T op)
{
    requires get_authentic(::stdexec::get_env(::std::forward<decltype(op)>(op)));
};

inline constexpr struct get_gapless_t
{

} get_gapless{};

template<class T>
concept gapless_port = requires(T op)
{
    requires get_gapless(::stdexec::get_env(::std::forward<decltype(op)>(op)));
};

inline constexpr struct get_intact_t
{

} get_intact{};

template<class T>
concept intact_port = requires(T op)
{
    requires get_intact(::stdexec::get_env(::std::forward<decltype(op)>(op)));
};

inline constexpr struct get_ordered_t
{

} get_ordered{};

template<class T>
concept ordered_port = requires(T op)
{
    requires get_ordered(::stdexec::get_env(::std::forward<decltype(op)>(op)));
};

inline constexpr struct get_unique_t
{

} get_unique{};

template<class T>
concept unique_port = requires(T op)
{
    requires get_unique(::stdexec::get_env(::std::forward<decltype(op)>(op)));
};

inline constexpr struct get_localized_t
{

} get_localized{};


inline constexpr auto infinite_error = ::std::numeric_limits<::std::size_t>::max();

NAGISA_BUILD_LIB_DETAIL_END

