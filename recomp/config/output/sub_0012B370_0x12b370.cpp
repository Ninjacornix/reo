#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B370
// Address: 0x12b370 - 0x12b3f8
void sub_0012B370_0x12b370(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B370_0x12b370");
#endif

    switch (ctx->pc) {
        case 0x12b3c4u: goto label_12b3c4;
        case 0x12b3d8u: goto label_12b3d8;
        case 0x12b3e8u: goto label_12b3e8;
        default: break;
    }

    ctx->pc = 0x12b370u;

    // 0x12b370: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b370u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b374: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12b374u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12b378: 0x8c477d78  lw          $a3, 0x7D78($v0)
    ctx->pc = 0x12b378u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32120)));
    // 0x12b37c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x12b37cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x12b380: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12b380u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12b384: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b384u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b388: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b38c: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12b38cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12b390: 0x24632d70  addiu       $v1, $v1, 0x2D70
    ctx->pc = 0x12b390u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 11632));
    // 0x12b394: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12b394u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b398: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x12b398u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x12b39c: 0x24a5ad70  addiu       $a1, $a1, -0x5290
    ctx->pc = 0x12b39cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294946160));
    // 0x12b3a0: 0x24421cf0  addiu       $v0, $v0, 0x1CF0
    ctx->pc = 0x12b3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7408));
    // 0x12b3a4: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12b3a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12b3a8: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x12b3a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x12b3ac: 0x261004e4  addiu       $s0, $s0, 0x4E4
    ctx->pc = 0x12b3acu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1252));
    // 0x12b3b0: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x12b3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x12b3b4: 0xafa6000c  sw          $a2, 0xC($sp)
    ctx->pc = 0x12b3b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 6));
    // 0x12b3b8: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x12b3b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12b3bc: 0xc045108  jal         func_114420
    ctx->pc = 0x12B3BCu;
    SET_GPR_U32(ctx, 31, 0x12B3C4u);
    ctx->pc = 0x12B3C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B3BCu;
            // 0x12b3c0: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B3C4u; }
        if (ctx->pc != 0x12B3C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B3C4u; }
        if (ctx->pc != 0x12B3C4u) { return; }
    }
    ctx->pc = 0x12B3C4u;
label_12b3c4:
    // 0x12b3c4: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12b3c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x12b3c8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12b3c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b3cc: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12b3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b3d0: 0xc045110  jal         func_114440
    ctx->pc = 0x12B3D0u;
    SET_GPR_U32(ctx, 31, 0x12B3D8u);
    ctx->pc = 0x12B3D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B3D0u;
            // 0x12b3d4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B3D8u; }
        if (ctx->pc != 0x12B3D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B3D8u; }
        if (ctx->pc != 0x12B3D8u) { return; }
    }
    ctx->pc = 0x12B3D8u;
label_12b3d8:
    // 0x12b3d8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b3d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b3dc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b3dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b3e0: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B3E0u;
    SET_GPR_U32(ctx, 31, 0x12B3E8u);
    ctx->pc = 0x12B3E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B3E0u;
            // 0x12b3e4: 0x8c450470  lw          $a1, 0x470($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1136)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B3E8u; }
        if (ctx->pc != 0x12B3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B3E8u; }
        if (ctx->pc != 0x12B3E8u) { return; }
    }
    ctx->pc = 0x12B3E8u;
label_12b3e8:
    // 0x12b3e8: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b3e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b3ec: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12b3ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b3f0: 0x3e00008  jr          $ra
    ctx->pc = 0x12B3F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B3F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B3F0u;
            // 0x12b3f4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B3C4u: goto label_12b3c4;
            case 0x12B3D8u: goto label_12b3d8;
            case 0x12B3E8u: goto label_12b3e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B3F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
