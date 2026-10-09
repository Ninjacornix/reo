#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103390
// Address: 0x103390 - 0x1033f8
void sub_00103390_0x103390(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103390_0x103390");
#endif

    switch (ctx->pc) {
        case 0x1033acu: goto label_1033ac;
        case 0x1033b8u: goto label_1033b8;
        default: break;
    }

    ctx->pc = 0x103390u;

    // 0x103390: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x103390u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x103394: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x103394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x103398: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x103398u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10339c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x10339cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1033a0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1033a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1033a4: 0xc040c00  jal         func_103000
    ctx->pc = 0x1033A4u;
    SET_GPR_U32(ctx, 31, 0x1033ACu);
    ctx->pc = 0x1033A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1033A4u;
            // 0x1033a8: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103000u;
    if (runtime->hasFunction(0x103000u)) {
        auto targetFn = runtime->lookupFunction(0x103000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1033ACu; }
        if (ctx->pc != 0x1033ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103000_0x103000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1033ACu; }
        if (ctx->pc != 0x1033ACu) { return; }
    }
    ctx->pc = 0x1033ACu;
label_1033ac:
    // 0x1033ac: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1033acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1033b0: 0xc040bc2  jal         func_102F08
    ctx->pc = 0x1033B0u;
    SET_GPR_U32(ctx, 31, 0x1033B8u);
    ctx->pc = 0x1033B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1033B0u;
            // 0x1033b4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102F08u;
    if (runtime->hasFunction(0x102F08u)) {
        auto targetFn = runtime->lookupFunction(0x102F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1033B8u; }
        if (ctx->pc != 0x1033B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102F08_0x102f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1033B8u; }
        if (ctx->pc != 0x1033B8u) { return; }
    }
    ctx->pc = 0x1033B8u;
label_1033b8:
    // 0x1033b8: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x1033b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x1033bc: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x1033bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1033c0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1033c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1033c4: 0x54620001  bnel        $v1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x1033C4u;
    {
        const bool branch_taken_0x1033c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1033c4) {
            ctx->pc = 0x1033C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1033C4u;
            // 0x1033c8: 0xae110030  sw          $s1, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1033CCu;
            goto label_1033cc;
        }
    }
    ctx->pc = 0x1033CCu;
label_1033cc:
    // 0x1033cc: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1033ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1033d0: 0x2403fff3  addiu       $v1, $zero, -0xD
    ctx->pc = 0x1033d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967283));
    // 0x1033d4: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x1033d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x1033d8: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1033d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1033dc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1033dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1033e0: 0x34420105  ori         $v0, $v0, 0x105
    ctx->pc = 0x1033e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)261);
    // 0x1033e4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1033e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1033e8: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1033e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1033ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1033ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1033f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1033F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1033F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1033F0u;
            // 0x1033f4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1033ACu: goto label_1033ac;
            case 0x1033B8u: goto label_1033b8;
            case 0x1033CCu: goto label_1033cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1033F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
