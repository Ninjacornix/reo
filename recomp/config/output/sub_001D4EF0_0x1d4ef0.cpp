#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4EF0
// Address: 0x1d4ef0 - 0x1d4f68
void sub_001D4EF0_0x1d4ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4EF0_0x1d4ef0");
#endif

    switch (ctx->pc) {
        case 0x1d4f0cu: goto label_1d4f0c;
        case 0x1d4f24u: goto label_1d4f24;
        default: break;
    }

    ctx->pc = 0x1d4ef0u;

    // 0x1d4ef0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d4ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d4ef4: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1d4ef4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d4ef8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d4efc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4efcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4f00: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d4f00u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4f04: 0xc0755cc  jal         func_1D5730
    ctx->pc = 0x1D4F04u;
    SET_GPR_U32(ctx, 31, 0x1D4F0Cu);
    ctx->pc = 0x1D4F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F04u;
            // 0x1d4f08: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5730u;
    if (runtime->hasFunction(0x1D5730u)) {
        auto targetFn = runtime->lookupFunction(0x1D5730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4F0Cu; }
        if (ctx->pc != 0x1D4F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5730_0x1d5730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4F0Cu; }
        if (ctx->pc != 0x1D4F0Cu) { return; }
    }
    ctx->pc = 0x1D4F0Cu;
label_1d4f0c:
    // 0x1d4f0c: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1d4f10: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4f10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d4f14: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D4F14u;
    {
        const bool branch_taken_0x1d4f14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F14u;
            // 0x1d4f18: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4f14) {
            ctx->pc = 0x1D4F54u;
            goto label_1d4f54;
        }
    }
    ctx->pc = 0x1D4F1Cu;
    // 0x1d4f1c: 0xc075646  jal         func_1D5918
    ctx->pc = 0x1D4F1Cu;
    SET_GPR_U32(ctx, 31, 0x1D4F24u);
    ctx->pc = 0x1D4F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F1Cu;
            // 0x1d4f20: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5918u;
    if (runtime->hasFunction(0x1D5918u)) {
        auto targetFn = runtime->lookupFunction(0x1D5918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4F24u; }
        if (ctx->pc != 0x1D4F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4F24u; }
        if (ctx->pc != 0x1D4F24u) { return; }
    }
    ctx->pc = 0x1D4F24u;
label_1d4f24:
    // 0x1d4f24: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4f28: 0xac222678  sw          $v0, 0x2678($at)
    ctx->pc = 0x1d4f28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9848), GPR_U32(ctx, 2));
    // 0x1d4f2c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4f30: 0x8c222678  lw          $v0, 0x2678($at)
    ctx->pc = 0x1d4f30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9848)));
    // 0x1d4f34: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D4F34u;
    {
        const bool branch_taken_0x1d4f34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4f34) {
            ctx->pc = 0x1D4F54u;
            goto label_1d4f54;
        }
    }
    ctx->pc = 0x1D4F3Cu;
    // 0x1d4f3c: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d4f40: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D4F40u;
    {
        const bool branch_taken_0x1d4f40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4f40) {
            ctx->pc = 0x1D4F54u;
            goto label_1d4f54;
        }
    }
    ctx->pc = 0x1D4F48u;
    // 0x1d4f48: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1d4f48u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d4f4c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d4f4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d4f50: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1d4f50u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
label_1d4f54:
    // 0x1d4f54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4f54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4f58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4f58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4f5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4f5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4f60: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F60u;
            // 0x1d4f64: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F54u: goto label_1d4f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4F68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
