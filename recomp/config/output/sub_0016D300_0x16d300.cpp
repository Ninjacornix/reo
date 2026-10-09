#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D300
// Address: 0x16d300 - 0x16d3d0
void sub_0016D300_0x16d300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D300_0x16d300");
#endif

    switch (ctx->pc) {
        case 0x16d328u: goto label_16d328;
        case 0x16d338u: goto label_16d338;
        case 0x16d348u: goto label_16d348;
        case 0x16d364u: goto label_16d364;
        case 0x16d378u: goto label_16d378;
        case 0x16d388u: goto label_16d388;
        case 0x16d3a0u: goto label_16d3a0;
        case 0x16d3acu: goto label_16d3ac;
        default: break;
    }

    ctx->pc = 0x16d300u;

    // 0x16d300: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16d300u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16d304: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16d304u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x16d308: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16d308u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16d30c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16d30cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d310: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16d310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16d314: 0x26110cc0  addiu       $s1, $s0, 0xCC0
    ctx->pc = 0x16d314u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x16d318: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16d318u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16d31c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16d31cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16d320: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16D320u;
    SET_GPR_U32(ctx, 31, 0x16D328u);
    ctx->pc = 0x16D324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D320u;
            // 0x16d324: 0x8e121b30  lw          $s2, 0x1B30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D328u; }
        if (ctx->pc != 0x16D328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D328u; }
        if (ctx->pc != 0x16D328u) { return; }
    }
    ctx->pc = 0x16D328u;
label_16d328:
    // 0x16d328: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D328u;
    {
        const bool branch_taken_0x16d328 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16D32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D328u;
            // 0x16d32c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d328) {
            ctx->pc = 0x16D340u;
            goto label_16d340;
        }
    }
    ctx->pc = 0x16D330u;
    // 0x16d330: 0xc05b4f4  jal         func_16D3D0
    ctx->pc = 0x16D330u;
    SET_GPR_U32(ctx, 31, 0x16D338u);
    ctx->pc = 0x16D3D0u;
    if (runtime->hasFunction(0x16D3D0u)) {
        auto targetFn = runtime->lookupFunction(0x16D3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D338u; }
        if (ctx->pc != 0x16D338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D3D0_0x16d3d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D338u; }
        if (ctx->pc != 0x16D338u) { return; }
    }
    ctx->pc = 0x16D338u;
label_16d338:
    // 0x16d338: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x16D338u;
    {
        const bool branch_taken_0x16d338 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D33Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D338u;
            // 0x16d33c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d338) {
            ctx->pc = 0x16D354u;
            goto label_16d354;
        }
    }
    ctx->pc = 0x16D340u;
label_16d340:
    // 0x16d340: 0xc05b518  jal         func_16D460
    ctx->pc = 0x16D340u;
    SET_GPR_U32(ctx, 31, 0x16D348u);
    ctx->pc = 0x16D460u;
    if (runtime->hasFunction(0x16D460u)) {
        auto targetFn = runtime->lookupFunction(0x16D460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D348u; }
        if (ctx->pc != 0x16D348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D460_0x16d460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D348u; }
        if (ctx->pc != 0x16D348u) { return; }
    }
    ctx->pc = 0x16D348u;
label_16d348:
    // 0x16d348: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x16d348u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d34c: 0x4a0001a  bltz        $a1, . + 4 + (0x1A << 2)
    ctx->pc = 0x16D34Cu;
    {
        const bool branch_taken_0x16d34c = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x16D350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D34Cu;
            // 0x16d350: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d34c) {
            ctx->pc = 0x16D3B8u;
            goto label_16d3b8;
        }
    }
    ctx->pc = 0x16D354u;
label_16d354:
    // 0x16d354: 0x58a0000f  blezl       $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x16D354u;
    {
        const bool branch_taken_0x16d354 = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x16d354) {
            ctx->pc = 0x16D358u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16D354u;
            // 0x16d358: 0x3c057fff  lui         $a1, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16D394u;
            goto label_16d394;
        }
    }
    ctx->pc = 0x16D35Cu;
    // 0x16d35c: 0xc059fa0  jal         func_167E80
    ctx->pc = 0x16D35Cu;
    SET_GPR_U32(ctx, 31, 0x16D364u);
    ctx->pc = 0x16D360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D35Cu;
            // 0x16d360: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167E80u;
    if (runtime->hasFunction(0x167E80u)) {
        auto targetFn = runtime->lookupFunction(0x167E80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D364u; }
        if (ctx->pc != 0x16D364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167E80_0x167e80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D364u; }
        if (ctx->pc != 0x16D364u) { return; }
    }
    ctx->pc = 0x16D364u;
label_16d364:
    // 0x16d364: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16d364u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d368: 0x8e420088  lw          $v0, 0x88($s2)
    ctx->pc = 0x16d368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 136)));
    // 0x16d36c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x16d36cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16d370: 0xc05c54c  jal         func_171530
    ctx->pc = 0x16D370u;
    SET_GPR_U32(ctx, 31, 0x16D378u);
    ctx->pc = 0x16D374u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D370u;
            // 0x16d374: 0xae420088  sw          $v0, 0x88($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 136), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171530u;
    if (runtime->hasFunction(0x171530u)) {
        auto targetFn = runtime->lookupFunction(0x171530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D378u; }
        if (ctx->pc != 0x16D378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171530_0x171530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D378u; }
        if (ctx->pc != 0x16D378u) { return; }
    }
    ctx->pc = 0x16D378u;
label_16d378:
    // 0x16d378: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D378u;
    {
        const bool branch_taken_0x16d378 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D37Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D378u;
            // 0x16d37c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d378) {
            ctx->pc = 0x16D390u;
            goto label_16d390;
        }
    }
    ctx->pc = 0x16D380u;
    // 0x16d380: 0xc05c796  jal         func_171E58
    ctx->pc = 0x16D380u;
    SET_GPR_U32(ctx, 31, 0x16D388u);
    ctx->pc = 0x171E58u;
    if (runtime->hasFunction(0x171E58u)) {
        auto targetFn = runtime->lookupFunction(0x171E58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D388u; }
        if (ctx->pc != 0x16D388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171E58_0x171e58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D388u; }
        if (ctx->pc != 0x16D388u) { return; }
    }
    ctx->pc = 0x16D388u;
label_16d388:
    // 0x16d388: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x16d388u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16d38c: 0xae22011c  sw          $v0, 0x11C($s1)
    ctx->pc = 0x16d38cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 284), GPR_U32(ctx, 2));
label_16d390:
    // 0x16d390: 0x3c057fff  lui         $a1, 0x7FFF
    ctx->pc = 0x16d390u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32767 << 16));
label_16d394:
    // 0x16d394: 0x2624001c  addiu       $a0, $s1, 0x1C
    ctx->pc = 0x16d394u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 28));
    // 0x16d398: 0xc05d714  jal         func_175C50
    ctx->pc = 0x16D398u;
    SET_GPR_U32(ctx, 31, 0x16D3A0u);
    ctx->pc = 0x16D39Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D398u;
            // 0x16d39c: 0x34a5ffff  ori         $a1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C50u;
    if (runtime->hasFunction(0x175C50u)) {
        auto targetFn = runtime->lookupFunction(0x175C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D3A0u; }
        if (ctx->pc != 0x16D3A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C50_0x175c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D3A0u; }
        if (ctx->pc != 0x16D3A0u) { return; }
    }
    ctx->pc = 0x16D3A0u;
label_16d3a0:
    // 0x16d3a0: 0x26240044  addiu       $a0, $s1, 0x44
    ctx->pc = 0x16d3a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 68));
    // 0x16d3a4: 0xc05d714  jal         func_175C50
    ctx->pc = 0x16D3A4u;
    SET_GPR_U32(ctx, 31, 0x16D3ACu);
    ctx->pc = 0x16D3A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D3A4u;
            // 0x16d3a8: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175C50u;
    if (runtime->hasFunction(0x175C50u)) {
        auto targetFn = runtime->lookupFunction(0x175C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D3ACu; }
        if (ctx->pc != 0x16D3ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175C50_0x175c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D3ACu; }
        if (ctx->pc != 0x16D3ACu) { return; }
    }
    ctx->pc = 0x16D3ACu;
label_16d3ac:
    // 0x16d3ac: 0x240200c0  addiu       $v0, $zero, 0xC0
    ctx->pc = 0x16d3acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x16d3b0: 0xae420078  sw          $v0, 0x78($s2)
    ctx->pc = 0x16d3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 120), GPR_U32(ctx, 2));
    // 0x16d3b4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16d3b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16d3b8:
    // 0x16d3b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16d3b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16d3bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16d3bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16d3c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16d3c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16d3c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16d3c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16d3c8: 0x3e00008  jr          $ra
    ctx->pc = 0x16D3C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D3CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D3C8u;
            // 0x16d3cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D328u: goto label_16d328;
            case 0x16D338u: goto label_16d338;
            case 0x16D340u: goto label_16d340;
            case 0x16D348u: goto label_16d348;
            case 0x16D354u: goto label_16d354;
            case 0x16D364u: goto label_16d364;
            case 0x16D378u: goto label_16d378;
            case 0x16D388u: goto label_16d388;
            case 0x16D390u: goto label_16d390;
            case 0x16D394u: goto label_16d394;
            case 0x16D3A0u: goto label_16d3a0;
            case 0x16D3ACu: goto label_16d3ac;
            case 0x16D3B8u: goto label_16d3b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D3D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
