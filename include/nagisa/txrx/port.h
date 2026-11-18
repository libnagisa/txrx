#pragma once

#include "./_port/send.h"
#include "./_port/receive.h"
#include "./_port/forward.h"

#include "./environment.h"

NAGISA_BUILD_LIB_BEGIN

using details::outgoing_pack;
using details::send;
using details::send_range;

using details::receive;

using details::forward_port;

NAGISA_BUILD_LIB_END

#include <nagisa/build_lib/destruct.h>
