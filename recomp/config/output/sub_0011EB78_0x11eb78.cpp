#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EB78
// Address: 0x11eb78 - 0x11ebc8
void sub_0011EB78_0x11eb78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EB78_0x11eb78");
#endif

    switch (ctx->pc) {
        case 0x11eb90u: goto label_11eb90;
        case 0x11eb9cu: goto label_11eb9c;
        case 0x11ebacu: goto label_11ebac;
        default: break;
    }

    ctx->pc = 0x11eb78u;

    // 0x11eb78: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11eb78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11eb7c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11eb7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11eb80: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11eb80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11eb84: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11eb84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11eb88: 0xc047598  jal         func_11D660
    ctx->pc = 0x11EB88u;
    SET_GPR_U32(ctx, 31, 0x11EB90u);
    ctx->pc = 0x11EB8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB88u;
            // 0x11eb8c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB90u; }
        if (ctx->pc != 0x11EB90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB90u; }
        if (ctx->pc != 0x11EB90u) { return; }
    }
    ctx->pc = 0x11EB90u;
label_11eb90:
    // 0x11eb90: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11eb90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11eb94: 0xc047ab2  jal         func_11EAC8
    ctx->pc = 0x11EB94u;
    SET_GPR_U32(ctx, 31, 0x11EB9Cu);
    ctx->pc = 0x11EB98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB94u;
            // 0x11eb98: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EAC8u;
    if (runtime->hasFunction(0x11EAC8u)) {
        auto targetFn = runtime->lookupFunction(0x11EAC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB9Cu; }
        if (ctx->pc != 0x11EB9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EAC8_0x11eac8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EB9Cu; }
        if (ctx->pc != 0x11EB9Cu) { return; }
    }
    ctx->pc = 0x11EB9Cu;
label_11eb9c:
    // 0x11eb9c: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EB9Cu;
    {
        const bool branch_taken_0x11eb9c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EBA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EB9Cu;
            // 0x11eba0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11eb9c) {
            ctx->pc = 0x11EBACu;
            goto label_11ebac;
        }
    }
    ctx->pc = 0x11EBA4u;
    // 0x11eba4: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11EBA4u;
    SET_GPR_U32(ctx, 31, 0x11EBACu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EBACu; }
        if (ctx->pc != 0x11EBACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EBACu; }
        if (ctx->pc != 0x11EBACu) { return; }
    }
    ctx->pc = 0x11EBACu;
label_11ebac:
    // 0x11ebac: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11ebacu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ebb0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ebb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ebb4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ebb4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ebb8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ebb8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ebbc: 0x3e00008  jr          $ra
    ctx->pc = 0x11EBBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EBC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EBBCu;
            // 0x11ebc0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EB90u: goto label_11eb90;
            case 0x11EB9Cu: goto label_11eb9c;
            case 0x11EBACu: goto label_11ebac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EBC4u;
    // 0x11ebc4: 0x0  nop
    ctx->pc = 0x11ebc4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
