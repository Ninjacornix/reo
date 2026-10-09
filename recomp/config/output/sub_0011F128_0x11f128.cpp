#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F128
// Address: 0x11f128 - 0x11f228
void sub_0011F128_0x11f128(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F128_0x11f128");
#endif

    switch (ctx->pc) {
        case 0x11f184u: goto label_11f184;
        case 0x11f1acu: goto label_11f1ac;
        case 0x11f1c4u: goto label_11f1c4;
        case 0x11f218u: goto label_11f218;
        default: break;
    }

    ctx->pc = 0x11f128u;

    // 0x11f128: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11f128u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11f12c: 0x3c0208ca  lui         $v0, 0x8CA
    ctx->pc = 0x11f12cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2250 << 16));
    // 0x11f130: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f130u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f134: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11f134u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f138: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11f138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11f13c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x11f13cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f140: 0x72020019  multu1      $zero, $s0, $v0
    ctx->pc = 0x11f140u;
    { uint64_t result = (uint64_t)GPR_U32(ctx, 16) * (uint64_t)GPR_U32(ctx, 2); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x11f144: 0x820019  multu       $a0, $v0
    ctx->pc = 0x11f144u;
    { uint64_t result = (uint64_t)GPR_U32(ctx, 4) * (uint64_t)GPR_U32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x11f148: 0x3c05000f  lui         $a1, 0xF
    ctx->pc = 0x11f148u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)15 << 16));
    // 0x11f14c: 0x34a54240  ori         $a1, $a1, 0x4240
    ctx->pc = 0x11f14cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)16960);
    // 0x11f150: 0x70008010  mfhi1       $s0
    ctx->pc = 0x11f150u;
    SET_GPR_U64(ctx, 16, ctx->hi1);
    // 0x11f154: 0x3012  mflo        $a2
    ctx->pc = 0x11f154u;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x11f158: 0x10803c  dsll32      $s0, $s0, 0
    ctx->pc = 0x11f158u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x11f15c: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x11f15cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x11f160: 0x2010  mfhi        $a0
    ctx->pc = 0x11f160u;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x11f164: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x11f164u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x11f168: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x11f168u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x11f16c: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x11f16cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x11f170: 0x70003012  mflo1       $a2
    ctx->pc = 0x11f170u;
    SET_GPR_U64(ctx, 6, ctx->lo1);
    // 0x11f174: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x11f174u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x11f178: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x11f178u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x11f17c: 0xc044210  jal         func_110840
    ctx->pc = 0x11F17Cu;
    SET_GPR_U32(ctx, 31, 0x11F184u);
    ctx->pc = 0x11F180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F17Cu;
            // 0x11f180: 0x2068025  or          $s0, $s0, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110840u;
    if (runtime->hasFunction(0x110840u)) {
        auto targetFn = runtime->lookupFunction(0x110840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F184u; }
        if (ctx->pc != 0x11F184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110840_0x110840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F184u; }
        if (ctx->pc != 0x11F184u) { return; }
    }
    ctx->pc = 0x11F184u;
label_11f184:
    // 0x11f184: 0x202102d  daddu       $v0, $s0, $v0
    ctx->pc = 0x11f184u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
    // 0x11f188: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11f188u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f18c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f18cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f190: 0x3e00008  jr          $ra
    ctx->pc = 0x11F190u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F190u;
            // 0x11f194: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F184u: goto label_11f184;
            case 0x11F1ACu: goto label_11f1ac;
            case 0x11F1B4u: goto label_11f1b4;
            case 0x11F1C4u: goto label_11f1c4;
            case 0x11F1C8u: goto label_11f1c8;
            case 0x11F218u: goto label_11f218;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F198u;
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
            case 0x11F184u: goto label_11f184;
            case 0x11F1ACu: goto label_11f1ac;
            case 0x11F1B4u: goto label_11f1b4;
            case 0x11F1C4u: goto label_11f1c4;
            case 0x11F1C8u: goto label_11f1c8;
            case 0x11F218u: goto label_11f218;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F1ECu;
    // 0x11f1ec: 0x0  nop
    ctx->pc = 0x11f1ecu;
    // NOP
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
            case 0x11F184u: goto label_11f184;
            case 0x11F1ACu: goto label_11f1ac;
            case 0x11F1B4u: goto label_11f1b4;
            case 0x11F1C4u: goto label_11f1c4;
            case 0x11F1C8u: goto label_11f1c8;
            case 0x11F218u: goto label_11f218;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F224u;
    // 0x11f224: 0x0  nop
    ctx->pc = 0x11f224u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
