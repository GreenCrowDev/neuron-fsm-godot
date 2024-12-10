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
	Ref<FSMState> get_state(const String &p_name);
	void add_transition(const String &p_state, const String &p_event, const String &p_target);

	String get_starting_state_name() const;
	Ref<FSMState> get_starting_state() const;
	void set_starting_state(const String &p_name);
	String get_current_state_name() const;
	Ref<FSMState> get_current_state() const;
	void change_state(const String &p_name, const bool p_silent = false);

	void start();
	void stop(const bool p_silent = false);
	void play();
	void pause();
	void reset();

	void lock();
	void unlock();

	void tick(double p_delta) const;

	void process_event(const String &p_event);

	bool is_running() const { return fsm.is_running(); }
	bool is_locked() const { return fsm.is_locked(); }

protected:
	static void _bind_methods();

private:
	nfsm::FSM fsm;
	Dictionary state_map;
};

} // namespace godot::nfsmg

#endif // NEURON_FSM_GODOT_FSM_H
