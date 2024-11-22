#include "register_types.h"

#include <gdextension_interface.h>

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "fsm.h"
#include "state.h"

using namespace godot;
using namespace godot::neuron_fsm_godot;

void initialize_neuron_fsm_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE || p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
		GDREGISTER_CLASS(State);
		GDREGISTER_CLASS(FSM);
	}
}

void uninitialize_neuron_fsm_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT neuron_fsm_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_neuron_fsm_module);
	init_obj.register_terminator(uninitialize_neuron_fsm_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
