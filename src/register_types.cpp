#include "register_types.h"

#include <gdextension_interface.h>

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "core/fsm.h"
#include "core/state.h"

using namespace godot::nfsmg;

void initialize_neuron_fsm_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		GDREGISTER_CLASS(FSM);
		GDREGISTER_CLASS(FSMState);
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
