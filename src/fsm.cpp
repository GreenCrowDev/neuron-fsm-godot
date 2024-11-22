#include "fsm.h"

using namespace godot::neuron_fsm_godot;

void FSM::_bind_methods() {
	ClassDB::bind_method(D_METHOD("test_func"), &FSM::test_func);
}

FSM::FSM() {
	fsm = new ublas::FSM();
}

FSM::~FSM() {
	delete fsm;
}

int FSM::test_func() const {
	return fsm->get_state_count();
}
