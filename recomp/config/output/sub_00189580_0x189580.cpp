#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189580
// Address: 0x189580 - 0x1896e8
void sub_00189580_0x189580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189580_0x189580");
#endif

    switch (ctx->pc) {
        case 0x1895d0u: goto label_1895d0;
        case 0x1895e8u: goto label_1895e8;
        case 0x189618u: goto label_189618;
        case 0x189650u: goto label_189650;
        case 0x189668u: goto label_189668;
        case 0x189698u: goto label_189698;
        case 0x1896a8u: goto label_1896a8;
        case 0x1896b8u: goto label_1896b8;
        default: break;
    }

    ctx->pc = 0x189580u;

    // 0x189580: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x189580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x189584: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x189584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x189588: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x189588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x18958c: 0x100b02d  daddu       $s6, $t0, $zero
    ctx->pc = 0x18958cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189590: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x189590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x189594: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x189594u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189598: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x189598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x18959c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x18959cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1895a0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1895a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1895a4: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1895a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1895a8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1895a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1895ac: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x1895acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1895b0: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1895b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1895b4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1895b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1895b8: 0x28422081  slti        $v0, $v0, 0x2081
    ctx->pc = 0x1895b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8321) ? 1 : 0);
    // 0x1895bc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1895BCu;
    {
        const bool branch_taken_0x1895bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1895C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1895BCu;
            // 0x1895c0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1895bc) {
            ctx->pc = 0x1895D8u;
            goto label_1895d8;
        }
    }
    ctx->pc = 0x1895C4u;
    // 0x1895c4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1895c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1895c8: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x1895C8u;
    SET_GPR_U32(ctx, 31, 0x1895D0u);
    ctx->pc = 0x1895CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1895C8u;
            // 0x1895cc: 0x24841a98  addiu       $a0, $a0, 0x1A98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6808));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1895D0u; }
        if (ctx->pc != 0x1895D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1895D0u; }
        if (ctx->pc != 0x1895D0u) { return; }
    }
    ctx->pc = 0x1895D0u;
label_1895d0:
    // 0x1895d0: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1895D0u;
    {
        const bool branch_taken_0x1895d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1895D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1895D0u;
            // 0x1895d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1895d0) {
            ctx->pc = 0x1896BCu;
            goto label_1896bc;
        }
    }
    ctx->pc = 0x1895D8u;
label_1895d8:
    // 0x1895d8: 0x3c150029  lui         $s5, 0x29
    ctx->pc = 0x1895d8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)41 << 16));
    // 0x1895dc: 0x3c130029  lui         $s3, 0x29
    ctx->pc = 0x1895dcu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)41 << 16));
    // 0x1895e0: 0xc045198  jal         func_114660
    ctx->pc = 0x1895E0u;
    SET_GPR_U32(ctx, 31, 0x1895E8u);
    ctx->pc = 0x1895E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1895E0u;
            // 0x1895e4: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1895E8u; }
        if (ctx->pc != 0x1895E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1895E8u; }
        if (ctx->pc != 0x1895E8u) { return; }
    }
    ctx->pc = 0x1895E8u;
label_1895e8:
    // 0x1895e8: 0xae721f80  sw          $s2, 0x1F80($s3)
    ctx->pc = 0x1895e8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8064), GPR_U32(ctx, 18));
    // 0x1895ec: 0x26641f80  addiu       $a0, $s3, 0x1F80
    ctx->pc = 0x1895ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 8064));
    // 0x1895f0: 0xac910004  sw          $s1, 0x4($a0)
    ctx->pc = 0x1895f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 17));
    // 0x1895f4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1895f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1895f8: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x1895f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x1895fc: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1895fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x189600: 0x1860000f  blez        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x189600u;
    {
        const bool branch_taken_0x189600 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x189604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189600u;
            // 0x189604: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189600) {
            ctx->pc = 0x189640u;
            goto label_189640;
        }
    }
    ctx->pc = 0x189608u;
    // 0x189608: 0x2486000c  addiu       $a2, $a0, 0xC
    ctx->pc = 0x189608u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x18960c: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x18960cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x189610: 0x2851021  addu        $v0, $s4, $a1
    ctx->pc = 0x189610u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
    // 0x189614: 0x0  nop
    ctx->pc = 0x189614u;
    // NOP
label_189618:
    // 0x189618: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x189618u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x18961c: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x18961cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x189620: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x189620u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x189624: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x189624u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x189628: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x189628u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18962c: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x18962cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x189630: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x189630u;
    {
        const bool branch_taken_0x189630 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x189634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189630u;
            // 0x189634: 0x2851021  addu        $v0, $s4, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189630) {
            ctx->pc = 0x189618u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189618;
        }
    }
    ctx->pc = 0x189638u;
    // 0x189638: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x189638u;
    {
        const bool branch_taken_0x189638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18963Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189638u;
            // 0x18963c: 0x24f00bd8  addiu       $s0, $a3, 0xBD8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 3032));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189638) {
            ctx->pc = 0x189648u;
            goto label_189648;
        }
    }
    ctx->pc = 0x189640u;
label_189640:
    // 0x189640: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x189640u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x189644: 0x24f00bd8  addiu       $s0, $a3, 0xBD8
    ctx->pc = 0x189644u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 3032));
label_189648:
    // 0x189648: 0xc045ef8  jal         func_117BE0
    ctx->pc = 0x189648u;
    SET_GPR_U32(ctx, 31, 0x189650u);
    ctx->pc = 0x18964Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189648u;
            // 0x18964c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117BE0u;
    if (runtime->hasFunction(0x117BE0u)) {
        auto targetFn = runtime->lookupFunction(0x117BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189650u; }
        if (ctx->pc != 0x189650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117BE0_0x117be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189650u; }
        if (ctx->pc != 0x189650u) { return; }
    }
    ctx->pc = 0x189650u;
label_189650:
    // 0x189650: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x189650u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x189654: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x189654u;
    {
        const bool branch_taken_0x189654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x189658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189654u;
            // 0x189658: 0x26671f80  addiu       $a3, $s3, 0x1F80 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 8064));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189654) {
            ctx->pc = 0x189670u;
            goto label_189670;
        }
    }
    ctx->pc = 0x18965Cu;
    // 0x18965c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x18965cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189660: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189660u;
    SET_GPR_U32(ctx, 31, 0x189668u);
    ctx->pc = 0x189664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189660u;
            // 0x189664: 0x24841ac0  addiu       $a0, $a0, 0x1AC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6848));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189668u; }
        if (ctx->pc != 0x189668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189668u; }
        if (ctx->pc != 0x189668u) { return; }
    }
    ctx->pc = 0x189668u;
label_189668:
    // 0x189668: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x189668u;
    {
        const bool branch_taken_0x189668 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x189668) {
            ctx->pc = 0x1896A0u;
            goto label_1896a0;
        }
    }
    ctx->pc = 0x189670u;
label_189670:
    // 0x189670: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189670u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x189674: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x189674u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189678: 0x2c0582d  daddu       $t3, $s6, $zero
    ctx->pc = 0x189678u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18967c: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x18967cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x189680: 0x34a5131c  ori         $a1, $a1, 0x131C
    ctx->pc = 0x189680u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4892);
    // 0x189684: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x189684u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x189688: 0x24082090  addiu       $t0, $zero, 0x2090
    ctx->pc = 0x189688u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8336));
    // 0x18968c: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x18968cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189690: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189690u;
    SET_GPR_U32(ctx, 31, 0x189698u);
    ctx->pc = 0x189694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189690u;
            // 0x189694: 0x240a2090  addiu       $t2, $zero, 0x2090 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 8336));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189698u; }
        if (ctx->pc != 0x189698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189698u; }
        if (ctx->pc != 0x189698u) { return; }
    }
    ctx->pc = 0x189698u;
label_189698:
    // 0x189698: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x189698u;
    {
        const bool branch_taken_0x189698 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x189698) {
            ctx->pc = 0x1896B0u;
            goto label_1896b0;
        }
    }
    ctx->pc = 0x1896A0u;
label_1896a0:
    // 0x1896a0: 0xc045190  jal         func_114640
    ctx->pc = 0x1896A0u;
    SET_GPR_U32(ctx, 31, 0x1896A8u);
    ctx->pc = 0x1896A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1896A0u;
            // 0x1896a4: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1896A8u; }
        if (ctx->pc != 0x1896A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1896A8u; }
        if (ctx->pc != 0x1896A8u) { return; }
    }
    ctx->pc = 0x1896A8u;
label_1896a8:
    // 0x1896a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1896A8u;
    {
        const bool branch_taken_0x1896a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1896ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1896A8u;
            // 0x1896ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1896a8) {
            ctx->pc = 0x1896BCu;
            goto label_1896bc;
        }
    }
    ctx->pc = 0x1896B0u;
label_1896b0:
    // 0x1896b0: 0xc045190  jal         func_114640
    ctx->pc = 0x1896B0u;
    SET_GPR_U32(ctx, 31, 0x1896B8u);
    ctx->pc = 0x1896B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1896B0u;
            // 0x1896b4: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1896B8u; }
        if (ctx->pc != 0x1896B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1896B8u; }
        if (ctx->pc != 0x1896B8u) { return; }
    }
    ctx->pc = 0x1896B8u;
label_1896b8:
    // 0x1896b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1896b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1896bc:
    // 0x1896bc: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1896bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1896c0: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x1896c0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1896c4: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x1896c4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1896c8: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x1896c8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1896cc: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x1896ccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1896d0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1896d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1896d4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1896d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1896d8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1896d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1896dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1896DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1896E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1896DCu;
            // 0x1896e0: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1895D0u: goto label_1895d0;
            case 0x1895D8u: goto label_1895d8;
            case 0x1895E8u: goto label_1895e8;
            case 0x189618u: goto label_189618;
            case 0x189640u: goto label_189640;
            case 0x189648u: goto label_189648;
            case 0x189650u: goto label_189650;
            case 0x189668u: goto label_189668;
            case 0x189670u: goto label_189670;
            case 0x189698u: goto label_189698;
            case 0x1896A0u: goto label_1896a0;
            case 0x1896A8u: goto label_1896a8;
            case 0x1896B0u: goto label_1896b0;
            case 0x1896B8u: goto label_1896b8;
            case 0x1896BCu: goto label_1896bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1896E4u;
    // 0x1896e4: 0x0  nop
    ctx->pc = 0x1896e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
