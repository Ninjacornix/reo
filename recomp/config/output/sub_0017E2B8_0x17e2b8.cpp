#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E2B8
// Address: 0x17e2b8 - 0x17e31c
void sub_0017E2B8_0x17e2b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E2B8_0x17e2b8");
#endif

    switch (ctx->pc) {
        case 0x17e2dcu: goto label_17e2dc;
        case 0x17e2fcu: goto label_17e2fc;
        default: break;
    }

    ctx->pc = 0x17e2b8u;

    // 0x17e2b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17e2b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17e2bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17e2bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17e2c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17e2c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e2c4: 0xe7b50018  swc1        $f21, 0x18($sp)
    ctx->pc = 0x17e2c4u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 24), bits); }
    // 0x17e2c8: 0x46006546  mov.s       $f21, $f12
    ctx->pc = 0x17e2c8u;
    ctx->f[21] = FPU_MOV_S(ctx->f[12]);
    // 0x17e2cc: 0xe7b40010  swc1        $f20, 0x10($sp)
    ctx->pc = 0x17e2ccu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x17e2d0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17e2d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17e2d4: 0xc05f8c8  jal         func_17E320
    ctx->pc = 0x17E2D4u;
    SET_GPR_U32(ctx, 31, 0x17E2DCu);
    ctx->pc = 0x17E2D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E2D4u;
            // 0x17e2d8: 0x46006d06  mov.s       $f20, $f13 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E320u;
    if (runtime->hasFunction(0x17E320u)) {
        auto targetFn = runtime->lookupFunction(0x17E320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E2DCu; }
        if (ctx->pc != 0x17E2DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E320_0x17e320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E2DCu; }
        if (ctx->pc != 0x17E2DCu) { return; }
    }
    ctx->pc = 0x17E2DCu;
label_17e2dc:
    // 0x17e2dc: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17e2dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17e2e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17e2e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17e2e4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17e2e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e2e8: 0x24c61498  addiu       $a2, $a2, 0x1498
    ctx->pc = 0x17e2e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5272));
    // 0x17e2ec: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E2ECu;
    {
        const bool branch_taken_0x17e2ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17E2F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E2ECu;
            // 0x17e2f0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e2ec) {
            ctx->pc = 0x17E2FCu;
            goto label_17e2fc;
        }
    }
    ctx->pc = 0x17E2F4u;
    // 0x17e2f4: 0xc05f472  jal         func_17D1C8
    ctx->pc = 0x17E2F4u;
    SET_GPR_U32(ctx, 31, 0x17E2FCu);
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E2FCu; }
        if (ctx->pc != 0x17E2FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E2FCu; }
        if (ctx->pc != 0x17E2FCu) { return; }
    }
    ctx->pc = 0x17E2FCu;
label_17e2fc:
    // 0x17e2fc: 0xe6140040  swc1        $f20, 0x40($s0)
    ctx->pc = 0x17e2fcu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 64), bits); }
    // 0x17e300: 0xe615003c  swc1        $f21, 0x3C($s0)
    ctx->pc = 0x17e300u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 60), bits); }
    // 0x17e304: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17e304u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17e308: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17e308u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e30c: 0xc7b50018  lwc1        $f21, 0x18($sp)
    ctx->pc = 0x17e30cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17e310: 0xc7b40010  lwc1        $f20, 0x10($sp)
    ctx->pc = 0x17e310u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17e314: 0x3e00008  jr          $ra
    ctx->pc = 0x17E314u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E314u;
            // 0x17e318: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E2DCu: goto label_17e2dc;
            case 0x17E2FCu: goto label_17e2fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E31Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
