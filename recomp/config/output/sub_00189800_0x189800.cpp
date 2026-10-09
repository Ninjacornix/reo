#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189800
// Address: 0x189800 - 0x189880
void sub_00189800_0x189800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189800_0x189800");
#endif

    switch (ctx->pc) {
        case 0x18986cu: goto label_18986c;
        default: break;
    }

    ctx->pc = 0x189800u;

    // 0x189800: 0x2402c000  addiu       $v0, $zero, -0x4000
    ctx->pc = 0x189800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294950912));
    // 0x189804: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x189804u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x189808: 0x421024  and         $v0, $v0, $v0
    ctx->pc = 0x189808u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 2));
    // 0x18980c: 0x3c06ffff  lui         $a2, 0xFFFF
    ctx->pc = 0x18980cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)65535 << 16));
    // 0x189810: 0x34c63fff  ori         $a2, $a2, 0x3FFF
    ctx->pc = 0x189810u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)16383);
    // 0x189814: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x189814u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x189818: 0x34078000  ori         $a3, $zero, 0x8000
    ctx->pc = 0x189818u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x18981c: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x18981cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x189820: 0x3c03ff00  lui         $v1, 0xFF00
    ctx->pc = 0x189820u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65280 << 16));
    // 0x189824: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x189824u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x189828: 0x471025  or          $v0, $v0, $a3
    ctx->pc = 0x189828u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
    // 0x18982c: 0x3c060003  lui         $a2, 0x3
    ctx->pc = 0x18982cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)3 << 16));
    // 0x189830: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x189830u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x189834: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x189834u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189838: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x189838u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x18983c: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x18983cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x189840: 0x84438  dsll        $t0, $t0, 16
    ctx->pc = 0x189840u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << 16);
    // 0x189844: 0x350800ff  ori         $t0, $t0, 0xFF
    ctx->pc = 0x189844u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)255);
    // 0x189848: 0x84438  dsll        $t0, $t0, 16
    ctx->pc = 0x189848u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << 16);
    // 0x18984c: 0x3508ffff  ori         $t0, $t0, 0xFFFF
    ctx->pc = 0x18984cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)65535);
    // 0x189850: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x189850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x189854: 0x481024  and         $v0, $v0, $t0
    ctx->pc = 0x189854u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
    // 0x189858: 0x3c050100  lui         $a1, 0x100
    ctx->pc = 0x189858u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
    // 0x18985c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x18985cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189860: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x189860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x189864: 0xc0625ba  jal         func_1896E8
    ctx->pc = 0x189864u;
    SET_GPR_U32(ctx, 31, 0x18986Cu);
    ctx->pc = 0x189868u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189864u;
            // 0x189868: 0x452825  or          $a1, $v0, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1896E8u;
    if (runtime->hasFunction(0x1896E8u)) {
        auto targetFn = runtime->lookupFunction(0x1896E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18986Cu; }
        if (ctx->pc != 0x18986Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001896E8_0x1896e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18986Cu; }
        if (ctx->pc != 0x18986Cu) { return; }
    }
    ctx->pc = 0x18986Cu;
label_18986c:
    // 0x18986c: 0x4430001  bgezl       $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x18986Cu;
    {
        const bool branch_taken_0x18986c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x18986c) {
            ctx->pc = 0x189870u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18986Cu;
            // 0x189870: 0x8fa20000  lw          $v0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x189874u;
            goto label_189874;
        }
    }
    ctx->pc = 0x189874u;
label_189874:
    // 0x189874: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x189874u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189878: 0x3e00008  jr          $ra
    ctx->pc = 0x189878u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18987Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189878u;
            // 0x18987c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18986Cu: goto label_18986c;
            case 0x189874u: goto label_189874;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189880u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
