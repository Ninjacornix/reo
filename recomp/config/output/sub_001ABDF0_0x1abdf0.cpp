#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ABDF0
// Address: 0x1abdf0 - 0x1ac240
void sub_001ABDF0_0x1abdf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ABDF0_0x1abdf0");
#endif

    switch (ctx->pc) {
        case 0x1abe3cu: goto label_1abe3c;
        case 0x1abf24u: goto label_1abf24;
        case 0x1abfecu: goto label_1abfec;
        case 0x1ac0a8u: goto label_1ac0a8;
        case 0x1ac168u: goto label_1ac168;
        case 0x1ac218u: goto label_1ac218;
        default: break;
    }

    ctx->pc = 0x1abdf0u;

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
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC240u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
