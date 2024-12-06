#include "fsm.h"
#include "../util/converters.h"
#include "../util/errors.h"

using namespace godot::nfsmg;

void FSM::_bind_methods() {
	ClassDB::bind_method(D_METHOD("register_state", "name", "state"), &FSM::register_state);
	ClassDB::bind_method(D_METHOD("set_starting_state", "name"), &FSM::set_starting_state);
	ClassDB::bind_method(D_METHOD("add_transition", "state", "event", "target"), &FSM::add_transition);

	ClassDB::bind_method(D_METHOD("tick"), &FSM::tick);
	ClassDB::bind_method(D_METHOD("lock"), &FSM::lock);
	ClassDB::bind_method(D_METHOD("start"), &FSM::start);
}

void FSM::register_state(const String &p_name, const Ref<FSMState> &p_state) {
	NFSMG_ASSERT_RETURN_MSG(!p_name.is_empty(), "State name cannot be empty.");
	NFSMG_ASSERT_RETURN_MSG(!p_state.is_null(), "State cannot be null.");

	std::shared_ptr<nfsm::State> state = std::make_shared<nfsm::State>();
	state->add_on_enter_callback([&p_state]() { p_state->emit_signal("on_enter"); });
	state->add_on_process_callback([&p_state]() { p_state->emit_signal("on_process"); });
	state->add_on_exit_callback([&p_state]() { p_state->emit_signal("on_exit"); });

	fsm.register_state(to_std_string(p_name), state);
}

void FSM::set_starting_state(const String &p_name) {
	NFSMG_ASSERT_RETURN_MSG(!p_name.is_empty(), "State name cannot be empty.");

	fsm.set_starting_state(to_std_string(p_name));
}

void FSM::add_transition(const String &p_state, const String &p_event, const String &p_target) {
	NFSMG_ASSERT_RETURN_MSG(!p_state.is_empty(), "State name cannot be empty.");
	NFSMG_ASSERT_RETURN_MSG(!p_event.is_empty(), "Event name cannot be empty.");
	NFSMG_ASSERT_RETURN_MSG(!p_target.is_empty(), "Target state name cannot be empty.");

	fsm.add_transition(to_std_string(p_state), to_std_string(p_event), to_std_string(p_target));
}

void FSM::tick() const {
	fsm.tick();
}

void FSM::lock() {
	fsm.lock();
}

void FSM::start() {
	fsm.start();
}
