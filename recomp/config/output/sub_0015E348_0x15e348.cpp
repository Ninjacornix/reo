#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E348
// Address: 0x15e348 - 0x15e3ec
void sub_0015E348_0x15e348(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E348_0x15e348");
#endif

    switch (ctx->pc) {
        case 0x15e368u: goto label_15e368;
        case 0x15e3a8u: goto label_15e3a8;
        case 0x15e3c0u: goto label_15e3c0;
        default: break;
    }

    ctx->pc = 0x15e348u;

    // 0x15e348: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15e348u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15e34c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15e34cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15e350: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15e350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15e354: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15e354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15e358: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15e358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15e35c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15e35cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15e360: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15E360u;
    SET_GPR_U32(ctx, 31, 0x15E368u);
    ctx->pc = 0x15E364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E360u;
            // 0x15e364: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E368u; }
        if (ctx->pc != 0x15E368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E368u; }
        if (ctx->pc != 0x15E368u) { return; }
    }
    ctx->pc = 0x15E368u;
label_15e368:
    // 0x15e368: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x15E368u;
    {
        const bool branch_taken_0x15e368 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15E36Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E368u;
            // 0x15e36c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e368) {
            ctx->pc = 0x15E398u;
            goto label_15e398;
        }
    }
    ctx->pc = 0x15E370u;
    // 0x15e370: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15e370u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15e374: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e374u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e378: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15e378u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e37c: 0x2484ed28  addiu       $a0, $a0, -0x12D8
    ctx->pc = 0x15e37cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962472));
    // 0x15e380: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15e380u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e384: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15e384u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15e388: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15e388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15e38c: 0x8058dd4  j           func_163750
    ctx->pc = 0x15E38Cu;
    ctx->pc = 0x15E390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E38Cu;
            // 0x15e390: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15E394u;
    // 0x15e394: 0x0  nop
    ctx->pc = 0x15e394u;
    // NOP
label_15e398:
    // 0x15e398: 0x8e72007c  lw          $s2, 0x7C($s3)
    ctx->pc = 0x15e398u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 124)));
    // 0x15e39c: 0x8e700080  lw          $s0, 0x80($s3)
    ctx->pc = 0x15e39cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 128)));
    // 0x15e3a0: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x15E3A0u;
    SET_GPR_U32(ctx, 31, 0x15E3A8u);
    ctx->pc = 0x15E3A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E3A0u;
            // 0x15e3a4: 0x8e710078  lw          $s1, 0x78($s3) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 120)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E3A8u; }
        if (ctx->pc != 0x15E3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E3A8u; }
        if (ctx->pc != 0x15E3A8u) { return; }
    }
    ctx->pc = 0x15E3A8u;
label_15e3a8:
    // 0x15e3a8: 0x212802a  slt         $s0, $s0, $s2
    ctx->pc = 0x15e3a8u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x15e3ac: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15e3acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e3b0: 0x12000007  beqz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15E3B0u;
    {
        const bool branch_taken_0x15e3b0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E3B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E3B0u;
            // 0x15e3b4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e3b0) {
            ctx->pc = 0x15E3D0u;
            goto label_15e3d0;
        }
    }
    ctx->pc = 0x15E3B8u;
    // 0x15e3b8: 0xc05d00c  jal         func_174030
    ctx->pc = 0x15E3B8u;
    SET_GPR_U32(ctx, 31, 0x15E3C0u);
    ctx->pc = 0x174030u;
    if (runtime->hasFunction(0x174030u)) {
        auto targetFn = runtime->lookupFunction(0x174030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E3C0u; }
        if (ctx->pc != 0x15E3C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174030_0x174030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E3C0u; }
        if (ctx->pc != 0x15E3C0u) { return; }
    }
    ctx->pc = 0x15E3C0u;
label_15e3c0:
    // 0x15e3c0: 0x8e630080  lw          $v1, 0x80($s3)
    ctx->pc = 0x15e3c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 128)));
    // 0x15e3c4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x15e3c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x15e3c8: 0xae63007c  sw          $v1, 0x7C($s3)
    ctx->pc = 0x15e3c8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 124), GPR_U32(ctx, 3));
    // 0x15e3cc: 0xae630080  sw          $v1, 0x80($s3)
    ctx->pc = 0x15e3ccu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 128), GPR_U32(ctx, 3));
label_15e3d0:
    // 0x15e3d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e3d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e3d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15e3d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e3d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15e3d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e3dc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15e3dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15e3e0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15e3e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15e3e4: 0x3e00008  jr          $ra
    ctx->pc = 0x15E3E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E3E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E3E4u;
            // 0x15e3e8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E368u: goto label_15e368;
            case 0x15E398u: goto label_15e398;
            case 0x15E3A8u: goto label_15e3a8;
            case 0x15E3C0u: goto label_15e3c0;
            case 0x15E3D0u: goto label_15e3d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E3ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
