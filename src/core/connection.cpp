#include "connection.h"

using namespace godot::neuron_fsm_godot;

void Connection::_bind_methods() {
}

Connection::Connection() {
}

Connection::Connection(const Callable &p_event, const Ref<State> &p_target) :
		event(p_event), target(p_target) {}

void Connection::set_event(const Callable &p_event) {
	event = p_event;
}

void Connection::set_target(const Ref<State> &p_target) {
	target = p_target;
}
