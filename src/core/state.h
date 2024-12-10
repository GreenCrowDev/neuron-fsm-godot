#ifndef NEURON_FSM_GODOT_STATE_H
#define NEURON_FSM_GODOT_STATE_H

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot::nfsmg {

class FSMState : public RefCounted {
	GDCLASS(FSMState, RefCounted);

protected:
	static void _bind_methods();
};

} // namespace godot::nfsmg

#endif // NEURON_FSM_GODOT_STATE_H
