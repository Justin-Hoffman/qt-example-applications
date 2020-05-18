function(package_add_test TESTNAME)
  add_executable(${TESTNAME} ${ARGN})
  target_link_libraries(${TESTNAME} ExampleTemplateLib GTest::GTest GTest::Main)
  add_test(NAME ${TESTNAME} COMMAND ${TESTNAME} WORKING_DIRECTORY ${CMAKE_PROJECT_BINARY_DIR})
  set_target_properties(${TESTNAME} PROPERTIES FOLDER test)
endfunction(package_add_test)

package_add_test(ExampleTest ${CMAKE_CURRENT_SOURCE_DIR}/src/ExampleTest.cpp)
