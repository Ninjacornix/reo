#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001752F8
// Address: 0x1752f8 - 0x175338
void sub_001752F8_0x1752f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001752F8_0x1752f8");
#endif

    switch (ctx->pc) {
        case 0x17530cu: goto label_17530c;
        case 0x175324u: goto label_175324;
        default: break;
    }

    ctx->pc = 0x1752f8u;

    // 0x1752f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1752f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1752fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1752fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175300: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x175300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x175304: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x175304u;
    SET_GPR_U32(ctx, 31, 0x17530Cu);
    ctx->pc = 0x175308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175304u;
            // 0x175308: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17530Cu; }
        if (ctx->pc != 0x17530Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17530Cu; }
        if (ctx->pc != 0x17530Cu) { return; }
    }
    ctx->pc = 0x17530Cu;
label_17530c:
    // 0x17530c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17530cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x175310: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x175310u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175314: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x175314u;
    {
        const bool branch_taken_0x175314 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175314u;
            // 0x175318: 0x34a50111  ori         $a1, $a1, 0x111 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)273);
        ctx->in_delay_slot = false;
        if (branch_taken_0x175314) {
            ctx->pc = 0x175324u;
            goto label_175324;
        }
    }
    ctx->pc = 0x17531Cu;
    // 0x17531c: 0xc05a704  jal         func_169C10
    ctx->pc = 0x17531Cu;
    SET_GPR_U32(ctx, 31, 0x175324u);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175324u; }
        if (ctx->pc != 0x175324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175324u; }
        if (ctx->pc != 0x175324u) { return; }
    }
    ctx->pc = 0x175324u;
label_175324:
    // 0x175324: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x175324u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x175328: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175328u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17532c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17532cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175330: 0x3e00008  jr          $ra
    ctx->pc = 0x175330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175330u;
            // 0x175334: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17530Cu: goto label_17530c;
            case 0x175324u: goto label_175324;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175338u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
