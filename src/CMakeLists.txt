add_executable(intro main.c test.c)
target_link_libraries(
  intro PRIVATE project_options project_warnings
  )

target_include_directories(intro PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_splint(intro main.c)
