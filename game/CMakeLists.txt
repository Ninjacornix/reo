add_library(reo_game STATIC
    formats/nbd_parser.cpp
    formats/amo_parser.cpp
    formats/nbd_renderer.cpp
    formats/rdt_parser.cpp
    formats/afs_archive.cpp
)

target_include_directories(reo_game PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)
