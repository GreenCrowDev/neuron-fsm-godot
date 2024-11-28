#include "state_behaviour.h"

using namespace godot::neuron_fsm_godot;

void StateBehaviour::_bind_methods() {
	ADD_SIGNAL(MethodInfo("on_enter"));
	ADD_SIGNAL(MethodInfo("on_process"));
	ADD_SIGNAL(MethodInfo("on_exit"));
}

StateBehaviour::StateBehaviour() {
	behaviour = std::make_shared<neuron_fsm::StateBehaviour>();

	// Add signal callbacks.

	behaviour->add_on_enter_callback([this]() {
		emit_signal("on_enter");
	});

	behaviour->add_on_process_callback([this]() {
		emit_signal("on_process");
	});

	behaviour->add_on_exit_callback([this]() {
		emit_signal("on_exit");
	});
}

std::shared_ptr<ublas::StateBehaviour> StateBehaviour::get_behaviour() const {
	return behaviour;
}
