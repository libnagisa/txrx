#pragma once

#include "./_port/range.h"
#include "./_port/send.h"
#include "./_port/receive.h"
#include "./_port/trait.h"

#include "./environment.h"

NAGISA_BUILD_LIB_BEGIN

using details::range_t;
using details::range;

using details::send_t;
using details::send;

using details::receive_t;
using details::receive;

using details::get_authentic_t;
using details::get_authentic;
using details::get_gapless_t;
using details::get_gapless;
using details::get_intact_t;
using details::get_intact;
using details::get_ordered_t;
using details::get_ordered;
using details::get_unique_t;
using details::get_unique;
using details::get_localized_t;
using details::get_localized;
using details::infinite_error;

using details::authentic_port;
using details::gapless_port;
using details::intact_port;
using details::ordered_port;
using details::unique_port;

NAGISA_BUILD_LIB_END

#include <nagisa/build_lib/destruct.h>
