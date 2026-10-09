#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C02A0
// Address: 0x1c02a0 - 0x1c0370
void sub_001C02A0_0x1c02a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C02A0_0x1c02a0");
#endif

    switch (ctx->pc) {
        case 0x1c02d4u: goto label_1c02d4;
        case 0x1c0310u: goto label_1c0310;
        case 0x1c0338u: goto label_1c0338;
        default: break;
    }

    ctx->pc = 0x1c02a0u;

    // 0x1c02a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c02a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c02a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c02a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c02a8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c02a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c02ac: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c02acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c02b0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1c02b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c02b4: 0x1062001e  beq         $v1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1C02B4u;
    {
        const bool branch_taken_0x1c02b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C02B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C02B4u;
            // 0x1c02b8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c02b4) {
            ctx->pc = 0x1C0330u;
            goto label_1c0330;
        }
    }
    ctx->pc = 0x1C02BCu;
    // 0x1c02bc: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C02BCu;
    {
        const bool branch_taken_0x1c02bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c02bc) {
            ctx->pc = 0x1C02CCu;
            goto label_1c02cc;
        }
    }
    ctx->pc = 0x1C02C4u;
    // 0x1c02c4: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1C02C4u;
    {
        const bool branch_taken_0x1c02c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C02C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C02C4u;
            // 0x1c02c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c02c4) {
            ctx->pc = 0x1C0354u;
            goto label_1c0354;
        }
    }
    ctx->pc = 0x1C02CCu;
label_1c02cc:
    // 0x1c02cc: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1C02CCu;
    SET_GPR_U32(ctx, 31, 0x1C02D4u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C02D4u; }
        if (ctx->pc != 0x1C02D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C02D4u; }
        if (ctx->pc != 0x1C02D4u) { return; }
    }
    ctx->pc = 0x1C02D4u;
label_1c02d4:
    // 0x1c02d4: 0x440001e  bltz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1C02D4u;
    {
        const bool branch_taken_0x1c02d4 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c02d4) {
            ctx->pc = 0x1C0350u;
            goto label_1c0350;
        }
    }
    ctx->pc = 0x1C02DCu;
    // 0x1c02dc: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x1c02dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x1c02e0: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1c02e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1c02e4: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1c02e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1c02e8: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1c02e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1c02ec: 0x8e08009c  lw          $t0, 0x9C($s0)
    ctx->pc = 0x1c02ecu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 156)));
    // 0x1c02f0: 0x26050044  addiu       $a1, $s0, 0x44
    ctx->pc = 0x1c02f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x1c02f4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1c02f4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c02f8: 0x24070100  addiu       $a3, $zero, 0x100
    ctx->pc = 0x1c02f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1c02fc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c02fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c0300: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c0300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c0304: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1c0304u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c0308: 0xc060558  jal         func_181560
    ctx->pc = 0x1C0308u;
    SET_GPR_U32(ctx, 31, 0x1C0310u);
    ctx->pc = 0x1C030Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0308u;
            // 0x1c030c: 0x2609000c  addiu       $t1, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181560u;
    if (runtime->hasFunction(0x181560u)) {
        auto targetFn = runtime->lookupFunction(0x181560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0310u; }
        if (ctx->pc != 0x1C0310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181560_0x181560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0310u; }
        if (ctx->pc != 0x1C0310u) { return; }
    }
    ctx->pc = 0x1C0310u;
label_1c0310:
    // 0x1c0310: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0310u;
    {
        const bool branch_taken_0x1c0310 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1c0310) {
            ctx->pc = 0x1C0320u;
            goto label_1c0320;
        }
    }
    ctx->pc = 0x1C0318u;
    // 0x1c0318: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1C0318u;
    {
        const bool branch_taken_0x1c0318 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C031Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0318u;
            // 0x1c031c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0318) {
            ctx->pc = 0x1C0354u;
            goto label_1c0354;
        }
    }
    ctx->pc = 0x1C0320u;
label_1c0320:
    // 0x1c0320: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1c0320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c0324: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0324u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0328: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C0328u;
    {
        const bool branch_taken_0x1c0328 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C032Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0328u;
            // 0x1c032c: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0328) {
            ctx->pc = 0x1C0350u;
            goto label_1c0350;
        }
    }
    ctx->pc = 0x1C0330u;
label_1c0330:
    // 0x1c0330: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1C0330u;
    SET_GPR_U32(ctx, 31, 0x1C0338u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0338u; }
        if (ctx->pc != 0x1C0338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0338u; }
        if (ctx->pc != 0x1C0338u) { return; }
    }
    ctx->pc = 0x1C0338u;
label_1c0338:
    // 0x1c0338: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C0338u;
    {
        const bool branch_taken_0x1c0338 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c0338) {
            ctx->pc = 0x1C0350u;
            goto label_1c0350;
        }
    }
    ctx->pc = 0x1C0340u;
    // 0x1c0340: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1c0340u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1c0344: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1c0344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c0348: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C0348u;
    {
        const bool branch_taken_0x1c0348 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C034Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0348u;
            // 0x1c034c: 0x40102a  slt         $v0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0348) {
            ctx->pc = 0x1C0354u;
            goto label_1c0354;
        }
    }
    ctx->pc = 0x1C0350u;
label_1c0350:
    // 0x1c0350: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c0350u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1c0354:
    // 0x1c0354: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c0354u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0358: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0358u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c035c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C035Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C035Cu;
            // 0x1c0360: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C02CCu: goto label_1c02cc;
            case 0x1C02D4u: goto label_1c02d4;
            case 0x1C0310u: goto label_1c0310;
            case 0x1C0320u: goto label_1c0320;
            case 0x1C0330u: goto label_1c0330;
            case 0x1C0338u: goto label_1c0338;
            case 0x1C0350u: goto label_1c0350;
            case 0x1C0354u: goto label_1c0354;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0364u;
    // 0x1c0364: 0x0  nop
    ctx->pc = 0x1c0364u;
    // NOP
    // 0x1c0368: 0x0  nop
    ctx->pc = 0x1c0368u;
    // NOP
    // 0x1c036c: 0x0  nop
    ctx->pc = 0x1c036cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
