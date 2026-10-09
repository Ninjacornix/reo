#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179DB0
// Address: 0x179db0 - 0x179e18
void sub_00179DB0_0x179db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179DB0_0x179db0");
#endif

    switch (ctx->pc) {
        case 0x179dd4u: goto label_179dd4;
        case 0x179de8u: goto label_179de8;
        default: break;
    }

    ctx->pc = 0x179db0u;

    // 0x179db0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179db4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179db8: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179db8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179dbc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179dbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179dc0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179dc4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179dc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179dc8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179dc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179dcc: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179DCCu;
    SET_GPR_U32(ctx, 31, 0x179DD4u);
    ctx->pc = 0x179DD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179DCCu;
            // 0x179dd0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179DD4u; }
        if (ctx->pc != 0x179DD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179DD4u; }
        if (ctx->pc != 0x179DD4u) { return; }
    }
    ctx->pc = 0x179DD4u;
label_179dd4:
    // 0x179dd4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179dd4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179dd8: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x179DD8u;
    {
        const bool branch_taken_0x179dd8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179DD8u;
            // 0x179ddc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179dd8) {
            ctx->pc = 0x179E00u;
            goto label_179e00;
        }
    }
    ctx->pc = 0x179DE0u;
    // 0x179de0: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179DE0u;
    SET_GPR_U32(ctx, 31, 0x179DE8u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179DE8u; }
        if (ctx->pc != 0x179DE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179DE8u; }
        if (ctx->pc != 0x179DE8u) { return; }
    }
    ctx->pc = 0x179DE8u;
label_179de8:
    // 0x179de8: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x179de8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x179dec: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179DECu;
    {
        const bool branch_taken_0x179dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x179DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179DECu;
            // 0x179df0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179dec) {
            ctx->pc = 0x179E00u;
            goto label_179e00;
        }
    }
    ctx->pc = 0x179DF4u;
    // 0x179df4: 0x92230019  lbu         $v1, 0x19($s1)
    ctx->pc = 0x179df4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 25)));
    // 0x179df8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179df8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179dfc: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179e00:
    // 0x179e00: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179e00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179e04: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179e04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179e08: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179e08u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179e0c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179e0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179e10: 0x3e00008  jr          $ra
    ctx->pc = 0x179E10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E10u;
            // 0x179e14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179DD4u: goto label_179dd4;
            case 0x179DE8u: goto label_179de8;
            case 0x179E00u: goto label_179e00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179E18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
