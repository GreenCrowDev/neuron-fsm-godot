#ifndef NEURON_FSM_GODOT_STATE_BEHAVIOUR
#define NEURON_FSM_GODOT_STATE_BEHAVIOUR

#include "../../../../libs/neuron-fsm/include/neuron_fsm/state_behaviour.h"
#include <godot_cpp/classes/ref_counted.hpp>

namespace ublas = neuron_fsm;

namespace godot::neuron_fsm_godot {

class StateBehaviour : public RefCounted {
	GDCLASS(StateBehaviour, RefCounted);

private:
	std::shared_ptr<ublas::StateBehaviour> behaviour;

protected:
	static void _bind_methods();

public:
	StateBehaviour();

	std::shared_ptr<ublas::StateBehaviour> get_behaviour() const;
};

} // namespace godot::neuron_fsm_godot

#endif // NEURON_FSM_GODOT_STATE_BEHAVIOUR
