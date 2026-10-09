#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B52B0
// Address: 0x1b52b0 - 0x1b55a0
void sub_001B52B0_0x1b52b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B52B0_0x1b52b0");
#endif

    switch (ctx->pc) {
        case 0x1b52f4u: goto label_1b52f4;
        case 0x1b5308u: goto label_1b5308;
        case 0x1b531cu: goto label_1b531c;
        case 0x1b541cu: goto label_1b541c;
        case 0x1b5474u: goto label_1b5474;
        case 0x1b5498u: goto label_1b5498;
        case 0x1b54a4u: goto label_1b54a4;
        case 0x1b5594u: goto label_1b5594;
        default: break;
    }

    ctx->pc = 0x1b52b0u;

label_1b52b0:
    // 0x1b52b0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1b52b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1b52b4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b52b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b52b8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b52b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b52bc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b52bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b52c0: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1b52c0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b52c4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b52c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b52c8: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1b52c8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b52cc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b52ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b52d0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1b52d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b52d4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b52d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b52d8: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1b52d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b52dc: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b52dcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b52e0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b52e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b52e4: 0x2610aa40  addiu       $s0, $s0, -0x55C0
    ctx->pc = 0x1b52e4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945344));
    // 0x1b52e8: 0x240600a8  addiu       $a2, $zero, 0xA8
    ctx->pc = 0x1b52e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 168));
    // 0x1b52ec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B52ECu;
    SET_GPR_U32(ctx, 31, 0x1B52F4u);
    ctx->pc = 0x1B52F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B52ECu;
            // 0x1b52f0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B52F4u; }
        if (ctx->pc != 0x1B52F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B52F4u; }
        if (ctx->pc != 0x1B52F4u) { return; }
    }
    ctx->pc = 0x1B52F4u;
label_1b52f4:
    // 0x1b52f4: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1b52f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1b52f8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b52f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b52fc: 0x2484c040  addiu       $a0, $a0, -0x3FC0
    ctx->pc = 0x1b52fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950976));
    // 0x1b5300: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B5300u;
    SET_GPR_U32(ctx, 31, 0x1B5308u);
    ctx->pc = 0x1B5304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5300u;
            // 0x1b5304: 0x34069180  ori         $a2, $zero, 0x9180 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37248);
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5308u; }
        if (ctx->pc != 0x1B5308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5308u; }
        if (ctx->pc != 0x1B5308u) { return; }
    }
    ctx->pc = 0x1B5308u;
label_1b5308:
    // 0x1b5308: 0x3c040030  lui         $a0, 0x30
    ctx->pc = 0x1b5308u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)48 << 16));
    // 0x1b530c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b530cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5310: 0x24842ec0  addiu       $a0, $a0, 0x2EC0
    ctx->pc = 0x1b5310u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11968));
    // 0x1b5314: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B5314u;
    SET_GPR_U32(ctx, 31, 0x1B531Cu);
    ctx->pc = 0x1B5318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5314u;
            // 0x1b5318: 0x34069180  ori         $a2, $zero, 0x9180 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37248);
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B531Cu; }
        if (ctx->pc != 0x1B531Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B531Cu; }
        if (ctx->pc != 0x1B531Cu) { return; }
    }
    ctx->pc = 0x1B531Cu;
label_1b531c:
    // 0x1b531c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b531cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5320: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1b5320u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1b5324: 0xac34aa44  sw          $s4, -0x55BC($at)
    ctx->pc = 0x1b5324u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945348), GPR_U32(ctx, 20));
    // 0x1b5328: 0x34029180  ori         $v0, $zero, 0x9180
    ctx->pc = 0x1b5328u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37248);
    // 0x1b532c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b532cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5330: 0x24a54590  addiu       $a1, $a1, 0x4590
    ctx->pc = 0x1b5330u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17808));
    // 0x1b5334: 0xac22aadc  sw          $v0, -0x5524($at)
    ctx->pc = 0x1b5334u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945500), GPR_U32(ctx, 2));
    // 0x1b5338: 0x2403ffc0  addiu       $v1, $zero, -0x40
    ctx->pc = 0x1b5338u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1b533c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b533cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5340: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1b5340u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1b5344: 0x8c27aa44  lw          $a3, -0x55BC($at)
    ctx->pc = 0x1b5344u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945348)));
    // 0x1b5348: 0x3442703f  ori         $v0, $v0, 0x703F
    ctx->pc = 0x1b5348u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)28735);
    // 0x1b534c: 0x2622021  addu        $a0, $s3, $v0
    ctx->pc = 0x1b534cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1b5350: 0x73040  sll         $a2, $a3, 1
    ctx->pc = 0x1b5350u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1b5354: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5354u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5358: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1b5358u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1b535c: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1b535cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1b5360: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1b5360u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1b5364: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1b5364u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1b5368: 0xa63021  addu        $a2, $a1, $a2
    ctx->pc = 0x1b5368u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1b536c: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1b536cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b5370: 0xac25aa48  sw          $a1, -0x55B8($at)
    ctx->pc = 0x1b5370u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945352), GPR_U32(ctx, 5));
    // 0x1b5374: 0x8cc50004  lw          $a1, 0x4($a2)
    ctx->pc = 0x1b5374u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1b5378: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5378u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b537c: 0xac25aa4c  sw          $a1, -0x55B4($at)
    ctx->pc = 0x1b537cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945356), GPR_U32(ctx, 5));
    // 0x1b5380: 0x8cc50008  lw          $a1, 0x8($a2)
    ctx->pc = 0x1b5380u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x1b5384: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5384u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5388: 0xac25aa50  sw          $a1, -0x55B0($at)
    ctx->pc = 0x1b5388u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945360), GPR_U32(ctx, 5));
    // 0x1b538c: 0x8cc5000c  lw          $a1, 0xC($a2)
    ctx->pc = 0x1b538cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x1b5390: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5390u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5394: 0xac25aa54  sw          $a1, -0x55AC($at)
    ctx->pc = 0x1b5394u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945364), GPR_U32(ctx, 5));
    // 0x1b5398: 0x8cc50010  lw          $a1, 0x10($a2)
    ctx->pc = 0x1b5398u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x1b539c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b539cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53a0: 0xac25aa58  sw          $a1, -0x55A8($at)
    ctx->pc = 0x1b53a0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945368), GPR_U32(ctx, 5));
    // 0x1b53a4: 0x8cc5001c  lw          $a1, 0x1C($a2)
    ctx->pc = 0x1b53a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 28)));
    // 0x1b53a8: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b53a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53ac: 0xac25aa5c  sw          $a1, -0x55A4($at)
    ctx->pc = 0x1b53acu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945372), GPR_U32(ctx, 5));
    // 0x1b53b0: 0x8cc50020  lw          $a1, 0x20($a2)
    ctx->pc = 0x1b53b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x1b53b4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b53b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53b8: 0xac25aa60  sw          $a1, -0x55A0($at)
    ctx->pc = 0x1b53b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945376), GPR_U32(ctx, 5));
    // 0x1b53bc: 0x8cc50018  lw          $a1, 0x18($a2)
    ctx->pc = 0x1b53bcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x1b53c0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b53c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53c4: 0xac25aa64  sw          $a1, -0x559C($at)
    ctx->pc = 0x1b53c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945380), GPR_U32(ctx, 5));
    // 0x1b53c8: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b53c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53cc: 0xac32aaa0  sw          $s2, -0x5560($at)
    ctx->pc = 0x1b53ccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945440), GPR_U32(ctx, 18));
    // 0x1b53d0: 0x8cc50028  lw          $a1, 0x28($a2)
    ctx->pc = 0x1b53d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 40)));
    // 0x1b53d4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b53d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53d8: 0xac25aacc  sw          $a1, -0x5534($at)
    ctx->pc = 0x1b53d8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945484), GPR_U32(ctx, 5));
    // 0x1b53dc: 0x8cc5002c  lw          $a1, 0x2C($a2)
    ctx->pc = 0x1b53dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 44)));
    // 0x1b53e0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b53e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53e4: 0xac25aad0  sw          $a1, -0x5530($at)
    ctx->pc = 0x1b53e4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945488), GPR_U32(ctx, 5));
    // 0x1b53e8: 0x8cc50030  lw          $a1, 0x30($a2)
    ctx->pc = 0x1b53e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 48)));
    // 0x1b53ec: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b53ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53f0: 0xac25aad4  sw          $a1, -0x552C($at)
    ctx->pc = 0x1b53f0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945492), GPR_U32(ctx, 5));
    // 0x1b53f4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b53f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b53f8: 0xac33aa68  sw          $s3, -0x5598($at)
    ctx->pc = 0x1b53f8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945384), GPR_U32(ctx, 19));
    // 0x1b53fc: 0x839824  and         $s3, $a0, $v1
    ctx->pc = 0x1b53fcu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1b5400: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5400u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5404: 0xac33aa74  sw          $s3, -0x558C($at)
    ctx->pc = 0x1b5404u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945396), GPR_U32(ctx, 19));
    // 0x1b5408: 0x8cc50014  lw          $a1, 0x14($a2)
    ctx->pc = 0x1b5408u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0x1b540c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b540cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5410: 0x8c26aa74  lw          $a2, -0x558C($at)
    ctx->pc = 0x1b5410u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945396)));
    // 0x1b5414: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1B5414u;
    {
        const bool branch_taken_0x1b5414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5414u;
            // 0x1b5418: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5414) {
            ctx->pc = 0x1B544Cu;
            goto label_1b544c;
        }
    }
    ctx->pc = 0x1B541Cu;
label_1b541c:
    // 0x1b541c: 0x90a40000  lbu         $a0, 0x0($a1)
    ctx->pc = 0x1b541cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1b5420: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1b5420u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1b5424: 0x28e30010  slti        $v1, $a3, 0x10
    ctx->pc = 0x1b5424u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b5428: 0xa0c40003  sb          $a0, 0x3($a2)
    ctx->pc = 0x1b5428u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x1b542c: 0x90a40001  lbu         $a0, 0x1($a1)
    ctx->pc = 0x1b542cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x1b5430: 0xa0c40002  sb          $a0, 0x2($a2)
    ctx->pc = 0x1b5430u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1b5434: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x1b5434u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x1b5438: 0xa0c40001  sb          $a0, 0x1($a2)
    ctx->pc = 0x1b5438u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x1b543c: 0xa0c40000  sb          $a0, 0x0($a2)
    ctx->pc = 0x1b543cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1b5440: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1B5440u;
    {
        const bool branch_taken_0x1b5440 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5440u;
            // 0x1b5444: 0x24c60004  addiu       $a2, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5440) {
            ctx->pc = 0x1B541Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b541c;
        }
    }
    ctx->pc = 0x1B5448u;
    // 0x1b5448: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b5448u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1b544c:
    // 0x1b544c: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x1b544cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1b5450: 0x44182b  sltu        $v1, $v0, $a0
    ctx->pc = 0x1b5450u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1b5454: 0x1460fff1  bnez        $v1, . + 4 + (-0xF << 2)
    ctx->pc = 0x1B5454u;
    {
        const bool branch_taken_0x1b5454 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5454u;
            // 0x1b5458: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5454) {
            ctx->pc = 0x1B541Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b541c;
        }
    }
    ctx->pc = 0x1B545Cu;
    // 0x1b545c: 0x41180  sll         $v0, $a0, 6
    ctx->pc = 0x1b545cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
    // 0x1b5460: 0xae110054  sw          $s1, 0x54($s0)
    ctx->pc = 0x1b5460u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 17));
    // 0x1b5464: 0x2629821  addu        $s3, $s3, $v0
    ctx->pc = 0x1b5464u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1b5468: 0x26220002  addiu       $v0, $s1, 0x2
    ctx->pc = 0x1b5468u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
    // 0x1b546c: 0xae020058  sw          $v0, 0x58($s0)
    ctx->pc = 0x1b546cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 2));
    // 0x1b5470: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b5470u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b5474:
    // 0x1b5474: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b5474u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b5478: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1b5478u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1b547c: 0x244244b8  addiu       $v0, $v0, 0x44B8
    ctx->pc = 0x1b547cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17592));
    // 0x1b5480: 0x2039021  addu        $s2, $s0, $v1
    ctx->pc = 0x1b5480u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1b5484: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b5484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b5488: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1b5488u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b548c: 0xae440038  sw          $a0, 0x38($s2)
    ctx->pc = 0x1b548cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 4));
    // 0x1b5490: 0xc06dbc4  jal         func_1B6F10
    ctx->pc = 0x1B5490u;
    SET_GPR_U32(ctx, 31, 0x1B5498u);
    ctx->pc = 0x1B5494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5490u;
            // 0x1b5494: 0x8e05000c  lw          $a1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6F10u;
    if (runtime->hasFunction(0x1B6F10u)) {
        auto targetFn = runtime->lookupFunction(0x1B6F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5498u; }
        if (ctx->pc != 0x1B5498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6F10_0x1b6f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5498u; }
        if (ctx->pc != 0x1B5498u) { return; }
    }
    ctx->pc = 0x1B5498u;
label_1b5498:
    // 0x1b5498: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b5498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b549c: 0xc06dc54  jal         func_1B7150
    ctx->pc = 0x1B549Cu;
    SET_GPR_U32(ctx, 31, 0x1B54A4u);
    ctx->pc = 0x1B54A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B549Cu;
            // 0x1b54a0: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7150u;
    if (runtime->hasFunction(0x1B7150u)) {
        auto targetFn = runtime->lookupFunction(0x1B7150u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B54A4u; }
        if (ctx->pc != 0x1B54A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7150_0x1b7150(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B54A4u; }
        if (ctx->pc != 0x1B54A4u) { return; }
    }
    ctx->pc = 0x1B54A4u;
label_1b54a4:
    // 0x1b54a4: 0xae420040  sw          $v0, 0x40($s2)
    ctx->pc = 0x1b54a4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 64), GPR_U32(ctx, 2));
    // 0x1b54a8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b54a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b54ac: 0x2a220002  slti        $v0, $s1, 0x2
    ctx->pc = 0x1b54acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1b54b0: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1B54B0u;
    {
        const bool branch_taken_0x1b54b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b54b0) {
            ctx->pc = 0x1B5474u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5474;
        }
    }
    ctx->pc = 0x1B54B8u;
    // 0x1b54b8: 0xae000048  sw          $zero, 0x48($s0)
    ctx->pc = 0x1b54b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 0));
    // 0x1b54bc: 0x3c038080  lui         $v1, 0x8080
    ctx->pc = 0x1b54bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32896 << 16));
    // 0x1b54c0: 0x8e060040  lw          $a2, 0x40($s0)
    ctx->pc = 0x1b54c0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x1b54c4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b54c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b54c8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b54c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b54cc: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x1b54ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1b54d0: 0x34638080  ori         $v1, $v1, 0x8080
    ctx->pc = 0x1b54d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32896);
    // 0x1b54d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1b54d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b54d8: 0xae06004c  sw          $a2, 0x4C($s0)
    ctx->pc = 0x1b54d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 6));
    // 0x1b54dc: 0x8e060028  lw          $a2, 0x28($s0)
    ctx->pc = 0x1b54dcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1b54e0: 0x2663023  subu        $a2, $s3, $a2
    ctx->pc = 0x1b54e0u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 6)));
    // 0x1b54e4: 0xae06005c  sw          $a2, 0x5C($s0)
    ctx->pc = 0x1b54e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 6));
    // 0x1b54e8: 0xa02543ea  sb          $a1, 0x43EA($at)
    ctx->pc = 0x1b54e8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17386), (uint8_t)GPR_U32(ctx, 5));
    // 0x1b54ec: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x1b54ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1b54f0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b54f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b54f4: 0xae05006c  sw          $a1, 0x6C($s0)
    ctx->pc = 0x1b54f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 108), GPR_U32(ctx, 5));
    // 0x1b54f8: 0xae000070  sw          $zero, 0x70($s0)
    ctx->pc = 0x1b54f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 112), GPR_U32(ctx, 0));
    // 0x1b54fc: 0xae000074  sw          $zero, 0x74($s0)
    ctx->pc = 0x1b54fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 116), GPR_U32(ctx, 0));
    // 0x1b5500: 0xae040078  sw          $a0, 0x78($s0)
    ctx->pc = 0x1b5500u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 120), GPR_U32(ctx, 4));
    // 0x1b5504: 0xae00007c  sw          $zero, 0x7C($s0)
    ctx->pc = 0x1b5504u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 124), GPR_U32(ctx, 0));
    // 0x1b5508: 0xae030080  sw          $v1, 0x80($s0)
    ctx->pc = 0x1b5508u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 128), GPR_U32(ctx, 3));
    // 0x1b550c: 0xac22ab78  sw          $v0, -0x5488($at)
    ctx->pc = 0x1b550cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945656), GPR_U32(ctx, 2));
    // 0x1b5510: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x1b5510u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1b5514: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b5514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b5518: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b5518u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b551c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b551cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b5520: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b5520u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b5524: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b5524u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b5528: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b5528u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b552c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B552Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B5530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B552Cu;
            // 0x1b5530: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B52B0u: goto label_1b52b0;
            case 0x1B52F4u: goto label_1b52f4;
            case 0x1B5308u: goto label_1b5308;
            case 0x1B531Cu: goto label_1b531c;
            case 0x1B541Cu: goto label_1b541c;
            case 0x1B544Cu: goto label_1b544c;
            case 0x1B5474u: goto label_1b5474;
            case 0x1B5498u: goto label_1b5498;
            case 0x1B54A4u: goto label_1b54a4;
            case 0x1B5570u: goto label_1b5570;
            case 0x1B558Cu: goto label_1b558c;
            case 0x1B5594u: goto label_1b5594;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B5534u;
    // 0x1b5534: 0x0  nop
    ctx->pc = 0x1b5534u;
    // NOP
    // 0x1b5538: 0x0  nop
    ctx->pc = 0x1b5538u;
    // NOP
    // 0x1b553c: 0x0  nop
    ctx->pc = 0x1b553cu;
    // NOP
    // 0x1b5540: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b5540u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b5544: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b5544u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b5548: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b5548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b554c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b554cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b5550: 0x902343c3  lbu         $v1, 0x43C3($at)
    ctx->pc = 0x1b5550u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17347)));
    // 0x1b5554: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B5554u;
    {
        const bool branch_taken_0x1b5554 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B5558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5554u;
            // 0x1b5558: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5554) {
            ctx->pc = 0x1B5570u;
            goto label_1b5570;
        }
    }
    ctx->pc = 0x1B555Cu;
    // 0x1b555c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b555cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b5560: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b5560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b5564: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1b5564u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5568: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B5568u;
    {
        const bool branch_taken_0x1b5568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B556Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5568u;
            // 0x1b556c: 0xa02343ea  sb          $v1, 0x43EA($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17386), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5568) {
            ctx->pc = 0x1B5594u;
            goto label_1b5594;
        }
    }
    ctx->pc = 0x1B5570u;
label_1b5570:
    // 0x1b5570: 0x94274414  lhu         $a3, 0x4414($at)
    ctx->pc = 0x1b5570u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17428)));
    // 0x1b5574: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B5574u;
    {
        const bool branch_taken_0x1b5574 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5574u;
            // 0x1b5578: 0x24060080  addiu       $a2, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5574) {
            ctx->pc = 0x1B558Cu;
            goto label_1b558c;
        }
    }
    ctx->pc = 0x1B557Cu;
    // 0x1b557c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b557cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b5580: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b5580u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5584: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B5584u;
    {
        const bool branch_taken_0x1b5584 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5584u;
            // 0x1b5588: 0xa02043ea  sb          $zero, 0x43EA($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17386), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5584) {
            ctx->pc = 0x1B5594u;
            goto label_1b5594;
        }
    }
    ctx->pc = 0x1B558Cu;
label_1b558c:
    // 0x1b558c: 0xc06d4ac  jal         func_1B52B0
    ctx->pc = 0x1B558Cu;
    SET_GPR_U32(ctx, 31, 0x1B5594u);
    ctx->pc = 0x1B52B0u;
    goto label_1b52b0;
    ctx->pc = 0x1B5594u;
label_1b5594:
    // 0x1b5594: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b5594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b5598: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B559Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5598u;
            // 0x1b559c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B52B0u: goto label_1b52b0;
            case 0x1B52F4u: goto label_1b52f4;
            case 0x1B5308u: goto label_1b5308;
            case 0x1B531Cu: goto label_1b531c;
            case 0x1B541Cu: goto label_1b541c;
            case 0x1B544Cu: goto label_1b544c;
            case 0x1B5474u: goto label_1b5474;
            case 0x1B5498u: goto label_1b5498;
            case 0x1B54A4u: goto label_1b54a4;
            case 0x1B5570u: goto label_1b5570;
            case 0x1B558Cu: goto label_1b558c;
            case 0x1B5594u: goto label_1b5594;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B55A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
