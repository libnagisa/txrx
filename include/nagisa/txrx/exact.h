#pragma once

#include <expected>
#include <functional>

#include "./trait.h"

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

template<class T>
void derived_from_expected(::std::expected<T, bottom_t> const&);

template<class T>
concept exact_result = requires(T t)
{
    { derived_from_expected(::std::forward<decltype(t)>(t)) };
};

template<class F, class T>
concept exact = ::std::invocable<F, T> && requires(F f, T t)
{
    { ::std::invoke(::std::forward<decltype(f)>(f), ::std::forward<decltype(t)>(t)) } -> exact_result;
};

NAGISA_BUILD_LIB_DETAIL_END

NAGISA_BUILD_LIB_BEGIN

using details::exact_result;
using details::exact;

NAGISA_BUILD_LIB_END

#include <nagisa/build_lib/destruct.h>
