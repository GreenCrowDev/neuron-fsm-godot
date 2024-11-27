#include "state.h"

#include <godot_cpp/core/binder_common.hpp>

using namespace godot::neuron_fsm_godot;

State::State() {
}

void State::_bind_methods() {
}

State::State(Ref<StateBehaviour> p_behaviour) {
	behaviour = p_behaviour;
	state = std::make_shared<ublas::State>(behaviour->get_behaviour());
}

std::shared_ptr<ublas::State> State::get_state() const {
	return state;
}
