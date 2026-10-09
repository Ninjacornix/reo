#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4DA0
// Address: 0x1f4da0 - 0x1f4e24
void sub_001F4DA0_0x1f4da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4DA0_0x1f4da0");
#endif

    switch (ctx->pc) {
        case 0x1f4dc8u: goto label_1f4dc8;
        case 0x1f4e04u: goto label_1f4e04;
        case 0x1f4e0cu: goto label_1f4e0c;
        default: break;
    }

    ctx->pc = 0x1f4da0u;

    // 0x1f4da0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f4da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f4da4: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1f4da4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1f4da8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f4da8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f4dac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f4dacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4db0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f4db0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f4db4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f4db4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f4db8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f4db8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4dbc: 0xac820090  sw          $v0, 0x90($a0)
    ctx->pc = 0x1f4dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 144), GPR_U32(ctx, 2));
    // 0x1f4dc0: 0xc07d284  jal         func_1F4A10
    ctx->pc = 0x1F4DC0u;
    SET_GPR_U32(ctx, 31, 0x1F4DC8u);
    ctx->pc = 0x1F4DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4DC0u;
            // 0x1f4dc4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4A10u;
    if (runtime->hasFunction(0x1F4A10u)) {
        auto targetFn = runtime->lookupFunction(0x1F4A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4DC8u; }
        if (ctx->pc != 0x1F4DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4A10_0x1f4a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4DC8u; }
        if (ctx->pc != 0x1F4DC8u) { return; }
    }
    ctx->pc = 0x1F4DC8u;
label_1f4dc8:
    // 0x1f4dc8: 0x9603002c  lhu         $v1, 0x2C($s0)
    ctx->pc = 0x1f4dc8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f4dcc: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1f4dccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f4dd0: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1f4dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1f4dd4: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x1f4dd4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1f4dd8: 0x3084ff00  andi        $a0, $a0, 0xFF00
    ctx->pc = 0x1f4dd8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1f4ddc: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1f4ddcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1f4de0: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1f4de0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1f4de4: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1f4de4u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f4de8: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x1f4de8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1f4dec: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f4decu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f4df0: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x1f4df0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1f4df4: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f4df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f4df8: 0x2343c  dsll32      $a2, $v0, 16
    ctx->pc = 0x1f4df8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f4dfc: 0xc075aa4  jal         func_1D6A90
    ctx->pc = 0x1F4DFCu;
    SET_GPR_U32(ctx, 31, 0x1F4E04u);
    ctx->pc = 0x1F4E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4DFCu;
            // 0x1f4e00: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A90u;
    if (runtime->hasFunction(0x1D6A90u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E04u; }
        if (ctx->pc != 0x1F4E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A90_0x1d6a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E04u; }
        if (ctx->pc != 0x1F4E04u) { return; }
    }
    ctx->pc = 0x1F4E04u;
label_1f4e04:
    // 0x1f4e04: 0xc07d16c  jal         func_1F45B0
    ctx->pc = 0x1F4E04u;
    SET_GPR_U32(ctx, 31, 0x1F4E0Cu);
    ctx->pc = 0x1F4E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4E04u;
            // 0x1f4e08: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45B0u;
    if (runtime->hasFunction(0x1F45B0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E0Cu; }
        if (ctx->pc != 0x1F4E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45B0_0x1f45b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4E0Cu; }
        if (ctx->pc != 0x1F4E0Cu) { return; }
    }
    ctx->pc = 0x1F4E0Cu;
label_1f4e0c:
    // 0x1f4e0c: 0x2841ffff  slti        $at, $v0, -0x1
    ctx->pc = 0x1f4e0cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x1f4e10: 0x1100a  movz        $v0, $zero, $at
    ctx->pc = 0x1f4e10u;
    if (GPR_U64(ctx, 1) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x1f4e14: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f4e14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f4e18: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4e18u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4e1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4E1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4E1Cu;
            // 0x1f4e20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4DC8u: goto label_1f4dc8;
            case 0x1F4E04u: goto label_1f4e04;
            case 0x1F4E0Cu: goto label_1f4e0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4E24u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
