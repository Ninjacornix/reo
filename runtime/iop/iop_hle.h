#pragma once

#include "runtime/core/memory.h"
#include <cstdint>
#include <string>

namespace reo {

// Forward declarations
class Input;
class SPU2;
class CDVD;

/*
 * IOP High-Level Emulation
 *
 * The IOP (I/O Processor) is the PS2's secondary CPU — a MIPS R3000A
 * running at 37.5 MHz with 2 MB of its own RAM. It handles all I/O:
 * controllers, memory cards, CD/DVD, sound, USB, network, HDD.
 *
 * Rather than recompiling all the IOP code, we use HLE:
 * intercept the SIF RPC calls from the EE side and provide
 * native implementations of the IOP module functions.
 *
 * Key modules to HLE:
 *   - sio2man (controller/memcard interface)
 *   - padman (controller input)
 *   - mcman/mcserv (memory card)
 *   - cdvdman (disc access)
 *   - libsd (SPU2 sound driver)
 *   - inet/netcnf/smap (network stack)
 */

// SIF RPC module IDs (for EE→IOP calls)
constexpr uint32_t SIF_PADMAN = 0x80000100;
constexpr uint32_t SIF_MCSERV = 0x80000400;
constexpr uint32_t SIF_CDVD = 0x80000592;
constexpr uint32_t SIF_LIBSD = 0x80000701;
constexpr uint32_t SIF_INET = 0x80000A01;
constexpr uint32_t SIF_NETCNF = 0x80000A02;

class IopHLE {
  public:
    explicit IopHLE(Memory& ee_memory);

    // Attach subsystem references (called during boot)
    void set_input(Input* input) {
        m_input = input;
    }
    void set_spu2(SPU2* spu2) {
        m_spu2 = spu2;
    }
    void set_cdvd(CDVD* cdvd) {
        m_cdvd = cdvd;
    }

    // SIF RPC call from EE
    void sif_rpc_call(uint32_t module_id, uint32_t func_id, uint32_t send_buf, uint32_t send_size,
                      uint32_t recv_buf, uint32_t recv_size);

    // SIF DMA between EE and IOP
    void sif_dma_to_iop(uint32_t ee_addr, uint32_t iop_addr, uint32_t size);
    void sif_dma_to_ee(uint32_t iop_addr, uint32_t ee_addr, uint32_t size);

    // Module loading (games request specific IRX modules)
    int load_module(const std::string& name);

  private:
    // HLE implementations of IOP modules
    void hle_padman(uint32_t func, uint32_t send, uint32_t recv);
    void hle_mcserv(uint32_t func, uint32_t send, uint32_t recv);
    void hle_cdvd(uint32_t func, uint32_t send, uint32_t recv);
    void hle_libsd(uint32_t func, uint32_t send, uint32_t recv);
    void hle_inet(uint32_t func, uint32_t send, uint32_t recv);

    Memory& m_ee_memory;
    Input* m_input = nullptr;
    SPU2* m_spu2 = nullptr;
    CDVD* m_cdvd = nullptr;

    // Memory card state
    std::string m_mc_save_dir = "saves";
};

} // namespace reo
