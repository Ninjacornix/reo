#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F1F0
// Address: 0x11f1f0 - 0x11f224
void sub_0011F1F0_0x11f1f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F1F0_0x11f1f0");
#endif

    switch (ctx->pc) {
        case 0x11f218u: goto label_11f218;
        default: break;
    }

    ctx->pc = 0x11f1f0u;

    // 0x11f1f0: 0x3c014d0c  lui         $at, 0x4D0C
    ctx->pc = 0x11f1f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)19724 << 16));
    // 0x11f1f4: 0x3421a000  ori         $at, $at, 0xA000
    ctx->pc = 0x11f1f4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)40960);
    // 0x11f1f8: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x11f1f8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x11f1fc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11f1fcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11f200: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11f200u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11f204: 0x0  nop
    ctx->pc = 0x11f204u;
    // NOP
    // 0x11f208: 0x0  nop
    ctx->pc = 0x11f208u;
    // NOP
    // 0x11f20c: 0x460c0303  div.s       $f12, $f0, $f12
    ctx->pc = 0x11f20cu;
    if (ctx->f[12] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[12])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[0] / ctx->f[12];
    // 0x11f210: 0xc044592  jal         func_111648
    ctx->pc = 0x11F210u;
    SET_GPR_U32(ctx, 31, 0x11F218u);
    ctx->pc = 0x111648u;
    if (runtime->hasFunction(0x111648u)) {
        auto targetFn = runtime->lookupFunction(0x111648u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F218u; }
        if (ctx->pc != 0x11F218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111648_0x111648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F218u; }
        if (ctx->pc != 0x11F218u) { return; }
    }
    ctx->pc = 0x11F218u;
label_11f218:
    // 0x11f218: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11f218u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f21c: 0x3e00008  jr          $ra
    ctx->pc = 0x11F21Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F21Cu;
            // 0x11f220: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F218u: goto label_11f218;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F224u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
