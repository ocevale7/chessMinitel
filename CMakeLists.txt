cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB PIECES_SRC "src/pieces/*.cpp")
file(GLOB TOOLS_SRC "src/tools/*.cpp")

add_executable(
    main
    src/Piece.cpp
    src/Plateau.cpp
    src/Game.cpp
    src/Main.cpp
    ${PIECES_SRC}
    ${TOOLS_SRC}
)

target_include_directories(main PRIVATE include)
target_compile_features(main PRIVATE cxx_std_20)
target_compile_options(main PRIVATE
    -Wall        # tous les warnings classiques
    -Wextra      # warnings supplémentaires utiles
    -Werror      # transforme les warnings en erreurs
    -pedantic    # pour la conformité stricte au standard C++
)


# add_custom_target(main
#     COMMAND ./bin/main
# )