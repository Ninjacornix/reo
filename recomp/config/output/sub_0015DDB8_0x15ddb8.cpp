#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DDB8
// Address: 0x15ddb8 - 0x15de60
void sub_0015DDB8_0x15ddb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DDB8_0x15ddb8");
#endif

    switch (ctx->pc) {
        case 0x15de18u: goto label_15de18;
        case 0x15de20u: goto label_15de20;
        case 0x15de38u: goto label_15de38;
        default: break;
    }

    ctx->pc = 0x15ddb8u;

    // 0x15ddb8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15ddb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15ddbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15ddbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15ddc0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x15ddc0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ddc4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15ddc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15ddc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15ddc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ddcc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15ddccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15ddd0: 0x8ca3003c  lw          $v1, 0x3C($a1)
    ctx->pc = 0x15ddd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 60)));
    // 0x15ddd4: 0x2c620003  sltiu       $v0, $v1, 0x3
    ctx->pc = 0x15ddd4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x15ddd8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15DDD8u;
    {
        const bool branch_taken_0x15ddd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DDDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DDD8u;
            // 0x15dddc: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ddd8) {
            ctx->pc = 0x15DDF0u;
            goto label_15ddf0;
        }
    }
    ctx->pc = 0x15DDE0u;
    // 0x15dde0: 0x5460000d  bnel        $v1, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x15DDE0u;
    {
        const bool branch_taken_0x15dde0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x15dde0) {
            ctx->pc = 0x15DDE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DDE0u;
            // 0x15dde4: 0x24110002  addiu       $s1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DE18u;
            goto label_15de18;
        }
    }
    ctx->pc = 0x15DDE8u;
    // 0x15dde8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x15DDE8u;
    {
        const bool branch_taken_0x15dde8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DDECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DDE8u;
            // 0x15ddec: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dde8) {
            ctx->pc = 0x15DE10u;
            goto label_15de10;
        }
    }
    ctx->pc = 0x15DDF0u;
label_15ddf0:
    // 0x15ddf0: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x15ddf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15ddf4: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15DDF4u;
    {
        const bool branch_taken_0x15ddf4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15DDF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DDF4u;
            // 0x15ddf8: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ddf4) {
            ctx->pc = 0x15DE10u;
            goto label_15de10;
        }
    }
    ctx->pc = 0x15DDFCu;
    // 0x15ddfc: 0x8ca20044  lw          $v0, 0x44($a1)
    ctx->pc = 0x15ddfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 68)));
    // 0x15de00: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15DE00u;
    {
        const bool branch_taken_0x15de00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15de00) {
            ctx->pc = 0x15DE18u;
            goto label_15de18;
        }
    }
    ctx->pc = 0x15DE08u;
    // 0x15de08: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15DE08u;
    {
        const bool branch_taken_0x15de08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DE08u;
            // 0x15de0c: 0x24110002  addiu       $s1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15de08) {
            ctx->pc = 0x15DE18u;
            goto label_15de18;
        }
    }
    ctx->pc = 0x15DE10u;
label_15de10:
    // 0x15de10: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15DE10u;
    SET_GPR_U32(ctx, 31, 0x15DE18u);
    ctx->pc = 0x15DE14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DE10u;
            // 0x15de14: 0x2484ecc8  addiu       $a0, $a0, -0x1338 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962376));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DE18u; }
        if (ctx->pc != 0x15DE18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DE18u; }
        if (ctx->pc != 0x15DE18u) { return; }
    }
    ctx->pc = 0x15DE18u;
label_15de18:
    // 0x15de18: 0xc057a4c  jal         func_15E930
    ctx->pc = 0x15DE18u;
    SET_GPR_U32(ctx, 31, 0x15DE20u);
    ctx->pc = 0x15E930u;
    if (runtime->hasFunction(0x15E930u)) {
        auto targetFn = runtime->lookupFunction(0x15E930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DE20u; }
        if (ctx->pc != 0x15DE20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E930_0x15e930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DE20u; }
        if (ctx->pc != 0x15DE20u) { return; }
    }
    ctx->pc = 0x15DE20u;
label_15de20:
    // 0x15de20: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15de20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15de24: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15de24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15de28: 0x56020007  bnel        $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15DE28u;
    {
        const bool branch_taken_0x15de28 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x15de28) {
            ctx->pc = 0x15DE2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DE28u;
            // 0x15de2c: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DE48u;
            goto label_15de48;
        }
    }
    ctx->pc = 0x15DE30u;
    // 0x15de30: 0xc058830  jal         func_1620C0
    ctx->pc = 0x15DE30u;
    SET_GPR_U32(ctx, 31, 0x15DE38u);
    ctx->pc = 0x15DE34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DE30u;
            // 0x15de34: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1620C0u;
    if (runtime->hasFunction(0x1620C0u)) {
        auto targetFn = runtime->lookupFunction(0x1620C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DE38u; }
        if (ctx->pc != 0x15DE38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001620C0_0x1620c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DE38u; }
        if (ctx->pc != 0x15DE38u) { return; }
    }
    ctx->pc = 0x15DE38u;
label_15de38:
    // 0x15de38: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x15de38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15de3c: 0x501026  xor         $v0, $v0, $s0
    ctx->pc = 0x15de3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 16));
    // 0x15de40: 0x62880a  movz        $s1, $v1, $v0
    ctx->pc = 0x15de40u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 3));
    // 0x15de44: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x15de44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_15de48:
    // 0x15de48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15de48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15de4c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15de4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15de50: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15de50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15de54: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15de54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15de58: 0x3e00008  jr          $ra
    ctx->pc = 0x15DE58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DE58u;
            // 0x15de5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DDF0u: goto label_15ddf0;
            case 0x15DE10u: goto label_15de10;
            case 0x15DE18u: goto label_15de18;
            case 0x15DE20u: goto label_15de20;
            case 0x15DE38u: goto label_15de38;
            case 0x15DE48u: goto label_15de48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15DE60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
