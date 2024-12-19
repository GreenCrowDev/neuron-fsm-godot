#include "fsm.h"
#include "../util/converters.h"
#include "../util/errors.h"

using namespace godot;
using namespace godot::nfsmg;

void FSM::_bind_methods() {
	ClassDB::bind_method(D_METHOD("register_state", "name", "state"), &FSM::register_state);
	ClassDB::bind_method(D_METHOD("get_state", "name"), &FSM::get_state);
	ClassDB::bind_method(D_METHOD("add_transition", "state", "event", "target"), &FSM::add_transition);

	ClassDB::bind_method(D_METHOD("get_starting_state_name"), &FSM::get_starting_state_name);
	ClassDB::bind_method(D_METHOD("get_starting_state"), &FSM::get_starting_state);
	ClassDB::bind_method(D_METHOD("set_starting_state", "name"), &FSM::set_starting_state);
	ClassDB::bind_method(D_METHOD("get_current_state_name"), &FSM::get_current_state_name);
	ClassDB::bind_method(D_METHOD("get_current_state"), &FSM::get_current_state);
	ClassDB::bind_method(D_METHOD("change_state", "state", "silent"), &FSM::change_state, DEFVAL(false));

	ClassDB::bind_method(D_METHOD("start"), &FSM::start);
	ClassDB::bind_method(D_METHOD("stop", "silent"), &FSM::stop, DEFVAL(false));
	ClassDB::bind_method(D_METHOD("play"), &FSM::play);
	ClassDB::bind_method(D_METHOD("pause"), &FSM::pause);
	ClassDB::bind_method(D_METHOD("reset"), &FSM::reset);

	ClassDB::bind_method(D_METHOD("lock"), &FSM::lock);
	ClassDB::bind_method(D_METHOD("unlock"), &FSM::unlock);

	ClassDB::bind_method(D_METHOD("tick", "delta"), &FSM::tick);

	ClassDB::bind_method(D_METHOD("process_event", "event"), &FSM::process_event);

	ClassDB::bind_method(D_METHOD("is_running"), &FSM::is_running);
	ClassDB::bind_method(D_METHOD("is_locked"), &FSM::is_locked);
}

void FSM::register_state(const String &p_name, const Ref<FSMState> &p_state) {
	NFSMG_ASSERT_RETURN_MSG(!fsm.is_locked(), "States cannot be registered while the FSM is locked.");
	NFSMG_ASSERT_RETURN_MSG(!p_name.is_empty(), "State name cannot be empty.");
	NFSMG_ASSERT_RETURN_MSG(!p_state.is_null(), "State cannot be null.");

	Ref<FSMState> map_state = state_map.get_or_add(p_name, p_state);
	NFSMG_ASSERT_RETURN_MSG(map_state == p_state, ("State '" + to_std_string(p_name) + "' is already registered.").c_str());

	std::shared_ptr<nfsm::State> state = std::make_shared<nfsm::State>();
	state->add_on_enter_callback(to_std_string(p_name), [p_state]() { p_state->emit_signal("on_enter"); });
	state->add_on_process_callback(to_std_string(p_name), [p_state](double delta) { p_state->emit_signal("on_process", delta); });
	state->add_on_exit_callback(to_std_string(p_name), [p_state]() { p_state->emit_signal("on_exit"); });

	fsm.register_state(to_std_string(p_name), state);
}

Ref<FSMState> FSM::get_state(const String &p_name) {
	NFSMG_ASSERT_RETURN_V_MSG(!p_name.is_empty(), Ref<FSMState>(), "State name cannot be empty.");
	Ref<FSMState> state = state_map.get(p_name, Ref<FSMState>());
	NFSMG_ASSERT_RETURN_V_MSG(!state.is_null(), Ref<FSMState>(), ("State '" + to_std_string(p_name) + "' does not exist.").c_str());
	return state;
}

void FSM::add_transition(const String &p_state, const String &p_event, const String &p_target) {
	NFSMG_ASSERT_RETURN_MSG(!p_state.is_empty(), "State name cannot be empty.");
	NFSMG_ASSERT_RETURN_MSG(!p_event.is_empty(), "Event name cannot be empty.");
	NFSMG_ASSERT_RETURN_MSG(!p_target.is_empty(), "Target state name cannot be empty.");

	fsm.add_transition(to_std_string(p_state), to_std_string(p_event), to_std_string(p_target));
}

String FSM::get_starting_state_name() const {
	auto result = fsm.get_starting_state_name();
	NFSMG_ASSERT_RETURN_V_MSG(result, String(), "Starting state name does not exist.");
	return result.value().c_str();
}

Ref<FSMState> FSM::get_starting_state() const {
	auto result = fsm.get_starting_state_name();
	NFSMG_ASSERT_RETURN_V_MSG(result, Ref<FSMState>(), "Starting state name does not exist.");
	return state_map[result.value().c_str()];
}

void FSM::set_starting_state(const String &p_name) {
	NFSMG_ASSERT_RETURN_MSG(!p_name.is_empty(), "State name cannot be empty.");

	fsm.set_starting_state(to_std_string(p_name));
}

String FSM::get_current_state_name() const {
	auto result = fsm.get_current_state_name();
	NFSMG_ASSERT_RETURN_V_MSG(result, String(), "Current state name does not exist.");
	return result.value().c_str();
}

Ref<FSMState> FSM::get_current_state() const {
	auto result = fsm.get_current_state_name();
	NFSMG_ASSERT_RETURN_V_MSG(result, Ref<FSMState>(), "Current state name does not exist.");
	return state_map[result.value().c_str()];
}

void FSM::change_state(const String &p_name, const bool p_silent) {
	NFSMG_ASSERT_RETURN_MSG(!p_name.is_empty(), "State name cannot be empty.");
	fsm.change_state(to_std_string(p_name));
}

void FSM::start() {
	fsm.start();
}

void FSM::stop(const bool p_silent) {
	fsm.stop();
}

void FSM::play() {
	fsm.play();
}

void FSM::pause() {
	fsm.pause();
}

void FSM::reset() {
	fsm.reset();
}

void FSM::lock() {
	fsm.lock();
}

void FSM::unlock() {
	fsm.unlock();
}

void FSM::tick(double p_delta) const {
	fsm.tick(p_delta);
}

void FSM::process_event(const String &p_event) {
	NFSMG_ASSERT_RETURN_MSG(!p_event.is_empty(), "Event name cannot be empty.");

	fsm.process_event(to_std_string(p_event));
}
