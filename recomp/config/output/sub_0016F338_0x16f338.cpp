#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016F338
// Address: 0x16f338 - 0x16f438
void sub_0016F338_0x16f338(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016F338_0x16f338");
#endif

    switch (ctx->pc) {
        case 0x16f39cu: goto label_16f39c;
        case 0x16f3c0u: goto label_16f3c0;
        case 0x16f3e8u: goto label_16f3e8;
        default: break;
    }

    ctx->pc = 0x16f338u;

    // 0x16f338: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16f338u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16f33c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16f33cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16f340: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16f340u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f344: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16f344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16f348: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16f348u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f34c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16f34cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16f350: 0x26120cc0  addiu       $s2, $s0, 0xCC0
    ctx->pc = 0x16f350u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x16f354: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16f354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16f358: 0x26130d54  addiu       $s3, $s0, 0xD54
    ctx->pc = 0x16f358u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 3412));
    // 0x16f35c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16f35cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16f360: 0x8e630024  lw          $v1, 0x24($s3)
    ctx->pc = 0x16f360u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 36)));
    // 0x16f364: 0xae230010  sw          $v1, 0x10($s1)
    ctx->pc = 0x16f364u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
    // 0x16f368: 0x8e030dc4  lw          $v1, 0xDC4($s0)
    ctx->pc = 0x16f368u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3524)));
    // 0x16f36c: 0x8e620020  lw          $v0, 0x20($s3)
    ctx->pc = 0x16f36cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x16f370: 0x8e450120  lw          $a1, 0x120($s2)
    ctx->pc = 0x16f370u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 288)));
    // 0x16f374: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x16f374u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16f378: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x16f378u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16f37c: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x16f37cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x16f380: 0x8e630020  lw          $v1, 0x20($s3)
    ctx->pc = 0x16f380u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x16f384: 0xae230020  sw          $v1, 0x20($s1)
    ctx->pc = 0x16f384u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 3));
    // 0x16f388: 0x8e620020  lw          $v0, 0x20($s3)
    ctx->pc = 0x16f388u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x16f38c: 0x8e430120  lw          $v1, 0x120($s2)
    ctx->pc = 0x16f38cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 288)));
    // 0x16f390: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16f390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16f394: 0xc05c54c  jal         func_171530
    ctx->pc = 0x16F394u;
    SET_GPR_U32(ctx, 31, 0x16F39Cu);
    ctx->pc = 0x16F398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F394u;
            // 0x16f398: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171530u;
    if (runtime->hasFunction(0x171530u)) {
        auto targetFn = runtime->lookupFunction(0x171530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F39Cu; }
        if (ctx->pc != 0x16F39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171530_0x171530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F39Cu; }
        if (ctx->pc != 0x16F39Cu) { return; }
    }
    ctx->pc = 0x16F39Cu;
label_16f39c:
    // 0x16f39c: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x16F39Cu;
    {
        const bool branch_taken_0x16f39c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F3A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F39Cu;
            // 0x16f3a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f39c) {
            ctx->pc = 0x16F3FCu;
            goto label_16f3fc;
        }
    }
    ctx->pc = 0x16F3A4u;
    // 0x16f3a4: 0x8e22003c  lw          $v0, 0x3C($s1)
    ctx->pc = 0x16f3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x16f3a8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x16f3a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16f3ac: 0x3c100024  lui         $s0, 0x24
    ctx->pc = 0x16f3acu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)36 << 16));
    // 0x16f3b0: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x16f3b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x16f3b4: 0x8e100af0  lw          $s0, 0xAF0($s0)
    ctx->pc = 0x16f3b4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2800)));
    // 0x16f3b8: 0xc05c796  jal         func_171E58
    ctx->pc = 0x16F3B8u;
    SET_GPR_U32(ctx, 31, 0x16F3C0u);
    ctx->pc = 0x171E58u;
    if (runtime->hasFunction(0x171E58u)) {
        auto targetFn = runtime->lookupFunction(0x171E58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F3C0u; }
        if (ctx->pc != 0x16F3C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171E58_0x171e58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F3C0u; }
        if (ctx->pc != 0x16F3C0u) { return; }
    }
    ctx->pc = 0x16F3C0u;
label_16f3c0:
    // 0x16f3c0: 0x8e43011c  lw          $v1, 0x11C($s2)
    ctx->pc = 0x16f3c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 284)));
    // 0x16f3c4: 0x8e640024  lw          $a0, 0x24($s3)
    ctx->pc = 0x16f3c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 36)));
    // 0x16f3c8: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x16f3c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f3cc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x16f3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16f3d0: 0x22940  sll         $a1, $v0, 5
    ctx->pc = 0x16f3d0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x16f3d4: 0xa22823  subu        $a1, $a1, $v0
    ctx->pc = 0x16f3d4u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x16f3d8: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x16f3d8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x16f3dc: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x16f3dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x16f3e0: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x16F3E0u;
    SET_GPR_U32(ctx, 31, 0x16F3E8u);
    ctx->pc = 0x16F3E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F3E0u;
            // 0x16f3e4: 0x528c0  sll         $a1, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F3E8u; }
        if (ctx->pc != 0x16F3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F3E8u; }
        if (ctx->pc != 0x16F3E8u) { return; }
    }
    ctx->pc = 0x16F3E8u;
label_16f3e8:
    // 0x16f3e8: 0xae220020  sw          $v0, 0x20($s1)
    ctx->pc = 0x16f3e8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 2));
    // 0x16f3ec: 0x8e430120  lw          $v1, 0x120($s2)
    ctx->pc = 0x16f3ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 288)));
    // 0x16f3f0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16f3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16f3f4: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x16f3f4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x16f3f8: 0xae220024  sw          $v0, 0x24($s1)
    ctx->pc = 0x16f3f8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
label_16f3fc:
    // 0x16f3fc: 0x8e23000c  lw          $v1, 0xC($s1)
    ctx->pc = 0x16f3fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x16f400: 0x8e420240  lw          $v0, 0x240($s2)
    ctx->pc = 0x16f400u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 576)));
    // 0x16f404: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x16f404u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x16f408: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16F408u;
    {
        const bool branch_taken_0x16f408 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F40Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F408u;
            // 0x16f40c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f408) {
            ctx->pc = 0x16F41Cu;
            goto label_16f41c;
        }
    }
    ctx->pc = 0x16F410u;
    // 0x16f410: 0xae430240  sw          $v1, 0x240($s2)
    ctx->pc = 0x16f410u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 576), GPR_U32(ctx, 3));
    // 0x16f414: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x16f414u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x16f418: 0xae420244  sw          $v0, 0x244($s2)
    ctx->pc = 0x16f418u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 580), GPR_U32(ctx, 2));
label_16f41c:
    // 0x16f41c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16f41cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16f420: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16f420u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16f424: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16f424u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16f428: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16f428u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16f42c: 0x3e00008  jr          $ra
    ctx->pc = 0x16F42Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16F430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F42Cu;
            // 0x16f430: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F39Cu: goto label_16f39c;
            case 0x16F3C0u: goto label_16f3c0;
            case 0x16F3E8u: goto label_16f3e8;
            case 0x16F3FCu: goto label_16f3fc;
            case 0x16F41Cu: goto label_16f41c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16F434u;
    // 0x16f434: 0x0  nop
    ctx->pc = 0x16f434u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
