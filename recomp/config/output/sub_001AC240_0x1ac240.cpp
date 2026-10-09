#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AC240
// Address: 0x1ac240 - 0x1ac624
void sub_001AC240_0x1ac240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AC240_0x1ac240");
#endif

    switch (ctx->pc) {
        case 0x1ac398u: goto label_1ac398;
        case 0x1ac3a4u: goto label_1ac3a4;
        case 0x1ac5f8u: goto label_1ac5f8;
        default: break;
    }

    ctx->pc = 0x1ac240u;

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
    ctx->pc = GPR_U32(ctx, 31); return;
}
