#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001227C0
// Address: 0x1227c0 - 0x1228ec
void sub_001227C0_0x1227c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001227C0_0x1227c0");
#endif

    switch (ctx->pc) {
        case 0x122800u: goto label_122800;
        case 0x122838u: goto label_122838;
        case 0x122860u: goto label_122860;
        case 0x1228c8u: goto label_1228c8;
        default: break;
    }

    ctx->pc = 0x1227c0u;

    // 0x1227c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1227c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1227c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1227c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1227c8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1227c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1227cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1227ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1227d0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1227d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1227d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1227d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1227d8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1227d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1227dc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1227dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1227e0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1227e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1227e4: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x1227e4u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x1227e8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1227e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1227ec: 0x2683b418  addiu       $v1, $s4, -0x4BE8
    ctx->pc = 0x1227ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 4294947864));
    // 0x1227f0: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x1227f0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1227f4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1227F4u;
    {
        const bool branch_taken_0x1227f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1227F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1227F4u;
            // 0x1227f8: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1227f4) {
            ctx->pc = 0x122824u;
            goto label_122824;
        }
    }
    ctx->pc = 0x1227FCu;
    // 0x1227fc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1227fcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_122800:
    // 0x122800: 0x2a020010  slti        $v0, $s0, 0x10
    ctx->pc = 0x122800u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x122804: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x122804u;
    {
        const bool branch_taken_0x122804 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x122808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122804u;
            // 0x122808: 0x24630030  addiu       $v1, $v1, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122804) {
            ctx->pc = 0x122824u;
            goto label_122824;
        }
    }
    ctx->pc = 0x12280Cu;
    // 0x12280c: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12280cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x122810: 0x0  nop
    ctx->pc = 0x122810u;
    // NOP
    // 0x122814: 0x0  nop
    ctx->pc = 0x122814u;
    // NOP
    // 0x122818: 0x0  nop
    ctx->pc = 0x122818u;
    // NOP
    // 0x12281c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x12281Cu;
    {
        const bool branch_taken_0x12281c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12281c) {
            ctx->pc = 0x122820u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12281Cu;
            // 0x122820: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122800u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122800;
        }
    }
    ctx->pc = 0x122824u;
label_122824:
    // 0x122824: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x122824u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x122828: 0x12030028  beq         $s0, $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x122828u;
    {
        const bool branch_taken_0x122828 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x12282Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122828u;
            // 0x12282c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122828) {
            ctx->pc = 0x1228CCu;
            goto label_1228cc;
        }
    }
    ctx->pc = 0x122830u;
    // 0x122830: 0xc049938  jal         func_1264E0
    ctx->pc = 0x122830u;
    SET_GPR_U32(ctx, 31, 0x122838u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122838u; }
        if (ctx->pc != 0x122838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122838u; }
        if (ctx->pc != 0x122838u) { return; }
    }
    ctx->pc = 0x122838u;
label_122838:
    // 0x122838: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x122838u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x12283c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x12283cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x122840: 0x2683b418  addiu       $v1, $s4, -0x4BE8
    ctx->pc = 0x122840u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 4294947864));
    // 0x122844: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x122844u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x122848: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x122848u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12284c: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x12284cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x122850: 0x1a200010  blez        $s1, . + 4 + (0x10 << 2)
    ctx->pc = 0x122850u;
    {
        const bool branch_taken_0x122850 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x122854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122850u;
            // 0x122854: 0xa2110002  sb          $s1, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122850) {
            ctx->pc = 0x122894u;
            goto label_122894;
        }
    }
    ctx->pc = 0x122858u;
    // 0x122858: 0x2609000c  addiu       $t1, $s0, 0xC
    ctx->pc = 0x122858u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x12285c: 0x26070004  addiu       $a3, $s0, 0x4
    ctx->pc = 0x12285cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
label_122860:
    // 0x122860: 0x81880  sll         $v1, $t0, 2
    ctx->pc = 0x122860u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x122864: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x122864u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x122868: 0x731021  addu        $v0, $v1, $s3
    ctx->pc = 0x122868u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x12286c: 0x723021  addu        $a2, $v1, $s2
    ctx->pc = 0x12286cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x122870: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x122870u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x122874: 0x111282a  slt         $a1, $t0, $s1
    ctx->pc = 0x122874u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x122878: 0x1231821  addu        $v1, $t1, $v1
    ctx->pc = 0x122878u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 3)));
    // 0x12287c: 0xace00010  sw          $zero, 0x10($a3)
    ctx->pc = 0x12287cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 16), GPR_U32(ctx, 0));
    // 0x122880: 0xace40000  sw          $a0, 0x0($a3)
    ctx->pc = 0x122880u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x122884: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x122884u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x122888: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x122888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12288c: 0x14a0fff4  bnez        $a1, . + 4 + (-0xC << 2)
    ctx->pc = 0x12288Cu;
    {
        const bool branch_taken_0x12288c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x122890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12288Cu;
            // 0x122890: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12288c) {
            ctx->pc = 0x122860u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122860;
        }
    }
    ctx->pc = 0x122894u;
label_122894:
    // 0x122894: 0x3c013dcc  lui         $at, 0x3DCC
    ctx->pc = 0x122894u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15820 << 16));
    // 0x122898: 0x3421cccc  ori         $at, $at, 0xCCCC
    ctx->pc = 0x122898u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)52428);
    // 0x12289c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x12289cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1228a0: 0x3402ac44  ori         $v0, $zero, 0xAC44
    ctx->pc = 0x1228a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)44100);
    // 0x1228a4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1228a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1228a8: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x1228a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x1228ac: 0xae11001c  sw          $s1, 0x1C($s0)
    ctx->pc = 0x1228acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 17));
    // 0x1228b0: 0xe6000028  swc1        $f0, 0x28($s0)
    ctx->pc = 0x1228b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 40), bits); }
    // 0x1228b4: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1228b4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1228b8: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1228b8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1228bc: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1228bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1228c0: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x1228C0u;
    SET_GPR_U32(ctx, 31, 0x1228C8u);
    ctx->pc = 0x1228C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1228C0u;
            // 0x1228c4: 0xe6000024  swc1        $f0, 0x24($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 36), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1228C8u; }
        if (ctx->pc != 0x1228C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1228C8u; }
        if (ctx->pc != 0x1228C8u) { return; }
    }
    ctx->pc = 0x1228C8u;
label_1228c8:
    // 0x1228c8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1228c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1228cc:
    // 0x1228cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1228ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1228d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1228d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1228d4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1228d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1228d8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1228d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1228dc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1228dcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1228e0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1228e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1228e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1228E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1228E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1228E4u;
            // 0x1228e8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122800u: goto label_122800;
            case 0x122824u: goto label_122824;
            case 0x122838u: goto label_122838;
            case 0x122860u: goto label_122860;
            case 0x122894u: goto label_122894;
            case 0x1228C8u: goto label_1228c8;
            case 0x1228CCu: goto label_1228cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1228ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
