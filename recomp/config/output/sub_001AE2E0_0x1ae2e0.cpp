#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE2E0
// Address: 0x1ae2e0 - 0x1ae3d0
void sub_001AE2E0_0x1ae2e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE2E0_0x1ae2e0");
#endif

    switch (ctx->pc) {
        case 0x1ae33cu: goto label_1ae33c;
        case 0x1ae37cu: goto label_1ae37c;
        case 0x1ae39cu: goto label_1ae39c;
        default: break;
    }

    ctx->pc = 0x1ae2e0u;

    // 0x1ae2e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ae2e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ae2e4: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1ae2e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1ae2e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ae2e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ae2ec: 0x10a3002d  beq         $a1, $v1, . + 4 + (0x2D << 2)
    ctx->pc = 0x1AE2ECu;
    {
        const bool branch_taken_0x1ae2ec = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AE2F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE2ECu;
            // 0x1ae2f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae2ec) {
            ctx->pc = 0x1AE3A4u;
            goto label_1ae3a4;
        }
    }
    ctx->pc = 0x1AE2F4u;
    // 0x1ae2f4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1ae2f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ae2f8: 0x10a30022  beq         $a1, $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x1AE2F8u;
    {
        const bool branch_taken_0x1ae2f8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AE2FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE2F8u;
            // 0x1ae2fc: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae2f8) {
            ctx->pc = 0x1AE384u;
            goto label_1ae384;
        }
    }
    ctx->pc = 0x1AE300u;
    // 0x1ae300: 0x10a30017  beq         $a1, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1AE300u;
    {
        const bool branch_taken_0x1ae300 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ae300) {
            ctx->pc = 0x1AE360u;
            goto label_1ae360;
        }
    }
    ctx->pc = 0x1AE308u;
    // 0x1ae308: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ae308u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ae30c: 0x10a3000d  beq         $a1, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1AE30Cu;
    {
        const bool branch_taken_0x1ae30c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AE310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE30Cu;
            // 0x1ae310: 0x41840  sll         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae30c) {
            ctx->pc = 0x1AE344u;
            goto label_1ae344;
        }
    }
    ctx->pc = 0x1AE314u;
    // 0x1ae314: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE314u;
    {
        const bool branch_taken_0x1ae314 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae314) {
            ctx->pc = 0x1AE324u;
            goto label_1ae324;
        }
    }
    ctx->pc = 0x1AE31Cu;
    // 0x1ae31c: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1AE31Cu;
    {
        const bool branch_taken_0x1ae31c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE31Cu;
            // 0x1ae320: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae31c) {
            ctx->pc = 0x1AE3C4u;
            goto label_1ae3c4;
        }
    }
    ctx->pc = 0x1AE324u;
label_1ae324:
    // 0x1ae324: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae324u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae328: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ae328u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae32c: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae32cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae330: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae334: 0xc04c7be  jal         func_131EF8
    ctx->pc = 0x1AE334u;
    SET_GPR_U32(ctx, 31, 0x1AE33Cu);
    ctx->pc = 0x1AE338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE334u;
            // 0x1ae338: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131EF8u;
    if (runtime->hasFunction(0x131EF8u)) {
        auto targetFn = runtime->lookupFunction(0x131EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE33Cu; }
        if (ctx->pc != 0x1AE33Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE33Cu; }
        if (ctx->pc != 0x1AE33Cu) { return; }
    }
    ctx->pc = 0x1AE33Cu;
label_1ae33c:
    // 0x1ae33c: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1AE33Cu;
    {
        const bool branch_taken_0x1ae33c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae33c) {
            ctx->pc = 0x1AE3C0u;
            goto label_1ae3c0;
        }
    }
    ctx->pc = 0x1AE344u;
label_1ae344:
    // 0x1ae344: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae344u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae348: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1ae348u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae34c: 0x24428d74  addiu       $v0, $v0, -0x728C
    ctx->pc = 0x1ae34cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937972));
    // 0x1ae350: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1ae350u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae354: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae354u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae358: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1AE358u;
    {
        const bool branch_taken_0x1ae358 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE35Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE358u;
            // 0x1ae35c: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae358) {
            ctx->pc = 0x1AE3C0u;
            goto label_1ae3c0;
        }
    }
    ctx->pc = 0x1AE360u;
label_1ae360:
    // 0x1ae360: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae360u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae364: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ae364u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae368: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae36c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae36cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae370: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ae370u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae374: 0xc04c9bc  jal         func_1326F0
    ctx->pc = 0x1AE374u;
    SET_GPR_U32(ctx, 31, 0x1AE37Cu);
    ctx->pc = 0x1AE378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE374u;
            // 0x1ae378: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1326F0u;
    if (runtime->hasFunction(0x1326F0u)) {
        auto targetFn = runtime->lookupFunction(0x1326F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE37Cu; }
        if (ctx->pc != 0x1AE37Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001326F0_0x1326f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE37Cu; }
        if (ctx->pc != 0x1AE37Cu) { return; }
    }
    ctx->pc = 0x1AE37Cu;
label_1ae37c:
    // 0x1ae37c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1AE37Cu;
    {
        const bool branch_taken_0x1ae37c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae37c) {
            ctx->pc = 0x1AE3C0u;
            goto label_1ae3c0;
        }
    }
    ctx->pc = 0x1AE384u;
label_1ae384:
    // 0x1ae384: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae384u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae388: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ae388u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae38c: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae38cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae390: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae394: 0xc04cb3c  jal         func_132CF0
    ctx->pc = 0x1AE394u;
    SET_GPR_U32(ctx, 31, 0x1AE39Cu);
    ctx->pc = 0x1AE398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE394u;
            // 0x1ae398: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132CF0u;
    if (runtime->hasFunction(0x132CF0u)) {
        auto targetFn = runtime->lookupFunction(0x132CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE39Cu; }
        if (ctx->pc != 0x1AE39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132CF0_0x132cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE39Cu; }
        if (ctx->pc != 0x1AE39Cu) { return; }
    }
    ctx->pc = 0x1AE39Cu;
label_1ae39c:
    // 0x1ae39c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AE39Cu;
    {
        const bool branch_taken_0x1ae39c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae39c) {
            ctx->pc = 0x1AE3C0u;
            goto label_1ae3c0;
        }
    }
    ctx->pc = 0x1AE3A4u;
label_1ae3a4:
    // 0x1ae3a4: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1ae3a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ae3a8: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae3a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae3ac: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1ae3acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae3b0: 0x24428d70  addiu       $v0, $v0, -0x7290
    ctx->pc = 0x1ae3b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937968));
    // 0x1ae3b4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1ae3b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae3b8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae3b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae3bc: 0x80420000  lb          $v0, 0x0($v0)
    ctx->pc = 0x1ae3bcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_1ae3c0:
    // 0x1ae3c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ae3c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1ae3c4:
    // 0x1ae3c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE3C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE3C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE3C4u;
            // 0x1ae3c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE324u: goto label_1ae324;
            case 0x1AE33Cu: goto label_1ae33c;
            case 0x1AE344u: goto label_1ae344;
            case 0x1AE360u: goto label_1ae360;
            case 0x1AE37Cu: goto label_1ae37c;
            case 0x1AE384u: goto label_1ae384;
            case 0x1AE39Cu: goto label_1ae39c;
            case 0x1AE3A4u: goto label_1ae3a4;
            case 0x1AE3C0u: goto label_1ae3c0;
            case 0x1AE3C4u: goto label_1ae3c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE3CCu;
    // 0x1ae3cc: 0x0  nop
    ctx->pc = 0x1ae3ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
