#pragma once

#include "types.h"
#include "memory.h"

namespace reo {

/*
 * EE (Emotion Engine) CPU Context
 *
 * This is the register file and state that the recompiled MIPS code operates on.
 * Each recompiled function receives a pointer to this context and reads/writes
 * registers through it. This is the bridge between static recomp output and
 * our runtime.
 *
 * R5900 register file:
 *   32 x 128-bit GPRs ($zero through $ra, with 128-bit upper halves for MMI)
 *   HI/LO multiply registers (128-bit each for MMI)
 *   SA (shift amount) register
 *   PC (program counter)
 *   32 x 32-bit FPU registers (COP1)
 *   FPU control/status register
 *   32 x 128-bit VU0 float registers (COP2 macro mode)
 *   16 x 16-bit VU0 integer registers
 */

struct EEContext {
    // General purpose registers (128-bit for MMI support)
    GPR128 gpr[32]; // $zero(0) through $ra(31)

    // Multiply/divide result registers (128-bit for MMI)
    GPR128 hi;
    GPR128 lo;

    // Shift amount register (used by MMI funnel shift)
    uint32_t sa;

    // Program counter
    uint32_t pc;

    // COP0 registers (subset needed for game code)
    uint32_t cop0_status;
    uint32_t cop0_cause;
    uint32_t cop0_epc;
    uint32_t cop0_count;
    uint32_t cop0_compare;

    // COP1 (FPU) registers
    float fpr[32];
    uint32_t fcr0;  // FPU implementation register
    uint32_t fcr31; // FPU control/status register

    // COP2 (VU0 macro mode) registers
    VF128 vf[32];     // 32 x 128-bit vector float registers
    uint16_t vi[16];  // 16 x 16-bit vector integer registers
    float vu0_acc[4]; // VU0 accumulator (xyzw)
    float vu0_q;      // VU0 Q register (division result)
    float vu0_p;      // VU0 P register (EFU result, VU0 doesn't have EFU but the field is here)

    // Memory reference (for load/store instructions)
    Memory& memory;

    explicit EEContext(Memory& mem) : memory(mem) {
        reset();
    }

    void reset() {
        for (int i = 0; i < 32; i++)
            gpr[i].clear();
        hi.clear();
        lo.clear();
        sa = 0;
        pc = 0;

        cop0_status = 0;
        cop0_cause = 0;
        cop0_epc = 0;
        cop0_count = 0;
        cop0_compare = 0;

        for (int i = 0; i < 32; i++)
            fpr[i] = 0.0f;
        fcr0 = 0x2E00; // R5900 FPU implementation ID
        fcr31 = 0;

        for (int i = 0; i < 32; i++)
            vf[i].clear();
        for (int i = 0; i < 16; i++)
            vi[i] = 0;
        for (int i = 0; i < 4; i++)
            vu0_acc[i] = 0.0f;
        vu0_q = 0.0f;
        vu0_p = 0.0f;
    }

    // Register names for debugging
    static const char* gpr_name(int reg) {
        static const char* names[] = {"zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
                                      "t0",   "t1", "t2", "t3", "t4", "t5", "t6", "t7",
                                      "s0",   "s1", "s2", "s3", "s4", "s5", "s6", "s7",
                                      "t8",   "t9", "k0", "k1", "gp", "sp", "fp", "ra"};
        return (reg >= 0 && reg < 32) ? names[reg] : "??";
    }
};

// Function signature for recompiled code
// Each recompiled MIPS function takes the CPU context
using RecompiledFunc = void (*)(EEContext* ctx);

} // namespace reo
