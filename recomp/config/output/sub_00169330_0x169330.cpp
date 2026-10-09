#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169330
// Address: 0x169330 - 0x169398
void sub_00169330_0x169330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169330_0x169330");
#endif

    switch (ctx->pc) {
        case 0x169350u: goto label_169350;
        case 0x169368u: goto label_169368;
        default: break;
    }

    ctx->pc = 0x169330u;

    // 0x169330: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x169330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x169334: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x169338: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x169338u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16933c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16933cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x169340: 0x26040094  addiu       $a0, $s0, 0x94
    ctx->pc = 0x169340u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 148));
    // 0x169344: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x169344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x169348: 0xc05e43c  jal         func_1790F0
    ctx->pc = 0x169348u;
    SET_GPR_U32(ctx, 31, 0x169350u);
    ctx->pc = 0x16934Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169348u;
            // 0x16934c: 0x8e050090  lw          $a1, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1790F0u;
    if (runtime->hasFunction(0x1790F0u)) {
        auto targetFn = runtime->lookupFunction(0x1790F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169350u; }
        if (ctx->pc != 0x169350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001790F0_0x1790f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169350u; }
        if (ctx->pc != 0x169350u) { return; }
    }
    ctx->pc = 0x169350u;
label_169350:
    // 0x169350: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x169350u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169354: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x169354u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169358: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x169358u;
    {
        const bool branch_taken_0x169358 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x16935Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169358u;
            // 0x16935c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169358) {
            ctx->pc = 0x169380u;
            goto label_169380;
        }
    }
    ctx->pc = 0x169360u;
    // 0x169360: 0xc05a4e6  jal         func_169398
    ctx->pc = 0x169360u;
    SET_GPR_U32(ctx, 31, 0x169368u);
    ctx->pc = 0x169398u;
    if (runtime->hasFunction(0x169398u)) {
        auto targetFn = runtime->lookupFunction(0x169398u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169368u; }
        if (ctx->pc != 0x169368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169398_0x169398(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169368u; }
        if (ctx->pc != 0x169368u) { return; }
    }
    ctx->pc = 0x169368u;
label_169368:
    // 0x169368: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x169368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16936c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16936cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169370: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x169370u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169374: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x169374u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169378: 0x805e46e  j           func_1791B8
    ctx->pc = 0x169378u;
    ctx->pc = 0x16937Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169378u;
            // 0x16937c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1791B8u;
    if (runtime->hasFunction(0x1791B8u)) {
        auto targetFn = runtime->lookupFunction(0x1791B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001791B8_0x1791b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169380u;
label_169380:
    // 0x169380: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169380u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169384: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x169384u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169388: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x169388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16938c: 0x3e00008  jr          $ra
    ctx->pc = 0x16938Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16938Cu;
            // 0x169390: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169350u: goto label_169350;
            case 0x169368u: goto label_169368;
            case 0x169380u: goto label_169380;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169394u;
    // 0x169394: 0x0  nop
    ctx->pc = 0x169394u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
