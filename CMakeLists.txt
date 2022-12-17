
cmake_minimum_required(VERSION 3.10)
project(FABRIK VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Add OpenGL
# find_package(OpenGL REQUIRED)
# include_directories( ${OPENGL_INCLUDE_DIRS} )


# find_package(GLM REQUIRED)
# include_directories( ${GLM_INCLUDE_DIRS} )

# #GLAD
# include_directories(glad/include)

#SOURCE FILES
file(GLOB_RECURSE SRC_FILES src/*)
add_executable(FABRIK 
	${SRC_FILES}
	#glad/src/glad.c
	)

# target_include_directories(TransmittanceEffects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})

# #assimp
# add_subdirectory(assimp)
# target_include_directories(${PROJECT_NAME} PUBLIC assimp/include)
# target_link_directories(${PROJECT_NAME} PRIVATE assimp/src)
# target_link_libraries(${PROJECT_NAME} assimp)


# #freeglut
# add_subdirectory(freeglut REQUIRED)
# target_include_directories(${PROJECT_NAME} PUBLIC freeglut/include)
# target_link_directories(${PROJECT_NAME} PRIVATE freeglut/src)
# target_link_libraries(${PROJECT_NAME} freeglut)


# #glfw
# add_subdirectory(glfw)
# target_include_directories(${PROJECT_NAME} PUBLIC glfw/include)
# target_link_directories(${PROJECT_NAME} PRIVATE glfw/src)
# target_link_libraries(${PROJECT_NAME} glfw)


# #stb
# target_include_directories(${PROJECT_NAME} PUBLIC stb)

# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Shaders DESTINATION ${CMAKE_BINARY_DIR})
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Textures DESTINATION ${CMAKE_BINARY_DIR})
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Models DESTINATION ${CMAKE_BINARY_DIR})