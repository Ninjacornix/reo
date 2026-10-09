#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193F90
// Address: 0x193f90 - 0x194208
void sub_00193F90_0x193f90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193F90_0x193f90");
#endif

    switch (ctx->pc) {
        case 0x193fccu: goto label_193fcc;
        case 0x193fd8u: goto label_193fd8;
        case 0x194028u: goto label_194028;
        case 0x194038u: goto label_194038;
        case 0x194068u: goto label_194068;
        case 0x19410cu: goto label_19410c;
        case 0x19411cu: goto label_19411c;
        case 0x19414cu: goto label_19414c;
        case 0x1941f0u: goto label_1941f0;
        default: break;
    }

    ctx->pc = 0x193f90u;

    // 0x193f90: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x193f90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x193f94: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x193f94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x193f98: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x193f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x193f9c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x193f9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x193fa0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x193fa0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x193fa4: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x193fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x193fa8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x193FA8u;
    {
        const bool branch_taken_0x193fa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x193FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193FA8u;
            // 0x193fac: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193fa8) {
            ctx->pc = 0x193FB8u;
            goto label_193fb8;
        }
    }
    ctx->pc = 0x193FB0u;
    // 0x193fb0: 0x10000090  b           . + 4 + (0x90 << 2)
    ctx->pc = 0x193FB0u;
    {
        const bool branch_taken_0x193fb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193FB0u;
            // 0x193fb4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193fb0) {
            ctx->pc = 0x1941F4u;
            goto label_1941f4;
        }
    }
    ctx->pc = 0x193FB8u;
label_193fb8:
    // 0x193fb8: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x193fb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x193fbc: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x193fbcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x193fc0: 0x2484fe50  addiu       $a0, $a0, -0x1B0
    ctx->pc = 0x193fc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966864));
    // 0x193fc4: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x193FC4u;
    SET_GPR_U32(ctx, 31, 0x193FCCu);
    ctx->pc = 0x193FC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193FC4u;
            // 0x193fc8: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193FCCu; }
        if (ctx->pc != 0x193FCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193FCCu; }
        if (ctx->pc != 0x193FCCu) { return; }
    }
    ctx->pc = 0x193FCCu;
label_193fcc:
    // 0x193fcc: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x193fccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x193fd0: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x193FD0u;
    SET_GPR_U32(ctx, 31, 0x193FD8u);
    ctx->pc = 0x193FD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193FD0u;
            // 0x193fd4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193FD8u; }
        if (ctx->pc != 0x193FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193FD8u; }
        if (ctx->pc != 0x193FD8u) { return; }
    }
    ctx->pc = 0x193FD8u;
label_193fd8:
    // 0x193fd8: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x193fd8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x193fdc: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x193fdcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x193fe0: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x193fe0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x193fe4: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x193fe4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x193fe8: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x193fe8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x193fec: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x193fecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x193ff0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x193ff0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x193ff4: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x193ff4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x193ff8: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x193ff8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x193ffc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x193ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x194000: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x194000u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194004: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194004u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194008: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194008u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19400c: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x19400cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x194010: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194014: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x194014u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194018: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19401c: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x19401cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x194020: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194020u;
    SET_GPR_U32(ctx, 31, 0x194028u);
    ctx->pc = 0x194024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194020u;
            // 0x194024: 0x86040000  lh          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194028u; }
        if (ctx->pc != 0x194028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194028u; }
        if (ctx->pc != 0x194028u) { return; }
    }
    ctx->pc = 0x194028u;
label_194028:
    // 0x194028: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x194028u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x19402c: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x19402cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194030: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194030u;
    SET_GPR_U32(ctx, 31, 0x194038u);
    ctx->pc = 0x194034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194030u;
            // 0x194034: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194038u; }
        if (ctx->pc != 0x194038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194038u; }
        if (ctx->pc != 0x194038u) { return; }
    }
    ctx->pc = 0x194038u;
label_194038:
    // 0x194038: 0x21c3c  dsll32      $v1, $v0, 16
    ctx->pc = 0x194038u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x19403c: 0x11143c  dsll32      $v0, $s1, 16
    ctx->pc = 0x19403cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
    // 0x194040: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x194040u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x194044: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x194044u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x194048: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194048u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19404c: 0x0  nop
    ctx->pc = 0x19404cu;
    // NOP
    // 0x194050: 0x46800320  cvt.s.w     $f12, $f0
    ctx->pc = 0x194050u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[12] = FPU_CVT_S_W(tmp); }
    // 0x194054: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x194054u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x194058: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x194058u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19405c: 0x44827000  mtc1        $v0, $f14
    ctx->pc = 0x19405cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[14], &bits, sizeof(bits)); }
    // 0x194060: 0xc064fb4  jal         func_193ED0
    ctx->pc = 0x194060u;
    SET_GPR_U32(ctx, 31, 0x194068u);
    ctx->pc = 0x194064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194060u;
            // 0x194064: 0x46800360  cvt.s.w     $f13, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x193ED0u;
    if (runtime->hasFunction(0x193ED0u)) {
        auto targetFn = runtime->lookupFunction(0x193ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194068u; }
        if (ctx->pc != 0x194068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193ED0_0x193ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194068u; }
        if (ctx->pc != 0x194068u) { return; }
    }
    ctx->pc = 0x194068u;
label_194068:
    // 0x194068: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194068u;
    {
        const bool branch_taken_0x194068 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19406Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194068u;
            // 0x19406c: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194068) {
            ctx->pc = 0x194078u;
            goto label_194078;
        }
    }
    ctx->pc = 0x194070u;
    // 0x194070: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x194070u;
    {
        const bool branch_taken_0x194070 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194070u;
            // 0x194074: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194070) {
            ctx->pc = 0x1941F4u;
            goto label_1941f4;
        }
    }
    ctx->pc = 0x194078u;
label_194078:
    // 0x194078: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194078u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x19407c: 0x8c24fd54  lw          $a0, -0x2AC($at)
    ctx->pc = 0x19407cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x194080: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x194080u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x194084: 0x112c3c  dsll32      $a1, $s1, 16
    ctx->pc = 0x194084u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 17) << (32 + 16));
    // 0x194088: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x194088u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x19408c: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x19408cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194090: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194090u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194094: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194094u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194098: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x194098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x19409c: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x19409cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1940a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1940a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1940a4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1940a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1940a8: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1940a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1940ac: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1940acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1940b0: 0x41900  sll         $v1, $a0, 4
    ctx->pc = 0x1940b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1940b4: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1940b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1940b8: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1940b8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1940bc: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1940BCu;
    {
        const bool branch_taken_0x1940bc = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1940C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1940BCu;
            // 0x1940c0: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1940bc) {
            ctx->pc = 0x1940D4u;
            goto label_1940d4;
        }
    }
    ctx->pc = 0x1940C4u;
    // 0x1940c4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1940c4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1940c8: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1940c8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1940cc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1940CCu;
    {
        const bool branch_taken_0x1940cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1940D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1940CCu;
            // 0x1940d0: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1940cc) {
            ctx->pc = 0x1940F0u;
            goto label_1940f0;
        }
    }
    ctx->pc = 0x1940D4u;
label_1940d4:
    // 0x1940d4: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1940d4u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1940d8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1940d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1940dc: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1940dcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1940e0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1940e0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1940e4: 0x0  nop
    ctx->pc = 0x1940e4u;
    // NOP
    // 0x1940e8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1940e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1940ec: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1940ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1940f0:
    // 0x1940f0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1940f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1940f4: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1940f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1940f8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1940f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1940fc: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1940fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x194100: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x194100u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x194104: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194104u;
    SET_GPR_U32(ctx, 31, 0x19410Cu);
    ctx->pc = 0x194108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194104u;
            // 0x194108: 0x86040004  lh          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19410Cu; }
        if (ctx->pc != 0x19410Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19410Cu; }
        if (ctx->pc != 0x19410Cu) { return; }
    }
    ctx->pc = 0x19410Cu;
label_19410c:
    // 0x19410c: 0x86040006  lh          $a0, 0x6($s0)
    ctx->pc = 0x19410cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x194110: 0x2843c  dsll32      $s0, $v0, 16
    ctx->pc = 0x194110u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194114: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194114u;
    SET_GPR_U32(ctx, 31, 0x19411Cu);
    ctx->pc = 0x194118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194114u;
            // 0x194118: 0x10843f  dsra32      $s0, $s0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19411Cu; }
        if (ctx->pc != 0x19411Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19411Cu; }
        if (ctx->pc != 0x19411Cu) { return; }
    }
    ctx->pc = 0x19411Cu;
label_19411c:
    // 0x19411c: 0x21c3c  dsll32      $v1, $v0, 16
    ctx->pc = 0x19411cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194120: 0x10143c  dsll32      $v0, $s0, 16
    ctx->pc = 0x194120u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 16));
    // 0x194124: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x194124u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x194128: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x194128u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x19412c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x19412cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194130: 0x0  nop
    ctx->pc = 0x194130u;
    // NOP
    // 0x194134: 0x46800320  cvt.s.w     $f12, $f0
    ctx->pc = 0x194134u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[12] = FPU_CVT_S_W(tmp); }
    // 0x194138: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x194138u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19413c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19413cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194140: 0x44827000  mtc1        $v0, $f14
    ctx->pc = 0x194140u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[14], &bits, sizeof(bits)); }
    // 0x194144: 0xc064fb4  jal         func_193ED0
    ctx->pc = 0x194144u;
    SET_GPR_U32(ctx, 31, 0x19414Cu);
    ctx->pc = 0x194148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194144u;
            // 0x194148: 0x46800360  cvt.s.w     $f13, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x193ED0u;
    if (runtime->hasFunction(0x193ED0u)) {
        auto targetFn = runtime->lookupFunction(0x193ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19414Cu; }
        if (ctx->pc != 0x19414Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193ED0_0x193ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19414Cu; }
        if (ctx->pc != 0x19414Cu) { return; }
    }
    ctx->pc = 0x19414Cu;
label_19414c:
    // 0x19414c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19414Cu;
    {
        const bool branch_taken_0x19414c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x194150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19414Cu;
            // 0x194150: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19414c) {
            ctx->pc = 0x19415Cu;
            goto label_19415c;
        }
    }
    ctx->pc = 0x194154u;
    // 0x194154: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x194154u;
    {
        const bool branch_taken_0x194154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194154u;
            // 0x194158: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194154) {
            ctx->pc = 0x1941F4u;
            goto label_1941f4;
        }
    }
    ctx->pc = 0x19415Cu;
label_19415c:
    // 0x19415c: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x19415cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194160: 0x8c24fd54  lw          $a0, -0x2AC($at)
    ctx->pc = 0x194160u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x194164: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x194164u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x194168: 0x102c3c  dsll32      $a1, $s0, 16
    ctx->pc = 0x194168u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 16));
    // 0x19416c: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x19416cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x194170: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x194170u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194174: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194174u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194178: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194178u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19417c: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x19417cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x194180: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194184: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194184u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194188: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x194188u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x19418c: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x19418cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194190: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194190u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194194: 0x41900  sll         $v1, $a0, 4
    ctx->pc = 0x194194u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x194198: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194198u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19419c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x19419cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1941a0: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1941A0u;
    {
        const bool branch_taken_0x1941a0 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1941A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1941A0u;
            // 0x1941a4: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1941a0) {
            ctx->pc = 0x1941B8u;
            goto label_1941b8;
        }
    }
    ctx->pc = 0x1941A8u;
    // 0x1941a8: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1941a8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1941ac: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1941acu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1941b0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1941B0u;
    {
        const bool branch_taken_0x1941b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1941B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1941B0u;
            // 0x1941b4: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1941b0) {
            ctx->pc = 0x1941D4u;
            goto label_1941d4;
        }
    }
    ctx->pc = 0x1941B8u;
label_1941b8:
    // 0x1941b8: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1941b8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1941bc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1941bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1941c0: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1941c0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1941c4: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1941c4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1941c8: 0x0  nop
    ctx->pc = 0x1941c8u;
    // NOP
    // 0x1941cc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1941ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1941d0: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1941d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1941d4:
    // 0x1941d4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1941d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1941d8: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1941d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1941dc: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1941dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1941e0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1941e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1941e4: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1941e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1941e8: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1941E8u;
    SET_GPR_U32(ctx, 31, 0x1941F0u);
    ctx->pc = 0x1941ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1941E8u;
            // 0x1941ec: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1941F0u; }
        if (ctx->pc != 0x1941F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1941F0u; }
        if (ctx->pc != 0x1941F0u) { return; }
    }
    ctx->pc = 0x1941F0u;
label_1941f0:
    // 0x1941f0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1941f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1941f4:
    // 0x1941f4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1941f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1941f8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1941f8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1941fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1941fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194200: 0x3e00008  jr          $ra
    ctx->pc = 0x194200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194200u;
            // 0x194204: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193FB8u: goto label_193fb8;
            case 0x193FCCu: goto label_193fcc;
            case 0x193FD8u: goto label_193fd8;
            case 0x194028u: goto label_194028;
            case 0x194038u: goto label_194038;
            case 0x194068u: goto label_194068;
            case 0x194078u: goto label_194078;
            case 0x1940D4u: goto label_1940d4;
            case 0x1940F0u: goto label_1940f0;
            case 0x19410Cu: goto label_19410c;
            case 0x19411Cu: goto label_19411c;
            case 0x19414Cu: goto label_19414c;
            case 0x19415Cu: goto label_19415c;
            case 0x1941B8u: goto label_1941b8;
            case 0x1941D4u: goto label_1941d4;
            case 0x1941F0u: goto label_1941f0;
            case 0x1941F4u: goto label_1941f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194208u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
