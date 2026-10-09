#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160F88
// Address: 0x160f88 - 0x161030
void sub_00160F88_0x160f88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160F88_0x160f88");
#endif

    switch (ctx->pc) {
        case 0x160fb0u: goto label_160fb0;
        case 0x160fc4u: goto label_160fc4;
        case 0x160fe0u: goto label_160fe0;
        case 0x160ff0u: goto label_160ff0;
        case 0x161004u: goto label_161004;
        case 0x161014u: goto label_161014;
        default: break;
    }

    ctx->pc = 0x160f88u;

    // 0x160f88: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x160f88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x160f8c: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x160f8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x160f90: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x160f90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160f94: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x160f94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x160f98: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x160f98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160f9c: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x160f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x160fa0: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x160fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x160fa4: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x160fa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x160fa8: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160FA8u;
    SET_GPR_U32(ctx, 31, 0x160FB0u);
    ctx->pc = 0x160FACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FA8u;
            // 0x160fac: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FB0u; }
        if (ctx->pc != 0x160FB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FB0u; }
        if (ctx->pc != 0x160FB0u) { return; }
    }
    ctx->pc = 0x160FB0u;
label_160fb0:
    // 0x160fb0: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x160FB0u;
    {
        const bool branch_taken_0x160fb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x160fb0) {
            ctx->pc = 0x160FB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x160FB0u;
            // 0x160fb4: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x160FD0u;
            goto label_160fd0;
        }
    }
    ctx->pc = 0x160FB8u;
    // 0x160fb8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160fb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160fbc: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160FBCu;
    SET_GPR_U32(ctx, 31, 0x160FC4u);
    ctx->pc = 0x160FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FBCu;
            // 0x160fc0: 0x2484f940  addiu       $a0, $a0, -0x6C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FC4u; }
        if (ctx->pc != 0x160FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FC4u; }
        if (ctx->pc != 0x160FC4u) { return; }
    }
    ctx->pc = 0x160FC4u;
label_160fc4:
    // 0x160fc4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x160FC4u;
    {
        const bool branch_taken_0x160fc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160FC4u;
            // 0x160fc8: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160fc4) {
            ctx->pc = 0x161018u;
            goto label_161018;
        }
    }
    ctx->pc = 0x160FCCu;
    // 0x160fcc: 0x0  nop
    ctx->pc = 0x160fccu;
    // NOP
label_160fd0:
    // 0x160fd0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x160FD0u;
    {
        const bool branch_taken_0x160fd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160FD0u;
            // 0x160fd4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160fd0) {
            ctx->pc = 0x160FE8u;
            goto label_160fe8;
        }
    }
    ctx->pc = 0x160FD8u;
    // 0x160fd8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160FD8u;
    SET_GPR_U32(ctx, 31, 0x160FE0u);
    ctx->pc = 0x160FDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FD8u;
            // 0x160fdc: 0x2484f978  addiu       $a0, $a0, -0x688 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FE0u; }
        if (ctx->pc != 0x160FE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FE0u; }
        if (ctx->pc != 0x160FE0u) { return; }
    }
    ctx->pc = 0x160FE0u;
label_160fe0:
    // 0x160fe0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x160FE0u;
    {
        const bool branch_taken_0x160fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160FE0u;
            // 0x160fe4: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160fe0) {
            ctx->pc = 0x161018u;
            goto label_161018;
        }
    }
    ctx->pc = 0x160FE8u;
label_160fe8:
    // 0x160fe8: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x160FE8u;
    SET_GPR_U32(ctx, 31, 0x160FF0u);
    ctx->pc = 0x160FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FE8u;
            // 0x160fec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FF0u; }
        if (ctx->pc != 0x160FF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FF0u; }
        if (ctx->pc != 0x160FF0u) { return; }
    }
    ctx->pc = 0x160FF0u;
label_160ff0:
    // 0x160ff0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x160ff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ff4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x160ff4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ff8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x160ff8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ffc: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x160FFCu;
    SET_GPR_U32(ctx, 31, 0x161004u);
    ctx->pc = 0x161000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FFCu;
            // 0x161000: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161004u; }
        if (ctx->pc != 0x161004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161004u; }
        if (ctx->pc != 0x161004u) { return; }
    }
    ctx->pc = 0x161004u;
label_161004:
    // 0x161004: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161004u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161008: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161008u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16100c: 0xc05ea06  jal         func_17A818
    ctx->pc = 0x16100Cu;
    SET_GPR_U32(ctx, 31, 0x161014u);
    ctx->pc = 0x161010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16100Cu;
            // 0x161010: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A818u;
    if (runtime->hasFunction(0x17A818u)) {
        auto targetFn = runtime->lookupFunction(0x17A818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161014u; }
        if (ctx->pc != 0x161014u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A818_0x17a818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161014u; }
        if (ctx->pc != 0x161014u) { return; }
    }
    ctx->pc = 0x161014u;
label_161014:
    // 0x161014: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161014u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161018:
    // 0x161018: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161018u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x16101c: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x16101cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161020: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161020u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161024: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x161024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161028: 0x3e00008  jr          $ra
    ctx->pc = 0x161028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16102Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161028u;
            // 0x16102c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161030u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
