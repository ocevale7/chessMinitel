cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(testAff tests/testAffichage.cpp src/Piece.cpp src/Plateau.cpp)

target_include_directories(testAff PRIVATE include)
target_compile_features(testAff PRIVATE cxx_std_20)
target_compile_options(testAff PRIVATE
    -Wall        # tous les warnings classiques
    -Wextra      # warnings supplémentaires utiles
    -Werror      # transforme les warnings en erreurs
    -pedantic    # pour la conformité stricte au standard C++
)


# add_custom_target(testAff
#     COMMAND ./bin/testAff
# )