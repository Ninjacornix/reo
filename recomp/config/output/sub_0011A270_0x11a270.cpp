#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011A270
// Address: 0x11a270 - 0x11a338
void sub_0011A270_0x11a270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011A270_0x11a270");
#endif

    switch (ctx->pc) {
        case 0x11a290u: goto label_11a290;
        case 0x11a2a8u: goto label_11a2a8;
        case 0x11a2b0u: goto label_11a2b0;
        case 0x11a2b8u: goto label_11a2b8;
        case 0x11a2d4u: goto label_11a2d4;
        case 0x11a2e8u: goto label_11a2e8;
        case 0x11a2fcu: goto label_11a2fc;
        case 0x11a31cu: goto label_11a31c;
        default: break;
    }

    ctx->pc = 0x11a270u;

    // 0x11a270: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11a270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11a274: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11a274u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11a278: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11a278u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a27c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11a27cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11a280: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11a280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11a284: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x11a284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x11a288: 0xc04619c  jal         func_118670
    ctx->pc = 0x11A288u;
    SET_GPR_U32(ctx, 31, 0x11A290u);
    ctx->pc = 0x11A28Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A288u;
            // 0x11a28c: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A290u; }
        if (ctx->pc != 0x11A290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A290u; }
        if (ctx->pc != 0x11A290u) { return; }
    }
    ctx->pc = 0x11A290u;
label_11a290:
    // 0x11a290: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11a290u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11a294: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x11a294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x11a298: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11A298u;
    {
        const bool branch_taken_0x11a298 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a298) {
            ctx->pc = 0x11A2A8u;
            goto label_11a2a8;
        }
    }
    ctx->pc = 0x11A2A0u;
    // 0x11a2a0: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11A2A0u;
    SET_GPR_U32(ctx, 31, 0x11A2A8u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2A8u; }
        if (ctx->pc != 0x11A2A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2A8u; }
        if (ctx->pc != 0x11A2A8u) { return; }
    }
    ctx->pc = 0x11A2A8u;
label_11a2a8:
    // 0x11a2a8: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A2A8u;
    SET_GPR_U32(ctx, 31, 0x11A2B0u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2B0u; }
        if (ctx->pc != 0x11A2B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2B0u; }
        if (ctx->pc != 0x11A2B0u) { return; }
    }
    ctx->pc = 0x11A2B0u;
label_11a2b0:
    // 0x11a2b0: 0xc04605c  jal         func_118170
    ctx->pc = 0x11A2B0u;
    SET_GPR_U32(ctx, 31, 0x11A2B8u);
    ctx->pc = 0x118170u;
    if (runtime->hasFunction(0x118170u)) {
        auto targetFn = runtime->lookupFunction(0x118170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2B8u; }
        if (ctx->pc != 0x11A2B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118170_0x118170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2B8u; }
        if (ctx->pc != 0x11A2B8u) { return; }
    }
    ctx->pc = 0x11A2B8u;
label_11a2b8:
    // 0x11a2b8: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11a2b8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a2bc: 0x16400003  bnez        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x11A2BCu;
    {
        const bool branch_taken_0x11a2bc = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x11A2C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A2BCu;
            // 0x11a2c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a2bc) {
            ctx->pc = 0x11A2CCu;
            goto label_11a2cc;
        }
    }
    ctx->pc = 0x11A2C4u;
    // 0x11a2c4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x11A2C4u;
    {
        const bool branch_taken_0x11a2c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A2C4u;
            // 0x11a2c8: 0x2402ffed  addiu       $v0, $zero, -0x13 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967277));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a2c4) {
            ctx->pc = 0x11A320u;
            goto label_11a320;
        }
    }
    ctx->pc = 0x11A2CCu;
label_11a2cc:
    // 0x11a2cc: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x11A2CCu;
    SET_GPR_U32(ctx, 31, 0x11A2D4u);
    ctx->pc = 0x11A2D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A2CCu;
            // 0x11a2d0: 0x24050009  addiu       $a1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2D4u; }
        if (ctx->pc != 0x11A2D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2D4u; }
        if (ctx->pc != 0x11A2D4u) { return; }
    }
    ctx->pc = 0x11A2D4u;
label_11a2d4:
    // 0x11a2d4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11a2d4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a2d8: 0x6210006  bgez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x11A2D8u;
    {
        const bool branch_taken_0x11a2d8 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x11A2DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A2D8u;
            // 0x11a2dc: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a2d8) {
            ctx->pc = 0x11A2F4u;
            goto label_11a2f4;
        }
    }
    ctx->pc = 0x11A2E0u;
    // 0x11a2e0: 0xc045198  jal         func_114660
    ctx->pc = 0x11A2E0u;
    SET_GPR_U32(ctx, 31, 0x11A2E8u);
    ctx->pc = 0x11A2E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A2E0u;
            // 0x11a2e4: 0x8e049de8  lw          $a0, -0x6218($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2E8u; }
        if (ctx->pc != 0x11A2E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2E8u; }
        if (ctx->pc != 0x11A2E8u) { return; }
    }
    ctx->pc = 0x11A2E8u;
label_11a2e8:
    // 0x11a2e8: 0xae400004  sw          $zero, 0x4($s2)
    ctx->pc = 0x11a2e8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 0));
    // 0x11a2ec: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x11A2ECu;
    {
        const bool branch_taken_0x11a2ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A2F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A2ECu;
            // 0x11a2f0: 0x8e049de8  lw          $a0, -0x6218($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a2ec) {
            ctx->pc = 0x11A314u;
            goto label_11a314;
        }
    }
    ctx->pc = 0x11A2F4u;
label_11a2f4:
    // 0x11a2f4: 0xc045198  jal         func_114660
    ctx->pc = 0x11A2F4u;
    SET_GPR_U32(ctx, 31, 0x11A2FCu);
    ctx->pc = 0x11A2F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A2F4u;
            // 0x11a2f8: 0x8e049de8  lw          $a0, -0x6218($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2FCu; }
        if (ctx->pc != 0x11A2FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A2FCu; }
        if (ctx->pc != 0x11A2FCu) { return; }
    }
    ctx->pc = 0x11A2FCu;
label_11a2fc:
    // 0x11a2fc: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11a2fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11a300: 0xae510000  sw          $s1, 0x0($s2)
    ctx->pc = 0x11a300u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    // 0x11a304: 0x2463df40  addiu       $v1, $v1, -0x20C0
    ctx->pc = 0x11a304u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958912));
    // 0x11a308: 0x8e049de8  lw          $a0, -0x6218($s0)
    ctx->pc = 0x11a308u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
    // 0x11a30c: 0x2431823  subu        $v1, $s2, $v1
    ctx->pc = 0x11a30cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x11a310: 0x38903  sra         $s1, $v1, 4
    ctx->pc = 0x11a310u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 3), 4));
label_11a314:
    // 0x11a314: 0xc045190  jal         func_114640
    ctx->pc = 0x11A314u;
    SET_GPR_U32(ctx, 31, 0x11A31Cu);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A31Cu; }
        if (ctx->pc != 0x11A31Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A31Cu; }
        if (ctx->pc != 0x11A31Cu) { return; }
    }
    ctx->pc = 0x11A31Cu;
label_11a31c:
    // 0x11a31c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x11a31cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_11a320:
    // 0x11a320: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11a320u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11a324: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11a324u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11a328: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11a328u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11a32c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11a32cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11a330: 0x3e00008  jr          $ra
    ctx->pc = 0x11A330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11A334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A330u;
            // 0x11a334: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11A290u: goto label_11a290;
            case 0x11A2A8u: goto label_11a2a8;
            case 0x11A2B0u: goto label_11a2b0;
            case 0x11A2B8u: goto label_11a2b8;
            case 0x11A2CCu: goto label_11a2cc;
            case 0x11A2D4u: goto label_11a2d4;
            case 0x11A2E8u: goto label_11a2e8;
            case 0x11A2F4u: goto label_11a2f4;
            case 0x11A2FCu: goto label_11a2fc;
            case 0x11A314u: goto label_11a314;
            case 0x11A31Cu: goto label_11a31c;
            case 0x11A320u: goto label_11a320;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11A338u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
