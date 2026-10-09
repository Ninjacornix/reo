#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166CB8
// Address: 0x166cb8 - 0x166db0
void sub_00166CB8_0x166cb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166CB8_0x166cb8");
#endif

    switch (ctx->pc) {
        case 0x166ce0u: goto label_166ce0;
        case 0x166d28u: goto label_166d28;
        case 0x166d58u: goto label_166d58;
        case 0x166d70u: goto label_166d70;
        case 0x166d88u: goto label_166d88;
        default: break;
    }

    ctx->pc = 0x166cb8u;

    // 0x166cb8: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x166cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x166cbc: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x166cbcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x166cc0: 0xac820050  sw          $v0, 0x50($a0)
    ctx->pc = 0x166cc0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 80), GPR_U32(ctx, 2));
    // 0x166cc4: 0xac860004  sw          $a2, 0x4($a0)
    ctx->pc = 0x166cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
    // 0x166cc8: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x166cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x166ccc: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x166cccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x166cd0: 0x3e00008  jr          $ra
    ctx->pc = 0x166CD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166CD0u;
            // 0x166cd4: 0xac82004c  sw          $v0, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166CE0u: goto label_166ce0;
            case 0x166D28u: goto label_166d28;
            case 0x166D50u: goto label_166d50;
            case 0x166D58u: goto label_166d58;
            case 0x166D70u: goto label_166d70;
            case 0x166D88u: goto label_166d88;
            case 0x166D98u: goto label_166d98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166CD8u;
    // 0x166cd8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x166cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x166cdc: 0x0  nop
    ctx->pc = 0x166cdcu;
    // NOP
label_166ce0:
    // 0x166ce0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x166ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x166ce4: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x166ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x166ce8: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x166ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x166cec: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x166cecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x166cf0: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x166cf0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x166cf4: 0x441fffa  bgez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x166CF4u;
    {
        const bool branch_taken_0x166cf4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x166CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166CF4u;
            // 0x166cf8: 0x24840010  addiu       $a0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166cf4) {
            ctx->pc = 0x166CE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_166ce0;
        }
    }
    ctx->pc = 0x166CFCu;
    // 0x166cfc: 0x3e00008  jr          $ra
    ctx->pc = 0x166CFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166CE0u: goto label_166ce0;
            case 0x166D28u: goto label_166d28;
            case 0x166D50u: goto label_166d50;
            case 0x166D58u: goto label_166d58;
            case 0x166D70u: goto label_166d70;
            case 0x166D88u: goto label_166d88;
            case 0x166D98u: goto label_166d98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166D04u;
    // 0x166d04: 0x0  nop
    ctx->pc = 0x166d04u;
    // NOP
    // 0x166d08: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166d08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x166d0c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166d0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166d10: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x166d10u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166d14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166d18: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x166d18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166d1c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x166d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x166d20: 0xc059b6c  jal         func_166DB0
    ctx->pc = 0x166D20u;
    SET_GPR_U32(ctx, 31, 0x166D28u);
    ctx->pc = 0x166D24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166D20u;
            // 0x166d24: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166DB0u;
    if (runtime->hasFunction(0x166DB0u)) {
        auto targetFn = runtime->lookupFunction(0x166DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166D28u; }
        if (ctx->pc != 0x166D28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166DB0_0x166db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166D28u; }
        if (ctx->pc != 0x166D28u) { return; }
    }
    ctx->pc = 0x166D28u;
label_166d28:
    // 0x166d28: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166d28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166d2c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x166D2Cu;
    {
        const bool branch_taken_0x166d2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166D2Cu;
            // 0x166d30: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166d2c) {
            ctx->pc = 0x166D50u;
            goto label_166d50;
        }
    }
    ctx->pc = 0x166D34u;
    // 0x166d34: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x166d34u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166d38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166d38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166d3c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166d3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166d40: 0x34a50408  ori         $a1, $a1, 0x408
    ctx->pc = 0x166d40u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1032);
    // 0x166d44: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166d44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166d48: 0x805a704  j           func_169C10
    ctx->pc = 0x166D48u;
    ctx->pc = 0x166D4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166D48u;
            // 0x166d4c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166D50u;
label_166d50:
    // 0x166d50: 0xc05df24  jal         func_177C90
    ctx->pc = 0x166D50u;
    SET_GPR_U32(ctx, 31, 0x166D58u);
    ctx->pc = 0x166D54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166D50u;
            // 0x166d54: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C90u;
    if (runtime->hasFunction(0x177C90u)) {
        auto targetFn = runtime->lookupFunction(0x177C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166D58u; }
        if (ctx->pc != 0x166D58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C90_0x177c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166D58u; }
        if (ctx->pc != 0x166D58u) { return; }
    }
    ctx->pc = 0x166D58u;
label_166d58:
    // 0x166d58: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166d58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166d5c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x166d5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x166d60: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x166D60u;
    {
        const bool branch_taken_0x166d60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x166D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166D60u;
            // 0x166d64: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166d60) {
            ctx->pc = 0x166D98u;
            goto label_166d98;
        }
    }
    ctx->pc = 0x166D68u;
    // 0x166d68: 0xc05df24  jal         func_177C90
    ctx->pc = 0x166D68u;
    SET_GPR_U32(ctx, 31, 0x166D70u);
    ctx->pc = 0x177C90u;
    if (runtime->hasFunction(0x177C90u)) {
        auto targetFn = runtime->lookupFunction(0x177C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166D70u; }
        if (ctx->pc != 0x166D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C90_0x177c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166D70u; }
        if (ctx->pc != 0x166D70u) { return; }
    }
    ctx->pc = 0x166D70u;
label_166d70:
    // 0x166d70: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166d70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166d74: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x166d74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x166d78: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x166D78u;
    {
        const bool branch_taken_0x166d78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x166D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166D78u;
            // 0x166d7c: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166d78) {
            ctx->pc = 0x166D98u;
            goto label_166d98;
        }
    }
    ctx->pc = 0x166D80u;
    // 0x166d80: 0xc05df24  jal         func_177C90
    ctx->pc = 0x166D80u;
    SET_GPR_U32(ctx, 31, 0x166D88u);
    ctx->pc = 0x177C90u;
    if (runtime->hasFunction(0x177C90u)) {
        auto targetFn = runtime->lookupFunction(0x177C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166D88u; }
        if (ctx->pc != 0x166D88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C90_0x177c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166D88u; }
        if (ctx->pc != 0x166D88u) { return; }
    }
    ctx->pc = 0x166D88u;
label_166d88:
    // 0x166d88: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x166d88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x166d8c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x166d8cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166d90: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x166d90u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x166d94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166d94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_166d98:
    // 0x166d98: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166d98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166d9c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x166d9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166da0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166da0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166da4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166da4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166da8: 0x8059b7e  j           func_166DF8
    ctx->pc = 0x166DA8u;
    ctx->pc = 0x166DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166DA8u;
            // 0x166dac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166DF8u;
    if (runtime->hasFunction(0x166DF8u)) {
        auto targetFn = runtime->lookupFunction(0x166DF8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00166DF8_0x166df8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166DB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
