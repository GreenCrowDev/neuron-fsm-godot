#include "fsm.h"

using namespace godot::neuron_fsm_godot;

FSM::FSM() {
}

void FSM::_bind_methods() {
	ClassDB::bind_method(D_METHOD("test_func"), &FSM::test_func);
}

FSM::FSM(Ref<State> p_start_state) {
	current_state = p_start_state;
	fsm = std::make_shared<ublas::FSM>(current_state->get_state());
}

void FSM::_process(double delta) {
	fsm->tick();
}

int FSM::test_func() const {
	return 0;
}
