#include "fsm.h"

using namespace godot::neuron_fsm_godot;

void FSM::_bind_methods() {
	ClassDB::bind_method(D_METHOD("register_state", "name", "state"), &FSM::register_state);
	ClassDB::bind_method(D_METHOD("tick"), &FSM::tick);
	ClassDB::bind_method(D_METHOD("add_signal_connection", "signal", "target"), &FSM::add_signal_connection);
}

FSM::FSM() :
		fsm(std::make_unique<ublas::FSM>()) {
}

void FSM::tick() const {
	fsm->tick();
}

void FSM::register_state(const StringName &p_name, const Ref<State> &p_state) {
	fsm->
}

void FSM::add_signal_connection(const Signal &p_signal, const Ref<State> &p_target) {
	// When p_signal is called, make the transition.
}
