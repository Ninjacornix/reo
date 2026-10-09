#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B3B0
// Address: 0x16b3b0 - 0x16b410
void sub_0016B3B0_0x16b3b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B3B0_0x16b3b0");
#endif

    switch (ctx->pc) {
        case 0x16b3dcu: goto label_16b3dc;
        case 0x16b3ecu: goto label_16b3ec;
        default: break;
    }

    ctx->pc = 0x16b3b0u;

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
