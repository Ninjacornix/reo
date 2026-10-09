#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100408
// Address: 0x100408 - 0x1004d4
void sub_00100408_0x100408(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100408_0x100408");
#endif

    switch (ctx->pc) {
        case 0x100448u: goto label_100448;
        case 0x100460u: goto label_100460;
        case 0x10048cu: goto label_10048c;
        case 0x10049cu: goto label_10049c;
        case 0x1004b0u: goto label_1004b0;
        default: break;
    }

    ctx->pc = 0x100408u;

    // 0x100408: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x100408u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x10040c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x10040cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x100410: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100414: 0x3c140020  lui         $s4, 0x20
    ctx->pc = 0x100414u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
    // 0x100418: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x100418u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10041c: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x10041cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x100420: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x100420u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x100424: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x100424u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x100428: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x100428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10042c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x10042cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100430: 0x8e847914  lw          $a0, 0x7914($s4)
    ctx->pc = 0x100430u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30996)));
    // 0x100434: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x100434u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100438: 0x1480001a  bnez        $a0, . + 4 + (0x1A << 2)
    ctx->pc = 0x100438u;
    {
        const bool branch_taken_0x100438 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10043Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100438u;
            // 0x10043c: 0xffbf0050  sd          $ra, 0x50($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100438) {
            ctx->pc = 0x1004A4u;
            goto label_1004a4;
        }
    }
    ctx->pc = 0x100440u;
    // 0x100440: 0xc045144  jal         func_114510
    ctx->pc = 0x100440u;
    SET_GPR_U32(ctx, 31, 0x100448u);
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100448u; }
        if (ctx->pc != 0x100448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100448u; }
        if (ctx->pc != 0x100448u) { return; }
    }
    ctx->pc = 0x100448u;
label_100448:
    // 0x100448: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x100448u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x10044c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x10044cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x100450: 0xac629f98  sw          $v0, -0x6068($v1)
    ctx->pc = 0x100450u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942616), GPR_U32(ctx, 2));
    // 0x100454: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x100454u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100458: 0xc045148  jal         func_114520
    ctx->pc = 0x100458u;
    SET_GPR_U32(ctx, 31, 0x100460u);
    ctx->pc = 0x10045Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100458u;
            // 0x10045c: 0x24a59fa0  addiu       $a1, $a1, -0x6060 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100460u; }
        if (ctx->pc != 0x100460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100460u; }
        if (ctx->pc != 0x100460u) { return; }
    }
    ctx->pc = 0x100460u;
label_100460:
    // 0x100460: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x100460u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x100464: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x100464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x100468: 0x24639fd0  addiu       $v1, $v1, -0x6030
    ctx->pc = 0x100468u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294942672));
    // 0x10046c: 0x24420338  addiu       $v0, $v0, 0x338
    ctx->pc = 0x10046cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 824));
    // 0x100470: 0xac70000c  sw          $s0, 0xC($v1)
    ctx->pc = 0x100470u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 16));
    // 0x100474: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x100474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100478: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x100478u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x10047c: 0xac720008  sw          $s2, 0x8($v1)
    ctx->pc = 0x10047cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 18));
    // 0x100480: 0xac710014  sw          $s1, 0x14($v1)
    ctx->pc = 0x100480u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 17));
    // 0x100484: 0xc045108  jal         func_114420
    ctx->pc = 0x100484u;
    SET_GPR_U32(ctx, 31, 0x10048Cu);
    ctx->pc = 0x100488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100484u;
            // 0x100488: 0xac600010  sw          $zero, 0x10($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10048Cu; }
        if (ctx->pc != 0x10048Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10048Cu; }
        if (ctx->pc != 0x10048Cu) { return; }
    }
    ctx->pc = 0x10048Cu;
label_10048c:
    // 0x10048c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10048cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100490: 0xae827914  sw          $v0, 0x7914($s4)
    ctx->pc = 0x100490u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 30996), GPR_U32(ctx, 2));
    // 0x100494: 0xc045110  jal         func_114440
    ctx->pc = 0x100494u;
    SET_GPR_U32(ctx, 31, 0x10049Cu);
    ctx->pc = 0x100498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100494u;
            // 0x100498: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10049Cu; }
        if (ctx->pc != 0x10049Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10049Cu; }
        if (ctx->pc != 0x10049Cu) { return; }
    }
    ctx->pc = 0x10049Cu;
label_10049c:
    // 0x10049c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10049Cu;
    {
        const bool branch_taken_0x10049c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1004A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10049Cu;
            // 0x1004a0: 0x260102d  daddu       $v0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10049c) {
            ctx->pc = 0x1004B4u;
            goto label_1004b4;
        }
    }
    ctx->pc = 0x1004A4u;
label_1004a4:
    // 0x1004a4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1004a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1004a8: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x1004A8u;
    SET_GPR_U32(ctx, 31, 0x1004B0u);
    ctx->pc = 0x1004ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1004A8u;
            // 0x1004ac: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1004B0u; }
        if (ctx->pc != 0x1004B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1004B0u; }
        if (ctx->pc != 0x1004B0u) { return; }
    }
    ctx->pc = 0x1004B0u;
label_1004b0:
    // 0x1004b0: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x1004b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1004b4:
    // 0x1004b4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1004b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1004b8: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x1004b8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1004bc: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x1004bcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1004c0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1004c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1004c4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1004c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1004c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1004c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1004cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1004CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1004D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1004CCu;
            // 0x1004d0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100448u: goto label_100448;
            case 0x100460u: goto label_100460;
            case 0x10048Cu: goto label_10048c;
            case 0x10049Cu: goto label_10049c;
            case 0x1004A4u: goto label_1004a4;
            case 0x1004B0u: goto label_1004b0;
            case 0x1004B4u: goto label_1004b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1004D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
