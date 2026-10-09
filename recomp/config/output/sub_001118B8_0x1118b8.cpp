#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001118B8
// Address: 0x1118b8 - 0x1118f8
void sub_001118B8_0x1118b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001118B8_0x1118b8");
#endif

    switch (ctx->pc) {
        case 0x1118d0u: goto label_1118d0;
        case 0x1118e8u: goto label_1118e8;
        default: break;
    }

    ctx->pc = 0x1118b8u;

    // 0x1118b8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1118b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1118bc: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1118bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1118c0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1118c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1118c4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1118c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1118c8: 0xc04460a  jal         func_111828
    ctx->pc = 0x1118C8u;
    SET_GPR_U32(ctx, 31, 0x1118D0u);
    ctx->pc = 0x1118CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1118C8u;
            // 0x1118cc: 0xe7ac0010  swc1        $f12, 0x10($sp) (Delay Slot)
        { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x111828u;
    if (runtime->hasFunction(0x111828u)) {
        auto targetFn = runtime->lookupFunction(0x111828u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1118D0u; }
        if (ctx->pc != 0x1118D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111828_0x111828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1118D0u; }
        if (ctx->pc != 0x1118D0u) { return; }
    }
    ctx->pc = 0x1118D0u;
label_1118d0:
    // 0x1118d0: 0x9fa7000c  lwu         $a3, 0xC($sp)
    ctx->pc = 0x1118d0u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1118d4: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1118d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1118d8: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x1118d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1118dc: 0x73fb8  dsll        $a3, $a3, 30
    ctx->pc = 0x1118dcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << 30);
    // 0x1118e0: 0xc044910  jal         func_112440
    ctx->pc = 0x1118E0u;
    SET_GPR_U32(ctx, 31, 0x1118E8u);
    ctx->pc = 0x1118E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1118E0u;
            // 0x1118e4: 0x8fa60008  lw          $a2, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112440u;
    if (runtime->hasFunction(0x112440u)) {
        auto targetFn = runtime->lookupFunction(0x112440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1118E8u; }
        if (ctx->pc != 0x1118E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112440_0x112440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1118E8u; }
        if (ctx->pc != 0x1118E8u) { return; }
    }
    ctx->pc = 0x1118E8u;
label_1118e8:
    // 0x1118e8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1118e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1118ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1118ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1118F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1118ECu;
            // 0x1118f0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1118D0u: goto label_1118d0;
            case 0x1118E8u: goto label_1118e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1118F4u;
    // 0x1118f4: 0x0  nop
    ctx->pc = 0x1118f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
