cmake_minimum_required(VERSION 3.0.0)
project(simple-shell VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(lib/)

add_executable(simple-shell shell.c
  lib/__getline.c
  lib/_pow_recursion.c
  lib/_realloc.c
  lib/add_input.c
  lib/add_node_list.c
  lib/change_directory.c
  lib/complete_path.c
  lib/double_pointer.c
  lib/env_variables.c
  lib/echo.c
  lib/execute_command.c
  lib/execute_decision.c
  lib/exit_command.c
  lib/find_control.c
  lib/free_list.c
  lib/get_builtin_function.c
  lib/help.c
  lib/parse_string.c
  lib/print_working_directory.c
  lib/sub_main.c
  lib/prompt.c
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
