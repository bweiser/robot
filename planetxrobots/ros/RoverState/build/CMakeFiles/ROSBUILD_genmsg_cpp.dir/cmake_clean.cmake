FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/RoverState/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/RoverState/Battery.h"
  "../msg_gen/cpp/include/RoverState/Range.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
