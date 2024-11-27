#ifndef NEURON_FSM_GODOT_CONNECTION_H
#define NEURON_FSM_GODOT_CONNECTION_H

#include "../../../../libs/neuron-fsm/include/neuron_fsm/state.h"
#include "state.h"
#include <godot_cpp/classes/ref_counted.hpp>

namespace ublas = neuron_fsm;

namespace godot::neuron_fsm_godot {

class State;

class Connection : public RefCounted {
	GDCLASS(Connection, RefCounted);

private:
	std::shared_ptr<ublas::State::Connection> connection;

	Callable event;
	Ref<State> target;

protected:
	static void _bind_methods();

public:
	Connection();
	Connection(const Callable &p_event, const Ref<State> &p_target);

	void set_event(const Callable &p_event);
	void set_target(const Ref<State> &p_target);
};

} // namespace godot::neuron_fsm_godot

#endif // NEURON_FSM_GODOT_CONNECTION_H
