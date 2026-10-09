#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B360
// Address: 0x15b360 - 0x15b410
void sub_0015B360_0x15b360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B360_0x15b360");
#endif

    switch (ctx->pc) {
        case 0x15b3b8u: goto label_15b3b8;
        case 0x15b3c4u: goto label_15b3c4;
        case 0x15b3dcu: goto label_15b3dc;
        default: break;
    }

    ctx->pc = 0x15b360u;

    // 0x15b360: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15b360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15b364: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x15b364u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x15b368: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15b368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15b36c: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x15b36cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b370: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15b370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15b374: 0x138940  sll         $s1, $s3, 5
    ctx->pc = 0x15b374u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 19), 5));
    // 0x15b378: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15b378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15b37c: 0x24b2003f  addiu       $s2, $a1, 0x3F
    ctx->pc = 0x15b37cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), 63));
    // 0x15b380: 0x2338823  subu        $s1, $s1, $s3
    ctx->pc = 0x15b380u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x15b384: 0x2429024  and         $s2, $s2, $v0
    ctx->pc = 0x15b384u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) & GPR_U64(ctx, 2));
    // 0x15b388: 0x118940  sll         $s1, $s1, 5
    ctx->pc = 0x15b388u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 5));
    // 0x15b38c: 0x133200  sll         $a2, $s3, 8
    ctx->pc = 0x15b38cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 19), 8));
    // 0x15b390: 0x2518821  addu        $s1, $s2, $s1
    ctx->pc = 0x15b390u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x15b394: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x15b394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x15b398: 0x24c60800  addiu       $a2, $a2, 0x800
    ctx->pc = 0x15b398u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2048));
    // 0x15b39c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15b39cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b3a0: 0x26341520  addiu       $s4, $s1, 0x1520
    ctx->pc = 0x15b3a0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 5408));
    // 0x15b3a4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15b3a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b3a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15b3a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15b3ac: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x15b3acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x15b3b0: 0xc0558b4  jal         func_1562D0
    ctx->pc = 0x15B3B0u;
    SET_GPR_U32(ctx, 31, 0x15B3B8u);
    ctx->pc = 0x15B3B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B3B0u;
            // 0x15b3b4: 0x3c100026  lui         $s0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1562D0u;
    if (runtime->hasFunction(0x1562D0u)) {
        auto targetFn = runtime->lookupFunction(0x1562D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B3B8u; }
        if (ctx->pc != 0x15B3B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001562D0_0x1562d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B3B8u; }
        if (ctx->pc != 0x15B3B8u) { return; }
    }
    ctx->pc = 0x15B3B8u;
label_15b3b8:
    // 0x15b3b8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x15b3b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b3bc: 0xc056da4  jal         func_15B690
    ctx->pc = 0x15B3BCu;
    SET_GPR_U32(ctx, 31, 0x15B3C4u);
    ctx->pc = 0x15B3C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B3BCu;
            // 0x15b3c0: 0x24050ae0  addiu       $a1, $zero, 0xAE0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2784));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B690u;
    if (runtime->hasFunction(0x15B690u)) {
        auto targetFn = runtime->lookupFunction(0x15B690u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B3C4u; }
        if (ctx->pc != 0x15B3C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B690_0x15b690(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B3C4u; }
        if (ctx->pc != 0x15B3C4u) { return; }
    }
    ctx->pc = 0x15B3C4u;
label_15b3c4:
    // 0x15b3c4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x15b3c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x15b3c8: 0x26104c70  addiu       $s0, $s0, 0x4C70
    ctx->pc = 0x15b3c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 19568));
    // 0x15b3cc: 0x24a5e610  addiu       $a1, $a1, -0x19F0
    ctx->pc = 0x15b3ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294960656));
    // 0x15b3d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15b3d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b3d4: 0xc05583c  jal         func_1560F0
    ctx->pc = 0x15B3D4u;
    SET_GPR_U32(ctx, 31, 0x15B3DCu);
    ctx->pc = 0x15B3D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B3D4u;
            // 0x15b3d8: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1560F0u;
    if (runtime->hasFunction(0x1560F0u)) {
        auto targetFn = runtime->lookupFunction(0x1560F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B3DCu; }
        if (ctx->pc != 0x15B3DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001560F0_0x1560f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B3DCu; }
        if (ctx->pc != 0x15B3DCu) { return; }
    }
    ctx->pc = 0x15B3DCu;
label_15b3dc:
    // 0x15b3dc: 0xae11004c  sw          $s1, 0x4C($s0)
    ctx->pc = 0x15b3dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 17));
    // 0x15b3e0: 0xae120058  sw          $s2, 0x58($s0)
    ctx->pc = 0x15b3e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 18));
    // 0x15b3e4: 0xae140050  sw          $s4, 0x50($s0)
    ctx->pc = 0x15b3e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 20));
    // 0x15b3e8: 0xae130054  sw          $s3, 0x54($s0)
    ctx->pc = 0x15b3e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 19));
    // 0x15b3ec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15b3ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b3f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15b3f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b3f4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15b3f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15b3f8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15b3f8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15b3fc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x15b3fcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15b400: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x15b400u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15b404: 0x3e00008  jr          $ra
    ctx->pc = 0x15B404u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B404u;
            // 0x15b408: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B3B8u: goto label_15b3b8;
            case 0x15B3C4u: goto label_15b3c4;
            case 0x15B3DCu: goto label_15b3dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B40Cu;
    // 0x15b40c: 0x0  nop
    ctx->pc = 0x15b40cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
