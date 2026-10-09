#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D748
// Address: 0x17d748 - 0x17d7a0
void sub_0017D748_0x17d748(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D748_0x17d748");
#endif

    switch (ctx->pc) {
        case 0x17d75cu: goto label_17d75c;
        case 0x17d770u: goto label_17d770;
        default: break;
    }

    ctx->pc = 0x17d748u;

    // 0x17d748: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d74c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d74cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d750: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17d750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17d754: 0xc05f5e8  jal         func_17D7A0
    ctx->pc = 0x17D754u;
    SET_GPR_U32(ctx, 31, 0x17D75Cu);
    ctx->pc = 0x17D7A0u;
    if (runtime->hasFunction(0x17D7A0u)) {
        auto targetFn = runtime->lookupFunction(0x17D7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D75Cu; }
        if (ctx->pc != 0x17D75Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D7A0_0x17d7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D75Cu; }
        if (ctx->pc != 0x17D75Cu) { return; }
    }
    ctx->pc = 0x17D75Cu;
label_17d75c:
    // 0x17d75c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x17d75cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d760: 0x1200000b  beqz        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x17D760u;
    {
        const bool branch_taken_0x17d760 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x17D764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D760u;
            // 0x17d764: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d760) {
            ctx->pc = 0x17D790u;
            goto label_17d790;
        }
    }
    ctx->pc = 0x17D768u;
    // 0x17d768: 0xc05f5fc  jal         func_17D7F0
    ctx->pc = 0x17D768u;
    SET_GPR_U32(ctx, 31, 0x17D770u);
    ctx->pc = 0x17D7F0u;
    if (runtime->hasFunction(0x17D7F0u)) {
        auto targetFn = runtime->lookupFunction(0x17D7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D770u; }
        if (ctx->pc != 0x17D770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D7F0_0x17d7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D770u; }
        if (ctx->pc != 0x17D770u) { return; }
    }
    ctx->pc = 0x17D770u;
label_17d770:
    // 0x17d770: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17d770u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17d774: 0x2463f748  addiu       $v1, $v1, -0x8B8
    ctx->pc = 0x17d774u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294965064));
    // 0x17d778: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x17d778u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17d77c: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x17d77cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17d780: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x17d780u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d784: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x17d784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x17d788: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x17d788u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x17d78c: 0xae050000  sw          $a1, 0x0($s0)
    ctx->pc = 0x17d78cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
label_17d790:
    // 0x17d790: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d790u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d794: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17d794u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d798: 0x3e00008  jr          $ra
    ctx->pc = 0x17D798u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D79Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D798u;
            // 0x17d79c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D75Cu: goto label_17d75c;
            case 0x17D770u: goto label_17d770;
            case 0x17D790u: goto label_17d790;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D7A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
