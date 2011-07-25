LINK_DIRECTORIES(/usr/local/lib)

add_executable(iliade iliade.cpp warrior.cpp army.cpp unit_id.cpp)
TARGET_LINK_LIBRARIES(iliade utilite yaml-cpp)
