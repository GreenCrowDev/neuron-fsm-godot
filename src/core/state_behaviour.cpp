#include "state_behaviour.h"

using namespace godot::neuron_fsm_godot;

void StateBehaviour::_bind_methods() {
	ADD_SIGNAL(MethodInfo("on_enter"));
}

StateBehaviour::StateBehaviour() {
	behaviour = std::make_shared<neuron_fsm::StateBehaviour>();
}

std::shared_ptr<ublas::StateBehaviour> StateBehaviour::get_behaviour() const {
	return behaviour;
}
