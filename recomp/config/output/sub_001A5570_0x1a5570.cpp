#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5570
// Address: 0x1a5570 - 0x1a5790
void sub_001A5570_0x1a5570(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5570_0x1a5570");
#endif

    switch (ctx->pc) {
        case 0x1a5590u: goto label_1a5590;
        case 0x1a55a8u: goto label_1a55a8;
        default: break;
    }

    ctx->pc = 0x1a5570u;

    // 0x1a5570: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a5570u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a5574: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a5574u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a5578: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a5578u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a557c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a557cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a5580: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a5580u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5584: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1a5584u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5588: 0xc0695ec  jal         func_1A57B0
    ctx->pc = 0x1A5588u;
    SET_GPR_U32(ctx, 31, 0x1A5590u);
    ctx->pc = 0x1A558Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5588u;
            // 0x1a558c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A57B0u;
    if (runtime->hasFunction(0x1A57B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A57B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5590u; }
        if (ctx->pc != 0x1A5590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A57B0_0x1a57b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5590u; }
        if (ctx->pc != 0x1A5590u) { return; }
    }
    ctx->pc = 0x1A5590u;
label_1a5590:
    // 0x1a5590: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5590u;
    {
        const bool branch_taken_0x1a5590 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5590u;
            // 0x1a5594: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5590) {
            ctx->pc = 0x1A55A0u;
            goto label_1a55a0;
        }
    }
    ctx->pc = 0x1A5598u;
    // 0x1a5598: 0x10000075  b           . + 4 + (0x75 << 2)
    ctx->pc = 0x1A5598u;
    {
        const bool branch_taken_0x1a5598 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A559Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5598u;
            // 0x1a559c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5598) {
            ctx->pc = 0x1A5770u;
            goto label_1a5770;
        }
    }
    ctx->pc = 0x1A55A0u;
label_1a55a0:
    // 0x1a55a0: 0xc069630  jal         func_1A58C0
    ctx->pc = 0x1A55A0u;
    SET_GPR_U32(ctx, 31, 0x1A55A8u);
    ctx->pc = 0x1A55A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A55A0u;
            // 0x1a55a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A58C0u;
    if (runtime->hasFunction(0x1A58C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A58C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A55A8u; }
        if (ctx->pc != 0x1A55A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A58C0_0x1a58c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A55A8u; }
        if (ctx->pc != 0x1A55A8u) { return; }
    }
    ctx->pc = 0x1A55A8u;
label_1a55a8:
    // 0x1a55a8: 0x90430011  lbu         $v1, 0x11($v0)
    ctx->pc = 0x1a55a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 17)));
    // 0x1a55ac: 0x28610008  slti        $at, $v1, 0x8
    ctx->pc = 0x1a55acu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1a55b0: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A55B0u;
    {
        const bool branch_taken_0x1a55b0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a55b0) {
            ctx->pc = 0x1A55C0u;
            goto label_1a55c0;
        }
    }
    ctx->pc = 0x1A55B8u;
    // 0x1a55b8: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x1A55B8u;
    {
        const bool branch_taken_0x1a55b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A55BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A55B8u;
            // 0x1a55bc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a55b8) {
            ctx->pc = 0x1A5770u;
            goto label_1a5770;
        }
    }
    ctx->pc = 0x1A55C0u;
label_1a55c0:
    // 0x1a55c0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1a55c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1a55c4: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1a55c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a55c8: 0x90450012  lbu         $a1, 0x12($v0)
    ctx->pc = 0x1a55c8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 18)));
    // 0x1a55cc: 0x10a4002f  beq         $a1, $a0, . + 4 + (0x2F << 2)
    ctx->pc = 0x1A55CCu;
    {
        const bool branch_taken_0x1a55cc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1A55D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A55CCu;
            // 0x1a55d0: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a55cc) {
            ctx->pc = 0x1A568Cu;
            goto label_1a568c;
        }
    }
    ctx->pc = 0x1A55D4u;
    // 0x1a55d4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1a55d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a55d8: 0x10a30019  beq         $a1, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1A55D8u;
    {
        const bool branch_taken_0x1a55d8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A55DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A55D8u;
            // 0x1a55dc: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a55d8) {
            ctx->pc = 0x1A5640u;
            goto label_1a5640;
        }
    }
    ctx->pc = 0x1A55E0u;
    // 0x1a55e0: 0x10a70003  beq         $a1, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A55E0u;
    {
        const bool branch_taken_0x1a55e0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 7));
        if (branch_taken_0x1a55e0) {
            ctx->pc = 0x1A55F0u;
            goto label_1a55f0;
        }
    }
    ctx->pc = 0x1A55E8u;
    // 0x1a55e8: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1A55E8u;
    {
        const bool branch_taken_0x1a55e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A55ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A55E8u;
            // 0x1a55ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a55e8) {
            ctx->pc = 0x1A56DCu;
            goto label_1a56dc;
        }
    }
    ctx->pc = 0x1A55F0u;
label_1a55f0:
    // 0x1a55f0: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x1a55f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x1a55f4: 0x24060005  addiu       $a2, $zero, 0x5
    ctx->pc = 0x1a55f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a55f8: 0xae060018  sw          $a2, 0x18($s0)
    ctx->pc = 0x1a55f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 6));
    // 0x1a55fc: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1a55fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1a5600: 0xae05001c  sw          $a1, 0x1C($s0)
    ctx->pc = 0x1a5600u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 5));
    // 0x1a5604: 0x2404001f  addiu       $a0, $zero, 0x1F
    ctx->pc = 0x1a5604u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1a5608: 0xae040020  sw          $a0, 0x20($s0)
    ctx->pc = 0x1a5608u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 4));
    // 0x1a560c: 0x2403000f  addiu       $v1, $zero, 0xF
    ctx->pc = 0x1a560cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1a5610: 0xae060024  sw          $a2, 0x24($s0)
    ctx->pc = 0x1a5610u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 6));
    // 0x1a5614: 0xae060028  sw          $a2, 0x28($s0)
    ctx->pc = 0x1a5614u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 6));
    // 0x1a5618: 0xae04002c  sw          $a0, 0x2C($s0)
    ctx->pc = 0x1a5618u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x1a561c: 0xae060030  sw          $a2, 0x30($s0)
    ctx->pc = 0x1a561cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 6));
    // 0x1a5620: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1a5620u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1a5624: 0xae040038  sw          $a0, 0x38($s0)
    ctx->pc = 0x1a5624u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 4));
    // 0x1a5628: 0xae07003c  sw          $a3, 0x3C($s0)
    ctx->pc = 0x1a5628u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 7));
    // 0x1a562c: 0xae030040  sw          $v1, 0x40($s0)
    ctx->pc = 0x1a562cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 3));
    // 0x1a5630: 0xae070044  sw          $a3, 0x44($s0)
    ctx->pc = 0x1a5630u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 7));
    // 0x1a5634: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1a5634u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1a5638: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1A5638u;
    {
        const bool branch_taken_0x1a5638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A563Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5638u;
            // 0x1a563c: 0xae050034  sw          $a1, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5638) {
            ctx->pc = 0x1A56E4u;
            goto label_1a56e4;
        }
    }
    ctx->pc = 0x1A5640u;
label_1a5640:
    // 0x1a5640: 0xae040014  sw          $a0, 0x14($s0)
    ctx->pc = 0x1a5640u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 4));
    // 0x1a5644: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1a5644u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a5648: 0xae050018  sw          $a1, 0x18($s0)
    ctx->pc = 0x1a5648u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 5));
    // 0x1a564c: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1a564cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a5650: 0xae04001c  sw          $a0, 0x1C($s0)
    ctx->pc = 0x1a5650u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 4));
    // 0x1a5654: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1a5654u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a5658: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1a5658u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1a565c: 0xae050024  sw          $a1, 0x24($s0)
    ctx->pc = 0x1a565cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 5));
    // 0x1a5660: 0xae050028  sw          $a1, 0x28($s0)
    ctx->pc = 0x1a5660u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 5));
    // 0x1a5664: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1a5664u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1a5668: 0xae050030  sw          $a1, 0x30($s0)
    ctx->pc = 0x1a5668u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 5));
    // 0x1a566c: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1a566cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1a5670: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1a5670u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1a5674: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x1a5674u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x1a5678: 0xae000040  sw          $zero, 0x40($s0)
    ctx->pc = 0x1a5678u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 0));
    // 0x1a567c: 0xae000044  sw          $zero, 0x44($s0)
    ctx->pc = 0x1a567cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 0));
    // 0x1a5680: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1a5680u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1a5684: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1A5684u;
    {
        const bool branch_taken_0x1a5684 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5684u;
            // 0x1a5688: 0xae040034  sw          $a0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5684) {
            ctx->pc = 0x1A56E4u;
            goto label_1a56e4;
        }
    }
    ctx->pc = 0x1A568Cu;
label_1a568c:
    // 0x1a568c: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x1a568cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a5690: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x1a5690u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x1a5694: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1a5694u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a5698: 0xae060018  sw          $a2, 0x18($s0)
    ctx->pc = 0x1a5698u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 6));
    // 0x1a569c: 0x240400ff  addiu       $a0, $zero, 0xFF
    ctx->pc = 0x1a569cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a56a0: 0xae05001c  sw          $a1, 0x1C($s0)
    ctx->pc = 0x1a56a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 5));
    // 0x1a56a4: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x1a56a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1a56a8: 0xae040020  sw          $a0, 0x20($s0)
    ctx->pc = 0x1a56a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 4));
    // 0x1a56ac: 0xae060024  sw          $a2, 0x24($s0)
    ctx->pc = 0x1a56acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 6));
    // 0x1a56b0: 0xae060028  sw          $a2, 0x28($s0)
    ctx->pc = 0x1a56b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 6));
    // 0x1a56b4: 0xae04002c  sw          $a0, 0x2C($s0)
    ctx->pc = 0x1a56b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x1a56b8: 0xae060030  sw          $a2, 0x30($s0)
    ctx->pc = 0x1a56b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 6));
    // 0x1a56bc: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1a56bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1a56c0: 0xae040038  sw          $a0, 0x38($s0)
    ctx->pc = 0x1a56c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 4));
    // 0x1a56c4: 0xae06003c  sw          $a2, 0x3C($s0)
    ctx->pc = 0x1a56c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 6));
    // 0x1a56c8: 0xae030040  sw          $v1, 0x40($s0)
    ctx->pc = 0x1a56c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 3));
    // 0x1a56cc: 0xae040044  sw          $a0, 0x44($s0)
    ctx->pc = 0x1a56ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 4));
    // 0x1a56d0: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1a56d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1a56d4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A56D4u;
    {
        const bool branch_taken_0x1a56d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A56D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A56D4u;
            // 0x1a56d8: 0xae050034  sw          $a1, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a56d4) {
            ctx->pc = 0x1A56E4u;
            goto label_1a56e4;
        }
    }
    ctx->pc = 0x1A56DCu;
label_1a56dc:
    // 0x1a56dc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1A56DCu;
    {
        const bool branch_taken_0x1a56dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A56E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A56DCu;
            // 0x1a56e0: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a56dc) {
            ctx->pc = 0x1A5774u;
            goto label_1a5774;
        }
    }
    ctx->pc = 0x1A56E4u;
label_1a56e4:
    // 0x1a56e4: 0x90440013  lbu         $a0, 0x13($v0)
    ctx->pc = 0x1a56e4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 19)));
    // 0x1a56e8: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1a56e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a56ec: 0x1083000f  beq         $a0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1A56ECu;
    {
        const bool branch_taken_0x1a56ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A56F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A56ECu;
            // 0x1a56f0: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a56ec) {
            ctx->pc = 0x1A572Cu;
            goto label_1a572c;
        }
    }
    ctx->pc = 0x1A56F4u;
    // 0x1a56f4: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A56F4u;
    {
        const bool branch_taken_0x1a56f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a56f4) {
            ctx->pc = 0x1A5704u;
            goto label_1a5704;
        }
    }
    ctx->pc = 0x1A56FCu;
    // 0x1a56fc: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1A56FCu;
    {
        const bool branch_taken_0x1a56fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A56FCu;
            // 0x1a5700: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a56fc) {
            ctx->pc = 0x1A5754u;
            goto label_1a5754;
        }
    }
    ctx->pc = 0x1A5704u;
label_1a5704:
    // 0x1a5704: 0x9443000e  lhu         $v1, 0xE($v0)
    ctx->pc = 0x1a5704u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 14)));
    // 0x1a5708: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1a5708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a570c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A570Cu;
    {
        const bool branch_taken_0x1a570c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a570c) {
            ctx->pc = 0x1A571Cu;
            goto label_1a571c;
        }
    }
    ctx->pc = 0x1A5714u;
    // 0x1a5714: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1A5714u;
    {
        const bool branch_taken_0x1a5714 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5714u;
            // 0x1a5718: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5714) {
            ctx->pc = 0x1A5770u;
            goto label_1a5770;
        }
    }
    ctx->pc = 0x1A571Cu;
label_1a571c:
    // 0x1a571c: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1a571cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1a5720: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a5720u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a5724: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1A5724u;
    {
        const bool branch_taken_0x1a5724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5724u;
            // 0x1a5728: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5724) {
            ctx->pc = 0x1A575Cu;
            goto label_1a575c;
        }
    }
    ctx->pc = 0x1A572Cu;
label_1a572c:
    // 0x1a572c: 0x9443000e  lhu         $v1, 0xE($v0)
    ctx->pc = 0x1a572cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 14)));
    // 0x1a5730: 0x24020100  addiu       $v0, $zero, 0x100
    ctx->pc = 0x1a5730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1a5734: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5734u;
    {
        const bool branch_taken_0x1a5734 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a5734) {
            ctx->pc = 0x1A5744u;
            goto label_1a5744;
        }
    }
    ctx->pc = 0x1A573Cu;
    // 0x1a573c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A573Cu;
    {
        const bool branch_taken_0x1a573c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A573Cu;
            // 0x1a5740: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a573c) {
            ctx->pc = 0x1A5770u;
            goto label_1a5770;
        }
    }
    ctx->pc = 0x1A5744u;
label_1a5744:
    // 0x1a5744: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1a5744u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1a5748: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a5748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a574c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A574Cu;
    {
        const bool branch_taken_0x1a574c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A574Cu;
            // 0x1a5750: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a574c) {
            ctx->pc = 0x1A575Cu;
            goto label_1a575c;
        }
    }
    ctx->pc = 0x1A5754u;
label_1a5754:
    // 0x1a5754: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A5754u;
    {
        const bool branch_taken_0x1a5754 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a5754) {
            ctx->pc = 0x1A5770u;
            goto label_1a5770;
        }
    }
    ctx->pc = 0x1A575Cu;
label_1a575c:
    // 0x1a575c: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x1a575cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1a5760: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a5760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a5764: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1a5764u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a5768: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1a5768u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1a576c: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1a576cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
label_1a5770:
    // 0x1a5770: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a5770u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1a5774:
    // 0x1a5774: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a5774u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a5778: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a5778u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a577c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A577Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A577Cu;
            // 0x1a5780: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5590u: goto label_1a5590;
            case 0x1A55A0u: goto label_1a55a0;
            case 0x1A55A8u: goto label_1a55a8;
            case 0x1A55C0u: goto label_1a55c0;
            case 0x1A55F0u: goto label_1a55f0;
            case 0x1A5640u: goto label_1a5640;
            case 0x1A568Cu: goto label_1a568c;
            case 0x1A56DCu: goto label_1a56dc;
            case 0x1A56E4u: goto label_1a56e4;
            case 0x1A5704u: goto label_1a5704;
            case 0x1A571Cu: goto label_1a571c;
            case 0x1A572Cu: goto label_1a572c;
            case 0x1A5744u: goto label_1a5744;
            case 0x1A5754u: goto label_1a5754;
            case 0x1A575Cu: goto label_1a575c;
            case 0x1A5770u: goto label_1a5770;
            case 0x1A5774u: goto label_1a5774;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5784u;
    // 0x1a5784: 0x0  nop
    ctx->pc = 0x1a5784u;
    // NOP
    // 0x1a5788: 0x0  nop
    ctx->pc = 0x1a5788u;
    // NOP
    // 0x1a578c: 0x0  nop
    ctx->pc = 0x1a578cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
