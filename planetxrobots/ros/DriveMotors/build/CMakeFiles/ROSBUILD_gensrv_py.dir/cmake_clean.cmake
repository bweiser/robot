FILE(REMOVE_RECURSE
  "../srv_gen"
  "../src/DriveMotors/srv"
  "CMakeFiles/ROSBUILD_gensrv_py"
  "../src/DriveMotors/srv/__init__.py"
  "../src/DriveMotors/srv/_Move.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
