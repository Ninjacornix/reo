#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B360
// Address: 0x17b360 - 0x17b45c
void sub_0017B360_0x17b360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B360_0x17b360");
#endif

    switch (ctx->pc) {
        case 0x17b3e8u: goto label_17b3e8;
        case 0x17b43cu: goto label_17b43c;
        default: break;
    }

    ctx->pc = 0x17b360u;

    // 0x17b360: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17b360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17b364: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x17b364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x17b368: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17b368u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b36c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x17b36cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x17b370: 0x26320004  addiu       $s2, $s1, 0x4
    ctx->pc = 0x17b370u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x17b374: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x17b374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x17b378: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x17b378u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b37c: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x17b37cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x17b380: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x17b380u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b384: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x17b384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x17b388: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b388u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b38c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x17b38cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x17b390: 0x8e230048  lw          $v1, 0x48($s1)
    ctx->pc = 0x17b390u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x17b394: 0x8e270044  lw          $a3, 0x44($s1)
    ctx->pc = 0x17b394u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x17b398: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17b398u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17b39c: 0x8e680008  lw          $t0, 0x8($s3)
    ctx->pc = 0x17b39cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x17b3a0: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x17b3a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x17b3a4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x17b3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17b3a8: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17b3a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17b3ac: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x17b3acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x17b3b0: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x17b3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x17b3b4: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x17b3b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x17b3b8: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x17b3b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x17b3bc: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x17b3bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x17b3c0: 0x15000005  bnez        $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17B3C0u;
    {
        const bool branch_taken_0x17b3c0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x17B3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B3C0u;
            // 0x17b3c4: 0xafb40010  sw          $s4, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b3c0) {
            ctx->pc = 0x17B3D8u;
            goto label_17b3d8;
        }
    }
    ctx->pc = 0x17B3C8u;
    // 0x17b3c8: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x17b3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x17b3cc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17b3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17b3d0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x17B3D0u;
    {
        const bool branch_taken_0x17b3d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B3D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B3D0u;
            // 0x17b3d4: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b3d0) {
            ctx->pc = 0x17B3DCu;
            goto label_17b3dc;
        }
    }
    ctx->pc = 0x17B3D8u;
label_17b3d8:
    // 0x17b3d8: 0xafa8001c  sw          $t0, 0x1C($sp)
    ctx->pc = 0x17b3d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 8));
label_17b3dc:
    // 0x17b3dc: 0x27b00010  addiu       $s0, $sp, 0x10
    ctx->pc = 0x17b3dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17b3e0: 0xc053df2  jal         func_14F7C8
    ctx->pc = 0x17B3E0u;
    SET_GPR_U32(ctx, 31, 0x17B3E8u);
    ctx->pc = 0x17B3E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B3E0u;
            // 0x17b3e4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F7C8u;
    if (runtime->hasFunction(0x14F7C8u)) {
        auto targetFn = runtime->lookupFunction(0x14F7C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B3E8u; }
        if (ctx->pc != 0x17B3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F7C8_0x14f7c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B3E8u; }
        if (ctx->pc != 0x17B3E8u) { return; }
    }
    ctx->pc = 0x17B3E8u;
label_17b3e8:
    // 0x17b3e8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17b3e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b3ec: 0x8e260048  lw          $a2, 0x48($s1)
    ctx->pc = 0x17b3ecu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x17b3f0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b3f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b3f4: 0x8e230044  lw          $v1, 0x44($s1)
    ctx->pc = 0x17b3f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x17b3f8: 0x8e670008  lw          $a3, 0x8($s3)
    ctx->pc = 0x17b3f8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x17b3fc: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x17b3fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x17b400: 0xafa30014  sw          $v1, 0x14($sp)
    ctx->pc = 0x17b400u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x17b404: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x17b404u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x17b408: 0xafb40010  sw          $s4, 0x10($sp)
    ctx->pc = 0x17b408u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
    // 0x17b40c: 0xafa60018  sw          $a2, 0x18($sp)
    ctx->pc = 0x17b40cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 6));
    // 0x17b410: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x17b410u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x17b414: 0x14e00006  bnez        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x17B414u;
    {
        const bool branch_taken_0x17b414 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x17B418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B414u;
            // 0x17b418: 0xafa60008  sw          $a2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b414) {
            ctx->pc = 0x17B430u;
            goto label_17b430;
        }
    }
    ctx->pc = 0x17B41Cu;
    // 0x17b41c: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x17b41cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x17b420: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17b420u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17b424: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17B424u;
    {
        const bool branch_taken_0x17b424 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B424u;
            // 0x17b428: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b424) {
            ctx->pc = 0x17B434u;
            goto label_17b434;
        }
    }
    ctx->pc = 0x17B42Cu;
    // 0x17b42c: 0x0  nop
    ctx->pc = 0x17b42cu;
    // NOP
label_17b430:
    // 0x17b430: 0xafa7001c  sw          $a3, 0x1C($sp)
    ctx->pc = 0x17b430u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 7));
label_17b434:
    // 0x17b434: 0xc054000  jal         func_150000
    ctx->pc = 0x17B434u;
    SET_GPR_U32(ctx, 31, 0x17B43Cu);
    ctx->pc = 0x17B438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B434u;
            // 0x17b438: 0x8e66003c  lw          $a2, 0x3C($s3) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 60)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150000u;
    if (runtime->hasFunction(0x150000u)) {
        auto targetFn = runtime->lookupFunction(0x150000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B43Cu; }
        if (ctx->pc != 0x17B43Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150000_0x150000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B43Cu; }
        if (ctx->pc != 0x17B43Cu) { return; }
    }
    ctx->pc = 0x17B43Cu;
label_17b43c:
    // 0x17b43c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x17b43cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17b440: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x17b440u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17b444: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x17b444u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17b448: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x17b448u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17b44c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x17b44cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17b450: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x17b450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17b454: 0x3e00008  jr          $ra
    ctx->pc = 0x17B454u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B454u;
            // 0x17b458: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B3D8u: goto label_17b3d8;
            case 0x17B3DCu: goto label_17b3dc;
            case 0x17B3E8u: goto label_17b3e8;
            case 0x17B430u: goto label_17b430;
            case 0x17B434u: goto label_17b434;
            case 0x17B43Cu: goto label_17b43c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B45Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
