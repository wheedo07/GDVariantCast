#include "variant_bench.h"
#include<godot_cpp/classes/time.hpp>
using namespace godot;

void VariantBench::_bind_methods() {
    ClassDB::bind_method(D_METHOD("run_cpp", "iters"), &VariantBench::run_cpp);
}

Array VariantBench::run_cpp(int iters) {
    return Array::make(forBench(iters), varBench(iters));
}

int64_t VariantBench::forBench(int iters) {
    uint64_t start = Time::get_singleton()->get_ticks_usec();
    for(int i = 0; i < iters; i++) a = 1;
    return int64_t((Time::get_singleton()->get_ticks_usec() - start));
}

int64_t VariantBench::varBench(int iters) {
    uint64_t start = Time::get_singleton()->get_ticks_usec();
    for(int i = 0; i < iters; i++) {
        switch(a.get_type()) {
            case Variant::Type::INT:
                a = 0.1;
                break;
            case Variant::Type::FLOAT:
                a = Vector2();
                break;
            case Variant::Type::VECTOR2:
                a = Vector3();
                break;
            case Variant::Type::VECTOR3:
                a = Color();
                break;
            case Variant::Type::COLOR:
                a = String();
                break;
            case Variant::Type::STRING:
                a = PackedStringArray();
                break;
            case Variant::Type::PACKED_STRING_ARRAY:
                a = 1;
                break;
        }
    }
    return int64_t((Time::get_singleton()->get_ticks_usec() - start));
}