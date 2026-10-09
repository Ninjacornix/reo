#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AAE80
// Address: 0x1aae80 - 0x1aafb0
void sub_001AAE80_0x1aae80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AAE80_0x1aae80");
#endif

    switch (ctx->pc) {
        case 0x1aaee8u: goto label_1aaee8;
        case 0x1aaef4u: goto label_1aaef4;
        case 0x1aaf08u: goto label_1aaf08;
        case 0x1aaf10u: goto label_1aaf10;
        case 0x1aaf50u: goto label_1aaf50;
        case 0x1aaf58u: goto label_1aaf58;
        case 0x1aaf80u: goto label_1aaf80;
        default: break;
    }

    ctx->pc = 0x1aae80u;

    // 0x1aae80: 0x27bdfe50  addiu       $sp, $sp, -0x1B0
    ctx->pc = 0x1aae80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966864));
    // 0x1aae84: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1aae84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1aae88: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1aae88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1aae8c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1aae8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1aae90: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1aae90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1aae94: 0x100b02d  daddu       $s6, $t0, $zero
    ctx->pc = 0x1aae94u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aae98: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1aae98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1aae9c: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1aae9cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaea0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1aaea0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1aaea4: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1aaea4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaea8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1aaea8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1aaeac: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1aaeacu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaeb0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aaeb0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aaeb4: 0x120902d  daddu       $s2, $t1, $zero
    ctx->pc = 0x1aaeb4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaeb8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aaeb8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aaebc: 0x12630030  beq         $s3, $v1, . + 4 + (0x30 << 2)
    ctx->pc = 0x1AAEBCu;
    {
        const bool branch_taken_0x1aaebc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AAEC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAEBCu;
            // 0x1aaec0: 0x140882d  daddu       $s1, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aaebc) {
            ctx->pc = 0x1AAF80u;
            goto label_1aaf80;
        }
    }
    ctx->pc = 0x1AAEC4u;
    // 0x1aaec4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aaec4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aaec8: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1aaec8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaecc: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1aaeccu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1aaed0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1aaed0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1aaed4: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1aaed4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1aaed8: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1aaed8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1aaedc: 0x24a5d0b8  addiu       $a1, $a1, -0x2F48
    ctx->pc = 0x1aaedcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955192));
    // 0x1aaee0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AAEE0u;
    SET_GPR_U32(ctx, 31, 0x1AAEE8u);
    ctx->pc = 0x1AAEE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAEE0u;
            // 0x1aaee4: 0x24c6d040  addiu       $a2, $a2, -0x2FC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294955072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAEE8u; }
        if (ctx->pc != 0x1AAEE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAEE8u; }
        if (ctx->pc != 0x1AAEE8u) { return; }
    }
    ctx->pc = 0x1AAEE8u;
label_1aaee8:
    // 0x1aaee8: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1aaee8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1aaeec: 0xc06a920  jal         func_1AA480
    ctx->pc = 0x1AAEECu;
    SET_GPR_U32(ctx, 31, 0x1AAEF4u);
    ctx->pc = 0x1AAEF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAEECu;
            // 0x1aaef0: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA480u;
    if (runtime->hasFunction(0x1AA480u)) {
        auto targetFn = runtime->lookupFunction(0x1AA480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAEF4u; }
        if (ctx->pc != 0x1AAEF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA480_0x1aa480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAEF4u; }
        if (ctx->pc != 0x1AAEF4u) { return; }
    }
    ctx->pc = 0x1AAEF4u;
label_1aaef4:
    // 0x1aaef4: 0x18400022  blez        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1AAEF4u;
    {
        const bool branch_taken_0x1aaef4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1AAEF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAEF4u;
            // 0x1aaef8: 0x27a40180  addiu       $a0, $sp, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aaef4) {
            ctx->pc = 0x1AAF80u;
            goto label_1aaf80;
        }
    }
    ctx->pc = 0x1AAEFCu;
    // 0x1aaefc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1aaefcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaf00: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1AAF00u;
    SET_GPR_U32(ctx, 31, 0x1AAF08u);
    ctx->pc = 0x1AAF04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAF00u;
            // 0x1aaf04: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF08u; }
        if (ctx->pc != 0x1AAF08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF08u; }
        if (ctx->pc != 0x1AAF08u) { return; }
    }
    ctx->pc = 0x1AAF08u;
label_1aaf08:
    // 0x1aaf08: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1AAF08u;
    SET_GPR_U32(ctx, 31, 0x1AAF10u);
    ctx->pc = 0x1AAF0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAF08u;
            // 0x1aaf0c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF10u; }
        if (ctx->pc != 0x1AAF10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF10u; }
        if (ctx->pc != 0x1AAF10u) { return; }
    }
    ctx->pc = 0x1AAF10u;
label_1aaf10:
    // 0x1aaf10: 0x3243007f  andi        $v1, $s2, 0x7F
    ctx->pc = 0x1aaf10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)127);
    // 0x1aaf14: 0x28610002  slti        $at, $v1, 0x2
    ctx->pc = 0x1aaf14u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1aaf18: 0x10200005  beqz        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AAF18u;
    {
        const bool branch_taken_0x1aaf18 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aaf18) {
            ctx->pc = 0x1AAF30u;
            goto label_1aaf30;
        }
    }
    ctx->pc = 0x1AAF20u;
    // 0x1aaf20: 0x1620000d  bnez        $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x1AAF20u;
    {
        const bool branch_taken_0x1aaf20 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aaf20) {
            ctx->pc = 0x1AAF58u;
            goto label_1aaf58;
        }
    }
    ctx->pc = 0x1AAF28u;
    // 0x1aaf28: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1AAF28u;
    {
        const bool branch_taken_0x1aaf28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AAF2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAF28u;
            // 0x1aaf2c: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aaf28) {
            ctx->pc = 0x1AAF84u;
            goto label_1aaf84;
        }
    }
    ctx->pc = 0x1AAF30u;
label_1aaf30:
    // 0x1aaf30: 0x8fa30194  lw          $v1, 0x194($sp)
    ctx->pc = 0x1aaf30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 404)));
    // 0x1aaf34: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AAF34u;
    {
        const bool branch_taken_0x1aaf34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AAF38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAF34u;
            // 0x1aaf38: 0x2033021  addu        $a2, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aaf34) {
            ctx->pc = 0x1AAF80u;
            goto label_1aaf80;
        }
    }
    ctx->pc = 0x1AAF3Cu;
    // 0x1aaf3c: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x1aaf3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaf40: 0x280402d  daddu       $t0, $s4, $zero
    ctx->pc = 0x1aaf40u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaf44: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1aaf44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaf48: 0xc073d58  jal         func_1CF560
    ctx->pc = 0x1AAF48u;
    SET_GPR_U32(ctx, 31, 0x1AAF50u);
    ctx->pc = 0x1AAF4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAF48u;
            // 0x1aaf4c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF560u;
    if (runtime->hasFunction(0x1CF560u)) {
        auto targetFn = runtime->lookupFunction(0x1CF560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF50u; }
        if (ctx->pc != 0x1AAF50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF560_0x1cf560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF50u; }
        if (ctx->pc != 0x1AAF50u) { return; }
    }
    ctx->pc = 0x1AAF50u;
label_1aaf50:
    // 0x1aaf50: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1AAF50u;
    SET_GPR_U32(ctx, 31, 0x1AAF58u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF58u; }
        if (ctx->pc != 0x1AAF58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF58u; }
        if (ctx->pc != 0x1AAF58u) { return; }
    }
    ctx->pc = 0x1AAF58u;
label_1aaf58:
    // 0x1aaf58: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AAF58u;
    {
        const bool branch_taken_0x1aaf58 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AAF5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAF58u;
            // 0x1aaf5c: 0x32430080  andi        $v1, $s2, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aaf58) {
            ctx->pc = 0x1AAF80u;
            goto label_1aaf80;
        }
    }
    ctx->pc = 0x1AAF60u;
    // 0x1aaf60: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AAF60u;
    {
        const bool branch_taken_0x1aaf60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1aaf60) {
            ctx->pc = 0x1AAF80u;
            goto label_1aaf80;
        }
    }
    ctx->pc = 0x1AAF68u;
    // 0x1aaf68: 0x8fa301a4  lw          $v1, 0x1A4($sp)
    ctx->pc = 0x1aaf68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 420)));
    // 0x1aaf6c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AAF6Cu;
    {
        const bool branch_taken_0x1aaf6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AAF70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAF6Cu;
            // 0x1aaf70: 0x2033021  addu        $a2, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aaf6c) {
            ctx->pc = 0x1AAF80u;
            goto label_1aaf80;
        }
    }
    ctx->pc = 0x1AAF74u;
    // 0x1aaf74: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1aaf74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aaf78: 0xc0737f8  jal         func_1CDFE0
    ctx->pc = 0x1AAF78u;
    SET_GPR_U32(ctx, 31, 0x1AAF80u);
    ctx->pc = 0x1AAF7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAF78u;
            // 0x1aaf7c: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDFE0u;
    if (runtime->hasFunction(0x1CDFE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CDFE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF80u; }
        if (ctx->pc != 0x1AAF80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDFE0_0x1cdfe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AAF80u; }
        if (ctx->pc != 0x1AAF80u) { return; }
    }
    ctx->pc = 0x1AAF80u;
label_1aaf80:
    // 0x1aaf80: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1aaf80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_1aaf84:
    // 0x1aaf84: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1aaf84u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1aaf88: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1aaf88u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1aaf8c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1aaf8cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1aaf90: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1aaf90u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1aaf94: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1aaf94u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aaf98: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aaf98u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aaf9c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aaf9cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aafa0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AAFA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AAFA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AAFA0u;
            // 0x1aafa4: 0x27bd01b0  addiu       $sp, $sp, 0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 432));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AAEE8u: goto label_1aaee8;
            case 0x1AAEF4u: goto label_1aaef4;
            case 0x1AAF08u: goto label_1aaf08;
            case 0x1AAF10u: goto label_1aaf10;
            case 0x1AAF30u: goto label_1aaf30;
            case 0x1AAF50u: goto label_1aaf50;
            case 0x1AAF58u: goto label_1aaf58;
            case 0x1AAF80u: goto label_1aaf80;
            case 0x1AAF84u: goto label_1aaf84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AAFA8u;
    // 0x1aafa8: 0x0  nop
    ctx->pc = 0x1aafa8u;
    // NOP
    // 0x1aafac: 0x0  nop
    ctx->pc = 0x1aafacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
