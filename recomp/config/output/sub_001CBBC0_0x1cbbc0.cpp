#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBBC0
// Address: 0x1cbbc0 - 0x1cbc60
void sub_001CBBC0_0x1cbbc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBBC0_0x1cbbc0");
#endif

    switch (ctx->pc) {
        case 0x1cbc04u: goto label_1cbc04;
        case 0x1cbc1cu: goto label_1cbc1c;
        case 0x1cbc28u: goto label_1cbc28;
        case 0x1cbc40u: goto label_1cbc40;
        default: break;
    }

    ctx->pc = 0x1cbbc0u;

    // 0x1cbbc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1cbbc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cbbc4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbbc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbbc8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1cbbc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1cbbcc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cbbccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cbbd0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cbbd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cbbd4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1cbbd4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cbbd8: 0x8c22d9f8  lw          $v0, -0x2608($at)
    ctx->pc = 0x1cbbd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957560)));
    // 0x1cbbdc: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CBBDCu;
    {
        const bool branch_taken_0x1cbbdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CBBE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBBDCu;
            // 0x1cbbe0: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbbdc) {
            ctx->pc = 0x1CBBF4u;
            goto label_1cbbf4;
        }
    }
    ctx->pc = 0x1CBBE4u;
    // 0x1cbbe4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbbe4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbbe8: 0x8c22da00  lw          $v0, -0x2600($at)
    ctx->pc = 0x1cbbe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbbec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBBECu;
    {
        const bool branch_taken_0x1cbbec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbbec) {
            ctx->pc = 0x1CBBFCu;
            goto label_1cbbfc;
        }
    }
    ctx->pc = 0x1CBBF4u;
label_1cbbf4:
    // 0x1cbbf4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1CBBF4u;
    {
        const bool branch_taken_0x1cbbf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBBF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBBF4u;
            // 0x1cbbf8: 0x2402fff0  addiu       $v0, $zero, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbbf4) {
            ctx->pc = 0x1CBC48u;
            goto label_1cbc48;
        }
    }
    ctx->pc = 0x1CBBFCu;
label_1cbbfc:
    // 0x1cbbfc: 0xc072f78  jal         func_1CBDE0
    ctx->pc = 0x1CBBFCu;
    SET_GPR_U32(ctx, 31, 0x1CBC04u);
    ctx->pc = 0x1CBDE0u;
    if (runtime->hasFunction(0x1CBDE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBC04u; }
        if (ctx->pc != 0x1CBC04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDE0_0x1cbde0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBC04u; }
        if (ctx->pc != 0x1CBC04u) { return; }
    }
    ctx->pc = 0x1CBC04u;
label_1cbc04:
    // 0x1cbc04: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbc04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbc08: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1cbc08u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cbc0c: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbc0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbc10: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x1cbc10u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1cbc14: 0xc079402  jal         func_1E5008
    ctx->pc = 0x1CBC14u;
    SET_GPR_U32(ctx, 31, 0x1CBC1Cu);
    ctx->pc = 0x1CBC18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBC14u;
            // 0x1cbc18: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1E5008u;
    if (runtime->hasFunction(0x1E5008u)) {
        auto targetFn = runtime->lookupFunction(0x1E5008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBC1Cu; }
        if (ctx->pc != 0x1CBC1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E5008_0x1e5008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBC1Cu; }
        if (ctx->pc != 0x1CBC1Cu) { return; }
    }
    ctx->pc = 0x1CBC1Cu;
label_1cbc1c:
    // 0x1cbc1c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbc1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbc20: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CBC20u;
    SET_GPR_U32(ctx, 31, 0x1CBC28u);
    ctx->pc = 0x1CBC24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBC20u;
            // 0x1cbc24: 0xac22da00  sw          $v0, -0x2600($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294957568), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBDF0u;
    if (runtime->hasFunction(0x1CBDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBC28u; }
        if (ctx->pc != 0x1CBC28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDF0_0x1cbdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBC28u; }
        if (ctx->pc != 0x1CBC28u) { return; }
    }
    ctx->pc = 0x1CBC28u;
label_1cbc28:
    // 0x1cbc28: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbc28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbc2c: 0x8c22da00  lw          $v0, -0x2600($at)
    ctx->pc = 0x1cbc2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbc30: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CBC30u;
    {
        const bool branch_taken_0x1cbc30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBC34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBC30u;
            // 0x1cbc34: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbc30) {
            ctx->pc = 0x1CBC48u;
            goto label_1cbc48;
        }
    }
    ctx->pc = 0x1CBC38u;
    // 0x1cbc38: 0xc072ed8  jal         func_1CBB60
    ctx->pc = 0x1CBC38u;
    SET_GPR_U32(ctx, 31, 0x1CBC40u);
    ctx->pc = 0x1CBB60u;
    if (runtime->hasFunction(0x1CBB60u)) {
        auto targetFn = runtime->lookupFunction(0x1CBB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBC40u; }
        if (ctx->pc != 0x1CBC40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBB60_0x1cbb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBC40u; }
        if (ctx->pc != 0x1CBC40u) { return; }
    }
    ctx->pc = 0x1CBC40u;
label_1cbc40:
    // 0x1cbc40: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1CBC40u;
    {
        const bool branch_taken_0x1cbc40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbc40) {
            ctx->pc = 0x1CBC48u;
            goto label_1cbc48;
        }
    }
    ctx->pc = 0x1CBC48u;
label_1cbc48:
    // 0x1cbc48: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1cbc48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cbc4c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cbc4cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cbc50: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbc50u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbc54: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBC54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBC58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBC54u;
            // 0x1cbc58: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBBF4u: goto label_1cbbf4;
            case 0x1CBBFCu: goto label_1cbbfc;
            case 0x1CBC04u: goto label_1cbc04;
            case 0x1CBC1Cu: goto label_1cbc1c;
            case 0x1CBC28u: goto label_1cbc28;
            case 0x1CBC40u: goto label_1cbc40;
            case 0x1CBC48u: goto label_1cbc48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBC5Cu;
    // 0x1cbc5c: 0x0  nop
    ctx->pc = 0x1cbc5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
