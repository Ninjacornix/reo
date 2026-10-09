#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017DE60
// Address: 0x17de60 - 0x17deb0
void sub_0017DE60_0x17de60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017DE60_0x17de60");
#endif

    switch (ctx->pc) {
        case 0x17de88u: goto label_17de88;
        case 0x17de9cu: goto label_17de9c;
        default: break;
    }

    ctx->pc = 0x17de60u;

    // 0x17de60: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17de60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17de64: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17de64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17de68: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17de68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17de6c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17de6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17de70: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17de70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17de74: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17de74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17de78: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x17de78u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17de7c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x17de7cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x17de80: 0xc05f65a  jal         func_17D968
    ctx->pc = 0x17DE80u;
    SET_GPR_U32(ctx, 31, 0x17DE88u);
    ctx->pc = 0x17DE84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DE80u;
            // 0x17de84: 0x27a70004  addiu       $a3, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D968u;
    if (runtime->hasFunction(0x17D968u)) {
        auto targetFn = runtime->lookupFunction(0x17D968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DE88u; }
        if (ctx->pc != 0x17DE88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D968_0x17d968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DE88u; }
        if (ctx->pc != 0x17DE88u) { return; }
    }
    ctx->pc = 0x17DE88u;
label_17de88:
    // 0x17de88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17de88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17de8c: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x17de8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17de90: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x17de90u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17de94: 0xc05f7ac  jal         func_17DEB0
    ctx->pc = 0x17DE94u;
    SET_GPR_U32(ctx, 31, 0x17DE9Cu);
    ctx->pc = 0x17DE98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DE94u;
            // 0x17de98: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17DEB0u;
    if (runtime->hasFunction(0x17DEB0u)) {
        auto targetFn = runtime->lookupFunction(0x17DEB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DE9Cu; }
        if (ctx->pc != 0x17DE9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017DEB0_0x17deb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DE9Cu; }
        if (ctx->pc != 0x17DE9Cu) { return; }
    }
    ctx->pc = 0x17DE9Cu;
label_17de9c:
    // 0x17de9c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17de9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17dea0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17dea0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17dea4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17dea4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17dea8: 0x3e00008  jr          $ra
    ctx->pc = 0x17DEA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17DEACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DEA8u;
            // 0x17deac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17DE88u: goto label_17de88;
            case 0x17DE9Cu: goto label_17de9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17DEB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
