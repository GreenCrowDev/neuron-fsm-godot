#include "connection.h"

using namespace godot::neuron_fsm_godot;

void Connection::_bind_methods() {
}

void Connection::set_event(Callable p_callback) {
	event = p_callback;
}

void Connection::set_target(Ref<State> p_target) {
	target = p_target;
}
