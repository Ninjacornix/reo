#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016DBF8
// Address: 0x16dbf8 - 0x16dd98
void sub_0016DBF8_0x16dbf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016DBF8_0x16dbf8");
#endif

    switch (ctx->pc) {
        case 0x16dc24u: goto label_16dc24;
        case 0x16dc34u: goto label_16dc34;
        case 0x16dc44u: goto label_16dc44;
        case 0x16dc50u: goto label_16dc50;
        case 0x16dcccu: goto label_16dccc;
        case 0x16dd1cu: goto label_16dd1c;
        default: break;
    }

    ctx->pc = 0x16dbf8u;

    // 0x16dbf8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16dbf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16dbfc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16dbfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dc00: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16dc00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x16dc04: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16dc04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dc08: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x16dc08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x16dc0c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x16dc0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dc10: 0x8e030d04  lw          $v1, 0xD04($s0)
    ctx->pc = 0x16dc10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3332)));
    // 0x16dc14: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x16DC14u;
    {
        const bool branch_taken_0x16dc14 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DC18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DC14u;
            // 0x16dc18: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dc14) {
            ctx->pc = 0x16DC78u;
            goto label_16dc78;
        }
    }
    ctx->pc = 0x16DC1Cu;
    // 0x16dc1c: 0xc05b87c  jal         func_16E1F0
    ctx->pc = 0x16DC1Cu;
    SET_GPR_U32(ctx, 31, 0x16DC24u);
    ctx->pc = 0x16E1F0u;
    if (runtime->hasFunction(0x16E1F0u)) {
        auto targetFn = runtime->lookupFunction(0x16E1F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DC24u; }
        if (ctx->pc != 0x16DC24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E1F0_0x16e1f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DC24u; }
        if (ctx->pc != 0x16DC24u) { return; }
    }
    ctx->pc = 0x16DC24u;
label_16dc24:
    // 0x16dc24: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16dc24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dc28: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x16dc28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x16dc2c: 0xc05da70  jal         func_1769C0
    ctx->pc = 0x16DC2Cu;
    SET_GPR_U32(ctx, 31, 0x16DC34u);
    ctx->pc = 0x16DC30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DC2Cu;
            // 0x16dc30: 0x27a60024  addiu       $a2, $sp, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769C0u;
    if (runtime->hasFunction(0x1769C0u)) {
        auto targetFn = runtime->lookupFunction(0x1769C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DC34u; }
        if (ctx->pc != 0x16DC34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769C0_0x1769c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DC34u; }
        if (ctx->pc != 0x16DC34u) { return; }
    }
    ctx->pc = 0x16DC34u;
label_16dc34:
    // 0x16dc34: 0x26040d08  addiu       $a0, $s0, 0xD08
    ctx->pc = 0x16dc34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 3336));
    // 0x16dc38: 0x27a50028  addiu       $a1, $sp, 0x28
    ctx->pc = 0x16dc38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x16dc3c: 0xc05da70  jal         func_1769C0
    ctx->pc = 0x16DC3Cu;
    SET_GPR_U32(ctx, 31, 0x16DC44u);
    ctx->pc = 0x16DC40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DC3Cu;
            // 0x16dc40: 0x27a60024  addiu       $a2, $sp, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769C0u;
    if (runtime->hasFunction(0x1769C0u)) {
        auto targetFn = runtime->lookupFunction(0x1769C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DC44u; }
        if (ctx->pc != 0x16DC44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769C0_0x1769c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DC44u; }
        if (ctx->pc != 0x16DC44u) { return; }
    }
    ctx->pc = 0x16DC44u;
label_16dc44:
    // 0x16dc44: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16dc44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dc48: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16DC48u;
    SET_GPR_U32(ctx, 31, 0x16DC50u);
    ctx->pc = 0x16DC4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DC48u;
            // 0x16dc4c: 0x24050035  addiu       $a1, $zero, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DC50u; }
        if (ctx->pc != 0x16DC50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DC50u; }
        if (ctx->pc != 0x16DC50u) { return; }
    }
    ctx->pc = 0x16DC50u;
label_16dc50:
    // 0x16dc50: 0x8fa60020  lw          $a2, 0x20($sp)
    ctx->pc = 0x16dc50u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16dc54: 0x8fa50028  lw          $a1, 0x28($sp)
    ctx->pc = 0x16dc54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16dc58: 0x8fa30024  lw          $v1, 0x24($sp)
    ctx->pc = 0x16dc58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x16dc5c: 0xa6202a  slt         $a0, $a1, $a2
    ctx->pc = 0x16dc5cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x16dc60: 0x431818  mult        $v1, $v0, $v1
    ctx->pc = 0x16dc60u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x16dc64: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16DC64u;
    {
        const bool branch_taken_0x16dc64 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DC68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DC64u;
            // 0x16dc68: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dc64) {
            ctx->pc = 0x16DC78u;
            goto label_16dc78;
        }
    }
    ctx->pc = 0x16DC6Cu;
    // 0x16dc6c: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x16dc6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x16dc70: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x16dc70u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16dc74: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x16dc74u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_16dc78:
    // 0x16dc78: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x16dc78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16dc7c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x16dc7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16dc80: 0x3e00008  jr          $ra
    ctx->pc = 0x16DC80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16DC84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DC80u;
            // 0x16dc84: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16DC24u: goto label_16dc24;
            case 0x16DC34u: goto label_16dc34;
            case 0x16DC44u: goto label_16dc44;
            case 0x16DC50u: goto label_16dc50;
            case 0x16DC78u: goto label_16dc78;
            case 0x16DCCCu: goto label_16dccc;
            case 0x16DCD8u: goto label_16dcd8;
            case 0x16DCDCu: goto label_16dcdc;
            case 0x16DD08u: goto label_16dd08;
            case 0x16DD1Cu: goto label_16dd1c;
            case 0x16DD20u: goto label_16dd20;
            case 0x16DD40u: goto label_16dd40;
            case 0x16DD88u: goto label_16dd88;
            case 0x16DD8Cu: goto label_16dd8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16DC88u;
    // 0x16dc88: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16dc88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16dc8c: 0xe0182d  daddu       $v1, $a3, $zero
    ctx->pc = 0x16dc8cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dc90: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16dc90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16dc94: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16dc94u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dc98: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16dc98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16dc9c: 0x24880d08  addiu       $t0, $a0, 0xD08
    ctx->pc = 0x16dc9cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), 3336));
    // 0x16dca0: 0x24820d04  addiu       $v0, $a0, 0xD04
    ctx->pc = 0x16dca0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 3332));
    // 0x16dca4: 0x8e070014  lw          $a3, 0x14($s0)
    ctx->pc = 0x16dca4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x16dca8: 0x8e09001c  lw          $t1, 0x1C($s0)
    ctx->pc = 0x16dca8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16dcac: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x16DCACu;
    {
        const bool branch_taken_0x16dcac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DCB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DCACu;
            // 0x16dcb0: 0x8e050010  lw          $a1, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dcac) {
            ctx->pc = 0x16DCD8u;
            goto label_16dcd8;
        }
    }
    ctx->pc = 0x16DCB4u;
    // 0x16dcb4: 0x4c20009  bltzl       $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x16DCB4u;
    {
        const bool branch_taken_0x16dcb4 = (GPR_S64(ctx, 6) < 0);
        if (branch_taken_0x16dcb4) {
            ctx->pc = 0x16DCB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DCB4u;
            // 0x16dcb8: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DCDCu;
            goto label_16dcdc;
        }
    }
    ctx->pc = 0x16DCBCu;
    // 0x16dcbc: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x16dcbcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dcc0: 0x120302d  daddu       $a2, $t1, $zero
    ctx->pc = 0x16dcc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dcc4: 0xc05b766  jal         func_16DD98
    ctx->pc = 0x16DCC4u;
    SET_GPR_U32(ctx, 31, 0x16DCCCu);
    ctx->pc = 0x16DCC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DCC4u;
            // 0x16dcc8: 0x3a0402d  daddu       $t0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16DD98u;
    if (runtime->hasFunction(0x16DD98u)) {
        auto targetFn = runtime->lookupFunction(0x16DD98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DCCCu; }
        if (ctx->pc != 0x16DCCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016DD98_0x16dd98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DCCCu; }
        if (ctx->pc != 0x16DCCCu) { return; }
    }
    ctx->pc = 0x16DCCCu;
label_16dccc:
    // 0x16dccc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x16DCCCu;
    {
        const bool branch_taken_0x16dccc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DCD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DCCCu;
            // 0x16dcd0: 0x8fa30008  lw          $v1, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dccc) {
            ctx->pc = 0x16DD20u;
            goto label_16dd20;
        }
    }
    ctx->pc = 0x16DCD4u;
    // 0x16dcd4: 0x0  nop
    ctx->pc = 0x16dcd4u;
    // NOP
label_16dcd8:
    // 0x16dcd8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x16dcd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_16dcdc:
    // 0x16dcdc: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16DCDCu;
    {
        const bool branch_taken_0x16dcdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16dcdc) {
            ctx->pc = 0x16DD08u;
            goto label_16dd08;
        }
    }
    ctx->pc = 0x16DCE4u;
    // 0x16dce4: 0x8c822ab0  lw          $v0, 0x2AB0($a0)
    ctx->pc = 0x16dce4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10928)));
    // 0x16dce8: 0x54400028  bnel        $v0, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x16DCE8u;
    {
        const bool branch_taken_0x16dce8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16dce8) {
            ctx->pc = 0x16DCECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DCE8u;
            // 0x16dcec: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DD8Cu;
            goto label_16dd8c;
        }
    }
    ctx->pc = 0x16DCF0u;
    // 0x16dcf0: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x16dcf0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x16dcf4: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x16dcf4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x16dcf8: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x16dcf8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x16dcfc: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x16dcfcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x16dd00: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x16DD00u;
    {
        const bool branch_taken_0x16dd00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DD04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DD00u;
            // 0x16dd04: 0xae000028  sw          $zero, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dd00) {
            ctx->pc = 0x16DD88u;
            goto label_16dd88;
        }
    }
    ctx->pc = 0x16DD08u;
label_16dd08:
    // 0x16dd08: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x16DD08u;
    {
        const bool branch_taken_0x16dd08 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DD0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DD08u;
            // 0x16dd0c: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dd08) {
            ctx->pc = 0x16DD40u;
            goto label_16dd40;
        }
    }
    ctx->pc = 0x16DD10u;
    // 0x16dd10: 0x120302d  daddu       $a2, $t1, $zero
    ctx->pc = 0x16dd10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dd14: 0xc05b7e0  jal         func_16DF80
    ctx->pc = 0x16DD14u;
    SET_GPR_U32(ctx, 31, 0x16DD1Cu);
    ctx->pc = 0x16DD18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DD14u;
            // 0x16dd18: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16DF80u;
    if (runtime->hasFunction(0x16DF80u)) {
        auto targetFn = runtime->lookupFunction(0x16DF80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DD1Cu; }
        if (ctx->pc != 0x16DD1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016DF80_0x16df80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DD1Cu; }
        if (ctx->pc != 0x16DD1Cu) { return; }
    }
    ctx->pc = 0x16DD1Cu;
label_16dd1c:
    // 0x16dd1c: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x16dd1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
label_16dd20:
    // 0x16dd20: 0x8fa4000c  lw          $a0, 0xC($sp)
    ctx->pc = 0x16dd20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16dd24: 0x8fa50010  lw          $a1, 0x10($sp)
    ctx->pc = 0x16dd24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16dd28: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x16dd28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x16dd2c: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x16dd2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x16dd30: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x16dd30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x16dd34: 0xae040024  sw          $a0, 0x24($s0)
    ctx->pc = 0x16dd34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 4));
    // 0x16dd38: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x16DD38u;
    {
        const bool branch_taken_0x16dd38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DD3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DD38u;
            // 0x16dd3c: 0xae050028  sw          $a1, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dd38) {
            ctx->pc = 0x16DD88u;
            goto label_16dd88;
        }
    }
    ctx->pc = 0x16DD40u;
label_16dd40:
    // 0x16dd40: 0x8d020008  lw          $v0, 0x8($t0)
    ctx->pc = 0x16dd40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x16dd44: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x16dd44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x16dd48: 0x8d03000c  lw          $v1, 0xC($t0)
    ctx->pc = 0x16dd48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
    // 0x16dd4c: 0xae030024  sw          $v1, 0x24($s0)
    ctx->pc = 0x16dd4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 3));
    // 0x16dd50: 0x8d020010  lw          $v0, 0x10($t0)
    ctx->pc = 0x16dd50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 16)));
    // 0x16dd54: 0xae020028  sw          $v0, 0x28($s0)
    ctx->pc = 0x16dd54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 2));
    // 0x16dd58: 0x8d040014  lw          $a0, 0x14($t0)
    ctx->pc = 0x16dd58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 20)));
    // 0x16dd5c: 0xae04002c  sw          $a0, 0x2C($s0)
    ctx->pc = 0x16dd5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x16dd60: 0x8d030018  lw          $v1, 0x18($t0)
    ctx->pc = 0x16dd60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 24)));
    // 0x16dd64: 0x671823  subu        $v1, $v1, $a3
    ctx->pc = 0x16dd64u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x16dd68: 0x24620337  addiu       $v0, $v1, 0x337
    ctx->pc = 0x16dd68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 823));
    // 0x16dd6c: 0x24630736  addiu       $v1, $v1, 0x736
    ctx->pc = 0x16dd6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1846));
    // 0x16dd70: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x16dd70u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16dd74: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x16dd74u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x16dd78: 0x21283  sra         $v0, $v0, 10
    ctx->pc = 0x16dd78u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 10));
    // 0x16dd7c: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x16dd7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x16dd80: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x16dd80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x16dd84: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x16dd84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
label_16dd88:
    // 0x16dd88: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16dd88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_16dd8c:
    // 0x16dd8c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16dd8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16dd90: 0x3e00008  jr          $ra
    ctx->pc = 0x16DD90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16DD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DD90u;
            // 0x16dd94: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16DC24u: goto label_16dc24;
            case 0x16DC34u: goto label_16dc34;
            case 0x16DC44u: goto label_16dc44;
            case 0x16DC50u: goto label_16dc50;
            case 0x16DC78u: goto label_16dc78;
            case 0x16DCCCu: goto label_16dccc;
            case 0x16DCD8u: goto label_16dcd8;
            case 0x16DCDCu: goto label_16dcdc;
            case 0x16DD08u: goto label_16dd08;
            case 0x16DD1Cu: goto label_16dd1c;
            case 0x16DD20u: goto label_16dd20;
            case 0x16DD40u: goto label_16dd40;
            case 0x16DD88u: goto label_16dd88;
            case 0x16DD8Cu: goto label_16dd8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16DD98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
