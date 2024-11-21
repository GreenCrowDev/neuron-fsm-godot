#ifndef NEURON_FSM_GODOT_STATE_H
#define NEURON_FSM_GODOT_STATE_H

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot::neuron_fsm_godot {

class State : public RefCounted {
	GDCLASS(State, RefCounted);

private:
protected:
	static void _bind_methods();

public:
};

} //namespace godot::neuron_fsm_godot

#endif // NEURON_FSM_GODOT_STATE_H
