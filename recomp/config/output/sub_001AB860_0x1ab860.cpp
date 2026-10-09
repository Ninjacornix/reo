#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB860
// Address: 0x1ab860 - 0x1abb60
void sub_001AB860_0x1ab860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB860_0x1ab860");
#endif

    switch (ctx->pc) {
        case 0x1ab97cu: goto label_1ab97c;
        case 0x1ab988u: goto label_1ab988;
        case 0x1abb38u: goto label_1abb38;
        default: break;
    }

    ctx->pc = 0x1ab860u;

    // 0x1ab860: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1ab860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1ab864: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ab864u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ab868: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1ab868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1ab86c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ab86cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ab870: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ab870u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ab874: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ab874u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ab878: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ab878u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ab87c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ab87cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ab880: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x1ab880u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x1ab884: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB884u;
    {
        const bool branch_taken_0x1ab884 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB884u;
            // 0x1ab888: 0x80a02d  daddu       $s4, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab884) {
            ctx->pc = 0x1AB894u;
            goto label_1ab894;
        }
    }
    ctx->pc = 0x1AB88Cu;
    // 0x1ab88c: 0x100000ab  b           . + 4 + (0xAB << 2)
    ctx->pc = 0x1AB88Cu;
    {
        const bool branch_taken_0x1ab88c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB88Cu;
            // 0x1ab890: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab88c) {
            ctx->pc = 0x1ABB3Cu;
            goto label_1abb3c;
        }
    }
    ctx->pc = 0x1AB894u;
label_1ab894:
    // 0x1ab894: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ab894u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ab898: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x1ab898u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1ab89c: 0x8c24f9bc  lw          $a0, -0x644($at)
    ctx->pc = 0x1ab89cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965692)));
    // 0x1ab8a0: 0x441823  subu        $v1, $v0, $a0
    ctx->pc = 0x1ab8a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ab8a4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB8A4u;
    {
        const bool branch_taken_0x1ab8a4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1AB8A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB8A4u;
            // 0x1ab8a8: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab8a4) {
            ctx->pc = 0x1AB8B4u;
            goto label_1ab8b4;
        }
    }
    ctx->pc = 0x1AB8ACu;
    // 0x1ab8ac: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1ab8acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ab8b0: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1ab8b0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1ab8b4:
    // 0x1ab8b4: 0x24900  sll         $t1, $v0, 4
    ctx->pc = 0x1ab8b4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ab8b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ab8b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ab8bc: 0x8c22f9c0  lw          $v0, -0x640($at)
    ctx->pc = 0x1ab8bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1ab8c0: 0x24031000  addiu       $v1, $zero, 0x1000
    ctx->pc = 0x1ab8c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1ab8c4: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1ab8c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ab8c8: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB8C8u;
    {
        const bool branch_taken_0x1ab8c8 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1AB8CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB8C8u;
            // 0x1ab8cc: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab8c8) {
            ctx->pc = 0x1AB8D8u;
            goto label_1ab8d8;
        }
    }
    ctx->pc = 0x1AB8D0u;
    // 0x1ab8d0: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1ab8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ab8d4: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1ab8d4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1ab8d8:
    // 0x1ab8d8: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1ab8d8u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1ab8dc: 0x24100  sll         $t0, $v0, 4
    ctx->pc = 0x1ab8dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ab8e0: 0x3c024420  lui         $v0, 0x4420
    ctx->pc = 0x1ab8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17440 << 16));
    // 0x1ab8e4: 0x86850002  lh          $a1, 0x2($s4)
    ctx->pc = 0x1ab8e4u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 2)));
    // 0x1ab8e8: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1ab8e8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1ab8ec: 0x86830006  lh          $v1, 0x6($s4)
    ctx->pc = 0x1ab8ecu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 6)));
    // 0x1ab8f0: 0x86870000  lh          $a3, 0x0($s4)
    ctx->pc = 0x1ab8f0u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1ab8f4: 0x3c064180  lui         $a2, 0x4180
    ctx->pc = 0x1ab8f4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)16768 << 16));
    // 0x1ab8f8: 0x86840004  lh          $a0, 0x4($s4)
    ctx->pc = 0x1ab8f8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x1ab8fc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1ab8fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1ab900: 0x59100  sll         $s2, $a1, 4
    ctx->pc = 0x1ab900u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1ab904: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ab904u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ab908: 0x0  nop
    ctx->pc = 0x1ab908u;
    // NOP
    // 0x1ab90c: 0x46000883  div.s       $f2, $f1, $f0
    ctx->pc = 0x1ab90cu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[1] / ctx->f[0];
    // 0x1ab910: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x1ab910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x1ab914: 0x44870000  mtc1        $a3, $f0
    ctx->pc = 0x1ab914u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ab918: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1ab918u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1ab91c: 0x0  nop
    ctx->pc = 0x1ab91cu;
    // NOP
    // 0x1ab920: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1ab920u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1ab924: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x1ab924u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1ab928: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1ab928u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1ab92c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ab92cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1ab930: 0x44130000  mfc1        $s3, $f0
    ctx->pc = 0x1ab930u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 19, bits); }
    // 0x1ab934: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1ab934u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ab938: 0x0  nop
    ctx->pc = 0x1ab938u;
    // NOP
    // 0x1ab93c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1ab93cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1ab940: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x1ab940u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1ab944: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1ab944u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1ab948: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ab948u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1ab94c: 0x44110000  mfc1        $s1, $f0
    ctx->pc = 0x1ab94cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 17, bits); }
    // 0x1ab950: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB950u;
    {
        const bool branch_taken_0x1ab950 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AB954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB950u;
            // 0x1ab954: 0x38100  sll         $s0, $v1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab950) {
            ctx->pc = 0x1AB960u;
            goto label_1ab960;
        }
    }
    ctx->pc = 0x1AB958u;
    // 0x1ab958: 0x129043  sra         $s2, $s2, 1
    ctx->pc = 0x1ab958u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 18), 1));
    // 0x1ab95c: 0x108043  sra         $s0, $s0, 1
    ctx->pc = 0x1ab95cu;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
label_1ab960:
    // 0x1ab960: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1ab960u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1ab964: 0x2699821  addu        $s3, $s3, $t1
    ctx->pc = 0x1ab964u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 9)));
    // 0x1ab968: 0x2489021  addu        $s2, $s2, $t0
    ctx->pc = 0x1ab968u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
    // 0x1ab96c: 0x24843f00  addiu       $a0, $a0, 0x3F00
    ctx->pc = 0x1ab96cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16128));
    // 0x1ab970: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x1ab970u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x1ab974: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x1AB974u;
    SET_GPR_U32(ctx, 31, 0x1AB97Cu);
    ctx->pc = 0x1AB978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB974u;
            // 0x1ab978: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB97Cu; }
        if (ctx->pc != 0x1AB97Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB97Cu; }
        if (ctx->pc != 0x1AB97Cu) { return; }
    }
    ctx->pc = 0x1AB97Cu;
label_1ab97c:
    // 0x1ab97c: 0x8e840008  lw          $a0, 0x8($s4)
    ctx->pc = 0x1ab97cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x1ab980: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1AB980u;
    SET_GPR_U32(ctx, 31, 0x1AB988u);
    ctx->pc = 0x1AB984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB980u;
            // 0x1ab984: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB988u; }
        if (ctx->pc != 0x1AB988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB988u; }
        if (ctx->pc != 0x1AB988u) { return; }
    }
    ctx->pc = 0x1AB988u;
label_1ab988:
    // 0x1ab988: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1ab988u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1ab98c: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1ab98cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1ab990: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1ab990u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1ab994: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1ab994u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1ab998: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x1ab998u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x1ab99c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ab99cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ab9a0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ab9a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ab9a4: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1ab9a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1ab9a8: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1ab9a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1ab9ac: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1ab9acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1ab9b0: 0x642825  or          $a1, $v1, $a0
    ctx->pc = 0x1ab9b0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1ab9b4: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ab9b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ab9b8: 0x32638  dsll        $a0, $v1, 24
    ctx->pc = 0x1ab9b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 24);
    // 0x1ab9bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ab9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ab9c0: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1ab9c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ab9c4: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1ab9c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1ab9c8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1ab9c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1ab9cc: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1ab9ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1ab9d0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ab9d0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ab9d4: 0xfc230028  sd          $v1, 0x28($at)
    ctx->pc = 0x1ab9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 3));
    // 0x1ab9d8: 0x8683000c  lh          $v1, 0xC($s4)
    ctx->pc = 0x1ab9d8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 12)));
    // 0x1ab9dc: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1ab9dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1ab9e0: 0x8682000e  lh          $v0, 0xE($s4)
    ctx->pc = 0x1ab9e0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 14)));
    // 0x1ab9e4: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1ab9e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1ab9e8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1ab9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1ab9ec: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1ab9ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1ab9f0: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1ab9f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1ab9f4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1ab9f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1ab9f8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1ab9f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1ab9fc: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1ab9fcu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1aba00: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1aba00u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1aba04: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1aba04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1aba08: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1aba08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1aba0c: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1aba0cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1aba10: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1aba10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1aba14: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1aba14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1aba18: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1aba18u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1aba1c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1ABA1Cu;
    {
        const bool branch_taken_0x1aba1c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1aba1c) {
            ctx->pc = 0x1ABA34u;
            goto label_1aba34;
        }
    }
    ctx->pc = 0x1ABA24u;
    // 0x1aba24: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1aba24u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1aba28: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1aba28u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1aba2c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1ABA2Cu;
    {
        const bool branch_taken_0x1aba2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABA30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABA2Cu;
            // 0x1aba30: 0x3183c  dsll32      $v1, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aba2c) {
            ctx->pc = 0x1ABA50u;
            goto label_1aba50;
        }
    }
    ctx->pc = 0x1ABA34u;
label_1aba34:
    // 0x1aba34: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1aba34u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1aba38: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1aba38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1aba3c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1aba3cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1aba40: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1aba40u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1aba44: 0x0  nop
    ctx->pc = 0x1aba44u;
    // NOP
    // 0x1aba48: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1aba48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1aba4c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1aba4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
label_1aba50:
    // 0x1aba50: 0x12203c  dsll32      $a0, $s2, 0
    ctx->pc = 0x1aba50u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) << (32 + 0));
    // 0x1aba54: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1aba54u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1aba58: 0x13283c  dsll32      $a1, $s3, 0
    ctx->pc = 0x1aba58u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 19) << (32 + 0));
    // 0x1aba5c: 0x2711021  addu        $v0, $s3, $s1
    ctx->pc = 0x1aba5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x1aba60: 0x3303c  dsll32      $a2, $v1, 0
    ctx->pc = 0x1aba60u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1aba64: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1aba64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1aba68: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1aba68u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1aba6c: 0x2501021  addu        $v0, $s2, $s0
    ctx->pc = 0x1aba6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x1aba70: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1aba70u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1aba74: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1aba74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1aba78: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x1aba78u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x1aba7c: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1aba7cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1aba80: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1aba80u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1aba84: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1aba84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1aba88: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1aba88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1aba8c: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1aba8cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1aba90: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1aba90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1aba94: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1aba94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1aba98: 0xc41825  or          $v1, $a2, $a0
    ctx->pc = 0x1aba98u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x1aba9c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1aba9cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1abaa0: 0xfc230038  sd          $v1, 0x38($at)
    ctx->pc = 0x1abaa0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 3));
    // 0x1abaa4: 0x86830010  lh          $v1, 0x10($s4)
    ctx->pc = 0x1abaa4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 16)));
    // 0x1abaa8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1abaa8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1abaac: 0x86820012  lh          $v0, 0x12($s4)
    ctx->pc = 0x1abaacu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 18)));
    // 0x1abab0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1abab0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1abab4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1abab4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1abab8: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1abab8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1ababc: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1ababcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1abac0: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1abac0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1abac4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1abac4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1abac8: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1abac8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1abacc: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1abaccu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1abad0: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1abad0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1abad4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1abad4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1abad8: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x1abad8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x1abadc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1abadcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1abae0: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1abae0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1abae4: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1abae4u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1abae8: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1ABAE8u;
    {
        const bool branch_taken_0x1abae8 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1abae8) {
            ctx->pc = 0x1ABB00u;
            goto label_1abb00;
        }
    }
    ctx->pc = 0x1ABAF0u;
    // 0x1abaf0: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abaf0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1abaf4: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1abaf4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1abaf8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1ABAF8u;
    {
        const bool branch_taken_0x1abaf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ABAFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABAF8u;
            // 0x1abafc: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1abaf8) {
            ctx->pc = 0x1ABB1Cu;
            goto label_1abb1c;
        }
    }
    ctx->pc = 0x1ABB00u;
label_1abb00:
    // 0x1abb00: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1abb00u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1abb04: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1abb04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1abb08: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1abb08u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1abb0c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1abb0cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1abb10: 0x0  nop
    ctx->pc = 0x1abb10u;
    // NOP
    // 0x1abb14: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1abb14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1abb18: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1abb18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1abb1c:
    // 0x1abb1c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1abb1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1abb20: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1abb20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1abb24: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1abb24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1abb28: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1abb28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1abb2c: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1abb2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1abb30: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1ABB30u;
    SET_GPR_U32(ctx, 31, 0x1ABB38u);
    ctx->pc = 0x1ABB34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABB30u;
            // 0x1abb34: 0xfc220048  sd          $v0, 0x48($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABB38u; }
        if (ctx->pc != 0x1ABB38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ABB38u; }
        if (ctx->pc != 0x1ABB38u) { return; }
    }
    ctx->pc = 0x1ABB38u;
label_1abb38:
    // 0x1abb38: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1abb38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1abb3c:
    // 0x1abb3c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1abb3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1abb40: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1abb40u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1abb44: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1abb44u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1abb48: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1abb48u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1abb4c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1abb4cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1abb50: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1abb50u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1abb54: 0x3e00008  jr          $ra
    ctx->pc = 0x1ABB54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ABB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ABB54u;
            // 0x1abb58: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB894u: goto label_1ab894;
            case 0x1AB8B4u: goto label_1ab8b4;
            case 0x1AB8D8u: goto label_1ab8d8;
            case 0x1AB960u: goto label_1ab960;
            case 0x1AB97Cu: goto label_1ab97c;
            case 0x1AB988u: goto label_1ab988;
            case 0x1ABA34u: goto label_1aba34;
            case 0x1ABA50u: goto label_1aba50;
            case 0x1ABB00u: goto label_1abb00;
            case 0x1ABB1Cu: goto label_1abb1c;
            case 0x1ABB38u: goto label_1abb38;
            case 0x1ABB3Cu: goto label_1abb3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ABB5Cu;
    // 0x1abb5c: 0x0  nop
    ctx->pc = 0x1abb5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
