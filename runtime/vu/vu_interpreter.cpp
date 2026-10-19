#include "vu_interpreter.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

namespace reo {

// Field extraction helpers
// Upper instruction: [31:26]=op [25:24]=? [24:21]=dest [20:16]=ft [15:11]=fs [10:6]=fd [1:0]=bc
// Lower instruction: [25:21]=dest [20:16]=ft [15:11]=fs [10:6]=id/it [5:0]=opcode

static inline uint32_t u_dest(uint32_t inst) {
    return (inst >> 21) & 0xF;
}
static inline uint32_t u_ft(uint32_t inst) {
    return (inst >> 16) & 0x1F;
}
static inline uint32_t u_fs(uint32_t inst) {
    return (inst >> 11) & 0x1F;
}
static inline uint32_t u_fd(uint32_t inst) {
    return (inst >> 6) & 0x1F;
}
static inline uint32_t u_bc(uint32_t inst) {
    return inst & 0x3;
}

// Lower instruction fields
static inline uint32_t l_dest(uint32_t inst) {
    return (inst >> 21) & 0xF;
}
static inline uint32_t l_ft(uint32_t inst) {
    return (inst >> 16) & 0x1F;
}
static inline uint32_t l_fs(uint32_t inst) {
    return (inst >> 11) & 0x1F;
}
static inline uint32_t l_id(uint32_t inst) {
    return (inst >> 6) & 0x1F;
}
static inline uint32_t l_it(uint32_t inst) {
    return (inst >> 16) & 0x1F;
}
static inline uint32_t l_is(uint32_t inst) {
    return (inst >> 11) & 0x1F;
}

// Sign-extend 11-bit immediate
static inline int32_t sign_ext_11(uint32_t val) {
    if (val & 0x400)
        return (int32_t)(val | 0xFFFFF800);
    return (int32_t)val;
}

// Sign-extend 5-bit immediate
static inline int32_t sign_ext_5(uint32_t val) {
    if (val & 0x10)
        return (int32_t)(val | 0xFFFFFFE0);
    return (int32_t)val;
}

// Data memory address wrapping (VU0: 4KB, VU1: 16KB)
inline uint32_t data_addr(uint32_t addr, uint32_t data_size) {
    return (addr * 16) & (data_size - 1);
}

// Constructor / Reset / Execution
VUInterpreter::VUInterpreter(int unit_id, uint8_t* code_mem, uint32_t code_size, uint8_t* data_mem,
                             uint32_t data_size)
    : m_unit_id(unit_id), m_code_mem(code_mem), m_code_size(code_size), m_data_mem(data_mem),
      m_data_size(data_size) {
    reset();
}

void VUInterpreter::reset() {
    m_state.reset();
}

void VUInterpreter::start(uint32_t addr) {
    m_state.pc = addr;
    m_state.running = true;
    m_state.stall_cycles = 0;
    m_state.delay_slot = false;
    printf("[VU%d] Start execution at 0x%04X\n", m_unit_id, addr);
}

void VUInterpreter::step() {
    if (!m_state.running)
        return;

    if (m_state.pc >= m_code_size) {
        printf("[VU%d] PC out of bounds: 0x%04X (code size: 0x%X)\n", m_unit_id, m_state.pc,
               m_code_size);
        m_state.running = false;
        return;
    }

    // Each VU instruction is 8 bytes: 4 bytes lower + 4 bytes upper
    // They execute in parallel (dual-issue)
    uint32_t* code = (uint32_t*)(m_code_mem + m_state.pc);
    uint32_t lower = code[0];
    uint32_t upper = code[1];

    // Save branch state before executing
    bool was_delay = m_state.delay_slot;
    uint32_t branch_target = m_state.delay_pc;

    execute_upper(upper);
    execute_lower(lower);

    // VF[0] is always (0, 0, 0, 1) — enforce after every instruction
    m_state.vf[0].x = 0.0f;
    m_state.vf[0].y = 0.0f;
    m_state.vf[0].z = 0.0f;
    m_state.vf[0].w = 1.0f;

    // VI[0] is always 0
    m_state.vi[0] = 0;

    if (was_delay) {
        // We just executed the delay slot — jump to branch target
        m_state.pc = branch_target;
        m_state.delay_slot = false;
    } else {
        m_state.pc += 8;
    }
}

void VUInterpreter::run(int max_cycles) {
    for (int i = 0; i < max_cycles && m_state.running; i++) {
        step();
    }

    if (m_state.running) {
        printf("[VU%d] Warning: execution did not complete within %d cycles\n", m_unit_id,
               max_cycles);
    }
}

void VUInterpreter::update_mac_flags(float result, int element) {
    uint16_t flags = 0;
    if (result == 0.0f)
        flags |= (0x1 << element); // Zero
    if (result < 0.0f)
        flags |= (0x10 << element); // Sign
    // Overflow/underflow detection omitted for now (rare in game code)
    m_state.status = (m_state.status & ~(0x11 << element)) | flags;
}

// Upper instruction dispatch
void VUInterpreter::execute_upper(uint32_t inst) {
    uint32_t opcode = (inst >> 26) & 0x3F;

    switch (opcode) {
        case 0x00:
            vu_addbc(inst);
            break; // ADDbc
        case 0x01:
            vu_subbc(inst);
            break; // SUBbc
        case 0x02:
            vu_maddbc(inst);
            break; // MADDbc
        case 0x03:
            vu_msubbc(inst);
            break; // MSUBbc
        case 0x04:
            vu_maxbc(inst);
            break; // MAXbc
        case 0x05:
            vu_minbc(inst);
            break; // MINIbc
        case 0x06:
            vu_mulbc(inst);
            break; // MULbc
        case 0x07: // MULq
        {
            uint32_t dest = u_dest(inst);
            uint32_t fs = u_fs(inst);
            uint32_t fd = u_fd(inst);
            VF128 result;
            if (dest & 0x8)
                result.x = m_state.vf[fs].x * m_state.q;
            if (dest & 0x4)
                result.y = m_state.vf[fs].y * m_state.q;
            if (dest & 0x2)
                result.z = m_state.vf[fs].z * m_state.q;
            if (dest & 0x1)
                result.w = m_state.vf[fs].w * m_state.q;
            if (fd != 0) {
                if (dest & 0x8)
                    m_state.vf[fd].x = result.x;
                if (dest & 0x4)
                    m_state.vf[fd].y = result.y;
                if (dest & 0x2)
                    m_state.vf[fd].z = result.z;
                if (dest & 0x1)
                    m_state.vf[fd].w = result.w;
            }
            break;
        }
        case 0x08: // ADDq
        {
            uint32_t dest = u_dest(inst);
            uint32_t fs = u_fs(inst);
            uint32_t fd = u_fd(inst);
            if (fd != 0) {
                if (dest & 0x8)
                    m_state.vf[fd].x = m_state.vf[fs].x + m_state.q;
                if (dest & 0x4)
                    m_state.vf[fd].y = m_state.vf[fs].y + m_state.q;
                if (dest & 0x2)
                    m_state.vf[fd].z = m_state.vf[fs].z + m_state.q;
                if (dest & 0x1)
                    m_state.vf[fd].w = m_state.vf[fs].w + m_state.q;
            }
            break;
        }
        case 0x09: // MADDq
        {
            uint32_t dest = u_dest(inst);
            uint32_t fs = u_fs(inst);
            uint32_t fd = u_fd(inst);
            if (fd != 0) {
                if (dest & 0x8)
                    m_state.vf[fd].x = m_state.acc[0] + m_state.vf[fs].x * m_state.q;
                if (dest & 0x4)
                    m_state.vf[fd].y = m_state.acc[1] + m_state.vf[fs].y * m_state.q;
                if (dest & 0x2)
                    m_state.vf[fd].z = m_state.acc[2] + m_state.vf[fs].z * m_state.q;
                if (dest & 0x1)
                    m_state.vf[fd].w = m_state.acc[3] + m_state.vf[fs].w * m_state.q;
            }
            break;
        }
        case 0x0A:
            vu_add(inst);
            break; // ADD
        case 0x0B:
            vu_sub(inst);
            break; // SUB
        case 0x0C:
            vu_madd(inst);
            break; // MADD
        case 0x0D:
            vu_msub(inst);
            break; // MSUB
        case 0x0E:
            vu_max(inst);
            break; // MAX
        case 0x0F:
            vu_min(inst);
            break; // MINI
        case 0x10:
            vu_mul(inst);
            break; // MUL
        case 0x11: // MULi (MUL by I register)
        {
            uint32_t dest = u_dest(inst);
            uint32_t fs = u_fs(inst);
            uint32_t fd = u_fd(inst);
            if (fd != 0) {
                if (dest & 0x8)
                    m_state.vf[fd].x = m_state.vf[fs].x * m_state.i_reg;
                if (dest & 0x4)
                    m_state.vf[fd].y = m_state.vf[fs].y * m_state.i_reg;
                if (dest & 0x2)
                    m_state.vf[fd].z = m_state.vf[fs].z * m_state.i_reg;
                if (dest & 0x1)
                    m_state.vf[fd].w = m_state.vf[fs].w * m_state.i_reg;
            }
            break;
        }
        case 0x1A: // ADDi
        {
            uint32_t dest = u_dest(inst);
            uint32_t fs = u_fs(inst);
            uint32_t fd = u_fd(inst);
            if (fd != 0) {
                if (dest & 0x8)
                    m_state.vf[fd].x = m_state.vf[fs].x + m_state.i_reg;
                if (dest & 0x4)
                    m_state.vf[fd].y = m_state.vf[fs].y + m_state.i_reg;
                if (dest & 0x2)
                    m_state.vf[fd].z = m_state.vf[fs].z + m_state.i_reg;
                if (dest & 0x1)
                    m_state.vf[fd].w = m_state.vf[fs].w + m_state.i_reg;
            }
            break;
        }
        case 0x1C: // Special upper opcodes (FTOI, ITOF, ABS, CLIP, OPMULA, OPMSUB)
        {
            uint32_t func = inst & 0x3;
            uint32_t sub = (inst >> 2) & 0x3;
            // Combined sub-opcode from bits [5:0]
            uint32_t full_func = inst & 0x3F;
            switch (full_func) {
                case 0x00:
                case 0x04:
                case 0x05:
                case 0x07: // ABS
                    vu_abs(inst);
                    break;
                case 0x0C:
                    vu_ftoi(inst);
                    break; // FTOI0
                case 0x0D:
                    vu_ftoi(inst);
                    break; // FTOI4
                case 0x0E:
                    vu_ftoi(inst);
                    break; // FTOI12
                case 0x0F:
                    vu_ftoi(inst);
                    break; // FTOI15
                case 0x10:
                    vu_itof(inst);
                    break; // ITOF0
                case 0x11:
                    vu_itof(inst);
                    break; // ITOF4
                case 0x12:
                    vu_itof(inst);
                    break; // ITOF12
                case 0x13:
                    vu_itof(inst);
                    break; // ITOF15
                case 0x1E:
                    vu_clip(inst);
                    break; // CLIP
                default:
                    break;
            }
            break;
        }
        case 0x1E: // MULA (MUL to accumulator)
        {
            uint32_t dest = u_dest(inst);
            uint32_t fs = u_fs(inst);
            uint32_t ft = u_ft(inst);
            if (dest & 0x8)
                m_state.acc[0] = m_state.vf[fs].x * m_state.vf[ft].x;
            if (dest & 0x4)
                m_state.acc[1] = m_state.vf[fs].y * m_state.vf[ft].y;
            if (dest & 0x2)
                m_state.acc[2] = m_state.vf[fs].z * m_state.vf[ft].z;
            if (dest & 0x1)
                m_state.acc[3] = m_state.vf[fs].w * m_state.vf[ft].w;
            break;
        }
        case 0x1F: // SPECIAL2 upper: OPMULA, NOP, etc.
        {
            uint32_t full_func = inst & 0x3F;
            if (full_func == 0x2E) {
                vu_opmula(inst);
            } else if (full_func == 0x2F) {
                vu_opmsub(inst);
            }
            // else NOP
            break;
        }
        default:
            // NOP or unimplemented
            break;
    }
}

// Lower instruction dispatch
void VUInterpreter::execute_lower(uint32_t inst) {
    // Check for NOP patterns
    if (inst == 0x8000033C || inst == 0x00000000) {
        return;
    }

    // Check for E bit (end) — bit 30 of lower instruction
    // The E bit causes the program to end after the next instruction (delay slot)
    if (inst & 0x40000000) {
        // After executing this instruction and the next, stop
        // We handle this by setting a "stop after delay" flag
        // For simplicity, stop after this instruction pair
        m_state.running = false;
        return;
    }

    uint32_t opcode = inst & 0x3F;

    switch (opcode) {
        case 0x30:
            vu_iadd(inst);
            break;
        case 0x31:
            vu_isub(inst);
            break;
        case 0x32:
            vu_iaddi(inst);
            break;
        case 0x34:
            vu_iand(inst);
            break;
        case 0x35:
            vu_ior(inst);
            break;

        // Load/store with immediate offset
        case 0x01:
            vu_lq(inst);
            break; // LQ
        case 0x05:
            vu_sq(inst);
            break; // SQ
        case 0x04:
            vu_ilw(inst);
            break; // ILW
        case 0x09:
            vu_isw(inst);
            break; // ISW

        // Branch instructions
        case 0x20:
            vu_ibeq(inst);
            break; // IBEQ
        case 0x21:
            vu_ibne(inst);
            break; // IBNE
        case 0x24:
            vu_ibltz(inst);
            break; // IBLTZ
        case 0x25:
            vu_ibgtz(inst);
            break; // IBGTZ
        case 0x26:
            vu_iblez(inst);
            break; // IBLEZ
        case 0x27:
            vu_ibgez(inst);
            break; // IBGEZ
        case 0x28: // B (unconditional branch)
            vu_branch(inst, true, false);
            break;
        case 0x29: // BAL (branch and link)
            vu_branch(inst, true, true);
            break;

        case 0x3C: // SPECIAL lower
        {
            uint32_t func2 = (inst >> 6) & 0x1F;
            switch (func2) {
                case 0x00:
                    vu_move(inst);
                    break;
                case 0x01:
                    vu_mr32(inst);
                    break;
                case 0x04:
                    vu_lqi(inst);
                    break;
                case 0x05:
                    vu_sqi(inst);
                    break;
                case 0x06:
                    vu_lqd(inst);
                    break;
                case 0x07:
                    vu_sqd(inst);
                    break;
                case 0x08:
                    vu_div(inst);
                    break;
                case 0x09:
                    vu_sqrt(inst);
                    break;
                case 0x0A:
                    vu_rsqrt(inst);
                    break;
                case 0x0B: // WAITQ — Q register is always ready in our interpreter
                    break;
                case 0x0C:
                    vu_mtir(inst);
                    break;
                case 0x0D:
                    vu_mfir(inst);
                    break;
                default:
                    break;
            }
            break;
        }
        case 0x3F: // SPECIAL2 lower
        {
            uint32_t func2 = (inst >> 6) & 0x1F;
            switch (func2) {
                case 0x10:
                    vu_xgkick(inst);
                    break;
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

//
// UPPER INSTRUCTION IMPLEMENTATIONS (FMAC pipeline)
//
void VUInterpreter::vu_add(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.vf[fs].x + m_state.vf[ft].x;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.vf[fs].y + m_state.vf[ft].y;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.vf[fs].z + m_state.vf[ft].z;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.vf[fs].w + m_state.vf[ft].w;
}

void VUInterpreter::vu_addbc(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    uint32_t bc = u_bc(inst);
    float bc_val = m_state.vf[ft].f[bc];
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.vf[fs].x + bc_val;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.vf[fs].y + bc_val;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.vf[fs].z + bc_val;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.vf[fs].w + bc_val;
}

void VUInterpreter::vu_sub(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.vf[fs].x - m_state.vf[ft].x;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.vf[fs].y - m_state.vf[ft].y;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.vf[fs].z - m_state.vf[ft].z;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.vf[fs].w - m_state.vf[ft].w;
}

void VUInterpreter::vu_subbc(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    float bc_val = m_state.vf[ft].f[u_bc(inst)];
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.vf[fs].x - bc_val;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.vf[fs].y - bc_val;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.vf[fs].z - bc_val;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.vf[fs].w - bc_val;
}

void VUInterpreter::vu_mul(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.vf[fs].x * m_state.vf[ft].x;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.vf[fs].y * m_state.vf[ft].y;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.vf[fs].z * m_state.vf[ft].z;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.vf[fs].w * m_state.vf[ft].w;
}

void VUInterpreter::vu_mulbc(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    float bc_val = m_state.vf[ft].f[u_bc(inst)];
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.vf[fs].x * bc_val;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.vf[fs].y * bc_val;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.vf[fs].z * bc_val;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.vf[fs].w * bc_val;
}

void VUInterpreter::vu_madd(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.acc[0] + m_state.vf[fs].x * m_state.vf[ft].x;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.acc[1] + m_state.vf[fs].y * m_state.vf[ft].y;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.acc[2] + m_state.vf[fs].z * m_state.vf[ft].z;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.acc[3] + m_state.vf[fs].w * m_state.vf[ft].w;
}

void VUInterpreter::vu_maddbc(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    float bc_val = m_state.vf[ft].f[u_bc(inst)];
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.acc[0] + m_state.vf[fs].x * bc_val;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.acc[1] + m_state.vf[fs].y * bc_val;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.acc[2] + m_state.vf[fs].z * bc_val;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.acc[3] + m_state.vf[fs].w * bc_val;
}

void VUInterpreter::vu_msub(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.acc[0] - m_state.vf[fs].x * m_state.vf[ft].x;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.acc[1] - m_state.vf[fs].y * m_state.vf[ft].y;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.acc[2] - m_state.vf[fs].z * m_state.vf[ft].z;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.acc[3] - m_state.vf[fs].w * m_state.vf[ft].w;
}

void VUInterpreter::vu_msubbc(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    float bc_val = m_state.vf[ft].f[u_bc(inst)];
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = m_state.acc[0] - m_state.vf[fs].x * bc_val;
    if (dest & 0x4)
        m_state.vf[fd].y = m_state.acc[1] - m_state.vf[fs].y * bc_val;
    if (dest & 0x2)
        m_state.vf[fd].z = m_state.acc[2] - m_state.vf[fs].z * bc_val;
    if (dest & 0x1)
        m_state.vf[fd].w = m_state.acc[3] - m_state.vf[fs].w * bc_val;
}

void VUInterpreter::vu_max(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = std::max(m_state.vf[fs].x, m_state.vf[ft].x);
    if (dest & 0x4)
        m_state.vf[fd].y = std::max(m_state.vf[fs].y, m_state.vf[ft].y);
    if (dest & 0x2)
        m_state.vf[fd].z = std::max(m_state.vf[fs].z, m_state.vf[ft].z);
    if (dest & 0x1)
        m_state.vf[fd].w = std::max(m_state.vf[fs].w, m_state.vf[ft].w);
}

void VUInterpreter::vu_maxbc(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    float bc_val = m_state.vf[ft].f[u_bc(inst)];
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = std::max(m_state.vf[fs].x, bc_val);
    if (dest & 0x4)
        m_state.vf[fd].y = std::max(m_state.vf[fs].y, bc_val);
    if (dest & 0x2)
        m_state.vf[fd].z = std::max(m_state.vf[fs].z, bc_val);
    if (dest & 0x1)
        m_state.vf[fd].w = std::max(m_state.vf[fs].w, bc_val);
}

void VUInterpreter::vu_min(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = std::min(m_state.vf[fs].x, m_state.vf[ft].x);
    if (dest & 0x4)
        m_state.vf[fd].y = std::min(m_state.vf[fs].y, m_state.vf[ft].y);
    if (dest & 0x2)
        m_state.vf[fd].z = std::min(m_state.vf[fs].z, m_state.vf[ft].z);
    if (dest & 0x1)
        m_state.vf[fd].w = std::min(m_state.vf[fs].w, m_state.vf[ft].w);
}

void VUInterpreter::vu_minbc(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fs = u_fs(inst);
    uint32_t fd = u_fd(inst);
    float bc_val = m_state.vf[ft].f[u_bc(inst)];
    if (fd == 0)
        return;

    if (dest & 0x8)
        m_state.vf[fd].x = std::min(m_state.vf[fs].x, bc_val);
    if (dest & 0x4)
        m_state.vf[fd].y = std::min(m_state.vf[fs].y, bc_val);
    if (dest & 0x2)
        m_state.vf[fd].z = std::min(m_state.vf[fs].z, bc_val);
    if (dest & 0x1)
        m_state.vf[fd].w = std::min(m_state.vf[fs].w, bc_val);
}

void VUInterpreter::vu_ftoi(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t fs = u_fs(inst);
    uint32_t ft = u_ft(inst); // destination for FTOI is the ft field

    // Determine shift from sub-opcode: FTOI0=0, FTOI4=4, FTOI12=12, FTOI15=15
    uint32_t sub = inst & 0x3;
    int shift_table[4] = {0, 4, 12, 15};
    float scale = (float)(1 << shift_table[sub]);

    if (ft == 0)
        return;

    if (dest & 0x8)
        m_state.vf[ft].u[0] = (uint32_t)(int32_t)(m_state.vf[fs].x * scale);
    if (dest & 0x4)
        m_state.vf[ft].u[1] = (uint32_t)(int32_t)(m_state.vf[fs].y * scale);
    if (dest & 0x2)
        m_state.vf[ft].u[2] = (uint32_t)(int32_t)(m_state.vf[fs].z * scale);
    if (dest & 0x1)
        m_state.vf[ft].u[3] = (uint32_t)(int32_t)(m_state.vf[fs].w * scale);
}

void VUInterpreter::vu_itof(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t fs = u_fs(inst);
    uint32_t ft = u_ft(inst);

    uint32_t sub = inst & 0x3;
    int shift_table[4] = {0, 4, 12, 15};
    float scale = 1.0f / (float)(1 << shift_table[sub]);

    if (ft == 0)
        return;

    if (dest & 0x8)
        m_state.vf[ft].x = (float)(int32_t)m_state.vf[fs].u[0] * scale;
    if (dest & 0x4)
        m_state.vf[ft].y = (float)(int32_t)m_state.vf[fs].u[1] * scale;
    if (dest & 0x2)
        m_state.vf[ft].z = (float)(int32_t)m_state.vf[fs].u[2] * scale;
    if (dest & 0x1)
        m_state.vf[ft].w = (float)(int32_t)m_state.vf[fs].u[3] * scale;
}

void VUInterpreter::vu_abs(uint32_t inst) {
    uint32_t dest = u_dest(inst);
    uint32_t fs = u_fs(inst);
    uint32_t ft = u_ft(inst);
    if (ft == 0)
        return;

    if (dest & 0x8)
        m_state.vf[ft].x = fabsf(m_state.vf[fs].x);
    if (dest & 0x4)
        m_state.vf[ft].y = fabsf(m_state.vf[fs].y);
    if (dest & 0x2)
        m_state.vf[ft].z = fabsf(m_state.vf[fs].z);
    if (dest & 0x1)
        m_state.vf[ft].w = fabsf(m_state.vf[fs].w);
}

void VUInterpreter::vu_clip(uint32_t inst) {
    uint32_t fs = u_fs(inst);
    uint32_t ft = u_ft(inst);

    float w = fabsf(m_state.vf[ft].w);
    float x = m_state.vf[fs].x;
    float y = m_state.vf[fs].y;
    float z = m_state.vf[fs].z;

    // Shift old clip results left by 6
    m_state.clip_flag = (m_state.clip_flag << 6) & 0xFFFFFF;

    // 6 clip judgements: +x, -x, +y, -y, +z, -z vs w
    if (x > +w)
        m_state.clip_flag |= 0x01;
    if (x < -w)
        m_state.clip_flag |= 0x02;
    if (y > +w)
        m_state.clip_flag |= 0x04;
    if (y < -w)
        m_state.clip_flag |= 0x08;
    if (z > +w)
        m_state.clip_flag |= 0x10;
    if (z < -w)
        m_state.clip_flag |= 0x20;
}

void VUInterpreter::vu_opmula(uint32_t inst) {
    // Outer product to accumulator: ACC = fs × ft (cross product components)
    uint32_t fs = u_fs(inst);
    uint32_t ft = u_ft(inst);

    m_state.acc[0] = m_state.vf[fs].y * m_state.vf[ft].z;
    m_state.acc[1] = m_state.vf[fs].z * m_state.vf[ft].x;
    m_state.acc[2] = m_state.vf[fs].x * m_state.vf[ft].y;
}

void VUInterpreter::vu_opmsub(uint32_t inst) {
    // Outer product subtract: fd = ACC - fs × ft
    uint32_t fs = u_fs(inst);
    uint32_t ft = u_ft(inst);
    uint32_t fd = u_fd(inst);
    if (fd == 0)
        return;

    m_state.vf[fd].x = m_state.acc[0] - m_state.vf[fs].y * m_state.vf[ft].z;
    m_state.vf[fd].y = m_state.acc[1] - m_state.vf[fs].z * m_state.vf[ft].x;
    m_state.vf[fd].z = m_state.acc[2] - m_state.vf[fs].x * m_state.vf[ft].y;
}

//
// LOWER INSTRUCTION IMPLEMENTATIONS
// // ── Integer arithmetic
void VUInterpreter::vu_iadd(uint32_t inst) {
    uint32_t id = l_id(inst);
    uint32_t is = l_is(inst);
    uint32_t it = l_it(inst);
    if (id != 0)
        m_state.vi[id] = m_state.vi[is] + m_state.vi[it];
}

void VUInterpreter::vu_isub(uint32_t inst) {
    uint32_t id = l_id(inst);
    uint32_t is = l_is(inst);
    uint32_t it = l_it(inst);
    if (id != 0)
        m_state.vi[id] = m_state.vi[is] - m_state.vi[it];
}

void VUInterpreter::vu_iaddi(uint32_t inst) {
    uint32_t it = l_it(inst);
    uint32_t is = l_is(inst);
    int32_t imm5 = sign_ext_5((inst >> 6) & 0x1F);
    if (it != 0)
        m_state.vi[it] = m_state.vi[is] + imm5;
}

void VUInterpreter::vu_iand(uint32_t inst) {
    uint32_t id = l_id(inst);
    uint32_t is = l_is(inst);
    uint32_t it = l_it(inst);
    if (id != 0)
        m_state.vi[id] = m_state.vi[is] & m_state.vi[it];
}

void VUInterpreter::vu_ior(uint32_t inst) {
    uint32_t id = l_id(inst);
    uint32_t is = l_is(inst);
    uint32_t it = l_it(inst);
    if (id != 0)
        m_state.vi[id] = m_state.vi[is] | m_state.vi[it];
}

// FDIV pipeline
void VUInterpreter::vu_div(uint32_t inst) {
    // Q = fs[fsf] / ft[ftf]
    uint32_t fsf = (inst >> 21) & 0x3;
    uint32_t ftf = (inst >> 23) & 0x3;
    uint32_t fs = l_is(inst);
    uint32_t ft = l_it(inst);

    float num = m_state.vf[fs].f[fsf];
    float den = m_state.vf[ft].f[ftf];

    if (den == 0.0f) {
        // PS2 returns max float with sign of num*den
        uint32_t sign = (m_state.vf[fs].u[fsf] ^ m_state.vf[ft].u[ftf]) & 0x80000000;
        uint32_t max_val = 0x7F7FFFFF | sign;
        memcpy(&m_state.q, &max_val, 4);
    } else {
        m_state.q = num / den;
    }
}

void VUInterpreter::vu_sqrt(uint32_t inst) {
    uint32_t ftf = (inst >> 23) & 0x3;
    uint32_t ft = l_it(inst);

    float val = m_state.vf[ft].f[ftf];
    m_state.q = (val < 0.0f) ? sqrtf(fabsf(val)) : sqrtf(val);
}

void VUInterpreter::vu_rsqrt(uint32_t inst) {
    uint32_t fsf = (inst >> 21) & 0x3;
    uint32_t ftf = (inst >> 23) & 0x3;
    uint32_t fs = l_is(inst);
    uint32_t ft = l_it(inst);

    float num = m_state.vf[fs].f[fsf];
    float den_sq = m_state.vf[ft].f[ftf];

    float den = sqrtf(fabsf(den_sq));
    if (den == 0.0f) {
        uint32_t sign = m_state.vf[fs].u[fsf] & 0x80000000;
        uint32_t max_val = 0x7F7FFFFF | sign;
        memcpy(&m_state.q, &max_val, 4);
    } else {
        m_state.q = num / den;
    }
}

// Load/Store — quadword (128-bit)
void VUInterpreter::vu_lq(uint32_t inst) {
    // LQ.dest vft, imm(vis)
    uint32_t dest = l_dest(inst);
    uint32_t ft = l_ft(inst);
    uint32_t is = l_is(inst);
    int32_t imm = sign_ext_11(inst >> 21 & 0x7FF);

    // Wait — the immediate is in bits [31:21] for LQ
    // Actually for the lower instruction format: immediate is in the upper bits
    // Let's re-extract: bits [31:21] = imm11
    imm = sign_ext_11((inst >> 21) & 0x7FF);
    uint32_t addr = data_addr(m_state.vi[is] + imm, m_data_size);

    if (ft == 0)
        return;

    float* src = (float*)(m_data_mem + addr);
    if (dest & 0x8)
        m_state.vf[ft].x = src[0];
    if (dest & 0x4)
        m_state.vf[ft].y = src[1];
    if (dest & 0x2)
        m_state.vf[ft].z = src[2];
    if (dest & 0x1)
        m_state.vf[ft].w = src[3];
}

void VUInterpreter::vu_sq(uint32_t inst) {
    // SQ.dest vfs, imm(vit)
    uint32_t dest = l_dest(inst);
    uint32_t fs = l_fs(inst);
    uint32_t it = l_it(inst);
    int32_t imm = sign_ext_11((inst >> 21) & 0x7FF);

    uint32_t addr = data_addr(m_state.vi[it] + imm, m_data_size);
    float* dst = (float*)(m_data_mem + addr);

    if (dest & 0x8)
        dst[0] = m_state.vf[fs].x;
    if (dest & 0x4)
        dst[1] = m_state.vf[fs].y;
    if (dest & 0x2)
        dst[2] = m_state.vf[fs].z;
    if (dest & 0x1)
        dst[3] = m_state.vf[fs].w;
}

void VUInterpreter::vu_lqi(uint32_t inst) {
    // LQI.dest vft, (vis++) — load then increment
    uint32_t dest = l_dest(inst);
    uint32_t ft = l_ft(inst);
    uint32_t is = l_is(inst);

    uint32_t addr = data_addr(m_state.vi[is], m_data_size);

    if (ft != 0) {
        float* src = (float*)(m_data_mem + addr);
        if (dest & 0x8)
            m_state.vf[ft].x = src[0];
        if (dest & 0x4)
            m_state.vf[ft].y = src[1];
        if (dest & 0x2)
            m_state.vf[ft].z = src[2];
        if (dest & 0x1)
            m_state.vf[ft].w = src[3];
    }

    if (is != 0)
        m_state.vi[is]++;
}

void VUInterpreter::vu_sqi(uint32_t inst) {
    // SQI.dest vfs, (vit++) — store then increment
    uint32_t dest = l_dest(inst);
    uint32_t fs = l_fs(inst);
    uint32_t it = l_it(inst);

    uint32_t addr = data_addr(m_state.vi[it], m_data_size);
    float* dst = (float*)(m_data_mem + addr);

    if (dest & 0x8)
        dst[0] = m_state.vf[fs].x;
    if (dest & 0x4)
        dst[1] = m_state.vf[fs].y;
    if (dest & 0x2)
        dst[2] = m_state.vf[fs].z;
    if (dest & 0x1)
        dst[3] = m_state.vf[fs].w;

    if (it != 0)
        m_state.vi[it]++;
}

void VUInterpreter::vu_lqd(uint32_t inst) {
    // LQD.dest vft, (--vis) — decrement then load
    uint32_t dest = l_dest(inst);
    uint32_t ft = l_ft(inst);
    uint32_t is = l_is(inst);

    if (is != 0)
        m_state.vi[is]--;

    uint32_t addr = data_addr(m_state.vi[is], m_data_size);

    if (ft != 0) {
        float* src = (float*)(m_data_mem + addr);
        if (dest & 0x8)
            m_state.vf[ft].x = src[0];
        if (dest & 0x4)
            m_state.vf[ft].y = src[1];
        if (dest & 0x2)
            m_state.vf[ft].z = src[2];
        if (dest & 0x1)
            m_state.vf[ft].w = src[3];
    }
}

void VUInterpreter::vu_sqd(uint32_t inst) {
    // SQD.dest vfs, (--vit) — decrement then store
    uint32_t dest = l_dest(inst);
    uint32_t fs = l_fs(inst);
    uint32_t it = l_it(inst);

    if (it != 0)
        m_state.vi[it]--;

    uint32_t addr = data_addr(m_state.vi[it], m_data_size);
    float* dst = (float*)(m_data_mem + addr);

    if (dest & 0x8)
        dst[0] = m_state.vf[fs].x;
    if (dest & 0x4)
        dst[1] = m_state.vf[fs].y;
    if (dest & 0x2)
        dst[2] = m_state.vf[fs].z;
    if (dest & 0x1)
        dst[3] = m_state.vf[fs].w;
}

// Load/Store — integer (16-bit from VU data memory)
void VUInterpreter::vu_ilw(uint32_t inst) {
    uint32_t dest = l_dest(inst);
    uint32_t it = l_it(inst);
    uint32_t is = l_is(inst);
    int32_t imm = sign_ext_11((inst >> 21) & 0x7FF);

    uint32_t addr = data_addr(m_state.vi[is] + imm, m_data_size);
    uint32_t* src = (uint32_t*)(m_data_mem + addr);

    if (it == 0)
        return;

    // Read from the component selected by dest mask (first set bit)
    if (dest & 0x8)
        m_state.vi[it] = (uint16_t)src[0];
    else if (dest & 0x4)
        m_state.vi[it] = (uint16_t)src[1];
    else if (dest & 0x2)
        m_state.vi[it] = (uint16_t)src[2];
    else if (dest & 0x1)
        m_state.vi[it] = (uint16_t)src[3];
}

void VUInterpreter::vu_isw(uint32_t inst) {
    uint32_t dest = l_dest(inst);
    uint32_t it = l_it(inst);
    uint32_t is = l_is(inst);
    int32_t imm = sign_ext_11((inst >> 21) & 0x7FF);

    uint32_t addr = data_addr(m_state.vi[is] + imm, m_data_size);
    uint32_t* dst = (uint32_t*)(m_data_mem + addr);

    uint32_t val = m_state.vi[it];
    if (dest & 0x8)
        dst[0] = val;
    if (dest & 0x4)
        dst[1] = val;
    if (dest & 0x2)
        dst[2] = val;
    if (dest & 0x1)
        dst[3] = val;
}

// Register transfer
void VUInterpreter::vu_move(uint32_t inst) {
    uint32_t dest = l_dest(inst);
    uint32_t ft = l_ft(inst);
    uint32_t fs = l_fs(inst);
    if (ft == 0)
        return;

    if (dest & 0x8)
        m_state.vf[ft].x = m_state.vf[fs].x;
    if (dest & 0x4)
        m_state.vf[ft].y = m_state.vf[fs].y;
    if (dest & 0x2)
        m_state.vf[ft].z = m_state.vf[fs].z;
    if (dest & 0x1)
        m_state.vf[ft].w = m_state.vf[fs].w;
}

void VUInterpreter::vu_mr32(uint32_t inst) {
    // Rotate right by 32 bits: ft.x=fs.y, ft.y=fs.z, ft.z=fs.w, ft.w=fs.x
    uint32_t dest = l_dest(inst);
    uint32_t ft = l_ft(inst);
    uint32_t fs = l_fs(inst);
    if (ft == 0)
        return;

    VF128 tmp = m_state.vf[fs];
    if (dest & 0x8)
        m_state.vf[ft].x = tmp.y;
    if (dest & 0x4)
        m_state.vf[ft].y = tmp.z;
    if (dest & 0x2)
        m_state.vf[ft].z = tmp.w;
    if (dest & 0x1)
        m_state.vf[ft].w = tmp.x;
}

void VUInterpreter::vu_mfir(uint32_t inst) {
    // Move from integer register: vft = sign_extend(vis)
    uint32_t dest = l_dest(inst);
    uint32_t ft = l_ft(inst);
    uint32_t is = l_is(inst);
    if (ft == 0)
        return;

    float val;
    int32_t sext = (int32_t)(int16_t)m_state.vi[is];
    memcpy(&val, &sext, 4); // Bitwise copy as integer into float register

    // Actually MFIR sets the float components to the sign-extended integer value
    // interpreted as a float. More commonly used to transfer addresses.
    // Re-interpret: just store the 32-bit pattern
    uint32_t bits = (uint32_t)sext;
    if (dest & 0x8)
        m_state.vf[ft].u[0] = bits;
    if (dest & 0x4)
        m_state.vf[ft].u[1] = bits;
    if (dest & 0x2)
        m_state.vf[ft].u[2] = bits;
    if (dest & 0x1)
        m_state.vf[ft].u[3] = bits;
}

void VUInterpreter::vu_mtir(uint32_t inst) {
    // Move to integer register: vit = vfs[fsf] (lower 16 bits)
    uint32_t fsf = (inst >> 21) & 0x3;
    uint32_t it = l_it(inst);
    uint32_t fs = l_is(inst);
    if (it == 0)
        return;

    m_state.vi[it] = (uint16_t)(m_state.vf[fs].u[fsf] & 0xFFFF);
}

// Branch instructions
void VUInterpreter::vu_branch(uint32_t inst, bool condition, bool link) {
    if (!condition)
        return;

    // Branch offset is in bits [31:21] (11-bit signed, in quadwords)
    int32_t offset = sign_ext_11((inst >> 21) & 0x7FF);

    if (link) {
        // VI[15] = return address (PC after delay slot, in instruction units)
        m_state.vi[15] = (uint16_t)((m_state.pc + 16) / 8);
    }

    // Branch is delayed — takes effect after the NEXT instruction
    m_state.delay_slot = true;
    m_state.delay_pc = m_state.pc + 8 + offset * 8;
}

void VUInterpreter::vu_ibeq(uint32_t inst) {
    uint32_t is = l_is(inst);
    uint32_t it = l_it(inst);
    vu_branch(inst, m_state.vi[is] == m_state.vi[it]);
}

void VUInterpreter::vu_ibne(uint32_t inst) {
    uint32_t is = l_is(inst);
    uint32_t it = l_it(inst);
    vu_branch(inst, m_state.vi[is] != m_state.vi[it]);
}

void VUInterpreter::vu_ibltz(uint32_t inst) {
    uint32_t is = l_is(inst);
    vu_branch(inst, (int16_t)m_state.vi[is] < 0);
}

void VUInterpreter::vu_ibgtz(uint32_t inst) {
    uint32_t is = l_is(inst);
    vu_branch(inst, (int16_t)m_state.vi[is] > 0);
}

void VUInterpreter::vu_iblez(uint32_t inst) {
    uint32_t is = l_is(inst);
    vu_branch(inst, (int16_t)m_state.vi[is] <= 0);
}

void VUInterpreter::vu_ibgez(uint32_t inst) {
    uint32_t is = l_is(inst);
    vu_branch(inst, (int16_t)m_state.vi[is] >= 0);
}

// VU1 special: XGKICK
void VUInterpreter::vu_xgkick(uint32_t inst) {
    // VU1 only — kick GIF packet from VU1 data memory to GS via PATH1
    if (m_unit_id != 1)
        return;

    uint32_t is = l_is(inst);
    uint32_t addr = data_addr(m_state.vi[is], m_data_size);

    // Submit GIF packet to GS renderer via callback
    if (m_xgkick_cb) {
        uint32_t max_size = m_data_size - addr;
        m_xgkick_cb(m_data_mem + addr, max_size, m_xgkick_user);
    }
}

} // namespace reo
