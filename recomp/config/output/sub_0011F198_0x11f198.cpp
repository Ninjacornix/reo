#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F198
// Address: 0x11f198 - 0x11f1ec
void sub_0011F198_0x11f198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F198_0x11f198");
#endif

    switch (ctx->pc) {
        case 0x11f1acu: goto label_11f1ac;
        case 0x11f1c4u: goto label_11f1c4;
        default: break;
    }

    ctx->pc = 0x11f198u;

    // 0x11f198: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11f198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11f19c: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11F19Cu;
    {
        const bool branch_taken_0x11f19c = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11F1A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F19Cu;
            // 0x11f1a0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f19c) {
            ctx->pc = 0x11F1B4u;
            goto label_11f1b4;
        }
    }
    ctx->pc = 0x11F1A4u;
    // 0x11f1a4: 0xc0444f4  jal         func_1113D0
    ctx->pc = 0x11F1A4u;
    SET_GPR_U32(ctx, 31, 0x11F1ACu);
    ctx->pc = 0x1113D0u;
    if (runtime->hasFunction(0x1113D0u)) {
        auto targetFn = runtime->lookupFunction(0x1113D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F1ACu; }
        if (ctx->pc != 0x11F1ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001113D0_0x1113d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F1ACu; }
        if (ctx->pc != 0x11F1ACu) { return; }
    }
    ctx->pc = 0x11F1ACu;
label_11f1ac:
    // 0x11f1ac: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11F1ACu;
    {
        const bool branch_taken_0x11f1ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F1ACu;
            // 0x11f1b0: 0x46000046  mov.s       $f1, $f0 (Delay Slot)
        ctx->f[1] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f1ac) {
            ctx->pc = 0x11F1C8u;
            goto label_11f1c8;
        }
    }
    ctx->pc = 0x11F1B4u;
label_11f1b4:
    // 0x11f1b4: 0x4107a  dsrl        $v0, $a0, 1
    ctx->pc = 0x11f1b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) >> 1);
    // 0x11f1b8: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x11f1b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x11f1bc: 0xc0444f4  jal         func_1113D0
    ctx->pc = 0x11F1BCu;
    SET_GPR_U32(ctx, 31, 0x11F1C4u);
    ctx->pc = 0x11F1C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F1BCu;
            // 0x11f1c0: 0x822025  or          $a0, $a0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1113D0u;
    if (runtime->hasFunction(0x1113D0u)) {
        auto targetFn = runtime->lookupFunction(0x1113D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F1C4u; }
        if (ctx->pc != 0x11F1C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001113D0_0x1113d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F1C4u; }
        if (ctx->pc != 0x11F1C4u) { return; }
    }
    ctx->pc = 0x11F1C4u;
label_11f1c4:
    // 0x11f1c4: 0x46000040  add.s       $f1, $f0, $f0
    ctx->pc = 0x11f1c4u;
    ctx->f[1] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_11f1c8:
    // 0x11f1c8: 0x3c014d0c  lui         $at, 0x4D0C
    ctx->pc = 0x11f1c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)19724 << 16));
    // 0x11f1cc: 0x3421a000  ori         $at, $at, 0xA000
    ctx->pc = 0x11f1ccu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)40960);
    // 0x11f1d0: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x11f1d0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x11f1d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11f1d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f1d8: 0x0  nop
    ctx->pc = 0x11f1d8u;
    // NOP
    // 0x11f1dc: 0x0  nop
    ctx->pc = 0x11f1dcu;
    // NOP
    // 0x11f1e0: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x11f1e0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x11f1e4: 0x3e00008  jr          $ra
    ctx->pc = 0x11F1E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F1E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F1E4u;
            // 0x11f1e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F1ACu: goto label_11f1ac;
            case 0x11F1B4u: goto label_11f1b4;
            case 0x11F1C4u: goto label_11f1c4;
            case 0x11F1C8u: goto label_11f1c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F1ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
