#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A598
// Address: 0x17a598 - 0x17a5d8
void sub_0017A598_0x17a598(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A598_0x17a598");
#endif

    switch (ctx->pc) {
        case 0x17a5acu: goto label_17a5ac;
        default: break;
    }

    ctx->pc = 0x17a598u;

    // 0x17a598: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17a598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a59c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a5a0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17a5a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17a5a4: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x17A5A4u;
    SET_GPR_U32(ctx, 31, 0x17A5ACu);
    ctx->pc = 0x17A5A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A5A4u;
            // 0x17a5a8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A5ACu; }
        if (ctx->pc != 0x17A5ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A5ACu; }
        if (ctx->pc != 0x17A5ACu) { return; }
    }
    ctx->pc = 0x17A5ACu;
label_17a5ac:
    // 0x17a5ac: 0x240300e0  addiu       $v1, $zero, 0xE0
    ctx->pc = 0x17a5acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x17a5b0: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A5B0u;
    {
        const bool branch_taken_0x17a5b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17A5B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A5B0u;
            // 0x17a5b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a5b0) {
            ctx->pc = 0x17A5C8u;
            goto label_17a5c8;
        }
    }
    ctx->pc = 0x17A5B8u;
    // 0x17a5b8: 0x92030020  lbu         $v1, 0x20($s0)
    ctx->pc = 0x17a5b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x17a5bc: 0x3102b  sltu        $v0, $zero, $v1
    ctx->pc = 0x17a5bcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x17a5c0: 0x2c630002  sltiu       $v1, $v1, 0x2
    ctx->pc = 0x17a5c0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x17a5c4: 0x3100a  movz        $v0, $zero, $v1
    ctx->pc = 0x17a5c4u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_17a5c8:
    // 0x17a5c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a5c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a5cc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17a5ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a5d0: 0x3e00008  jr          $ra
    ctx->pc = 0x17A5D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A5D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A5D0u;
            // 0x17a5d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A5ACu: goto label_17a5ac;
            case 0x17A5C8u: goto label_17a5c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A5D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
