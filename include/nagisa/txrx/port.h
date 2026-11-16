#pragma once

#include "./_port/pack.h"
#include "./_port/communicate.h"
#include "./_port/simple_operate.h"

#include "./environment.h"

NAGISA_BUILD_LIB_BEGIN

using details::outgoing_pack;
using details::incoming_pack;

using details::communicate;
using details::communicate_range;

using details::send;
using details::receive;

NAGISA_BUILD_LIB_END

#include <nagisa/build_lib/destruct.h>
