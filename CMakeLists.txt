cmake_minimum_required (VERSION 3.0)
project (shooter)

find_package(OpenGL REQUIRED)

set(ALL_LIBS
	${OPENGL_LIBRARY}
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

add_executable(shooter
    main.cpp
    shader.cpp
    enemy.cpp
    gen.cpp

    enemy.vertexshader
    enemy.fragmentshader    
)
target_link_libraries(shooter
	${ALL_LIBS}
    -lglfw
    -lGLEW
)
add_custom_command(
    TARGET shooter POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "shooter" "../shooter"
    )

