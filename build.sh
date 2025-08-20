#!/bin/bash
is=1

if (( $is == 1 )); then
    find bin ! -name run.py -exec rm {} \;
    scons platform=linux build_library=no &&
    scons platform=windows build_library=no target=template_release && 
    godot --headless --path ./godot/ --export-release "Windows"
else
    scons platform=windows build_library=no
fi