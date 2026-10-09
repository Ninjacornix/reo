#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4CF0
// Address: 0x1d4cf0 - 0x1d4d78
void sub_001D4CF0_0x1d4cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4CF0_0x1d4cf0");
#endif

    switch (ctx->pc) {
        case 0x1d4d14u: goto label_1d4d14;
        default: break;
    }

    ctx->pc = 0x1d4cf0u;

    // 0x1d4cf0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d4cf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d4cf4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4cf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4cf8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4cf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d4cfc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4cfcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4d00: 0x80222650  lb          $v0, 0x2650($at)
    ctx->pc = 0x1d4d00u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 9808)));
    // 0x1d4d04: 0x14400016  bnez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1D4D04u;
    {
        const bool branch_taken_0x1d4d04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D04u;
            // 0x1d4d08: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d04) {
            ctx->pc = 0x1D4D60u;
            goto label_1d4d60;
        }
    }
    ctx->pc = 0x1D4D0Cu;
    // 0x1d4d0c: 0xc07544c  jal         func_1D5130
    ctx->pc = 0x1D4D0Cu;
    SET_GPR_U32(ctx, 31, 0x1D4D14u);
    ctx->pc = 0x1D4D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D0Cu;
            // 0x1d4d10: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5130u;
    if (runtime->hasFunction(0x1D5130u)) {
        auto targetFn = runtime->lookupFunction(0x1D5130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4D14u; }
        if (ctx->pc != 0x1D4D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5130_0x1d5130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4D14u; }
        if (ctx->pc != 0x1D4D14u) { return; }
    }
    ctx->pc = 0x1D4D14u;
label_1d4d14:
    // 0x1d4d14: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D4D14u;
    {
        const bool branch_taken_0x1d4d14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d4d14) {
            ctx->pc = 0x1D4D28u;
            goto label_1d4d28;
        }
    }
    ctx->pc = 0x1D4D1Cu;
    // 0x1d4d1c: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4d1cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d4d20: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1D4D20u;
    {
        const bool branch_taken_0x1d4d20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D20u;
            // 0x1d4d24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d20) {
            ctx->pc = 0x1D4D68u;
            goto label_1d4d68;
        }
    }
    ctx->pc = 0x1D4D28u;
label_1d4d28:
    // 0x1d4d28: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4d28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d4d2c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D4D2Cu;
    {
        const bool branch_taken_0x1d4d2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D2Cu;
            // 0x1d4d30: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d2c) {
            ctx->pc = 0x1D4D40u;
            goto label_1d4d40;
        }
    }
    ctx->pc = 0x1D4D34u;
    // 0x1d4d34: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4d34u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d4d38: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1D4D38u;
    {
        const bool branch_taken_0x1d4d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D38u;
            // 0x1d4d3c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d38) {
            ctx->pc = 0x1D4D68u;
            goto label_1d4d68;
        }
    }
    ctx->pc = 0x1D4D40u;
label_1d4d40:
    // 0x1d4d40: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4d44: 0xac202678  sw          $zero, 0x2678($at)
    ctx->pc = 0x1d4d44u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9848), GPR_U32(ctx, 0));
    // 0x1d4d48: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4d48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4d4c: 0xa0222650  sb          $v0, 0x2650($at)
    ctx->pc = 0x1d4d4cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 9808), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d4d50: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1d4d50u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d4d54: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1d4d54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1d4d58: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4D58u;
    {
        const bool branch_taken_0x1d4d58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D58u;
            // 0x1d4d5c: 0xa2030000  sb          $v1, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d58) {
            ctx->pc = 0x1D4D68u;
            goto label_1d4d68;
        }
    }
    ctx->pc = 0x1D4D60u;
label_1d4d60:
    // 0x1d4d60: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4d60u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d4d64: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d4d64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d4d68:
    // 0x1d4d68: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4d68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4d6c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4d6cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4d70: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4D70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D70u;
            // 0x1d4d74: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D68u: goto label_1d4d68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4D78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
