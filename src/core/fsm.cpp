#include "fsm.h"

using namespace godot::neuron_fsm_godot;

FSM::FSM() {
}

void FSM::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_state", "state"), &FSM::set_state);
	ClassDB::bind_method(D_METHOD("tick"), &FSM::tick);
	ClassDB::bind_method(D_METHOD("test_func"), &FSM::test_func);
}

FSM::FSM(Ref<State> p_start_state) {
	current_state = p_start_state;
	fsm = std::make_shared<ublas::FSM>(current_state->get_state());
}

void FSM::_notification(int p_what) {
}

void FSM::_process(double delta) {
	fsm->tick();
}

void FSM::tick() const {
	fsm->tick();
}

void FSM::set_state(const Ref<State> &p_state) {
	current_state = p_state;
	fsm = std::make_shared<ublas::FSM>(current_state->get_state());
}

int FSM::test_func() const {
	return 0;
}
