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
            int64_t run(int iters);
    };
}

#endif