#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155D30
// Address: 0x155d30 - 0x155de0
void sub_00155D30_0x155d30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155D30_0x155d30");
#endif

    switch (ctx->pc) {
        case 0x155d78u: goto label_155d78;
        case 0x155d90u: goto label_155d90;
        default: break;
    }

    ctx->pc = 0x155d30u;

    // 0x155d30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x155d30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x155d34: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x155d34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x155d38: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x155d38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x155d3c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x155d3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155d40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x155d40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x155d44: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x155d44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155d48: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x155d48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x155d4c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x155d4cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155d50: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x155d50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x155d54: 0x16420004  bne         $s2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x155D54u;
    {
        const bool branch_taken_0x155d54 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x155D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D54u;
            // 0x155d58: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155d54) {
            ctx->pc = 0x155D68u;
            goto label_155d68;
        }
    }
    ctx->pc = 0x155D5Cu;
    // 0x155d5c: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x155D5Cu;
    {
        const bool branch_taken_0x155d5c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x155D60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D5Cu;
            // 0x155d60: 0x3c020015  lui         $v0, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155d5c) {
            ctx->pc = 0x155D68u;
            goto label_155d68;
        }
    }
    ctx->pc = 0x155D64u;
    // 0x155d64: 0x24510318  addiu       $s1, $v0, 0x318
    ctx->pc = 0x155d64u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 792));
label_155d68:
    // 0x155d68: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x155D68u;
    {
        const bool branch_taken_0x155d68 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x155d68) {
            ctx->pc = 0x155D88u;
            goto label_155d88;
        }
    }
    ctx->pc = 0x155D70u;
    // 0x155d70: 0xc055778  jal         func_155DE0
    ctx->pc = 0x155D70u;
    SET_GPR_U32(ctx, 31, 0x155D78u);
    ctx->pc = 0x155D74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155D70u;
            // 0x155d74: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155DE0u;
    if (runtime->hasFunction(0x155DE0u)) {
        auto targetFn = runtime->lookupFunction(0x155DE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155D78u; }
        if (ctx->pc != 0x155D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155DE0_0x155de0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155D78u; }
        if (ctx->pc != 0x155D78u) { return; }
    }
    ctx->pc = 0x155D78u;
label_155d78:
    // 0x155d78: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x155d78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x155d7c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x155D7Cu;
    {
        const bool branch_taken_0x155d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x155D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D7Cu;
            // 0x155d80: 0x24444c10  addiu       $a0, $v0, 0x4C10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 19472));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155d7c) {
            ctx->pc = 0x155DBCu;
            goto label_155dbc;
        }
    }
    ctx->pc = 0x155D84u;
    // 0x155d84: 0x0  nop
    ctx->pc = 0x155d84u;
    // NOP
label_155d88:
    // 0x155d88: 0xc05578e  jal         func_155E38
    ctx->pc = 0x155D88u;
    SET_GPR_U32(ctx, 31, 0x155D90u);
    ctx->pc = 0x155D8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155D88u;
            // 0x155d8c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155D90u; }
        if (ctx->pc != 0x155D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155D90u; }
        if (ctx->pc != 0x155D90u) { return; }
    }
    ctx->pc = 0x155D90u;
label_155d90:
    // 0x155d90: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x155d90u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x155d94: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x155D94u;
    {
        const bool branch_taken_0x155d94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x155D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D94u;
            // 0x155d98: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155d94) {
            ctx->pc = 0x155DB8u;
            goto label_155db8;
        }
    }
    ctx->pc = 0x155D9Cu;
    // 0x155d9c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155d9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155da0: 0x34a50202  ori         $a1, $a1, 0x202
    ctx->pc = 0x155da0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)514);
    // 0x155da4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x155da4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155da8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x155da8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x155dac: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x155dacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x155db0: 0x805419c  j           func_150670
    ctx->pc = 0x155DB0u;
    ctx->pc = 0x155DB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155DB0u;
            // 0x155db4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155DB8u;
label_155db8:
    // 0x155db8: 0x26040018  addiu       $a0, $s0, 0x18
    ctx->pc = 0x155db8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
label_155dbc:
    // 0x155dbc: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x155dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x155dc0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x155dc0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x155dc4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x155dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x155dc8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155dc8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155dcc: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x155dccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x155dd0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x155dd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x155dd4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x155dd4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155dd8: 0x3e00008  jr          $ra
    ctx->pc = 0x155DD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155DD8u;
            // 0x155ddc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155D68u: goto label_155d68;
            case 0x155D78u: goto label_155d78;
            case 0x155D88u: goto label_155d88;
            case 0x155D90u: goto label_155d90;
            case 0x155DB8u: goto label_155db8;
            case 0x155DBCu: goto label_155dbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155DE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
