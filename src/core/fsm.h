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
	std::shared_ptr<ublas::FSM> fsm;
	Ref<State> current_state;

protected:
	static void _bind_methods();

public:
	FSM();
	FSM(Ref<State> p_start_state);

	void _notification(int p_what);
	void _process(double p_delta);

	void tick() const;

	void set_state(const Ref<State> &p_state);
	int test_func() const;
};

} // namespace godot::neuron_fsm_godot

#endif // NEURON_FSM_GODOT_FSM_H
