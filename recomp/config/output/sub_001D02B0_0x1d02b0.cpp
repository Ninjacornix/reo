#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D02B0
// Address: 0x1d02b0 - 0x1d03a0
void sub_001D02B0_0x1d02b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D02B0_0x1d02b0");
#endif

    switch (ctx->pc) {
        case 0x1d02d8u: goto label_1d02d8;
        case 0x1d0308u: goto label_1d0308;
        default: break;
    }

    ctx->pc = 0x1d02b0u;

    // 0x1d02b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d02b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d02b4: 0x80682d  daddu       $t5, $a0, $zero
    ctx->pc = 0x1d02b4u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d02b8: 0x15a00003  bnez        $t5, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D02B8u;
    {
        const bool branch_taken_0x1d02b8 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D02BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D02B8u;
            // 0x1d02bc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d02b8) {
            ctx->pc = 0x1D02C8u;
            goto label_1d02c8;
        }
    }
    ctx->pc = 0x1D02C0u;
    // 0x1d02c0: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1D02C0u;
    {
        const bool branch_taken_0x1d02c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D02C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D02C0u;
            // 0x1d02c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d02c0) {
            ctx->pc = 0x1D032Cu;
            goto label_1d032c;
        }
    }
    ctx->pc = 0x1D02C8u;
label_1d02c8:
    // 0x1d02c8: 0x3c0c0034  lui         $t4, 0x34
    ctx->pc = 0x1d02c8u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)52 << 16));
    // 0x1d02cc: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x1d02ccu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d02d0: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1D02D0u;
    {
        const bool branch_taken_0x1d02d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D02D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D02D0u;
            // 0x1d02d4: 0x258c1430  addiu       $t4, $t4, 0x1430 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 5168));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d02d0) {
            ctx->pc = 0x1D0320u;
            goto label_1d0320;
        }
    }
    ctx->pc = 0x1D02D8u;
label_1d02d8:
    // 0x1d02d8: 0x91820000  lbu         $v0, 0x0($t4)
    ctx->pc = 0x1d02d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x1d02dc: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1D02DCu;
    {
        const bool branch_taken_0x1d02dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d02dc) {
            ctx->pc = 0x1D0318u;
            goto label_1d0318;
        }
    }
    ctx->pc = 0x1D02E4u;
    // 0x1d02e4: 0x91820003  lbu         $v0, 0x3($t4)
    ctx->pc = 0x1d02e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 12), 3)));
    // 0x1d02e8: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x1d02e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1d02ec: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D02ECu;
    {
        const bool branch_taken_0x1d02ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d02ec) {
            ctx->pc = 0x1D0318u;
            goto label_1d0318;
        }
    }
    ctx->pc = 0x1D02F4u;
    // 0x1d02f4: 0x8d840004  lw          $a0, 0x4($t4)
    ctx->pc = 0x1d02f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 4)));
    // 0x1d02f8: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D02F8u;
    {
        const bool branch_taken_0x1d02f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D02FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D02F8u;
            // 0x1d02fc: 0x1a0282d  daddu       $a1, $t5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d02f8) {
            ctx->pc = 0x1D0318u;
            goto label_1d0318;
        }
    }
    ctx->pc = 0x1D0300u;
    // 0x1d0300: 0xc073d7c  jal         func_1CF5F0
    ctx->pc = 0x1D0300u;
    SET_GPR_U32(ctx, 31, 0x1D0308u);
    ctx->pc = 0x1CF5F0u;
    if (runtime->hasFunction(0x1CF5F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CF5F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0308u; }
        if (ctx->pc != 0x1D0308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF5F0_0x1cf5f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0308u; }
        if (ctx->pc != 0x1D0308u) { return; }
    }
    ctx->pc = 0x1D0308u;
label_1d0308:
    // 0x1d0308: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D0308u;
    {
        const bool branch_taken_0x1d0308 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0308) {
            ctx->pc = 0x1D0318u;
            goto label_1d0318;
        }
    }
    ctx->pc = 0x1D0310u;
    // 0x1d0310: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D0310u;
    {
        const bool branch_taken_0x1d0310 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0310u;
            // 0x1d0314: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0310) {
            ctx->pc = 0x1D032Cu;
            goto label_1d032c;
        }
    }
    ctx->pc = 0x1D0318u;
label_1d0318:
    // 0x1d0318: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x1d0318u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1d031c: 0x258c000c  addiu       $t4, $t4, 0xC
    ctx->pc = 0x1d031cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 12));
label_1d0320:
    // 0x1d0320: 0x29620010  slti        $v0, $t3, 0x10
    ctx->pc = 0x1d0320u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 11) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1d0324: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1D0324u;
    {
        const bool branch_taken_0x1d0324 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D0328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0324u;
            // 0x1d0328: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0324) {
            ctx->pc = 0x1D02D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d02d8;
        }
    }
    ctx->pc = 0x1D032Cu;
label_1d032c:
    // 0x1d032c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d032cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d0330: 0x3e00008  jr          $ra
    ctx->pc = 0x1D0330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0330u;
            // 0x1d0334: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D02C8u: goto label_1d02c8;
            case 0x1D02D8u: goto label_1d02d8;
            case 0x1D0308u: goto label_1d0308;
            case 0x1D0318u: goto label_1d0318;
            case 0x1D0320u: goto label_1d0320;
            case 0x1D032Cu: goto label_1d032c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0338u;
    // 0x1d0338: 0x0  nop
    ctx->pc = 0x1d0338u;
    // NOP
    // 0x1d033c: 0x0  nop
    ctx->pc = 0x1d033cu;
    // NOP
    // 0x1d0340: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d0340u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0344: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0344u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0348: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d0348u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d034c: 0xac254480  sw          $a1, 0x4480($at)
    ctx->pc = 0x1d034cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17536), GPR_U32(ctx, 5));
    // 0x1d0350: 0x248461c0  addiu       $a0, $a0, 0x61C0
    ctx->pc = 0x1d0350u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 25024));
    // 0x1d0354: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d0354u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0358: 0x807323c  j           func_1CC8F0
    ctx->pc = 0x1D0358u;
    ctx->pc = 0x1D035Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0358u;
            // 0x1d035c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D0360u;
    // 0x1d0360: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d0360u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0364: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0364u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0368: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d0368u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d036c: 0xac254484  sw          $a1, 0x4484($at)
    ctx->pc = 0x1d036cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17540), GPR_U32(ctx, 5));
    // 0x1d0370: 0x248461f0  addiu       $a0, $a0, 0x61F0
    ctx->pc = 0x1d0370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 25072));
    // 0x1d0374: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d0374u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0378: 0x807323c  j           func_1CC8F0
    ctx->pc = 0x1D0378u;
    ctx->pc = 0x1D037Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0378u;
            // 0x1d037c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D0380u;
    // 0x1d0380: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d0380u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0384: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0384u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0388: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d0388u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d038c: 0xac25447c  sw          $a1, 0x447C($at)
    ctx->pc = 0x1d038cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17532), GPR_U32(ctx, 5));
    // 0x1d0390: 0x24846220  addiu       $a0, $a0, 0x6220
    ctx->pc = 0x1d0390u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 25120));
    // 0x1d0394: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d0394u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0398: 0x807323c  j           func_1CC8F0
    ctx->pc = 0x1D0398u;
    ctx->pc = 0x1D039Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0398u;
            // 0x1d039c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D03A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
