#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018B2C0
// Address: 0x18b2c0 - 0x18b3b0
void sub_0018B2C0_0x18b2c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018B2C0_0x18b2c0");
#endif

    ctx->pc = 0x18b2c0u;

    // 0x18b2c0: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x18b2c0u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18b2c4: 0x14a0001a  bnez        $a1, . + 4 + (0x1A << 2)
    ctx->pc = 0x18B2C4u;
    {
        const bool branch_taken_0x18b2c4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x18B2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B2C4u;
            // 0x18b2c8: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b2c4) {
            ctx->pc = 0x18B330u;
            goto label_18b330;
        }
    }
    ctx->pc = 0x18B2CCu;
    // 0x18b2cc: 0x14820005  bne         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18B2CCu;
    {
        const bool branch_taken_0x18b2cc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x18b2cc) {
            ctx->pc = 0x18B2E4u;
            goto label_18b2e4;
        }
    }
    ctx->pc = 0x18B2D4u;
    // 0x18b2d4: 0x3c024300  lui         $v0, 0x4300
    ctx->pc = 0x18b2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17152 << 16));
    // 0x18b2d8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18b2d8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18b2dc: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x18B2DCu;
    {
        const bool branch_taken_0x18b2dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b2dc) {
            ctx->pc = 0x18B3A4u;
            goto label_18b3a4;
        }
    }
    ctx->pc = 0x18B2E4u;
label_18b2e4:
    // 0x18b2e4: 0x1080002f  beqz        $a0, . + 4 + (0x2F << 2)
    ctx->pc = 0x18B2E4u;
    {
        const bool branch_taken_0x18b2e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b2e4) {
            ctx->pc = 0x18B3A4u;
            goto label_18b3a4;
        }
    }
    ctx->pc = 0x18B2ECu;
    // 0x18b2ec: 0x42042  srl         $a0, $a0, 1
    ctx->pc = 0x18b2ecu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
    // 0x18b2f0: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x18B2F0u;
    {
        const bool branch_taken_0x18b2f0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x18b2f0) {
            ctx->pc = 0x18B2FCu;
            goto label_18b2fc;
        }
    }
    ctx->pc = 0x18B2F8u;
    // 0x18b2f8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x18b2f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_18b2fc:
    // 0x18b2fc: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18B2FCu;
    {
        const bool branch_taken_0x18b2fc = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x18B300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B2FCu;
            // 0x18b300: 0x41842  srl         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b2fc) {
            ctx->pc = 0x18B310u;
            goto label_18b310;
        }
    }
    ctx->pc = 0x18B304u;
    // 0x18b304: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x18b304u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18b308: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18B308u;
    {
        const bool branch_taken_0x18b308 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B30Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B308u;
            // 0x18b30c: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b308) {
            ctx->pc = 0x18B328u;
            goto label_18b328;
        }
    }
    ctx->pc = 0x18B310u;
label_18b310:
    // 0x18b310: 0x30820001  andi        $v0, $a0, 0x1
    ctx->pc = 0x18b310u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x18b314: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x18b314u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18b318: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18b318u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18b31c: 0x0  nop
    ctx->pc = 0x18b31cu;
    // NOP
    // 0x18b320: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18b320u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18b324: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x18b324u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_18b328:
    // 0x18b328: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x18B328u;
    {
        const bool branch_taken_0x18b328 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b328) {
            ctx->pc = 0x18B3A4u;
            goto label_18b3a4;
        }
    }
    ctx->pc = 0x18B330u;
label_18b330:
    // 0x18b330: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18B330u;
    {
        const bool branch_taken_0x18b330 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x18B334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B330u;
            // 0x18b334: 0x41842  srl         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b330) {
            ctx->pc = 0x18B344u;
            goto label_18b344;
        }
    }
    ctx->pc = 0x18B338u;
    // 0x18b338: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x18b338u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18b33c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18B33Cu;
    {
        const bool branch_taken_0x18b33c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B33Cu;
            // 0x18b340: 0x468000a0  cvt.s.w     $f2, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b33c) {
            ctx->pc = 0x18B35Cu;
            goto label_18b35c;
        }
    }
    ctx->pc = 0x18B344u;
label_18b344:
    // 0x18b344: 0x30820001  andi        $v0, $a0, 0x1
    ctx->pc = 0x18b344u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x18b348: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x18b348u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18b34c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18b34cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18b350: 0x0  nop
    ctx->pc = 0x18b350u;
    // NOP
    // 0x18b354: 0x468000a0  cvt.s.w     $f2, $f0
    ctx->pc = 0x18b354u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x18b358: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x18b358u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_18b35c:
    // 0x18b35c: 0x3c03437f  lui         $v1, 0x437F
    ctx->pc = 0x18b35cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17279 << 16));
    // 0x18b360: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x18b360u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x18b364: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18b364u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18b368: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x18b368u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18b36c: 0x0  nop
    ctx->pc = 0x18b36cu;
    // NOP
    // 0x18b370: 0x46001003  div.s       $f0, $f2, $f0
    ctx->pc = 0x18b370u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[2] / ctx->f[0];
    // 0x18b374: 0x0  nop
    ctx->pc = 0x18b374u;
    // NOP
    // 0x18b378: 0x0  nop
    ctx->pc = 0x18b378u;
    // NOP
    // 0x18b37c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x18b37cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18b380: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x18B380u;
    {
        const bool branch_taken_0x18b380 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18b380) {
            ctx->pc = 0x18B38Cu;
            goto label_18b38c;
        }
    }
    ctx->pc = 0x18B388u;
    // 0x18b388: 0x46000806  mov.s       $f0, $f1
    ctx->pc = 0x18b388u;
    ctx->f[0] = FPU_MOV_S(ctx->f[1]);
label_18b38c:
    // 0x18b38c: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x18b38cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18b390: 0x0  nop
    ctx->pc = 0x18b390u;
    // NOP
    // 0x18b394: 0x46010034  c.lt.s      $f0, $f1
    ctx->pc = 0x18b394u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18b398: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x18B398u;
    {
        const bool branch_taken_0x18b398 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18b398) {
            ctx->pc = 0x18B3A4u;
            goto label_18b3a4;
        }
    }
    ctx->pc = 0x18B3A0u;
    // 0x18b3a0: 0x46000806  mov.s       $f0, $f1
    ctx->pc = 0x18b3a0u;
    ctx->f[0] = FPU_MOV_S(ctx->f[1]);
label_18b3a4:
    // 0x18b3a4: 0x3e00008  jr          $ra
    ctx->pc = 0x18B3A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18B2E4u: goto label_18b2e4;
            case 0x18B2FCu: goto label_18b2fc;
            case 0x18B310u: goto label_18b310;
            case 0x18B328u: goto label_18b328;
            case 0x18B330u: goto label_18b330;
            case 0x18B344u: goto label_18b344;
            case 0x18B35Cu: goto label_18b35c;
            case 0x18B38Cu: goto label_18b38c;
            case 0x18B3A4u: goto label_18b3a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18B3ACu;
    // 0x18b3ac: 0x0  nop
    ctx->pc = 0x18b3acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
