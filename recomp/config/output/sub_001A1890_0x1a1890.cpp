#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1890
// Address: 0x1a1890 - 0x1a1900
void sub_001A1890_0x1a1890(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1890_0x1a1890");
#endif

    switch (ctx->pc) {
        case 0x1a18a0u: goto label_1a18a0;
        case 0x1a18a8u: goto label_1a18a8;
        case 0x1a18d0u: goto label_1a18d0;
        default: break;
    }

    ctx->pc = 0x1a1890u;

    // 0x1a1890: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a1890u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a1894: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a1894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a1898: 0xc069720  jal         func_1A5C80
    ctx->pc = 0x1A1898u;
    SET_GPR_U32(ctx, 31, 0x1A18A0u);
    ctx->pc = 0x1A189Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1898u;
            // 0x1a189c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5C80u;
    if (runtime->hasFunction(0x1A5C80u)) {
        auto targetFn = runtime->lookupFunction(0x1A5C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A18A0u; }
        if (ctx->pc != 0x1A18A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5C80_0x1a5c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A18A0u; }
        if (ctx->pc != 0x1A18A0u) { return; }
    }
    ctx->pc = 0x1A18A0u;
label_1a18a0:
    // 0x1a18a0: 0xc068640  jal         func_1A1900
    ctx->pc = 0x1A18A0u;
    SET_GPR_U32(ctx, 31, 0x1A18A8u);
    ctx->pc = 0x1A18A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A18A0u;
            // 0x1a18a4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1900u;
    if (runtime->hasFunction(0x1A1900u)) {
        auto targetFn = runtime->lookupFunction(0x1A1900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A18A8u; }
        if (ctx->pc != 0x1A18A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1900_0x1a1900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A18A8u; }
        if (ctx->pc != 0x1A18A8u) { return; }
    }
    ctx->pc = 0x1A18A8u;
label_1a18a8:
    // 0x1a18a8: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a18a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a18ac: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a18acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a18b0: 0x2442ff30  addiu       $v0, $v0, -0xD0
    ctx->pc = 0x1a18b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967088));
    // 0x1a18b4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a18b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a18b8: 0xac22ffa8  sw          $v0, -0x58($at)
    ctx->pc = 0x1a18b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967208), GPR_U32(ctx, 2));
    // 0x1a18bc: 0x24841b00  addiu       $a0, $a0, 0x1B00
    ctx->pc = 0x1a18bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6912));
    // 0x1a18c0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a18c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a18c4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a18c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a18c8: 0xc068644  jal         func_1A1910
    ctx->pc = 0x1A18C8u;
    SET_GPR_U32(ctx, 31, 0x1A18D0u);
    ctx->pc = 0x1A18CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A18C8u;
            // 0x1a18cc: 0xac22ffac  sw          $v0, -0x54($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294967212), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1910u;
    if (runtime->hasFunction(0x1A1910u)) {
        auto targetFn = runtime->lookupFunction(0x1A1910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A18D0u; }
        if (ctx->pc != 0x1A18D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1910_0x1a1910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A18D0u; }
        if (ctx->pc != 0x1A18D0u) { return; }
    }
    ctx->pc = 0x1A18D0u;
label_1a18d0:
    // 0x1a18d0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1a18d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a18d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a18d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a18d8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a18d8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a18dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A18DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A18E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A18DCu;
            // 0x1a18e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A18A0u: goto label_1a18a0;
            case 0x1A18A8u: goto label_1a18a8;
            case 0x1A18D0u: goto label_1a18d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A18E4u;
    // 0x1a18e4: 0x0  nop
    ctx->pc = 0x1a18e4u;
    // NOP
    // 0x1a18e8: 0x0  nop
    ctx->pc = 0x1a18e8u;
    // NOP
    // 0x1a18ec: 0x0  nop
    ctx->pc = 0x1a18ecu;
    // NOP
    // 0x1a18f0: 0x80697a0  j           func_1A5E80
    ctx->pc = 0x1A18F0u;
    ctx->pc = 0x1A5E80u;
    if (runtime->hasFunction(0x1A5E80u)) {
        auto targetFn = runtime->lookupFunction(0x1A5E80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A5E80_0x1a5e80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A18F8u;
    // 0x1a18f8: 0x0  nop
    ctx->pc = 0x1a18f8u;
    // NOP
    // 0x1a18fc: 0x0  nop
    ctx->pc = 0x1a18fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
