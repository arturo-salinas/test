cmake_minimum_required(VERSION 3.0.0)
project(BFX_Power_Scaling_VERSION_0.1.0)

add_executable(testBroker test/testBroker.cc src/Broker.cc src/Carrier.cc)
target_link_libraries(testBroker gtest pthread gmock)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
