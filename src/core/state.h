#ifndef NEURON_FSM_GODOT_STATE_H
#define NEURON_FSM_GODOT_STATE_H

#include "../../../../libs/neuron-fsm/include/neuron_fsm/state.h"
#include "connection.h"
#include "state_behaviour.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/templates/list.hpp>

namespace ublas = neuron_fsm;

namespace godot::neuron_fsm_godot {

class Connection;

class State : public RefCounted {
	GDCLASS(State, RefCounted);

private:
	std::shared_ptr<ublas::State> state;
	Ref<StateBehaviour> behaviour;
	List<Ref<Connection>> connections;

protected:
	static void _bind_methods();

public:
	State();
	State(Ref<StateBehaviour> p_behaviour);

	std::shared_ptr<ublas::State> get_state() const;
	void set_behaviour(const Ref<StateBehaviour> &p_behaviour);
};

} // namespace godot::neuron_fsm_godot

#endif // NEURON_FSM_GODOT_STATE_H
