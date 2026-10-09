#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00195330
// Address: 0x195330 - 0x1955fc
void sub_00195330_0x195330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00195330_0x195330");
#endif

    switch (ctx->pc) {
        case 0x19537cu: goto label_19537c;
        case 0x195390u: goto label_195390;
        case 0x1953a4u: goto label_1953a4;
        case 0x1953b4u: goto label_1953b4;
        case 0x1953e0u: goto label_1953e0;
        case 0x195430u: goto label_195430;
        case 0x195440u: goto label_195440;
        case 0x195450u: goto label_195450;
        case 0x1954f8u: goto label_1954f8;
        case 0x19551cu: goto label_19551c;
        case 0x195528u: goto label_195528;
        case 0x195534u: goto label_195534;
        case 0x1955d4u: goto label_1955d4;
        default: break;
    }

    ctx->pc = 0x195330u;

    // 0x195330: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x195330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x195334: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195334u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195338: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x195338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x19533c: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x19533cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x195340: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x195340u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x195344: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x195344u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x195348: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x195348u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x19534c: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x19534cu;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x195350: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x195350u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x195354: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x195354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x195358: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x195358u;
    {
        const bool branch_taken_0x195358 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19535Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195358u;
            // 0x19535c: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195358) {
            ctx->pc = 0x195368u;
            goto label_195368;
        }
    }
    ctx->pc = 0x195360u;
    // 0x195360: 0x1000009d  b           . + 4 + (0x9D << 2)
    ctx->pc = 0x195360u;
    {
        const bool branch_taken_0x195360 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195360u;
            // 0x195364: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195360) {
            ctx->pc = 0x1955D8u;
            goto label_1955d8;
        }
    }
    ctx->pc = 0x195368u;
label_195368:
    // 0x195368: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x195368u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x19536c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x19536cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x195370: 0x24840070  addiu       $a0, $a0, 0x70
    ctx->pc = 0x195370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 112));
    // 0x195374: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x195374u;
    SET_GPR_U32(ctx, 31, 0x19537Cu);
    ctx->pc = 0x195378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195374u;
            // 0x195378: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19537Cu; }
        if (ctx->pc != 0x19537Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19537Cu; }
        if (ctx->pc != 0x19537Cu) { return; }
    }
    ctx->pc = 0x19537Cu;
label_19537c:
    // 0x19537c: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19537cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x195380: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x195380u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x195384: 0x34453700  ori         $a1, $v0, 0x3700
    ctx->pc = 0x195384u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x195388: 0xc0644a0  jal         func_191280
    ctx->pc = 0x195388u;
    SET_GPR_U32(ctx, 31, 0x195390u);
    ctx->pc = 0x19538Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195388u;
            // 0x19538c: 0x34463f40  ori         $a2, $v0, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195390u; }
        if (ctx->pc != 0x195390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195390u; }
        if (ctx->pc != 0x195390u) { return; }
    }
    ctx->pc = 0x195390u;
label_195390:
    // 0x195390: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x195390u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x195394: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x195394u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x195398: 0x24c64d80  addiu       $a2, $a2, 0x4D80
    ctx->pc = 0x195398u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19840));
    // 0x19539c: 0xc0644a0  jal         func_191280
    ctx->pc = 0x19539Cu;
    SET_GPR_U32(ctx, 31, 0x1953A4u);
    ctx->pc = 0x1953A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19539Cu;
            // 0x1953a0: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1953A4u; }
        if (ctx->pc != 0x1953A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1953A4u; }
        if (ctx->pc != 0x1953A4u) { return; }
    }
    ctx->pc = 0x1953A4u;
label_1953a4:
    // 0x1953a4: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1953a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1953a8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1953a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1953ac: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x1953ACu;
    SET_GPR_U32(ctx, 31, 0x1953B4u);
    ctx->pc = 0x1953B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1953ACu;
            // 0x1953b0: 0x27a60060  addiu       $a2, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1953B4u; }
        if (ctx->pc != 0x1953B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1953B4u; }
        if (ctx->pc != 0x1953B4u) { return; }
    }
    ctx->pc = 0x1953B4u;
label_1953b4:
    // 0x1953b4: 0x27b200ac  addiu       $s2, $sp, 0xAC
    ctx->pc = 0x1953b4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 172));
    // 0x1953b8: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x1953b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x1953bc: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1953bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1953c0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1953c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1953c4: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1953c4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1953c8: 0x0  nop
    ctx->pc = 0x1953c8u;
    // NOP
    // 0x1953cc: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1953ccu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1953d0: 0x0  nop
    ctx->pc = 0x1953d0u;
    // NOP
    // 0x1953d4: 0xe6400000  swc1        $f0, 0x0($s2)
    ctx->pc = 0x1953d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
    // 0x1953d8: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1953D8u;
    SET_GPR_U32(ctx, 31, 0x1953E0u);
    ctx->pc = 0x1953DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1953D8u;
            // 0x1953dc: 0x8e640018  lw          $a0, 0x18($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1953E0u; }
        if (ctx->pc != 0x1953E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1953E0u; }
        if (ctx->pc != 0x1953E0u) { return; }
    }
    ctx->pc = 0x1953E0u;
label_1953e0:
    // 0x1953e0: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1953e0u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1953e4: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1953e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1953e8: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1953e8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1953ec: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1953ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1953f0: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x1953f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x1953f4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1953f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1953f8: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1953f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1953fc: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1953fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x195400: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x195400u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x195404: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x195404u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x195408: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x195408u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x19540c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x19540cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195410: 0x9e420000  lwu         $v0, 0x0($s2)
    ctx->pc = 0x195410u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x195414: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x195414u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x195418: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x195418u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x19541c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19541cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195420: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x195420u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x195424: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x195424u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x195428: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x195428u;
    SET_GPR_U32(ctx, 31, 0x195430u);
    ctx->pc = 0x19542Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195428u;
            // 0x19542c: 0xc7ac00a0  lwc1        $f12, 0xA0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195430u; }
        if (ctx->pc != 0x195430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195430u; }
        if (ctx->pc != 0x195430u) { return; }
    }
    ctx->pc = 0x195430u;
label_195430:
    // 0x195430: 0x27b100a4  addiu       $s1, $sp, 0xA4
    ctx->pc = 0x195430u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 164));
    // 0x195434: 0xc62c0000  lwc1        $f12, 0x0($s1)
    ctx->pc = 0x195434u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195438: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x195438u;
    SET_GPR_U32(ctx, 31, 0x195440u);
    ctx->pc = 0x19543Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195438u;
            // 0x19543c: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195440u; }
        if (ctx->pc != 0x195440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195440u; }
        if (ctx->pc != 0x195440u) { return; }
    }
    ctx->pc = 0x195440u;
label_195440:
    // 0x195440: 0x27b000a8  addiu       $s0, $sp, 0xA8
    ctx->pc = 0x195440u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
    // 0x195444: 0xc60c0000  lwc1        $f12, 0x0($s0)
    ctx->pc = 0x195444u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195448: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x195448u;
    SET_GPR_U32(ctx, 31, 0x195450u);
    ctx->pc = 0x19544Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195448u;
            // 0x19544c: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195450u; }
        if (ctx->pc != 0x195450u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195450u; }
        if (ctx->pc != 0x195450u) { return; }
    }
    ctx->pc = 0x195450u;
label_195450:
    // 0x195450: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195450u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195454: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195454u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x195458: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x195458u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19545c: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x19545cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195460: 0x0  nop
    ctx->pc = 0x195460u;
    // NOP
    // 0x195464: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x195464u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x195468: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195468u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19546c: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x19546cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x195470: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x195470u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x195474: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x195474u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x195478: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x195478u;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x19547c: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x19547cu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x195480: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195480u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x195484: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x195484u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195488: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195488u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x19548c: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x19548cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195490: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x195490u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195494: 0x0  nop
    ctx->pc = 0x195494u;
    // NOP
    // 0x195498: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x195498u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19549c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x19549cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1954a0: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1954A0u;
    {
        const bool branch_taken_0x1954a0 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1954A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1954A0u;
            // 0x1954a4: 0x623025  or          $a2, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1954a0) {
            ctx->pc = 0x1954B8u;
            goto label_1954b8;
        }
    }
    ctx->pc = 0x1954A8u;
    // 0x1954a8: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1954a8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1954ac: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1954acu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1954b0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1954B0u;
    {
        const bool branch_taken_0x1954b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1954B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1954B0u;
            // 0x1954b4: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1954b0) {
            ctx->pc = 0x1954D4u;
            goto label_1954d4;
        }
    }
    ctx->pc = 0x1954B8u;
label_1954b8:
    // 0x1954b8: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x1954b8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x1954bc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1954bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1954c0: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1954c0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1954c4: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1954c4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1954c8: 0x0  nop
    ctx->pc = 0x1954c8u;
    // NOP
    // 0x1954cc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1954ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1954d0: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1954d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1954d4:
    // 0x1954d4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1954d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1954d8: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1954d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1954dc: 0x2665000c  addiu       $a1, $s3, 0xC
    ctx->pc = 0x1954dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 12));
    // 0x1954e0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1954e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1954e4: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1954e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1954e8: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x1954e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x1954ec: 0x27a60060  addiu       $a2, $sp, 0x60
    ctx->pc = 0x1954ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1954f0: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x1954F0u;
    SET_GPR_U32(ctx, 31, 0x1954F8u);
    ctx->pc = 0x1954F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1954F0u;
            // 0x1954f4: 0xfc220030  sd          $v0, 0x30($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1954F8u; }
        if (ctx->pc != 0x1954F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1954F8u; }
        if (ctx->pc != 0x1954F8u) { return; }
    }
    ctx->pc = 0x1954F8u;
label_1954f8:
    // 0x1954f8: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1954f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1954fc: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x1954fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x195500: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195500u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195504: 0x0  nop
    ctx->pc = 0x195504u;
    // NOP
    // 0x195508: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x195508u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x19550c: 0x0  nop
    ctx->pc = 0x19550cu;
    // NOP
    // 0x195510: 0xe6400000  swc1        $f0, 0x0($s2)
    ctx->pc = 0x195510u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
    // 0x195514: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x195514u;
    SET_GPR_U32(ctx, 31, 0x19551Cu);
    ctx->pc = 0x195518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195514u;
            // 0x195518: 0xc7ac00a0  lwc1        $f12, 0xA0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19551Cu; }
        if (ctx->pc != 0x19551Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19551Cu; }
        if (ctx->pc != 0x19551Cu) { return; }
    }
    ctx->pc = 0x19551Cu;
label_19551c:
    // 0x19551c: 0xc62c0000  lwc1        $f12, 0x0($s1)
    ctx->pc = 0x19551cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195520: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x195520u;
    SET_GPR_U32(ctx, 31, 0x195528u);
    ctx->pc = 0x195524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195520u;
            // 0x195524: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195528u; }
        if (ctx->pc != 0x195528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195528u; }
        if (ctx->pc != 0x195528u) { return; }
    }
    ctx->pc = 0x195528u;
label_195528:
    // 0x195528: 0xc60c0000  lwc1        $f12, 0x0($s0)
    ctx->pc = 0x195528u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19552c: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x19552Cu;
    SET_GPR_U32(ctx, 31, 0x195534u);
    ctx->pc = 0x195530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19552Cu;
            // 0x195530: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195534u; }
        if (ctx->pc != 0x195534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195534u; }
        if (ctx->pc != 0x195534u) { return; }
    }
    ctx->pc = 0x195534u;
label_195534:
    // 0x195534: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195534u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195538: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195538u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x19553c: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x19553cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x195540: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195540u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195544: 0x0  nop
    ctx->pc = 0x195544u;
    // NOP
    // 0x195548: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x195548u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x19554c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19554cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195550: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x195550u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x195554: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x195554u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x195558: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x195558u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x19555c: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x19555cu;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x195560: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x195560u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x195564: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195564u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x195568: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x195568u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x19556c: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19556cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x195570: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x195570u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195574: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x195574u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195578: 0x0  nop
    ctx->pc = 0x195578u;
    // NOP
    // 0x19557c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x19557cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195580: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x195580u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x195584: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x195584u;
    {
        const bool branch_taken_0x195584 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x195588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195584u;
            // 0x195588: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195584) {
            ctx->pc = 0x19559Cu;
            goto label_19559c;
        }
    }
    ctx->pc = 0x19558Cu;
    // 0x19558c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19558cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x195590: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x195590u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x195594: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x195594u;
    {
        const bool branch_taken_0x195594 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195594u;
            // 0x195598: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195594) {
            ctx->pc = 0x1955B8u;
            goto label_1955b8;
        }
    }
    ctx->pc = 0x19559Cu;
label_19559c:
    // 0x19559c: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x19559cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x1955a0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1955a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1955a4: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1955a4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1955a8: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1955a8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1955ac: 0x0  nop
    ctx->pc = 0x1955acu;
    // NOP
    // 0x1955b0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1955b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1955b4: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1955b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1955b8:
    // 0x1955b8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1955b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1955bc: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1955bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1955c0: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1955c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1955c4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1955c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1955c8: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1955c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1955cc: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1955CCu;
    SET_GPR_U32(ctx, 31, 0x1955D4u);
    ctx->pc = 0x1955D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1955CCu;
            // 0x1955d0: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1955D4u; }
        if (ctx->pc != 0x1955D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1955D4u; }
        if (ctx->pc != 0x1955D4u) { return; }
    }
    ctx->pc = 0x1955D4u;
label_1955d4:
    // 0x1955d4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1955d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1955d8:
    // 0x1955d8: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1955d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1955dc: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x1955dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x1955e0: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x1955e0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1955e4: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1955e4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1955e8: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1955e8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1955ec: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1955ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1955f0: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1955f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1955f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1955F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1955F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1955F4u;
            // 0x1955f8: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x195368u: goto label_195368;
            case 0x19537Cu: goto label_19537c;
            case 0x195390u: goto label_195390;
            case 0x1953A4u: goto label_1953a4;
            case 0x1953B4u: goto label_1953b4;
            case 0x1953E0u: goto label_1953e0;
            case 0x195430u: goto label_195430;
            case 0x195440u: goto label_195440;
            case 0x195450u: goto label_195450;
            case 0x1954B8u: goto label_1954b8;
            case 0x1954D4u: goto label_1954d4;
            case 0x1954F8u: goto label_1954f8;
            case 0x19551Cu: goto label_19551c;
            case 0x195528u: goto label_195528;
            case 0x195534u: goto label_195534;
            case 0x19559Cu: goto label_19559c;
            case 0x1955B8u: goto label_1955b8;
            case 0x1955D4u: goto label_1955d4;
            case 0x1955D8u: goto label_1955d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1955FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
