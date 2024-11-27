#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

env_fsm = env.Clone()

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# Hardcoded neuron library path.
# env_fsm.Append(CPPPATH=[neuron_libpath])
env_fsm.Append(LIBPATH=["D:/work/green_crow/dev_tools/libs/neuron-fsm/bin/Debug"])
env_fsm.Append(LIBS=["neuron_fsm"])

# tweak this if you want to use different folders, or more folders, to store your source code in.
env_fsm.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")
sources += Glob("src/core/*.cpp")

if env_fsm["platform"] == "macos":
    library = env_fsm.SharedLibrary(
        "demo/addons/neuron_fsm/neuron_fsm.{}.{}.framework/neuron_fsm.{}.{}".format(
            env_fsm["platform"], env_fsm["target"], env_fsm["platform"], env_fsm["target"]
        ),
        source=sources,
    )
elif env_fsm["platform"] == "ios":
    if env_fsm["ios_simulator"]:
        library = env_fsm.StaticLibrary(
            "demo/addons/neuron_fsm/neuron_fsm.{}.{}.simulator.a".format(env_fsm["platform"], env_fsm["target"]),
            source=sources,
        )
    else:
        library = env_fsm.StaticLibrary(
            "demo/addons/neuron_fsm/neuron_fsm.{}.{}.a".format(env_fsm["platform"], env_fsm["target"]),
            source=sources,
        )
else:
    library = env_fsm.SharedLibrary(
        "demo/addons/neuron_fsm/neuron_fsm{}{}".format(env_fsm["suffix"], env_fsm["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
