#ifndef NEURON_FSM_GODOT_FSM_H
#define NEURON_FSM_GODOT_FSM_H

#include "../../../../libs/neuron-fsm/include/neuron_fsm/fsm.h"
#include "state.h"
#include <godot_cpp/classes/ref_counted.hpp>

namespace ublas = neuron_fsm;

namespace godot::neuron_fsm_godot {

class FSM : public RefCounted {
	GDCLASS(FSM, RefCounted);

private:
	std::unique_ptr<ublas::FSM> fsm;

protected:
	static void _bind_methods();

public:
	FSM();

	void tick() const;

	void register_state(const StringName &p_name, const Ref<State> &p_state);
	void add_signal_connection(const Signal &p_signal, const Ref<State> &p_target);
};

} // namespace godot::neuron_fsm_godot

#endif // NEURON_FSM_GODOT_FSM_H
