#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124860
// Address: 0x124860 - 0x1249a0
void sub_00124860_0x124860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124860_0x124860");
#endif

    switch (ctx->pc) {
        case 0x1248a8u: goto label_1248a8;
        case 0x124904u: goto label_124904;
        case 0x124910u: goto label_124910;
        case 0x124920u: goto label_124920;
        case 0x12497cu: goto label_12497c;
        default: break;
    }

    ctx->pc = 0x124860u;

    // 0x124860: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x124860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x124864: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x124864u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x124868: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x124868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12486c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x12486cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124870: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x124870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x124874: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x124874u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124878: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x124878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12487c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x12487cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124880: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x124880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x124884: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x124884u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124888: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x124888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12488c: 0x2503b958  addiu       $v1, $t0, -0x46A8
    ctx->pc = 0x12488cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 4294949208));
    // 0x124890: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x124890u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x124894: 0x84620000  lh          $v0, 0x0($v1)
    ctx->pc = 0x124894u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x124898: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x124898u;
    {
        const bool branch_taken_0x124898 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12489Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124898u;
            // 0x12489c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124898) {
            ctx->pc = 0x1248CCu;
            goto label_1248cc;
        }
    }
    ctx->pc = 0x1248A0u;
    // 0x1248a0: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1248a0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1248a4: 0x0  nop
    ctx->pc = 0x1248a4u;
    // NOP
label_1248a8:
    // 0x1248a8: 0x28e20010  slti        $v0, $a3, 0x10
    ctx->pc = 0x1248a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1248ac: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1248ACu;
    {
        const bool branch_taken_0x1248ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1248B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1248ACu;
            // 0x1248b0: 0x246300e4  addiu       $v1, $v1, 0xE4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 228));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1248ac) {
            ctx->pc = 0x1248CCu;
            goto label_1248cc;
        }
    }
    ctx->pc = 0x1248B4u;
    // 0x1248b4: 0x84620000  lh          $v0, 0x0($v1)
    ctx->pc = 0x1248b4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1248b8: 0x0  nop
    ctx->pc = 0x1248b8u;
    // NOP
    // 0x1248bc: 0x0  nop
    ctx->pc = 0x1248bcu;
    // NOP
    // 0x1248c0: 0x0  nop
    ctx->pc = 0x1248c0u;
    // NOP
    // 0x1248c4: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1248C4u;
    {
        const bool branch_taken_0x1248c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1248c4) {
            ctx->pc = 0x1248C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1248C4u;
            // 0x1248c8: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1248A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1248a8;
        }
    }
    ctx->pc = 0x1248CCu;
label_1248cc:
    // 0x1248cc: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1248ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1248d0: 0x10e3002b  beq         $a3, $v1, . + 4 + (0x2B << 2)
    ctx->pc = 0x1248D0u;
    {
        const bool branch_taken_0x1248d0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 3));
        ctx->pc = 0x1248D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1248D0u;
            // 0x1248d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1248d0) {
            ctx->pc = 0x124980u;
            goto label_124980;
        }
    }
    ctx->pc = 0x1248D8u;
    // 0x1248d8: 0x710c0  sll         $v0, $a3, 3
    ctx->pc = 0x1248d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x1248dc: 0x2503b958  addiu       $v1, $t0, -0x46A8
    ctx->pc = 0x1248dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 4294949208));
    // 0x1248e0: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x1248e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1248e4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1248e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1248e8: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1248e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1248ec: 0x240600e4  addiu       $a2, $zero, 0xE4
    ctx->pc = 0x1248ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 228));
    // 0x1248f0: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1248f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1248f4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1248f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1248f8: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1248f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1248fc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1248FCu;
    SET_GPR_U32(ctx, 31, 0x124904u);
    ctx->pc = 0x124900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1248FCu;
            // 0x124900: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124904u; }
        if (ctx->pc != 0x124904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124904u; }
        if (ctx->pc != 0x124904u) { return; }
    }
    ctx->pc = 0x124904u;
label_124904:
    // 0x124904: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x124904u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x124908: 0xc04d378  jal         func_134DE0
    ctx->pc = 0x124908u;
    SET_GPR_U32(ctx, 31, 0x124910u);
    ctx->pc = 0x12490Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124908u;
            // 0x12490c: 0xa6030000  sh          $v1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134DE0u;
    if (runtime->hasFunction(0x134DE0u)) {
        auto targetFn = runtime->lookupFunction(0x134DE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124910u; }
        if (ctx->pc != 0x124910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134DE0_0x134de0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124910u; }
        if (ctx->pc != 0x124910u) { return; }
    }
    ctx->pc = 0x124910u;
label_124910:
    // 0x124910: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x124910u;
    {
        const bool branch_taken_0x124910 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x124914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124910u;
            // 0x124914: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124910) {
            ctx->pc = 0x124928u;
            goto label_124928;
        }
    }
    ctx->pc = 0x124918u;
    // 0x124918: 0xc049268  jal         func_1249A0
    ctx->pc = 0x124918u;
    SET_GPR_U32(ctx, 31, 0x124920u);
    ctx->pc = 0x12491Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124918u;
            // 0x12491c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1249A0u;
    if (runtime->hasFunction(0x1249A0u)) {
        auto targetFn = runtime->lookupFunction(0x1249A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124920u; }
        if (ctx->pc != 0x124920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001249A0_0x1249a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124920u; }
        if (ctx->pc != 0x124920u) { return; }
    }
    ctx->pc = 0x124920u;
label_124920:
    // 0x124920: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x124920u;
    {
        const bool branch_taken_0x124920 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x124924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124920u;
            // 0x124924: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124920) {
            ctx->pc = 0x124980u;
            goto label_124980;
        }
    }
    ctx->pc = 0x124928u;
label_124928:
    // 0x124928: 0x3c020012  lui         $v0, 0x12
    ctx->pc = 0x124928u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)18 << 16));
    // 0x12492c: 0x3c030012  lui         $v1, 0x12
    ctx->pc = 0x12492cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)18 << 16));
    // 0x124930: 0x2407ff80  addiu       $a3, $zero, -0x80
    ctx->pc = 0x124930u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x124934: 0x24424810  addiu       $v0, $v0, 0x4810
    ctx->pc = 0x124934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18448));
    // 0x124938: 0x24634840  addiu       $v1, $v1, 0x4840
    ctx->pc = 0x124938u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 18496));
    // 0x12493c: 0xae140038  sw          $s4, 0x38($s0)
    ctx->pc = 0x12493cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 20));
    // 0x124940: 0xae13003c  sw          $s3, 0x3C($s0)
    ctx->pc = 0x124940u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 19));
    // 0x124944: 0x260400cc  addiu       $a0, $s0, 0xCC
    ctx->pc = 0x124944u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 204));
    // 0x124948: 0xae110040  sw          $s1, 0x40($s0)
    ctx->pc = 0x124948u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 17));
    // 0x12494c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12494cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124950: 0xae120044  sw          $s2, 0x44($s0)
    ctx->pc = 0x124950u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 18));
    // 0x124954: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x124954u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x124958: 0xae020078  sw          $v0, 0x78($s0)
    ctx->pc = 0x124958u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 120), GPR_U32(ctx, 2));
    // 0x12495c: 0xae030080  sw          $v1, 0x80($s0)
    ctx->pc = 0x12495cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 128), GPR_U32(ctx, 3));
    // 0x124960: 0xa60700e0  sh          $a3, 0xE0($s0)
    ctx->pc = 0x124960u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 224), (uint16_t)GPR_U32(ctx, 7));
    // 0x124964: 0xae10007c  sw          $s0, 0x7C($s0)
    ctx->pc = 0x124964u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 124), GPR_U32(ctx, 16));
    // 0x124968: 0xae100084  sw          $s0, 0x84($s0)
    ctx->pc = 0x124968u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 16));
    // 0x12496c: 0xae0000c8  sw          $zero, 0xC8($s0)
    ctx->pc = 0x12496cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 200), GPR_U32(ctx, 0));
    // 0x124970: 0xa60000dc  sh          $zero, 0xDC($s0)
    ctx->pc = 0x124970u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 220), (uint16_t)GPR_U32(ctx, 0));
    // 0x124974: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x124974u;
    SET_GPR_U32(ctx, 31, 0x12497Cu);
    ctx->pc = 0x124978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124974u;
            // 0x124978: 0xa60700de  sh          $a3, 0xDE($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 222), (uint16_t)GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12497Cu; }
        if (ctx->pc != 0x12497Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12497Cu; }
        if (ctx->pc != 0x12497Cu) { return; }
    }
    ctx->pc = 0x12497Cu;
label_12497c:
    // 0x12497c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x12497cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_124980:
    // 0x124980: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124980u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124984: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124984u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124988: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124988u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12498c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12498cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124990: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x124990u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x124994: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x124994u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x124998: 0x3e00008  jr          $ra
    ctx->pc = 0x124998u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12499Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124998u;
            // 0x12499c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1248A8u: goto label_1248a8;
            case 0x1248CCu: goto label_1248cc;
            case 0x124904u: goto label_124904;
            case 0x124910u: goto label_124910;
            case 0x124920u: goto label_124920;
            case 0x124928u: goto label_124928;
            case 0x12497Cu: goto label_12497c;
            case 0x124980u: goto label_124980;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1249A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
