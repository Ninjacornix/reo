#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DF60
// Address: 0x11df60 - 0x11e1a0
void sub_0011DF60_0x11df60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DF60_0x11df60");
#endif

    switch (ctx->pc) {
        case 0x11dfbcu: goto label_11dfbc;
        case 0x11dfd0u: goto label_11dfd0;
        case 0x11dff8u: goto label_11dff8;
        case 0x11e010u: goto label_11e010;
        case 0x11e030u: goto label_11e030;
        case 0x11e068u: goto label_11e068;
        case 0x11e070u: goto label_11e070;
        case 0x11e078u: goto label_11e078;
        case 0x11e080u: goto label_11e080;
        case 0x11e090u: goto label_11e090;
        case 0x11e10cu: goto label_11e10c;
        case 0x11e11cu: goto label_11e11c;
        case 0x11e12cu: goto label_11e12c;
        case 0x11e134u: goto label_11e134;
        case 0x11e13cu: goto label_11e13c;
        case 0x11e154u: goto label_11e154;
        default: break;
    }

    ctx->pc = 0x11df60u;

    // 0x11df60: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x11df60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x11df64: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11df64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11df68: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x11df68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11df6c: 0x3c120021  lui         $s2, 0x21
    ctx->pc = 0x11df6cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
    // 0x11df70: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11df70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11df74: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x11df74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x11df78: 0x2651b3e8  addiu       $s1, $s2, -0x4C18
    ctx->pc = 0x11df78u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 4294947816));
    // 0x11df7c: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11df7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11df80: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11df80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11df84: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x11df84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x11df88: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11DF88u;
    {
        const bool branch_taken_0x11df88 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x11DF8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DF88u;
            // 0x11df8c: 0x80a02d  daddu       $s4, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11df88) {
            ctx->pc = 0x11DF9Cu;
            goto label_11df9c;
        }
    }
    ctx->pc = 0x11DF90u;
    // 0x11df90: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11df90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11df94: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x11DF94u;
    {
        const bool branch_taken_0x11df94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11DF98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DF94u;
            // 0x11df98: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11df94) {
            ctx->pc = 0x11E094u;
            goto label_11e094;
        }
    }
    ctx->pc = 0x11DF9Cu;
label_11df9c:
    // 0x11df9c: 0x3c130026  lui         $s3, 0x26
    ctx->pc = 0x11df9cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)38 << 16));
    // 0x11dfa0: 0xfe40b3e8  sd          $zero, -0x4C18($s2)
    ctx->pc = 0x11dfa0u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 4294947816), GPR_U64(ctx, 0));
    // 0x11dfa4: 0x2670f900  addiu       $s0, $s3, -0x700
    ctx->pc = 0x11dfa4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 4294965504));
    // 0x11dfa8: 0xae200010  sw          $zero, 0x10($s1)
    ctx->pc = 0x11dfa8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x11dfac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11dfacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dfb0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11dfb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dfb4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x11DFB4u;
    SET_GPR_U32(ctx, 31, 0x11DFBCu);
    ctx->pc = 0x11DFB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DFB4u;
            // 0x11dfb8: 0x24062000  addiu       $a2, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DFBCu; }
        if (ctx->pc != 0x11DFBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DFBCu; }
        if (ctx->pc != 0x11DFBCu) { return; }
    }
    ctx->pc = 0x11DFBCu;
label_11dfbc:
    // 0x11dfbc: 0xae300014  sw          $s0, 0x14($s1)
    ctx->pc = 0x11dfbcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 16));
    // 0x11dfc0: 0x26032000  addiu       $v1, $s0, 0x2000
    ctx->pc = 0x11dfc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 8192));
    // 0x11dfc4: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x11dfc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x11dfc8: 0x26101fc0  addiu       $s0, $s0, 0x1FC0
    ctx->pc = 0x11dfc8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8128));
    // 0x11dfcc: 0x0  nop
    ctx->pc = 0x11dfccu;
    // NOP
label_11dfd0:
    // 0x11dfd0: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x11dfd0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x11dfd4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x11dfd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x11dfd8: 0x2610ffc0  addiu       $s0, $s0, -0x40
    ctx->pc = 0x11dfd8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967232));
    // 0x11dfdc: 0x2463ffc0  addiu       $v1, $v1, -0x40
    ctx->pc = 0x11dfdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967232));
    // 0x11dfe0: 0x0  nop
    ctx->pc = 0x11dfe0u;
    // NOP
    // 0x11dfe4: 0x441fffa  bgez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11DFE4u;
    {
        const bool branch_taken_0x11dfe4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11dfe4) {
            ctx->pc = 0x11DFD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11dfd0;
        }
    }
    ctx->pc = 0x11DFECu;
    // 0x11dfec: 0x2662f900  addiu       $v0, $s3, -0x700
    ctx->pc = 0x11dfecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294965504));
    // 0x11dff0: 0xc047c8a  jal         func_11F228
    ctx->pc = 0x11DFF0u;
    SET_GPR_U32(ctx, 31, 0x11DFF8u);
    ctx->pc = 0x11DFF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DFF0u;
            // 0x11dff4: 0xac401fc0  sw          $zero, 0x1FC0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 8128), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F228u;
    if (runtime->hasFunction(0x11F228u)) {
        auto targetFn = runtime->lookupFunction(0x11F228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DFF8u; }
        if (ctx->pc != 0x11DFF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011F228_0x11f228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DFF8u; }
        if (ctx->pc != 0x11DFF8u) { return; }
    }
    ctx->pc = 0x11DFF8u;
label_11dff8:
    // 0x11dff8: 0x3c050012  lui         $a1, 0x12
    ctx->pc = 0x11dff8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)18 << 16));
    // 0x11dffc: 0x2404000b  addiu       $a0, $zero, 0xB
    ctx->pc = 0x11dffcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x11e000: 0x24a5e500  addiu       $a1, $a1, -0x1B00
    ctx->pc = 0x11e000u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294960384));
    // 0x11e004: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11e004u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e008: 0xc0450c4  jal         func_114310
    ctx->pc = 0x11E008u;
    SET_GPR_U32(ctx, 31, 0x11E010u);
    ctx->pc = 0x11E00Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E008u;
            // 0x11e00c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114310u;
    if (runtime->hasFunction(0x114310u)) {
        auto targetFn = runtime->lookupFunction(0x114310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E010u; }
        if (ctx->pc != 0x11E010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114310_0x114310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E010u; }
        if (ctx->pc != 0x11E010u) { return; }
    }
    ctx->pc = 0x11E010u;
label_11e010:
    // 0x11e010: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x11e010u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e014: 0x4630004  bgezl       $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E014u;
    {
        const bool branch_taken_0x11e014 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x11e014) {
            ctx->pc = 0x11E018u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11E014u;
            // 0x11e018: 0x2642b3e8  addiu       $v0, $s2, -0x4C18 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294947816));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11E028u;
            goto label_11e028;
        }
    }
    ctx->pc = 0x11E01Cu;
    // 0x11e01c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e01cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e020: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x11E020u;
    {
        const bool branch_taken_0x11e020 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E020u;
            // 0x11e024: 0x34429021  ori         $v0, $v0, 0x9021 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36897);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e020) {
            ctx->pc = 0x11E094u;
            goto label_11e094;
        }
    }
    ctx->pc = 0x11E028u;
label_11e028:
    // 0x11e028: 0xc047598  jal         func_11D660
    ctx->pc = 0x11E028u;
    SET_GPR_U32(ctx, 31, 0x11E030u);
    ctx->pc = 0x11E02Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E028u;
            // 0x11e02c: 0xac430008  sw          $v1, 0x8($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E030u; }
        if (ctx->pc != 0x11E030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E030u; }
        if (ctx->pc != 0x11E030u) { return; }
    }
    ctx->pc = 0x11E030u;
label_11e030:
    // 0x11e030: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x11e030u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x11e034: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11e034u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e038: 0x34631010  ori         $v1, $v1, 0x1010
    ctx->pc = 0x11e038u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4112);
    // 0x11e03c: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11e03cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11e040: 0x8c700000  lw          $s0, 0x0($v1)
    ctx->pc = 0x11e040u;
    SET_GPR_S32(ctx, 16, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x11e044: 0x3442fffc  ori         $v0, $v0, 0xFFFC
    ctx->pc = 0x11e044u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65532);
    // 0x11e048: 0x2021024  and         $v0, $s0, $v0
    ctx->pc = 0x11e048u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x11e04c: 0x548025  or          $s0, $v0, $s4
    ctx->pc = 0x11e04cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) | GPR_U64(ctx, 20));
    // 0x11e050: 0x36100300  ori         $s0, $s0, 0x300
    ctx->pc = 0x11e050u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)768);
    // 0x11e054: 0x32020080  andi        $v0, $s0, 0x80
    ctx->pc = 0x11e054u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)128);
    // 0x11e058: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11E058u;
    {
        const bool branch_taken_0x11e058 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11E05Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E058u;
            // 0x11e05c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e058) {
            ctx->pc = 0x11E070u;
            goto label_11e070;
        }
    }
    ctx->pc = 0x11E060u;
    // 0x11e060: 0xc0477cc  jal         func_11DF30
    ctx->pc = 0x11E060u;
    SET_GPR_U32(ctx, 31, 0x11E068u);
    ctx->pc = 0x11E064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E060u;
            // 0x11e064: 0x36100c80  ori         $s0, $s0, 0xC80 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)3200);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF30u;
    if (runtime->hasFunction(0x11DF30u)) {
        auto targetFn = runtime->lookupFunction(0x11DF30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E068u; }
        if (ctx->pc != 0x11E068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF30_0x11df30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E068u; }
        if (ctx->pc != 0x11E068u) { return; }
    }
    ctx->pc = 0x11E068u;
label_11e068:
    // 0x11e068: 0xc0477d4  jal         func_11DF50
    ctx->pc = 0x11E068u;
    SET_GPR_U32(ctx, 31, 0x11E070u);
    ctx->pc = 0x11E06Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E068u;
            // 0x11e06c: 0x3404ffff  ori         $a0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF50u;
    if (runtime->hasFunction(0x11DF50u)) {
        auto targetFn = runtime->lookupFunction(0x11DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E070u; }
        if (ctx->pc != 0x11E070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF50_0x11df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E070u; }
        if (ctx->pc != 0x11E070u) { return; }
    }
    ctx->pc = 0x11E070u;
label_11e070:
    // 0x11e070: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E070u;
    SET_GPR_U32(ctx, 31, 0x11E078u);
    ctx->pc = 0x11E074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E070u;
            // 0x11e074: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E078u; }
        if (ctx->pc != 0x11E078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E078u; }
        if (ctx->pc != 0x11E078u) { return; }
    }
    ctx->pc = 0x11E078u;
label_11e078:
    // 0x11e078: 0xc04545a  jal         func_115168
    ctx->pc = 0x11E078u;
    SET_GPR_U32(ctx, 31, 0x11E080u);
    ctx->pc = 0x11E07Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E078u;
            // 0x11e07c: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115168u;
    if (runtime->hasFunction(0x115168u)) {
        auto targetFn = runtime->lookupFunction(0x115168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E080u; }
        if (ctx->pc != 0x11E080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115168_0x115168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E080u; }
        if (ctx->pc != 0x11E080u) { return; }
    }
    ctx->pc = 0x11E080u;
label_11e080:
    // 0x11e080: 0x12200004  beqz        $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E080u;
    {
        const bool branch_taken_0x11e080 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E080u;
            // 0x11e084: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e080) {
            ctx->pc = 0x11E094u;
            goto label_11e094;
        }
    }
    ctx->pc = 0x11E088u;
    // 0x11e088: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11E088u;
    SET_GPR_U32(ctx, 31, 0x11E090u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E090u; }
        if (ctx->pc != 0x11E090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E090u; }
        if (ctx->pc != 0x11E090u) { return; }
    }
    ctx->pc = 0x11E090u;
label_11e090:
    // 0x11e090: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11e090u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11e094:
    // 0x11e094: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x11e094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11e098: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x11e098u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11e09c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11e09cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e0a0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11e0a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e0a4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e0a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e0a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e0a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e0ac: 0x3e00008  jr          $ra
    ctx->pc = 0x11E0ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E0B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E0ACu;
            // 0x11e0b0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DF9Cu: goto label_11df9c;
            case 0x11DFBCu: goto label_11dfbc;
            case 0x11DFD0u: goto label_11dfd0;
            case 0x11DFF8u: goto label_11dff8;
            case 0x11E010u: goto label_11e010;
            case 0x11E028u: goto label_11e028;
            case 0x11E030u: goto label_11e030;
            case 0x11E068u: goto label_11e068;
            case 0x11E070u: goto label_11e070;
            case 0x11E078u: goto label_11e078;
            case 0x11E080u: goto label_11e080;
            case 0x11E090u: goto label_11e090;
            case 0x11E094u: goto label_11e094;
            case 0x11E0ECu: goto label_11e0ec;
            case 0x11E104u: goto label_11e104;
            case 0x11E10Cu: goto label_11e10c;
            case 0x11E11Cu: goto label_11e11c;
            case 0x11E12Cu: goto label_11e12c;
            case 0x11E134u: goto label_11e134;
            case 0x11E13Cu: goto label_11e13c;
            case 0x11E140u: goto label_11e140;
            case 0x11E154u: goto label_11e154;
            case 0x11E158u: goto label_11e158;
            case 0x11E18Cu: goto label_11e18c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E0B4u;
    // 0x11e0b4: 0x0  nop
    ctx->pc = 0x11e0b4u;
    // NOP
    // 0x11e0b8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11e0b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11e0bc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11e0bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11e0c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11e0c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11e0c4: 0x3c120021  lui         $s2, 0x21
    ctx->pc = 0x11e0c4u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
    // 0x11e0c8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11e0c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11e0cc: 0x2650b3e8  addiu       $s0, $s2, -0x4C18
    ctx->pc = 0x11e0ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294947816));
    // 0x11e0d0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11e0d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11e0d4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x11e0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11e0d8: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E0D8u;
    {
        const bool branch_taken_0x11e0d8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11e0d8) {
            ctx->pc = 0x11E0ECu;
            goto label_11e0ec;
        }
    }
    ctx->pc = 0x11E0E0u;
    // 0x11e0e0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e0e4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x11E0E4u;
    {
        const bool branch_taken_0x11e0e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E0E4u;
            // 0x11e0e8: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e0e4) {
            ctx->pc = 0x11E158u;
            goto label_11e158;
        }
    }
    ctx->pc = 0x11E0ECu;
label_11e0ec:
    // 0x11e0ec: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x11e0ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11e0f0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E0F0u;
    {
        const bool branch_taken_0x11e0f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11e0f0) {
            ctx->pc = 0x11E104u;
            goto label_11e104;
        }
    }
    ctx->pc = 0x11E0F8u;
    // 0x11e0f8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e0fc: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x11E0FCu;
    {
        const bool branch_taken_0x11e0fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E0FCu;
            // 0x11e100: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e0fc) {
            ctx->pc = 0x11E158u;
            goto label_11e158;
        }
    }
    ctx->pc = 0x11E104u;
label_11e104:
    // 0x11e104: 0xc047598  jal         func_11D660
    ctx->pc = 0x11E104u;
    SET_GPR_U32(ctx, 31, 0x11E10Cu);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E10Cu; }
        if (ctx->pc != 0x11E10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E10Cu; }
        if (ctx->pc != 0x11E10Cu) { return; }
    }
    ctx->pc = 0x11E10Cu;
label_11e10c:
    // 0x11e10c: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x11e10cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11e110: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11e110u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11e114: 0xc0450c8  jal         func_114320
    ctx->pc = 0x11E114u;
    SET_GPR_U32(ctx, 31, 0x11E11Cu);
    ctx->pc = 0x11E118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E114u;
            // 0x11e118: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114320u;
    if (runtime->hasFunction(0x114320u)) {
        auto targetFn = runtime->lookupFunction(0x114320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E11Cu; }
        if (ctx->pc != 0x11E11Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E11Cu; }
        if (ctx->pc != 0x11E11Cu) { return; }
    }
    ctx->pc = 0x11E11Cu;
label_11e11c:
    // 0x11e11c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11E11Cu;
    {
        const bool branch_taken_0x11e11c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11E120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E11Cu;
            // 0x11e120: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e11c) {
            ctx->pc = 0x11E140u;
            goto label_11e140;
        }
    }
    ctx->pc = 0x11E124u;
    // 0x11e124: 0xc045440  jal         func_115100
    ctx->pc = 0x11E124u;
    SET_GPR_U32(ctx, 31, 0x11E12Cu);
    ctx->pc = 0x11E128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E124u;
            // 0x11e128: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115100u;
    if (runtime->hasFunction(0x115100u)) {
        auto targetFn = runtime->lookupFunction(0x115100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E12Cu; }
        if (ctx->pc != 0x11E12Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E12Cu; }
        if (ctx->pc != 0x11E12Cu) { return; }
    }
    ctx->pc = 0x11E12Cu;
label_11e12c:
    // 0x11e12c: 0xc0477d0  jal         func_11DF40
    ctx->pc = 0x11E12Cu;
    SET_GPR_U32(ctx, 31, 0x11E134u);
    ctx->pc = 0x11E130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E12Cu;
            // 0x11e130: 0x24040c00  addiu       $a0, $zero, 0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF40u;
    if (runtime->hasFunction(0x11DF40u)) {
        auto targetFn = runtime->lookupFunction(0x11DF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E134u; }
        if (ctx->pc != 0x11E134u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF40_0x11df40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E134u; }
        if (ctx->pc != 0x11E134u) { return; }
    }
    ctx->pc = 0x11E134u;
label_11e134:
    // 0x11e134: 0xc0477cc  jal         func_11DF30
    ctx->pc = 0x11E134u;
    SET_GPR_U32(ctx, 31, 0x11E13Cu);
    ctx->pc = 0x11E138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11E134u;
            // 0x11e138: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DF30u;
    if (runtime->hasFunction(0x11DF30u)) {
        auto targetFn = runtime->lookupFunction(0x11DF30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E13Cu; }
        if (ctx->pc != 0x11E13Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DF30_0x11df30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E13Cu; }
        if (ctx->pc != 0x11E13Cu) { return; }
    }
    ctx->pc = 0x11E13Cu;
label_11e13c:
    // 0x11e13c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x11e13cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_11e140:
    // 0x11e140: 0xfe40b3e8  sd          $zero, -0x4C18($s2)
    ctx->pc = 0x11e140u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 4294947816), GPR_U64(ctx, 0));
    // 0x11e144: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11E144u;
    {
        const bool branch_taken_0x11e144 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11E148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E144u;
            // 0x11e148: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e144) {
            ctx->pc = 0x11E154u;
            goto label_11e154;
        }
    }
    ctx->pc = 0x11E14Cu;
    // 0x11e14c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11E14Cu;
    SET_GPR_U32(ctx, 31, 0x11E154u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E154u; }
        if (ctx->pc != 0x11E154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11E154u; }
        if (ctx->pc != 0x11E154u) { return; }
    }
    ctx->pc = 0x11E154u;
label_11e154:
    // 0x11e154: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11e154u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11e158:
    // 0x11e158: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11e158u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11e15c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11e15cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11e160: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11e160u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11e164: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11e164u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11e168: 0x3e00008  jr          $ra
    ctx->pc = 0x11E168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E16Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E168u;
            // 0x11e16c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DF9Cu: goto label_11df9c;
            case 0x11DFBCu: goto label_11dfbc;
            case 0x11DFD0u: goto label_11dfd0;
            case 0x11DFF8u: goto label_11dff8;
            case 0x11E010u: goto label_11e010;
            case 0x11E028u: goto label_11e028;
            case 0x11E030u: goto label_11e030;
            case 0x11E068u: goto label_11e068;
            case 0x11E070u: goto label_11e070;
            case 0x11E078u: goto label_11e078;
            case 0x11E080u: goto label_11e080;
            case 0x11E090u: goto label_11e090;
            case 0x11E094u: goto label_11e094;
            case 0x11E0ECu: goto label_11e0ec;
            case 0x11E104u: goto label_11e104;
            case 0x11E10Cu: goto label_11e10c;
            case 0x11E11Cu: goto label_11e11c;
            case 0x11E12Cu: goto label_11e12c;
            case 0x11E134u: goto label_11e134;
            case 0x11E13Cu: goto label_11e13c;
            case 0x11E140u: goto label_11e140;
            case 0x11E154u: goto label_11e154;
            case 0x11E158u: goto label_11e158;
            case 0x11E18Cu: goto label_11e18c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E170u;
    // 0x11e170: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11e170u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11e174: 0x8c43b3f0  lw          $v1, -0x4C10($v0)
    ctx->pc = 0x11e174u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294947824)));
    // 0x11e178: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x11E178u;
    {
        const bool branch_taken_0x11e178 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11E17Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E178u;
            // 0x11e17c: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11e178) {
            ctx->pc = 0x11E18Cu;
            goto label_11e18c;
        }
    }
    ctx->pc = 0x11E180u;
    // 0x11e180: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11e180u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11e184: 0x3e00008  jr          $ra
    ctx->pc = 0x11E184u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E184u;
            // 0x11e188: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DF9Cu: goto label_11df9c;
            case 0x11DFBCu: goto label_11dfbc;
            case 0x11DFD0u: goto label_11dfd0;
            case 0x11DFF8u: goto label_11dff8;
            case 0x11E010u: goto label_11e010;
            case 0x11E028u: goto label_11e028;
            case 0x11E030u: goto label_11e030;
            case 0x11E068u: goto label_11e068;
            case 0x11E070u: goto label_11e070;
            case 0x11E078u: goto label_11e078;
            case 0x11E080u: goto label_11e080;
            case 0x11E090u: goto label_11e090;
            case 0x11E094u: goto label_11e094;
            case 0x11E0ECu: goto label_11e0ec;
            case 0x11E104u: goto label_11e104;
            case 0x11E10Cu: goto label_11e10c;
            case 0x11E11Cu: goto label_11e11c;
            case 0x11E12Cu: goto label_11e12c;
            case 0x11E134u: goto label_11e134;
            case 0x11E13Cu: goto label_11e13c;
            case 0x11E140u: goto label_11e140;
            case 0x11E154u: goto label_11e154;
            case 0x11E158u: goto label_11e158;
            case 0x11E18Cu: goto label_11e18c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E18Cu;
label_11e18c:
    // 0x11e18c: 0x34631010  ori         $v1, $v1, 0x1010
    ctx->pc = 0x11e18cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4112);
    // 0x11e190: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x11e190u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x11e194: 0x3e00008  jr          $ra
    ctx->pc = 0x11E194u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11E198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11E194u;
            // 0x11e198: 0x30420003  andi        $v0, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DF9Cu: goto label_11df9c;
            case 0x11DFBCu: goto label_11dfbc;
            case 0x11DFD0u: goto label_11dfd0;
            case 0x11DFF8u: goto label_11dff8;
            case 0x11E010u: goto label_11e010;
            case 0x11E028u: goto label_11e028;
            case 0x11E030u: goto label_11e030;
            case 0x11E068u: goto label_11e068;
            case 0x11E070u: goto label_11e070;
            case 0x11E078u: goto label_11e078;
            case 0x11E080u: goto label_11e080;
            case 0x11E090u: goto label_11e090;
            case 0x11E094u: goto label_11e094;
            case 0x11E0ECu: goto label_11e0ec;
            case 0x11E104u: goto label_11e104;
            case 0x11E10Cu: goto label_11e10c;
            case 0x11E11Cu: goto label_11e11c;
            case 0x11E12Cu: goto label_11e12c;
            case 0x11E134u: goto label_11e134;
            case 0x11E13Cu: goto label_11e13c;
            case 0x11E140u: goto label_11e140;
            case 0x11E154u: goto label_11e154;
            case 0x11E158u: goto label_11e158;
            case 0x11E18Cu: goto label_11e18c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11E19Cu;
    // 0x11e19c: 0x0  nop
    ctx->pc = 0x11e19cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
