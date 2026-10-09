#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161240
// Address: 0x161240 - 0x1612e8
void sub_00161240_0x161240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161240_0x161240");
#endif

    switch (ctx->pc) {
        case 0x161268u: goto label_161268;
        case 0x16127cu: goto label_16127c;
        case 0x161298u: goto label_161298;
        case 0x1612a8u: goto label_1612a8;
        case 0x1612bcu: goto label_1612bc;
        case 0x1612ccu: goto label_1612cc;
        default: break;
    }

    ctx->pc = 0x161240u;

    // 0x161240: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x161244: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161248: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161248u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16124c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x16124cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x161250: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x161250u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161254: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x161254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x161258: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x16125c: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x16125cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x161260: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161260u;
    SET_GPR_U32(ctx, 31, 0x161268u);
    ctx->pc = 0x161264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161260u;
            // 0x161264: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161268u; }
        if (ctx->pc != 0x161268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161268u; }
        if (ctx->pc != 0x161268u) { return; }
    }
    ctx->pc = 0x161268u;
label_161268:
    // 0x161268: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x161268u;
    {
        const bool branch_taken_0x161268 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x161268) {
            ctx->pc = 0x16126Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161268u;
            // 0x16126c: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161288u;
            goto label_161288;
        }
    }
    ctx->pc = 0x161270u;
    // 0x161270: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161270u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161274: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161274u;
    SET_GPR_U32(ctx, 31, 0x16127Cu);
    ctx->pc = 0x161278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161274u;
            // 0x161278: 0x2484faf8  addiu       $a0, $a0, -0x508 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966008));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16127Cu; }
        if (ctx->pc != 0x16127Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16127Cu; }
        if (ctx->pc != 0x16127Cu) { return; }
    }
    ctx->pc = 0x16127Cu;
label_16127c:
    // 0x16127c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x16127Cu;
    {
        const bool branch_taken_0x16127c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16127Cu;
            // 0x161280: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16127c) {
            ctx->pc = 0x1612D0u;
            goto label_1612d0;
        }
    }
    ctx->pc = 0x161284u;
    // 0x161284: 0x0  nop
    ctx->pc = 0x161284u;
    // NOP
label_161288:
    // 0x161288: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x161288u;
    {
        const bool branch_taken_0x161288 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16128Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161288u;
            // 0x16128c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161288) {
            ctx->pc = 0x1612A0u;
            goto label_1612a0;
        }
    }
    ctx->pc = 0x161290u;
    // 0x161290: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161290u;
    SET_GPR_U32(ctx, 31, 0x161298u);
    ctx->pc = 0x161294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161290u;
            // 0x161294: 0x2484fb30  addiu       $a0, $a0, -0x4D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161298u; }
        if (ctx->pc != 0x161298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161298u; }
        if (ctx->pc != 0x161298u) { return; }
    }
    ctx->pc = 0x161298u;
label_161298:
    // 0x161298: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x161298u;
    {
        const bool branch_taken_0x161298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16129Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161298u;
            // 0x16129c: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161298) {
            ctx->pc = 0x1612D0u;
            goto label_1612d0;
        }
    }
    ctx->pc = 0x1612A0u;
label_1612a0:
    // 0x1612a0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1612A0u;
    SET_GPR_U32(ctx, 31, 0x1612A8u);
    ctx->pc = 0x1612A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1612A0u;
            // 0x1612a4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612A8u; }
        if (ctx->pc != 0x1612A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612A8u; }
        if (ctx->pc != 0x1612A8u) { return; }
    }
    ctx->pc = 0x1612A8u;
label_1612a8:
    // 0x1612a8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1612a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612ac: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1612acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612b0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1612b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612b4: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x1612B4u;
    SET_GPR_U32(ctx, 31, 0x1612BCu);
    ctx->pc = 0x1612B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1612B4u;
            // 0x1612b8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612BCu; }
        if (ctx->pc != 0x1612BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612BCu; }
        if (ctx->pc != 0x1612BCu) { return; }
    }
    ctx->pc = 0x1612BCu;
label_1612bc:
    // 0x1612bc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1612bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1612c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612c4: 0xc05f284  jal         func_17CA10
    ctx->pc = 0x1612C4u;
    SET_GPR_U32(ctx, 31, 0x1612CCu);
    ctx->pc = 0x1612C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1612C4u;
            // 0x1612c8: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CA10u;
    if (runtime->hasFunction(0x17CA10u)) {
        auto targetFn = runtime->lookupFunction(0x17CA10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612CCu; }
        if (ctx->pc != 0x1612CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CA10_0x17ca10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612CCu; }
        if (ctx->pc != 0x1612CCu) { return; }
    }
    ctx->pc = 0x1612CCu;
label_1612cc:
    // 0x1612cc: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x1612ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1612d0:
    // 0x1612d0: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x1612d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x1612d4: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x1612d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1612d8: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x1612d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1612dc: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x1612dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1612e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1612E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1612E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1612E0u;
            // 0x1612e4: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1612E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
