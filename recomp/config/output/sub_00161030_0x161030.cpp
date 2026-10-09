#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161030
// Address: 0x161030 - 0x1610d8
void sub_00161030_0x161030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161030_0x161030");
#endif

    switch (ctx->pc) {
        case 0x161058u: goto label_161058;
        case 0x16106cu: goto label_16106c;
        case 0x161088u: goto label_161088;
        case 0x161098u: goto label_161098;
        case 0x1610acu: goto label_1610ac;
        case 0x1610bcu: goto label_1610bc;
        default: break;
    }

    ctx->pc = 0x161030u;

    // 0x161030: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x161034: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161038: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161038u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16103c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x16103cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x161040: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x161040u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161044: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x161044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x161048: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x16104c: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x16104cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x161050: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161050u;
    SET_GPR_U32(ctx, 31, 0x161058u);
    ctx->pc = 0x161054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161050u;
            // 0x161054: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161058u; }
        if (ctx->pc != 0x161058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161058u; }
        if (ctx->pc != 0x161058u) { return; }
    }
    ctx->pc = 0x161058u;
label_161058:
    // 0x161058: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x161058u;
    {
        const bool branch_taken_0x161058 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x161058) {
            ctx->pc = 0x16105Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161058u;
            // 0x16105c: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161078u;
            goto label_161078;
        }
    }
    ctx->pc = 0x161060u;
    // 0x161060: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161060u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161064: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161064u;
    SET_GPR_U32(ctx, 31, 0x16106Cu);
    ctx->pc = 0x161068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161064u;
            // 0x161068: 0x2484f9b0  addiu       $a0, $a0, -0x650 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965680));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16106Cu; }
        if (ctx->pc != 0x16106Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16106Cu; }
        if (ctx->pc != 0x16106Cu) { return; }
    }
    ctx->pc = 0x16106Cu;
label_16106c:
    // 0x16106c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x16106Cu;
    {
        const bool branch_taken_0x16106c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16106Cu;
            // 0x161070: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16106c) {
            ctx->pc = 0x1610C0u;
            goto label_1610c0;
        }
    }
    ctx->pc = 0x161074u;
    // 0x161074: 0x0  nop
    ctx->pc = 0x161074u;
    // NOP
label_161078:
    // 0x161078: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x161078u;
    {
        const bool branch_taken_0x161078 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16107Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161078u;
            // 0x16107c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161078) {
            ctx->pc = 0x161090u;
            goto label_161090;
        }
    }
    ctx->pc = 0x161080u;
    // 0x161080: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161080u;
    SET_GPR_U32(ctx, 31, 0x161088u);
    ctx->pc = 0x161084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161080u;
            // 0x161084: 0x2484f9e8  addiu       $a0, $a0, -0x618 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965736));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161088u; }
        if (ctx->pc != 0x161088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161088u; }
        if (ctx->pc != 0x161088u) { return; }
    }
    ctx->pc = 0x161088u;
label_161088:
    // 0x161088: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x161088u;
    {
        const bool branch_taken_0x161088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16108Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161088u;
            // 0x16108c: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161088) {
            ctx->pc = 0x1610C0u;
            goto label_1610c0;
        }
    }
    ctx->pc = 0x161090u;
label_161090:
    // 0x161090: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161090u;
    SET_GPR_U32(ctx, 31, 0x161098u);
    ctx->pc = 0x161094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161090u;
            // 0x161094: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161098u; }
        if (ctx->pc != 0x161098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161098u; }
        if (ctx->pc != 0x161098u) { return; }
    }
    ctx->pc = 0x161098u;
label_161098:
    // 0x161098: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161098u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16109c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16109cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610a0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1610a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610a4: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x1610A4u;
    SET_GPR_U32(ctx, 31, 0x1610ACu);
    ctx->pc = 0x1610A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1610A4u;
            // 0x1610a8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1610ACu; }
        if (ctx->pc != 0x1610ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1610ACu; }
        if (ctx->pc != 0x1610ACu) { return; }
    }
    ctx->pc = 0x1610ACu;
label_1610ac:
    // 0x1610ac: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1610acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1610b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610b4: 0xc05ee88  jal         func_17BA20
    ctx->pc = 0x1610B4u;
    SET_GPR_U32(ctx, 31, 0x1610BCu);
    ctx->pc = 0x1610B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1610B4u;
            // 0x1610b8: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BA20u;
    if (runtime->hasFunction(0x17BA20u)) {
        auto targetFn = runtime->lookupFunction(0x17BA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1610BCu; }
        if (ctx->pc != 0x1610BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017BA20_0x17ba20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1610BCu; }
        if (ctx->pc != 0x1610BCu) { return; }
    }
    ctx->pc = 0x1610BCu;
label_1610bc:
    // 0x1610bc: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x1610bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1610c0:
    // 0x1610c0: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x1610c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x1610c4: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x1610c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1610c8: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x1610c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1610cc: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x1610ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1610d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1610D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1610D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1610D0u;
            // 0x1610d4: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1610D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
