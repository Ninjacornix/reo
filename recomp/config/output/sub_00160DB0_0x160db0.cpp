#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160DB0
// Address: 0x160db0 - 0x160e24
void sub_00160DB0_0x160db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160DB0_0x160db0");
#endif

    switch (ctx->pc) {
        case 0x160dccu: goto label_160dcc;
        case 0x160ddcu: goto label_160ddc;
        case 0x160e00u: goto label_160e00;
        case 0x160e0cu: goto label_160e0c;
        default: break;
    }

    ctx->pc = 0x160db0u;

    // 0x160db0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x160db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x160db4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160db8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x160db8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160dbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x160dbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x160dc0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x160dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x160dc4: 0xc05838a  jal         func_160E28
    ctx->pc = 0x160DC4u;
    SET_GPR_U32(ctx, 31, 0x160DCCu);
    ctx->pc = 0x160DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160DC4u;
            // 0x160dc8: 0x24b10060  addiu       $s1, $a1, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160E28u;
    if (runtime->hasFunction(0x160E28u)) {
        auto targetFn = runtime->lookupFunction(0x160E28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160DCCu; }
        if (ctx->pc != 0x160DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160E28_0x160e28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160DCCu; }
        if (ctx->pc != 0x160DCCu) { return; }
    }
    ctx->pc = 0x160DCCu;
label_160dcc:
    // 0x160dcc: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x160dccu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x160dd0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x160dd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160dd4: 0xc0583a6  jal         func_160E98
    ctx->pc = 0x160DD4u;
    SET_GPR_U32(ctx, 31, 0x160DDCu);
    ctx->pc = 0x160DD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160DD4u;
            // 0x160dd8: 0x26100088  addiu       $s0, $s0, 0x88 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160E98u;
    if (runtime->hasFunction(0x160E98u)) {
        auto targetFn = runtime->lookupFunction(0x160E98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160DDCu; }
        if (ctx->pc != 0x160DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160E98_0x160e98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160DDCu; }
        if (ctx->pc != 0x160DDCu) { return; }
    }
    ctx->pc = 0x160DDCu;
label_160ddc:
    // 0x160ddc: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x160ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x160de0: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x160de0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x160de4: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x160de4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x160de8: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x160de8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x160dec: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x160decu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x160df0: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x160df0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x160df4: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x160df4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x160df8: 0xc0583c2  jal         func_160F08
    ctx->pc = 0x160DF8u;
    SET_GPR_U32(ctx, 31, 0x160E00u);
    ctx->pc = 0x160DFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160DF8u;
            // 0x160dfc: 0xae230010  sw          $v1, 0x10($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160F08u;
    if (runtime->hasFunction(0x160F08u)) {
        auto targetFn = runtime->lookupFunction(0x160F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160E00u; }
        if (ctx->pc != 0x160E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160F08_0x160f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160E00u; }
        if (ctx->pc != 0x160E00u) { return; }
    }
    ctx->pc = 0x160E00u;
label_160e00:
    // 0x160e00: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x160e00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x160e04: 0xc0583c2  jal         func_160F08
    ctx->pc = 0x160E04u;
    SET_GPR_U32(ctx, 31, 0x160E0Cu);
    ctx->pc = 0x160E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160E04u;
            // 0x160e08: 0xae220014  sw          $v0, 0x14($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160F08u;
    if (runtime->hasFunction(0x160F08u)) {
        auto targetFn = runtime->lookupFunction(0x160F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160E0Cu; }
        if (ctx->pc != 0x160E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160F08_0x160f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160E0Cu; }
        if (ctx->pc != 0x160E0Cu) { return; }
    }
    ctx->pc = 0x160E0Cu;
label_160e0c:
    // 0x160e0c: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x160e0cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
    // 0x160e10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160e10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160e14: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160e14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160e18: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x160e18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160e1c: 0x3e00008  jr          $ra
    ctx->pc = 0x160E1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160E1Cu;
            // 0x160e20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160DCCu: goto label_160dcc;
            case 0x160DDCu: goto label_160ddc;
            case 0x160E00u: goto label_160e00;
            case 0x160E0Cu: goto label_160e0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160E24u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
