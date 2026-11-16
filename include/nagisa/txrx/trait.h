#pragma once

#include "./_trait/atomic.h"
#include "./_trait/authentic.h"
#include "./_trait/gapless.h"
#include "./_trait/intact.h"
#include "./_trait/localized.h"
#include "./_trait/ordered.h"
#include "./_trait/unique.h"
#include "./environment.h"

NAGISA_BUILD_LIB_BEGIN

using details::is_atomic_v;
using details::is_authentic_v;
using details::is_gapless_v;
using details::is_intact_v;
using details::localized_v;
using details::infinite_error;
using details::bottom;
using details::is_ordered_v;
using details::is_unique_v;

NAGISA_BUILD_LIB_END


#include <nagisa/build_lib/destruct.h>
