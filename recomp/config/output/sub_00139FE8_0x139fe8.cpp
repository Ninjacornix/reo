#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139FE8
// Address: 0x139fe8 - 0x13a034
void sub_00139FE8_0x139fe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139FE8_0x139fe8");
#endif

    switch (ctx->pc) {
        case 0x13a004u: goto label_13a004;
        default: break;
    }

    ctx->pc = 0x139fe8u;

    // 0x139fe8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x139fe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x139fec: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x139fecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139ff0: 0x14a00007  bnez        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x139FF0u;
    {
        const bool branch_taken_0x139ff0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x139FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139FF0u;
            // 0x139ff4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139ff0) {
            ctx->pc = 0x13A010u;
            goto label_13a010;
        }
    }
    ctx->pc = 0x139FF8u;
    // 0x139ff8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139ff8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139ffc: 0xc04e57e  jal         func_1395F8
    ctx->pc = 0x139FFCu;
    SET_GPR_U32(ctx, 31, 0x13A004u);
    ctx->pc = 0x13A000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139FFCu;
            // 0x13a000: 0x24a5cbe8  addiu       $a1, $a1, -0x3418 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953960));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1395F8u;
    if (runtime->hasFunction(0x1395F8u)) {
        auto targetFn = runtime->lookupFunction(0x1395F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A004u; }
        if (ctx->pc != 0x13A004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001395F8_0x1395f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A004u; }
        if (ctx->pc != 0x13A004u) { return; }
    }
    ctx->pc = 0x13A004u;
label_13a004:
    // 0x13a004: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13A004u;
    {
        const bool branch_taken_0x13a004 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A004u;
            // 0x13a008: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a004) {
            ctx->pc = 0x13A028u;
            goto label_13a028;
        }
    }
    ctx->pc = 0x13A00Cu;
    // 0x13a00c: 0x0  nop
    ctx->pc = 0x13a00cu;
    // NOP
label_13a010:
    // 0x13a010: 0x80a30002  lb          $v1, 0x2($a1)
    ctx->pc = 0x13a010u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x13a014: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13a014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13a018: 0x54620003  bnel        $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13A018u;
    {
        const bool branch_taken_0x13a018 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13a018) {
            ctx->pc = 0x13A01Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13A018u;
            // 0x13a01c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13A028u;
            goto label_13a028;
        }
    }
    ctx->pc = 0x13A020u;
    // 0x13a020: 0x8ca20014  lw          $v0, 0x14($a1)
    ctx->pc = 0x13a020u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x13a024: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x13a024u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
label_13a028:
    // 0x13a028: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13a028u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13a02c: 0x3e00008  jr          $ra
    ctx->pc = 0x13A02Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A02Cu;
            // 0x13a030: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A004u: goto label_13a004;
            case 0x13A010u: goto label_13a010;
            case 0x13A028u: goto label_13a028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A034u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
