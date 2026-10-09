#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00194FD0
// Address: 0x194fd0 - 0x195e20
void sub_00194FD0_0x194fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00194FD0_0x194fd0");
#endif

    switch (ctx->pc) {
        case 0x19501cu: goto label_19501c;
        case 0x195030u: goto label_195030;
        case 0x195044u: goto label_195044;
        case 0x195054u: goto label_195054;
        case 0x195080u: goto label_195080;
        case 0x1950d0u: goto label_1950d0;
        case 0x1950e0u: goto label_1950e0;
        case 0x1950f0u: goto label_1950f0;
        case 0x195100u: goto label_195100;
        case 0x1951b4u: goto label_1951b4;
        case 0x1951d8u: goto label_1951d8;
        case 0x195228u: goto label_195228;
        case 0x195234u: goto label_195234;
        case 0x195240u: goto label_195240;
        case 0x195250u: goto label_195250;
        case 0x1952fcu: goto label_1952fc;
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
        case 0x195980u: goto label_195980;
        case 0x195994u: goto label_195994;
        case 0x1959a8u: goto label_1959a8;
        case 0x1959b4u: goto label_1959b4;
        case 0x1959c8u: goto label_1959c8;
        case 0x195a64u: goto label_195a64;
        case 0x195a74u: goto label_195a74;
        case 0x195a84u: goto label_195a84;
        case 0x195b28u: goto label_195b28;
        case 0x195b3cu: goto label_195b3c;
        case 0x195bd4u: goto label_195bd4;
        case 0x195be0u: goto label_195be0;
        case 0x195becu: goto label_195bec;
        case 0x195c90u: goto label_195c90;
        case 0x195ca4u: goto label_195ca4;
        case 0x195d3cu: goto label_195d3c;
        case 0x195d48u: goto label_195d48;
        case 0x195d54u: goto label_195d54;
        case 0x195df4u: goto label_195df4;
        default: break;
    }

    ctx->pc = 0x194fd0u;

    // 0x194fd0: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x194fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x194fd4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194fd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194fd8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x194fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x194fdc: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x194fdcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x194fe0: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x194fe0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x194fe4: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x194fe4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x194fe8: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x194fe8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x194fec: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x194fecu;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x194ff0: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x194ff0u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x194ff4: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194ff8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194FF8u;
    {
        const bool branch_taken_0x194ff8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x194FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194FF8u;
            // 0x194ffc: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194ff8) {
            ctx->pc = 0x195008u;
            goto label_195008;
        }
    }
    ctx->pc = 0x195000u;
    // 0x195000: 0x100000bf  b           . + 4 + (0xBF << 2)
    ctx->pc = 0x195000u;
    {
        const bool branch_taken_0x195000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195000u;
            // 0x195004: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195000) {
            ctx->pc = 0x195300u;
            goto label_195300;
        }
    }
    ctx->pc = 0x195008u;
label_195008:
    // 0x195008: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x195008u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x19500c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x19500cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x195010: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x195010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x195014: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x195014u;
    SET_GPR_U32(ctx, 31, 0x19501Cu);
    ctx->pc = 0x195018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195014u;
            // 0x195018: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19501Cu; }
        if (ctx->pc != 0x19501Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19501Cu; }
        if (ctx->pc != 0x19501Cu) { return; }
    }
    ctx->pc = 0x19501Cu;
label_19501c:
    // 0x19501c: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19501cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x195020: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x195020u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x195024: 0x34453700  ori         $a1, $v0, 0x3700
    ctx->pc = 0x195024u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x195028: 0xc0644a0  jal         func_191280
    ctx->pc = 0x195028u;
    SET_GPR_U32(ctx, 31, 0x195030u);
    ctx->pc = 0x19502Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195028u;
            // 0x19502c: 0x34463f40  ori         $a2, $v0, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195030u; }
        if (ctx->pc != 0x195030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195030u; }
        if (ctx->pc != 0x195030u) { return; }
    }
    ctx->pc = 0x195030u;
label_195030:
    // 0x195030: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x195030u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x195034: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x195034u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x195038: 0x24c64d80  addiu       $a2, $a2, 0x4D80
    ctx->pc = 0x195038u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19840));
    // 0x19503c: 0xc0644a0  jal         func_191280
    ctx->pc = 0x19503Cu;
    SET_GPR_U32(ctx, 31, 0x195044u);
    ctx->pc = 0x195040u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19503Cu;
            // 0x195040: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195044u; }
        if (ctx->pc != 0x195044u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195044u; }
        if (ctx->pc != 0x195044u) { return; }
    }
    ctx->pc = 0x195044u;
label_195044:
    // 0x195044: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x195044u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x195048: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x195048u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19504c: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x19504Cu;
    SET_GPR_U32(ctx, 31, 0x195054u);
    ctx->pc = 0x195050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19504Cu;
            // 0x195050: 0x27a60060  addiu       $a2, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195054u; }
        if (ctx->pc != 0x195054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195054u; }
        if (ctx->pc != 0x195054u) { return; }
    }
    ctx->pc = 0x195054u;
label_195054:
    // 0x195054: 0x27b000ac  addiu       $s0, $sp, 0xAC
    ctx->pc = 0x195054u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 172));
    // 0x195058: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x195058u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19505c: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x19505cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195060: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x195060u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x195064: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195064u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195068: 0x0  nop
    ctx->pc = 0x195068u;
    // NOP
    // 0x19506c: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x19506cu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x195070: 0x0  nop
    ctx->pc = 0x195070u;
    // NOP
    // 0x195074: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x195074u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x195078: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x195078u;
    SET_GPR_U32(ctx, 31, 0x195080u);
    ctx->pc = 0x19507Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195078u;
            // 0x19507c: 0x8e640018  lw          $a0, 0x18($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195080u; }
        if (ctx->pc != 0x195080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195080u; }
        if (ctx->pc != 0x195080u) { return; }
    }
    ctx->pc = 0x195080u;
label_195080:
    // 0x195080: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x195080u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x195084: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x195084u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x195088: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x195088u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x19508c: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x19508cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x195090: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x195090u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x195094: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195094u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195098: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x195098u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x19509c: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x19509cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1950a0: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1950a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1950a4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1950a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1950a8: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1950a8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1950ac: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1950acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1950b0: 0x9e020000  lwu         $v0, 0x0($s0)
    ctx->pc = 0x1950b0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1950b4: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x1950b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x1950b8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1950b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1950bc: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1950bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1950c0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1950c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1950c4: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x1950c4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x1950c8: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x1950C8u;
    SET_GPR_U32(ctx, 31, 0x1950D0u);
    ctx->pc = 0x1950CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1950C8u;
            // 0x1950cc: 0xc7ac00a0  lwc1        $f12, 0xA0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1950D0u; }
        if (ctx->pc != 0x1950D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1950D0u; }
        if (ctx->pc != 0x1950D0u) { return; }
    }
    ctx->pc = 0x1950D0u;
label_1950d0:
    // 0x1950d0: 0x27b200a4  addiu       $s2, $sp, 0xA4
    ctx->pc = 0x1950d0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 164));
    // 0x1950d4: 0xc64c0000  lwc1        $f12, 0x0($s2)
    ctx->pc = 0x1950d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x1950d8: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x1950D8u;
    SET_GPR_U32(ctx, 31, 0x1950E0u);
    ctx->pc = 0x1950DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1950D8u;
            // 0x1950dc: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1950E0u; }
        if (ctx->pc != 0x1950E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1950E0u; }
        if (ctx->pc != 0x1950E0u) { return; }
    }
    ctx->pc = 0x1950E0u;
label_1950e0:
    // 0x1950e0: 0x27b100a8  addiu       $s1, $sp, 0xA8
    ctx->pc = 0x1950e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
    // 0x1950e4: 0xc62c0000  lwc1        $f12, 0x0($s1)
    ctx->pc = 0x1950e4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x1950e8: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x1950E8u;
    SET_GPR_U32(ctx, 31, 0x1950F0u);
    ctx->pc = 0x1950ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1950E8u;
            // 0x1950ec: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1950F0u; }
        if (ctx->pc != 0x1950F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1950F0u; }
        if (ctx->pc != 0x1950F0u) { return; }
    }
    ctx->pc = 0x1950F0u;
label_1950f0:
    // 0x1950f0: 0x46000386  mov.s       $f14, $f0
    ctx->pc = 0x1950f0u;
    ctx->f[14] = FPU_MOV_S(ctx->f[0]);
    // 0x1950f4: 0x4600ab06  mov.s       $f12, $f21
    ctx->pc = 0x1950f4u;
    ctx->f[12] = FPU_MOV_S(ctx->f[21]);
    // 0x1950f8: 0xc064fb4  jal         func_193ED0
    ctx->pc = 0x1950F8u;
    SET_GPR_U32(ctx, 31, 0x195100u);
    ctx->pc = 0x1950FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1950F8u;
            // 0x1950fc: 0x4600a346  mov.s       $f13, $f20 (Delay Slot)
        ctx->f[13] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193ED0u;
    if (runtime->hasFunction(0x193ED0u)) {
        auto targetFn = runtime->lookupFunction(0x193ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195100u; }
        if (ctx->pc != 0x195100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193ED0_0x193ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195100u; }
        if (ctx->pc != 0x195100u) { return; }
    }
    ctx->pc = 0x195100u;
label_195100:
    // 0x195100: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x195100u;
    {
        const bool branch_taken_0x195100 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x195104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195100u;
            // 0x195104: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195100) {
            ctx->pc = 0x195110u;
            goto label_195110;
        }
    }
    ctx->pc = 0x195108u;
    // 0x195108: 0x1000007d  b           . + 4 + (0x7D << 2)
    ctx->pc = 0x195108u;
    {
        const bool branch_taken_0x195108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19510Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195108u;
            // 0x19510c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195108) {
            ctx->pc = 0x195300u;
            goto label_195300;
        }
    }
    ctx->pc = 0x195110u;
label_195110:
    // 0x195110: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195110u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x195114: 0xc422fd54  lwc1        $f2, -0x2AC($at)
    ctx->pc = 0x195114u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x195118: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x195118u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19511c: 0x0  nop
    ctx->pc = 0x19511cu;
    // NOP
    // 0x195120: 0x460e0036  c.le.s      $f0, $f14
    ctx->pc = 0x195120u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[14])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x195124: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195124u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195128: 0xc421fd58  lwc1        $f1, -0x2A8($at)
    ctx->pc = 0x195128u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19512c: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x19512cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x195130: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x195130u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x195134: 0x46151080  add.s       $f2, $f2, $f21
    ctx->pc = 0x195134u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[21]);
    // 0x195138: 0x46140840  add.s       $f1, $f1, $f20
    ctx->pc = 0x195138u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[20]);
    // 0x19513c: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19513cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x195140: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x195140u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195144: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195144u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x195148: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x195148u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19514c: 0x44020800  mfc1        $v0, $f1
    ctx->pc = 0x19514cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195150: 0x0  nop
    ctx->pc = 0x195150u;
    // NOP
    // 0x195154: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x195154u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195158: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x195158u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19515c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x19515Cu;
    {
        const bool branch_taken_0x19515c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x195160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19515Cu;
            // 0x195160: 0x623025  or          $a2, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19515c) {
            ctx->pc = 0x195174u;
            goto label_195174;
        }
    }
    ctx->pc = 0x195164u;
    // 0x195164: 0x460073a4  .word       0x460073A4                   # cvt.w.s     $f14, $f14 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195164u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[14]); std::memcpy(&ctx->f[14], &tmp, sizeof(tmp)); }
    // 0x195168: 0x44037000  mfc1        $v1, $f14
    ctx->pc = 0x195168u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[14], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x19516c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19516Cu;
    {
        const bool branch_taken_0x19516c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19516Cu;
            // 0x195170: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19516c) {
            ctx->pc = 0x195190u;
            goto label_195190;
        }
    }
    ctx->pc = 0x195174u;
label_195174:
    // 0x195174: 0x46007381  sub.s       $f14, $f14, $f0
    ctx->pc = 0x195174u;
    ctx->f[14] = FPU_SUB_S(ctx->f[14], ctx->f[0]);
    // 0x195178: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x195178u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x19517c: 0x460073a4  .word       0x460073A4                   # cvt.w.s     $f14, $f14 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19517cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[14]); std::memcpy(&ctx->f[14], &tmp, sizeof(tmp)); }
    // 0x195180: 0x44037000  mfc1        $v1, $f14
    ctx->pc = 0x195180u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[14], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x195184: 0x0  nop
    ctx->pc = 0x195184u;
    // NOP
    // 0x195188: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x195188u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19518c: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x19518cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_195190:
    // 0x195190: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195190u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195194: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x195194u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x195198: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x195198u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x19519c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19519cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1951a0: 0x2665000c  addiu       $a1, $s3, 0xC
    ctx->pc = 0x1951a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 12));
    // 0x1951a4: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x1951a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x1951a8: 0x27a60060  addiu       $a2, $sp, 0x60
    ctx->pc = 0x1951a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1951ac: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x1951ACu;
    SET_GPR_U32(ctx, 31, 0x1951B4u);
    ctx->pc = 0x1951B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1951ACu;
            // 0x1951b0: 0xfc220030  sd          $v0, 0x30($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1951B4u; }
        if (ctx->pc != 0x1951B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1951B4u; }
        if (ctx->pc != 0x1951B4u) { return; }
    }
    ctx->pc = 0x1951B4u;
label_1951b4:
    // 0x1951b4: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x1951b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1951b8: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x1951b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x1951bc: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1951bcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1951c0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1951c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1951c4: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1951c4u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1951c8: 0x0  nop
    ctx->pc = 0x1951c8u;
    // NOP
    // 0x1951cc: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x1951ccu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x1951d0: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1951D0u;
    SET_GPR_U32(ctx, 31, 0x1951D8u);
    ctx->pc = 0x1951D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1951D0u;
            // 0x1951d4: 0x8e64001c  lw          $a0, 0x1C($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1951D8u; }
        if (ctx->pc != 0x1951D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1951D8u; }
        if (ctx->pc != 0x1951D8u) { return; }
    }
    ctx->pc = 0x1951D8u;
label_1951d8:
    // 0x1951d8: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1951d8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1951dc: 0x9e030000  lwu         $v1, 0x0($s0)
    ctx->pc = 0x1951dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1951e0: 0x308600ff  andi        $a2, $a0, 0xFF
    ctx->pc = 0x1951e0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1951e4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1951e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1951e8: 0x22202  srl         $a0, $v0, 8
    ctx->pc = 0x1951e8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1951ec: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1951ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1951f0: 0x304400ff  andi        $a0, $v0, 0xFF
    ctx->pc = 0x1951f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1951f4: 0x52a38  dsll        $a1, $a1, 8
    ctx->pc = 0x1951f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 8);
    // 0x1951f8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1951f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1951fc: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x1951fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x195200: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x195200u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x195204: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x195204u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195208: 0x852825  or          $a1, $a0, $a1
    ctx->pc = 0x195208u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x19520c: 0x22638  dsll        $a0, $v0, 24
    ctx->pc = 0x19520cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << 24);
    // 0x195210: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x195210u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
    // 0x195214: 0x851825  or          $v1, $a0, $a1
    ctx->pc = 0x195214u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x195218: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x195218u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x19521c: 0xfc220038  sd          $v0, 0x38($at)
    ctx->pc = 0x19521cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
    // 0x195220: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x195220u;
    SET_GPR_U32(ctx, 31, 0x195228u);
    ctx->pc = 0x195224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195220u;
            // 0x195224: 0xc7ac00a0  lwc1        $f12, 0xA0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195228u; }
        if (ctx->pc != 0x195228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195228u; }
        if (ctx->pc != 0x195228u) { return; }
    }
    ctx->pc = 0x195228u;
label_195228:
    // 0x195228: 0xc64c0000  lwc1        $f12, 0x0($s2)
    ctx->pc = 0x195228u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19522c: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x19522Cu;
    SET_GPR_U32(ctx, 31, 0x195234u);
    ctx->pc = 0x195230u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19522Cu;
            // 0x195230: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195234u; }
        if (ctx->pc != 0x195234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195234u; }
        if (ctx->pc != 0x195234u) { return; }
    }
    ctx->pc = 0x195234u;
label_195234:
    // 0x195234: 0xc62c0000  lwc1        $f12, 0x0($s1)
    ctx->pc = 0x195234u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195238: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x195238u;
    SET_GPR_U32(ctx, 31, 0x195240u);
    ctx->pc = 0x19523Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195238u;
            // 0x19523c: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195240u; }
        if (ctx->pc != 0x195240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195240u; }
        if (ctx->pc != 0x195240u) { return; }
    }
    ctx->pc = 0x195240u;
label_195240:
    // 0x195240: 0x46000386  mov.s       $f14, $f0
    ctx->pc = 0x195240u;
    ctx->f[14] = FPU_MOV_S(ctx->f[0]);
    // 0x195244: 0x4600ab06  mov.s       $f12, $f21
    ctx->pc = 0x195244u;
    ctx->f[12] = FPU_MOV_S(ctx->f[21]);
    // 0x195248: 0xc064fb4  jal         func_193ED0
    ctx->pc = 0x195248u;
    SET_GPR_U32(ctx, 31, 0x195250u);
    ctx->pc = 0x19524Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195248u;
            // 0x19524c: 0x4600a346  mov.s       $f13, $f20 (Delay Slot)
        ctx->f[13] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193ED0u;
    if (runtime->hasFunction(0x193ED0u)) {
        auto targetFn = runtime->lookupFunction(0x193ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195250u; }
        if (ctx->pc != 0x195250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193ED0_0x193ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195250u; }
        if (ctx->pc != 0x195250u) { return; }
    }
    ctx->pc = 0x195250u;
label_195250:
    // 0x195250: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x195250u;
    {
        const bool branch_taken_0x195250 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x195254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195250u;
            // 0x195254: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195250) {
            ctx->pc = 0x195260u;
            goto label_195260;
        }
    }
    ctx->pc = 0x195258u;
    // 0x195258: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x195258u;
    {
        const bool branch_taken_0x195258 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19525Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195258u;
            // 0x19525c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195258) {
            ctx->pc = 0x195300u;
            goto label_195300;
        }
    }
    ctx->pc = 0x195260u;
label_195260:
    // 0x195260: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195260u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x195264: 0xc422fd54  lwc1        $f2, -0x2AC($at)
    ctx->pc = 0x195264u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x195268: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x195268u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19526c: 0x0  nop
    ctx->pc = 0x19526cu;
    // NOP
    // 0x195270: 0x460e0036  c.le.s      $f0, $f14
    ctx->pc = 0x195270u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[14])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x195274: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195274u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195278: 0xc421fd58  lwc1        $f1, -0x2A8($at)
    ctx->pc = 0x195278u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19527c: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x19527cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x195280: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x195280u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x195284: 0x46151080  add.s       $f2, $f2, $f21
    ctx->pc = 0x195284u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[21]);
    // 0x195288: 0x46140840  add.s       $f1, $f1, $f20
    ctx->pc = 0x195288u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[20]);
    // 0x19528c: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19528cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x195290: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x195290u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195294: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195294u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x195298: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x195298u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19529c: 0x44020800  mfc1        $v0, $f1
    ctx->pc = 0x19529cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1952a0: 0x0  nop
    ctx->pc = 0x1952a0u;
    // NOP
    // 0x1952a4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1952a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1952a8: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1952a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1952ac: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1952ACu;
    {
        const bool branch_taken_0x1952ac = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1952B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1952ACu;
            // 0x1952b0: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1952ac) {
            ctx->pc = 0x1952C4u;
            goto label_1952c4;
        }
    }
    ctx->pc = 0x1952B4u;
    // 0x1952b4: 0x460073a4  .word       0x460073A4                   # cvt.w.s     $f14, $f14 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1952b4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[14]); std::memcpy(&ctx->f[14], &tmp, sizeof(tmp)); }
    // 0x1952b8: 0x44037000  mfc1        $v1, $f14
    ctx->pc = 0x1952b8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[14], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1952bc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1952BCu;
    {
        const bool branch_taken_0x1952bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1952C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1952BCu;
            // 0x1952c0: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1952bc) {
            ctx->pc = 0x1952E0u;
            goto label_1952e0;
        }
    }
    ctx->pc = 0x1952C4u;
label_1952c4:
    // 0x1952c4: 0x46007381  sub.s       $f14, $f14, $f0
    ctx->pc = 0x1952c4u;
    ctx->f[14] = FPU_SUB_S(ctx->f[14], ctx->f[0]);
    // 0x1952c8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1952c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1952cc: 0x460073a4  .word       0x460073A4                   # cvt.w.s     $f14, $f14 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1952ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[14]); std::memcpy(&ctx->f[14], &tmp, sizeof(tmp)); }
    // 0x1952d0: 0x44037000  mfc1        $v1, $f14
    ctx->pc = 0x1952d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[14], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1952d4: 0x0  nop
    ctx->pc = 0x1952d4u;
    // NOP
    // 0x1952d8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1952d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1952dc: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1952dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1952e0:
    // 0x1952e0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1952e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1952e4: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1952e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1952e8: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1952e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1952ec: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1952ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1952f0: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1952f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1952f4: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1952F4u;
    SET_GPR_U32(ctx, 31, 0x1952FCu);
    ctx->pc = 0x1952F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1952F4u;
            // 0x1952f8: 0xfc220040  sd          $v0, 0x40($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1952FCu; }
        if (ctx->pc != 0x1952FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1952FCu; }
        if (ctx->pc != 0x1952FCu) { return; }
    }
    ctx->pc = 0x1952FCu;
label_1952fc:
    // 0x1952fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1952fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_195300:
    // 0x195300: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x195300u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x195304: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x195304u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x195308: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x195308u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19530c: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x19530cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x195310: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x195310u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x195314: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x195314u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x195318: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x195318u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19531c: 0x3e00008  jr          $ra
    ctx->pc = 0x19531Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x195320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19531Cu;
            // 0x195320: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x195008u: goto label_195008;
            case 0x19501Cu: goto label_19501c;
            case 0x195030u: goto label_195030;
            case 0x195044u: goto label_195044;
            case 0x195054u: goto label_195054;
            case 0x195080u: goto label_195080;
            case 0x1950D0u: goto label_1950d0;
            case 0x1950E0u: goto label_1950e0;
            case 0x1950F0u: goto label_1950f0;
            case 0x195100u: goto label_195100;
            case 0x195110u: goto label_195110;
            case 0x195174u: goto label_195174;
            case 0x195190u: goto label_195190;
            case 0x1951B4u: goto label_1951b4;
            case 0x1951D8u: goto label_1951d8;
            case 0x195228u: goto label_195228;
            case 0x195234u: goto label_195234;
            case 0x195240u: goto label_195240;
            case 0x195250u: goto label_195250;
            case 0x195260u: goto label_195260;
            case 0x1952C4u: goto label_1952c4;
            case 0x1952E0u: goto label_1952e0;
            case 0x1952FCu: goto label_1952fc;
            case 0x195300u: goto label_195300;
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
            case 0x19596Cu: goto label_19596c;
            case 0x195980u: goto label_195980;
            case 0x195994u: goto label_195994;
            case 0x1959A8u: goto label_1959a8;
            case 0x1959B4u: goto label_1959b4;
            case 0x1959C8u: goto label_1959c8;
            case 0x195A64u: goto label_195a64;
            case 0x195A74u: goto label_195a74;
            case 0x195A84u: goto label_195a84;
            case 0x195AECu: goto label_195aec;
            case 0x195B08u: goto label_195b08;
            case 0x195B28u: goto label_195b28;
            case 0x195B3Cu: goto label_195b3c;
            case 0x195BD4u: goto label_195bd4;
            case 0x195BE0u: goto label_195be0;
            case 0x195BECu: goto label_195bec;
            case 0x195C54u: goto label_195c54;
            case 0x195C70u: goto label_195c70;
            case 0x195C90u: goto label_195c90;
            case 0x195CA4u: goto label_195ca4;
            case 0x195D3Cu: goto label_195d3c;
            case 0x195D48u: goto label_195d48;
            case 0x195D54u: goto label_195d54;
            case 0x195DBCu: goto label_195dbc;
            case 0x195DD8u: goto label_195dd8;
            case 0x195DF4u: goto label_195df4;
            case 0x195DF8u: goto label_195df8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x195324u;
    // 0x195324: 0x0  nop
    ctx->pc = 0x195324u;
    // NOP
    // 0x195328: 0x0  nop
    ctx->pc = 0x195328u;
    // NOP
    // 0x19532c: 0x0  nop
    ctx->pc = 0x19532cu;
    // NOP
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
            case 0x195008u: goto label_195008;
            case 0x19501Cu: goto label_19501c;
            case 0x195030u: goto label_195030;
            case 0x195044u: goto label_195044;
            case 0x195054u: goto label_195054;
            case 0x195080u: goto label_195080;
            case 0x1950D0u: goto label_1950d0;
            case 0x1950E0u: goto label_1950e0;
            case 0x1950F0u: goto label_1950f0;
            case 0x195100u: goto label_195100;
            case 0x195110u: goto label_195110;
            case 0x195174u: goto label_195174;
            case 0x195190u: goto label_195190;
            case 0x1951B4u: goto label_1951b4;
            case 0x1951D8u: goto label_1951d8;
            case 0x195228u: goto label_195228;
            case 0x195234u: goto label_195234;
            case 0x195240u: goto label_195240;
            case 0x195250u: goto label_195250;
            case 0x195260u: goto label_195260;
            case 0x1952C4u: goto label_1952c4;
            case 0x1952E0u: goto label_1952e0;
            case 0x1952FCu: goto label_1952fc;
            case 0x195300u: goto label_195300;
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
            case 0x19596Cu: goto label_19596c;
            case 0x195980u: goto label_195980;
            case 0x195994u: goto label_195994;
            case 0x1959A8u: goto label_1959a8;
            case 0x1959B4u: goto label_1959b4;
            case 0x1959C8u: goto label_1959c8;
            case 0x195A64u: goto label_195a64;
            case 0x195A74u: goto label_195a74;
            case 0x195A84u: goto label_195a84;
            case 0x195AECu: goto label_195aec;
            case 0x195B08u: goto label_195b08;
            case 0x195B28u: goto label_195b28;
            case 0x195B3Cu: goto label_195b3c;
            case 0x195BD4u: goto label_195bd4;
            case 0x195BE0u: goto label_195be0;
            case 0x195BECu: goto label_195bec;
            case 0x195C54u: goto label_195c54;
            case 0x195C70u: goto label_195c70;
            case 0x195C90u: goto label_195c90;
            case 0x195CA4u: goto label_195ca4;
            case 0x195D3Cu: goto label_195d3c;
            case 0x195D48u: goto label_195d48;
            case 0x195D54u: goto label_195d54;
            case 0x195DBCu: goto label_195dbc;
            case 0x195DD8u: goto label_195dd8;
            case 0x195DF4u: goto label_195df4;
            case 0x195DF8u: goto label_195df8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1955FCu;
    // 0x1955fc: 0x0  nop
    ctx->pc = 0x1955fcu;
    // NOP
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
            case 0x195008u: goto label_195008;
            case 0x19501Cu: goto label_19501c;
            case 0x195030u: goto label_195030;
            case 0x195044u: goto label_195044;
            case 0x195054u: goto label_195054;
            case 0x195080u: goto label_195080;
            case 0x1950D0u: goto label_1950d0;
            case 0x1950E0u: goto label_1950e0;
            case 0x1950F0u: goto label_1950f0;
            case 0x195100u: goto label_195100;
            case 0x195110u: goto label_195110;
            case 0x195174u: goto label_195174;
            case 0x195190u: goto label_195190;
            case 0x1951B4u: goto label_1951b4;
            case 0x1951D8u: goto label_1951d8;
            case 0x195228u: goto label_195228;
            case 0x195234u: goto label_195234;
            case 0x195240u: goto label_195240;
            case 0x195250u: goto label_195250;
            case 0x195260u: goto label_195260;
            case 0x1952C4u: goto label_1952c4;
            case 0x1952E0u: goto label_1952e0;
            case 0x1952FCu: goto label_1952fc;
            case 0x195300u: goto label_195300;
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
            case 0x19596Cu: goto label_19596c;
            case 0x195980u: goto label_195980;
            case 0x195994u: goto label_195994;
            case 0x1959A8u: goto label_1959a8;
            case 0x1959B4u: goto label_1959b4;
            case 0x1959C8u: goto label_1959c8;
            case 0x195A64u: goto label_195a64;
            case 0x195A74u: goto label_195a74;
            case 0x195A84u: goto label_195a84;
            case 0x195AECu: goto label_195aec;
            case 0x195B08u: goto label_195b08;
            case 0x195B28u: goto label_195b28;
            case 0x195B3Cu: goto label_195b3c;
            case 0x195BD4u: goto label_195bd4;
            case 0x195BE0u: goto label_195be0;
            case 0x195BECu: goto label_195bec;
            case 0x195C54u: goto label_195c54;
            case 0x195C70u: goto label_195c70;
            case 0x195C90u: goto label_195c90;
            case 0x195CA4u: goto label_195ca4;
            case 0x195D3Cu: goto label_195d3c;
            case 0x195D48u: goto label_195d48;
            case 0x195D54u: goto label_195d54;
            case 0x195DBCu: goto label_195dbc;
            case 0x195DD8u: goto label_195dd8;
            case 0x195DF4u: goto label_195df4;
            case 0x195DF8u: goto label_195df8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x195924u;
    // 0x195924: 0x0  nop
    ctx->pc = 0x195924u;
    // NOP
    // 0x195928: 0x0  nop
    ctx->pc = 0x195928u;
    // NOP
    // 0x19592c: 0x0  nop
    ctx->pc = 0x19592cu;
    // NOP
    // 0x195930: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x195930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x195934: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195934u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195938: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x195938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x19593c: 0x7fb40050  sq          $s4, 0x50($sp)
    ctx->pc = 0x19593cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 20));
    // 0x195940: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x195940u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x195944: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x195944u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x195948: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x195948u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x19594c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x19594cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x195950: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x195950u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x195954: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x195954u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x195958: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x195958u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x19595c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19595Cu;
    {
        const bool branch_taken_0x19595c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x195960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19595Cu;
            // 0x195960: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19595c) {
            ctx->pc = 0x19596Cu;
            goto label_19596c;
        }
    }
    ctx->pc = 0x195964u;
    // 0x195964: 0x10000124  b           . + 4 + (0x124 << 2)
    ctx->pc = 0x195964u;
    {
        const bool branch_taken_0x195964 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195964u;
            // 0x195968: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195964) {
            ctx->pc = 0x195DF8u;
            goto label_195df8;
        }
    }
    ctx->pc = 0x19596Cu;
label_19596c:
    // 0x19596c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x19596cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x195970: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x195970u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x195974: 0x24840100  addiu       $a0, $a0, 0x100
    ctx->pc = 0x195974u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 256));
    // 0x195978: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x195978u;
    SET_GPR_U32(ctx, 31, 0x195980u);
    ctx->pc = 0x19597Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195978u;
            // 0x19597c: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195980u; }
        if (ctx->pc != 0x195980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195980u; }
        if (ctx->pc != 0x195980u) { return; }
    }
    ctx->pc = 0x195980u;
label_195980:
    // 0x195980: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x195980u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x195984: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x195984u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x195988: 0x34453700  ori         $a1, $v0, 0x3700
    ctx->pc = 0x195988u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x19598c: 0xc0644a0  jal         func_191280
    ctx->pc = 0x19598Cu;
    SET_GPR_U32(ctx, 31, 0x195994u);
    ctx->pc = 0x195990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19598Cu;
            // 0x195990: 0x34463f40  ori         $a2, $v0, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195994u; }
        if (ctx->pc != 0x195994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195994u; }
        if (ctx->pc != 0x195994u) { return; }
    }
    ctx->pc = 0x195994u;
label_195994:
    // 0x195994: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x195994u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x195998: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x195998u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19599c: 0x24c64d80  addiu       $a2, $a2, 0x4D80
    ctx->pc = 0x19599cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19840));
    // 0x1959a0: 0xc0644a0  jal         func_191280
    ctx->pc = 0x1959A0u;
    SET_GPR_U32(ctx, 31, 0x1959A8u);
    ctx->pc = 0x1959A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1959A0u;
            // 0x1959a4: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1959A8u; }
        if (ctx->pc != 0x1959A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1959A8u; }
        if (ctx->pc != 0x1959A8u) { return; }
    }
    ctx->pc = 0x1959A8u;
label_1959a8:
    // 0x1959a8: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x1959a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1959ac: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1959ACu;
    SET_GPR_U32(ctx, 31, 0x1959B4u);
    ctx->pc = 0x1959B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1959ACu;
            // 0x1959b0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1959B4u; }
        if (ctx->pc != 0x1959B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1959B4u; }
        if (ctx->pc != 0x1959B4u) { return; }
    }
    ctx->pc = 0x1959B4u;
label_1959b4:
    // 0x1959b4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1959b4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1959b8: 0x27a400b0  addiu       $a0, $sp, 0xB0
    ctx->pc = 0x1959b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x1959bc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1959bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1959c0: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x1959C0u;
    SET_GPR_U32(ctx, 31, 0x1959C8u);
    ctx->pc = 0x1959C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1959C0u;
            // 0x1959c4: 0x27a60070  addiu       $a2, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1959C8u; }
        if (ctx->pc != 0x1959C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1959C8u; }
        if (ctx->pc != 0x1959C8u) { return; }
    }
    ctx->pc = 0x1959C8u;
label_1959c8:
    // 0x1959c8: 0x27b400bc  addiu       $s4, $sp, 0xBC
    ctx->pc = 0x1959c8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 29), 188));
    // 0x1959cc: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x1959ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x1959d0: 0xc6800000  lwc1        $f0, 0x0($s4)
    ctx->pc = 0x1959d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1959d4: 0x111c02  srl         $v1, $s1, 16
    ctx->pc = 0x1959d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 17), 16));
    // 0x1959d8: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1959d8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1959dc: 0x306400ff  andi        $a0, $v1, 0xFF
    ctx->pc = 0x1959dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1959e0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1959e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1959e4: 0x111202  srl         $v0, $s1, 8
    ctx->pc = 0x1959e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 8));
    // 0x1959e8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1959e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1959ec: 0x21a38  dsll        $v1, $v0, 8
    ctx->pc = 0x1959ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 8);
    // 0x1959f0: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1959f0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1959f4: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1959f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1959f8: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1959f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1959fc: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1959fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x195a00: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x195a00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x195a04: 0x111602  srl         $v0, $s1, 24
    ctx->pc = 0x195a04u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 24));
    // 0x195a08: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x195a08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195a0c: 0x21638  dsll        $v0, $v0, 24
    ctx->pc = 0x195a0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x195a10: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x195a10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x195a14: 0xe6800000  swc1        $f0, 0x0($s4)
    ctx->pc = 0x195a14u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 0), bits); }
    // 0x195a18: 0x9e820000  lwu         $v0, 0x0($s4)
    ctx->pc = 0x195a18u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x195a1c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195a1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195a20: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x195a20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x195a24: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x195a24u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x195a28: 0xc6810000  lwc1        $f1, 0x0($s4)
    ctx->pc = 0x195a28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x195a2c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195a2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195a30: 0xc6000030  lwc1        $f0, 0x30($s0)
    ctx->pc = 0x195a30u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195a34: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195a34u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195a38: 0xe7a000cc  swc1        $f0, 0xCC($sp)
    ctx->pc = 0x195a38u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 204), bits); }
    // 0x195a3c: 0xc6000034  lwc1        $f0, 0x34($s0)
    ctx->pc = 0x195a3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195a40: 0x9fa300cc  lwu         $v1, 0xCC($sp)
    ctx->pc = 0x195a40u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 204)));
    // 0x195a44: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195a44u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195a48: 0xe7a000c8  swc1        $f0, 0xC8($sp)
    ctx->pc = 0x195a48u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 200), bits); }
    // 0x195a4c: 0x9fa200c8  lwu         $v0, 0xC8($sp)
    ctx->pc = 0x195a4cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x195a50: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195a50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195a54: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x195a54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x195a58: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x195a58u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x195a5c: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x195A5Cu;
    SET_GPR_U32(ctx, 31, 0x195A64u);
    ctx->pc = 0x195A60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195A5Cu;
            // 0x195a60: 0xc7ac00b0  lwc1        $f12, 0xB0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195A64u; }
        if (ctx->pc != 0x195A64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195A64u; }
        if (ctx->pc != 0x195A64u) { return; }
    }
    ctx->pc = 0x195A64u;
label_195a64:
    // 0x195a64: 0x27b300b4  addiu       $s3, $sp, 0xB4
    ctx->pc = 0x195a64u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 180));
    // 0x195a68: 0xc66c0000  lwc1        $f12, 0x0($s3)
    ctx->pc = 0x195a68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195a6c: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x195A6Cu;
    SET_GPR_U32(ctx, 31, 0x195A74u);
    ctx->pc = 0x195A70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195A6Cu;
            // 0x195a70: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195A74u; }
        if (ctx->pc != 0x195A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195A74u; }
        if (ctx->pc != 0x195A74u) { return; }
    }
    ctx->pc = 0x195A74u;
label_195a74:
    // 0x195a74: 0x27b200b8  addiu       $s2, $sp, 0xB8
    ctx->pc = 0x195a74u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 184));
    // 0x195a78: 0xc64c0000  lwc1        $f12, 0x0($s2)
    ctx->pc = 0x195a78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195a7c: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x195A7Cu;
    SET_GPR_U32(ctx, 31, 0x195A84u);
    ctx->pc = 0x195A80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195A7Cu;
            // 0x195a80: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195A84u; }
        if (ctx->pc != 0x195A84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195A84u; }
        if (ctx->pc != 0x195A84u) { return; }
    }
    ctx->pc = 0x195A84u;
label_195a84:
    // 0x195a84: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195a84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195a88: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195a88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x195a8c: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x195a8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x195a90: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195a90u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195a94: 0x0  nop
    ctx->pc = 0x195a94u;
    // NOP
    // 0x195a98: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x195a98u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x195a9c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195a9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195aa0: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x195aa0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x195aa4: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x195aa4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x195aa8: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x195aa8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x195aac: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x195aacu;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x195ab0: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x195ab0u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x195ab4: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195ab4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x195ab8: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x195ab8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195abc: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195abcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x195ac0: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x195ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195ac4: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x195ac4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195ac8: 0x0  nop
    ctx->pc = 0x195ac8u;
    // NOP
    // 0x195acc: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x195accu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195ad0: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x195ad0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x195ad4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x195AD4u;
    {
        const bool branch_taken_0x195ad4 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x195AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195AD4u;
            // 0x195ad8: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195ad4) {
            ctx->pc = 0x195AECu;
            goto label_195aec;
        }
    }
    ctx->pc = 0x195ADCu;
    // 0x195adc: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195adcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x195ae0: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x195ae0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x195ae4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x195AE4u;
    {
        const bool branch_taken_0x195ae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195AE4u;
            // 0x195ae8: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195ae4) {
            ctx->pc = 0x195B08u;
            goto label_195b08;
        }
    }
    ctx->pc = 0x195AECu;
label_195aec:
    // 0x195aec: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x195aecu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x195af0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x195af0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x195af4: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195af4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x195af8: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x195af8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x195afc: 0x0  nop
    ctx->pc = 0x195afcu;
    // NOP
    // 0x195b00: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x195b00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x195b04: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x195b04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_195b08:
    // 0x195b08: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195b08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195b0c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x195b0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x195b10: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195b10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195b14: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x195b14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x195b18: 0xfc220038  sd          $v0, 0x38($at)
    ctx->pc = 0x195b18u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
    // 0x195b1c: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x195b1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x195b20: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x195B20u;
    SET_GPR_U32(ctx, 31, 0x195B28u);
    ctx->pc = 0x195B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195B20u;
            // 0x195b24: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195B28u; }
        if (ctx->pc != 0x195B28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195B28u; }
        if (ctx->pc != 0x195B28u) { return; }
    }
    ctx->pc = 0x195B28u;
label_195b28:
    // 0x195b28: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x195b28u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x195b2c: 0x27a400b0  addiu       $a0, $sp, 0xB0
    ctx->pc = 0x195b2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x195b30: 0x2605000c  addiu       $a1, $s0, 0xC
    ctx->pc = 0x195b30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x195b34: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x195B34u;
    SET_GPR_U32(ctx, 31, 0x195B3Cu);
    ctx->pc = 0x195B38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195B34u;
            // 0x195b38: 0x27a60070  addiu       $a2, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195B3Cu; }
        if (ctx->pc != 0x195B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195B3Cu; }
        if (ctx->pc != 0x195B3Cu) { return; }
    }
    ctx->pc = 0x195B3Cu;
label_195b3c:
    // 0x195b3c: 0xc6800000  lwc1        $f0, 0x0($s4)
    ctx->pc = 0x195b3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195b40: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x195b40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x195b44: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195b44u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195b48: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195b48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195b4c: 0x111402  srl         $v0, $s1, 16
    ctx->pc = 0x195b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 16));
    // 0x195b50: 0x304500ff  andi        $a1, $v0, 0xFF
    ctx->pc = 0x195b50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195b54: 0x111202  srl         $v0, $s1, 8
    ctx->pc = 0x195b54u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 8));
    // 0x195b58: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x195b58u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x195b5c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x195b5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195b60: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x195b60u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x195b64: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x195b64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x195b68: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x195b68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x195b6c: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x195b6cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x195b70: 0x111602  srl         $v0, $s1, 24
    ctx->pc = 0x195b70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 24));
    // 0x195b74: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x195b74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x195b78: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x195b78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195b7c: 0x21638  dsll        $v0, $v0, 24
    ctx->pc = 0x195b7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x195b80: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x195b80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x195b84: 0xe6800000  swc1        $f0, 0x0($s4)
    ctx->pc = 0x195b84u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 0), bits); }
    // 0x195b88: 0x9e820000  lwu         $v0, 0x0($s4)
    ctx->pc = 0x195b88u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x195b8c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195b8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195b90: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x195b90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x195b94: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x195b94u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x195b98: 0xc6810000  lwc1        $f1, 0x0($s4)
    ctx->pc = 0x195b98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x195b9c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195b9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195ba0: 0xc6000038  lwc1        $f0, 0x38($s0)
    ctx->pc = 0x195ba0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195ba4: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195ba4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195ba8: 0xe7a000cc  swc1        $f0, 0xCC($sp)
    ctx->pc = 0x195ba8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 204), bits); }
    // 0x195bac: 0xc600003c  lwc1        $f0, 0x3C($s0)
    ctx->pc = 0x195bacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195bb0: 0x9fa300cc  lwu         $v1, 0xCC($sp)
    ctx->pc = 0x195bb0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 204)));
    // 0x195bb4: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195bb4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195bb8: 0xe7a000c8  swc1        $f0, 0xC8($sp)
    ctx->pc = 0x195bb8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 200), bits); }
    // 0x195bbc: 0x9fa200c8  lwu         $v0, 0xC8($sp)
    ctx->pc = 0x195bbcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x195bc0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195bc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195bc4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x195bc4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x195bc8: 0xfc220048  sd          $v0, 0x48($at)
    ctx->pc = 0x195bc8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
    // 0x195bcc: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x195BCCu;
    SET_GPR_U32(ctx, 31, 0x195BD4u);
    ctx->pc = 0x195BD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195BCCu;
            // 0x195bd0: 0xc7ac00b0  lwc1        $f12, 0xB0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195BD4u; }
        if (ctx->pc != 0x195BD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195BD4u; }
        if (ctx->pc != 0x195BD4u) { return; }
    }
    ctx->pc = 0x195BD4u;
label_195bd4:
    // 0x195bd4: 0xc66c0000  lwc1        $f12, 0x0($s3)
    ctx->pc = 0x195bd4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195bd8: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x195BD8u;
    SET_GPR_U32(ctx, 31, 0x195BE0u);
    ctx->pc = 0x195BDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195BD8u;
            // 0x195bdc: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195BE0u; }
        if (ctx->pc != 0x195BE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195BE0u; }
        if (ctx->pc != 0x195BE0u) { return; }
    }
    ctx->pc = 0x195BE0u;
label_195be0:
    // 0x195be0: 0xc64c0000  lwc1        $f12, 0x0($s2)
    ctx->pc = 0x195be0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195be4: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x195BE4u;
    SET_GPR_U32(ctx, 31, 0x195BECu);
    ctx->pc = 0x195BE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195BE4u;
            // 0x195be8: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195BECu; }
        if (ctx->pc != 0x195BECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195BECu; }
        if (ctx->pc != 0x195BECu) { return; }
    }
    ctx->pc = 0x195BECu;
label_195bec:
    // 0x195bec: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195becu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195bf0: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x195bf4: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x195bf4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x195bf8: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195bf8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195bfc: 0x0  nop
    ctx->pc = 0x195bfcu;
    // NOP
    // 0x195c00: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x195c00u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x195c04: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195c04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195c08: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x195c08u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x195c0c: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x195c0cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x195c10: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x195c10u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x195c14: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x195c14u;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x195c18: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x195c18u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x195c1c: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195c1cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x195c20: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x195c20u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195c24: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195c24u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x195c28: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x195c28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195c2c: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x195c2cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195c30: 0x0  nop
    ctx->pc = 0x195c30u;
    // NOP
    // 0x195c34: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x195c34u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195c38: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x195c38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x195c3c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x195C3Cu;
    {
        const bool branch_taken_0x195c3c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x195C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195C3Cu;
            // 0x195c40: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195c3c) {
            ctx->pc = 0x195C54u;
            goto label_195c54;
        }
    }
    ctx->pc = 0x195C44u;
    // 0x195c44: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195c44u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x195c48: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x195c48u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x195c4c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x195C4Cu;
    {
        const bool branch_taken_0x195c4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195C50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195C4Cu;
            // 0x195c50: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195c4c) {
            ctx->pc = 0x195C70u;
            goto label_195c70;
        }
    }
    ctx->pc = 0x195C54u;
label_195c54:
    // 0x195c54: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x195c54u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x195c58: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x195c58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x195c5c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195c5cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x195c60: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x195c60u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x195c64: 0x0  nop
    ctx->pc = 0x195c64u;
    // NOP
    // 0x195c68: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x195c68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x195c6c: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x195c6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_195c70:
    // 0x195c70: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195c74: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x195c74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x195c78: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195c78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195c7c: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x195c7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x195c80: 0xfc220050  sd          $v0, 0x50($at)
    ctx->pc = 0x195c80u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 80), GPR_U64(ctx, 2));
    // 0x195c84: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x195c84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x195c88: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x195C88u;
    SET_GPR_U32(ctx, 31, 0x195C90u);
    ctx->pc = 0x195C8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195C88u;
            // 0x195c8c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195C90u; }
        if (ctx->pc != 0x195C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195C90u; }
        if (ctx->pc != 0x195C90u) { return; }
    }
    ctx->pc = 0x195C90u;
label_195c90:
    // 0x195c90: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x195c90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x195c94: 0x27a400b0  addiu       $a0, $sp, 0xB0
    ctx->pc = 0x195c94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x195c98: 0x26050018  addiu       $a1, $s0, 0x18
    ctx->pc = 0x195c98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x195c9c: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x195C9Cu;
    SET_GPR_U32(ctx, 31, 0x195CA4u);
    ctx->pc = 0x195CA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195C9Cu;
            // 0x195ca0: 0x27a60070  addiu       $a2, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195CA4u; }
        if (ctx->pc != 0x195CA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195CA4u; }
        if (ctx->pc != 0x195CA4u) { return; }
    }
    ctx->pc = 0x195CA4u;
label_195ca4:
    // 0x195ca4: 0xc6800000  lwc1        $f0, 0x0($s4)
    ctx->pc = 0x195ca4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195ca8: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x195ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x195cac: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195cacu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195cb0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195cb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195cb4: 0x111402  srl         $v0, $s1, 16
    ctx->pc = 0x195cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 16));
    // 0x195cb8: 0x304500ff  andi        $a1, $v0, 0xFF
    ctx->pc = 0x195cb8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195cbc: 0x111202  srl         $v0, $s1, 8
    ctx->pc = 0x195cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 8));
    // 0x195cc0: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x195cc0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x195cc4: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x195cc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195cc8: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x195cc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x195ccc: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x195cccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x195cd0: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x195cd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x195cd4: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x195cd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x195cd8: 0x111602  srl         $v0, $s1, 24
    ctx->pc = 0x195cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 24));
    // 0x195cdc: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x195cdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x195ce0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x195ce0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x195ce4: 0x21638  dsll        $v0, $v0, 24
    ctx->pc = 0x195ce4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x195ce8: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x195ce8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x195cec: 0xe6800000  swc1        $f0, 0x0($s4)
    ctx->pc = 0x195cecu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 0), bits); }
    // 0x195cf0: 0x9e820000  lwu         $v0, 0x0($s4)
    ctx->pc = 0x195cf0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x195cf4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195cf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195cf8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x195cf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x195cfc: 0xfc220058  sd          $v0, 0x58($at)
    ctx->pc = 0x195cfcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 88), GPR_U64(ctx, 2));
    // 0x195d00: 0xc6810000  lwc1        $f1, 0x0($s4)
    ctx->pc = 0x195d00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x195d04: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195d04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195d08: 0xc6000040  lwc1        $f0, 0x40($s0)
    ctx->pc = 0x195d08u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195d0c: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195d0cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195d10: 0xe7a000cc  swc1        $f0, 0xCC($sp)
    ctx->pc = 0x195d10u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 204), bits); }
    // 0x195d14: 0xc6000044  lwc1        $f0, 0x44($s0)
    ctx->pc = 0x195d14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 68)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x195d18: 0x9fa300cc  lwu         $v1, 0xCC($sp)
    ctx->pc = 0x195d18u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 204)));
    // 0x195d1c: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x195d1cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x195d20: 0xe7a000c8  swc1        $f0, 0xC8($sp)
    ctx->pc = 0x195d20u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 200), bits); }
    // 0x195d24: 0x9fa200c8  lwu         $v0, 0xC8($sp)
    ctx->pc = 0x195d24u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x195d28: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195d28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195d2c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x195d2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x195d30: 0xfc220060  sd          $v0, 0x60($at)
    ctx->pc = 0x195d30u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 96), GPR_U64(ctx, 2));
    // 0x195d34: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x195D34u;
    SET_GPR_U32(ctx, 31, 0x195D3Cu);
    ctx->pc = 0x195D38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195D34u;
            // 0x195d38: 0xc7ac00b0  lwc1        $f12, 0xB0($sp) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195D3Cu; }
        if (ctx->pc != 0x195D3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195D3Cu; }
        if (ctx->pc != 0x195D3Cu) { return; }
    }
    ctx->pc = 0x195D3Cu;
label_195d3c:
    // 0x195d3c: 0xc66c0000  lwc1        $f12, 0x0($s3)
    ctx->pc = 0x195d3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195d40: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x195D40u;
    SET_GPR_U32(ctx, 31, 0x195D48u);
    ctx->pc = 0x195D44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195D40u;
            // 0x195d44: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195D48u; }
        if (ctx->pc != 0x195D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195D48u; }
        if (ctx->pc != 0x195D48u) { return; }
    }
    ctx->pc = 0x195D48u;
label_195d48:
    // 0x195d48: 0xc64c0000  lwc1        $f12, 0x0($s2)
    ctx->pc = 0x195d48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x195d4c: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x195D4Cu;
    SET_GPR_U32(ctx, 31, 0x195D54u);
    ctx->pc = 0x195D50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195D4Cu;
            // 0x195d50: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195D54u; }
        if (ctx->pc != 0x195D54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195D54u; }
        if (ctx->pc != 0x195D54u) { return; }
    }
    ctx->pc = 0x195D54u;
label_195d54:
    // 0x195d54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195d54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195d58: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x195d58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x195d5c: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x195d5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x195d60: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x195d60u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x195d64: 0x0  nop
    ctx->pc = 0x195d64u;
    // NOP
    // 0x195d68: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x195d68u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x195d6c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x195d6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x195d70: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x195d70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x195d74: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x195d74u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x195d78: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x195d78u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x195d7c: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x195d7cu;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x195d80: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x195d80u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x195d84: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195d84u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x195d88: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x195d88u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195d8c: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195d8cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x195d90: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x195d90u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195d94: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x195d94u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x195d98: 0x0  nop
    ctx->pc = 0x195d98u;
    // NOP
    // 0x195d9c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x195d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x195da0: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x195da0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x195da4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x195DA4u;
    {
        const bool branch_taken_0x195da4 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x195DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195DA4u;
            // 0x195da8: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195da4) {
            ctx->pc = 0x195DBCu;
            goto label_195dbc;
        }
    }
    ctx->pc = 0x195DACu;
    // 0x195dac: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195dacu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x195db0: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x195db0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x195db4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x195DB4u;
    {
        const bool branch_taken_0x195db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x195DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195DB4u;
            // 0x195db8: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x195db4) {
            ctx->pc = 0x195DD8u;
            goto label_195dd8;
        }
    }
    ctx->pc = 0x195DBCu;
label_195dbc:
    // 0x195dbc: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x195dbcu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x195dc0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x195dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x195dc4: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x195dc4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x195dc8: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x195dc8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x195dcc: 0x0  nop
    ctx->pc = 0x195dccu;
    // NOP
    // 0x195dd0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x195dd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x195dd4: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x195dd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_195dd8:
    // 0x195dd8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x195dd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x195ddc: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x195ddcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x195de0: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x195de0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x195de4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x195de4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x195de8: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x195de8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x195dec: 0xc064f88  jal         func_193E20
    ctx->pc = 0x195DECu;
    SET_GPR_U32(ctx, 31, 0x195DF4u);
    ctx->pc = 0x195DF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x195DECu;
            // 0x195df0: 0xfc220068  sd          $v0, 0x68($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 104), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195DF4u; }
        if (ctx->pc != 0x195DF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x195DF4u; }
        if (ctx->pc != 0x195DF4u) { return; }
    }
    ctx->pc = 0x195DF4u;
label_195df4:
    // 0x195df4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x195df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_195df8:
    // 0x195df8: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x195df8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x195dfc: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x195dfcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x195e00: 0x7bb40050  lq          $s4, 0x50($sp)
    ctx->pc = 0x195e00u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x195e04: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x195e04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x195e08: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x195e08u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x195e0c: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x195e0cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x195e10: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x195e10u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x195e14: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x195e14u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x195e18: 0x3e00008  jr          $ra
    ctx->pc = 0x195E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x195E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x195E18u;
            // 0x195e1c: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x195008u: goto label_195008;
            case 0x19501Cu: goto label_19501c;
            case 0x195030u: goto label_195030;
            case 0x195044u: goto label_195044;
            case 0x195054u: goto label_195054;
            case 0x195080u: goto label_195080;
            case 0x1950D0u: goto label_1950d0;
            case 0x1950E0u: goto label_1950e0;
            case 0x1950F0u: goto label_1950f0;
            case 0x195100u: goto label_195100;
            case 0x195110u: goto label_195110;
            case 0x195174u: goto label_195174;
            case 0x195190u: goto label_195190;
            case 0x1951B4u: goto label_1951b4;
            case 0x1951D8u: goto label_1951d8;
            case 0x195228u: goto label_195228;
            case 0x195234u: goto label_195234;
            case 0x195240u: goto label_195240;
            case 0x195250u: goto label_195250;
            case 0x195260u: goto label_195260;
            case 0x1952C4u: goto label_1952c4;
            case 0x1952E0u: goto label_1952e0;
            case 0x1952FCu: goto label_1952fc;
            case 0x195300u: goto label_195300;
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
            case 0x19596Cu: goto label_19596c;
            case 0x195980u: goto label_195980;
            case 0x195994u: goto label_195994;
            case 0x1959A8u: goto label_1959a8;
            case 0x1959B4u: goto label_1959b4;
            case 0x1959C8u: goto label_1959c8;
            case 0x195A64u: goto label_195a64;
            case 0x195A74u: goto label_195a74;
            case 0x195A84u: goto label_195a84;
            case 0x195AECu: goto label_195aec;
            case 0x195B08u: goto label_195b08;
            case 0x195B28u: goto label_195b28;
            case 0x195B3Cu: goto label_195b3c;
            case 0x195BD4u: goto label_195bd4;
            case 0x195BE0u: goto label_195be0;
            case 0x195BECu: goto label_195bec;
            case 0x195C54u: goto label_195c54;
            case 0x195C70u: goto label_195c70;
            case 0x195C90u: goto label_195c90;
            case 0x195CA4u: goto label_195ca4;
            case 0x195D3Cu: goto label_195d3c;
            case 0x195D48u: goto label_195d48;
            case 0x195D54u: goto label_195d54;
            case 0x195DBCu: goto label_195dbc;
            case 0x195DD8u: goto label_195dd8;
            case 0x195DF4u: goto label_195df4;
            case 0x195DF8u: goto label_195df8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x195E20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
