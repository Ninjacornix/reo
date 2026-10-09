#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E170
// Address: 0x15e170 - 0x15e270
void sub_0015E170_0x15e170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E170_0x15e170");
#endif

    switch (ctx->pc) {
        case 0x15e188u: goto label_15e188;
        case 0x15e194u: goto label_15e194;
        case 0x15e1e4u: goto label_15e1e4;
        case 0x15e200u: goto label_15e200;
        default: break;
    }

    ctx->pc = 0x15e170u;

    // 0x15e170: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15e170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15e174: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15e174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15e178: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x15e178u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e17c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15e17cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15e180: 0xc05af8e  jal         func_16BE38
    ctx->pc = 0x15E180u;
    SET_GPR_U32(ctx, 31, 0x15E188u);
    ctx->pc = 0x15E184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E180u;
            // 0x15e184: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BE38u;
    if (runtime->hasFunction(0x16BE38u)) {
        auto targetFn = runtime->lookupFunction(0x16BE38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E188u; }
        if (ctx->pc != 0x15E188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BE38_0x16be38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E188u; }
        if (ctx->pc != 0x15E188u) { return; }
    }
    ctx->pc = 0x15E188u;
label_15e188:
    // 0x15e188: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15e188u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e18c: 0xc0578c6  jal         func_15E318
    ctx->pc = 0x15E18Cu;
    SET_GPR_U32(ctx, 31, 0x15E194u);
    ctx->pc = 0x15E190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E18Cu;
            // 0x15e190: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E318u;
    if (runtime->hasFunction(0x15E318u)) {
        auto targetFn = runtime->lookupFunction(0x15E318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E194u; }
        if (ctx->pc != 0x15E194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E318_0x15e318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E194u; }
        if (ctx->pc != 0x15E194u) { return; }
    }
    ctx->pc = 0x15E194u;
label_15e194:
    // 0x15e194: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15e194u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e198: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15e198u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15e19c: 0x3e00008  jr          $ra
    ctx->pc = 0x15E19Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E1A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E19Cu;
            // 0x15e1a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E188u: goto label_15e188;
            case 0x15E194u: goto label_15e194;
            case 0x15E1E4u: goto label_15e1e4;
            case 0x15E200u: goto label_15e200;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E1A4u;
    // 0x15e1a4: 0x0  nop
    ctx->pc = 0x15e1a4u;
    // NOP
    // 0x15e1a8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15e1a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15e1ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15e1acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15e1b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15e1b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e1b4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15e1b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15e1b8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15e1b8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e1bc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15e1bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15e1c0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15e1c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15e1c4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x15e1c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x15e1c8: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x15e1c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x15e1cc: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x15e1ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x15e1d0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x15e1d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x15e1d4: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x15e1d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x15e1d8: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x15e1d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x15e1dc: 0xc05789c  jal         func_15E270
    ctx->pc = 0x15E1DCu;
    SET_GPR_U32(ctx, 31, 0x15E1E4u);
    ctx->pc = 0x15E1E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E1DCu;
            // 0x15e1e0: 0x8e170000  lw          $s7, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E270u;
    if (runtime->hasFunction(0x15E270u)) {
        auto targetFn = runtime->lookupFunction(0x15E270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E1E4u; }
        if (ctx->pc != 0x15E1E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E270_0x15e270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E1E4u; }
        if (ctx->pc != 0x15E1E4u) { return; }
    }
    ctx->pc = 0x15E1E4u;
label_15e1e4:
    // 0x15e1e4: 0x8e160008  lw          $s6, 0x8($s0)
    ctx->pc = 0x15e1e4u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x15e1e8: 0x8e040018  lw          $a0, 0x18($s0)
    ctx->pc = 0x15e1e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x15e1ec: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x15e1ecu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e1f0: 0x8e12000c  lw          $s2, 0xC($s0)
    ctx->pc = 0x15e1f0u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x15e1f4: 0x8e130010  lw          $s3, 0x10($s0)
    ctx->pc = 0x15e1f4u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x15e1f8: 0xc0578ac  jal         func_15E2B0
    ctx->pc = 0x15E1F8u;
    SET_GPR_U32(ctx, 31, 0x15E200u);
    ctx->pc = 0x15E1FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E1F8u;
            // 0x15e1fc: 0x8e140014  lw          $s4, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E2B0u;
    if (runtime->hasFunction(0x15E2B0u)) {
        auto targetFn = runtime->lookupFunction(0x15E2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E200u; }
        if (ctx->pc != 0x15E200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E2B0_0x15e2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E200u; }
        if (ctx->pc != 0x15E200u) { return; }
    }
    ctx->pc = 0x15E200u;
label_15e200:
    // 0x15e200: 0x8e03002c  lw          $v1, 0x2C($s0)
    ctx->pc = 0x15e200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x15e204: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x15e204u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x15e208: 0x8e050028  lw          $a1, 0x28($s0)
    ctx->pc = 0x15e208u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x15e20c: 0x8e060038  lw          $a2, 0x38($s0)
    ctx->pc = 0x15e20cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x15e210: 0x8e07003c  lw          $a3, 0x3C($s0)
    ctx->pc = 0x15e210u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x15e214: 0xae370020  sw          $s7, 0x20($s1)
    ctx->pc = 0x15e214u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 23));
    // 0x15e218: 0xae35001c  sw          $s5, 0x1C($s1)
    ctx->pc = 0x15e218u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 21));
    // 0x15e21c: 0xae360000  sw          $s6, 0x0($s1)
    ctx->pc = 0x15e21cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 22));
    // 0x15e220: 0xae320004  sw          $s2, 0x4($s1)
    ctx->pc = 0x15e220u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 18));
    // 0x15e224: 0xae330008  sw          $s3, 0x8($s1)
    ctx->pc = 0x15e224u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 19));
    // 0x15e228: 0xae34000c  sw          $s4, 0xC($s1)
    ctx->pc = 0x15e228u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 20));
    // 0x15e22c: 0xae23002c  sw          $v1, 0x2C($s1)
    ctx->pc = 0x15e22cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 3));
    // 0x15e230: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x15e230u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x15e234: 0xae240014  sw          $a0, 0x14($s1)
    ctx->pc = 0x15e234u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 4));
    // 0x15e238: 0xae250018  sw          $a1, 0x18($s1)
    ctx->pc = 0x15e238u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 5));
    // 0x15e23c: 0xae260024  sw          $a2, 0x24($s1)
    ctx->pc = 0x15e23cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 6));
    // 0x15e240: 0xae270028  sw          $a3, 0x28($s1)
    ctx->pc = 0x15e240u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 7));
    // 0x15e244: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e244u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e248: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15e248u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e24c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15e24cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e250: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15e250u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15e254: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x15e254u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15e258: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x15e258u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15e25c: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x15e25cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15e260: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x15e260u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15e264: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x15e264u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15e268: 0x3e00008  jr          $ra
    ctx->pc = 0x15E268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E268u;
            // 0x15e26c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E188u: goto label_15e188;
            case 0x15E194u: goto label_15e194;
            case 0x15E1E4u: goto label_15e1e4;
            case 0x15E200u: goto label_15e200;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E270u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
