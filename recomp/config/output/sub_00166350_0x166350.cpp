#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166350
// Address: 0x166350 - 0x166428
void sub_00166350_0x166350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166350_0x166350");
#endif

    switch (ctx->pc) {
        case 0x166370u: goto label_166370;
        case 0x166390u: goto label_166390;
        case 0x1663d0u: goto label_1663d0;
        case 0x16640cu: goto label_16640c;
        case 0x166414u: goto label_166414;
        default: break;
    }

    ctx->pc = 0x166350u;

    // 0x166350: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x166354: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166358: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x166358u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16635c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16635cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x166360: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166360u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166364: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x166364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x166368: 0xc05d58a  jal         func_175628
    ctx->pc = 0x166368u;
    SET_GPR_U32(ctx, 31, 0x166370u);
    ctx->pc = 0x16636Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166368u;
            // 0x16636c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166370u; }
        if (ctx->pc != 0x166370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166370u; }
        if (ctx->pc != 0x166370u) { return; }
    }
    ctx->pc = 0x166370u;
label_166370:
    // 0x166370: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x166370u;
    {
        const bool branch_taken_0x166370 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x166370) {
            ctx->pc = 0x166374u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x166370u;
            // 0x166374: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x166394u;
            goto label_166394;
        }
    }
    ctx->pc = 0x166378u;
    // 0x166378: 0x8e021c84  lw          $v0, 0x1C84($s0)
    ctx->pc = 0x166378u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7300)));
    // 0x16637c: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x16637cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x166380: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x166380u;
    {
        const bool branch_taken_0x166380 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166380u;
            // 0x166384: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166380) {
            ctx->pc = 0x166390u;
            goto label_166390;
        }
    }
    ctx->pc = 0x166388u;
    // 0x166388: 0x40f809  jalr        $v0
    ctx->pc = 0x166388u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x166390u);
        ctx->pc = 0x16638Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166388u;
            // 0x16638c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x166390u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166370u: goto label_166370;
            case 0x166390u: goto label_166390;
            case 0x166394u: goto label_166394;
            case 0x1663D0u: goto label_1663d0;
            case 0x1663E8u: goto label_1663e8;
            case 0x1663F8u: goto label_1663f8;
            case 0x16640Cu: goto label_16640c;
            case 0x166414u: goto label_166414;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x166390u; }
            if (ctx->pc != 0x166390u) { return; }
        }
        }
    }
    ctx->pc = 0x166390u;
label_166390:
    // 0x166390: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166390u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_166394:
    // 0x166394: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166394u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166398: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166398u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16639c: 0x3e00008  jr          $ra
    ctx->pc = 0x16639Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1663A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16639Cu;
            // 0x1663a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166370u: goto label_166370;
            case 0x166390u: goto label_166390;
            case 0x166394u: goto label_166394;
            case 0x1663D0u: goto label_1663d0;
            case 0x1663E8u: goto label_1663e8;
            case 0x1663F8u: goto label_1663f8;
            case 0x16640Cu: goto label_16640c;
            case 0x166414u: goto label_166414;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1663A4u;
    // 0x1663a4: 0x0  nop
    ctx->pc = 0x1663a4u;
    // NOP
    // 0x1663a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1663A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1663ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1663A8u;
            // 0x1663ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166370u: goto label_166370;
            case 0x166390u: goto label_166390;
            case 0x166394u: goto label_166394;
            case 0x1663D0u: goto label_1663d0;
            case 0x1663E8u: goto label_1663e8;
            case 0x1663F8u: goto label_1663f8;
            case 0x16640Cu: goto label_16640c;
            case 0x166414u: goto label_166414;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1663B0u;
    // 0x1663b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1663B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1663B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1663B0u;
            // 0x1663b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166370u: goto label_166370;
            case 0x166390u: goto label_166390;
            case 0x166394u: goto label_166394;
            case 0x1663D0u: goto label_1663d0;
            case 0x1663E8u: goto label_1663e8;
            case 0x1663F8u: goto label_1663f8;
            case 0x16640Cu: goto label_16640c;
            case 0x166414u: goto label_166414;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1663B8u;
    // 0x1663b8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1663b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1663bc: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1663bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1663c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1663c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1663c4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1663c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1663c8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1663C8u;
    SET_GPR_U32(ctx, 31, 0x1663D0u);
    ctx->pc = 0x1663CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1663C8u;
            // 0x1663cc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1663D0u; }
        if (ctx->pc != 0x1663D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1663D0u; }
        if (ctx->pc != 0x1663D0u) { return; }
    }
    ctx->pc = 0x1663D0u;
label_1663d0:
    // 0x1663d0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1663D0u;
    {
        const bool branch_taken_0x1663d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1663D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1663D0u;
            // 0x1663d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1663d0) {
            ctx->pc = 0x1663E8u;
            goto label_1663e8;
        }
    }
    ctx->pc = 0x1663D8u;
    // 0x1663d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1663d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1663dc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1663dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1663e0: 0x80598fe  j           func_1663F8
    ctx->pc = 0x1663E0u;
    ctx->pc = 0x1663E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1663E0u;
            // 0x1663e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1663F8u;
    goto label_1663f8;
    ctx->pc = 0x1663E8u;
label_1663e8:
    // 0x1663e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1663e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1663ec: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1663ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1663f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1663F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1663F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1663F0u;
            // 0x1663f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166370u: goto label_166370;
            case 0x166390u: goto label_166390;
            case 0x166394u: goto label_166394;
            case 0x1663D0u: goto label_1663d0;
            case 0x1663E8u: goto label_1663e8;
            case 0x1663F8u: goto label_1663f8;
            case 0x16640Cu: goto label_16640c;
            case 0x166414u: goto label_166414;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1663F8u;
label_1663f8:
    // 0x1663f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1663f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1663fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1663fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166400: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x166400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x166404: 0xc05990a  jal         func_166428
    ctx->pc = 0x166404u;
    SET_GPR_U32(ctx, 31, 0x16640Cu);
    ctx->pc = 0x166408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166404u;
            // 0x166408: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166428u;
    if (runtime->hasFunction(0x166428u)) {
        auto targetFn = runtime->lookupFunction(0x166428u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16640Cu; }
        if (ctx->pc != 0x16640Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166428_0x166428(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16640Cu; }
        if (ctx->pc != 0x16640Cu) { return; }
    }
    ctx->pc = 0x16640Cu;
label_16640c:
    // 0x16640c: 0xc059926  jal         func_166498
    ctx->pc = 0x16640Cu;
    SET_GPR_U32(ctx, 31, 0x166414u);
    ctx->pc = 0x166410u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16640Cu;
            // 0x166410: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166498u;
    if (runtime->hasFunction(0x166498u)) {
        auto targetFn = runtime->lookupFunction(0x166498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166414u; }
        if (ctx->pc != 0x166414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166498_0x166498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166414u; }
        if (ctx->pc != 0x166414u) { return; }
    }
    ctx->pc = 0x166414u;
label_166414:
    // 0x166414: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166414u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166418: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166418u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16641c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16641cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166420: 0x3e00008  jr          $ra
    ctx->pc = 0x166420u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166420u;
            // 0x166424: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166370u: goto label_166370;
            case 0x166390u: goto label_166390;
            case 0x166394u: goto label_166394;
            case 0x1663D0u: goto label_1663d0;
            case 0x1663E8u: goto label_1663e8;
            case 0x1663F8u: goto label_1663f8;
            case 0x16640Cu: goto label_16640c;
            case 0x166414u: goto label_166414;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166428u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
