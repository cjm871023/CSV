cmake_minimum_required(VERSION 3.10)
project(IceServer)




add_executable(IceServer demo.cpp IceServer.cpp )



target_link_libraries(IceServer Ice pthread  )


