#ifndef __MainNode__
#define __MainNode__
#include<godot_cpp/classes/node.hpp>
namespace godot {
    class MainNode : public Node {
        GDCLASS(MainNode, Node);

        protected:
            static void _bind_methods();

        private:
            String path_cpp;
            String path_gd;

        private:
            void save(String path, String content);

        public:
            MainNode();

            void saveData(String type, String content);
    };
};

#endif