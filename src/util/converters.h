#ifndef NEURON_FSM_GODOT_CONVERTERS_H
#define NEURON_FSM_GODOT_CONVERTERS_H

#include <godot_cpp/variant/string.hpp>
#include <string>

namespace godot::nfsmg {

inline const std::string to_std_string(const godot::String &godot_string) {
	return godot_string.ascii().get_data();
}

} //namespace godot::nfsmg

#endif // NEURON_FSM_GODOT_CONVERTERS_H
