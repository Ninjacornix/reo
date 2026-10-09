#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192690
// Address: 0x192690 - 0x192708
void sub_00192690_0x192690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192690_0x192690");
#endif

    switch (ctx->pc) {
        case 0x1926c0u: goto label_1926c0;
        case 0x1926d0u: goto label_1926d0;
        case 0x1926e8u: goto label_1926e8;
        default: break;
    }

    ctx->pc = 0x192690u;

    // 0x192690: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x192690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x192694: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x192694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x192698: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x192698u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x19269c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x19269cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1926a0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1926a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1926a4: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x1926a4u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x1926a8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1926a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1926ac: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1926acu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1926b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1926b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1926b4: 0x46006546  mov.s       $f21, $f12
    ctx->pc = 0x1926b4u;
    ctx->f[21] = FPU_MOV_S(ctx->f[12]);
    // 0x1926b8: 0xc064b44  jal         func_192D10
    ctx->pc = 0x1926B8u;
    SET_GPR_U32(ctx, 31, 0x1926C0u);
    ctx->pc = 0x1926BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1926B8u;
            // 0x1926bc: 0x46006d06  mov.s       $f20, $f13 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x192D10u;
    if (runtime->hasFunction(0x192D10u)) {
        auto targetFn = runtime->lookupFunction(0x192D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1926C0u; }
        if (ctx->pc != 0x1926C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192D10_0x192d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1926C0u; }
        if (ctx->pc != 0x1926C0u) { return; }
    }
    ctx->pc = 0x1926C0u;
label_1926c0:
    // 0x1926c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1926c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1926c4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1926c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1926c8: 0xc064b44  jal         func_192D10
    ctx->pc = 0x1926C8u;
    SET_GPR_U32(ctx, 31, 0x1926D0u);
    ctx->pc = 0x1926CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1926C8u;
            // 0x1926cc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192D10u;
    if (runtime->hasFunction(0x192D10u)) {
        auto targetFn = runtime->lookupFunction(0x192D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1926D0u; }
        if (ctx->pc != 0x1926D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192D10_0x192d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1926D0u; }
        if (ctx->pc != 0x1926D0u) { return; }
    }
    ctx->pc = 0x1926D0u;
label_1926d0:
    // 0x1926d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1926d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1926d4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1926d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1926d8: 0x4600ab06  mov.s       $f12, $f21
    ctx->pc = 0x1926d8u;
    ctx->f[12] = FPU_MOV_S(ctx->f[21]);
    // 0x1926dc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1926dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1926e0: 0xc0649c4  jal         func_192710
    ctx->pc = 0x1926E0u;
    SET_GPR_U32(ctx, 31, 0x1926E8u);
    ctx->pc = 0x1926E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1926E0u;
            // 0x1926e4: 0x4600a346  mov.s       $f13, $f20 (Delay Slot)
        ctx->f[13] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x192710u;
    if (runtime->hasFunction(0x192710u)) {
        auto targetFn = runtime->lookupFunction(0x192710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1926E8u; }
        if (ctx->pc != 0x1926E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192710_0x192710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1926E8u; }
        if (ctx->pc != 0x1926E8u) { return; }
    }
    ctx->pc = 0x1926E8u;
label_1926e8:
    // 0x1926e8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1926e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1926ec: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x1926ecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x1926f0: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1926f0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1926f4: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1926f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1926f8: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1926f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1926fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1926fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192700: 0x3e00008  jr          $ra
    ctx->pc = 0x192700u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192700u;
            // 0x192704: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1926C0u: goto label_1926c0;
            case 0x1926D0u: goto label_1926d0;
            case 0x1926E8u: goto label_1926e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192708u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
