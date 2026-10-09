#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ABB60
// Address: 0x1abb60 - 0x1ac630
void sub_001ABB60_0x1abb60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ABB60_0x1abb60");
#endif

    switch (ctx->pc) {
        case 0x1abc84u: goto label_1abc84;
        case 0x1abc90u: goto label_1abc90;
        case 0x1abdc8u: goto label_1abdc8;
        case 0x1abe3cu: goto label_1abe3c;
        case 0x1abf24u: goto label_1abf24;
        case 0x1abfecu: goto label_1abfec;
        case 0x1ac0a8u: goto label_1ac0a8;
        case 0x1ac168u: goto label_1ac168;
        case 0x1ac218u: goto label_1ac218;
        case 0x1ac398u: goto label_1ac398;
        case 0x1ac3a4u: goto label_1ac3a4;
        case 0x1ac5f8u: goto label_1ac5f8;
        default: break;
    }

    ctx->pc = 0x1abb60u;

    // 0x1abb60: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1abb60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1abb64: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abb64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abb68: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1abb68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1abb6c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1abb6cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1abb70: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1abb70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1abb74: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1abb74u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1abb78: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1abb78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1abb7c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1abb7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1abb80: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x1abb80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x1abb84: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ABB84u;
    {
        const bool branch_taken_0x1abb84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABB88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABB84u;
            // 0x1abb88: 0x80a02d  daddu       $s4, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abb84) {
            ctx->pc = 0x1ABB94u;
            goto label_1abb94;
        }
    }
    ctx->pc = 0x1ABB8Cu;
    // 0x1abb8c: 0x1000008f  b           . + 4 + (0x8F << 2)
    ctx->pc = 0x1ABB8Cu;
    {
        const bool branch_taken_0x1abb8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABB8Cu;
            // 0x1abb90: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abb8c) {
            ctx->pc = 0x1ABDCCu;
            goto label_1abdcc;
        }
    }
    ctx->pc = 0x1ABB94u;
label_1abb94:
    // 0x1abb94: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abb94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abb98: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x1abb98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1abb9c: 0x8c24f9bc  lw          $a0, -0x644($at)
    ctx->pc = 0x1abb9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965692)));
    // 0x1abba0: 0x441823  subu        $v1, $v0, $a0
    ctx->pc = 0x1abba0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1abba4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ABBA4u;
    {
        const bool branch_taken_0x1abba4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1ABBA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABBA4u;
            // 0x1abba8: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abba4) {
            ctx->pc = 0x1ABBB4u;
            goto label_1abbb4;
        }
    }
    ctx->pc = 0x1ABBACu;
    // 0x1abbac: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1abbacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1abbb0: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1abbb0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1abbb4:
    // 0x1abbb4: 0x24900  sll         $t1, $v0, 4
    ctx->pc = 0x1abbb4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1abbb8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abbb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abbbc: 0x8c22f9c0  lw          $v0, -0x640($at)
    ctx->pc = 0x1abbbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1abbc0: 0x24031000  addiu       $v1, $zero, 0x1000
    ctx->pc = 0x1abbc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1abbc4: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1abbc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1abbc8: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ABBC8u;
    {
        const bool branch_taken_0x1abbc8 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1ABBCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABBC8u;
            // 0x1abbcc: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abbc8) {
            ctx->pc = 0x1ABBD8u;
            goto label_1abbd8;
        }
    }
    ctx->pc = 0x1ABBD0u;
    // 0x1abbd0: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1abbd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1abbd4: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1abbd4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1abbd8:
    // 0x1abbd8: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1abbd8u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1abbdc: 0x24100  sll         $t0, $v0, 4
    ctx->pc = 0x1abbdcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1abbe0: 0x3c024420  lui         $v0, 0x4420
    ctx->pc = 0x1abbe0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17440 << 16));
    // 0x1abbe4: 0x86850002  lh          $a1, 0x2($s4)
    ctx->pc = 0x1abbe4u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 2)));
    // 0x1abbe8: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1abbe8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1abbec: 0x86830006  lh          $v1, 0x6($s4)
    ctx->pc = 0x1abbecu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 6)));
    // 0x1abbf0: 0x86870000  lh          $a3, 0x0($s4)
    ctx->pc = 0x1abbf0u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1abbf4: 0x3c064180  lui         $a2, 0x4180
    ctx->pc = 0x1abbf4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)16768 << 16));
    // 0x1abbf8: 0x86840004  lh          $a0, 0x4($s4)
    ctx->pc = 0x1abbf8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x1abbfc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abbfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abc00: 0x59100  sll         $s2, $a1, 4
    ctx->pc = 0x1abc00u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1abc04: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1abc04u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abc08: 0x0  nop
    ctx->pc = 0x1abc08u;
    // NOP
    // 0x1abc0c: 0x46000883  div.s       $f2, $f1, $f0
    ctx->pc = 0x1abc0cu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[1] / ctx->f[0];
    // 0x1abc10: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x1abc10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x1abc14: 0x44870000  mtc1        $a3, $f0
    ctx->pc = 0x1abc14u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abc18: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1abc18u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1abc1c: 0x0  nop
    ctx->pc = 0x1abc1cu;
    // NOP
    // 0x1abc20: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1abc20u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1abc24: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x1abc24u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1abc28: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1abc28u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1abc2c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abc2cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1abc30: 0x44130000  mfc1        $s3, $f0
    ctx->pc = 0x1abc30u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 19, bits); }
    // 0x1abc34: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1abc34u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abc38: 0x0  nop
    ctx->pc = 0x1abc38u;
    // NOP
    // 0x1abc3c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1abc3cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1abc40: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x1abc40u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1abc44: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1abc44u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1abc48: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abc48u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1abc4c: 0x44110000  mfc1        $s1, $f0
    ctx->pc = 0x1abc4cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 17, bits); }
    // 0x1abc50: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ABC50u;
    {
        const bool branch_taken_0x1abc50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1ABC54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABC50u;
            // 0x1abc54: 0x38100  sll         $s0, $v1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abc50) {
            ctx->pc = 0x1ABC60u;
            goto label_1abc60;
        }
    }
    ctx->pc = 0x1ABC58u;
    // 0x1abc58: 0x129043  sra         $s2, $s2, 1
    ctx->pc = 0x1abc58u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 18), 1));
    // 0x1abc5c: 0x108043  sra         $s0, $s0, 1
    ctx->pc = 0x1abc5cu;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
label_1abc60:
    // 0x1abc60: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1abc60u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1abc64: 0x2699821  addu        $s3, $s3, $t1
    ctx->pc = 0x1abc64u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 9)));
    // 0x1abc68: 0x2298821  addu        $s1, $s1, $t1
    ctx->pc = 0x1abc68u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 9)));
    // 0x1abc6c: 0x2489021  addu        $s2, $s2, $t0
    ctx->pc = 0x1abc6cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
    // 0x1abc70: 0x2088021  addu        $s0, $s0, $t0
    ctx->pc = 0x1abc70u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 8)));
    // 0x1abc74: 0x24843f50  addiu       $a0, $a0, 0x3F50
    ctx->pc = 0x1abc74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16208));
    // 0x1abc78: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x1abc78u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x1abc7c: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x1ABC7Cu;
    SET_GPR_U32(ctx, 31, 0x1ABC84u);
    ctx->pc = 0x1ABC80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABC7Cu;
            // 0x1abc80: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABC84u; }
        if (ctx->pc != 0x1ABC84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABC84u; }
        if (ctx->pc != 0x1ABC84u) { return; }
    }
    ctx->pc = 0x1ABC84u;
label_1abc84:
    // 0x1abc84: 0x8e840008  lw          $a0, 0x8($s4)
    ctx->pc = 0x1abc84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x1abc88: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1ABC88u;
    SET_GPR_U32(ctx, 31, 0x1ABC90u);
    ctx->pc = 0x1ABC8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABC88u;
            // 0x1abc8c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABC90u; }
        if (ctx->pc != 0x1ABC90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABC90u; }
        if (ctx->pc != 0x1ABC90u) { return; }
    }
    ctx->pc = 0x1ABC90u;
label_1abc90:
    // 0x1abc90: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1abc90u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1abc94: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1abc94u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1abc98: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1abc98u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1abc9c: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1abc9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1abca0: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x1abca0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x1abca4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1abca4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1abca8: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1abca8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1abcac: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1abcacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1abcb0: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1abcb0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1abcb4: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1abcb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1abcb8: 0x642825  or          $a1, $v1, $a0
    ctx->pc = 0x1abcb8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1abcbc: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1abcbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1abcc0: 0x32638  dsll        $a0, $v1, 24
    ctx->pc = 0x1abcc0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 24);
    // 0x1abcc4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1abcc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1abcc8: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1abcc8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1abccc: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1abcccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1abcd0: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1abcd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1abcd4: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1abcd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1abcd8: 0xfc230028  sd          $v1, 0x28($at)
    ctx->pc = 0x1abcd8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 3));
    // 0x1abcdc: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1abcdcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abce0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abce0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abce4: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1abce4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1abce8: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1abce8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1abcec: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1ABCECu;
    {
        const bool branch_taken_0x1abcec = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1abcec) {
            ctx->pc = 0x1ABD04u;
            goto label_1abd04;
        }
    }
    ctx->pc = 0x1ABCF4u;
    // 0x1abcf4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abcf4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1abcf8: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1abcf8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1abcfc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1ABCFCu;
    {
        const bool branch_taken_0x1abcfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABCFCu;
            // 0x1abd00: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abcfc) {
            ctx->pc = 0x1ABD20u;
            goto label_1abd20;
        }
    }
    ctx->pc = 0x1ABD04u;
label_1abd04:
    // 0x1abd04: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1abd04u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1abd08: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1abd08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1abd0c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abd0cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1abd10: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1abd10u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1abd14: 0x0  nop
    ctx->pc = 0x1abd14u;
    // NOP
    // 0x1abd18: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1abd18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1abd1c: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1abd1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1abd20:
    // 0x1abd20: 0x13203c  dsll32      $a0, $s3, 0
    ctx->pc = 0x1abd20u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) << (32 + 0));
    // 0x1abd24: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1abd24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1abd28: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1abd28u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1abd2c: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x1abd2cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1abd30: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1abd30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1abd34: 0x12103c  dsll32      $v0, $s2, 0
    ctx->pc = 0x1abd34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) << (32 + 0));
    // 0x1abd38: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1abd38u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1abd3c: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x1abd3cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x1abd40: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1abd40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1abd44: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1abd44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1abd48: 0xa31825  or          $v1, $a1, $v1
    ctx->pc = 0x1abd48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1abd4c: 0xfc230030  sd          $v1, 0x30($at)
    ctx->pc = 0x1abd4cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 3));
    // 0x1abd50: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1abd50u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abd54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abd54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abd58: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1abd58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1abd5c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1abd5cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1abd60: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1ABD60u;
    {
        const bool branch_taken_0x1abd60 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1abd60) {
            ctx->pc = 0x1ABD78u;
            goto label_1abd78;
        }
    }
    ctx->pc = 0x1ABD68u;
    // 0x1abd68: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abd68u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1abd6c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1abd6cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1abd70: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1ABD70u;
    {
        const bool branch_taken_0x1abd70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABD74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABD70u;
            // 0x1abd74: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abd70) {
            ctx->pc = 0x1ABD94u;
            goto label_1abd94;
        }
    }
    ctx->pc = 0x1ABD78u;
label_1abd78:
    // 0x1abd78: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1abd78u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1abd7c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1abd7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1abd80: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abd80u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1abd84: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1abd84u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1abd88: 0x0  nop
    ctx->pc = 0x1abd88u;
    // NOP
    // 0x1abd8c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1abd8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1abd90: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1abd90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1abd94:
    // 0x1abd94: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1abd94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1abd98: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1abd98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1abd9c: 0x11183c  dsll32      $v1, $s1, 0
    ctx->pc = 0x1abd9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 0));
    // 0x1abda0: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x1abda0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1abda4: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1abda4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1abda8: 0x10103c  dsll32      $v0, $s0, 0
    ctx->pc = 0x1abda8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 0));
    // 0x1abdac: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1abdacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1abdb0: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1abdb0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1abdb4: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1abdb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1abdb8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1abdb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1abdbc: 0xa21025  or          $v0, $a1, $v0
    ctx->pc = 0x1abdbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1abdc0: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1ABDC0u;
    SET_GPR_U32(ctx, 31, 0x1ABDC8u);
    ctx->pc = 0x1ABDC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABDC0u;
            // 0x1abdc4: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABDC8u; }
        if (ctx->pc != 0x1ABDC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABDC8u; }
        if (ctx->pc != 0x1ABDC8u) { return; }
    }
    ctx->pc = 0x1ABDC8u;
label_1abdc8:
    // 0x1abdc8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1abdc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1abdcc:
    // 0x1abdcc: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1abdccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1abdd0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1abdd0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1abdd4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1abdd4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1abdd8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1abdd8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1abddc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1abddcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1abde0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1abde0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1abde4: 0x3e00008  jr          $ra
    ctx->pc = 0x1ABDE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ABDE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABDE4u;
            // 0x1abde8: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ABB94u: goto label_1abb94;
            case 0x1ABBB4u: goto label_1abbb4;
            case 0x1ABBD8u: goto label_1abbd8;
            case 0x1ABC60u: goto label_1abc60;
            case 0x1ABC84u: goto label_1abc84;
            case 0x1ABC90u: goto label_1abc90;
            case 0x1ABD04u: goto label_1abd04;
            case 0x1ABD20u: goto label_1abd20;
            case 0x1ABD78u: goto label_1abd78;
            case 0x1ABD94u: goto label_1abd94;
            case 0x1ABDC8u: goto label_1abdc8;
            case 0x1ABDCCu: goto label_1abdcc;
            case 0x1ABE28u: goto label_1abe28;
            case 0x1ABE3Cu: goto label_1abe3c;
            case 0x1ABE5Cu: goto label_1abe5c;
            case 0x1ABE80u: goto label_1abe80;
            case 0x1ABF08u: goto label_1abf08;
            case 0x1ABF24u: goto label_1abf24;
            case 0x1ABFACu: goto label_1abfac;
            case 0x1ABFC8u: goto label_1abfc8;
            case 0x1ABFECu: goto label_1abfec;
            case 0x1AC068u: goto label_1ac068;
            case 0x1AC084u: goto label_1ac084;
            case 0x1AC0A8u: goto label_1ac0a8;
            case 0x1AC128u: goto label_1ac128;
            case 0x1AC144u: goto label_1ac144;
            case 0x1AC168u: goto label_1ac168;
            case 0x1AC1DCu: goto label_1ac1dc;
            case 0x1AC1F8u: goto label_1ac1f8;
            case 0x1AC218u: goto label_1ac218;
            case 0x1AC21Cu: goto label_1ac21c;
            case 0x1AC27Cu: goto label_1ac27c;
            case 0x1AC29Cu: goto label_1ac29c;
            case 0x1AC2C0u: goto label_1ac2c0;
            case 0x1AC36Cu: goto label_1ac36c;
            case 0x1AC398u: goto label_1ac398;
            case 0x1AC3A4u: goto label_1ac3a4;
            case 0x1AC450u: goto label_1ac450;
            case 0x1AC46Cu: goto label_1ac46c;
            case 0x1AC4FCu: goto label_1ac4fc;
            case 0x1AC518u: goto label_1ac518;
            case 0x1AC5A8u: goto label_1ac5a8;
            case 0x1AC5C4u: goto label_1ac5c4;
            case 0x1AC5F8u: goto label_1ac5f8;
            case 0x1AC5FCu: goto label_1ac5fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ABDECu;
    // 0x1abdec: 0x0  nop
    ctx->pc = 0x1abdecu;
    // NOP
    // 0x1abdf0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1abdf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1abdf4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abdf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abdf8: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1abdf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1abdfc: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1abdfcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1abe00: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1abe00u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1abe04: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1abe04u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1abe08: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1abe08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1abe0c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1abe0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1abe10: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1abe10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1abe14: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x1abe14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x1abe18: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ABE18u;
    {
        const bool branch_taken_0x1abe18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABE1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABE18u;
            // 0x1abe1c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abe18) {
            ctx->pc = 0x1ABE28u;
            goto label_1abe28;
        }
    }
    ctx->pc = 0x1ABE20u;
    // 0x1abe20: 0x100000fe  b           . + 4 + (0xFE << 2)
    ctx->pc = 0x1ABE20u;
    {
        const bool branch_taken_0x1abe20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABE24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABE20u;
            // 0x1abe24: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abe20) {
            ctx->pc = 0x1AC21Cu;
            goto label_1ac21c;
        }
    }
    ctx->pc = 0x1ABE28u;
label_1abe28:
    // 0x1abe28: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1abe28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1abe2c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x1abe2cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x1abe30: 0x24843f90  addiu       $a0, $a0, 0x3F90
    ctx->pc = 0x1abe30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16272));
    // 0x1abe34: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x1ABE34u;
    SET_GPR_U32(ctx, 31, 0x1ABE3Cu);
    ctx->pc = 0x1ABE38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABE34u;
            // 0x1abe38: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABE3Cu; }
        if (ctx->pc != 0x1ABE3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABE3Cu; }
        if (ctx->pc != 0x1ABE3Cu) { return; }
    }
    ctx->pc = 0x1ABE3Cu;
label_1abe3c:
    // 0x1abe3c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abe3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abe40: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x1abe40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1abe44: 0x8c24f9bc  lw          $a0, -0x644($at)
    ctx->pc = 0x1abe44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965692)));
    // 0x1abe48: 0x441823  subu        $v1, $v0, $a0
    ctx->pc = 0x1abe48u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1abe4c: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ABE4Cu;
    {
        const bool branch_taken_0x1abe4c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1ABE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABE4Cu;
            // 0x1abe50: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abe4c) {
            ctx->pc = 0x1ABE5Cu;
            goto label_1abe5c;
        }
    }
    ctx->pc = 0x1ABE54u;
    // 0x1abe54: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1abe54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1abe58: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1abe58u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1abe5c:
    // 0x1abe5c: 0x24900  sll         $t1, $v0, 4
    ctx->pc = 0x1abe5cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1abe60: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abe60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abe64: 0x8c22f9c0  lw          $v0, -0x640($at)
    ctx->pc = 0x1abe64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1abe68: 0x24031000  addiu       $v1, $zero, 0x1000
    ctx->pc = 0x1abe68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1abe6c: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1abe6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1abe70: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ABE70u;
    {
        const bool branch_taken_0x1abe70 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1ABE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABE70u;
            // 0x1abe74: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abe70) {
            ctx->pc = 0x1ABE80u;
            goto label_1abe80;
        }
    }
    ctx->pc = 0x1ABE78u;
    // 0x1abe78: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1abe78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1abe7c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1abe7cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1abe80:
    // 0x1abe80: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1abe80u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1abe84: 0x24100  sll         $t0, $v0, 4
    ctx->pc = 0x1abe84u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1abe88: 0x3c024420  lui         $v0, 0x4420
    ctx->pc = 0x1abe88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17440 << 16));
    // 0x1abe8c: 0x86050002  lh          $a1, 0x2($s0)
    ctx->pc = 0x1abe8cu;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1abe90: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1abe90u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1abe94: 0x86030006  lh          $v1, 0x6($s0)
    ctx->pc = 0x1abe94u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1abe98: 0x86070000  lh          $a3, 0x0($s0)
    ctx->pc = 0x1abe98u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1abe9c: 0x3c064180  lui         $a2, 0x4180
    ctx->pc = 0x1abe9cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)16768 << 16));
    // 0x1abea0: 0x86040004  lh          $a0, 0x4($s0)
    ctx->pc = 0x1abea0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1abea4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abea4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abea8: 0x58900  sll         $s1, $a1, 4
    ctx->pc = 0x1abea8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1abeac: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1abeacu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abeb0: 0x0  nop
    ctx->pc = 0x1abeb0u;
    // NOP
    // 0x1abeb4: 0x46000883  div.s       $f2, $f1, $f0
    ctx->pc = 0x1abeb4u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[1] / ctx->f[0];
    // 0x1abeb8: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x1abeb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x1abebc: 0x44870000  mtc1        $a3, $f0
    ctx->pc = 0x1abebcu;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abec0: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1abec0u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1abec4: 0x0  nop
    ctx->pc = 0x1abec4u;
    // NOP
    // 0x1abec8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1abec8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1abecc: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x1abeccu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1abed0: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1abed0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1abed4: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abed4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1abed8: 0x44120000  mfc1        $s2, $f0
    ctx->pc = 0x1abed8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 18, bits); }
    // 0x1abedc: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1abedcu;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abee0: 0x0  nop
    ctx->pc = 0x1abee0u;
    // NOP
    // 0x1abee4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1abee4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1abee8: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x1abee8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1abeec: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1abeecu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1abef0: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abef0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1abef4: 0x44150000  mfc1        $s5, $f0
    ctx->pc = 0x1abef4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 21, bits); }
    // 0x1abef8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ABEF8u;
    {
        const bool branch_taken_0x1abef8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1ABEFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABEF8u;
            // 0x1abefc: 0x3a100  sll         $s4, $v1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abef8) {
            ctx->pc = 0x1ABF08u;
            goto label_1abf08;
        }
    }
    ctx->pc = 0x1ABF00u;
    // 0x1abf00: 0x118843  sra         $s1, $s1, 1
    ctx->pc = 0x1abf00u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
    // 0x1abf04: 0x14a043  sra         $s4, $s4, 1
    ctx->pc = 0x1abf04u;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 20), 1));
label_1abf08:
    // 0x1abf08: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x1abf08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1abf0c: 0x2499021  addu        $s2, $s2, $t1
    ctx->pc = 0x1abf0cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 9)));
    // 0x1abf10: 0x2a9a821  addu        $s5, $s5, $t1
    ctx->pc = 0x1abf10u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 9)));
    // 0x1abf14: 0x2288821  addu        $s1, $s1, $t0
    ctx->pc = 0x1abf14u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 8)));
    // 0x1abf18: 0x288a021  addu        $s4, $s4, $t0
    ctx->pc = 0x1abf18u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 8)));
    // 0x1abf1c: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1ABF1Cu;
    SET_GPR_U32(ctx, 31, 0x1ABF24u);
    ctx->pc = 0x1ABF20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABF1Cu;
            // 0x1abf20: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABF24u; }
        if (ctx->pc != 0x1ABF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABF24u; }
        if (ctx->pc != 0x1ABF24u) { return; }
    }
    ctx->pc = 0x1ABF24u;
label_1abf24:
    // 0x1abf24: 0x11183c  dsll32      $v1, $s1, 0
    ctx->pc = 0x1abf24u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 0));
    // 0x1abf28: 0x12983c  dsll32      $s3, $s2, 0
    ctx->pc = 0x1abf28u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 18) << (32 + 0));
    // 0x1abf2c: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1abf2cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1abf30: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1abf30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1abf34: 0x39438  dsll        $s2, $v1, 16
    ctx->pc = 0x1abf34u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 3) << 16);
    // 0x1abf38: 0x21c02  srl         $v1, $v0, 16
    ctx->pc = 0x1abf38u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1abf3c: 0x306500ff  andi        $a1, $v1, 0xFF
    ctx->pc = 0x1abf3cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1abf40: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1abf40u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1abf44: 0x306400ff  andi        $a0, $v1, 0xFF
    ctx->pc = 0x1abf44u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1abf48: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1abf48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1abf4c: 0x42238  dsll        $a0, $a0, 8
    ctx->pc = 0x1abf4cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 8);
    // 0x1abf50: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1abf50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1abf54: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1abf54u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1abf58: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1abf58u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1abf5c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1abf5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1abf60: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1abf60u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1abf64: 0x21e38  dsll        $v1, $v0, 24
    ctx->pc = 0x1abf64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 24);
    // 0x1abf68: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1abf68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1abf6c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1abf6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1abf70: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1abf70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1abf74: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1abf74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1abf78: 0xfc230028  sd          $v1, 0x28($at)
    ctx->pc = 0x1abf78u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 3));
    // 0x1abf7c: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1abf7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1abf80: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abf80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abf84: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1abf84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1abf88: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1abf88u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abf8c: 0x0  nop
    ctx->pc = 0x1abf8cu;
    // NOP
    // 0x1abf90: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1abf90u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1abf94: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1ABF94u;
    {
        const bool branch_taken_0x1abf94 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1ABF98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABF94u;
            // 0x1abf98: 0x13983f  dsra32      $s3, $s3, 0 (Delay Slot)
        SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abf94) {
            ctx->pc = 0x1ABFACu;
            goto label_1abfac;
        }
    }
    ctx->pc = 0x1ABF9Cu;
    // 0x1abf9c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abf9cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1abfa0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1abfa0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1abfa4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1ABFA4u;
    {
        const bool branch_taken_0x1abfa4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABFA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABFA4u;
            // 0x1abfa8: 0x3183c  dsll32      $v1, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abfa4) {
            ctx->pc = 0x1ABFC8u;
            goto label_1abfc8;
        }
    }
    ctx->pc = 0x1ABFACu;
label_1abfac:
    // 0x1abfac: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1abfacu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1abfb0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1abfb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1abfb4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abfb4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1abfb8: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1abfb8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1abfbc: 0x0  nop
    ctx->pc = 0x1abfbcu;
    // NOP
    // 0x1abfc0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1abfc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1abfc4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1abfc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
label_1abfc8:
    // 0x1abfc8: 0x2721025  or          $v0, $s3, $s2
    ctx->pc = 0x1abfc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) | GPR_U64(ctx, 18));
    // 0x1abfcc: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1abfccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1abfd0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1abfd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1abfd4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1abfd4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1abfd8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1abfd8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1abfdc: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1abfdcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1abfe0: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x1abfe0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1abfe4: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1ABFE4u;
    SET_GPR_U32(ctx, 31, 0x1ABFECu);
    ctx->pc = 0x1ABFE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABFE4u;
            // 0x1abfe8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABFECu; }
        if (ctx->pc != 0x1ABFECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABFECu; }
        if (ctx->pc != 0x1ABFECu) { return; }
    }
    ctx->pc = 0x1ABFECu;
label_1abfec:
    // 0x1abfec: 0x21c02  srl         $v1, $v0, 16
    ctx->pc = 0x1abfecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1abff0: 0x15883c  dsll32      $s1, $s5, 0
    ctx->pc = 0x1abff0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 21) << (32 + 0));
    // 0x1abff4: 0x306500ff  andi        $a1, $v1, 0xFF
    ctx->pc = 0x1abff4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1abff8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1abff8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1abffc: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1abffcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ac000: 0x306400ff  andi        $a0, $v1, 0xFF
    ctx->pc = 0x1ac000u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1ac004: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ac004u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ac008: 0x42238  dsll        $a0, $a0, 8
    ctx->pc = 0x1ac008u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 8);
    // 0x1ac00c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ac00cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ac010: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1ac010u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1ac014: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1ac014u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1ac018: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ac018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ac01c: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1ac01cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1ac020: 0x21e38  dsll        $v1, $v0, 24
    ctx->pc = 0x1ac020u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 24);
    // 0x1ac024: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac028: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1ac028u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1ac02c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1ac02cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac030: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ac030u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac034: 0xfc230038  sd          $v1, 0x38($at)
    ctx->pc = 0x1ac034u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 3));
    // 0x1ac038: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1ac038u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1ac03c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac03cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac040: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1ac040u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ac044: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ac044u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac048: 0x0  nop
    ctx->pc = 0x1ac048u;
    // NOP
    // 0x1ac04c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1ac04cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ac050: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1AC050u;
    {
        const bool branch_taken_0x1ac050 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1AC054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC050u;
            // 0x1ac054: 0x11883f  dsra32      $s1, $s1, 0 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac050) {
            ctx->pc = 0x1AC068u;
            goto label_1ac068;
        }
    }
    ctx->pc = 0x1AC058u;
    // 0x1ac058: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac058u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac05c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac05cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac060: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AC060u;
    {
        const bool branch_taken_0x1ac060 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC060u;
            // 0x1ac064: 0x3183c  dsll32      $v1, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac060) {
            ctx->pc = 0x1AC084u;
            goto label_1ac084;
        }
    }
    ctx->pc = 0x1AC068u;
label_1ac068:
    // 0x1ac068: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1ac068u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1ac06c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ac06cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ac070: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac070u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac074: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac074u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac078: 0x0  nop
    ctx->pc = 0x1ac078u;
    // NOP
    // 0x1ac07c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ac07cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac080: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac080u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
label_1ac084:
    // 0x1ac084: 0x2321025  or          $v0, $s1, $s2
    ctx->pc = 0x1ac084u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | GPR_U64(ctx, 18));
    // 0x1ac088: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1ac088u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1ac08c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac08cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac090: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac090u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1ac094: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ac094u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac098: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x1ac098u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x1ac09c: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1ac09cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1ac0a0: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1AC0A0u;
    SET_GPR_U32(ctx, 31, 0x1AC0A8u);
    ctx->pc = 0x1AC0A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC0A0u;
            // 0x1ac0a4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC0A8u; }
        if (ctx->pc != 0x1AC0A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC0A8u; }
        if (ctx->pc != 0x1AC0A8u) { return; }
    }
    ctx->pc = 0x1AC0A8u;
label_1ac0a8:
    // 0x1ac0a8: 0x14183c  dsll32      $v1, $s4, 0
    ctx->pc = 0x1ac0a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) << (32 + 0));
    // 0x1ac0ac: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1ac0acu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1ac0b0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1ac0b0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1ac0b4: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1ac0b4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1ac0b8: 0x39438  dsll        $s2, $v1, 16
    ctx->pc = 0x1ac0b8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 3) << 16);
    // 0x1ac0bc: 0x22202  srl         $a0, $v0, 8
    ctx->pc = 0x1ac0bcu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ac0c0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ac0c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ac0c4: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x1ac0c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1ac0c8: 0x42238  dsll        $a0, $a0, 8
    ctx->pc = 0x1ac0c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 8);
    // 0x1ac0cc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ac0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ac0d0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ac0d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ac0d4: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1ac0d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1ac0d8: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1ac0d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1ac0dc: 0x21638  dsll        $v0, $v0, 24
    ctx->pc = 0x1ac0dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 24);
    // 0x1ac0e0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1ac0e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1ac0e4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac0e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac0e8: 0x432025  or          $a0, $v0, $v1
    ctx->pc = 0x1ac0e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ac0ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac0ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac0f0: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1ac0f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac0f4: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1ac0f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1ac0f8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1ac0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1ac0fc: 0xfc230048  sd          $v1, 0x48($at)
    ctx->pc = 0x1ac0fcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 3));
    // 0x1ac100: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ac100u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac104: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac104u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac108: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1ac108u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ac10c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1ac10cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ac110: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1AC110u;
    {
        const bool branch_taken_0x1ac110 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1ac110) {
            ctx->pc = 0x1AC128u;
            goto label_1ac128;
        }
    }
    ctx->pc = 0x1AC118u;
    // 0x1ac118: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac118u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac11c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac11cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac120: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AC120u;
    {
        const bool branch_taken_0x1ac120 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC120u;
            // 0x1ac124: 0x3183c  dsll32      $v1, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac120) {
            ctx->pc = 0x1AC144u;
            goto label_1ac144;
        }
    }
    ctx->pc = 0x1AC128u;
label_1ac128:
    // 0x1ac128: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1ac128u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1ac12c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ac12cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ac130: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac130u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac134: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac134u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac138: 0x0  nop
    ctx->pc = 0x1ac138u;
    // NOP
    // 0x1ac13c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ac13cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac140: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac140u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
label_1ac144:
    // 0x1ac144: 0x2721025  or          $v0, $s3, $s2
    ctx->pc = 0x1ac144u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) | GPR_U64(ctx, 18));
    // 0x1ac148: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1ac148u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1ac14c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac14cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac150: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac150u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1ac154: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ac154u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac158: 0xfc220050  sd          $v0, 0x50($at)
    ctx->pc = 0x1ac158u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 80), GPR_U64(ctx, 2));
    // 0x1ac15c: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x1ac15cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1ac160: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1AC160u;
    SET_GPR_U32(ctx, 31, 0x1AC168u);
    ctx->pc = 0x1AC164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC160u;
            // 0x1ac164: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC168u; }
        if (ctx->pc != 0x1AC168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC168u; }
        if (ctx->pc != 0x1AC168u) { return; }
    }
    ctx->pc = 0x1AC168u;
label_1ac168:
    // 0x1ac168: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1ac168u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1ac16c: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1ac16cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ac170: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1ac170u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1ac174: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1ac174u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1ac178: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x1ac178u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x1ac17c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac17cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac180: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ac180u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ac184: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1ac184u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1ac188: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1ac188u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1ac18c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ac18cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ac190: 0x642825  or          $a1, $v1, $a0
    ctx->pc = 0x1ac190u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1ac194: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ac194u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ac198: 0x32638  dsll        $a0, $v1, 24
    ctx->pc = 0x1ac198u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 24);
    // 0x1ac19c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac19cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac1a0: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1ac1a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac1a4: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1ac1a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1ac1a8: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1ac1a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1ac1ac: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1ac1acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1ac1b0: 0xfc230058  sd          $v1, 0x58($at)
    ctx->pc = 0x1ac1b0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 88), GPR_U64(ctx, 3));
    // 0x1ac1b4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ac1b4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac1b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac1b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac1bc: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1ac1bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ac1c0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1ac1c0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ac1c4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1AC1C4u;
    {
        const bool branch_taken_0x1ac1c4 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1ac1c4) {
            ctx->pc = 0x1AC1DCu;
            goto label_1ac1dc;
        }
    }
    ctx->pc = 0x1AC1CCu;
    // 0x1ac1cc: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac1ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac1d0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac1d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac1d4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AC1D4u;
    {
        const bool branch_taken_0x1ac1d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC1D4u;
            // 0x1ac1d8: 0x3183c  dsll32      $v1, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac1d4) {
            ctx->pc = 0x1AC1F8u;
            goto label_1ac1f8;
        }
    }
    ctx->pc = 0x1AC1DCu;
label_1ac1dc:
    // 0x1ac1dc: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1ac1dcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1ac1e0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ac1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ac1e4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac1e4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac1e8: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac1e8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac1ec: 0x0  nop
    ctx->pc = 0x1ac1ecu;
    // NOP
    // 0x1ac1f0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ac1f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac1f4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac1f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
label_1ac1f8:
    // 0x1ac1f8: 0x2321025  or          $v0, $s1, $s2
    ctx->pc = 0x1ac1f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | GPR_U64(ctx, 18));
    // 0x1ac1fc: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1ac1fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1ac200: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac200u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac204: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac204u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1ac208: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1ac208u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac20c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ac20cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac210: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1AC210u;
    SET_GPR_U32(ctx, 31, 0x1AC218u);
    ctx->pc = 0x1AC214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC210u;
            // 0x1ac214: 0xfc220060  sd          $v0, 0x60($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 96), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC218u; }
        if (ctx->pc != 0x1AC218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC218u; }
        if (ctx->pc != 0x1AC218u) { return; }
    }
    ctx->pc = 0x1AC218u;
label_1ac218:
    // 0x1ac218: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac218u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1ac21c:
    // 0x1ac21c: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1ac21cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ac220: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ac220u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ac224: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ac224u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ac228: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ac228u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ac22c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ac22cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ac230: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ac230u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ac234: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ac234u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ac238: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC238u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AC23Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC238u;
            // 0x1ac23c: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ABB94u: goto label_1abb94;
            case 0x1ABBB4u: goto label_1abbb4;
            case 0x1ABBD8u: goto label_1abbd8;
            case 0x1ABC60u: goto label_1abc60;
            case 0x1ABC84u: goto label_1abc84;
            case 0x1ABC90u: goto label_1abc90;
            case 0x1ABD04u: goto label_1abd04;
            case 0x1ABD20u: goto label_1abd20;
            case 0x1ABD78u: goto label_1abd78;
            case 0x1ABD94u: goto label_1abd94;
            case 0x1ABDC8u: goto label_1abdc8;
            case 0x1ABDCCu: goto label_1abdcc;
            case 0x1ABE28u: goto label_1abe28;
            case 0x1ABE3Cu: goto label_1abe3c;
            case 0x1ABE5Cu: goto label_1abe5c;
            case 0x1ABE80u: goto label_1abe80;
            case 0x1ABF08u: goto label_1abf08;
            case 0x1ABF24u: goto label_1abf24;
            case 0x1ABFACu: goto label_1abfac;
            case 0x1ABFC8u: goto label_1abfc8;
            case 0x1ABFECu: goto label_1abfec;
            case 0x1AC068u: goto label_1ac068;
            case 0x1AC084u: goto label_1ac084;
            case 0x1AC0A8u: goto label_1ac0a8;
            case 0x1AC128u: goto label_1ac128;
            case 0x1AC144u: goto label_1ac144;
            case 0x1AC168u: goto label_1ac168;
            case 0x1AC1DCu: goto label_1ac1dc;
            case 0x1AC1F8u: goto label_1ac1f8;
            case 0x1AC218u: goto label_1ac218;
            case 0x1AC21Cu: goto label_1ac21c;
            case 0x1AC27Cu: goto label_1ac27c;
            case 0x1AC29Cu: goto label_1ac29c;
            case 0x1AC2C0u: goto label_1ac2c0;
            case 0x1AC36Cu: goto label_1ac36c;
            case 0x1AC398u: goto label_1ac398;
            case 0x1AC3A4u: goto label_1ac3a4;
            case 0x1AC450u: goto label_1ac450;
            case 0x1AC46Cu: goto label_1ac46c;
            case 0x1AC4FCu: goto label_1ac4fc;
            case 0x1AC518u: goto label_1ac518;
            case 0x1AC5A8u: goto label_1ac5a8;
            case 0x1AC5C4u: goto label_1ac5c4;
            case 0x1AC5F8u: goto label_1ac5f8;
            case 0x1AC5FCu: goto label_1ac5fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC240u;
    // 0x1ac240: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1ac240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1ac244: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac244u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac248: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1ac248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1ac24c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1ac24cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1ac250: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ac250u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ac254: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ac254u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ac258: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ac258u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ac25c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ac25cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ac260: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ac260u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ac264: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ac264u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ac268: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x1ac268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x1ac26c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AC26Cu;
    {
        const bool branch_taken_0x1ac26c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC26Cu;
            // 0x1ac270: 0x80b02d  daddu       $s6, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac26c) {
            ctx->pc = 0x1AC27Cu;
            goto label_1ac27c;
        }
    }
    ctx->pc = 0x1AC274u;
    // 0x1ac274: 0x100000e1  b           . + 4 + (0xE1 << 2)
    ctx->pc = 0x1AC274u;
    {
        const bool branch_taken_0x1ac274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC274u;
            // 0x1ac278: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac274) {
            ctx->pc = 0x1AC5FCu;
            goto label_1ac5fc;
        }
    }
    ctx->pc = 0x1AC27Cu;
label_1ac27c:
    // 0x1ac27c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac27cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac280: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x1ac280u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1ac284: 0x8c24f9bc  lw          $a0, -0x644($at)
    ctx->pc = 0x1ac284u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965692)));
    // 0x1ac288: 0x441823  subu        $v1, $v0, $a0
    ctx->pc = 0x1ac288u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ac28c: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AC28Cu;
    {
        const bool branch_taken_0x1ac28c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1AC290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC28Cu;
            // 0x1ac290: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac28c) {
            ctx->pc = 0x1AC29Cu;
            goto label_1ac29c;
        }
    }
    ctx->pc = 0x1AC294u;
    // 0x1ac294: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1ac294u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ac298: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1ac298u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1ac29c:
    // 0x1ac29c: 0x25900  sll         $t3, $v0, 4
    ctx->pc = 0x1ac29cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ac2a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac2a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac2a4: 0x8c22f9c0  lw          $v0, -0x640($at)
    ctx->pc = 0x1ac2a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1ac2a8: 0x24031000  addiu       $v1, $zero, 0x1000
    ctx->pc = 0x1ac2a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1ac2ac: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1ac2acu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ac2b0: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AC2B0u;
    {
        const bool branch_taken_0x1ac2b0 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1AC2B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC2B0u;
            // 0x1ac2b4: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac2b0) {
            ctx->pc = 0x1AC2C0u;
            goto label_1ac2c0;
        }
    }
    ctx->pc = 0x1AC2B8u;
    // 0x1ac2b8: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1ac2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ac2bc: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1ac2bcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1ac2c0:
    // 0x1ac2c0: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1ac2c0u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1ac2c4: 0x25100  sll         $t2, $v0, 4
    ctx->pc = 0x1ac2c4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ac2c8: 0x3c024420  lui         $v0, 0x4420
    ctx->pc = 0x1ac2c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17440 << 16));
    // 0x1ac2cc: 0x3c084180  lui         $t0, 0x4180
    ctx->pc = 0x1ac2ccu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)16768 << 16));
    // 0x1ac2d0: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1ac2d0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1ac2d4: 0x86c70002  lh          $a3, 0x2($s6)
    ctx->pc = 0x1ac2d4u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 2)));
    // 0x1ac2d8: 0x86c50006  lh          $a1, 0x6($s6)
    ctx->pc = 0x1ac2d8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 6)));
    // 0x1ac2dc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac2dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac2e0: 0x86c3000a  lh          $v1, 0xA($s6)
    ctx->pc = 0x1ac2e0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 10)));
    // 0x1ac2e4: 0x86c90000  lh          $t1, 0x0($s6)
    ctx->pc = 0x1ac2e4u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1ac2e8: 0x86c60004  lh          $a2, 0x4($s6)
    ctx->pc = 0x1ac2e8u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 4)));
    // 0x1ac2ec: 0x86c40008  lh          $a0, 0x8($s6)
    ctx->pc = 0x1ac2ecu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x1ac2f0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ac2f0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac2f4: 0x7a100  sll         $s4, $a3, 4
    ctx->pc = 0x1ac2f4u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x1ac2f8: 0x44881000  mtc1        $t0, $f2
    ctx->pc = 0x1ac2f8u;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1ac2fc: 0x59100  sll         $s2, $a1, 4
    ctx->pc = 0x1ac2fcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1ac300: 0x460008c3  div.s       $f3, $f1, $f0
    ctx->pc = 0x1ac300u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[3] = std::bit_cast<float>(__maxf); } else ctx->f[3] = ctx->f[1] / ctx->f[0];
    // 0x1ac304: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x1ac304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x1ac308: 0x44890000  mtc1        $t1, $f0
    ctx->pc = 0x1ac308u;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac30c: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1ac30cu;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1ac310: 0x0  nop
    ctx->pc = 0x1ac310u;
    // NOP
    // 0x1ac314: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1ac314u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1ac318: 0x46030002  mul.s       $f0, $f0, $f3
    ctx->pc = 0x1ac318u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[3]);
    // 0x1ac31c: 0x46001002  mul.s       $f0, $f2, $f0
    ctx->pc = 0x1ac31cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
    // 0x1ac320: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac320u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1ac324: 0x44150000  mfc1        $s5, $f0
    ctx->pc = 0x1ac324u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 21, bits); }
    // 0x1ac328: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1ac328u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1ac32c: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1ac32cu;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac330: 0x0  nop
    ctx->pc = 0x1ac330u;
    // NOP
    // 0x1ac334: 0x46030842  mul.s       $f1, $f1, $f3
    ctx->pc = 0x1ac334u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[3]);
    // 0x1ac338: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1ac338u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1ac33c: 0x46030002  mul.s       $f0, $f0, $f3
    ctx->pc = 0x1ac33cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[3]);
    // 0x1ac340: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x1ac340u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x1ac344: 0x46001002  mul.s       $f0, $f2, $f0
    ctx->pc = 0x1ac344u;
    ctx->f[0] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
    // 0x1ac348: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac348u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac34c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac34cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1ac350: 0x44130800  mfc1        $s3, $f1
    ctx->pc = 0x1ac350u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 19, bits); }
    // 0x1ac354: 0x44110000  mfc1        $s1, $f0
    ctx->pc = 0x1ac354u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 17, bits); }
    // 0x1ac358: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AC358u;
    {
        const bool branch_taken_0x1ac358 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AC35Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC358u;
            // 0x1ac35c: 0x38100  sll         $s0, $v1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac358) {
            ctx->pc = 0x1AC36Cu;
            goto label_1ac36c;
        }
    }
    ctx->pc = 0x1AC360u;
    // 0x1ac360: 0x14a043  sra         $s4, $s4, 1
    ctx->pc = 0x1ac360u;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 20), 1));
    // 0x1ac364: 0x129043  sra         $s2, $s2, 1
    ctx->pc = 0x1ac364u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 18), 1));
    // 0x1ac368: 0x108043  sra         $s0, $s0, 1
    ctx->pc = 0x1ac368u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
label_1ac36c:
    // 0x1ac36c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1ac36cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1ac370: 0x2aba821  addu        $s5, $s5, $t3
    ctx->pc = 0x1ac370u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 11)));
    // 0x1ac374: 0x28aa021  addu        $s4, $s4, $t2
    ctx->pc = 0x1ac374u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 10)));
    // 0x1ac378: 0x26b9821  addu        $s3, $s3, $t3
    ctx->pc = 0x1ac378u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 11)));
    // 0x1ac37c: 0x22b8821  addu        $s1, $s1, $t3
    ctx->pc = 0x1ac37cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 11)));
    // 0x1ac380: 0x24a9021  addu        $s2, $s2, $t2
    ctx->pc = 0x1ac380u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 10)));
    // 0x1ac384: 0x20a8021  addu        $s0, $s0, $t2
    ctx->pc = 0x1ac384u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 10)));
    // 0x1ac388: 0x24844000  addiu       $a0, $a0, 0x4000
    ctx->pc = 0x1ac388u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16384));
    // 0x1ac38c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x1ac38cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac390: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x1AC390u;
    SET_GPR_U32(ctx, 31, 0x1AC398u);
    ctx->pc = 0x1AC394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC390u;
            // 0x1ac394: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC398u; }
        if (ctx->pc != 0x1AC398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC398u; }
        if (ctx->pc != 0x1AC398u) { return; }
    }
    ctx->pc = 0x1AC398u;
label_1ac398:
    // 0x1ac398: 0x8ec4000c  lw          $a0, 0xC($s6)
    ctx->pc = 0x1ac398u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x1ac39c: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1AC39Cu;
    SET_GPR_U32(ctx, 31, 0x1AC3A4u);
    ctx->pc = 0x1AC3A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC39Cu;
            // 0x1ac3a0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC3A4u; }
        if (ctx->pc != 0x1AC3A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC3A4u; }
        if (ctx->pc != 0x1AC3A4u) { return; }
    }
    ctx->pc = 0x1AC3A4u;
label_1ac3a4:
    // 0x1ac3a4: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1ac3a4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1ac3a8: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1ac3a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ac3ac: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1ac3acu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1ac3b0: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1ac3b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1ac3b4: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x1ac3b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x1ac3b8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac3b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac3bc: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ac3bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ac3c0: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1ac3c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1ac3c4: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1ac3c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1ac3c8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ac3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ac3cc: 0x642825  or          $a1, $v1, $a0
    ctx->pc = 0x1ac3ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1ac3d0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ac3d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ac3d4: 0x32638  dsll        $a0, $v1, 24
    ctx->pc = 0x1ac3d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 24);
    // 0x1ac3d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac3d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac3dc: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1ac3dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac3e0: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1ac3e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1ac3e4: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1ac3e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1ac3e8: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1ac3e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1ac3ec: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ac3ecu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac3f0: 0xfc230028  sd          $v1, 0x28($at)
    ctx->pc = 0x1ac3f0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 3));
    // 0x1ac3f4: 0x86c30010  lh          $v1, 0x10($s6)
    ctx->pc = 0x1ac3f4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 16)));
    // 0x1ac3f8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac3f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac3fc: 0x86c20012  lh          $v0, 0x12($s6)
    ctx->pc = 0x1ac3fcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 18)));
    // 0x1ac400: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1ac400u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1ac404: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1ac404u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ac408: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1ac408u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1ac40c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1ac40cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1ac410: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac410u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1ac414: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1ac414u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac418: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1ac418u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1ac41c: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1ac41cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1ac420: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1ac420u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1ac424: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ac424u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac428: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1ac428u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1ac42c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac42cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac430: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1ac430u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ac434: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1ac434u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ac438: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1AC438u;
    {
        const bool branch_taken_0x1ac438 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1ac438) {
            ctx->pc = 0x1AC450u;
            goto label_1ac450;
        }
    }
    ctx->pc = 0x1AC440u;
    // 0x1ac440: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac440u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac444: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac444u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac448: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AC448u;
    {
        const bool branch_taken_0x1ac448 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC44Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC448u;
            // 0x1ac44c: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac448) {
            ctx->pc = 0x1AC46Cu;
            goto label_1ac46c;
        }
    }
    ctx->pc = 0x1AC450u;
label_1ac450:
    // 0x1ac450: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1ac450u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1ac454: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ac454u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ac458: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac458u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac45c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac45cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac460: 0x0  nop
    ctx->pc = 0x1ac460u;
    // NOP
    // 0x1ac464: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ac464u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac468: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1ac468u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1ac46c:
    // 0x1ac46c: 0x15203c  dsll32      $a0, $s5, 0
    ctx->pc = 0x1ac46cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 21) << (32 + 0));
    // 0x1ac470: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1ac470u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1ac474: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1ac474u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1ac478: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x1ac478u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac47c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac47cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac480: 0x14103c  dsll32      $v0, $s4, 0
    ctx->pc = 0x1ac480u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) << (32 + 0));
    // 0x1ac484: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1ac484u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1ac488: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x1ac488u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x1ac48c: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1ac48cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1ac490: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1ac490u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1ac494: 0xa31825  or          $v1, $a1, $v1
    ctx->pc = 0x1ac494u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1ac498: 0xfc230038  sd          $v1, 0x38($at)
    ctx->pc = 0x1ac498u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 3));
    // 0x1ac49c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ac49cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac4a0: 0x86c30014  lh          $v1, 0x14($s6)
    ctx->pc = 0x1ac4a0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 20)));
    // 0x1ac4a4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac4a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac4a8: 0x86c20016  lh          $v0, 0x16($s6)
    ctx->pc = 0x1ac4a8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 22)));
    // 0x1ac4ac: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1ac4acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1ac4b0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1ac4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ac4b4: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1ac4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1ac4b8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1ac4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1ac4bc: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac4bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1ac4c0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1ac4c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac4c4: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1ac4c4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1ac4c8: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1ac4c8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1ac4cc: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1ac4ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1ac4d0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ac4d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac4d4: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x1ac4d4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x1ac4d8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac4d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac4dc: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1ac4dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ac4e0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1ac4e0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ac4e4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1AC4E4u;
    {
        const bool branch_taken_0x1ac4e4 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1ac4e4) {
            ctx->pc = 0x1AC4FCu;
            goto label_1ac4fc;
        }
    }
    ctx->pc = 0x1AC4ECu;
    // 0x1ac4ec: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac4ecu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac4f0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac4f0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac4f4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AC4F4u;
    {
        const bool branch_taken_0x1ac4f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC4F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC4F4u;
            // 0x1ac4f8: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac4f4) {
            ctx->pc = 0x1AC518u;
            goto label_1ac518;
        }
    }
    ctx->pc = 0x1AC4FCu;
label_1ac4fc:
    // 0x1ac4fc: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1ac4fcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1ac500: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ac500u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ac504: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac504u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac508: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac508u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac50c: 0x0  nop
    ctx->pc = 0x1ac50cu;
    // NOP
    // 0x1ac510: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ac510u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac514: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1ac514u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1ac518:
    // 0x1ac518: 0x13203c  dsll32      $a0, $s3, 0
    ctx->pc = 0x1ac518u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) << (32 + 0));
    // 0x1ac51c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1ac51cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1ac520: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1ac520u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1ac524: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x1ac524u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac528: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac528u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac52c: 0x12103c  dsll32      $v0, $s2, 0
    ctx->pc = 0x1ac52cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) << (32 + 0));
    // 0x1ac530: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1ac530u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1ac534: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x1ac534u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x1ac538: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1ac538u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1ac53c: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1ac53cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1ac540: 0xa31825  or          $v1, $a1, $v1
    ctx->pc = 0x1ac540u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1ac544: 0xfc230048  sd          $v1, 0x48($at)
    ctx->pc = 0x1ac544u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 3));
    // 0x1ac548: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ac548u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac54c: 0x86c30018  lh          $v1, 0x18($s6)
    ctx->pc = 0x1ac54cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x1ac550: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac550u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac554: 0x86c2001a  lh          $v0, 0x1A($s6)
    ctx->pc = 0x1ac554u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 26)));
    // 0x1ac558: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1ac558u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1ac55c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1ac55cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ac560: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1ac560u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1ac564: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1ac564u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1ac568: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ac568u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1ac56c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1ac56cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac570: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1ac570u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1ac574: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1ac574u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1ac578: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1ac578u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1ac57c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ac57cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac580: 0xfc220050  sd          $v0, 0x50($at)
    ctx->pc = 0x1ac580u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 80), GPR_U64(ctx, 2));
    // 0x1ac584: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ac584u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ac588: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1ac588u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ac58c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1ac58cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ac590: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1AC590u;
    {
        const bool branch_taken_0x1ac590 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1ac590) {
            ctx->pc = 0x1AC5A8u;
            goto label_1ac5a8;
        }
    }
    ctx->pc = 0x1AC598u;
    // 0x1ac598: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac598u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac59c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac59cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac5a0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AC5A0u;
    {
        const bool branch_taken_0x1ac5a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC5A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC5A0u;
            // 0x1ac5a4: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac5a0) {
            ctx->pc = 0x1AC5C4u;
            goto label_1ac5c4;
        }
    }
    ctx->pc = 0x1AC5A8u;
label_1ac5a8:
    // 0x1ac5a8: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1ac5a8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1ac5ac: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1ac5acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1ac5b0: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ac5b0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1ac5b4: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1ac5b4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1ac5b8: 0x0  nop
    ctx->pc = 0x1ac5b8u;
    // NOP
    // 0x1ac5bc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ac5bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac5c0: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1ac5c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1ac5c4:
    // 0x1ac5c4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ac5c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac5c8: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1ac5c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1ac5cc: 0x11183c  dsll32      $v1, $s1, 0
    ctx->pc = 0x1ac5ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 0));
    // 0x1ac5d0: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x1ac5d0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ac5d4: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1ac5d4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1ac5d8: 0x10103c  dsll32      $v0, $s0, 0
    ctx->pc = 0x1ac5d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 0));
    // 0x1ac5dc: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1ac5dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1ac5e0: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1ac5e0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1ac5e4: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1ac5e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1ac5e8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ac5e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac5ec: 0xa21025  or          $v0, $a1, $v0
    ctx->pc = 0x1ac5ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1ac5f0: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1AC5F0u;
    SET_GPR_U32(ctx, 31, 0x1AC5F8u);
    ctx->pc = 0x1AC5F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC5F0u;
            // 0x1ac5f4: 0xfc220058  sd          $v0, 0x58($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 88), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC5F8u; }
        if (ctx->pc != 0x1AC5F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC5F8u; }
        if (ctx->pc != 0x1AC5F8u) { return; }
    }
    ctx->pc = 0x1AC5F8u;
label_1ac5f8:
    // 0x1ac5f8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac5f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1ac5fc:
    // 0x1ac5fc: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1ac5fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1ac600: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1ac600u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ac604: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ac604u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ac608: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ac608u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ac60c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ac60cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ac610: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ac610u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ac614: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ac614u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ac618: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ac618u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ac61c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC61Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AC620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC61Cu;
            // 0x1ac620: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ABB94u: goto label_1abb94;
            case 0x1ABBB4u: goto label_1abbb4;
            case 0x1ABBD8u: goto label_1abbd8;
            case 0x1ABC60u: goto label_1abc60;
            case 0x1ABC84u: goto label_1abc84;
            case 0x1ABC90u: goto label_1abc90;
            case 0x1ABD04u: goto label_1abd04;
            case 0x1ABD20u: goto label_1abd20;
            case 0x1ABD78u: goto label_1abd78;
            case 0x1ABD94u: goto label_1abd94;
            case 0x1ABDC8u: goto label_1abdc8;
            case 0x1ABDCCu: goto label_1abdcc;
            case 0x1ABE28u: goto label_1abe28;
            case 0x1ABE3Cu: goto label_1abe3c;
            case 0x1ABE5Cu: goto label_1abe5c;
            case 0x1ABE80u: goto label_1abe80;
            case 0x1ABF08u: goto label_1abf08;
            case 0x1ABF24u: goto label_1abf24;
            case 0x1ABFACu: goto label_1abfac;
            case 0x1ABFC8u: goto label_1abfc8;
            case 0x1ABFECu: goto label_1abfec;
            case 0x1AC068u: goto label_1ac068;
            case 0x1AC084u: goto label_1ac084;
            case 0x1AC0A8u: goto label_1ac0a8;
            case 0x1AC128u: goto label_1ac128;
            case 0x1AC144u: goto label_1ac144;
            case 0x1AC168u: goto label_1ac168;
            case 0x1AC1DCu: goto label_1ac1dc;
            case 0x1AC1F8u: goto label_1ac1f8;
            case 0x1AC218u: goto label_1ac218;
            case 0x1AC21Cu: goto label_1ac21c;
            case 0x1AC27Cu: goto label_1ac27c;
            case 0x1AC29Cu: goto label_1ac29c;
            case 0x1AC2C0u: goto label_1ac2c0;
            case 0x1AC36Cu: goto label_1ac36c;
            case 0x1AC398u: goto label_1ac398;
            case 0x1AC3A4u: goto label_1ac3a4;
            case 0x1AC450u: goto label_1ac450;
            case 0x1AC46Cu: goto label_1ac46c;
            case 0x1AC4FCu: goto label_1ac4fc;
            case 0x1AC518u: goto label_1ac518;
            case 0x1AC5A8u: goto label_1ac5a8;
            case 0x1AC5C4u: goto label_1ac5c4;
            case 0x1AC5F8u: goto label_1ac5f8;
            case 0x1AC5FCu: goto label_1ac5fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC624u;
    // 0x1ac624: 0x0  nop
    ctx->pc = 0x1ac624u;
    // NOP
    // 0x1ac628: 0x0  nop
    ctx->pc = 0x1ac628u;
    // NOP
    // 0x1ac62c: 0x0  nop
    ctx->pc = 0x1ac62cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
