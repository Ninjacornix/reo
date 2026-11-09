#include "scene_matrix_tables.hpp"
#include <bit>
namespace reo::native::gameplay_scenario {
#include "scene_matrix_program_tables.inc"
const SceneMatrixTables& stock_scene_matrix_tables()noexcept{return tables;}
}
