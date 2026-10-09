#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001612E8
// Address: 0x1612e8 - 0x161390
void sub_001612E8_0x1612e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001612E8_0x1612e8");
#endif

    switch (ctx->pc) {
        case 0x161310u: goto label_161310;
        case 0x161324u: goto label_161324;
        case 0x161340u: goto label_161340;
        case 0x161350u: goto label_161350;
        case 0x161364u: goto label_161364;
        case 0x161374u: goto label_161374;
        default: break;
    }

    ctx->pc = 0x1612e8u;

    // 0x1612e8: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x1612e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1612ec: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x1612ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x1612f0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1612f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612f4: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x1612f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x1612f8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1612f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612fc: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x1612fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x161300: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x161304: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x161304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x161308: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161308u;
    SET_GPR_U32(ctx, 31, 0x161310u);
    ctx->pc = 0x16130Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161308u;
            // 0x16130c: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161310u; }
        if (ctx->pc != 0x161310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161310u; }
        if (ctx->pc != 0x161310u) { return; }
    }
    ctx->pc = 0x161310u;
label_161310:
    // 0x161310: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x161310u;
    {
        const bool branch_taken_0x161310 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x161310) {
            ctx->pc = 0x161314u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161310u;
            // 0x161314: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161330u;
            goto label_161330;
        }
    }
    ctx->pc = 0x161318u;
    // 0x161318: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161318u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16131c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16131Cu;
    SET_GPR_U32(ctx, 31, 0x161324u);
    ctx->pc = 0x161320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16131Cu;
            // 0x161320: 0x2484fb60  addiu       $a0, $a0, -0x4A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161324u; }
        if (ctx->pc != 0x161324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161324u; }
        if (ctx->pc != 0x161324u) { return; }
    }
    ctx->pc = 0x161324u;
label_161324:
    // 0x161324: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x161324u;
    {
        const bool branch_taken_0x161324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161324u;
            // 0x161328: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161324) {
            ctx->pc = 0x161378u;
            goto label_161378;
        }
    }
    ctx->pc = 0x16132Cu;
    // 0x16132c: 0x0  nop
    ctx->pc = 0x16132cu;
    // NOP
label_161330:
    // 0x161330: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x161330u;
    {
        const bool branch_taken_0x161330 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161330u;
            // 0x161334: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161330) {
            ctx->pc = 0x161348u;
            goto label_161348;
        }
    }
    ctx->pc = 0x161338u;
    // 0x161338: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161338u;
    SET_GPR_U32(ctx, 31, 0x161340u);
    ctx->pc = 0x16133Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161338u;
            // 0x16133c: 0x2484fb90  addiu       $a0, $a0, -0x470 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161340u; }
        if (ctx->pc != 0x161340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161340u; }
        if (ctx->pc != 0x161340u) { return; }
    }
    ctx->pc = 0x161340u;
label_161340:
    // 0x161340: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x161340u;
    {
        const bool branch_taken_0x161340 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161340u;
            // 0x161344: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161340) {
            ctx->pc = 0x161378u;
            goto label_161378;
        }
    }
    ctx->pc = 0x161348u;
label_161348:
    // 0x161348: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161348u;
    SET_GPR_U32(ctx, 31, 0x161350u);
    ctx->pc = 0x16134Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161348u;
            // 0x16134c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161350u; }
        if (ctx->pc != 0x161350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161350u; }
        if (ctx->pc != 0x161350u) { return; }
    }
    ctx->pc = 0x161350u;
label_161350:
    // 0x161350: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161350u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161354: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161354u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161358: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161358u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16135c: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x16135Cu;
    SET_GPR_U32(ctx, 31, 0x161364u);
    ctx->pc = 0x161360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16135Cu;
            // 0x161360: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161364u; }
        if (ctx->pc != 0x161364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161364u; }
        if (ctx->pc != 0x161364u) { return; }
    }
    ctx->pc = 0x161364u;
label_161364:
    // 0x161364: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161364u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161368: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16136c: 0xc05f040  jal         func_17C100
    ctx->pc = 0x16136Cu;
    SET_GPR_U32(ctx, 31, 0x161374u);
    ctx->pc = 0x161370u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16136Cu;
            // 0x161370: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C100u;
    if (runtime->hasFunction(0x17C100u)) {
        auto targetFn = runtime->lookupFunction(0x17C100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161374u; }
        if (ctx->pc != 0x161374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C100_0x17c100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161374u; }
        if (ctx->pc != 0x161374u) { return; }
    }
    ctx->pc = 0x161374u;
label_161374:
    // 0x161374: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161374u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161378:
    // 0x161378: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161378u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x16137c: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x16137cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161380: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161380u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161384: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x161384u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161388: 0x3e00008  jr          $ra
    ctx->pc = 0x161388u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16138Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161388u;
            // 0x16138c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161390u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
