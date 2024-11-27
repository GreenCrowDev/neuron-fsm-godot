#ifndef NEURON_FSM_GODOT_STATE_H
#define NEURON_FSM_GODOT_STATE_H

#include "../../../../libs/neuron-fsm/include/neuron_fsm/state.h"
#include "state_behaviour.h"
#include <godot_cpp/classes/ref_counted.hpp>

namespace ublas = neuron_fsm;

namespace godot::neuron_fsm_godot {

class State : public RefCounted {
	GDCLASS(State, RefCounted);

private:
	State();

	std::shared_ptr<ublas::State> state;
	Ref<StateBehaviour> behaviour;

protected:
	static void _bind_methods();

public:
	State(Ref<StateBehaviour> p_behaviour);

	std::shared_ptr<ublas::State> get_state() const;
};

} // namespace godot::neuron_fsm_godot

#endif // NEURON_FSM_GODOT_STATE_H
