#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8450
// Address: 0x1d8450 - 0x1d8560
void sub_001D8450_0x1d8450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8450_0x1d8450");
#endif

    switch (ctx->pc) {
        case 0x1d8488u: goto label_1d8488;
        case 0x1d84e8u: goto label_1d84e8;
        case 0x1d8508u: goto label_1d8508;
        case 0x1d8514u: goto label_1d8514;
        case 0x1d852cu: goto label_1d852c;
        default: break;
    }

    ctx->pc = 0x1d8450u;

    // 0x1d8450: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1d8450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1d8454: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1d8454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1d8458: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d8458u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d845c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d845cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d8460: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x1d8460u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8464: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d8464u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d8468: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1d8468u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d846c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d846cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d8470: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1d8470u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8474: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d8474u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d8478: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1d8478u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d847c: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1d847cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8480: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8480u;
    SET_GPR_U32(ctx, 31, 0x1D8488u);
    ctx->pc = 0x1D8484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8480u;
            // 0x1d8484: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8488u; }
        if (ctx->pc != 0x1D8488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8488u; }
        if (ctx->pc != 0x1D8488u) { return; }
    }
    ctx->pc = 0x1D8488u;
label_1d8488:
    // 0x1d8488: 0x13843c  dsll32      $s0, $s3, 16
    ctx->pc = 0x1d8488u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 19) << (32 + 16));
    // 0x1d848c: 0x10843f  dsra32      $s0, $s0, 16
    ctx->pc = 0x1d848cu;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
    // 0x1d8490: 0x1a000003  blez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D8490u;
    {
        const bool branch_taken_0x1d8490 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x1D8494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8490u;
            // 0x1d8494: 0x2a011001  slti        $at, $s0, 0x1001 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4097) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d8490) {
            ctx->pc = 0x1D84A0u;
            goto label_1d84a0;
        }
    }
    ctx->pc = 0x1D8498u;
    // 0x1d8498: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D8498u;
    {
        const bool branch_taken_0x1d8498 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d8498) {
            ctx->pc = 0x1D84A8u;
            goto label_1d84a8;
        }
    }
    ctx->pc = 0x1D84A0u;
label_1d84a0:
    // 0x1d84a0: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1D84A0u;
    {
        const bool branch_taken_0x1d84a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D84A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D84A0u;
            // 0x1d84a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d84a0) {
            ctx->pc = 0x1D8538u;
            goto label_1d8538;
        }
    }
    ctx->pc = 0x1D84A8u;
label_1d84a8:
    // 0x1d84a8: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d84a8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d84ac: 0x24e7729c  addiu       $a3, $a3, 0x729C
    ctx->pc = 0x1d84acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 29340));
    // 0x1d84b0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1d84b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d84b4: 0xa4f40000  sh          $s4, 0x0($a3)
    ctx->pc = 0x1d84b4u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 20));
    // 0x1d84b8: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1d84b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d84bc: 0xa4f3000a  sh          $s3, 0xA($a3)
    ctx->pc = 0x1d84bcu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 10), (uint16_t)GPR_U32(ctx, 19));
    // 0x1d84c0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d84c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d84c4: 0xacf20004  sw          $s2, 0x4($a3)
    ctx->pc = 0x1d84c4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 18));
    // 0x1d84c8: 0x24e4000c  addiu       $a0, $a3, 0xC
    ctx->pc = 0x1d84c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 12));
    // 0x1d84cc: 0xa4f10008  sh          $s1, 0x8($a3)
    ctx->pc = 0x1d84ccu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 8), (uint16_t)GPR_U32(ctx, 17));
    // 0x1d84d0: 0x84e3000a  lh          $v1, 0xA($a3)
    ctx->pc = 0x1d84d0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 10)));
    // 0x1d84d4: 0x30630003  andi        $v1, $v1, 0x3
    ctx->pc = 0x1d84d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x1d84d8: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1d84d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d84dc: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x1d84dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x1d84e0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D84E0u;
    SET_GPR_U32(ctx, 31, 0x1D84E8u);
    ctx->pc = 0x1D84E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D84E0u;
            // 0x1d84e4: 0xa4e20002  sh          $v0, 0x2($a3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 7), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D84E8u; }
        if (ctx->pc != 0x1D84E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D84E8u; }
        if (ctx->pc != 0x1D84E8u) { return; }
    }
    ctx->pc = 0x1D84E8u;
label_1d84e8:
    // 0x1d84e8: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d84e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d84ec: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d84ecu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d84f0: 0x26060030  addiu       $a2, $s0, 0x30
    ctx->pc = 0x1d84f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x1d84f4: 0x24040019  addiu       $a0, $zero, 0x19
    ctx->pc = 0x1d84f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x1d84f8: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d84f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d84fc: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d84fcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8500: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8500u;
    SET_GPR_U32(ctx, 31, 0x1D8508u);
    ctx->pc = 0x1D8504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8500u;
            // 0x1d8504: 0x24080020  addiu       $t0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8508u; }
        if (ctx->pc != 0x1D8508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8508u; }
        if (ctx->pc != 0x1D8508u) { return; }
    }
    ctx->pc = 0x1D8508u;
label_1d8508:
    // 0x1d8508: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8508u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d850c: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D850Cu;
    SET_GPR_U32(ctx, 31, 0x1D8514u);
    ctx->pc = 0x1D8510u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D850Cu;
            // 0x1d8510: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8514u; }
        if (ctx->pc != 0x1D8514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8514u; }
        if (ctx->pc != 0x1D8514u) { return; }
    }
    ctx->pc = 0x1D8514u;
label_1d8514:
    // 0x1d8514: 0x102c3c  dsll32      $a1, $s0, 16
    ctx->pc = 0x1d8514u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1d8518: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1d8518u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1d851c: 0x4a10004  bgez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D851Cu;
    {
        const bool branch_taken_0x1d851c = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x1D8520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D851Cu;
            // 0x1d8520: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d851c) {
            ctx->pc = 0x1D8530u;
            goto label_1d8530;
        }
    }
    ctx->pc = 0x1D8524u;
    // 0x1d8524: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1D8524u;
    SET_GPR_U32(ctx, 31, 0x1D852Cu);
    ctx->pc = 0x1D8528u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8524u;
            // 0x1d8528: 0x248469e0  addiu       $a0, $a0, 0x69E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D852Cu; }
        if (ctx->pc != 0x1D852Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D852Cu; }
        if (ctx->pc != 0x1D852Cu) { return; }
    }
    ctx->pc = 0x1D852Cu;
label_1d852c:
    // 0x1d852c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d852cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d8530:
    // 0x1d8530: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8530u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8534: 0x0  nop
    ctx->pc = 0x1d8534u;
    // NOP
label_1d8538:
    // 0x1d8538: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1d8538u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d853c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d853cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d8540: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d8540u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d8544: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d8544u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d8548: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d8548u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d854c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d854cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8550: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8550u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8554: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8554u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8554u;
            // 0x1d8558: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8488u: goto label_1d8488;
            case 0x1D84A0u: goto label_1d84a0;
            case 0x1D84A8u: goto label_1d84a8;
            case 0x1D84E8u: goto label_1d84e8;
            case 0x1D8508u: goto label_1d8508;
            case 0x1D8514u: goto label_1d8514;
            case 0x1D852Cu: goto label_1d852c;
            case 0x1D8530u: goto label_1d8530;
            case 0x1D8538u: goto label_1d8538;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D855Cu;
    // 0x1d855c: 0x0  nop
    ctx->pc = 0x1d855cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
