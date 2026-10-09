#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D49E0
// Address: 0x1d49e0 - 0x1d4a4c
void sub_001D49E0_0x1d49e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D49E0_0x1d49e0");
#endif

    switch (ctx->pc) {
        case 0x1d4a14u: goto label_1d4a14;
        case 0x1d4a2cu: goto label_1d4a2c;
        default: break;
    }

    ctx->pc = 0x1d49e0u;

    // 0x1d49e0: 0x27bdfee0  addiu       $sp, $sp, -0x120
    ctx->pc = 0x1d49e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967008));
    // 0x1d49e4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d49e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d49e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d49e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d49ec: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d49ecu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d49f0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d49f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d49f4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d49f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d49f8: 0x8c30446c  lw          $s0, 0x446C($at)
    ctx->pc = 0x1d49f8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17516)));
    // 0x1d49fc: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d49fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4a00: 0x24a56a38  addiu       $a1, $a1, 0x6A38
    ctx->pc = 0x1d4a00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27192));
    // 0x1d4a04: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4a04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4a08: 0x942743da  lhu         $a3, 0x43DA($at)
    ctx->pc = 0x1d4a08u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d4a0c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4A0Cu;
    SET_GPR_U32(ctx, 31, 0x1D4A14u);
    ctx->pc = 0x1D4A10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4A0Cu;
            // 0x1d4a10: 0x24c66a50  addiu       $a2, $a2, 0x6A50 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 27216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A14u; }
        if (ctx->pc != 0x1D4A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A14u; }
        if (ctx->pc != 0x1D4A14u) { return; }
    }
    ctx->pc = 0x1D4A14u;
label_1d4a14:
    // 0x1d4a14: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d4a14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d4a18: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d4a18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4a1c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d4a1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a20: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d4a20u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a24: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4A24u;
    SET_GPR_U32(ctx, 31, 0x1D4A2Cu);
    ctx->pc = 0x1D4A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4A24u;
            // 0x1d4a28: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A2Cu; }
        if (ctx->pc != 0x1D4A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A2Cu; }
        if (ctx->pc != 0x1D4A2Cu) { return; }
    }
    ctx->pc = 0x1D4A2Cu;
label_1d4a2c:
    // 0x1d4a2c: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4A2Cu;
    {
        const bool branch_taken_0x1d4a2c = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1d4a2c) {
            ctx->pc = 0x1D4A3Cu;
            goto label_1d4a3c;
        }
    }
    ctx->pc = 0x1D4A34u;
    // 0x1d4a34: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d4a34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d4a38: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1d4a38u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
label_1d4a3c:
    // 0x1d4a3c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4a3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4a40: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4a40u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4a44: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4A44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4A44u;
            // 0x1d4a48: 0x27bd0120  addiu       $sp, $sp, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 288));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4A14u: goto label_1d4a14;
            case 0x1D4A2Cu: goto label_1d4a2c;
            case 0x1D4A3Cu: goto label_1d4a3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4A4Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
