#pragma once

#include "./_port/pack.h"
#include "./_port/communicate.h"

#include "./environment.h"

NAGISA_BUILD_LIB_BEGIN

using details::send_pack;
using details::receive_pack;
using details::transceive_pack;

using details::communicate;
using details::communicate_range;

NAGISA_BUILD_LIB_END

#include <nagisa/build_lib/destruct.h>
