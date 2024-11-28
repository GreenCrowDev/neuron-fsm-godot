#include "state.h"

#include <godot_cpp/core/binder_common.hpp>

using namespace godot::neuron_fsm_godot;

State::State() {
}

void State::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_behaviour", "behaviour"), &State::set_behaviour);
	ClassDB::bind_method(D_METHOD("add_connection", "event", "target"), static_cast<void (State::*)(const Callable &, const Ref<State> &)>(&State::add_connection));
}

State::State(Ref<StateBehaviour> p_behaviour) {
	behaviour = p_behaviour;
	state = std::make_shared<ublas::State>(behaviour->get_behaviour());
}

std::shared_ptr<ublas::State> State::get_state() const {
	return state;
}

void State::set_behaviour(const Ref<StateBehaviour> &p_behaviour) {
	behaviour = p_behaviour;
	state = std::make_shared<ublas::State>(behaviour->get_behaviour());
}
