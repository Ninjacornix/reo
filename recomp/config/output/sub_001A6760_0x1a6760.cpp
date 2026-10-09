#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A6760
// Address: 0x1a6760 - 0x1a6f90
void sub_001A6760_0x1a6760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A6760_0x1a6760");
#endif

    switch (ctx->pc) {
        case 0x1a67acu: goto label_1a67ac;
        case 0x1a67ecu: goto label_1a67ec;
        case 0x1a68a0u: goto label_1a68a0;
        case 0x1a6974u: goto label_1a6974;
        case 0x1a69f8u: goto label_1a69f8;
        case 0x1a6a24u: goto label_1a6a24;
        case 0x1a6a70u: goto label_1a6a70;
        case 0x1a6b5cu: goto label_1a6b5c;
        case 0x1a6bd4u: goto label_1a6bd4;
        case 0x1a6c50u: goto label_1a6c50;
        case 0x1a6cd4u: goto label_1a6cd4;
        case 0x1a6ee8u: goto label_1a6ee8;
        case 0x1a6f3cu: goto label_1a6f3c;
        default: break;
    }

    ctx->pc = 0x1a6760u;

    // 0x1a6760: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1a6760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1a6764: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a6764u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a6768: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1a6768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1a676c: 0x244209e0  addiu       $v0, $v0, 0x9E0
    ctx->pc = 0x1a676cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2528));
    // 0x1a6770: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1a6770u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1a6774: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1a6774u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1a6778: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1a6778u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1a677c: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1a677cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a6780: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a6780u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a6784: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a6784u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a6788: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a6788u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a678c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a678cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a6790: 0x48140  sll         $s0, $a0, 5
    ctx->pc = 0x1a6790u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x1a6794: 0x50a021  addu        $s4, $v0, $s0
    ctx->pc = 0x1a6794u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1a6798: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1a6798u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a679c: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a679cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a67a0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1a67a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a67a4: 0x244209c0  addiu       $v0, $v0, 0x9C0
    ctx->pc = 0x1a67a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2496));
    // 0x1a67a8: 0x503021  addu        $a2, $v0, $s0
    ctx->pc = 0x1a67a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_1a67ac:
    // 0x1a67ac: 0x84c30000  lh          $v1, 0x0($a2)
    ctx->pc = 0x1a67acu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1a67b0: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1a67b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1a67b4: 0x84c20002  lh          $v0, 0x2($a2)
    ctx->pc = 0x1a67b4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 2)));
    // 0x1a67b8: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1a67b8u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a67bc: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1a67bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1a67c0: 0xa4a20002  sh          $v0, 0x2($a1)
    ctx->pc = 0x1a67c0u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a67c4: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A67C4u;
    {
        const bool branch_taken_0x1a67c4 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x1A67C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A67C4u;
            // 0x1a67c8: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a67c4) {
            ctx->pc = 0x1A67ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a67ac;
        }
    }
    ctx->pc = 0x1A67CCu;
    // 0x1a67cc: 0x151840  sll         $v1, $s5, 1
    ctx->pc = 0x1a67ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 21), 1));
    // 0x1a67d0: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a67d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a67d4: 0x751821  addu        $v1, $v1, $s5
    ctx->pc = 0x1a67d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 21)));
    // 0x1a67d8: 0x24420a16  addiu       $v0, $v0, 0xA16
    ctx->pc = 0x1a67d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2582));
    // 0x1a67dc: 0x388c0  sll         $s1, $v1, 3
    ctx->pc = 0x1a67dcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a67e0: 0x519821  addu        $s3, $v0, $s1
    ctx->pc = 0x1a67e0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1a67e4: 0xc0601a0  jal         func_180680
    ctx->pc = 0x1A67E4u;
    SET_GPR_U32(ctx, 31, 0x1A67ECu);
    ctx->pc = 0x1A67E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A67E4u;
            // 0x1a67e8: 0x92640000  lbu         $a0, 0x0($s3) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180680u;
    if (runtime->hasFunction(0x180680u)) {
        auto targetFn = runtime->lookupFunction(0x180680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A67ECu; }
        if (ctx->pc != 0x1A67ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180680_0x180680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A67ECu; }
        if (ctx->pc != 0x1A67ECu) { return; }
    }
    ctx->pc = 0x1A67ECu;
label_1a67ec:
    // 0x1a67ec: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a67ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a67f0: 0x10430044  beq         $v0, $v1, . + 4 + (0x44 << 2)
    ctx->pc = 0x1A67F0u;
    {
        const bool branch_taken_0x1a67f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a67f0) {
            ctx->pc = 0x1A6904u;
            goto label_1a6904;
        }
    }
    ctx->pc = 0x1A67F8u;
    // 0x1a67f8: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1a67f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a67fc: 0x10440041  beq         $v0, $a0, . + 4 + (0x41 << 2)
    ctx->pc = 0x1A67FCu;
    {
        const bool branch_taken_0x1a67fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x1a67fc) {
            ctx->pc = 0x1A6904u;
            goto label_1a6904;
        }
    }
    ctx->pc = 0x1A6804u;
    // 0x1a6804: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1A6804u;
    {
        const bool branch_taken_0x1a6804 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6804u;
            // 0x1a6808: 0x3c03002b  lui         $v1, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6804) {
            ctx->pc = 0x1A6834u;
            goto label_1a6834;
        }
    }
    ctx->pc = 0x1A680Cu;
    // 0x1a680c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a680cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a6810: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A6810u;
    {
        const bool branch_taken_0x1a6810 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a6810) {
            ctx->pc = 0x1A6820u;
            goto label_1a6820;
        }
    }
    ctx->pc = 0x1A6818u;
    // 0x1a6818: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1A6818u;
    {
        const bool branch_taken_0x1a6818 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6818) {
            ctx->pc = 0x1A6904u;
            goto label_1a6904;
        }
    }
    ctx->pc = 0x1A6820u;
label_1a6820:
    // 0x1a6820: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a6820u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a6824: 0x24420a10  addiu       $v0, $v0, 0xA10
    ctx->pc = 0x1a6824u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2576));
    // 0x1a6828: 0x51b021  addu        $s6, $v0, $s1
    ctx->pc = 0x1a6828u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1a682c: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x1A682Cu;
    {
        const bool branch_taken_0x1a682c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A682Cu;
            // 0x1a6830: 0xa2c40000  sb          $a0, 0x0($s6) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a682c) {
            ctx->pc = 0x1A69D8u;
            goto label_1a69d8;
        }
    }
    ctx->pc = 0x1A6834u;
label_1a6834:
    // 0x1a6834: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6834u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6838: 0x24630a10  addiu       $v1, $v1, 0xA10
    ctx->pc = 0x1a6838u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2576));
    // 0x1a683c: 0x24840a11  addiu       $a0, $a0, 0xA11
    ctx->pc = 0x1a683cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2577));
    // 0x1a6840: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1a6840u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a6844: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1a6844u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a6848: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x1a6848u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1a684c: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1a684cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a6850: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1a6850u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6854: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a6854u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a6858: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6858u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a685c: 0x24e709a0  addiu       $a3, $a3, 0x9A0
    ctx->pc = 0x1a685cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2464));
    // 0x1a6860: 0x24840a14  addiu       $a0, $a0, 0xA14
    ctx->pc = 0x1a6860u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2580));
    // 0x1a6864: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x1a6864u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a6868: 0x912821  addu        $a1, $a0, $s1
    ctx->pc = 0x1a6868u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a686c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a686cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6870: 0xa0a00000  sb          $zero, 0x0($a1)
    ctx->pc = 0x1a6870u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6874: 0x24840a15  addiu       $a0, $a0, 0xA15
    ctx->pc = 0x1a6874u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2581));
    // 0x1a6878: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1a6878u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a687c: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1a687cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6880: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6880u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6884: 0x24840a1c  addiu       $a0, $a0, 0xA1C
    ctx->pc = 0x1a6884u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2588));
    // 0x1a6888: 0x912821  addu        $a1, $a0, $s1
    ctx->pc = 0x1a6888u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a688c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a688cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6890: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x1a6890u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x1a6894: 0x24840a20  addiu       $a0, $a0, 0xA20
    ctx->pc = 0x1a6894u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2592));
    // 0x1a6898: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1a6898u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a689c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1a689cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
label_1a68a0:
    // 0x1a68a0: 0x84e50000  lh          $a1, 0x0($a3)
    ctx->pc = 0x1a68a0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1a68a4: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1a68a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1a68a8: 0x84e40002  lh          $a0, 0x2($a3)
    ctx->pc = 0x1a68a8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x1a68ac: 0xa6850000  sh          $a1, 0x0($s4)
    ctx->pc = 0x1a68acu;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1a68b0: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x1a68b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1a68b4: 0xa6840002  sh          $a0, 0x2($s4)
    ctx->pc = 0x1a68b4u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a68b8: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A68B8u;
    {
        const bool branch_taken_0x1a68b8 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x1A68BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A68B8u;
            // 0x1a68bc: 0x26940004  addiu       $s4, $s4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a68b8) {
            ctx->pc = 0x1A68A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a68a0;
        }
    }
    ctx->pc = 0x1A68C0u;
    // 0x1a68c0: 0x1520c0  sll         $a0, $s5, 3
    ctx->pc = 0x1a68c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 21), 3));
    // 0x1a68c4: 0x3c06002b  lui         $a2, 0x2B
    ctx->pc = 0x1a68c4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)43 << 16));
    // 0x1a68c8: 0x952021  addu        $a0, $a0, $s5
    ctx->pc = 0x1a68c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 21)));
    // 0x1a68cc: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1a68ccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1a68d0: 0x43880  sll         $a3, $a0, 2
    ctx->pc = 0x1a68d0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a68d4: 0x24c60a32  addiu       $a2, $a2, 0xA32
    ctx->pc = 0x1a68d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2610));
    // 0x1a68d8: 0x24a50a31  addiu       $a1, $a1, 0xA31
    ctx->pc = 0x1a68d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2609));
    // 0x1a68dc: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1a68dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1a68e0: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1a68e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1a68e4: 0xa4c00000  sh          $zero, 0x0($a2)
    ctx->pc = 0x1a68e4u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a68e8: 0xa0a00000  sb          $zero, 0x0($a1)
    ctx->pc = 0x1a68e8u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a68ec: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a68ecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a68f0: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1a68f0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a68f4: 0x24840a30  addiu       $a0, $a0, 0xA30
    ctx->pc = 0x1a68f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2608));
    // 0x1a68f8: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1a68f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1a68fc: 0x10000197  b           . + 4 + (0x197 << 2)
    ctx->pc = 0x1A68FCu;
    {
        const bool branch_taken_0x1a68fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A68FCu;
            // 0x1a6900: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a68fc) {
            ctx->pc = 0x1A6F5Cu;
            goto label_1a6f5c;
        }
    }
    ctx->pc = 0x1A6904u;
label_1a6904:
    // 0x1a6904: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6904u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6908: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6908u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a690c: 0x24630a10  addiu       $v1, $v1, 0xA10
    ctx->pc = 0x1a690cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2576));
    // 0x1a6910: 0x24840a11  addiu       $a0, $a0, 0xA11
    ctx->pc = 0x1a6910u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2577));
    // 0x1a6914: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1a6914u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a6918: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1a6918u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a691c: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x1a691cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1a6920: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1a6920u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a6924: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1a6924u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6928: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a6928u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a692c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a692cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6930: 0x24e709a0  addiu       $a3, $a3, 0x9A0
    ctx->pc = 0x1a6930u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2464));
    // 0x1a6934: 0x24840a14  addiu       $a0, $a0, 0xA14
    ctx->pc = 0x1a6934u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2580));
    // 0x1a6938: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x1a6938u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a693c: 0x912821  addu        $a1, $a0, $s1
    ctx->pc = 0x1a693cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a6940: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6940u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6944: 0xa0a00000  sb          $zero, 0x0($a1)
    ctx->pc = 0x1a6944u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6948: 0x24840a15  addiu       $a0, $a0, 0xA15
    ctx->pc = 0x1a6948u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2581));
    // 0x1a694c: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1a694cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a6950: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1a6950u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6954: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6954u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6958: 0x24840a1c  addiu       $a0, $a0, 0xA1C
    ctx->pc = 0x1a6958u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2588));
    // 0x1a695c: 0x912821  addu        $a1, $a0, $s1
    ctx->pc = 0x1a695cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a6960: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6960u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6964: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x1a6964u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x1a6968: 0x24840a20  addiu       $a0, $a0, 0xA20
    ctx->pc = 0x1a6968u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2592));
    // 0x1a696c: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1a696cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a6970: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1a6970u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
label_1a6974:
    // 0x1a6974: 0x84e50000  lh          $a1, 0x0($a3)
    ctx->pc = 0x1a6974u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1a6978: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1a6978u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1a697c: 0x84e40002  lh          $a0, 0x2($a3)
    ctx->pc = 0x1a697cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x1a6980: 0xa6850000  sh          $a1, 0x0($s4)
    ctx->pc = 0x1a6980u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1a6984: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x1a6984u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1a6988: 0xa6840002  sh          $a0, 0x2($s4)
    ctx->pc = 0x1a6988u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a698c: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A698Cu;
    {
        const bool branch_taken_0x1a698c = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x1A6990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A698Cu;
            // 0x1a6990: 0x26940004  addiu       $s4, $s4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a698c) {
            ctx->pc = 0x1A6974u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a6974;
        }
    }
    ctx->pc = 0x1A6994u;
    // 0x1a6994: 0x1520c0  sll         $a0, $s5, 3
    ctx->pc = 0x1a6994u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 21), 3));
    // 0x1a6998: 0x3c06002b  lui         $a2, 0x2B
    ctx->pc = 0x1a6998u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)43 << 16));
    // 0x1a699c: 0x952021  addu        $a0, $a0, $s5
    ctx->pc = 0x1a699cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 21)));
    // 0x1a69a0: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1a69a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1a69a4: 0x43880  sll         $a3, $a0, 2
    ctx->pc = 0x1a69a4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a69a8: 0x24c60a32  addiu       $a2, $a2, 0xA32
    ctx->pc = 0x1a69a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2610));
    // 0x1a69ac: 0x24a50a31  addiu       $a1, $a1, 0xA31
    ctx->pc = 0x1a69acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2609));
    // 0x1a69b0: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1a69b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1a69b4: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1a69b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1a69b8: 0xa4c00000  sh          $zero, 0x0($a2)
    ctx->pc = 0x1a69b8u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a69bc: 0xa0a00000  sb          $zero, 0x0($a1)
    ctx->pc = 0x1a69bcu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a69c0: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a69c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a69c4: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1a69c4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a69c8: 0x24840a30  addiu       $a0, $a0, 0xA30
    ctx->pc = 0x1a69c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2608));
    // 0x1a69cc: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1a69ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1a69d0: 0x10000162  b           . + 4 + (0x162 << 2)
    ctx->pc = 0x1A69D0u;
    {
        const bool branch_taken_0x1a69d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A69D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A69D0u;
            // 0x1a69d4: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a69d0) {
            ctx->pc = 0x1A6F5Cu;
            goto label_1a6f5c;
        }
    }
    ctx->pc = 0x1A69D8u;
label_1a69d8:
    // 0x1a69d8: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a69d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a69dc: 0x24420a11  addiu       $v0, $v0, 0xA11
    ctx->pc = 0x1a69dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2577));
    // 0x1a69e0: 0x519021  addu        $s2, $v0, $s1
    ctx->pc = 0x1a69e0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1a69e4: 0x92420000  lbu         $v0, 0x0($s2)
    ctx->pc = 0x1a69e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1a69e8: 0x144000b7  bnez        $v0, . + 4 + (0xB7 << 2)
    ctx->pc = 0x1A69E8u;
    {
        const bool branch_taken_0x1a69e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A69ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A69E8u;
            // 0x1a69ec: 0x3c05002b  lui         $a1, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a69e8) {
            ctx->pc = 0x1A6CC8u;
            goto label_1a6cc8;
        }
    }
    ctx->pc = 0x1A69F0u;
    // 0x1a69f0: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1a69f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a69f4: 0x24a509a0  addiu       $a1, $a1, 0x9A0
    ctx->pc = 0x1a69f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2464));
label_1a69f8:
    // 0x1a69f8: 0x84a30000  lh          $v1, 0x0($a1)
    ctx->pc = 0x1a69f8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a69fc: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1a69fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1a6a00: 0x84a20002  lh          $v0, 0x2($a1)
    ctx->pc = 0x1a6a00u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1a6a04: 0xa6830000  sh          $v1, 0x0($s4)
    ctx->pc = 0x1a6a04u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a6a08: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1a6a08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1a6a0c: 0xa6820002  sh          $v0, 0x2($s4)
    ctx->pc = 0x1a6a0cu;
    WRITE16(ADD32(GPR_U32(ctx, 20), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a6a10: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A6A10u;
    {
        const bool branch_taken_0x1a6a10 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x1A6A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6A10u;
            // 0x1a6a14: 0x26940004  addiu       $s4, $s4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6a10) {
            ctx->pc = 0x1A69F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a69f8;
        }
    }
    ctx->pc = 0x1A6A18u;
    // 0x1a6a18: 0x92640000  lbu         $a0, 0x0($s3)
    ctx->pc = 0x1a6a18u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a6a1c: 0xc06016c  jal         func_1805B0
    ctx->pc = 0x1A6A1Cu;
    SET_GPR_U32(ctx, 31, 0x1A6A24u);
    ctx->pc = 0x1A6A20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6A1Cu;
            // 0x1a6a20: 0x27a500ac  addiu       $a1, $sp, 0xAC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 172));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1805B0u;
    if (runtime->hasFunction(0x1805B0u)) {
        auto targetFn = runtime->lookupFunction(0x1805B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6A24u; }
        if (ctx->pc != 0x1A6A24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001805B0_0x1805b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6A24u; }
        if (ctx->pc != 0x1A6A24u) { return; }
    }
    ctx->pc = 0x1A6A24u;
label_1a6a24:
    // 0x1a6a24: 0x440014d  bltz        $v0, . + 4 + (0x14D << 2)
    ctx->pc = 0x1A6A24u;
    {
        const bool branch_taken_0x1a6a24 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1a6a24) {
            ctx->pc = 0x1A6F5Cu;
            goto label_1a6f5c;
        }
    }
    ctx->pc = 0x1A6A2Cu;
    // 0x1a6a2c: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a6a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a6a30: 0x93a600af  lbu         $a2, 0xAF($sp)
    ctx->pc = 0x1a6a30u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 175)));
    // 0x1a6a34: 0x93a400ae  lbu         $a0, 0xAE($sp)
    ctx->pc = 0x1a6a34u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 174)));
    // 0x1a6a38: 0x24420a1c  addiu       $v0, $v0, 0xA1C
    ctx->pc = 0x1a6a38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2588));
    // 0x1a6a3c: 0x93a300ad  lbu         $v1, 0xAD($sp)
    ctx->pc = 0x1a6a3cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 173)));
    // 0x1a6a40: 0x518021  addu        $s0, $v0, $s1
    ctx->pc = 0x1a6a40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1a6a44: 0x93a200ac  lbu         $v0, 0xAC($sp)
    ctx->pc = 0x1a6a44u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x1a6a48: 0x63600  sll         $a2, $a2, 24
    ctx->pc = 0x1a6a48u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 24));
    // 0x1a6a4c: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1a6a4cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1a6a50: 0xc42025  or          $a0, $a2, $a0
    ctx->pc = 0x1a6a50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x1a6a54: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1a6a54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1a6a58: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1a6a58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1a6a5c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1a6a5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a6a60: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1a6a60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1a6a64: 0x92640000  lbu         $a0, 0x0($s3)
    ctx->pc = 0x1a6a64u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a6a68: 0xc062600  jal         func_189800
    ctx->pc = 0x1A6A68u;
    SET_GPR_U32(ctx, 31, 0x1A6A70u);
    ctx->pc = 0x1A6A6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6A68u;
            // 0x1a6a6c: 0x27a500a8  addiu       $a1, $sp, 0xA8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189800u;
    if (runtime->hasFunction(0x189800u)) {
        auto targetFn = runtime->lookupFunction(0x189800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6A70u; }
        if (ctx->pc != 0x1A6A70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189800_0x189800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6A70u; }
        if (ctx->pc != 0x1A6A70u) { return; }
    }
    ctx->pc = 0x1A6A70u;
label_1a6a70:
    // 0x1a6a70: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A6A70u;
    {
        const bool branch_taken_0x1a6a70 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1a6a70) {
            ctx->pc = 0x1A6A8Cu;
            goto label_1a6a8c;
        }
    }
    ctx->pc = 0x1A6A78u;
    // 0x1a6a78: 0x93a400a8  lbu         $a0, 0xA8($sp)
    ctx->pc = 0x1a6a78u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1a6a7c: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6a80: 0x24630a20  addiu       $v1, $v1, 0xA20
    ctx->pc = 0x1a6a80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2592));
    // 0x1a6a84: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1a6a84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a6a88: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1a6a88u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
label_1a6a8c:
    // 0x1a6a8c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1a6a8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a6a90: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x1a6a90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x1a6a94: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1a6a94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1a6a98: 0x10600011  beqz        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1A6A98u;
    {
        const bool branch_taken_0x1a6a98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6A98u;
            // 0x1a6a9c: 0x3c03002b  lui         $v1, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6a98) {
            ctx->pc = 0x1A6AE0u;
            goto label_1a6ae0;
        }
    }
    ctx->pc = 0x1A6AA0u;
    // 0x1a6aa0: 0x3c03fff0  lui         $v1, 0xFFF0
    ctx->pc = 0x1a6aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65520 << 16));
    // 0x1a6aa4: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1a6aa4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1a6aa8: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A6AA8u;
    {
        const bool branch_taken_0x1a6aa8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6aa8) {
            ctx->pc = 0x1A6AC8u;
            goto label_1a6ac8;
        }
    }
    ctx->pc = 0x1A6AB0u;
    // 0x1a6ab0: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6ab0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6ab4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1a6ab4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a6ab8: 0x24840a17  addiu       $a0, $a0, 0xA17
    ctx->pc = 0x1a6ab8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2583));
    // 0x1a6abc: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1a6abcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a6ac0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1A6AC0u;
    {
        const bool branch_taken_0x1a6ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6AC0u;
            // 0x1a6ac4: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6ac0) {
            ctx->pc = 0x1A6AECu;
            goto label_1a6aec;
        }
    }
    ctx->pc = 0x1A6AC8u;
label_1a6ac8:
    // 0x1a6ac8: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6ac8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6acc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a6accu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a6ad0: 0x24840a17  addiu       $a0, $a0, 0xA17
    ctx->pc = 0x1a6ad0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2583));
    // 0x1a6ad4: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1a6ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1a6ad8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A6AD8u;
    {
        const bool branch_taken_0x1a6ad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6AD8u;
            // 0x1a6adc: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6ad8) {
            ctx->pc = 0x1A6AECu;
            goto label_1a6aec;
        }
    }
    ctx->pc = 0x1A6AE0u;
label_1a6ae0:
    // 0x1a6ae0: 0x24630a17  addiu       $v1, $v1, 0xA17
    ctx->pc = 0x1a6ae0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2583));
    // 0x1a6ae4: 0x712021  addu        $a0, $v1, $s1
    ctx->pc = 0x1a6ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a6ae8: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1a6ae8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
label_1a6aec:
    // 0x1a6aec: 0x90840000  lbu         $a0, 0x0($a0)
    ctx->pc = 0x1a6aecu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a6af0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1a6af0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a6af4: 0x10830043  beq         $a0, $v1, . + 4 + (0x43 << 2)
    ctx->pc = 0x1A6AF4u;
    {
        const bool branch_taken_0x1a6af4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A6AF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6AF4u;
            // 0x1a6af8: 0x1518c0  sll         $v1, $s5, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 21), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6af4) {
            ctx->pc = 0x1A6C04u;
            goto label_1a6c04;
        }
    }
    ctx->pc = 0x1A6AFCu;
    // 0x1a6afc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1a6afcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a6b00: 0x10860022  beq         $a0, $a2, . + 4 + (0x22 << 2)
    ctx->pc = 0x1A6B00u;
    {
        const bool branch_taken_0x1a6b00 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        ctx->pc = 0x1A6B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6B00u;
            // 0x1a6b04: 0x1518c0  sll         $v1, $s5, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 21), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6b00) {
            ctx->pc = 0x1A6B8Cu;
            goto label_1a6b8c;
        }
    }
    ctx->pc = 0x1A6B08u;
    // 0x1a6b08: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A6B08u;
    {
        const bool branch_taken_0x1a6b08 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6B08u;
            // 0x1a6b0c: 0x1518c0  sll         $v1, $s5, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 21), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6b08) {
            ctx->pc = 0x1A6B18u;
            goto label_1a6b18;
        }
    }
    ctx->pc = 0x1A6B10u;
    // 0x1a6b10: 0x10000059  b           . + 4 + (0x59 << 2)
    ctx->pc = 0x1A6B10u;
    {
        const bool branch_taken_0x1a6b10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6b10) {
            ctx->pc = 0x1A6C78u;
            goto label_1a6c78;
        }
    }
    ctx->pc = 0x1A6B18u;
label_1a6b18:
    // 0x1a6b18: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6b18u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6b1c: 0x752821  addu        $a1, $v1, $s5
    ctx->pc = 0x1a6b1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 21)));
    // 0x1a6b20: 0x24840a32  addiu       $a0, $a0, 0xA32
    ctx->pc = 0x1a6b20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2610));
    // 0x1a6b24: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6b24u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6b28: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1a6b28u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1a6b2c: 0x24630a31  addiu       $v1, $v1, 0xA31
    ctx->pc = 0x1a6b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2609));
    // 0x1a6b30: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1a6b30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1a6b34: 0xa4860000  sh          $a2, 0x0($a0)
    ctx->pc = 0x1a6b34u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a6b38: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1a6b38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a6b3c: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1a6b3cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6b40: 0x1521c0  sll         $a0, $s5, 7
    ctx->pc = 0x1a6b40u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 21), 7));
    // 0x1a6b44: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6b44u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6b48: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1a6b48u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a6b4c: 0x24630900  addiu       $v1, $v1, 0x900
    ctx->pc = 0x1a6b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2304));
    // 0x1a6b50: 0x644021  addu        $t0, $v1, $a0
    ctx->pc = 0x1a6b50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a6b54: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1a6b54u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1a6b58: 0x24a510d0  addiu       $a1, $a1, 0x10D0
    ctx->pc = 0x1a6b58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4304));
label_1a6b5c:
    // 0x1a6b5c: 0x918c0  sll         $v1, $t1, 3
    ctx->pc = 0x1a6b5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x1a6b60: 0xa33821  addu        $a3, $a1, $v1
    ctx->pc = 0x1a6b60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a6b64: 0x1033021  addu        $a2, $t0, $v1
    ctx->pc = 0x1a6b64u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1a6b68: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x1a6b68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1a6b6c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1a6b6cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1a6b70: 0x29230010  slti        $v1, $t1, 0x10
    ctx->pc = 0x1a6b70u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1a6b74: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1a6b74u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1a6b78: 0x8ce40004  lw          $a0, 0x4($a3)
    ctx->pc = 0x1a6b78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1a6b7c: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A6B7Cu;
    {
        const bool branch_taken_0x1a6b7c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A6B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6B7Cu;
            // 0x1a6b80: 0xacc40004  sw          $a0, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6b7c) {
            ctx->pc = 0x1A6B5Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a6b5c;
        }
    }
    ctx->pc = 0x1A6B84u;
    // 0x1a6b84: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1A6B84u;
    {
        const bool branch_taken_0x1a6b84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6b84) {
            ctx->pc = 0x1A6C78u;
            goto label_1a6c78;
        }
    }
    ctx->pc = 0x1A6B8Cu;
label_1a6b8c:
    // 0x1a6b8c: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1a6b8cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1a6b90: 0x751821  addu        $v1, $v1, $s5
    ctx->pc = 0x1a6b90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 21)));
    // 0x1a6b94: 0x24a50a32  addiu       $a1, $a1, 0xA32
    ctx->pc = 0x1a6b94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2610));
    // 0x1a6b98: 0x33880  sll         $a3, $v1, 2
    ctx->pc = 0x1a6b98u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a6b9c: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x1a6b9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1a6ba0: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6ba0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6ba4: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1a6ba4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1a6ba8: 0x24630a31  addiu       $v1, $v1, 0xA31
    ctx->pc = 0x1a6ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2609));
    // 0x1a6bac: 0xa4a60000  sh          $a2, 0x0($a1)
    ctx->pc = 0x1a6bacu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a6bb0: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x1a6bb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1a6bb4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a6bb4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a6bb8: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x1a6bb8u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a6bbc: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6bbcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6bc0: 0x1521c0  sll         $a0, $s5, 7
    ctx->pc = 0x1a6bc0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 21), 7));
    // 0x1a6bc4: 0x24630900  addiu       $v1, $v1, 0x900
    ctx->pc = 0x1a6bc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2304));
    // 0x1a6bc8: 0x644821  addu        $t1, $v1, $a0
    ctx->pc = 0x1a6bc8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a6bcc: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1a6bccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1a6bd0: 0x24a51050  addiu       $a1, $a1, 0x1050
    ctx->pc = 0x1a6bd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4176));
label_1a6bd4:
    // 0x1a6bd4: 0x618c0  sll         $v1, $a2, 3
    ctx->pc = 0x1a6bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x1a6bd8: 0xa34021  addu        $t0, $a1, $v1
    ctx->pc = 0x1a6bd8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a6bdc: 0x1233821  addu        $a3, $t1, $v1
    ctx->pc = 0x1a6bdcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 3)));
    // 0x1a6be0: 0x8d040000  lw          $a0, 0x0($t0)
    ctx->pc = 0x1a6be0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a6be4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a6be4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a6be8: 0x28c30010  slti        $v1, $a2, 0x10
    ctx->pc = 0x1a6be8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1a6bec: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x1a6becu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x1a6bf0: 0x8d040004  lw          $a0, 0x4($t0)
    ctx->pc = 0x1a6bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x1a6bf4: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A6BF4u;
    {
        const bool branch_taken_0x1a6bf4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A6BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6BF4u;
            // 0x1a6bf8: 0xace40004  sw          $a0, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6bf4) {
            ctx->pc = 0x1A6BD4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a6bd4;
        }
    }
    ctx->pc = 0x1A6BFCu;
    // 0x1a6bfc: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1A6BFCu;
    {
        const bool branch_taken_0x1a6bfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6bfc) {
            ctx->pc = 0x1A6C78u;
            goto label_1a6c78;
        }
    }
    ctx->pc = 0x1A6C04u;
label_1a6c04:
    // 0x1a6c04: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1a6c04u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a6c08: 0x752021  addu        $a0, $v1, $s5
    ctx->pc = 0x1a6c08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 21)));
    // 0x1a6c0c: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6c10: 0x43880  sll         $a3, $a0, 2
    ctx->pc = 0x1a6c10u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a6c14: 0x24630a32  addiu       $v1, $v1, 0xA32
    ctx->pc = 0x1a6c14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2610));
    // 0x1a6c18: 0x24040073  addiu       $a0, $zero, 0x73
    ctx->pc = 0x1a6c18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
    // 0x1a6c1c: 0x672821  addu        $a1, $v1, $a3
    ctx->pc = 0x1a6c1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1a6c20: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6c20u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6c24: 0xa4a60000  sh          $a2, 0x0($a1)
    ctx->pc = 0x1a6c24u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a6c28: 0x24630a31  addiu       $v1, $v1, 0xA31
    ctx->pc = 0x1a6c28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2609));
    // 0x1a6c2c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a6c2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a6c30: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x1a6c30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1a6c34: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x1a6c34u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a6c38: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6c38u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6c3c: 0x1521c0  sll         $a0, $s5, 7
    ctx->pc = 0x1a6c3cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 21), 7));
    // 0x1a6c40: 0x24630900  addiu       $v1, $v1, 0x900
    ctx->pc = 0x1a6c40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2304));
    // 0x1a6c44: 0x644821  addu        $t1, $v1, $a0
    ctx->pc = 0x1a6c44u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a6c48: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1a6c48u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1a6c4c: 0x24a51050  addiu       $a1, $a1, 0x1050
    ctx->pc = 0x1a6c4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4176));
label_1a6c50:
    // 0x1a6c50: 0x618c0  sll         $v1, $a2, 3
    ctx->pc = 0x1a6c50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x1a6c54: 0xa34021  addu        $t0, $a1, $v1
    ctx->pc = 0x1a6c54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a6c58: 0x1233821  addu        $a3, $t1, $v1
    ctx->pc = 0x1a6c58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 3)));
    // 0x1a6c5c: 0x8d040000  lw          $a0, 0x0($t0)
    ctx->pc = 0x1a6c5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a6c60: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a6c60u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a6c64: 0x28c30010  slti        $v1, $a2, 0x10
    ctx->pc = 0x1a6c64u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1a6c68: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x1a6c68u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x1a6c6c: 0x8d040004  lw          $a0, 0x4($t0)
    ctx->pc = 0x1a6c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x1a6c70: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A6C70u;
    {
        const bool branch_taken_0x1a6c70 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A6C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6C70u;
            // 0x1a6c74: 0xace40004  sw          $a0, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6c70) {
            ctx->pc = 0x1A6C50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a6c50;
        }
    }
    ctx->pc = 0x1A6C78u;
label_1a6c78:
    // 0x1a6c78: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6c78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6c7c: 0x24630a20  addiu       $v1, $v1, 0xA20
    ctx->pc = 0x1a6c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2592));
    // 0x1a6c80: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1a6c80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a6c84: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1a6c84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a6c88: 0x30630003  andi        $v1, $v1, 0x3
    ctx->pc = 0x1a6c88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x1a6c8c: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A6C8Cu;
    {
        const bool branch_taken_0x1a6c8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A6C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6C8Cu;
            // 0x1a6c90: 0x3c03002b  lui         $v1, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6c8c) {
            ctx->pc = 0x1A6CA8u;
            goto label_1a6ca8;
        }
    }
    ctx->pc = 0x1A6C94u;
    // 0x1a6c94: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6c94u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6c98: 0x24630a15  addiu       $v1, $v1, 0xA15
    ctx->pc = 0x1a6c98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2581));
    // 0x1a6c9c: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1a6c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a6ca0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A6CA0u;
    {
        const bool branch_taken_0x1a6ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6CA0u;
            // 0x1a6ca4: 0xa0600000  sb          $zero, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6ca0) {
            ctx->pc = 0x1A6CB8u;
            goto label_1a6cb8;
        }
    }
    ctx->pc = 0x1A6CA8u;
label_1a6ca8:
    // 0x1a6ca8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1a6ca8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a6cac: 0x24630a15  addiu       $v1, $v1, 0xA15
    ctx->pc = 0x1a6cacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2581));
    // 0x1a6cb0: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1a6cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a6cb4: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x1a6cb4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
label_1a6cb8:
    // 0x1a6cb8: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1a6cb8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1a6cbc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a6cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a6cc0: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1A6CC0u;
    {
        const bool branch_taken_0x1a6cc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6CC0u;
            // 0x1a6cc4: 0xa2430000  sb          $v1, 0x0($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6cc0) {
            ctx->pc = 0x1A6F3Cu;
            goto label_1a6f3c;
        }
    }
    ctx->pc = 0x1A6CC8u;
label_1a6cc8:
    // 0x1a6cc8: 0x92640000  lbu         $a0, 0x0($s3)
    ctx->pc = 0x1a6cc8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a6ccc: 0xc060136  jal         func_1804D8
    ctx->pc = 0x1A6CCCu;
    SET_GPR_U32(ctx, 31, 0x1A6CD4u);
    ctx->pc = 0x1A6CD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6CCCu;
            // 0x1a6cd0: 0x27a50080  addiu       $a1, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1804D8u;
    if (runtime->hasFunction(0x1804D8u)) {
        auto targetFn = runtime->lookupFunction(0x1804D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6CD4u; }
        if (ctx->pc != 0x1A6CD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001804D8_0x1804d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6CD4u; }
        if (ctx->pc != 0x1A6CD4u) { return; }
    }
    ctx->pc = 0x1A6CD4u;
label_1a6cd4:
    // 0x1a6cd4: 0x44000a1  bltz        $v0, . + 4 + (0xA1 << 2)
    ctx->pc = 0x1A6CD4u;
    {
        const bool branch_taken_0x1a6cd4 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A6CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6CD4u;
            // 0x1a6cd8: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6cd4) {
            ctx->pc = 0x1A6F5Cu;
            goto label_1a6f5c;
        }
    }
    ctx->pc = 0x1A6CDCu;
    // 0x1a6cdc: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6ce0: 0x246309e1  addiu       $v1, $v1, 0x9E1
    ctx->pc = 0x1a6ce0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2529));
    // 0x1a6ce4: 0xa2c80000  sb          $t0, 0x0($s6)
    ctx->pc = 0x1a6ce4u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x1a6ce8: 0x702021  addu        $a0, $v1, $s0
    ctx->pc = 0x1a6ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a6cec: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1a6cecu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6cf0: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1a6cf0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a6cf4: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6cf8: 0x93a70080  lbu         $a3, 0x80($sp)
    ctx->pc = 0x1a6cf8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1a6cfc: 0x246309e2  addiu       $v1, $v1, 0x9E2
    ctx->pc = 0x1a6cfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2530));
    // 0x1a6d00: 0x93a60081  lbu         $a2, 0x81($sp)
    ctx->pc = 0x1a6d00u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 129)));
    // 0x1a6d04: 0x702821  addu        $a1, $v1, $s0
    ctx->pc = 0x1a6d04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a6d08: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6d08u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6d0c: 0x24630a17  addiu       $v1, $v1, 0xA17
    ctx->pc = 0x1a6d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2583));
    // 0x1a6d10: 0x712021  addu        $a0, $v1, $s1
    ctx->pc = 0x1a6d10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a6d14: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1a6d14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a6d18: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1a6d18u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1a6d1c: 0xe63025  or          $a2, $a3, $a2
    ctx->pc = 0x1a6d1cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1a6d20: 0xa4a60000  sh          $a2, 0x0($a1)
    ctx->pc = 0x1a6d20u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a6d24: 0x90840000  lbu         $a0, 0x0($a0)
    ctx->pc = 0x1a6d24u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a6d28: 0x1083001c  beq         $a0, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1A6D28u;
    {
        const bool branch_taken_0x1a6d28 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a6d28) {
            ctx->pc = 0x1A6D9Cu;
            goto label_1a6d9c;
        }
    }
    ctx->pc = 0x1A6D30u;
    // 0x1a6d30: 0x10880005  beq         $a0, $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A6D30u;
    {
        const bool branch_taken_0x1a6d30 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 8));
        if (branch_taken_0x1a6d30) {
            ctx->pc = 0x1A6D48u;
            goto label_1a6d48;
        }
    }
    ctx->pc = 0x1A6D38u;
    // 0x1a6d38: 0x10800073  beqz        $a0, . + 4 + (0x73 << 2)
    ctx->pc = 0x1A6D38u;
    {
        const bool branch_taken_0x1a6d38 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6d38) {
            ctx->pc = 0x1A6F08u;
            goto label_1a6f08;
        }
    }
    ctx->pc = 0x1A6D40u;
    // 0x1a6d40: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x1A6D40u;
    {
        const bool branch_taken_0x1a6d40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6D40u;
            // 0x1a6d44: 0x3c06002b  lui         $a2, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6d40) {
            ctx->pc = 0x1A6EE0u;
            goto label_1a6ee0;
        }
    }
    ctx->pc = 0x1A6D48u;
label_1a6d48:
    // 0x1a6d48: 0x93a70082  lbu         $a3, 0x82($sp)
    ctx->pc = 0x1a6d48u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 130)));
    // 0x1a6d4c: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6d50: 0x246309e4  addiu       $v1, $v1, 0x9E4
    ctx->pc = 0x1a6d50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2532));
    // 0x1a6d54: 0x703021  addu        $a2, $v1, $s0
    ctx->pc = 0x1a6d54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a6d58: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6d58u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6d5c: 0x246309e5  addiu       $v1, $v1, 0x9E5
    ctx->pc = 0x1a6d5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2533));
    // 0x1a6d60: 0x702821  addu        $a1, $v1, $s0
    ctx->pc = 0x1a6d60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a6d64: 0xa0c70000  sb          $a3, 0x0($a2)
    ctx->pc = 0x1a6d64u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0x1a6d68: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6d68u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6d6c: 0x93a60083  lbu         $a2, 0x83($sp)
    ctx->pc = 0x1a6d6cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 131)));
    // 0x1a6d70: 0x246309e6  addiu       $v1, $v1, 0x9E6
    ctx->pc = 0x1a6d70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2534));
    // 0x1a6d74: 0x702021  addu        $a0, $v1, $s0
    ctx->pc = 0x1a6d74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a6d78: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6d78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6d7c: 0x246309e7  addiu       $v1, $v1, 0x9E7
    ctx->pc = 0x1a6d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2535));
    // 0x1a6d80: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1a6d80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a6d84: 0xa0a60000  sb          $a2, 0x0($a1)
    ctx->pc = 0x1a6d84u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1a6d88: 0x93a50084  lbu         $a1, 0x84($sp)
    ctx->pc = 0x1a6d88u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 132)));
    // 0x1a6d8c: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1a6d8cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1a6d90: 0x93a40085  lbu         $a0, 0x85($sp)
    ctx->pc = 0x1a6d90u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 133)));
    // 0x1a6d94: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x1A6D94u;
    {
        const bool branch_taken_0x1a6d94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6D94u;
            // 0x1a6d98: 0xa0640000  sb          $a0, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6d94) {
            ctx->pc = 0x1A6F08u;
            goto label_1a6f08;
        }
    }
    ctx->pc = 0x1A6D9Cu;
label_1a6d9c:
    // 0x1a6d9c: 0x93a60082  lbu         $a2, 0x82($sp)
    ctx->pc = 0x1a6d9cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 130)));
    // 0x1a6da0: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6da0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6da4: 0x246309e4  addiu       $v1, $v1, 0x9E4
    ctx->pc = 0x1a6da4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2532));
    // 0x1a6da8: 0x3c0d002b  lui         $t5, 0x2B
    ctx->pc = 0x1a6da8u;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)43 << 16));
    // 0x1a6dac: 0x702821  addu        $a1, $v1, $s0
    ctx->pc = 0x1a6dacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a6db0: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6db0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6db4: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6db4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6db8: 0x248409e6  addiu       $a0, $a0, 0x9E6
    ctx->pc = 0x1a6db8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2534));
    // 0x1a6dbc: 0x246309e5  addiu       $v1, $v1, 0x9E5
    ctx->pc = 0x1a6dbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2533));
    // 0x1a6dc0: 0x906021  addu        $t4, $a0, $s0
    ctx->pc = 0x1a6dc0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6dc4: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6dc4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6dc8: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1a6dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a6dcc: 0xa0a60000  sb          $a2, 0x0($a1)
    ctx->pc = 0x1a6dccu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1a6dd0: 0x248409e7  addiu       $a0, $a0, 0x9E7
    ctx->pc = 0x1a6dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2535));
    // 0x1a6dd4: 0x93ae0083  lbu         $t6, 0x83($sp)
    ctx->pc = 0x1a6dd4u;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 131)));
    // 0x1a6dd8: 0x905821  addu        $t3, $a0, $s0
    ctx->pc = 0x1a6dd8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6ddc: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6ddcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6de0: 0x25ad09ef  addiu       $t5, $t5, 0x9EF
    ctx->pc = 0x1a6de0u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 2543));
    // 0x1a6de4: 0x248409e8  addiu       $a0, $a0, 0x9E8
    ctx->pc = 0x1a6de4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2536));
    // 0x1a6de8: 0x905021  addu        $t2, $a0, $s0
    ctx->pc = 0x1a6de8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6dec: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6decu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6df0: 0x248409e9  addiu       $a0, $a0, 0x9E9
    ctx->pc = 0x1a6df0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2537));
    // 0x1a6df4: 0xa06e0000  sb          $t6, 0x0($v1)
    ctx->pc = 0x1a6df4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 14));
    // 0x1a6df8: 0x904821  addu        $t1, $a0, $s0
    ctx->pc = 0x1a6df8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6dfc: 0x1b01821  addu        $v1, $t5, $s0
    ctx->pc = 0x1a6dfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 16)));
    // 0x1a6e00: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6e00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e04: 0x93ad0084  lbu         $t5, 0x84($sp)
    ctx->pc = 0x1a6e04u;
    SET_GPR_U32(ctx, 13, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 132)));
    // 0x1a6e08: 0x248409ea  addiu       $a0, $a0, 0x9EA
    ctx->pc = 0x1a6e08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2538));
    // 0x1a6e0c: 0x904021  addu        $t0, $a0, $s0
    ctx->pc = 0x1a6e0cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6e10: 0x3c0e002b  lui         $t6, 0x2B
    ctx->pc = 0x1a6e10u;
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e14: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6e14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e18: 0x25ce09f0  addiu       $t6, $t6, 0x9F0
    ctx->pc = 0x1a6e18u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 2544));
    // 0x1a6e1c: 0x248409eb  addiu       $a0, $a0, 0x9EB
    ctx->pc = 0x1a6e1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2539));
    // 0x1a6e20: 0x1d09821  addu        $s3, $t6, $s0
    ctx->pc = 0x1a6e20u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 16)));
    // 0x1a6e24: 0x903821  addu        $a3, $a0, $s0
    ctx->pc = 0x1a6e24u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6e28: 0x3c0e002b  lui         $t6, 0x2B
    ctx->pc = 0x1a6e28u;
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e2c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6e2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e30: 0x25ce09f1  addiu       $t6, $t6, 0x9F1
    ctx->pc = 0x1a6e30u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 2545));
    // 0x1a6e34: 0xa18d0000  sb          $t5, 0x0($t4)
    ctx->pc = 0x1a6e34u;
    WRITE8(ADD32(GPR_U32(ctx, 12), 0), (uint8_t)GPR_U32(ctx, 13));
    // 0x1a6e38: 0x248409ec  addiu       $a0, $a0, 0x9EC
    ctx->pc = 0x1a6e38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2540));
    // 0x1a6e3c: 0x93ac0085  lbu         $t4, 0x85($sp)
    ctx->pc = 0x1a6e3cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 133)));
    // 0x1a6e40: 0x903021  addu        $a2, $a0, $s0
    ctx->pc = 0x1a6e40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6e44: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6e44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e48: 0x1d09021  addu        $s2, $t6, $s0
    ctx->pc = 0x1a6e48u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 16)));
    // 0x1a6e4c: 0x248409ed  addiu       $a0, $a0, 0x9ED
    ctx->pc = 0x1a6e4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2541));
    // 0x1a6e50: 0x3c0e002b  lui         $t6, 0x2B
    ctx->pc = 0x1a6e50u;
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e54: 0x902821  addu        $a1, $a0, $s0
    ctx->pc = 0x1a6e54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6e58: 0x25ce09f2  addiu       $t6, $t6, 0x9F2
    ctx->pc = 0x1a6e58u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 2546));
    // 0x1a6e5c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a6e5cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e60: 0x1d07821  addu        $t7, $t6, $s0
    ctx->pc = 0x1a6e60u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 16)));
    // 0x1a6e64: 0x248409ee  addiu       $a0, $a0, 0x9EE
    ctx->pc = 0x1a6e64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2542));
    // 0x1a6e68: 0x3c0e002b  lui         $t6, 0x2B
    ctx->pc = 0x1a6e68u;
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)43 << 16));
    // 0x1a6e6c: 0xa16c0000  sb          $t4, 0x0($t3)
    ctx->pc = 0x1a6e6cu;
    WRITE8(ADD32(GPR_U32(ctx, 11), 0), (uint8_t)GPR_U32(ctx, 12));
    // 0x1a6e70: 0x25ce09f3  addiu       $t6, $t6, 0x9F3
    ctx->pc = 0x1a6e70u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 2547));
    // 0x1a6e74: 0x93ab0086  lbu         $t3, 0x86($sp)
    ctx->pc = 0x1a6e74u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 134)));
    // 0x1a6e78: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x1a6e78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1a6e7c: 0x1d07021  addu        $t6, $t6, $s0
    ctx->pc = 0x1a6e7cu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 16)));
    // 0x1a6e80: 0xa14b0000  sb          $t3, 0x0($t2)
    ctx->pc = 0x1a6e80u;
    WRITE8(ADD32(GPR_U32(ctx, 10), 0), (uint8_t)GPR_U32(ctx, 11));
    // 0x1a6e84: 0x93aa0087  lbu         $t2, 0x87($sp)
    ctx->pc = 0x1a6e84u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 135)));
    // 0x1a6e88: 0xa12a0000  sb          $t2, 0x0($t1)
    ctx->pc = 0x1a6e88u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 10));
    // 0x1a6e8c: 0x93a90088  lbu         $t1, 0x88($sp)
    ctx->pc = 0x1a6e8cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x1a6e90: 0xa1090000  sb          $t1, 0x0($t0)
    ctx->pc = 0x1a6e90u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 9));
    // 0x1a6e94: 0x93a80089  lbu         $t0, 0x89($sp)
    ctx->pc = 0x1a6e94u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 137)));
    // 0x1a6e98: 0xa0e80000  sb          $t0, 0x0($a3)
    ctx->pc = 0x1a6e98u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x1a6e9c: 0x93a7008a  lbu         $a3, 0x8A($sp)
    ctx->pc = 0x1a6e9cu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1a6ea0: 0xa0c70000  sb          $a3, 0x0($a2)
    ctx->pc = 0x1a6ea0u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0x1a6ea4: 0x93a6008b  lbu         $a2, 0x8B($sp)
    ctx->pc = 0x1a6ea4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 139)));
    // 0x1a6ea8: 0xa0a60000  sb          $a2, 0x0($a1)
    ctx->pc = 0x1a6ea8u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1a6eac: 0x93a5008c  lbu         $a1, 0x8C($sp)
    ctx->pc = 0x1a6eacu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 140)));
    // 0x1a6eb0: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1a6eb0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1a6eb4: 0x93a4008d  lbu         $a0, 0x8D($sp)
    ctx->pc = 0x1a6eb4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 141)));
    // 0x1a6eb8: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x1a6eb8u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a6ebc: 0x93a3008e  lbu         $v1, 0x8E($sp)
    ctx->pc = 0x1a6ebcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 142)));
    // 0x1a6ec0: 0xa2630000  sb          $v1, 0x0($s3)
    ctx->pc = 0x1a6ec0u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a6ec4: 0x93a3008f  lbu         $v1, 0x8F($sp)
    ctx->pc = 0x1a6ec4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 143)));
    // 0x1a6ec8: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x1a6ec8u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a6ecc: 0x93a30090  lbu         $v1, 0x90($sp)
    ctx->pc = 0x1a6eccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1a6ed0: 0xa1e30000  sb          $v1, 0x0($t7)
    ctx->pc = 0x1a6ed0u;
    WRITE8(ADD32(GPR_U32(ctx, 15), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a6ed4: 0x93a30091  lbu         $v1, 0x91($sp)
    ctx->pc = 0x1a6ed4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 145)));
    // 0x1a6ed8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A6ED8u;
    {
        const bool branch_taken_0x1a6ed8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A6EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6ED8u;
            // 0x1a6edc: 0xa1c30000  sb          $v1, 0x0($t6) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 14), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6ed8) {
            ctx->pc = 0x1A6F08u;
            goto label_1a6f08;
        }
    }
    ctx->pc = 0x1A6EE0u;
label_1a6ee0:
    // 0x1a6ee0: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1a6ee0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a6ee4: 0x24c609a0  addiu       $a2, $a2, 0x9A0
    ctx->pc = 0x1a6ee4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2464));
label_1a6ee8:
    // 0x1a6ee8: 0x84c40000  lh          $a0, 0x0($a2)
    ctx->pc = 0x1a6ee8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1a6eec: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a6eecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a6ef0: 0x84c30002  lh          $v1, 0x2($a2)
    ctx->pc = 0x1a6ef0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 2)));
    // 0x1a6ef4: 0xa6840000  sh          $a0, 0x0($s4)
    ctx->pc = 0x1a6ef4u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a6ef8: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1a6ef8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1a6efc: 0xa6830002  sh          $v1, 0x2($s4)
    ctx->pc = 0x1a6efcu;
    WRITE16(ADD32(GPR_U32(ctx, 20), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a6f00: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A6F00u;
    {
        const bool branch_taken_0x1a6f00 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x1A6F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6F00u;
            // 0x1a6f04: 0x26940004  addiu       $s4, $s4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6f00) {
            ctx->pc = 0x1A6EE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a6ee8;
        }
    }
    ctx->pc = 0x1A6F08u;
label_1a6f08:
    // 0x1a6f08: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6f08u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6f0c: 0x24630a24  addiu       $v1, $v1, 0xA24
    ctx->pc = 0x1a6f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2596));
    // 0x1a6f10: 0x712021  addu        $a0, $v1, $s1
    ctx->pc = 0x1a6f10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1a6f14: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1a6f14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a6f18: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A6F18u;
    {
        const bool branch_taken_0x1a6f18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a6f18) {
            ctx->pc = 0x1A6F3Cu;
            goto label_1a6f3c;
        }
    }
    ctx->pc = 0x1A6F20u;
    // 0x1a6f20: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a6f20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a6f24: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A6F24u;
    {
        const bool branch_taken_0x1a6f24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A6F28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6F24u;
            // 0x1a6f28: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a6f24) {
            ctx->pc = 0x1A6F3Cu;
            goto label_1a6f3c;
        }
    }
    ctx->pc = 0x1A6F2Cu;
    // 0x1a6f2c: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1a6f2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a6f30: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a6f30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a6f34: 0xc069be4  jal         func_1A6F90
    ctx->pc = 0x1A6F34u;
    SET_GPR_U32(ctx, 31, 0x1A6F3Cu);
    ctx->pc = 0x1A6F38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6F34u;
            // 0x1a6f38: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A6F90u;
    if (runtime->hasFunction(0x1A6F90u)) {
        auto targetFn = runtime->lookupFunction(0x1A6F90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6F3Cu; }
        if (ctx->pc != 0x1A6F3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6F90_0x1a6f90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A6F3Cu; }
        if (ctx->pc != 0x1A6F3Cu) { return; }
    }
    ctx->pc = 0x1A6F3Cu;
label_1a6f3c:
    // 0x1a6f3c: 0x92c50000  lbu         $a1, 0x0($s6)
    ctx->pc = 0x1a6f3cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1a6f40: 0x1518c0  sll         $v1, $s5, 3
    ctx->pc = 0x1a6f40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 21), 3));
    // 0x1a6f44: 0x752021  addu        $a0, $v1, $s5
    ctx->pc = 0x1a6f44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 21)));
    // 0x1a6f48: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a6f48u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a6f4c: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1a6f4cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a6f50: 0x24630a30  addiu       $v1, $v1, 0xA30
    ctx->pc = 0x1a6f50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2608));
    // 0x1a6f54: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a6f54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a6f58: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x1a6f58u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
label_1a6f5c:
    // 0x1a6f5c: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1a6f5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1a6f60: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1a6f60u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1a6f64: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1a6f64u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1a6f68: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1a6f68u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a6f6c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a6f6cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a6f70: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a6f70u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a6f74: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a6f74u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a6f78: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a6f78u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a6f7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A6F7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A6F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A6F7Cu;
            // 0x1a6f80: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A67ACu: goto label_1a67ac;
            case 0x1A67ECu: goto label_1a67ec;
            case 0x1A6820u: goto label_1a6820;
            case 0x1A6834u: goto label_1a6834;
            case 0x1A68A0u: goto label_1a68a0;
            case 0x1A6904u: goto label_1a6904;
            case 0x1A6974u: goto label_1a6974;
            case 0x1A69D8u: goto label_1a69d8;
            case 0x1A69F8u: goto label_1a69f8;
            case 0x1A6A24u: goto label_1a6a24;
            case 0x1A6A70u: goto label_1a6a70;
            case 0x1A6A8Cu: goto label_1a6a8c;
            case 0x1A6AC8u: goto label_1a6ac8;
            case 0x1A6AE0u: goto label_1a6ae0;
            case 0x1A6AECu: goto label_1a6aec;
            case 0x1A6B18u: goto label_1a6b18;
            case 0x1A6B5Cu: goto label_1a6b5c;
            case 0x1A6B8Cu: goto label_1a6b8c;
            case 0x1A6BD4u: goto label_1a6bd4;
            case 0x1A6C04u: goto label_1a6c04;
            case 0x1A6C50u: goto label_1a6c50;
            case 0x1A6C78u: goto label_1a6c78;
            case 0x1A6CA8u: goto label_1a6ca8;
            case 0x1A6CB8u: goto label_1a6cb8;
            case 0x1A6CC8u: goto label_1a6cc8;
            case 0x1A6CD4u: goto label_1a6cd4;
            case 0x1A6D48u: goto label_1a6d48;
            case 0x1A6D9Cu: goto label_1a6d9c;
            case 0x1A6EE0u: goto label_1a6ee0;
            case 0x1A6EE8u: goto label_1a6ee8;
            case 0x1A6F08u: goto label_1a6f08;
            case 0x1A6F3Cu: goto label_1a6f3c;
            case 0x1A6F5Cu: goto label_1a6f5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A6F84u;
    // 0x1a6f84: 0x0  nop
    ctx->pc = 0x1a6f84u;
    // NOP
    // 0x1a6f88: 0x0  nop
    ctx->pc = 0x1a6f88u;
    // NOP
    // 0x1a6f8c: 0x0  nop
    ctx->pc = 0x1a6f8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
