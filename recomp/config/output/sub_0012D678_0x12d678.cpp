#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D678
// Address: 0x12d678 - 0x12d6e0
void sub_0012D678_0x12d678(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D678_0x12d678");
#endif

    switch (ctx->pc) {
        case 0x12d6a0u: goto label_12d6a0;
        case 0x12d6b4u: goto label_12d6b4;
        default: break;
    }

    ctx->pc = 0x12d678u;

    // 0x12d678: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12d678u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12d67c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12d67cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12d680: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12d680u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x12d684: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12d684u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12d688: 0x24507d88  addiu       $s0, $v0, 0x7D88
    ctx->pc = 0x12d688u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 32136));
    // 0x12d68c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12d68cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12d690: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x12d690u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x12d694: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12d694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12d698: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x12d698u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12d69c: 0x0  nop
    ctx->pc = 0x12d69cu;
    // NOP
label_12d6a0:
    // 0x12d6a0: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x12d6a0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12d6a4: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x12D6A4u;
    {
        const bool branch_taken_0x12d6a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x12d6a4) {
            ctx->pc = 0x12D6A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12D6A4u;
            // 0x12d6a8: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12D6B8u;
            goto label_12d6b8;
        }
    }
    ctx->pc = 0x12D6ACu;
    // 0x12d6ac: 0xc04b58e  jal         func_12D638
    ctx->pc = 0x12D6ACu;
    SET_GPR_U32(ctx, 31, 0x12D6B4u);
    ctx->pc = 0x12D6B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D6ACu;
            // 0x12d6b0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D638u;
    if (runtime->hasFunction(0x12D638u)) {
        auto targetFn = runtime->lookupFunction(0x12D638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D6B4u; }
        if (ctx->pc != 0x12D6B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D638_0x12d638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D6B4u; }
        if (ctx->pc != 0x12D6B4u) { return; }
    }
    ctx->pc = 0x12D6B4u;
label_12d6b4:
    // 0x12d6b4: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x12d6b4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_12d6b8:
    // 0x12d6b8: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x12D6B8u;
    {
        const bool branch_taken_0x12d6b8 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x12D6BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D6B8u;
            // 0x12d6bc: 0x2610009c  addiu       $s0, $s0, 0x9C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 156));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d6b8) {
            ctx->pc = 0x12D6A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12d6a0;
        }
    }
    ctx->pc = 0x12D6C0u;
    // 0x12d6c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12d6c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d6c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12d6c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12d6c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12d6c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12d6cc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12d6ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12d6d0: 0x3e00008  jr          $ra
    ctx->pc = 0x12D6D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D6D0u;
            // 0x12d6d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D6A0u: goto label_12d6a0;
            case 0x12D6B4u: goto label_12d6b4;
            case 0x12D6B8u: goto label_12d6b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D6D8u;
    // 0x12d6d8: 0x3e00008  jr          $ra
    ctx->pc = 0x12D6D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D6DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D6D8u;
            // 0x12d6dc: 0x8c820030  lw          $v0, 0x30($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D6A0u: goto label_12d6a0;
            case 0x12D6B4u: goto label_12d6b4;
            case 0x12D6B8u: goto label_12d6b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D6E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
