#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125818
// Address: 0x125818 - 0x125878
void sub_00125818_0x125818(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125818_0x125818");
#endif

    switch (ctx->pc) {
        case 0x125840u: goto label_125840;
        case 0x125854u: goto label_125854;
        default: break;
    }

    ctx->pc = 0x125818u;

    // 0x125818: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x125818u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12581c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12581cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x125820: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x125820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x125824: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x125824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125828: 0x2450b958  addiu       $s0, $v0, -0x46A8
    ctx->pc = 0x125828u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949208));
    // 0x12582c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12582cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x125830: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x125830u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x125834: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x125834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x125838: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x125838u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12583c: 0x0  nop
    ctx->pc = 0x12583cu;
    // NOP
label_125840:
    // 0x125840: 0x86020000  lh          $v0, 0x0($s0)
    ctx->pc = 0x125840u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x125844: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x125844u;
    {
        const bool branch_taken_0x125844 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x125844) {
            ctx->pc = 0x125848u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125844u;
            // 0x125848: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125858u;
            goto label_125858;
        }
    }
    ctx->pc = 0x12584Cu;
    // 0x12584c: 0xc0495da  jal         func_125768
    ctx->pc = 0x12584Cu;
    SET_GPR_U32(ctx, 31, 0x125854u);
    ctx->pc = 0x125850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12584Cu;
            // 0x125850: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125768u;
    if (runtime->hasFunction(0x125768u)) {
        auto targetFn = runtime->lookupFunction(0x125768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125854u; }
        if (ctx->pc != 0x125854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125768_0x125768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125854u; }
        if (ctx->pc != 0x125854u) { return; }
    }
    ctx->pc = 0x125854u;
label_125854:
    // 0x125854: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x125854u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_125858:
    // 0x125858: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x125858u;
    {
        const bool branch_taken_0x125858 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x12585Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125858u;
            // 0x12585c: 0x261000e4  addiu       $s0, $s0, 0xE4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 228));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125858) {
            ctx->pc = 0x125840u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_125840;
        }
    }
    ctx->pc = 0x125860u;
    // 0x125860: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125860u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125864: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x125864u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125868: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x125868u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12586c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12586cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x125870: 0x3e00008  jr          $ra
    ctx->pc = 0x125870u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125870u;
            // 0x125874: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125840u: goto label_125840;
            case 0x125854u: goto label_125854;
            case 0x125858u: goto label_125858;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125878u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
