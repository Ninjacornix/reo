#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172E78
// Address: 0x172e78 - 0x172f58
void sub_00172E78_0x172e78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172E78_0x172e78");
#endif

    switch (ctx->pc) {
        case 0x172e90u: goto label_172e90;
        case 0x172ea4u: goto label_172ea4;
        case 0x172eb8u: goto label_172eb8;
        case 0x172eccu: goto label_172ecc;
        case 0x172ee0u: goto label_172ee0;
        case 0x172f00u: goto label_172f00;
        case 0x172f18u: goto label_172f18;
        case 0x172f2cu: goto label_172f2c;
        case 0x172f40u: goto label_172f40;
        default: break;
    }

    ctx->pc = 0x172e78u;

    // 0x172e78: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x172e78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x172e7c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x172e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x172e80: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x172e80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x172e84: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x172e84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x172e88: 0xc05cbd6  jal         func_172F58
    ctx->pc = 0x172E88u;
    SET_GPR_U32(ctx, 31, 0x172E90u);
    ctx->pc = 0x172E8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172E88u;
            // 0x172e8c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172F58u;
    if (runtime->hasFunction(0x172F58u)) {
        auto targetFn = runtime->lookupFunction(0x172F58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E90u; }
        if (ctx->pc != 0x172E90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172F58_0x172f58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172E90u; }
        if (ctx->pc != 0x172E90u) { return; }
    }
    ctx->pc = 0x172E90u;
label_172e90:
    // 0x172e90: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172e90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172e94: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x172E94u;
    {
        const bool branch_taken_0x172e94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172E94u;
            // 0x172e98: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172e94) {
            ctx->pc = 0x172EE8u;
            goto label_172ee8;
        }
    }
    ctx->pc = 0x172E9Cu;
    // 0x172e9c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172E9Cu;
    SET_GPR_U32(ctx, 31, 0x172EA4u);
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172EA4u; }
        if (ctx->pc != 0x172EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172EA4u; }
        if (ctx->pc != 0x172EA4u) { return; }
    }
    ctx->pc = 0x172EA4u;
label_172ea4:
    // 0x172ea4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x172ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172ea8: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x172EA8u;
    {
        const bool branch_taken_0x172ea8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x172EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172EA8u;
            // 0x172eac: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172ea8) {
            ctx->pc = 0x172EC0u;
            goto label_172ec0;
        }
    }
    ctx->pc = 0x172EB0u;
    // 0x172eb0: 0xc05cbfe  jal         func_172FF8
    ctx->pc = 0x172EB0u;
    SET_GPR_U32(ctx, 31, 0x172EB8u);
    ctx->pc = 0x172FF8u;
    if (runtime->hasFunction(0x172FF8u)) {
        auto targetFn = runtime->lookupFunction(0x172FF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172EB8u; }
        if (ctx->pc != 0x172EB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172FF8_0x172ff8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172EB8u; }
        if (ctx->pc != 0x172EB8u) { return; }
    }
    ctx->pc = 0x172EB8u;
label_172eb8:
    // 0x172eb8: 0x14400022  bnez        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x172EB8u;
    {
        const bool branch_taken_0x172eb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x172EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172EB8u;
            // 0x172ebc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172eb8) {
            ctx->pc = 0x172F44u;
            goto label_172f44;
        }
    }
    ctx->pc = 0x172EC0u;
label_172ec0:
    // 0x172ec0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172ec0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172ec4: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172EC4u;
    SET_GPR_U32(ctx, 31, 0x172ECCu);
    ctx->pc = 0x172EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172EC4u;
            // 0x172ec8: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172ECCu; }
        if (ctx->pc != 0x172ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172ECCu; }
        if (ctx->pc != 0x172ECCu) { return; }
    }
    ctx->pc = 0x172ECCu;
label_172ecc:
    // 0x172ecc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x172eccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x172ed0: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x172ED0u;
    {
        const bool branch_taken_0x172ed0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x172ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172ED0u;
            // 0x172ed4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172ed0) {
            ctx->pc = 0x172EF0u;
            goto label_172ef0;
        }
    }
    ctx->pc = 0x172ED8u;
    // 0x172ed8: 0xc05cc2c  jal         func_1730B0
    ctx->pc = 0x172ED8u;
    SET_GPR_U32(ctx, 31, 0x172EE0u);
    ctx->pc = 0x1730B0u;
    if (runtime->hasFunction(0x1730B0u)) {
        auto targetFn = runtime->lookupFunction(0x1730B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172EE0u; }
        if (ctx->pc != 0x172EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001730B0_0x1730b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172EE0u; }
        if (ctx->pc != 0x172EE0u) { return; }
    }
    ctx->pc = 0x172EE0u;
label_172ee0:
    // 0x172ee0: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x172EE0u;
    {
        const bool branch_taken_0x172ee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x172ee0) {
            ctx->pc = 0x172EE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x172EE0u;
            // 0x172ee4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x172EF4u;
            goto label_172ef4;
        }
    }
    ctx->pc = 0x172EE8u;
label_172ee8:
    // 0x172ee8: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x172EE8u;
    {
        const bool branch_taken_0x172ee8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172EE8u;
            // 0x172eec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172ee8) {
            ctx->pc = 0x172F44u;
            goto label_172f44;
        }
    }
    ctx->pc = 0x172EF0u;
label_172ef0:
    // 0x172ef0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x172ef0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_172ef4:
    // 0x172ef4: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x172ef4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x172ef8: 0xc05d8d4  jal         func_176350
    ctx->pc = 0x172EF8u;
    SET_GPR_U32(ctx, 31, 0x172F00u);
    ctx->pc = 0x172EFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172EF8u;
            // 0x172efc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176350u;
    if (runtime->hasFunction(0x176350u)) {
        auto targetFn = runtime->lookupFunction(0x176350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F00u; }
        if (ctx->pc != 0x172F00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176350_0x176350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F00u; }
        if (ctx->pc != 0x172F00u) { return; }
    }
    ctx->pc = 0x172F00u;
label_172f00:
    // 0x172f00: 0x26230cc0  addiu       $v1, $s1, 0xCC0
    ctx->pc = 0x172f00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 3264));
    // 0x172f04: 0x8c700244  lw          $s0, 0x244($v1)
    ctx->pc = 0x172f04u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 580)));
    // 0x172f08: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172f08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172f0c: 0x24050045  addiu       $a1, $zero, 0x45
    ctx->pc = 0x172f0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x172f10: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172F10u;
    SET_GPR_U32(ctx, 31, 0x172F18u);
    ctx->pc = 0x172F14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172F10u;
            // 0x172f14: 0x8c710240  lw          $s1, 0x240($v1) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 576)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F18u; }
        if (ctx->pc != 0x172F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F18u; }
        if (ctx->pc != 0x172F18u) { return; }
    }
    ctx->pc = 0x172F18u;
label_172f18:
    // 0x172f18: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x172f18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172f1c: 0x3c06000f  lui         $a2, 0xF
    ctx->pc = 0x172f1cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)15 << 16));
    // 0x172f20: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x172f20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172f24: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x172F24u;
    SET_GPR_U32(ctx, 31, 0x172F2Cu);
    ctx->pc = 0x172F28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172F24u;
            // 0x172f28: 0x34c64240  ori         $a2, $a2, 0x4240 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)16960);
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F2Cu; }
        if (ctx->pc != 0x172F2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F2Cu; }
        if (ctx->pc != 0x172F2Cu) { return; }
    }
    ctx->pc = 0x172F2Cu;
label_172f2c:
    // 0x172f2c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x172f2cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172f30: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x172f30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172f34: 0x2223023  subu        $a2, $s1, $v0
    ctx->pc = 0x172f34u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x172f38: 0xc05d9de  jal         func_176778
    ctx->pc = 0x172F38u;
    SET_GPR_U32(ctx, 31, 0x172F40u);
    ctx->pc = 0x172F3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172F38u;
            // 0x172f3c: 0x8fa50004  lw          $a1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176778u;
    if (runtime->hasFunction(0x176778u)) {
        auto targetFn = runtime->lookupFunction(0x176778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F40u; }
        if (ctx->pc != 0x172F40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176778_0x176778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172F40u; }
        if (ctx->pc != 0x172F40u) { return; }
    }
    ctx->pc = 0x172F40u;
label_172f40:
    // 0x172f40: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x172f40u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_172f44:
    // 0x172f44: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x172f44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172f48: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x172f48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x172f4c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x172f4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x172f50: 0x3e00008  jr          $ra
    ctx->pc = 0x172F50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172F50u;
            // 0x172f54: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172E90u: goto label_172e90;
            case 0x172EA4u: goto label_172ea4;
            case 0x172EB8u: goto label_172eb8;
            case 0x172EC0u: goto label_172ec0;
            case 0x172ECCu: goto label_172ecc;
            case 0x172EE0u: goto label_172ee0;
            case 0x172EE8u: goto label_172ee8;
            case 0x172EF0u: goto label_172ef0;
            case 0x172EF4u: goto label_172ef4;
            case 0x172F00u: goto label_172f00;
            case 0x172F18u: goto label_172f18;
            case 0x172F2Cu: goto label_172f2c;
            case 0x172F40u: goto label_172f40;
            case 0x172F44u: goto label_172f44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172F58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
