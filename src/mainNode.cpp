#include "mainNode.h"
#include<sstream>
#include<fstream>
#include<filesystem>
#include<godot_cpp/classes/engine.hpp>
using namespace godot;
namespace fs = std::filesystem;

MainNode::MainNode() {
    if(Engine::get_singleton()->is_editor_hint()) return;
    String user_dir = fs::current_path().generic_string().c_str();
    path_gd  = user_dir.path_join("variantCast_gd.csv");
    path_cpp = user_dir.path_join("variantCast_cpp.csv");

    String content = "iters,us_no_cast,us_cast_assign";
    if(!fs::exists(path_gd.utf8().get_data())) save(path_gd, content);
    if(!fs::exists(path_cpp.utf8().get_data())) save(path_cpp, content);
}

void MainNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("saveData", "type", "content"), &MainNode::saveData);
}

void MainNode::save(String path, String content) {
    std::ofstream file(path.utf8().get_data(), std::ios::binary | std::ios::app);
    if(file.is_open()) {
        file << content.utf8().get_data() << std::endl;
        file.close();
    }else {
        ERR_PRINT("없는 경로가 들어왔습니다");
    }
}

void MainNode::saveData(String type, String content) {
    if(type == "cpp") {
        save(path_cpp, content);
    }else if(type == "gd") {
        save(path_gd, content);
    }else {
        ERR_PRINT("다른 타입이 들어왔습니다 (유효 타입 [cpp, gd])");
    }
}