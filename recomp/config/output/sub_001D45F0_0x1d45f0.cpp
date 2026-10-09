#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D45F0
// Address: 0x1d45f0 - 0x1d486c
void sub_001D45F0_0x1d45f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D45F0_0x1d45f0");
#endif

    switch (ctx->pc) {
        case 0x1d4654u: goto label_1d4654;
        case 0x1d4668u: goto label_1d4668;
        case 0x1d468cu: goto label_1d468c;
        case 0x1d4698u: goto label_1d4698;
        case 0x1d46b8u: goto label_1d46b8;
        case 0x1d46d4u: goto label_1d46d4;
        case 0x1d47fcu: goto label_1d47fc;
        default: break;
    }

    ctx->pc = 0x1d45f0u;

    // 0x1d45f0: 0x27bdfe50  addiu       $sp, $sp, -0x1B0
    ctx->pc = 0x1d45f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966864));
    // 0x1d45f4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d45f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d45f8: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1d45f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1d45fc: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1d45fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1d4600: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1d4600u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1d4604: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1d4604u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1d4608: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d4608u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d460c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d460cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d4610: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d4610u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d4614: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d4614u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4618: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d4618u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d461c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d461cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4620: 0x8c34440c  lw          $s4, 0x440C($at)
    ctx->pc = 0x1d4620u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d4624: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4624u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4628: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d4628u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d462c: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D462Cu;
    {
        const bool branch_taken_0x1d462c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D462Cu;
            // 0x1d4630: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d462c) {
            ctx->pc = 0x1D4678u;
            goto label_1d4678;
        }
    }
    ctx->pc = 0x1D4634u;
    // 0x1d4634: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4634u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4638: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4638u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d463c: 0x942743da  lhu         $a3, 0x43DA($at)
    ctx->pc = 0x1d463cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d4640: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1d4640u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1d4644: 0x27a400b0  addiu       $a0, $sp, 0xB0
    ctx->pc = 0x1d4644u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x1d4648: 0x24a56940  addiu       $a1, $a1, 0x6940
    ctx->pc = 0x1d4648u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26944));
    // 0x1d464c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D464Cu;
    SET_GPR_U32(ctx, 31, 0x1D4654u);
    ctx->pc = 0x1D4650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D464Cu;
            // 0x1d4650: 0x24c66950  addiu       $a2, $a2, 0x6950 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26960));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4654u; }
        if (ctx->pc != 0x1D4654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4654u; }
        if (ctx->pc != 0x1D4654u) { return; }
    }
    ctx->pc = 0x1D4654u;
label_1d4654:
    // 0x1d4654: 0x27a400b0  addiu       $a0, $sp, 0xB0
    ctx->pc = 0x1d4654u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x1d4658: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1d4658u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d465c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d465cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4660: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4660u;
    SET_GPR_U32(ctx, 31, 0x1D4668u);
    ctx->pc = 0x1D4664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4660u;
            // 0x1d4664: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4668u; }
        if (ctx->pc != 0x1D4668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4668u; }
        if (ctx->pc != 0x1D4668u) { return; }
    }
    ctx->pc = 0x1D4668u;
label_1d4668:
    // 0x1d4668: 0x1c40000d  bgtz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1D4668u;
    {
        const bool branch_taken_0x1d4668 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1d4668) {
            ctx->pc = 0x1D46A0u;
            goto label_1d46a0;
        }
    }
    ctx->pc = 0x1D4670u;
    // 0x1d4670: 0x10000073  b           . + 4 + (0x73 << 2)
    ctx->pc = 0x1D4670u;
    {
        const bool branch_taken_0x1d4670 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4670u;
            // 0x1d4674: 0xdfbf0090  ld          $ra, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4670) {
            ctx->pc = 0x1D4840u;
            goto label_1d4840;
        }
    }
    ctx->pc = 0x1D4678u;
label_1d4678:
    // 0x1d4678: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4678u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d467c: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d467cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d4680: 0x27a400b0  addiu       $a0, $sp, 0xB0
    ctx->pc = 0x1d4680u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x1d4684: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4684u;
    SET_GPR_U32(ctx, 31, 0x1D468Cu);
    ctx->pc = 0x1D4688u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4684u;
            // 0x1d4688: 0x24a56968  addiu       $a1, $a1, 0x6968 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26984));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D468Cu; }
        if (ctx->pc != 0x1D468Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D468Cu; }
        if (ctx->pc != 0x1D468Cu) { return; }
    }
    ctx->pc = 0x1D468Cu;
label_1d468c:
    // 0x1d468c: 0x27a400b0  addiu       $a0, $sp, 0xB0
    ctx->pc = 0x1d468cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x1d4690: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1D4690u;
    SET_GPR_U32(ctx, 31, 0x1D4698u);
    ctx->pc = 0x1D4694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4690u;
            // 0x1d4694: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4698u; }
        if (ctx->pc != 0x1D4698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4698u; }
        if (ctx->pc != 0x1D4698u) { return; }
    }
    ctx->pc = 0x1D4698u;
label_1d4698:
    // 0x1d4698: 0x10400068  beqz        $v0, . + 4 + (0x68 << 2)
    ctx->pc = 0x1D4698u;
    {
        const bool branch_taken_0x1d4698 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d4698) {
            ctx->pc = 0x1D483Cu;
            goto label_1d483c;
        }
    }
    ctx->pc = 0x1D46A0u;
label_1d46a0:
    // 0x1d46a0: 0x8e830000  lw          $v1, 0x0($s4)
    ctx->pc = 0x1d46a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1d46a4: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1d46a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d46a8: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1d46a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d46ac: 0x31842  srl         $v1, $v1, 1
    ctx->pc = 0x1d46acu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x1d46b0: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x1D46B0u;
    {
        const bool branch_taken_0x1d46b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D46B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D46B0u;
            // 0x1d46b4: 0x3f082  srl         $fp, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)SRL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d46b0) {
            ctx->pc = 0x1D4830u;
            goto label_1d4830;
        }
    }
    ctx->pc = 0x1D46B8u;
label_1d46b8:
    // 0x1d46b8: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1d46b8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d46bc: 0x2831821  addu        $v1, $s4, $v1
    ctx->pc = 0x1d46bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1d46c0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1d46c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d46c4: 0x283b021  addu        $s6, $s4, $v1
    ctx->pc = 0x1d46c4u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1d46c8: 0x8ec30000  lw          $v1, 0x0($s6)
    ctx->pc = 0x1d46c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1d46cc: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1D46CCu;
    {
        const bool branch_taken_0x1d46cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D46D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D46CCu;
            // 0x1d46d0: 0xafa300a0  sw          $v1, 0xA0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d46cc) {
            ctx->pc = 0x1D481Cu;
            goto label_1d481c;
        }
    }
    ctx->pc = 0x1D46D4u;
label_1d46d4:
    // 0x1d46d4: 0x10200055  beqz        $at, . + 4 + (0x55 << 2)
    ctx->pc = 0x1D46D4u;
    {
        const bool branch_taken_0x1d46d4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D46D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D46D4u;
            // 0x1d46d8: 0x122080  sll         $a0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d46d4) {
            ctx->pc = 0x1D482Cu;
            goto label_1d482c;
        }
    }
    ctx->pc = 0x1D46DCu;
    // 0x1d46dc: 0x111900  sll         $v1, $s1, 4
    ctx->pc = 0x1d46dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x1d46e0: 0x2c42021  addu        $a0, $s6, $a0
    ctx->pc = 0x1d46e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 4)));
    // 0x1d46e4: 0x711823  subu        $v1, $v1, $s1
    ctx->pc = 0x1d46e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1d46e8: 0x8c860004  lw          $a2, 0x4($a0)
    ctx->pc = 0x1d46e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d46ec: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d46ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d46f0: 0x2c6a821  addu        $s5, $s6, $a2
    ctx->pc = 0x1d46f0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 6)));
    // 0x1d46f4: 0x320c0  sll         $a0, $v1, 3
    ctx->pc = 0x1d46f4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1d46f8: 0x8ea60000  lw          $a2, 0x0($s5)
    ctx->pc = 0x1d46f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1d46fc: 0x3c030039  lui         $v1, 0x39
    ctx->pc = 0x1d46fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)57 << 16));
    // 0x1d4700: 0x24630210  addiu       $v1, $v1, 0x210
    ctx->pc = 0x1d4700u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 528));
    // 0x1d4704: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1d4704u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d4708: 0x2404001d  addiu       $a0, $zero, 0x1D
    ctx->pc = 0x1d4708u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1d470c: 0xa2060000  sb          $a2, 0x0($s0)
    ctx->pc = 0x1d470cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4710: 0x8ea60004  lw          $a2, 0x4($s5)
    ctx->pc = 0x1d4710u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4)));
    // 0x1d4714: 0xa2060001  sb          $a2, 0x1($s0)
    ctx->pc = 0x1d4714u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4718: 0x8ea60008  lw          $a2, 0x8($s5)
    ctx->pc = 0x1d4718u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x1d471c: 0xa2060002  sb          $a2, 0x2($s0)
    ctx->pc = 0x1d471cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4720: 0x8ea60020  lw          $a2, 0x20($s5)
    ctx->pc = 0x1d4720u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 32)));
    // 0x1d4724: 0xa2060003  sb          $a2, 0x3($s0)
    ctx->pc = 0x1d4724u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4728: 0x8ea6000c  lw          $a2, 0xC($s5)
    ctx->pc = 0x1d4728u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 12)));
    // 0x1d472c: 0xa6060004  sh          $a2, 0x4($s0)
    ctx->pc = 0x1d472cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 6));
    // 0x1d4730: 0x8ea60024  lw          $a2, 0x24($s5)
    ctx->pc = 0x1d4730u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 36)));
    // 0x1d4734: 0xa2060006  sb          $a2, 0x6($s0)
    ctx->pc = 0x1d4734u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 6), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4738: 0xc6a20010  lwc1        $f2, 0x10($s5)
    ctx->pc = 0x1d4738u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1d473c: 0xc6a10014  lwc1        $f1, 0x14($s5)
    ctx->pc = 0x1d473cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1d4740: 0xc6a00018  lwc1        $f0, 0x18($s5)
    ctx->pc = 0x1d4740u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d4744: 0xe6020008  swc1        $f2, 0x8($s0)
    ctx->pc = 0x1d4744u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
    // 0x1d4748: 0xe601000c  swc1        $f1, 0xC($s0)
    ctx->pc = 0x1d4748u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 12), bits); }
    // 0x1d474c: 0xe6000010  swc1        $f0, 0x10($s0)
    ctx->pc = 0x1d474cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 16), bits); }
    // 0x1d4750: 0x8ea6001c  lw          $a2, 0x1C($s5)
    ctx->pc = 0x1d4750u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 28)));
    // 0x1d4754: 0xa6060014  sh          $a2, 0x14($s0)
    ctx->pc = 0x1d4754u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 20), (uint16_t)GPR_U32(ctx, 6));
    // 0x1d4758: 0x8ea60048  lw          $a2, 0x48($s5)
    ctx->pc = 0x1d4758u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 72)));
    // 0x1d475c: 0xa6060016  sh          $a2, 0x16($s0)
    ctx->pc = 0x1d475cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 22), (uint16_t)GPR_U32(ctx, 6));
    // 0x1d4760: 0x8ea6004c  lw          $a2, 0x4C($s5)
    ctx->pc = 0x1d4760u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 76)));
    // 0x1d4764: 0xa6060022  sh          $a2, 0x22($s0)
    ctx->pc = 0x1d4764u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 34), (uint16_t)GPR_U32(ctx, 6));
    // 0x1d4768: 0xa200001e  sb          $zero, 0x1E($s0)
    ctx->pc = 0x1d4768u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d476c: 0x8ea60050  lw          $a2, 0x50($s5)
    ctx->pc = 0x1d476cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 80)));
    // 0x1d4770: 0xa2060034  sb          $a2, 0x34($s0)
    ctx->pc = 0x1d4770u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 52), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4774: 0xae050028  sw          $a1, 0x28($s0)
    ctx->pc = 0x1d4774u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 5));
    // 0x1d4778: 0xae050030  sw          $a1, 0x30($s0)
    ctx->pc = 0x1d4778u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 5));
    // 0x1d477c: 0x96050004  lhu         $a1, 0x4($s0)
    ctx->pc = 0x1d477cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1d4780: 0x10a40003  beq         $a1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4780u;
    {
        const bool branch_taken_0x1d4780 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1D4784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4780u;
            // 0x1d4784: 0x26030006  addiu       $v1, $s0, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4780) {
            ctx->pc = 0x1D4790u;
            goto label_1d4790;
        }
    }
    ctx->pc = 0x1D4788u;
    // 0x1d4788: 0xaea00024  sw          $zero, 0x24($s5)
    ctx->pc = 0x1d4788u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 36), GPR_U32(ctx, 0));
    // 0x1d478c: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1d478cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4790:
    // 0x1d4790: 0x8ea40024  lw          $a0, 0x24($s5)
    ctx->pc = 0x1d4790u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 36)));
    // 0x1d4794: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1d4794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d4798: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1D4798u;
    {
        const bool branch_taken_0x1d4798 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D479Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4798u;
            // 0x1d479c: 0x2617005c  addiu       $s7, $s0, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 16), 92));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4798) {
            ctx->pc = 0x1D47ECu;
            goto label_1d47ec;
        }
    }
    ctx->pc = 0x1D47A0u;
    // 0x1d47a0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d47a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d47a4: 0x1083000e  beq         $a0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1D47A4u;
    {
        const bool branch_taken_0x1d47a4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d47a4) {
            ctx->pc = 0x1D47E0u;
            goto label_1d47e0;
        }
    }
    ctx->pc = 0x1D47ACu;
    // 0x1d47ac: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D47ACu;
    {
        const bool branch_taken_0x1d47ac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d47ac) {
            ctx->pc = 0x1D47BCu;
            goto label_1d47bc;
        }
    }
    ctx->pc = 0x1D47B4u;
    // 0x1d47b4: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D47B4u;
    {
        const bool branch_taken_0x1d47b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D47B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D47B4u;
            // 0x1d47b8: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d47b4) {
            ctx->pc = 0x1D4818u;
            goto label_1d4818;
        }
    }
    ctx->pc = 0x1D47BCu;
label_1d47bc:
    // 0x1d47bc: 0x8ea3002c  lw          $v1, 0x2C($s5)
    ctx->pc = 0x1d47bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 44)));
    // 0x1d47c0: 0xa6030054  sh          $v1, 0x54($s0)
    ctx->pc = 0x1d47c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 84), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d47c4: 0x8ea30030  lw          $v1, 0x30($s5)
    ctx->pc = 0x1d47c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 48)));
    // 0x1d47c8: 0xa6030056  sh          $v1, 0x56($s0)
    ctx->pc = 0x1d47c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 86), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d47cc: 0x8ea30028  lw          $v1, 0x28($s5)
    ctx->pc = 0x1d47ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x1d47d0: 0xa2030058  sb          $v1, 0x58($s0)
    ctx->pc = 0x1d47d0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 88), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d47d4: 0x8ea30034  lw          $v1, 0x34($s5)
    ctx->pc = 0x1d47d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 52)));
    // 0x1d47d8: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1D47D8u;
    {
        const bool branch_taken_0x1d47d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D47DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D47D8u;
            // 0x1d47dc: 0xa203001f  sb          $v1, 0x1F($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d47d8) {
            ctx->pc = 0x1D4814u;
            goto label_1d4814;
        }
    }
    ctx->pc = 0x1D47E0u;
label_1d47e0:
    // 0x1d47e0: 0x8ea30028  lw          $v1, 0x28($s5)
    ctx->pc = 0x1d47e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x1d47e4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1D47E4u;
    {
        const bool branch_taken_0x1d47e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D47E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D47E4u;
            // 0x1d47e8: 0xa2030058  sb          $v1, 0x58($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 88), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d47e4) {
            ctx->pc = 0x1D4814u;
            goto label_1d4814;
        }
    }
    ctx->pc = 0x1D47ECu;
label_1d47ec:
    // 0x1d47ec: 0x26a50034  addiu       $a1, $s5, 0x34
    ctx->pc = 0x1d47ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 52));
    // 0x1d47f0: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1d47f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d47f4: 0xc0636ec  jal         func_18DBB0
    ctx->pc = 0x1D47F4u;
    SET_GPR_U32(ctx, 31, 0x1D47FCu);
    ctx->pc = 0x1D47F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D47F4u;
            // 0x1d47f8: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DBB0u;
    if (runtime->hasFunction(0x18DBB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D47FCu; }
        if (ctx->pc != 0x1D47FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D47FCu; }
        if (ctx->pc != 0x1D47FCu) { return; }
    }
    ctx->pc = 0x1D47FCu;
label_1d47fc:
    // 0x1d47fc: 0x8ea30044  lw          $v1, 0x44($s5)
    ctx->pc = 0x1d47fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 68)));
    // 0x1d4800: 0xae03006c  sw          $v1, 0x6C($s0)
    ctx->pc = 0x1d4800u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 108), GPR_U32(ctx, 3));
    // 0x1d4804: 0x8ea30028  lw          $v1, 0x28($s5)
    ctx->pc = 0x1d4804u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x1d4808: 0xa2030058  sb          $v1, 0x58($s0)
    ctx->pc = 0x1d4808u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 88), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d480c: 0x8ee30000  lw          $v1, 0x0($s7)
    ctx->pc = 0x1d480cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x1d4810: 0xa603001a  sh          $v1, 0x1A($s0)
    ctx->pc = 0x1d4810u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 26), (uint16_t)GPR_U32(ctx, 3));
label_1d4814:
    // 0x1d4814: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1d4814u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1d4818:
    // 0x1d4818: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1d4818u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1d481c:
    // 0x1d481c: 0x8fa300a0  lw          $v1, 0xA0($sp)
    ctx->pc = 0x1d481cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1d4820: 0x243182b  sltu        $v1, $s2, $v1
    ctx->pc = 0x1d4820u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1d4824: 0x1460ffab  bnez        $v1, . + 4 + (-0x55 << 2)
    ctx->pc = 0x1D4824u;
    {
        const bool branch_taken_0x1d4824 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4824u;
            // 0x1d4828: 0x2e210040  sltiu       $at, $s1, 0x40 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)64) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4824) {
            ctx->pc = 0x1D46D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d46d4;
        }
    }
    ctx->pc = 0x1D482Cu;
label_1d482c:
    // 0x1d482c: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d482cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1d4830:
    // 0x1d4830: 0x27e182b  sltu        $v1, $s3, $fp
    ctx->pc = 0x1d4830u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 30)) ? 1 : 0);
    // 0x1d4834: 0x1460ffa0  bnez        $v1, . + 4 + (-0x60 << 2)
    ctx->pc = 0x1D4834u;
    {
        const bool branch_taken_0x1d4834 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4834u;
            // 0x1d4838: 0x1318c0  sll         $v1, $s3, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4834) {
            ctx->pc = 0x1D46B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d46b8;
        }
    }
    ctx->pc = 0x1D483Cu;
label_1d483c:
    // 0x1d483c: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1d483cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1d4840:
    // 0x1d4840: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1d4840u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1d4844: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1d4844u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1d4848: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1d4848u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d484c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d484cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d4850: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d4850u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d4854: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d4854u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d4858: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d4858u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d485c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d485cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4860: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4860u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4864: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4864u;
            // 0x1d4868: 0x27bd01b0  addiu       $sp, $sp, 0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 432));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4654u: goto label_1d4654;
            case 0x1D4668u: goto label_1d4668;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D468Cu: goto label_1d468c;
            case 0x1D4698u: goto label_1d4698;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D47FCu: goto label_1d47fc;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D486Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
