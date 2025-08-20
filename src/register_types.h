#ifndef __RegisterTYPE__
#define __RegisterTYPE__
#include<godot_cpp/core/class_db.hpp>
using namespace godot;

#include "mainNode.h"
#include "variant_bench.h"

void register_types_init(ModuleInitializationLevel p_level);
void register_types_uninit(ModuleInitializationLevel p_level);

#endif