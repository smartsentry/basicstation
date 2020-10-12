add_executable(unit-tests "")

target_sources(
    unit-tests
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/cpputest_all.cpp
    ${CMAKE_CURRENT_LIST_DIR}/utest-hello.cpp
)

target_link_libraries(
	unit-tests
	PRIVATE
    CppUTest
    CppUTestExt

    s2core
)