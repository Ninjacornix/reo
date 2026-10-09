#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B340
// Address: 0x16b340 - 0x16b410
void sub_0016B340_0x16b340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B340_0x16b340");
#endif

    switch (ctx->pc) {
        case 0x16b368u: goto label_16b368;
        case 0x16b378u: goto label_16b378;
        case 0x16b38cu: goto label_16b38c;
        case 0x16b3dcu: goto label_16b3dc;
        case 0x16b3ecu: goto label_16b3ec;
        default: break;
    }

    ctx->pc = 0x16b340u;

    // 0x16b340: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16b340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16b344: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b348: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16b348u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b34c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16b34cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16b350: 0x26111ae4  addiu       $s1, $s0, 0x1AE4
    ctx->pc = 0x16b350u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 6884));
    // 0x16b354: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16b354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16b358: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16b358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16b35c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16b35cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16b360: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x16B360u;
    SET_GPR_U32(ctx, 31, 0x16B368u);
    ctx->pc = 0x16B364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B360u;
            // 0x16b364: 0x8e250018  lw          $a1, 0x18($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B368u; }
        if (ctx->pc != 0x16B368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B368u; }
        if (ctx->pc != 0x16B368u) { return; }
    }
    ctx->pc = 0x16B368u;
label_16b368:
    // 0x16b368: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b36c: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x16b36cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x16b370: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x16B370u;
    SET_GPR_U32(ctx, 31, 0x16B378u);
    ctx->pc = 0x16B374u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B370u;
            // 0x16b374: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B378u; }
        if (ctx->pc != 0x16B378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B378u; }
        if (ctx->pc != 0x16B378u) { return; }
    }
    ctx->pc = 0x16B378u;
label_16b378:
    // 0x16b378: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b378u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b37c: 0x8e25001c  lw          $a1, 0x1C($s1)
    ctx->pc = 0x16b37cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x16b380: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x16b380u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b384: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x16B384u;
    SET_GPR_U32(ctx, 31, 0x16B38Cu);
    ctx->pc = 0x16B388u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B384u;
            // 0x16b388: 0x2539025  or          $s2, $s2, $s3 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B38Cu; }
        if (ctx->pc != 0x16B38Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B38Cu; }
        if (ctx->pc != 0x16B38Cu) { return; }
    }
    ctx->pc = 0x16B38Cu;
label_16b38c:
    // 0x16b38c: 0x2421025  or          $v0, $s2, $v0
    ctx->pc = 0x16b38cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x16b390: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b390u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b394: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b394u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b398: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b398u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b39c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16b39cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b3a0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16b3a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16b3a4: 0x3e00008  jr          $ra
    ctx->pc = 0x16B3A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B3A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B3A4u;
            // 0x16b3a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B368u: goto label_16b368;
            case 0x16B378u: goto label_16b378;
            case 0x16B38Cu: goto label_16b38c;
            case 0x16B3DCu: goto label_16b3dc;
            case 0x16B3ECu: goto label_16b3ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B3ACu;
    // 0x16b3ac: 0x0  nop
    ctx->pc = 0x16b3acu;
    // NOP
    // 0x16b3b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16b3b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16b3b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b3b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b3b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16b3b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b3bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16b3bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16b3c0: 0x26111ae4  addiu       $s1, $s0, 0x1AE4
    ctx->pc = 0x16b3c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 6884));
    // 0x16b3c4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16b3c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16b3c8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16b3c8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b3cc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16b3ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16b3d0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x16b3d0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b3d4: 0xc059f28  jal         func_167CA0
    ctx->pc = 0x16B3D4u;
    SET_GPR_U32(ctx, 31, 0x16B3DCu);
    ctx->pc = 0x16B3D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B3D4u;
            // 0x16b3d8: 0x8e250018  lw          $a1, 0x18($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CA0u;
    if (runtime->hasFunction(0x167CA0u)) {
        auto targetFn = runtime->lookupFunction(0x167CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B3DCu; }
        if (ctx->pc != 0x16B3DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CA0_0x167ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B3DCu; }
        if (ctx->pc != 0x16B3DCu) { return; }
    }
    ctx->pc = 0x16B3DCu;
label_16b3dc:
    // 0x16b3dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b3dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b3e0: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x16b3e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x16b3e4: 0xc059f28  jal         func_167CA0
    ctx->pc = 0x16B3E4u;
    SET_GPR_U32(ctx, 31, 0x16B3ECu);
    ctx->pc = 0x16B3E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B3E4u;
            // 0x16b3e8: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CA0u;
    if (runtime->hasFunction(0x167CA0u)) {
        auto targetFn = runtime->lookupFunction(0x167CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B3ECu; }
        if (ctx->pc != 0x16B3ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CA0_0x167ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B3ECu; }
        if (ctx->pc != 0x16B3ECu) { return; }
    }
    ctx->pc = 0x16B3ECu;
label_16b3ec:
    // 0x16b3ec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b3ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b3f0: 0x8e25001c  lw          $a1, 0x1C($s1)
    ctx->pc = 0x16b3f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x16b3f4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x16b3f4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b3f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b3f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b3fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b3fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b400: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b400u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b404: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16b404u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b408: 0x8059f28  j           func_167CA0
    ctx->pc = 0x16B408u;
    ctx->pc = 0x16B40Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B408u;
            // 0x16b40c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CA0u;
    if (runtime->hasFunction(0x167CA0u)) {
        auto targetFn = runtime->lookupFunction(0x167CA0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00167CA0_0x167ca0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B410u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
