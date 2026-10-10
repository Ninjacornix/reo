#include "MiniTest.h"

#include <cstdlib>

void register_ps2_sif_dma_tests();
void register_ps2_sif_rpc_tests();
void register_ps2_spr_dma_tests();

int main()
{
    register_ps2_sif_dma_tests();
    register_ps2_sif_rpc_tests();
    register_ps2_spr_dma_tests();

    const int result = MiniTest::Run();
    std::cout.flush();
    std::cerr.flush();
    // Process-wide HLE workers do not need teardown in this standalone runner.
    std::_Exit(result);
}
