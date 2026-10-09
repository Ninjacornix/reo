#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176930
// Address: 0x176930 - 0x1769b0
void sub_00176930_0x176930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176930_0x176930");
#endif

    switch (ctx->pc) {
        case 0x176954u: goto label_176954;
        case 0x176980u: goto label_176980;
        default: break;
    }

    ctx->pc = 0x176930u;

    // 0x176930: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x176930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x176934: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x176934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x176938: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176938u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17693c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17693cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176940: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x176940u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x176944: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x176944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x176948: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x176948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17694c: 0xc05d906  jal         func_176418
    ctx->pc = 0x17694Cu;
    SET_GPR_U32(ctx, 31, 0x176954u);
    ctx->pc = 0x176950u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17694Cu;
            // 0x176950: 0x26300cc0  addiu       $s0, $s1, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 3264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176418u;
    if (runtime->hasFunction(0x176418u)) {
        auto targetFn = runtime->lookupFunction(0x176418u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176954u; }
        if (ctx->pc != 0x176954u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176418_0x176418(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176954u; }
        if (ctx->pc != 0x176954u) { return; }
    }
    ctx->pc = 0x176954u;
label_176954:
    // 0x176954: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x176954u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176958: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x176958u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17695c: 0x8e030248  lw          $v1, 0x248($s0)
    ctx->pc = 0x17695cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 584)));
    // 0x176960: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x176960u;
    {
        const bool branch_taken_0x176960 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x176964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176960u;
            // 0x176964: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176960) {
            ctx->pc = 0x176978u;
            goto label_176978;
        }
    }
    ctx->pc = 0x176968u;
    // 0x176968: 0x8e03024c  lw          $v1, 0x24C($s0)
    ctx->pc = 0x176968u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 588)));
    // 0x17696c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x17696cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x176970: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x176970u;
    {
        const bool branch_taken_0x176970 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x176974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176970u;
            // 0x176974: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176970) {
            ctx->pc = 0x176994u;
            goto label_176994;
        }
    }
    ctx->pc = 0x176978u;
label_176978:
    // 0x176978: 0xc05d7c8  jal         func_175F20
    ctx->pc = 0x176978u;
    SET_GPR_U32(ctx, 31, 0x176980u);
    ctx->pc = 0x175F20u;
    if (runtime->hasFunction(0x175F20u)) {
        auto targetFn = runtime->lookupFunction(0x175F20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176980u; }
        if (ctx->pc != 0x176980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175F20_0x175f20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176980u; }
        if (ctx->pc != 0x176980u) { return; }
    }
    ctx->pc = 0x176980u;
label_176980:
    // 0x176980: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x176980u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176984: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x176984u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x176988: 0xae020248  sw          $v0, 0x248($s0)
    ctx->pc = 0x176988u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 584), GPR_U32(ctx, 2));
    // 0x17698c: 0xae03024c  sw          $v1, 0x24C($s0)
    ctx->pc = 0x17698cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 588), GPR_U32(ctx, 3));
    // 0x176990: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x176990u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_176994:
    // 0x176994: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x176994u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176998: 0xae220044  sw          $v0, 0x44($s1)
    ctx->pc = 0x176998u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 2));
    // 0x17699c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17699cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1769a0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1769a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1769a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1769A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1769A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1769A4u;
            // 0x1769a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176954u: goto label_176954;
            case 0x176978u: goto label_176978;
            case 0x176980u: goto label_176980;
            case 0x176994u: goto label_176994;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1769ACu;
    // 0x1769ac: 0x0  nop
    ctx->pc = 0x1769acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
