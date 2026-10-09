#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F640
// Address: 0x11f640 - 0x11f6bc
void sub_0011F640_0x11f640(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F640_0x11f640");
#endif

    switch (ctx->pc) {
        case 0x11f664u: goto label_11f664;
        case 0x11f68cu: goto label_11f68c;
        case 0x11f69cu: goto label_11f69c;
        default: break;
    }

    ctx->pc = 0x11f640u;

    // 0x11f640: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11f640u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11f644: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f648: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f64c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11f64cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f650: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f650u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f654: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f658: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11f658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11f65c: 0xc047598  jal         func_11D660
    ctx->pc = 0x11F65Cu;
    SET_GPR_U32(ctx, 31, 0x11F664u);
    ctx->pc = 0x11F660u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F65Cu;
            // 0x11f660: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F664u; }
        if (ctx->pc != 0x11F664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F664u; }
        if (ctx->pc != 0x11F664u) { return; }
    }
    ctx->pc = 0x11F664u;
label_11f664:
    // 0x11f664: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f664u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f668: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x11f668u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x11f66c: 0x8c73b408  lw          $s3, -0x4BF8($v1)
    ctx->pc = 0x11f66cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294947848)));
    // 0x11f670: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11f670u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f674: 0xacb1b40c  sw          $s1, -0x4BF4($a1)
    ctx->pc = 0x11f674u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294947852), GPR_U32(ctx, 17));
    // 0x11f678: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11f678u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f67c: 0xac70b408  sw          $s0, -0x4BF8($v1)
    ctx->pc = 0x11f67cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294947848), GPR_U32(ctx, 16));
    // 0x11f680: 0x113100  sll         $a2, $s1, 4
    ctx->pc = 0x11f680u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x11f684: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x11F684u;
    SET_GPR_U32(ctx, 31, 0x11F68Cu);
    ctx->pc = 0x11F688u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F684u;
            // 0x11f688: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F68Cu; }
        if (ctx->pc != 0x11F68Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F68Cu; }
        if (ctx->pc != 0x11F68Cu) { return; }
    }
    ctx->pc = 0x11F68Cu;
label_11f68c:
    // 0x11f68c: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F68Cu;
    {
        const bool branch_taken_0x11f68c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F68Cu;
            // 0x11f690: 0x260102d  daddu       $v0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f68c) {
            ctx->pc = 0x11F6A0u;
            goto label_11f6a0;
        }
    }
    ctx->pc = 0x11F694u;
    // 0x11f694: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F694u;
    SET_GPR_U32(ctx, 31, 0x11F69Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F69Cu; }
        if (ctx->pc != 0x11F69Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F69Cu; }
        if (ctx->pc != 0x11F69Cu) { return; }
    }
    ctx->pc = 0x11F69Cu;
label_11f69c:
    // 0x11f69c: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x11f69cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_11f6a0:
    // 0x11f6a0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11f6a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f6a4: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f6a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f6a8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f6a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f6ac: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f6acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f6b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f6b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f6b4: 0x3e00008  jr          $ra
    ctx->pc = 0x11F6B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F6B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F6B4u;
            // 0x11f6b8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F6BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
