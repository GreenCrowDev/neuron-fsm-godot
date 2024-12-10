#ifndef NEURON_FSM_GODOT_ERRORS_H
#define NEURON_FSM_GODOT_ERRORS_H

#include "io/log.h"
#include <iostream>

// Abnormally terminate the program.
#ifdef _MSC_VER
#define NFSMG_GENERATE_TRAP() __debugbreak()
#else
#define NFSMG_GENERATE_TRAP() __builtin_trap()
#endif

// The following macros check a condition. If it fails, they print a message and crash the program.

#define NFSMG_ASSERT_MSG(cond, msg)                                                                                           \
	if (!(cond)) {                                                                                                            \
		godot::nfsmg::print_error("FATAL: Assertion failed: \"" #cond "\" is false.", msg, __FUNCTION__, __FILE__, __LINE__); \
		godot::nfsmg::flush_stdout();                                                                                         \
		NFSMG_GENERATE_TRAP();                                                                                                \
	} else                                                                                                                    \
		((void)0)

#define NFSMG_ASSERT(cond) NFSMG_ASSERT_MSG(cond, "")

// The following macros check a condition. If it fails, they print a message, then return or continue.

#define NFSMG_INTERNAL_ASSERT_ACT(cond, act, msg)                                                                      \
	if (!(cond)) {                                                                                                     \
		godot::nfsmg::print_error("Assertion failed: \"" #cond "\" is false.", msg, __FUNCTION__, __FILE__, __LINE__); \
		act;                                                                                                           \
	} else                                                                                                             \
		((void)0)

#define NFSMG_ASSERT_RETURN(cond) NFSMG_INTERNAL_ASSERT_ACT(cond, return, "")
#define NFSMG_ASSERT_RETURN_MSG(cond, msg) NFSMG_INTERNAL_ASSERT_ACT(cond, return, msg)
#define NFSMG_ASSERT_RETURN_V(cond, retval) NFSMG_INTERNAL_ASSERT_ACT(cond, return retval, "")
#define NFSMG_ASSERT_RETURN_V_MSG(cond, retval, msg) NFSMG_INTERNAL_ASSERT_ACT(cond, return retval, msg)
#define NFSMG_ASSERT_CONTINUE(cond) NFSMG_INTERNAL_ASSERT_ACT(cond, continue, "")
#define NFSMG_ASSERT_CONTINUE_MSG(cond, msg) NFSMG_INTERNAL_ASSERT_ACT(cond, continue, msg)

#endif // NEURON_FSM_GODOT_ERRORS_H
