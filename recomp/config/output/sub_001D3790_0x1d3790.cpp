#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3790
// Address: 0x1d3790 - 0x1d3b90
void sub_001D3790_0x1d3790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3790_0x1d3790");
#endif

    switch (ctx->pc) {
        case 0x1d37d4u: goto label_1d37d4;
        case 0x1d37e8u: goto label_1d37e8;
        case 0x1d380cu: goto label_1d380c;
        case 0x1d3818u: goto label_1d3818;
        case 0x1d3868u: goto label_1d3868;
        case 0x1d3870u: goto label_1d3870;
        case 0x1d387cu: goto label_1d387c;
        case 0x1d38e8u: goto label_1d38e8;
        case 0x1d3970u: goto label_1d3970;
        case 0x1d39d8u: goto label_1d39d8;
        case 0x1d39f4u: goto label_1d39f4;
        case 0x1d3a10u: goto label_1d3a10;
        case 0x1d3a3cu: goto label_1d3a3c;
        case 0x1d3a9cu: goto label_1d3a9c;
        case 0x1d3abcu: goto label_1d3abc;
        case 0x1d3ad0u: goto label_1d3ad0;
        case 0x1d3ae0u: goto label_1d3ae0;
        case 0x1d3b2cu: goto label_1d3b2c;
        case 0x1d3b4cu: goto label_1d3b4c;
        case 0x1d3b60u: goto label_1d3b60;
        case 0x1d3b70u: goto label_1d3b70;
        default: break;
    }

    ctx->pc = 0x1d3790u;

label_1d3790:
    // 0x1d3790: 0x27bdfee0  addiu       $sp, $sp, -0x120
    ctx->pc = 0x1d3790u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967008));
    // 0x1d3794: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3794u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3798: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d3798u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d379c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d379cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d37a0: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d37a0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d37a4: 0x3c100032  lui         $s0, 0x32
    ctx->pc = 0x1d37a4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)50 << 16));
    // 0x1d37a8: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1D37A8u;
    {
        const bool branch_taken_0x1d37a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D37ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D37A8u;
            // 0x1d37ac: 0x261043c0  addiu       $s0, $s0, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 17344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d37a8) {
            ctx->pc = 0x1D37F0u;
            goto label_1d37f0;
        }
    }
    ctx->pc = 0x1D37B0u;
    // 0x1d37b0: 0x9607001a  lhu         $a3, 0x1A($s0)
    ctx->pc = 0x1d37b0u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 26)));
    // 0x1d37b4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d37b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d37b8: 0x9608001c  lhu         $t0, 0x1C($s0)
    ctx->pc = 0x1d37b8u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1d37bc: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d37bcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d37c0: 0x9609001e  lhu         $t1, 0x1E($s0)
    ctx->pc = 0x1d37c0u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 30)));
    // 0x1d37c4: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d37c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d37c8: 0x24a56600  addiu       $a1, $a1, 0x6600
    ctx->pc = 0x1d37c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26112));
    // 0x1d37cc: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D37CCu;
    SET_GPR_U32(ctx, 31, 0x1D37D4u);
    ctx->pc = 0x1D37D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D37CCu;
            // 0x1d37d0: 0x24c66618  addiu       $a2, $a2, 0x6618 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D37D4u; }
        if (ctx->pc != 0x1D37D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D37D4u; }
        if (ctx->pc != 0x1D37D4u) { return; }
    }
    ctx->pc = 0x1D37D4u;
label_1d37d4:
    // 0x1d37d4: 0x8e050060  lw          $a1, 0x60($s0)
    ctx->pc = 0x1d37d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1d37d8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d37d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d37dc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d37dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d37e0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D37E0u;
    SET_GPR_U32(ctx, 31, 0x1D37E8u);
    ctx->pc = 0x1D37E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D37E0u;
            // 0x1d37e4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D37E8u; }
        if (ctx->pc != 0x1D37E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D37E8u; }
        if (ctx->pc != 0x1D37E8u) { return; }
    }
    ctx->pc = 0x1D37E8u;
label_1d37e8:
    // 0x1d37e8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D37E8u;
    {
        const bool branch_taken_0x1d37e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D37ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D37E8u;
            // 0x1d37ec: 0xae02005c  sw          $v0, 0x5C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d37e8) {
            ctx->pc = 0x1D381Cu;
            goto label_1d381c;
        }
    }
    ctx->pc = 0x1D37F0u;
label_1d37f0:
    // 0x1d37f0: 0x9606001a  lhu         $a2, 0x1A($s0)
    ctx->pc = 0x1d37f0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 26)));
    // 0x1d37f4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d37f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d37f8: 0x9607001c  lhu         $a3, 0x1C($s0)
    ctx->pc = 0x1d37f8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1d37fc: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d37fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3800: 0x9608001e  lhu         $t0, 0x1E($s0)
    ctx->pc = 0x1d3800u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 30)));
    // 0x1d3804: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3804u;
    SET_GPR_U32(ctx, 31, 0x1D380Cu);
    ctx->pc = 0x1D3808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3804u;
            // 0x1d3808: 0x24a56630  addiu       $a1, $a1, 0x6630 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D380Cu; }
        if (ctx->pc != 0x1D380Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D380Cu; }
        if (ctx->pc != 0x1D380Cu) { return; }
    }
    ctx->pc = 0x1D380Cu;
label_1d380c:
    // 0x1d380c: 0x8e050060  lw          $a1, 0x60($s0)
    ctx->pc = 0x1d380cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1d3810: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D3810u;
    SET_GPR_U32(ctx, 31, 0x1D3818u);
    ctx->pc = 0x1D3814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3810u;
            // 0x1d3814: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3818u; }
        if (ctx->pc != 0x1D3818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3818u; }
        if (ctx->pc != 0x1D3818u) { return; }
    }
    ctx->pc = 0x1D3818u;
label_1d3818:
    // 0x1d3818: 0xae02005c  sw          $v0, 0x5C($s0)
    ctx->pc = 0x1d3818u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 2));
label_1d381c:
    // 0x1d381c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d381cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3820: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3820u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3824: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3824u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3824u;
            // 0x1d3828: 0x27bd0120  addiu       $sp, $sp, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 288));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3790u: goto label_1d3790;
            case 0x1D37D4u: goto label_1d37d4;
            case 0x1D37E8u: goto label_1d37e8;
            case 0x1D37F0u: goto label_1d37f0;
            case 0x1D380Cu: goto label_1d380c;
            case 0x1D3818u: goto label_1d3818;
            case 0x1D381Cu: goto label_1d381c;
            case 0x1D3868u: goto label_1d3868;
            case 0x1D3870u: goto label_1d3870;
            case 0x1D387Cu: goto label_1d387c;
            case 0x1D38E8u: goto label_1d38e8;
            case 0x1D3954u: goto label_1d3954;
            case 0x1D3970u: goto label_1d3970;
            case 0x1D3988u: goto label_1d3988;
            case 0x1D398Cu: goto label_1d398c;
            case 0x1D3994u: goto label_1d3994;
            case 0x1D39D0u: goto label_1d39d0;
            case 0x1D39D8u: goto label_1d39d8;
            case 0x1D39E0u: goto label_1d39e0;
            case 0x1D39F4u: goto label_1d39f4;
            case 0x1D39FCu: goto label_1d39fc;
            case 0x1D3A10u: goto label_1d3a10;
            case 0x1D3A18u: goto label_1d3a18;
            case 0x1D3A3Cu: goto label_1d3a3c;
            case 0x1D3A40u: goto label_1d3a40;
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D382Cu;
    // 0x1d382c: 0x0  nop
    ctx->pc = 0x1d382cu;
    // NOP
    // 0x1d3830: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1d3830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1d3834: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3834u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3838: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d3838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d383c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d383cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3840: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d3840u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d3844: 0x3c060030  lui         $a2, 0x30
    ctx->pc = 0x1d3844u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)48 << 16));
    // 0x1d3848: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d3848u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d384c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d384cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d3850: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3850u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3854: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3854u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3858: 0x8c244420  lw          $a0, 0x4420($at)
    ctx->pc = 0x1d3858u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17440)));
    // 0x1d385c: 0x3c100032  lui         $s0, 0x32
    ctx->pc = 0x1d385cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)50 << 16));
    // 0x1d3860: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D3860u;
    SET_GPR_U32(ctx, 31, 0x1D3868u);
    ctx->pc = 0x1D3864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3860u;
            // 0x1d3864: 0x261043c0  addiu       $s0, $s0, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 17344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3868u; }
        if (ctx->pc != 0x1D3868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3868u; }
        if (ctx->pc != 0x1D3868u) { return; }
    }
    ctx->pc = 0x1D3868u;
label_1d3868:
    // 0x1d3868: 0xc074de4  jal         func_1D3790
    ctx->pc = 0x1D3868u;
    SET_GPR_U32(ctx, 31, 0x1D3870u);
    ctx->pc = 0x1D3790u;
    goto label_1d3790;
    ctx->pc = 0x1D3870u;
label_1d3870:
    // 0x1d3870: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3870u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3874: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1d3874u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3878: 0x8c274420  lw          $a3, 0x4420($at)
    ctx->pc = 0x1d3878u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17440)));
label_1d387c:
    // 0x1d387c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d387cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3880: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d3880u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1d3884: 0x8c254420  lw          $a1, 0x4420($at)
    ctx->pc = 0x1d3884u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17440)));
    // 0x1d3888: 0x2cc30020  sltiu       $v1, $a2, 0x20
    ctx->pc = 0x1d3888u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x1d388c: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x1d388cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1d3890: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1d3890u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1d3894: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x1d3894u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x1d3898: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1D3898u;
    {
        const bool branch_taken_0x1d3898 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D389Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3898u;
            // 0x1d389c: 0x24e70008  addiu       $a3, $a3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3898) {
            ctx->pc = 0x1D387Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d387c;
        }
    }
    ctx->pc = 0x1D38A0u;
    // 0x1d38a0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d38a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d38a4: 0x8e140060  lw          $s4, 0x60($s0)
    ctx->pc = 0x1d38a4u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1d38a8: 0x8c254420  lw          $a1, 0x4420($at)
    ctx->pc = 0x1d38a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17440)));
    // 0x1d38ac: 0x3c040018  lui         $a0, 0x18
    ctx->pc = 0x1d38acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)24 << 16));
    // 0x1d38b0: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x1d38b0u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x1d38b4: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x1d38b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1d38b8: 0x27b10064  addiu       $s1, $sp, 0x64
    ctx->pc = 0x1d38b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 100));
    // 0x1d38bc: 0x26736800  addiu       $s3, $s3, 0x6800
    ctx->pc = 0x1d38bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 26624));
    // 0x1d38c0: 0x27b2006c  addiu       $s2, $sp, 0x6C
    ctx->pc = 0x1d38c0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 108));
    // 0x1d38c4: 0xafa00060  sw          $zero, 0x60($sp)
    ctx->pc = 0x1d38c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 0));
    // 0x1d38c8: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1d38c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1d38cc: 0xafa40068  sw          $a0, 0x68($sp)
    ctx->pc = 0x1d38ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 4));
    // 0x1d38d0: 0x8fa40068  lw          $a0, 0x68($sp)
    ctx->pc = 0x1d38d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1d38d4: 0x24840003  addiu       $a0, $a0, 0x3
    ctx->pc = 0x1d38d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3));
    // 0x1d38d8: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1d38d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1d38dc: 0xafa30068  sw          $v1, 0x68($sp)
    ctx->pc = 0x1d38dcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 3));
    // 0x1d38e0: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1D38E0u;
    {
        const bool branch_taken_0x1d38e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D38E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D38E0u;
            // 0x1d38e4: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d38e0) {
            ctx->pc = 0x1D3A40u;
            goto label_1d3a40;
        }
    }
    ctx->pc = 0x1D38E8u;
label_1d38e8:
    // 0x1d38e8: 0x8e650004  lw          $a1, 0x4($s3)
    ctx->pc = 0x1d38e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x1d38ec: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1d38ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1d38f0: 0x10a30028  beq         $a1, $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x1D38F0u;
    {
        const bool branch_taken_0x1d38f0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d38f0) {
            ctx->pc = 0x1D3994u;
            goto label_1d3994;
        }
    }
    ctx->pc = 0x1D38F8u;
    // 0x1d38f8: 0x8e640008  lw          $a0, 0x8($s3)
    ctx->pc = 0x1d38f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1d38fc: 0x10830025  beq         $a0, $v1, . + 4 + (0x25 << 2)
    ctx->pc = 0x1D38FCu;
    {
        const bool branch_taken_0x1d38fc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d38fc) {
            ctx->pc = 0x1D3994u;
            goto label_1d3994;
        }
    }
    ctx->pc = 0x1D3904u;
    // 0x1d3904: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x1d3904u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d3908: 0x2838021  addu        $s0, $s4, $v1
    ctx->pc = 0x1d3908u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1d390c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1d390cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d3910: 0x1060001e  beqz        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1D3910u;
    {
        const bool branch_taken_0x1d3910 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3910u;
            // 0x1d3914: 0x41880  sll         $v1, $a0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3910) {
            ctx->pc = 0x1D398Cu;
            goto label_1d398c;
        }
    }
    ctx->pc = 0x1D3918u;
    // 0x1d3918: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1d3918u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1d391c: 0x1060001a  beqz        $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1D391Cu;
    {
        const bool branch_taken_0x1d391c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d391c) {
            ctx->pc = 0x1D3988u;
            goto label_1d3988;
        }
    }
    ctx->pc = 0x1D3924u;
    // 0x1d3924: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d3924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d3928: 0x1482000a  bne         $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D3928u;
    {
        const bool branch_taken_0x1d3928 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d3928) {
            ctx->pc = 0x1D3954u;
            goto label_1d3954;
        }
    }
    ctx->pc = 0x1D3930u;
    // 0x1d3930: 0x8fa40068  lw          $a0, 0x68($sp)
    ctx->pc = 0x1d3930u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1d3934: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1d3934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1d3938: 0x8fa30060  lw          $v1, 0x60($sp)
    ctx->pc = 0x1d3938u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d393c: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1d393cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d3940: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x1d3940u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x1d3944: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1d3944u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1d3948: 0x24630003  addiu       $v1, $v1, 0x3
    ctx->pc = 0x1d3948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1d394c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1d394cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1d3950: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1d3950u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_1d3954:
    // 0x1d3954: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1d3954u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1d3958: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1d3958u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d395c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1d395cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d3960: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1d3960u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1d3964: 0x8c440068  lw          $a0, 0x68($v0)
    ctx->pc = 0x1d3964u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 104)));
    // 0x1d3968: 0xc0636ec  jal         func_18DBB0
    ctx->pc = 0x1D3968u;
    SET_GPR_U32(ctx, 31, 0x1D3970u);
    ctx->pc = 0x1D396Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3968u;
            // 0x1d396c: 0x8e060004  lw          $a2, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DBB0u;
    if (runtime->hasFunction(0x18DBB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3970u; }
        if (ctx->pc != 0x1D3970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3970u; }
        if (ctx->pc != 0x1D3970u) { return; }
    }
    ctx->pc = 0x1D3970u;
label_1d3970:
    // 0x1d3970: 0x8e630008  lw          $v1, 0x8($s3)
    ctx->pc = 0x1d3970u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1d3974: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x1d3974u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1d3978: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d3978u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d397c: 0x7d1821  addu        $v1, $v1, $sp
    ctx->pc = 0x1d397cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x1d3980: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D3980u;
    {
        const bool branch_taken_0x1d3980 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3980u;
            // 0x1d3984: 0xac640060  sw          $a0, 0x60($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 96), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3980) {
            ctx->pc = 0x1D3994u;
            goto label_1d3994;
        }
    }
    ctx->pc = 0x1D3988u;
label_1d3988:
    // 0x1d3988: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1d3988u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_1d398c:
    // 0x1d398c: 0x7d1821  addu        $v1, $v1, $sp
    ctx->pc = 0x1d398cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x1d3990: 0xac600060  sw          $zero, 0x60($v1)
    ctx->pc = 0x1d3990u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 96), GPR_U32(ctx, 0));
label_1d3994:
    // 0x1d3994: 0x8e660000  lw          $a2, 0x0($s3)
    ctx->pc = 0x1d3994u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d3998: 0x10c00028  beqz        $a2, . + 4 + (0x28 << 2)
    ctx->pc = 0x1D3998u;
    {
        const bool branch_taken_0x1d3998 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3998) {
            ctx->pc = 0x1D3A3Cu;
            goto label_1d3a3c;
        }
    }
    ctx->pc = 0x1D39A0u;
    // 0x1d39a0: 0x8e64000c  lw          $a0, 0xC($s3)
    ctx->pc = 0x1d39a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x1d39a4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1d39a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d39a8: 0x1083001b  beq         $a0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1D39A8u;
    {
        const bool branch_taken_0x1d39a8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D39ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D39A8u;
            // 0x1d39ac: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d39a8) {
            ctx->pc = 0x1D3A18u;
            goto label_1d3a18;
        }
    }
    ctx->pc = 0x1D39B0u;
    // 0x1d39b0: 0x10830012  beq         $a0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D39B0u;
    {
        const bool branch_taken_0x1d39b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d39b0) {
            ctx->pc = 0x1D39FCu;
            goto label_1d39fc;
        }
    }
    ctx->pc = 0x1D39B8u;
    // 0x1d39b8: 0x10800009  beqz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D39B8u;
    {
        const bool branch_taken_0x1d39b8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D39BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D39B8u;
            // 0x1d39bc: 0x24030063  addiu       $v1, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d39b8) {
            ctx->pc = 0x1D39E0u;
            goto label_1d39e0;
        }
    }
    ctx->pc = 0x1D39C0u;
    // 0x1d39c0: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D39C0u;
    {
        const bool branch_taken_0x1d39c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d39c0) {
            ctx->pc = 0x1D39D0u;
            goto label_1d39d0;
        }
    }
    ctx->pc = 0x1D39C8u;
    // 0x1d39c8: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1D39C8u;
    {
        const bool branch_taken_0x1d39c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D39CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D39C8u;
            // 0x1d39cc: 0x26730010  addiu       $s3, $s3, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d39c8) {
            ctx->pc = 0x1D3A40u;
            goto label_1d3a40;
        }
    }
    ctx->pc = 0x1D39D0u;
label_1d39d0:
    // 0x1d39d0: 0xc0f809  jalr        $a2
    ctx->pc = 0x1D39D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x1D39D8u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1D39D8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3790u: goto label_1d3790;
            case 0x1D37D4u: goto label_1d37d4;
            case 0x1D37E8u: goto label_1d37e8;
            case 0x1D37F0u: goto label_1d37f0;
            case 0x1D380Cu: goto label_1d380c;
            case 0x1D3818u: goto label_1d3818;
            case 0x1D381Cu: goto label_1d381c;
            case 0x1D3868u: goto label_1d3868;
            case 0x1D3870u: goto label_1d3870;
            case 0x1D387Cu: goto label_1d387c;
            case 0x1D38E8u: goto label_1d38e8;
            case 0x1D3954u: goto label_1d3954;
            case 0x1D3970u: goto label_1d3970;
            case 0x1D3988u: goto label_1d3988;
            case 0x1D398Cu: goto label_1d398c;
            case 0x1D3994u: goto label_1d3994;
            case 0x1D39D0u: goto label_1d39d0;
            case 0x1D39D8u: goto label_1d39d8;
            case 0x1D39E0u: goto label_1d39e0;
            case 0x1D39F4u: goto label_1d39f4;
            case 0x1D39FCu: goto label_1d39fc;
            case 0x1D3A10u: goto label_1d3a10;
            case 0x1D3A18u: goto label_1d3a18;
            case 0x1D3A3Cu: goto label_1d3a3c;
            case 0x1D3A40u: goto label_1d3a40;
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1D39D8u; }
            if (ctx->pc != 0x1D39D8u) { return; }
        }
        }
    }
    ctx->pc = 0x1D39D8u;
label_1d39d8:
    // 0x1d39d8: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D39D8u;
    {
        const bool branch_taken_0x1d39d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d39d8) {
            ctx->pc = 0x1D3A3Cu;
            goto label_1d3a3c;
        }
    }
    ctx->pc = 0x1D39E0u;
label_1d39e0:
    // 0x1d39e0: 0x8fa50060  lw          $a1, 0x60($sp)
    ctx->pc = 0x1d39e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d39e4: 0x10a00015  beqz        $a1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1D39E4u;
    {
        const bool branch_taken_0x1d39e4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d39e4) {
            ctx->pc = 0x1D3A3Cu;
            goto label_1d3a3c;
        }
    }
    ctx->pc = 0x1D39ECu;
    // 0x1d39ec: 0xc0f809  jalr        $a2
    ctx->pc = 0x1D39ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x1D39F4u);
        ctx->pc = 0x1D39F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D39ECu;
            // 0x1d39f0: 0x8fa40068  lw          $a0, 0x68($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1D39F4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3790u: goto label_1d3790;
            case 0x1D37D4u: goto label_1d37d4;
            case 0x1D37E8u: goto label_1d37e8;
            case 0x1D37F0u: goto label_1d37f0;
            case 0x1D380Cu: goto label_1d380c;
            case 0x1D3818u: goto label_1d3818;
            case 0x1D381Cu: goto label_1d381c;
            case 0x1D3868u: goto label_1d3868;
            case 0x1D3870u: goto label_1d3870;
            case 0x1D387Cu: goto label_1d387c;
            case 0x1D38E8u: goto label_1d38e8;
            case 0x1D3954u: goto label_1d3954;
            case 0x1D3970u: goto label_1d3970;
            case 0x1D3988u: goto label_1d3988;
            case 0x1D398Cu: goto label_1d398c;
            case 0x1D3994u: goto label_1d3994;
            case 0x1D39D0u: goto label_1d39d0;
            case 0x1D39D8u: goto label_1d39d8;
            case 0x1D39E0u: goto label_1d39e0;
            case 0x1D39F4u: goto label_1d39f4;
            case 0x1D39FCu: goto label_1d39fc;
            case 0x1D3A10u: goto label_1d3a10;
            case 0x1D3A18u: goto label_1d3a18;
            case 0x1D3A3Cu: goto label_1d3a3c;
            case 0x1D3A40u: goto label_1d3a40;
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1D39F4u; }
            if (ctx->pc != 0x1D39F4u) { return; }
        }
        }
    }
    ctx->pc = 0x1D39F4u;
label_1d39f4:
    // 0x1d39f4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1D39F4u;
    {
        const bool branch_taken_0x1d39f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d39f4) {
            ctx->pc = 0x1D3A3Cu;
            goto label_1d3a3c;
        }
    }
    ctx->pc = 0x1D39FCu;
label_1d39fc:
    // 0x1d39fc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1d39fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d3a00: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1D3A00u;
    {
        const bool branch_taken_0x1d3a00 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3a00) {
            ctx->pc = 0x1D3A3Cu;
            goto label_1d3a3c;
        }
    }
    ctx->pc = 0x1D3A08u;
    // 0x1d3a08: 0xc0f809  jalr        $a2
    ctx->pc = 0x1D3A08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x1D3A10u);
        ctx->pc = 0x1D3A0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3A08u;
            // 0x1d3a0c: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1D3A10u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3790u: goto label_1d3790;
            case 0x1D37D4u: goto label_1d37d4;
            case 0x1D37E8u: goto label_1d37e8;
            case 0x1D37F0u: goto label_1d37f0;
            case 0x1D380Cu: goto label_1d380c;
            case 0x1D3818u: goto label_1d3818;
            case 0x1D381Cu: goto label_1d381c;
            case 0x1D3868u: goto label_1d3868;
            case 0x1D3870u: goto label_1d3870;
            case 0x1D387Cu: goto label_1d387c;
            case 0x1D38E8u: goto label_1d38e8;
            case 0x1D3954u: goto label_1d3954;
            case 0x1D3970u: goto label_1d3970;
            case 0x1D3988u: goto label_1d3988;
            case 0x1D398Cu: goto label_1d398c;
            case 0x1D3994u: goto label_1d3994;
            case 0x1D39D0u: goto label_1d39d0;
            case 0x1D39D8u: goto label_1d39d8;
            case 0x1D39E0u: goto label_1d39e0;
            case 0x1D39F4u: goto label_1d39f4;
            case 0x1D39FCu: goto label_1d39fc;
            case 0x1D3A10u: goto label_1d3a10;
            case 0x1D3A18u: goto label_1d3a18;
            case 0x1D3A3Cu: goto label_1d3a3c;
            case 0x1D3A40u: goto label_1d3a40;
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1D3A10u; }
            if (ctx->pc != 0x1D3A10u) { return; }
        }
        }
    }
    ctx->pc = 0x1D3A10u;
label_1d3a10:
    // 0x1d3a10: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1D3A10u;
    {
        const bool branch_taken_0x1d3a10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3a10) {
            ctx->pc = 0x1D3A3Cu;
            goto label_1d3a3c;
        }
    }
    ctx->pc = 0x1D3A18u;
label_1d3a18:
    // 0x1d3a18: 0x8fa30060  lw          $v1, 0x60($sp)
    ctx->pc = 0x1d3a18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d3a1c: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D3A1Cu;
    {
        const bool branch_taken_0x1d3a1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3a1c) {
            ctx->pc = 0x1D3A3Cu;
            goto label_1d3a3c;
        }
    }
    ctx->pc = 0x1D3A24u;
    // 0x1d3a24: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1d3a24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d3a28: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D3A28u;
    {
        const bool branch_taken_0x1d3a28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d3a28) {
            ctx->pc = 0x1D3A3Cu;
            goto label_1d3a3c;
        }
    }
    ctx->pc = 0x1D3A30u;
    // 0x1d3a30: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x1d3a30u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1d3a34: 0xc0f809  jalr        $a2
    ctx->pc = 0x1D3A34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x1D3A3Cu);
        ctx->pc = 0x1D3A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3A34u;
            // 0x1d3a38: 0x8fa40068  lw          $a0, 0x68($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1D3A3Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3790u: goto label_1d3790;
            case 0x1D37D4u: goto label_1d37d4;
            case 0x1D37E8u: goto label_1d37e8;
            case 0x1D37F0u: goto label_1d37f0;
            case 0x1D380Cu: goto label_1d380c;
            case 0x1D3818u: goto label_1d3818;
            case 0x1D381Cu: goto label_1d381c;
            case 0x1D3868u: goto label_1d3868;
            case 0x1D3870u: goto label_1d3870;
            case 0x1D387Cu: goto label_1d387c;
            case 0x1D38E8u: goto label_1d38e8;
            case 0x1D3954u: goto label_1d3954;
            case 0x1D3970u: goto label_1d3970;
            case 0x1D3988u: goto label_1d3988;
            case 0x1D398Cu: goto label_1d398c;
            case 0x1D3994u: goto label_1d3994;
            case 0x1D39D0u: goto label_1d39d0;
            case 0x1D39D8u: goto label_1d39d8;
            case 0x1D39E0u: goto label_1d39e0;
            case 0x1D39F4u: goto label_1d39f4;
            case 0x1D39FCu: goto label_1d39fc;
            case 0x1D3A10u: goto label_1d3a10;
            case 0x1D3A18u: goto label_1d3a18;
            case 0x1D3A3Cu: goto label_1d3a3c;
            case 0x1D3A40u: goto label_1d3a40;
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1D3A3Cu; }
            if (ctx->pc != 0x1D3A3Cu) { return; }
        }
        }
    }
    ctx->pc = 0x1D3A3Cu;
label_1d3a3c:
    // 0x1d3a3c: 0x26730010  addiu       $s3, $s3, 0x10
    ctx->pc = 0x1d3a3cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
label_1d3a40:
    // 0x1d3a40: 0x8e64000c  lw          $a0, 0xC($s3)
    ctx->pc = 0x1d3a40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x1d3a44: 0x240303e7  addiu       $v1, $zero, 0x3E7
    ctx->pc = 0x1d3a44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 999));
    // 0x1d3a48: 0x1483ffa7  bne         $a0, $v1, . + 4 + (-0x59 << 2)
    ctx->pc = 0x1D3A48u;
    {
        const bool branch_taken_0x1d3a48 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1d3a48) {
            ctx->pc = 0x1D38E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d38e8;
        }
    }
    ctx->pc = 0x1D3A50u;
    // 0x1d3a50: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d3a50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d3a54: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d3a54u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d3a58: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d3a58u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d3a5c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d3a5cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3a60: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d3a60u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3a64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3a64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3a68: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3A68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3A68u;
            // 0x1d3a6c: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3790u: goto label_1d3790;
            case 0x1D37D4u: goto label_1d37d4;
            case 0x1D37E8u: goto label_1d37e8;
            case 0x1D37F0u: goto label_1d37f0;
            case 0x1D380Cu: goto label_1d380c;
            case 0x1D3818u: goto label_1d3818;
            case 0x1D381Cu: goto label_1d381c;
            case 0x1D3868u: goto label_1d3868;
            case 0x1D3870u: goto label_1d3870;
            case 0x1D387Cu: goto label_1d387c;
            case 0x1D38E8u: goto label_1d38e8;
            case 0x1D3954u: goto label_1d3954;
            case 0x1D3970u: goto label_1d3970;
            case 0x1D3988u: goto label_1d3988;
            case 0x1D398Cu: goto label_1d398c;
            case 0x1D3994u: goto label_1d3994;
            case 0x1D39D0u: goto label_1d39d0;
            case 0x1D39D8u: goto label_1d39d8;
            case 0x1D39E0u: goto label_1d39e0;
            case 0x1D39F4u: goto label_1d39f4;
            case 0x1D39FCu: goto label_1d39fc;
            case 0x1D3A10u: goto label_1d3a10;
            case 0x1D3A18u: goto label_1d3a18;
            case 0x1D3A3Cu: goto label_1d3a3c;
            case 0x1D3A40u: goto label_1d3a40;
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3A70u;
    // 0x1d3a70: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1d3a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1d3a74: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1d3a74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1d3a78: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d3a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d3a7c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3a7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3a80: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3a80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3a84: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d3a84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3a88: 0x90840c7c  lbu         $a0, 0xC7C($a0)
    ctx->pc = 0x1d3a88u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3196)));
    // 0x1d3a8c: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1D3A8Cu;
    {
        const bool branch_taken_0x1d3a8c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d3a8c) {
            ctx->pc = 0x1D3AE0u;
            goto label_1d3ae0;
        }
    }
    ctx->pc = 0x1D3A94u;
    // 0x1d3a94: 0xc16d338  jal         func_5B4CE0
    ctx->pc = 0x1D3A94u;
    SET_GPR_U32(ctx, 31, 0x1D3A9Cu);
    ctx->pc = 0x1D3A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3A94u;
            // 0x1d3a98: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x5B4CE0u;
    {
        auto targetFn = runtime->lookupFunction(0x5B4CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3A9Cu; }
        if (ctx->pc != 0x1D3A9Cu) { return; }
    }
    ctx->pc = 0x1D3A9Cu;
label_1d3a9c:
    // 0x1d3a9c: 0x2863c  dsll32      $s0, $v0, 24
    ctx->pc = 0x1d3a9cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1d3aa0: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d3aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d3aa4: 0x10863f  dsra32      $s0, $s0, 24
    ctx->pc = 0x1d3aa4u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 24));
    // 0x1d3aa8: 0x1203000d  beq         $s0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1D3AA8u;
    {
        const bool branch_taken_0x1d3aa8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d3aa8) {
            ctx->pc = 0x1D3AE0u;
            goto label_1d3ae0;
        }
    }
    ctx->pc = 0x1D3AB0u;
    // 0x1d3ab0: 0x92240003  lbu         $a0, 0x3($s1)
    ctx->pc = 0x1d3ab0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1d3ab4: 0xc1ad2b8  jal         func_6B4AE0
    ctx->pc = 0x1D3AB4u;
    SET_GPR_U32(ctx, 31, 0x1D3ABCu);
    ctx->pc = 0x1D3AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3AB4u;
            // 0x1d3ab8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B4AE0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B4AE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3ABCu; }
        if (ctx->pc != 0x1D3ABCu) { return; }
    }
    ctx->pc = 0x1D3ABCu;
label_1d3abc:
    // 0x1d3abc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3abcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3ac0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d3ac0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3ac4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3ac8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3AC8u;
    SET_GPR_U32(ctx, 31, 0x1D3AD0u);
    ctx->pc = 0x1D3ACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3AC8u;
            // 0x1d3acc: 0x24a56648  addiu       $a1, $a1, 0x6648 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3AD0u; }
        if (ctx->pc != 0x1D3AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3AD0u; }
        if (ctx->pc != 0x1D3AD0u) { return; }
    }
    ctx->pc = 0x1D3AD0u;
label_1d3ad0:
    // 0x1d3ad0: 0x92220003  lbu         $v0, 0x3($s1)
    ctx->pc = 0x1d3ad0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1d3ad4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3ad8: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D3AD8u;
    SET_GPR_U32(ctx, 31, 0x1D3AE0u);
    ctx->pc = 0x1D3ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3AD8u;
            // 0x1d3adc: 0x24450008  addiu       $a1, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3AE0u; }
        if (ctx->pc != 0x1D3AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3AE0u; }
        if (ctx->pc != 0x1D3AE0u) { return; }
    }
    ctx->pc = 0x1D3AE0u;
label_1d3ae0:
    // 0x1d3ae0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d3ae0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3ae4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d3ae4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3ae8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3ae8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3aec: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3AECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3AECu;
            // 0x1d3af0: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3790u: goto label_1d3790;
            case 0x1D37D4u: goto label_1d37d4;
            case 0x1D37E8u: goto label_1d37e8;
            case 0x1D37F0u: goto label_1d37f0;
            case 0x1D380Cu: goto label_1d380c;
            case 0x1D3818u: goto label_1d3818;
            case 0x1D381Cu: goto label_1d381c;
            case 0x1D3868u: goto label_1d3868;
            case 0x1D3870u: goto label_1d3870;
            case 0x1D387Cu: goto label_1d387c;
            case 0x1D38E8u: goto label_1d38e8;
            case 0x1D3954u: goto label_1d3954;
            case 0x1D3970u: goto label_1d3970;
            case 0x1D3988u: goto label_1d3988;
            case 0x1D398Cu: goto label_1d398c;
            case 0x1D3994u: goto label_1d3994;
            case 0x1D39D0u: goto label_1d39d0;
            case 0x1D39D8u: goto label_1d39d8;
            case 0x1D39E0u: goto label_1d39e0;
            case 0x1D39F4u: goto label_1d39f4;
            case 0x1D39FCu: goto label_1d39fc;
            case 0x1D3A10u: goto label_1d3a10;
            case 0x1D3A18u: goto label_1d3a18;
            case 0x1D3A3Cu: goto label_1d3a3c;
            case 0x1D3A40u: goto label_1d3a40;
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3AF4u;
    // 0x1d3af4: 0x0  nop
    ctx->pc = 0x1d3af4u;
    // NOP
    // 0x1d3af8: 0x0  nop
    ctx->pc = 0x1d3af8u;
    // NOP
    // 0x1d3afc: 0x0  nop
    ctx->pc = 0x1d3afcu;
    // NOP
    // 0x1d3b00: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1d3b00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1d3b04: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1d3b04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1d3b08: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d3b08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d3b0c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3b0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3b10: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3b10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3b14: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d3b14u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3b18: 0x90840c7c  lbu         $a0, 0xC7C($a0)
    ctx->pc = 0x1d3b18u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3196)));
    // 0x1d3b1c: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1D3B1Cu;
    {
        const bool branch_taken_0x1d3b1c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d3b1c) {
            ctx->pc = 0x1D3B70u;
            goto label_1d3b70;
        }
    }
    ctx->pc = 0x1D3B24u;
    // 0x1d3b24: 0xc16d338  jal         func_5B4CE0
    ctx->pc = 0x1D3B24u;
    SET_GPR_U32(ctx, 31, 0x1D3B2Cu);
    ctx->pc = 0x1D3B28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B24u;
            // 0x1d3b28: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x5B4CE0u;
    {
        auto targetFn = runtime->lookupFunction(0x5B4CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B2Cu; }
        if (ctx->pc != 0x1D3B2Cu) { return; }
    }
    ctx->pc = 0x1D3B2Cu;
label_1d3b2c:
    // 0x1d3b2c: 0x2863c  dsll32      $s0, $v0, 24
    ctx->pc = 0x1d3b2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1d3b30: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d3b30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d3b34: 0x10863f  dsra32      $s0, $s0, 24
    ctx->pc = 0x1d3b34u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 24));
    // 0x1d3b38: 0x1203000d  beq         $s0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1D3B38u;
    {
        const bool branch_taken_0x1d3b38 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d3b38) {
            ctx->pc = 0x1D3B70u;
            goto label_1d3b70;
        }
    }
    ctx->pc = 0x1D3B40u;
    // 0x1d3b40: 0x92240003  lbu         $a0, 0x3($s1)
    ctx->pc = 0x1d3b40u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1d3b44: 0xc1ad2b8  jal         func_6B4AE0
    ctx->pc = 0x1D3B44u;
    SET_GPR_U32(ctx, 31, 0x1D3B4Cu);
    ctx->pc = 0x1D3B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B44u;
            // 0x1d3b48: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B4AE0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B4AE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B4Cu; }
        if (ctx->pc != 0x1D3B4Cu) { return; }
    }
    ctx->pc = 0x1D3B4Cu;
label_1d3b4c:
    // 0x1d3b4c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3b4cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3b50: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d3b50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3b54: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3b54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3b58: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3B58u;
    SET_GPR_U32(ctx, 31, 0x1D3B60u);
    ctx->pc = 0x1D3B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B58u;
            // 0x1d3b5c: 0x24a56648  addiu       $a1, $a1, 0x6648 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B60u; }
        if (ctx->pc != 0x1D3B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B60u; }
        if (ctx->pc != 0x1D3B60u) { return; }
    }
    ctx->pc = 0x1D3B60u;
label_1d3b60:
    // 0x1d3b60: 0x92220003  lbu         $v0, 0x3($s1)
    ctx->pc = 0x1d3b60u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1d3b64: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3b64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3b68: 0xc06b584  jal         func_1AD610
    ctx->pc = 0x1D3B68u;
    SET_GPR_U32(ctx, 31, 0x1D3B70u);
    ctx->pc = 0x1D3B6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B68u;
            // 0x1d3b6c: 0x24450008  addiu       $a1, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD610u;
    if (runtime->hasFunction(0x1AD610u)) {
        auto targetFn = runtime->lookupFunction(0x1AD610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B70u; }
        if (ctx->pc != 0x1D3B70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD610_0x1ad610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B70u; }
        if (ctx->pc != 0x1D3B70u) { return; }
    }
    ctx->pc = 0x1D3B70u;
label_1d3b70:
    // 0x1d3b70: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d3b70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3b74: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d3b74u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3b78: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3b78u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3b7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3B7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B7Cu;
            // 0x1d3b80: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3790u: goto label_1d3790;
            case 0x1D37D4u: goto label_1d37d4;
            case 0x1D37E8u: goto label_1d37e8;
            case 0x1D37F0u: goto label_1d37f0;
            case 0x1D380Cu: goto label_1d380c;
            case 0x1D3818u: goto label_1d3818;
            case 0x1D381Cu: goto label_1d381c;
            case 0x1D3868u: goto label_1d3868;
            case 0x1D3870u: goto label_1d3870;
            case 0x1D387Cu: goto label_1d387c;
            case 0x1D38E8u: goto label_1d38e8;
            case 0x1D3954u: goto label_1d3954;
            case 0x1D3970u: goto label_1d3970;
            case 0x1D3988u: goto label_1d3988;
            case 0x1D398Cu: goto label_1d398c;
            case 0x1D3994u: goto label_1d3994;
            case 0x1D39D0u: goto label_1d39d0;
            case 0x1D39D8u: goto label_1d39d8;
            case 0x1D39E0u: goto label_1d39e0;
            case 0x1D39F4u: goto label_1d39f4;
            case 0x1D39FCu: goto label_1d39fc;
            case 0x1D3A10u: goto label_1d3a10;
            case 0x1D3A18u: goto label_1d3a18;
            case 0x1D3A3Cu: goto label_1d3a3c;
            case 0x1D3A40u: goto label_1d3a40;
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3B84u;
    // 0x1d3b84: 0x0  nop
    ctx->pc = 0x1d3b84u;
    // NOP
    // 0x1d3b88: 0x0  nop
    ctx->pc = 0x1d3b88u;
    // NOP
    // 0x1d3b8c: 0x0  nop
    ctx->pc = 0x1d3b8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
