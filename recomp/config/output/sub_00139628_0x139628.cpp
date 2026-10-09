#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139628
// Address: 0x139628 - 0x1396d0
void sub_00139628_0x139628(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139628_0x139628");
#endif

    switch (ctx->pc) {
        case 0x139648u: goto label_139648;
        case 0x13965cu: goto label_13965c;
        case 0x139668u: goto label_139668;
        case 0x139698u: goto label_139698;
        default: break;
    }

    ctx->pc = 0x139628u;

    // 0x139628: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x139628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13962c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13962cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x139630: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x139630u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139634: 0x34048000  ori         $a0, $zero, 0x8000
    ctx->pc = 0x139634u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x139638: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x139638u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13963c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13963cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x139640: 0xc04e082  jal         func_138208
    ctx->pc = 0x139640u;
    SET_GPR_U32(ctx, 31, 0x139648u);
    ctx->pc = 0x139644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139640u;
            // 0x139644: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139648u; }
        if (ctx->pc != 0x139648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139648u; }
        if (ctx->pc != 0x139648u) { return; }
    }
    ctx->pc = 0x139648u;
label_139648:
    // 0x139648: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x139648u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13964c: 0x8c46cbec  lw          $a2, -0x3414($v0)
    ctx->pc = 0x13964cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294953964)));
    // 0x139650: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x139650u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139654: 0xc04020e  jal         func_100838
    ctx->pc = 0x139654u;
    SET_GPR_U32(ctx, 31, 0x13965Cu);
    ctx->pc = 0x139658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139654u;
            // 0x139658: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100838u;
    if (runtime->hasFunction(0x100838u)) {
        auto targetFn = runtime->lookupFunction(0x100838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13965Cu; }
        if (ctx->pc != 0x13965Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100838_0x100838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13965Cu; }
        if (ctx->pc != 0x13965Cu) { return; }
    }
    ctx->pc = 0x13965Cu;
label_13965c:
    // 0x13965c: 0x34048001  ori         $a0, $zero, 0x8001
    ctx->pc = 0x13965cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x139660: 0xc04e082  jal         func_138208
    ctx->pc = 0x139660u;
    SET_GPR_U32(ctx, 31, 0x139668u);
    ctx->pc = 0x139664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139660u;
            // 0x139664: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139668u; }
        if (ctx->pc != 0x139668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139668u; }
        if (ctx->pc != 0x139668u) { return; }
    }
    ctx->pc = 0x139668u;
label_139668:
    // 0x139668: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x139668u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13966c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x13966cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139670: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x139670u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139674: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139674u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139678: 0x3e00008  jr          $ra
    ctx->pc = 0x139678u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13967Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139678u;
            // 0x13967c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139648u: goto label_139648;
            case 0x13965Cu: goto label_13965c;
            case 0x139668u: goto label_139668;
            case 0x139698u: goto label_139698;
            case 0x1396B4u: goto label_1396b4;
            case 0x1396C8u: goto label_1396c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139680u;
    // 0x139680: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x139680u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x139684: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x139684u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139688: 0x2444cc60  addiu       $a0, $v0, -0x33A0
    ctx->pc = 0x139688u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954080));
    // 0x13968c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x13968cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x139690: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x139690u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x139694: 0x0  nop
    ctx->pc = 0x139694u;
    // NOP
label_139698:
    // 0x139698: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x139698u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13969c: 0x54470005  bnel        $v0, $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x13969Cu;
    {
        const bool branch_taken_0x13969c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        if (branch_taken_0x13969c) {
            ctx->pc = 0x1396A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13969Cu;
            // 0x1396a0: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1396B4u;
            goto label_1396b4;
        }
    }
    ctx->pc = 0x1396A4u;
    // 0x1396a4: 0x80830002  lb          $v1, 0x2($a0)
    ctx->pc = 0x1396a4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1396a8: 0x10660007  beq         $v1, $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x1396A8u;
    {
        const bool branch_taken_0x1396a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        ctx->pc = 0x1396ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1396A8u;
            // 0x1396ac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1396a8) {
            ctx->pc = 0x1396C8u;
            goto label_1396c8;
        }
    }
    ctx->pc = 0x1396B0u;
    // 0x1396b0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1396b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1396b4:
    // 0x1396b4: 0x28a20028  slti        $v0, $a1, 0x28
    ctx->pc = 0x1396b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)40) ? 1 : 0);
    // 0x1396b8: 0x0  nop
    ctx->pc = 0x1396b8u;
    // NOP
    // 0x1396bc: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1396BCu;
    {
        const bool branch_taken_0x1396bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1396C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1396BCu;
            // 0x1396c0: 0x24840048  addiu       $a0, $a0, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 72));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1396bc) {
            ctx->pc = 0x139698u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_139698;
        }
    }
    ctx->pc = 0x1396C4u;
    // 0x1396c4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1396c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1396c8:
    // 0x1396c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1396C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139648u: goto label_139648;
            case 0x13965Cu: goto label_13965c;
            case 0x139668u: goto label_139668;
            case 0x139698u: goto label_139698;
            case 0x1396B4u: goto label_1396b4;
            case 0x1396C8u: goto label_1396c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1396D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
