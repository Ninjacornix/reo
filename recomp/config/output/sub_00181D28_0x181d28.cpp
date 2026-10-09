#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181D28
// Address: 0x181d28 - 0x181dc8
void sub_00181D28_0x181d28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181D28_0x181d28");
#endif

    switch (ctx->pc) {
        case 0x181d70u: goto label_181d70;
        case 0x181d80u: goto label_181d80;
        default: break;
    }

    ctx->pc = 0x181d28u;

    // 0x181d28: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181d28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181d2c: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x181d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x181d30: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x181d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x181d34: 0x24529500  addiu       $s2, $v0, -0x6B00
    ctx->pc = 0x181d34u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 4294939904));
    // 0x181d38: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x181d38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x181d3c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x181d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x181d40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x181d40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x181d44: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x181d44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181d48: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x181d48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x181d4c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x181d4cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181d50: 0x10600017  beqz        $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x181D50u;
    {
        const bool branch_taken_0x181d50 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x181D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181D50u;
            // 0x181d54: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181d50) {
            ctx->pc = 0x181DB0u;
            goto label_181db0;
        }
    }
    ctx->pc = 0x181D58u;
    // 0x181d58: 0x56200001  bnel        $s1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x181D58u;
    {
        const bool branch_taken_0x181d58 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x181d58) {
            ctx->pc = 0x181D5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x181D58u;
            // 0x181d5c: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x181D60u;
            goto label_181d60;
        }
    }
    ctx->pc = 0x181D60u;
label_181d60:
    // 0x181d60: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x181D60u;
    {
        const bool branch_taken_0x181d60 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x181D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181D60u;
            // 0x181d64: 0x3c020028  lui         $v0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181d60) {
            ctx->pc = 0x181D78u;
            goto label_181d78;
        }
    }
    ctx->pc = 0x181D68u;
    // 0x181d68: 0xc045198  jal         func_114660
    ctx->pc = 0x181D68u;
    SET_GPR_U32(ctx, 31, 0x181D70u);
    ctx->pc = 0x181D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181D68u;
            // 0x181d6c: 0x8c449a28  lw          $a0, -0x65D8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294941224)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181D70u; }
        if (ctx->pc != 0x181D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181D70u; }
        if (ctx->pc != 0x181D70u) { return; }
    }
    ctx->pc = 0x181D70u;
label_181d70:
    // 0x181d70: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x181D70u;
    {
        const bool branch_taken_0x181d70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x181d70) {
            ctx->pc = 0x181D88u;
            goto label_181d88;
        }
    }
    ctx->pc = 0x181D78u;
label_181d78:
    // 0x181d78: 0xc04519c  jal         func_114670
    ctx->pc = 0x181D78u;
    SET_GPR_U32(ctx, 31, 0x181D80u);
    ctx->pc = 0x181D7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181D78u;
            // 0x181d7c: 0x8c449a28  lw          $a0, -0x65D8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294941224)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114670u;
    if (runtime->hasFunction(0x114670u)) {
        auto targetFn = runtime->lookupFunction(0x114670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181D80u; }
        if (ctx->pc != 0x181D80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181D80u; }
        if (ctx->pc != 0x181D80u) { return; }
    }
    ctx->pc = 0x181D80u;
label_181d80:
    // 0x181d80: 0x440000b  bltz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x181D80u;
    {
        const bool branch_taken_0x181d80 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x181D84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181D80u;
            // 0x181d84: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181d80) {
            ctx->pc = 0x181DB0u;
            goto label_181db0;
        }
    }
    ctx->pc = 0x181D88u;
label_181d88:
    // 0x181d88: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x181D88u;
    {
        const bool branch_taken_0x181d88 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x181d88) {
            ctx->pc = 0x181D98u;
            goto label_181d98;
        }
    }
    ctx->pc = 0x181D90u;
    // 0x181d90: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x181d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x181d94: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x181d94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_181d98:
    // 0x181d98: 0x52200004  beql        $s1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x181D98u;
    {
        const bool branch_taken_0x181d98 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x181d98) {
            ctx->pc = 0x181D9Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x181D98u;
            // 0x181d9c: 0xae400004  sw          $zero, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x181DACu;
            goto label_181dac;
        }
    }
    ctx->pc = 0x181DA0u;
    // 0x181da0: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x181da0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x181da4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x181da4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x181da8: 0xae400004  sw          $zero, 0x4($s2)
    ctx->pc = 0x181da8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 0));
label_181dac:
    // 0x181dac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x181dacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_181db0:
    // 0x181db0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x181db0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181db4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x181db4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x181db8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x181db8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x181dbc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x181dbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x181dc0: 0x3e00008  jr          $ra
    ctx->pc = 0x181DC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181DC0u;
            // 0x181dc4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181D60u: goto label_181d60;
            case 0x181D70u: goto label_181d70;
            case 0x181D78u: goto label_181d78;
            case 0x181D80u: goto label_181d80;
            case 0x181D88u: goto label_181d88;
            case 0x181D98u: goto label_181d98;
            case 0x181DACu: goto label_181dac;
            case 0x181DB0u: goto label_181db0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x181DC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
