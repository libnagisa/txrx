#pragma once

#include <utility>
#include <ranges>
#include <concepts>

#if !__has_include(<stdexec/execution.hpp>)
#	error "nagisa.txrx verify_port requires the stdexec library"
#endif
#include <stdexec/execution.hpp>

#include <nagisa/txrx/environment.h>
