# Build example
add_executable(aufgabe1
  beispiel.cpp)
target_link_libraries(aufgabe1
  
  m)
#add_dependencies(aufgabe1  ${COPY_BINARY})

add_executable(aufgabe2bis4
  aufgabe2bis4.cpp)
target_link_libraries(aufgabe2bis4

  m)
#add_dependencies(aufgabe2bis4 ${COPY_BINARY})

add_executable(aufgabe5
  aufgabe5.cpp)
target_link_libraries(aufgabe5

  m)
#add_dependencies(aufgabe5 ${COPY_BINARY})

add_executable(aufgabe7
  aufgabe7.cpp
  circle.cpp)
target_link_libraries(aufgabe7

  m)
#add_dependencies(aufgabe7 ${COPY_BINARY})




