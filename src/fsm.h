#ifndef NEURON_FSM_GODOT_FSM_H
#define NEURON_FSM_GODOT_FSM_H

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot::neuron_fsm {

class FSM : public RefCounted {
    GDCLASS(FSM, RefCounted);

private:

protected:
	static void _bind_methods();

public:

};

}

#endif // NEURON_FSM_GODOT_FSM_H