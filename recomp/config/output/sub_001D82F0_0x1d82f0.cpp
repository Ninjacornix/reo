#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D82F0
// Address: 0x1d82f0 - 0x1d8360
void sub_001D82F0_0x1d82f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D82F0_0x1d82f0");
#endif

    switch (ctx->pc) {
        case 0x1d830cu: goto label_1d830c;
        case 0x1d833cu: goto label_1d833c;
        case 0x1d8348u: goto label_1d8348;
        default: break;
    }

    ctx->pc = 0x1d82f0u;

    // 0x1d82f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d82f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d82f4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d82f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d82f8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d82f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d82fc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d82fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8300: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d8300u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8304: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8304u;
    SET_GPR_U32(ctx, 31, 0x1D830Cu);
    ctx->pc = 0x1D8308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8304u;
            // 0x1d8308: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D830Cu; }
        if (ctx->pc != 0x1D830Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D830Cu; }
        if (ctx->pc != 0x1D830Cu) { return; }
    }
    ctx->pc = 0x1D830Cu;
label_1d830c:
    // 0x1d830c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d830cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d8310: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8310u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8314: 0x2442729c  addiu       $v0, $v0, 0x729C
    ctx->pc = 0x1d8314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29340));
    // 0x1d8318: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8318u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d831c: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x1d831cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x1d8320: 0x2404001c  addiu       $a0, $zero, 0x1C
    ctx->pc = 0x1d8320u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x1d8324: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8324u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8328: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x1d8328u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x1d832c: 0x24060028  addiu       $a2, $zero, 0x28
    ctx->pc = 0x1d832cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1d8330: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d8330u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8334: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8334u;
    SET_GPR_U32(ctx, 31, 0x1D833Cu);
    ctx->pc = 0x1D8338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8334u;
            // 0x1d8338: 0x24080020  addiu       $t0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D833Cu; }
        if (ctx->pc != 0x1D833Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D833Cu; }
        if (ctx->pc != 0x1D833Cu) { return; }
    }
    ctx->pc = 0x1D833Cu;
label_1d833c:
    // 0x1d833c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d833cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8340: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8340u;
    SET_GPR_U32(ctx, 31, 0x1D8348u);
    ctx->pc = 0x1D8344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8340u;
            // 0x1d8344: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8348u; }
        if (ctx->pc != 0x1D8348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8348u; }
        if (ctx->pc != 0x1D8348u) { return; }
    }
    ctx->pc = 0x1D8348u;
label_1d8348:
    // 0x1d8348: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8348u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d834c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d834cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d8350: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d8350u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8354: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8354u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8358: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D835Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8358u;
            // 0x1d835c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D830Cu: goto label_1d830c;
            case 0x1D833Cu: goto label_1d833c;
            case 0x1D8348u: goto label_1d8348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8360u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
