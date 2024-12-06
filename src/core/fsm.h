#ifndef NEURON_FSM_GODOT_FSM_H
#define NEURON_FSM_GODOT_FSM_H

#include "state.h"
#include <neuron_fsm/fsm.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <memory>

namespace nfsm = neuron_fsm;

namespace godot::nfsmg {

class FSM : public RefCounted {
	GDCLASS(FSM, RefCounted);

public:
	void register_state(const String &p_name, const Ref<FSMState> &p_state);
	void set_starting_state(const String &p_name);
	void add_transition(const String &p_state, const String &p_event, const String &p_target);

	void tick() const;
	void lock();
	void start();

protected:
	static void _bind_methods();

private:
	nfsm::FSM fsm;
};

} // namespace godot::nfsmg

#endif // NEURON_FSM_GODOT_FSM_H
