#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3E90
// Address: 0x1d3e90 - 0x1d3f60
void sub_001D3E90_0x1d3e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3E90_0x1d3e90");
#endif

    switch (ctx->pc) {
        case 0x1d3ed4u: goto label_1d3ed4;
        case 0x1d3ee8u: goto label_1d3ee8;
        case 0x1d3ef8u: goto label_1d3ef8;
        case 0x1d3f08u: goto label_1d3f08;
        case 0x1d3f24u: goto label_1d3f24;
        case 0x1d3f30u: goto label_1d3f30;
        case 0x1d3f40u: goto label_1d3f40;
        case 0x1d3f50u: goto label_1d3f50;
        default: break;
    }

    ctx->pc = 0x1d3e90u;

    // 0x1d3e90: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d3e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d3e94: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1d3e94u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1d3e98: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d3e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d3e9c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3e9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3ea0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3ea0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3ea4: 0x8c304424  lw          $s0, 0x4424($at)
    ctx->pc = 0x1d3ea4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17444)));
    // 0x1d3ea8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3ea8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3eac: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d3eacu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d3eb0: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1D3EB0u;
    {
        const bool branch_taken_0x1d3eb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D3EB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3EB0u;
            // 0x1d3eb4: 0x246343c0  addiu       $v1, $v1, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3eb0) {
            ctx->pc = 0x1D3F10u;
            goto label_1d3f10;
        }
    }
    ctx->pc = 0x1D3EB8u;
    // 0x1d3eb8: 0x9467001a  lhu         $a3, 0x1A($v1)
    ctx->pc = 0x1d3eb8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d3ebc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3ebcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3ec0: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d3ec0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d3ec4: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3ec4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3ec8: 0x24a566c0  addiu       $a1, $a1, 0x66C0
    ctx->pc = 0x1d3ec8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26304));
    // 0x1d3ecc: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3ECCu;
    SET_GPR_U32(ctx, 31, 0x1D3ED4u);
    ctx->pc = 0x1D3ED0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3ECCu;
            // 0x1d3ed0: 0x24c666d0  addiu       $a2, $a2, 0x66D0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3ED4u; }
        if (ctx->pc != 0x1D3ED4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3ED4u; }
        if (ctx->pc != 0x1D3ED4u) { return; }
    }
    ctx->pc = 0x1D3ED4u;
label_1d3ed4:
    // 0x1d3ed4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d3ed4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3ed8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3edc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d3edcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d3ee0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D3EE0u;
    SET_GPR_U32(ctx, 31, 0x1D3EE8u);
    ctx->pc = 0x1D3EE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3EE0u;
            // 0x1d3ee4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3EE8u; }
        if (ctx->pc != 0x1D3EE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3EE8u; }
        if (ctx->pc != 0x1D3EE8u) { return; }
    }
    ctx->pc = 0x1D3EE8u;
label_1d3ee8:
    // 0x1d3ee8: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D3EE8u;
    {
        const bool branch_taken_0x1d3ee8 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1d3ee8) {
            ctx->pc = 0x1D3F00u;
            goto label_1d3f00;
        }
    }
    ctx->pc = 0x1D3EF0u;
    // 0x1d3ef0: 0xc1a3098  jal         func_68C260
    ctx->pc = 0x1D3EF0u;
    SET_GPR_U32(ctx, 31, 0x1D3EF8u);
    ctx->pc = 0x68C260u;
    {
        auto targetFn = runtime->lookupFunction(0x68C260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3EF8u; }
        if (ctx->pc != 0x1D3EF8u) { return; }
    }
    ctx->pc = 0x1D3EF8u;
label_1d3ef8:
    // 0x1d3ef8: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1D3EF8u;
    {
        const bool branch_taken_0x1d3ef8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3EF8u;
            // 0x1d3efc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3ef8) {
            ctx->pc = 0x1D3F54u;
            goto label_1d3f54;
        }
    }
    ctx->pc = 0x1D3F00u;
label_1d3f00:
    // 0x1d3f00: 0xc1a3068  jal         func_68C1A0
    ctx->pc = 0x1D3F00u;
    SET_GPR_U32(ctx, 31, 0x1D3F08u);
    ctx->pc = 0x68C1A0u;
    {
        auto targetFn = runtime->lookupFunction(0x68C1A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F08u; }
        if (ctx->pc != 0x1D3F08u) { return; }
    }
    ctx->pc = 0x1D3F08u;
label_1d3f08:
    // 0x1d3f08: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1D3F08u;
    {
        const bool branch_taken_0x1d3f08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3f08) {
            ctx->pc = 0x1D3F50u;
            goto label_1d3f50;
        }
    }
    ctx->pc = 0x1D3F10u;
label_1d3f10:
    // 0x1d3f10: 0x9466001a  lhu         $a2, 0x1A($v1)
    ctx->pc = 0x1d3f10u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d3f14: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3f14u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3f18: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3f18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3f1c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3F1Cu;
    SET_GPR_U32(ctx, 31, 0x1D3F24u);
    ctx->pc = 0x1D3F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3F1Cu;
            // 0x1d3f20: 0x24a566e8  addiu       $a1, $a1, 0x66E8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F24u; }
        if (ctx->pc != 0x1D3F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F24u; }
        if (ctx->pc != 0x1D3F24u) { return; }
    }
    ctx->pc = 0x1D3F24u;
label_1d3f24:
    // 0x1d3f24: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d3f24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3f28: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D3F28u;
    SET_GPR_U32(ctx, 31, 0x1D3F30u);
    ctx->pc = 0x1D3F2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3F28u;
            // 0x1d3f2c: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F30u; }
        if (ctx->pc != 0x1D3F30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F30u; }
        if (ctx->pc != 0x1D3F30u) { return; }
    }
    ctx->pc = 0x1D3F30u;
label_1d3f30:
    // 0x1d3f30: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D3F30u;
    {
        const bool branch_taken_0x1d3f30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3f30) {
            ctx->pc = 0x1D3F48u;
            goto label_1d3f48;
        }
    }
    ctx->pc = 0x1D3F38u;
    // 0x1d3f38: 0xc1a3098  jal         func_68C260
    ctx->pc = 0x1D3F38u;
    SET_GPR_U32(ctx, 31, 0x1D3F40u);
    ctx->pc = 0x68C260u;
    {
        auto targetFn = runtime->lookupFunction(0x68C260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F40u; }
        if (ctx->pc != 0x1D3F40u) { return; }
    }
    ctx->pc = 0x1D3F40u;
label_1d3f40:
    // 0x1d3f40: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D3F40u;
    {
        const bool branch_taken_0x1d3f40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3f40) {
            ctx->pc = 0x1D3F50u;
            goto label_1d3f50;
        }
    }
    ctx->pc = 0x1D3F48u;
label_1d3f48:
    // 0x1d3f48: 0xc1a3068  jal         func_68C1A0
    ctx->pc = 0x1D3F48u;
    SET_GPR_U32(ctx, 31, 0x1D3F50u);
    ctx->pc = 0x68C1A0u;
    {
        auto targetFn = runtime->lookupFunction(0x68C1A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F50u; }
        if (ctx->pc != 0x1D3F50u) { return; }
    }
    ctx->pc = 0x1D3F50u;
label_1d3f50:
    // 0x1d3f50: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d3f50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1d3f54:
    // 0x1d3f54: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3f54u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3f58: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3F58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3F58u;
            // 0x1d3f5c: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3ED4u: goto label_1d3ed4;
            case 0x1D3EE8u: goto label_1d3ee8;
            case 0x1D3EF8u: goto label_1d3ef8;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F08u: goto label_1d3f08;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F24u: goto label_1d3f24;
            case 0x1D3F30u: goto label_1d3f30;
            case 0x1D3F40u: goto label_1d3f40;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3F60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
