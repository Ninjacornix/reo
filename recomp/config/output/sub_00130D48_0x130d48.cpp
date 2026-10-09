#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130D48
// Address: 0x130d48 - 0x130e18
void sub_00130D48_0x130d48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130D48_0x130d48");
#endif

    switch (ctx->pc) {
        case 0x130d6cu: goto label_130d6c;
        case 0x130d80u: goto label_130d80;
        case 0x130d94u: goto label_130d94;
        case 0x130ddcu: goto label_130ddc;
        default: break;
    }

    ctx->pc = 0x130d48u;

    // 0x130d48: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x130d48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x130d4c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x130d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x130d50: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x130d50u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x130d54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130d58: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x130d58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x130d5c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x130d5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x130d60: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x130d60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x130d64: 0xc050864  jal         func_142190
    ctx->pc = 0x130D64u;
    SET_GPR_U32(ctx, 31, 0x130D6Cu);
    ctx->pc = 0x130D68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130D64u;
            // 0x130d68: 0x2664a8b0  addiu       $a0, $s3, -0x5750 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294944944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142190u;
    if (runtime->hasFunction(0x142190u)) {
        auto targetFn = runtime->lookupFunction(0x142190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130D6Cu; }
        if (ctx->pc != 0x130D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142190_0x142190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130D6Cu; }
        if (ctx->pc != 0x130D6Cu) { return; }
    }
    ctx->pc = 0x130D6Cu;
label_130d6c:
    // 0x130d6c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x130D6Cu;
    {
        const bool branch_taken_0x130d6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x130D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130D6Cu;
            // 0x130d70: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130d6c) {
            ctx->pc = 0x130DA8u;
            goto label_130da8;
        }
    }
    ctx->pc = 0x130D74u;
    // 0x130d74: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x130d74u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130d78: 0x2450a8c0  addiu       $s0, $v0, -0x5740
    ctx->pc = 0x130d78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944960));
    // 0x130d7c: 0x24110027  addiu       $s1, $zero, 0x27
    ctx->pc = 0x130d7cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
label_130d80:
    // 0x130d80: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x130d80u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x130d84: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x130D84u;
    {
        const bool branch_taken_0x130d84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x130d84) {
            ctx->pc = 0x130D88u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x130D84u;
            // 0x130d88: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x130D98u;
            goto label_130d98;
        }
    }
    ctx->pc = 0x130D8Cu;
    // 0x130d8c: 0xc04c2de  jal         func_130B78
    ctx->pc = 0x130D8Cu;
    SET_GPR_U32(ctx, 31, 0x130D94u);
    ctx->pc = 0x130D90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130D8Cu;
            // 0x130d90: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130B78u;
    if (runtime->hasFunction(0x130B78u)) {
        auto targetFn = runtime->lookupFunction(0x130B78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130D94u; }
        if (ctx->pc != 0x130D94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130B78_0x130b78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130D94u; }
        if (ctx->pc != 0x130D94u) { return; }
    }
    ctx->pc = 0x130D94u;
label_130d94:
    // 0x130d94: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x130d94u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_130d98:
    // 0x130d98: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x130D98u;
    {
        const bool branch_taken_0x130d98 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x130D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130D98u;
            // 0x130d9c: 0x2610005c  addiu       $s0, $s0, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 92));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130d98) {
            ctx->pc = 0x130D80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_130d80;
        }
    }
    ctx->pc = 0x130DA0u;
    // 0x130da0: 0x2662a8b0  addiu       $v0, $s3, -0x5750
    ctx->pc = 0x130da0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294944944));
    // 0x130da4: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x130da4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_130da8:
    // 0x130da8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130da8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130dac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x130dacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130db0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x130db0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x130db4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x130db4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x130db8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x130db8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x130dbc: 0x3e00008  jr          $ra
    ctx->pc = 0x130DBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130DBCu;
            // 0x130dc0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130D6Cu: goto label_130d6c;
            case 0x130D80u: goto label_130d80;
            case 0x130D94u: goto label_130d94;
            case 0x130D98u: goto label_130d98;
            case 0x130DA8u: goto label_130da8;
            case 0x130DDCu: goto label_130ddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130DC4u;
    // 0x130dc4: 0x0  nop
    ctx->pc = 0x130dc4u;
    // NOP
    // 0x130dc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130dc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130dcc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130dd0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130dd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130dd4: 0xc04c182  jal         func_130608
    ctx->pc = 0x130DD4u;
    SET_GPR_U32(ctx, 31, 0x130DDCu);
    ctx->pc = 0x130DD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130DD4u;
            // 0x130dd8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130608u;
    if (runtime->hasFunction(0x130608u)) {
        auto targetFn = runtime->lookupFunction(0x130608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130DDCu; }
        if (ctx->pc != 0x130DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130608_0x130608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130DDCu; }
        if (ctx->pc != 0x130DDCu) { return; }
    }
    ctx->pc = 0x130DDCu;
label_130ddc:
    // 0x130ddc: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x130ddcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x130de0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130de0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130de4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130de4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130de8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130de8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130dec: 0x3e00008  jr          $ra
    ctx->pc = 0x130DECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130DECu;
            // 0x130df0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130D6Cu: goto label_130d6c;
            case 0x130D80u: goto label_130d80;
            case 0x130D94u: goto label_130d94;
            case 0x130D98u: goto label_130d98;
            case 0x130DA8u: goto label_130da8;
            case 0x130DDCu: goto label_130ddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130DF4u;
    // 0x130df4: 0x0  nop
    ctx->pc = 0x130df4u;
    // NOP
    // 0x130df8: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x130df8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x130dfc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130e00: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x130e00u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x130e04: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x130e04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x130e08: 0x3e00008  jr          $ra
    ctx->pc = 0x130E08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E08u;
            // 0x130e0c: 0xacc50000  sw          $a1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130D6Cu: goto label_130d6c;
            case 0x130D80u: goto label_130d80;
            case 0x130D94u: goto label_130d94;
            case 0x130D98u: goto label_130d98;
            case 0x130DA8u: goto label_130da8;
            case 0x130DDCu: goto label_130ddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130E10u;
    // 0x130e10: 0x3e00008  jr          $ra
    ctx->pc = 0x130E10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E10u;
            // 0x130e14: 0x8c820004  lw          $v0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130D6Cu: goto label_130d6c;
            case 0x130D80u: goto label_130d80;
            case 0x130D94u: goto label_130d94;
            case 0x130D98u: goto label_130d98;
            case 0x130DA8u: goto label_130da8;
            case 0x130DDCu: goto label_130ddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130E18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
