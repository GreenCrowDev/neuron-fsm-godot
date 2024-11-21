#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# Function to filter out conflicting flags
def remove_runtime_flags(env):
    flags_to_remove = ["/MD", "/MDd", "/MT", "/MTd"]
    for flag in flags_to_remove:
        while flag in env["CCFLAGS"]:
            env["CCFLAGS"].remove(flag)

# Manually control the runtime library
if env["platform"] == "windows":
    remove_runtime_flags(env)
    if env["use_static_cpp"]:
        if env["target"] == "editor":
            env.Append(CCFLAGS=["/MTd"])
        else:
            env.Append(CCFLAGS=["/MT"])
    else:
        if env["target"] == "editor":
            env.Append(CCFLAGS=["/MDd"])
        else:
            env.Append(CCFLAGS=["/MD"])

env_fsm = env.Clone()

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# Hardcoded neuron library path
# env_fsm.Append(CPPPATH=[neuron_libpath])
env_fsm.Append(LIBPATH=["D:/work/green_crow/dev_tools/libs/neuron-fsm/bin/Debug"])
env_fsm.Append(LIBS=["neuron_fsm"])

# tweak this if you want to use different folders, or more folders, to store your source code in.
env_fsm.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

if env_fsm["platform"] == "macos":
    library = env_fsm.SharedLibrary(
        "demo/addon/neuron_fsm/neuron_fsm.{}.{}.framework/neuron_fsm.{}.{}".format(
            env_fsm["platform"], env_fsm["target"], env_fsm["platform"], env_fsm["target"]
        ),
        source=sources,
    )
elif env_fsm["platform"] == "ios":
    if env_fsm["ios_simulator"]:
        library = env_fsm.StaticLibrary(
            "demo/addon/neuron_fsm/neuron_fsm.{}.{}.simulator.a".format(env_fsm["platform"], env_fsm["target"]),
            source=sources,
        )
    else:
        library = env_fsm.StaticLibrary(
            "demo/addon/neuron_fsm/neuron_fsm.{}.{}.a".format(env_fsm["platform"], env_fsm["target"]),
            source=sources,
        )
else:
    library = env_fsm.SharedLibrary(
        "demo/addon/neuron_fsm/neuron_fsm{}{}".format(env_fsm["suffix"], env_fsm["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
