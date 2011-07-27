include_directories( ${Boost_INCLUDE_DIR} )

LINK_DIRECTORIES(/usr/local/lib)

add_executable(iliade iliade.cpp warrior.cpp warrior_cfg.cpp army.cpp unit_id.cpp)
TARGET_LINK_LIBRARIES(iliade utilite yaml-cpp)
