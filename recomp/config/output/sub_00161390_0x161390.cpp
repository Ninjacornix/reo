#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161390
// Address: 0x161390 - 0x161438
void sub_00161390_0x161390(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161390_0x161390");
#endif

    switch (ctx->pc) {
        case 0x1613b8u: goto label_1613b8;
        case 0x1613ccu: goto label_1613cc;
        case 0x1613e8u: goto label_1613e8;
        case 0x1613f8u: goto label_1613f8;
        case 0x16140cu: goto label_16140c;
        case 0x16141cu: goto label_16141c;
        default: break;
    }

    ctx->pc = 0x161390u;

    // 0x161390: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161390u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x161394: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161398: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161398u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16139c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x16139cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x1613a0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1613a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1613a4: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x1613a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x1613a8: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x1613a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x1613ac: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x1613acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x1613b0: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1613B0u;
    SET_GPR_U32(ctx, 31, 0x1613B8u);
    ctx->pc = 0x1613B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1613B0u;
            // 0x1613b4: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613B8u; }
        if (ctx->pc != 0x1613B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613B8u; }
        if (ctx->pc != 0x1613B8u) { return; }
    }
    ctx->pc = 0x1613B8u;
label_1613b8:
    // 0x1613b8: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1613B8u;
    {
        const bool branch_taken_0x1613b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1613b8) {
            ctx->pc = 0x1613BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1613B8u;
            // 0x1613bc: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1613D8u;
            goto label_1613d8;
        }
    }
    ctx->pc = 0x1613C0u;
    // 0x1613c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1613c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1613c4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1613C4u;
    SET_GPR_U32(ctx, 31, 0x1613CCu);
    ctx->pc = 0x1613C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1613C4u;
            // 0x1613c8: 0x2484fbc0  addiu       $a0, $a0, -0x440 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613CCu; }
        if (ctx->pc != 0x1613CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613CCu; }
        if (ctx->pc != 0x1613CCu) { return; }
    }
    ctx->pc = 0x1613CCu;
label_1613cc:
    // 0x1613cc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1613CCu;
    {
        const bool branch_taken_0x1613cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1613D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1613CCu;
            // 0x1613d0: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1613cc) {
            ctx->pc = 0x161420u;
            goto label_161420;
        }
    }
    ctx->pc = 0x1613D4u;
    // 0x1613d4: 0x0  nop
    ctx->pc = 0x1613d4u;
    // NOP
label_1613d8:
    // 0x1613d8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1613D8u;
    {
        const bool branch_taken_0x1613d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1613DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1613D8u;
            // 0x1613dc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1613d8) {
            ctx->pc = 0x1613F0u;
            goto label_1613f0;
        }
    }
    ctx->pc = 0x1613E0u;
    // 0x1613e0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1613E0u;
    SET_GPR_U32(ctx, 31, 0x1613E8u);
    ctx->pc = 0x1613E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1613E0u;
            // 0x1613e4: 0x2484fbf0  addiu       $a0, $a0, -0x410 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613E8u; }
        if (ctx->pc != 0x1613E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613E8u; }
        if (ctx->pc != 0x1613E8u) { return; }
    }
    ctx->pc = 0x1613E8u;
label_1613e8:
    // 0x1613e8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1613E8u;
    {
        const bool branch_taken_0x1613e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1613ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1613E8u;
            // 0x1613ec: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1613e8) {
            ctx->pc = 0x161420u;
            goto label_161420;
        }
    }
    ctx->pc = 0x1613F0u;
label_1613f0:
    // 0x1613f0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1613F0u;
    SET_GPR_U32(ctx, 31, 0x1613F8u);
    ctx->pc = 0x1613F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1613F0u;
            // 0x1613f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613F8u; }
        if (ctx->pc != 0x1613F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613F8u; }
        if (ctx->pc != 0x1613F8u) { return; }
    }
    ctx->pc = 0x1613F8u;
label_1613f8:
    // 0x1613f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1613f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1613fc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1613fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161400: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161400u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161404: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x161404u;
    SET_GPR_U32(ctx, 31, 0x16140Cu);
    ctx->pc = 0x161408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161404u;
            // 0x161408: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16140Cu; }
        if (ctx->pc != 0x16140Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16140Cu; }
        if (ctx->pc != 0x16140Cu) { return; }
    }
    ctx->pc = 0x16140Cu;
label_16140c:
    // 0x16140c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16140cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161410: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161410u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161414: 0xc05f050  jal         func_17C140
    ctx->pc = 0x161414u;
    SET_GPR_U32(ctx, 31, 0x16141Cu);
    ctx->pc = 0x161418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161414u;
            // 0x161418: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C140u;
    if (runtime->hasFunction(0x17C140u)) {
        auto targetFn = runtime->lookupFunction(0x17C140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16141Cu; }
        if (ctx->pc != 0x16141Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C140_0x17c140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16141Cu; }
        if (ctx->pc != 0x16141Cu) { return; }
    }
    ctx->pc = 0x16141Cu;
label_16141c:
    // 0x16141c: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x16141cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161420:
    // 0x161420: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161420u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x161424: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x161424u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161428: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161428u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x16142c: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x16142cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161430: 0x3e00008  jr          $ra
    ctx->pc = 0x161430u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161430u;
            // 0x161434: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161438u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
