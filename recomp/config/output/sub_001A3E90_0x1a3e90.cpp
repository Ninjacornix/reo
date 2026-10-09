#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3E90
// Address: 0x1a3e90 - 0x1a3ee0
void sub_001A3E90_0x1a3e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3E90_0x1a3e90");
#endif

    switch (ctx->pc) {
        case 0x1a3eacu: goto label_1a3eac;
        case 0x1a3ec0u: goto label_1a3ec0;
        case 0x1a3ed0u: goto label_1a3ed0;
        default: break;
    }

    ctx->pc = 0x1a3e90u;

    // 0x1a3e90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3e94: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x1a3e94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3e98: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x1a3e98u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3e9c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a3ea0: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x1a3ea0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3ea4: 0xc068d68  jal         func_1A35A0
    ctx->pc = 0x1A3EA4u;
    SET_GPR_U32(ctx, 31, 0x1A3EACu);
    ctx->pc = 0x1A3EA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3EA4u;
            // 0x1a3ea8: 0x3c05000c  lui         $a1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)12 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35A0u;
    if (runtime->hasFunction(0x1A35A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3EACu; }
        if (ctx->pc != 0x1A3EACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35A0_0x1a35a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3EACu; }
        if (ctx->pc != 0x1A3EACu) { return; }
    }
    ctx->pc = 0x1A3EACu;
label_1a3eac:
    // 0x1a3eac: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A3EACu;
    {
        const bool branch_taken_0x1a3eac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3EACu;
            // 0x1a3eb0: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3eac) {
            ctx->pc = 0x1A3EC8u;
            goto label_1a3ec8;
        }
    }
    ctx->pc = 0x1A3EB4u;
    // 0x1a3eb4: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x1a3eb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3eb8: 0xc068fdc  jal         func_1A3F70
    ctx->pc = 0x1A3EB8u;
    SET_GPR_U32(ctx, 31, 0x1A3EC0u);
    ctx->pc = 0x1A3EBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3EB8u;
            // 0x1a3ebc: 0xe0282d  daddu       $a1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3F70u;
    if (runtime->hasFunction(0x1A3F70u)) {
        auto targetFn = runtime->lookupFunction(0x1A3F70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3EC0u; }
        if (ctx->pc != 0x1A3EC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3F70_0x1a3f70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3EC0u; }
        if (ctx->pc != 0x1A3EC0u) { return; }
    }
    ctx->pc = 0x1A3EC0u;
label_1a3ec0:
    // 0x1a3ec0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A3EC0u;
    {
        const bool branch_taken_0x1a3ec0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3EC0u;
            // 0x1a3ec4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3ec0) {
            ctx->pc = 0x1A3ED4u;
            goto label_1a3ed4;
        }
    }
    ctx->pc = 0x1A3EC8u;
label_1a3ec8:
    // 0x1a3ec8: 0xc069168  jal         func_1A45A0
    ctx->pc = 0x1A3EC8u;
    SET_GPR_U32(ctx, 31, 0x1A3ED0u);
    ctx->pc = 0x1A3ECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3EC8u;
            // 0x1a3ecc: 0xe0282d  daddu       $a1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A45A0u;
    if (runtime->hasFunction(0x1A45A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A45A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3ED0u; }
        if (ctx->pc != 0x1A3ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A45A0_0x1a45a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3ED0u; }
        if (ctx->pc != 0x1A3ED0u) { return; }
    }
    ctx->pc = 0x1A3ED0u;
label_1a3ed0:
    // 0x1a3ed0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a3ed4:
    // 0x1a3ed4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3ED4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3ED4u;
            // 0x1a3ed8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3EACu: goto label_1a3eac;
            case 0x1A3EC0u: goto label_1a3ec0;
            case 0x1A3EC8u: goto label_1a3ec8;
            case 0x1A3ED0u: goto label_1a3ed0;
            case 0x1A3ED4u: goto label_1a3ed4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3EDCu;
    // 0x1a3edc: 0x0  nop
    ctx->pc = 0x1a3edcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
