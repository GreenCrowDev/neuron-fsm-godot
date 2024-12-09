#include "state.h"

#include <godot_cpp/core/binder_common.hpp>

using namespace godot::nfsmg;

void FSMState::_bind_methods() {
	ADD_SIGNAL(MethodInfo("on_enter"));
	ADD_SIGNAL(MethodInfo("on_process", PropertyInfo(Variant::FLOAT, "delta")));
	ADD_SIGNAL(MethodInfo("on_exit"));
}
