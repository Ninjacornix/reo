#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001793F8
// Address: 0x1793f8 - 0x179468
void sub_001793F8_0x1793f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001793F8_0x1793f8");
#endif

    switch (ctx->pc) {
        case 0x179420u: goto label_179420;
        case 0x179434u: goto label_179434;
        default: break;
    }

    ctx->pc = 0x1793f8u;

    // 0x1793f8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1793f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1793fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1793fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179400: 0x30b100ff  andi        $s1, $a1, 0xFF
    ctx->pc = 0x179400u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179404: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179404u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179408: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x179408u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17940c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17940cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179410: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179414: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x179414u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x179418: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179418u;
    SET_GPR_U32(ctx, 31, 0x179420u);
    ctx->pc = 0x17941Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179418u;
            // 0x17941c: 0x8c900004  lw          $s0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179420u; }
        if (ctx->pc != 0x179420u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179420u; }
        if (ctx->pc != 0x179420u) { return; }
    }
    ctx->pc = 0x179420u;
label_179420:
    // 0x179420: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x179420u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179424: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x179424u;
    {
        const bool branch_taken_0x179424 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x179428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179424u;
            // 0x179428: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179424) {
            ctx->pc = 0x17944Cu;
            goto label_17944c;
        }
    }
    ctx->pc = 0x17942Cu;
    // 0x17942c: 0xc05e54e  jal         func_179538
    ctx->pc = 0x17942Cu;
    SET_GPR_U32(ctx, 31, 0x179434u);
    ctx->pc = 0x179538u;
    if (runtime->hasFunction(0x179538u)) {
        auto targetFn = runtime->lookupFunction(0x179538u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179434u; }
        if (ctx->pc != 0x179434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179538_0x179538(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179434u; }
        if (ctx->pc != 0x179434u) { return; }
    }
    ctx->pc = 0x179434u;
label_179434:
    // 0x179434: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x179434u;
    {
        const bool branch_taken_0x179434 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x179438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179434u;
            // 0x179438: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179434) {
            ctx->pc = 0x179448u;
            goto label_179448;
        }
    }
    ctx->pc = 0x17943Cu;
    // 0x17943c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17943Cu;
    {
        const bool branch_taken_0x17943c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x179440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17943Cu;
            // 0x179440: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17943c) {
            ctx->pc = 0x17944Cu;
            goto label_17944c;
        }
    }
    ctx->pc = 0x179444u;
    // 0x179444: 0x0  nop
    ctx->pc = 0x179444u;
    // NOP
label_179448:
    // 0x179448: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x179448u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
label_17944c:
    // 0x17944c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17944cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179450: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179450u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179454: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179454u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179458: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179458u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17945c: 0x3e00008  jr          $ra
    ctx->pc = 0x17945Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17945Cu;
            // 0x179460: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179420u: goto label_179420;
            case 0x179434u: goto label_179434;
            case 0x179448u: goto label_179448;
            case 0x17944Cu: goto label_17944c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179464u;
    // 0x179464: 0x0  nop
    ctx->pc = 0x179464u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
