#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001563A0
// Address: 0x1563a0 - 0x156400
void sub_001563A0_0x1563a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001563A0_0x1563a0");
#endif

    switch (ctx->pc) {
        case 0x1563c4u: goto label_1563c4;
        default: break;
    }

    ctx->pc = 0x1563a0u;

    // 0x1563a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1563A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1563C4u: goto label_1563c4;
            case 0x1563E8u: goto label_1563e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1563A8u;
    // 0x1563a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1563a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1563ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1563acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1563b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1563b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1563b4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1563b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1563b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1563b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1563bc: 0xc0560f2  jal         func_1583C8
    ctx->pc = 0x1563BCu;
    SET_GPR_U32(ctx, 31, 0x1563C4u);
    ctx->pc = 0x1563C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1563BCu;
            // 0x1563c0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1583C8u;
    if (runtime->hasFunction(0x1583C8u)) {
        auto targetFn = runtime->lookupFunction(0x1583C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1563C4u; }
        if (ctx->pc != 0x1563C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583C8_0x1583c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1563C4u; }
        if (ctx->pc != 0x1563C4u) { return; }
    }
    ctx->pc = 0x1563C4u;
label_1563c4:
    // 0x1563c4: 0x3c05ff02  lui         $a1, 0xFF02
    ctx->pc = 0x1563c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65282 << 16));
    // 0x1563c8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1563C8u;
    {
        const bool branch_taken_0x1563c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1563CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1563C8u;
            // 0x1563cc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1563c8) {
            ctx->pc = 0x1563E8u;
            goto label_1563e8;
        }
    }
    ctx->pc = 0x1563D0u;
    // 0x1563d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1563d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1563d4: 0x34a50302  ori         $a1, $a1, 0x302
    ctx->pc = 0x1563d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)770);
    // 0x1563d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1563d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1563dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1563dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1563e0: 0x805607e  j           func_1581F8
    ctx->pc = 0x1563E0u;
    ctx->pc = 0x1563E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1563E0u;
            // 0x1563e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581F8u;
    if (runtime->hasFunction(0x1581F8u)) {
        auto targetFn = runtime->lookupFunction(0x1581F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001581F8_0x1581f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1563E8u;
label_1563e8:
    // 0x1563e8: 0xae110010  sw          $s1, 0x10($s0)
    ctx->pc = 0x1563e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
    // 0x1563ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1563ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1563f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1563f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1563f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1563f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1563f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1563F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1563FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1563F8u;
            // 0x1563fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1563C4u: goto label_1563c4;
            case 0x1563E8u: goto label_1563e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x156400u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
