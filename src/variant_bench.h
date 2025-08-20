#ifndef __VariantBench__
#define __VariantBench__
#include<godot_cpp/classes/node.hpp>
namespace godot {
    class VariantBench : public Node {
        GDCLASS(VariantBench, Node);

        protected:
            static void _bind_methods();

        private:
            Variant a = 1;

        public:
            Array run_cpp(int iters);
            int64_t varBench(int iters);
            int64_t forBench(int iters);
    };
}

#endif