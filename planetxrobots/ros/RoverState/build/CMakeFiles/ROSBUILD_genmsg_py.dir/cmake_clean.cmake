FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/RoverState/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/RoverState/msg/__init__.py"
  "../src/RoverState/msg/_Battery.py"
  "../src/RoverState/msg/_Range.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
