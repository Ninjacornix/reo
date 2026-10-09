#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166988
// Address: 0x166988 - 0x1669e0
void sub_00166988_0x166988(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166988_0x166988");
#endif

    switch (ctx->pc) {
        case 0x1669ccu: goto label_1669cc;
        default: break;
    }

    ctx->pc = 0x166988u;

    // 0x166988: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166988u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16698c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x16698cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166990: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166990u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166994: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x166994u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166998: 0xc71823  subu        $v1, $a2, $a3
    ctx->pc = 0x166998u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x16699c: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x16699cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1669a0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1669a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1669a4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1669a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1669a8: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x1669a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x1669ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1669acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1669b0: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1669b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1669b4: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1669b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1669b8: 0x18600005  blez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1669B8u;
    {
        const bool branch_taken_0x1669b8 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x1669BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1669B8u;
            // 0x1669bc: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1669b8) {
            ctx->pc = 0x1669D0u;
            goto label_1669d0;
        }
    }
    ctx->pc = 0x1669C0u;
    // 0x1669c0: 0xae070010  sw          $a3, 0x10($s0)
    ctx->pc = 0x1669c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 7));
    // 0x1669c4: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x1669C4u;
    SET_GPR_U32(ctx, 31, 0x1669CCu);
    ctx->pc = 0x1669C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1669C4u;
            // 0x1669c8: 0xae000014  sw          $zero, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1669CCu; }
        if (ctx->pc != 0x1669CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1669CCu; }
        if (ctx->pc != 0x1669CCu) { return; }
    }
    ctx->pc = 0x1669CCu;
label_1669cc:
    // 0x1669cc: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1669ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
label_1669d0:
    // 0x1669d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1669d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1669d4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1669d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1669d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1669D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1669DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1669D8u;
            // 0x1669dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1669CCu: goto label_1669cc;
            case 0x1669D0u: goto label_1669d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1669E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
