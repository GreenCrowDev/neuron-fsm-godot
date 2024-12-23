#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# Set build_type to "Debug" or "Release".
if env["target"] in ("editor", "template_debug"):
    build_type = "Debug"
elif env["target"] == "template_release":
    build_type = "Release"

# Thirdparty dependencies.
env = SConscript("thirdparty/SConstruct", exports=["env", "build_type"])

env_fsm = env.Clone()

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# Tweak this if you want to use different folders, or more folders, to store your source code in.
env_fsm.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")
sources += Glob("src/core/*.cpp")
sources += Glob("src/util/*.cpp")
sources += Glob("src/util/io/*.cpp")

if env_fsm["platform"] == "macos":
    library = env_fsm.SharedLibrary(
        "demo/addons/neuron_fsm/{}.framework/libneuron_fsm.{}.{}".format(
            env_fsm["platform"], env_fsm["platform"], env_fsm["target"]
        ),
        source=sources,
    )
elif env_fsm["platform"] == "ios":
    if env_fsm["ios_simulator"]:
        library = env_fsm.StaticLibrary(
            "demo/addons/neuron_fsm/ios.framework/libneuron_fsm.{}.{}.simulator".format(env_fsm["platform"], env_fsm["target"]),
            source=sources,
        )
    else:
        library = env_fsm.StaticLibrary(
            "demo/addons/neuron_fsm/ios.framework/libneuron_fsm.{}.{}".format(env_fsm["platform"], env_fsm["target"]),
            source=sources,
        )
else:
    library = env_fsm.SharedLibrary(
        "demo/addons/neuron_fsm/libneuron_fsm{}{}".format(env_fsm["suffix"], env_fsm["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
