#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00195930
// Address: 0x195930 - 0x195e20
void sub_00195930_0x195930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00195930_0x195930");
#endif

    switch (ctx->pc) {
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

    ctx->pc = 0x195930u;

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
