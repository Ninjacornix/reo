#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFB80
// Address: 0x1afb80 - 0x1afbec
void sub_001AFB80_0x1afb80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFB80_0x1afb80");
#endif

    switch (ctx->pc) {
        case 0x1afb94u: goto label_1afb94;
        case 0x1afbccu: goto label_1afbcc;
        case 0x1afbdcu: goto label_1afbdc;
        default: break;
    }

    ctx->pc = 0x1afb80u;

    // 0x1afb80: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1afb80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1afb84: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1afb84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1afb88: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1afb88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1afb8c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFB8Cu;
    SET_GPR_U32(ctx, 31, 0x1AFB94u);
    ctx->pc = 0x1AFB90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB8Cu;
            // 0x1afb90: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFB94u; }
        if (ctx->pc != 0x1AFB94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFB94u; }
        if (ctx->pc != 0x1AFB94u) { return; }
    }
    ctx->pc = 0x1AFB94u;
label_1afb94:
    // 0x1afb94: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afb94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afb98: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFB98u;
    {
        const bool branch_taken_0x1afb98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFB9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB98u;
            // 0x1afb9c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afb98) {
            ctx->pc = 0x1AFBDCu;
            goto label_1afbdc;
        }
    }
    ctx->pc = 0x1AFBA0u;
    // 0x1afba0: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1AFBA0u;
    {
        const bool branch_taken_0x1afba0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afba0) {
            ctx->pc = 0x1AFBDCu;
            goto label_1afbdc;
        }
    }
    ctx->pc = 0x1AFBA8u;
    // 0x1afba8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afba8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afbac: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFBACu;
    {
        const bool branch_taken_0x1afbac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFBB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFBACu;
            // 0x1afbb0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afbac) {
            ctx->pc = 0x1AFBD4u;
            goto label_1afbd4;
        }
    }
    ctx->pc = 0x1AFBB4u;
    // 0x1afbb4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFBB4u;
    {
        const bool branch_taken_0x1afbb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFBB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFBB4u;
            // 0x1afbb8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afbb4) {
            ctx->pc = 0x1AFBC4u;
            goto label_1afbc4;
        }
    }
    ctx->pc = 0x1AFBBCu;
    // 0x1afbbc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AFBBCu;
    {
        const bool branch_taken_0x1afbbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFBC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFBBCu;
            // 0x1afbc0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afbbc) {
            ctx->pc = 0x1AFBE0u;
            goto label_1afbe0;
        }
    }
    ctx->pc = 0x1AFBC4u;
label_1afbc4:
    // 0x1afbc4: 0xc204074  jal         func_8101D0
    ctx->pc = 0x1AFBC4u;
    SET_GPR_U32(ctx, 31, 0x1AFBCCu);
    ctx->pc = 0x8101D0u;
    {
        auto targetFn = runtime->lookupFunction(0x8101D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFBCCu; }
        if (ctx->pc != 0x1AFBCCu) { return; }
    }
    ctx->pc = 0x1AFBCCu;
label_1afbcc:
    // 0x1afbcc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFBCCu;
    {
        const bool branch_taken_0x1afbcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afbcc) {
            ctx->pc = 0x1AFBDCu;
            goto label_1afbdc;
        }
    }
    ctx->pc = 0x1AFBD4u;
label_1afbd4:
    // 0x1afbd4: 0xc2046ec  jal         func_811BB0
    ctx->pc = 0x1AFBD4u;
    SET_GPR_U32(ctx, 31, 0x1AFBDCu);
    ctx->pc = 0x811BB0u;
    {
        auto targetFn = runtime->lookupFunction(0x811BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFBDCu; }
        if (ctx->pc != 0x1AFBDCu) { return; }
    }
    ctx->pc = 0x1AFBDCu;
label_1afbdc:
    // 0x1afbdc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1afbdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1afbe0:
    // 0x1afbe0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1afbe0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1afbe4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFBE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFBE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFBE4u;
            // 0x1afbe8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFB94u: goto label_1afb94;
            case 0x1AFBC4u: goto label_1afbc4;
            case 0x1AFBCCu: goto label_1afbcc;
            case 0x1AFBD4u: goto label_1afbd4;
            case 0x1AFBDCu: goto label_1afbdc;
            case 0x1AFBE0u: goto label_1afbe0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFBECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
