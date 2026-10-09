#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001921B0
// Address: 0x1921b0 - 0x1921f0
void sub_001921B0_0x1921b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001921B0_0x1921b0");
#endif

    switch (ctx->pc) {
        case 0x1921c8u: goto label_1921c8;
        default: break;
    }

    ctx->pc = 0x1921b0u;

    // 0x1921b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1921b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1921b4: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x1921b4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1921b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1921b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1921bc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1921bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1921c0: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x1921C0u;
    SET_GPR_U32(ctx, 31, 0x1921C8u);
    ctx->pc = 0x1921C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1921C0u;
            // 0x1921c4: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1921C8u; }
        if (ctx->pc != 0x1921C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1921C8u; }
        if (ctx->pc != 0x1921C8u) { return; }
    }
    ctx->pc = 0x1921C8u;
label_1921c8:
    // 0x1921c8: 0xc7a00010  lwc1        $f0, 0x10($sp)
    ctx->pc = 0x1921c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1921cc: 0xe5200000  swc1        $f0, 0x0($t1)
    ctx->pc = 0x1921ccu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 0), bits); }
    // 0x1921d0: 0xc7a00014  lwc1        $f0, 0x14($sp)
    ctx->pc = 0x1921d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1921d4: 0xe4c00000  swc1        $f0, 0x0($a2)
    ctx->pc = 0x1921d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 0), bits); }
    // 0x1921d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1921d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1921dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1921DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1921E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1921DCu;
            // 0x1921e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1921C8u: goto label_1921c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1921E4u;
    // 0x1921e4: 0x0  nop
    ctx->pc = 0x1921e4u;
    // NOP
    // 0x1921e8: 0x0  nop
    ctx->pc = 0x1921e8u;
    // NOP
    // 0x1921ec: 0x0  nop
    ctx->pc = 0x1921ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
