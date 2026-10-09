#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00195600
// Address: 0x195600 - 0x195924
void sub_00195600_0x195600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00195600_0x195600");
#endif

    switch (ctx->pc) {
        case 0x19564cu: goto label_19564c;
        case 0x195660u: goto label_195660;
        case 0x195674u: goto label_195674;
        case 0x195680u: goto label_195680;
        case 0x195694u: goto label_195694;
        case 0x195730u: goto label_195730;
        case 0x195740u: goto label_195740;
        case 0x195750u: goto label_195750;
        case 0x1957f8u: goto label_1957f8;
        case 0x195844u: goto label_195844;
        case 0x195850u: goto label_195850;
        case 0x19585cu: goto label_19585c;
        case 0x1958fcu: goto label_1958fc;
        default: break;
    }

    ctx->pc = 0x195600u;

    // 0x195600: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x195600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x195604: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195604u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195608: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x195608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x19560c: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x19560cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x195610: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x195610u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x195614: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x195614u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x195618: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x195618u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x19561c: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x19561cu;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x195620: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x195620u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x195624: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x195624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x195628: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x195628u;
    {
        const bool branch_taken_0x195628 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19562Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195628u;
            // 0x19562c: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195628) {
            ctx->pc = 0x195638u;
            goto label_195638;
        }
    }
    ctx->pc = 0x195630u;
    // 0x195630: 0x100000b3  b           . + 4 + (0xB3 << 2)
    ctx->pc = 0x195630u;
    {
        const bool branch_taken_0x195630 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195630u;
            // 0x195634: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195630) {
            ctx->pc = 0x195900u;
            goto label_195900;
        }
    }
    ctx->pc = 0x195638u;
label_195638:
    // 0x195638: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x195638u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x19563c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x19563cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x195640: 0x248400b0  addiu       $a0, $a0, 0xB0
    ctx->pc = 0x195640u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 176));
    // 0x195644: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x195644u;
    SET_GPR_U32(ctx, 31, 0x19564Cu);
    ctx->pc = 0x195648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195644u;
            // 0x195648: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19564Cu; }
        if (ctx->pc != 0x19564Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19564Cu; }
        if (ctx->pc != 0x19564Cu) { return; }
    }
    ctx->pc = 0x19564Cu;
label_19564c:
    // 0x19564c: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19564cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x195650: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x195650u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x195654: 0x34453700  ori         $a1, $v0, 0x3700
    ctx->pc = 0x195654u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x195658: 0xc0644a0  jal         func_191280
    ctx->pc = 0x195658u;
    SET_GPR_U32(ctx, 31, 0x195660u);
    ctx->pc = 0x19565Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195658u;
            // 0x19565c: 0x34463f40  ori         $a2, $v0, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195660u; }
        if (ctx->pc != 0x195660u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195660u; }
        if (ctx->pc != 0x195660u) { return; }
    }
    ctx->pc = 0x195660u;
label_195660:
    // 0x195660: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x195660u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x195664: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x195664u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x195668: 0x24c64d80  addiu       $a2, $a2, 0x4D80
    ctx->pc = 0x195668u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19840));
    // 0x19566c: 0xc0644a0  jal         func_191280
    ctx->pc = 0x19566Cu;
    SET_GPR_U32(ctx, 31, 0x195674u);
    ctx->pc = 0x195670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19566Cu;
            // 0x195670: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195674u; }
        if (ctx->pc != 0x195674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195674u; }
        if (ctx->pc != 0x195674u) { return; }
    }
    ctx->pc = 0x195674u;
label_195674:
    // 0x195674: 0x8e640018  lw          $a0, 0x18($s3)
    ctx->pc = 0x195674u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x195678: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x195678u;
    SET_GPR_U32(ctx, 31, 0x195680u);
    ctx->pc = 0x19567Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195678u;
            // 0x19567c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195680u; }
        if (ctx->pc != 0x195680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195680u; }
        if (ctx->pc != 0x195680u) { return; }
    }
    ctx->pc = 0x195680u;
label_195680:
    // 0x195680: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x195680u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x195684: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x195684u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x195688: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x195688u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19568c: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x19568Cu;
    SET_GPR_U32(ctx, 31, 0x195694u);
    ctx->pc = 0x195690u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19568Cu;
            // 0x195690: 0x27a60060  addiu       $a2, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195694u; }
        if (ctx->pc != 0x195694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195694u; }
        if (ctx->pc != 0x195694u) { return; }
    }
    ctx->pc = 0x195694u;
label_195694:
    // 0x195694: 0x27b200ac  addiu       $s2, $sp, 0xAC
    ctx->pc = 0x195694u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 172));
    // 0x195698: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x195698u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19569c: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x19569cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1956a0: 0x101c02  srl         $v1, $s0, 16
    ctx->pc = 0x1956a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 16), 16));
    // 0x1956a4: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1956a4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1956a8: 0x306400ff  andi        $a0, $v1, 0xFF
    ctx->pc = 0x1956a8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1956ac: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1956acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1956b0: 0x101202  srl         $v0, $s0, 8
    ctx->pc = 0x1956b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 8));
    // 0x1956b4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1956b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1956b8: 0x21a38  dsll        $v1, $v0, 8
    ctx->pc = 0x1956b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 8);
    // 0x1956bc: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1956bcu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1956c0: 0x320200ff  andi        $v0, $s0, 0xFF
    ctx->pc = 0x1956c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x1956c4: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1956c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1956c8: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1956c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1956cc: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x1956ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1956d0: 0x101602  srl         $v0, $s0, 24
    ctx->pc = 0x1956d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 24));
    // 0x1956d4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1956d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1956d8: 0x21638  dsll        $v0, $v0, 24
    ctx->pc = 0x1956d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x1956dc: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x1956dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1956e0: 0xe6400000  swc1        $f0, 0x0($s2)
    ctx->pc = 0x1956e0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
    // 0x1956e4: 0x9e420000  lwu         $v0, 0x0($s2)
    ctx->pc = 0x1956e4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1956e8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1956e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1956ec: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1956ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1956f0: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x1956f0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x1956f4: 0xc6410000  lwc1        $f1, 0x0($s2)
    ctx->pc = 0x1956f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1956f8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1956f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1956fc: 0xc660001c  lwc1        $f0, 0x1C($s3)
    ctx->pc = 0x1956fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195700: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195700u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195704: 0xe7a000bc  swc1        $f0, 0xBC($sp)
    ctx->pc = 0x195704u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 188), bits); }
    // 0x195708: 0xc6600020  lwc1        $f0, 0x20($s3)
    ctx->pc = 0x195708u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19570c: 0x9fa300bc  lwu         $v1, 0xBC($sp)
    ctx->pc = 0x19570cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 188)));
    // 0x195710: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195710u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195714: 0xe7a000b8  swc1        $f0, 0xB8($sp)
    ctx->pc = 0x195714u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 184), bits); }
    // 0x195718: 0x9fa200b8  lwu         $v0, 0xB8($sp)
    ctx->pc = 0x195718u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x19571c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19571cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195720: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x195720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x195724: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x195724u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x195728: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x195728u;
    SET_GPR_U32(ctx, 31, 0x195730u);
    ctx->pc = 0x19572Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195728u;
            // 0x19572c: 0xc7ac00a0  lwc1        $f12, 0xA0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195730u; }
        if (ctx->pc != 0x195730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195730u; }
        if (ctx->pc != 0x195730u) { return; }
    }
    ctx->pc = 0x195730u;
label_195730:
    // 0x195730: 0x27b100a4  addiu       $s1, $sp, 0xA4
    ctx->pc = 0x195730u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 164));
    // 0x195734: 0xc62c0000  lwc1        $f12, 0x0($s1)
    ctx->pc = 0x195734u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195738: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x195738u;
    SET_GPR_U32(ctx, 31, 0x195740u);
    ctx->pc = 0x19573Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195738u;
            // 0x19573c: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195740u; }
        if (ctx->pc != 0x195740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195740u; }
        if (ctx->pc != 0x195740u) { return; }
    }
    ctx->pc = 0x195740u;
label_195740:
    // 0x195740: 0x27b000a8  addiu       $s0, $sp, 0xA8
    ctx->pc = 0x195740u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
    // 0x195744: 0xc60c0000  lwc1        $f12, 0x0($s0)
    ctx->pc = 0x195744u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195748: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x195748u;
    SET_GPR_U32(ctx, 31, 0x195750u);
    ctx->pc = 0x19574Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195748u;
            // 0x19574c: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195750u; }
        if (ctx->pc != 0x195750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195750u; }
        if (ctx->pc != 0x195750u) { return; }
    }
    ctx->pc = 0x195750u;
label_195750:
    // 0x195750: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195750u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195754: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195754u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x195758: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x195758u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19575c: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x19575cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195760: 0x0  nop
    ctx->pc = 0x195760u;
    // NOP
    // 0x195764: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x195764u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x195768: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195768u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19576c: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x19576cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x195770: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x195770u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x195774: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x195774u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x195778: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x195778u;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x19577c: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x19577cu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x195780: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195780u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x195784: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x195784u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195788: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195788u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x19578c: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x19578cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195790: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x195790u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195794: 0x0  nop
    ctx->pc = 0x195794u;
    // NOP
    // 0x195798: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x195798u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19579c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x19579cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1957a0: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1957A0u;
    {
        const bool branch_taken_0x1957a0 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1957A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1957A0u;
            // 0x1957a4: 0x623025  or          $a2, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1957a0) {
            ctx->pc = 0x1957B8u;
            goto label_1957b8;
        }
    }
    ctx->pc = 0x1957A8u;
    // 0x1957a8: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1957a8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1957ac: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1957acu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1957b0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1957B0u;
    {
        const bool branch_taken_0x1957b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1957B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1957B0u;
            // 0x1957b4: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1957b0) {
            ctx->pc = 0x1957D4u;
            goto label_1957d4;
        }
    }
    ctx->pc = 0x1957B8u;
label_1957b8:
    // 0x1957b8: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x1957b8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x1957bc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1957bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1957c0: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1957c0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1957c4: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1957c4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1957c8: 0x0  nop
    ctx->pc = 0x1957c8u;
    // NOP
    // 0x1957cc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1957ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1957d0: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1957d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1957d4:
    // 0x1957d4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1957d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1957d8: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1957d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1957dc: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1957dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1957e0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1957e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1957e4: 0x2665000c  addiu       $a1, $s3, 0xC
    ctx->pc = 0x1957e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 12));
    // 0x1957e8: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x1957e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x1957ec: 0x27a60060  addiu       $a2, $sp, 0x60
    ctx->pc = 0x1957ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1957f0: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x1957F0u;
    SET_GPR_U32(ctx, 31, 0x1957F8u);
    ctx->pc = 0x1957F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1957F0u;
            // 0x1957f4: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1957F8u; }
        if (ctx->pc != 0x1957F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1957F8u; }
        if (ctx->pc != 0x1957F8u) { return; }
    }
    ctx->pc = 0x1957F8u;
label_1957f8:
    // 0x1957f8: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1957f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1957fc: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x1957fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x195800: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195800u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195804: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195804u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195808: 0x46000843  div.s       $f1, $f1, $f0
    ctx->pc = 0x195808u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[1] / ctx->f[0];
    // 0x19580c: 0xe6410000  swc1        $f1, 0x0($s2)
    ctx->pc = 0x19580cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
    // 0x195810: 0xc6600024  lwc1        $f0, 0x24($s3)
    ctx->pc = 0x195810u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195814: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195814u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195818: 0xe7a000bc  swc1        $f0, 0xBC($sp)
    ctx->pc = 0x195818u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 188), bits); }
    // 0x19581c: 0xc6600028  lwc1        $f0, 0x28($s3)
    ctx->pc = 0x19581cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195820: 0x9fa300bc  lwu         $v1, 0xBC($sp)
    ctx->pc = 0x195820u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 188)));
    // 0x195824: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195824u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195828: 0xe7a000b8  swc1        $f0, 0xB8($sp)
    ctx->pc = 0x195828u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 184), bits); }
    // 0x19582c: 0x9fa200b8  lwu         $v0, 0xB8($sp)
    ctx->pc = 0x19582cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x195830: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195830u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195834: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x195834u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x195838: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x195838u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x19583c: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x19583Cu;
    SET_GPR_U32(ctx, 31, 0x195844u);
    ctx->pc = 0x195840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19583Cu;
            // 0x195840: 0xc7ac00a0  lwc1        $f12, 0xA0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195844u; }
        if (ctx->pc != 0x195844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195844u; }
        if (ctx->pc != 0x195844u) { return; }
    }
    ctx->pc = 0x195844u;
label_195844:
    // 0x195844: 0xc62c0000  lwc1        $f12, 0x0($s1)
    ctx->pc = 0x195844u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195848: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x195848u;
    SET_GPR_U32(ctx, 31, 0x195850u);
    ctx->pc = 0x19584Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195848u;
            // 0x19584c: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195850u; }
        if (ctx->pc != 0x195850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195850u; }
        if (ctx->pc != 0x195850u) { return; }
    }
    ctx->pc = 0x195850u;
label_195850:
    // 0x195850: 0xc60c0000  lwc1        $f12, 0x0($s0)
    ctx->pc = 0x195850u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195854: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x195854u;
    SET_GPR_U32(ctx, 31, 0x19585Cu);
    ctx->pc = 0x195858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195854u;
            // 0x195858: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19585Cu; }
        if (ctx->pc != 0x19585Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19585Cu; }
        if (ctx->pc != 0x19585Cu) { return; }
    }
    ctx->pc = 0x19585Cu;
label_19585c:
    // 0x19585c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19585cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195860: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195860u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x195864: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x195864u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x195868: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195868u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x19586c: 0x0  nop
    ctx->pc = 0x19586cu;
    // NOP
    // 0x195870: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x195870u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x195874: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195874u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195878: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x195878u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19587c: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x19587cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x195880: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x195880u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x195884: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x195884u;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x195888: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x195888u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x19588c: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19588cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x195890: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x195890u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195894: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195894u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x195898: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x195898u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19589c: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x19589cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1958a0: 0x0  nop
    ctx->pc = 0x1958a0u;
    // NOP
    // 0x1958a4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1958a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1958a8: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1958a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1958ac: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1958ACu;
    {
        const bool branch_taken_0x1958ac = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1958B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1958ACu;
            // 0x1958b0: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1958ac) {
            ctx->pc = 0x1958C4u;
            goto label_1958c4;
        }
    }
    ctx->pc = 0x1958B4u;
    // 0x1958b4: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1958b4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1958b8: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1958b8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1958bc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1958BCu;
    {
        const bool branch_taken_0x1958bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1958C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1958BCu;
            // 0x1958c0: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1958bc) {
            ctx->pc = 0x1958E0u;
            goto label_1958e0;
        }
    }
    ctx->pc = 0x1958C4u;
label_1958c4:
    // 0x1958c4: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x1958c4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x1958c8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1958c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1958cc: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1958ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1958d0: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1958d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1958d4: 0x0  nop
    ctx->pc = 0x1958d4u;
    // NOP
    // 0x1958d8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1958d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1958dc: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1958dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1958e0:
    // 0x1958e0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1958e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1958e4: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1958e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1958e8: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1958e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1958ec: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1958ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1958f0: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1958f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1958f4: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1958F4u;
    SET_GPR_U32(ctx, 31, 0x1958FCu);
    ctx->pc = 0x1958F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1958F4u;
            // 0x1958f8: 0xfc220048  sd          $v0, 0x48($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1958FCu; }
        if (ctx->pc != 0x1958FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1958FCu; }
        if (ctx->pc != 0x1958FCu) { return; }
    }
    ctx->pc = 0x1958FCu;
label_1958fc:
    // 0x1958fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1958fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_195900:
    // 0x195900: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x195900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x195904: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x195904u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x195908: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x195908u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19590c: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x19590cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x195910: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x195910u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x195914: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x195914u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x195918: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x195918u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19591c: 0x3e00008  jr          $ra
    ctx->pc = 0x19591Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x195920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19591Cu;
            // 0x195920: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x195638u: goto label_195638;
            case 0x19564Cu: goto label_19564c;
            case 0x195660u: goto label_195660;
            case 0x195674u: goto label_195674;
            case 0x195680u: goto label_195680;
            case 0x195694u: goto label_195694;
            case 0x195730u: goto label_195730;
            case 0x195740u: goto label_195740;
            case 0x195750u: goto label_195750;
            case 0x1957B8u: goto label_1957b8;
            case 0x1957D4u: goto label_1957d4;
            case 0x1957F8u: goto label_1957f8;
            case 0x195844u: goto label_195844;
            case 0x195850u: goto label_195850;
            case 0x19585Cu: goto label_19585c;
            case 0x1958C4u: goto label_1958c4;
            case 0x1958E0u: goto label_1958e0;
            case 0x1958FCu: goto label_1958fc;
            case 0x195900u: goto label_195900;
            default: break;
        }
        return;
    }
    ctx->pc = 0x195924u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
