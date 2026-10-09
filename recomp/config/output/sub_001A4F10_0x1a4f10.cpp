#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A4F10
// Address: 0x1a4f10 - 0x1a5180
void sub_001A4F10_0x1a4f10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A4F10_0x1a4f10");
#endif

    switch (ctx->pc) {
        case 0x1a50b0u: goto label_1a50b0;
        case 0x1a50b8u: goto label_1a50b8;
        case 0x1a50e8u: goto label_1a50e8;
        case 0x1a50f0u: goto label_1a50f0;
        case 0x1a5100u: goto label_1a5100;
        default: break;
    }

    ctx->pc = 0x1a4f10u;

    // 0x1a4f10: 0x80693c8  j           func_1A4F20
    ctx->pc = 0x1A4F10u;
    ctx->pc = 0x1A4F20u;
    goto label_1a4f20;
    ctx->pc = 0x1A4F18u;
    // 0x1a4f18: 0x0  nop
    ctx->pc = 0x1a4f18u;
    // NOP
    // 0x1a4f1c: 0x0  nop
    ctx->pc = 0x1a4f1cu;
    // NOP
label_1a4f20:
    // 0x1a4f20: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a4f20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a4f24: 0x8c860004  lw          $a2, 0x4($a0)
    ctx->pc = 0x1a4f24u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a4f28: 0x8c22ffe8  lw          $v0, -0x18($at)
    ctx->pc = 0x1a4f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967272)));
    // 0x1a4f2c: 0x24030013  addiu       $v1, $zero, 0x13
    ctx->pc = 0x1a4f2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1a4f30: 0x90850000  lbu         $a1, 0x0($a0)
    ctx->pc = 0x1a4f30u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a4f34: 0x10a3003a  beq         $a1, $v1, . + 4 + (0x3A << 2)
    ctx->pc = 0x1A4F34u;
    {
        const bool branch_taken_0x1a4f34 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A4F38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4F34u;
            // 0x1a4f38: 0xc21021  addu        $v0, $a2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4f34) {
            ctx->pc = 0x1A5020u;
            goto label_1a5020;
        }
    }
    ctx->pc = 0x1A4F3Cu;
    // 0x1a4f3c: 0x24030012  addiu       $v1, $zero, 0x12
    ctx->pc = 0x1a4f3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1a4f40: 0x10a30030  beq         $a1, $v1, . + 4 + (0x30 << 2)
    ctx->pc = 0x1A4F40u;
    {
        const bool branch_taken_0x1a4f40 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A4F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4F40u;
            // 0x1a4f44: 0x24030011  addiu       $v1, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4f40) {
            ctx->pc = 0x1A5004u;
            goto label_1a5004;
        }
    }
    ctx->pc = 0x1A4F48u;
    // 0x1a4f48: 0x10a30027  beq         $a1, $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1A4F48u;
    {
        const bool branch_taken_0x1a4f48 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a4f48) {
            ctx->pc = 0x1A4FE8u;
            goto label_1a4fe8;
        }
    }
    ctx->pc = 0x1A4F50u;
    // 0x1a4f50: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1a4f50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a4f54: 0x10a30021  beq         $a1, $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x1A4F54u;
    {
        const bool branch_taken_0x1a4f54 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A4F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4F54u;
            // 0x1a4f58: 0x24030023  addiu       $v1, $zero, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4f54) {
            ctx->pc = 0x1A4FDCu;
            goto label_1a4fdc;
        }
    }
    ctx->pc = 0x1A4F5Cu;
    // 0x1a4f5c: 0x10a30018  beq         $a1, $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1A4F5Cu;
    {
        const bool branch_taken_0x1a4f5c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a4f5c) {
            ctx->pc = 0x1A4FC0u;
            goto label_1a4fc0;
        }
    }
    ctx->pc = 0x1A4F64u;
    // 0x1a4f64: 0x24030022  addiu       $v1, $zero, 0x22
    ctx->pc = 0x1a4f64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1a4f68: 0x10a30010  beq         $a1, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1A4F68u;
    {
        const bool branch_taken_0x1a4f68 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A4F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4F68u;
            // 0x1a4f6c: 0x24030021  addiu       $v1, $zero, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4f68) {
            ctx->pc = 0x1A4FACu;
            goto label_1a4fac;
        }
    }
    ctx->pc = 0x1A4F70u;
    // 0x1a4f70: 0x10a30009  beq         $a1, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A4F70u;
    {
        const bool branch_taken_0x1a4f70 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1a4f70) {
            ctx->pc = 0x1A4F98u;
            goto label_1a4f98;
        }
    }
    ctx->pc = 0x1A4F78u;
    // 0x1a4f78: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1a4f78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1a4f7c: 0x10a20003  beq         $a1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A4F7Cu;
    {
        const bool branch_taken_0x1a4f7c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a4f7c) {
            ctx->pc = 0x1A4F8Cu;
            goto label_1a4f8c;
        }
    }
    ctx->pc = 0x1A4F84u;
    // 0x1a4f84: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1A4F84u;
    {
        const bool branch_taken_0x1a4f84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a4f84) {
            ctx->pc = 0x1A5044u;
            goto label_1a5044;
        }
    }
    ctx->pc = 0x1A4F8Cu;
label_1a4f8c:
    // 0x1a4f8c: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1a4f8cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4f90: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1A4F90u;
    {
        const bool branch_taken_0x1a4f90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a4f90) {
            ctx->pc = 0x1A5044u;
            goto label_1a5044;
        }
    }
    ctx->pc = 0x1A4F98u;
label_1a4f98:
    // 0x1a4f98: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x1a4f98u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a4f9c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1a4f9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a4fa0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a4fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a4fa4: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1A4FA4u;
    {
        const bool branch_taken_0x1a4fa4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4FA4u;
            // 0x1a4fa8: 0xc440fffc  lwc1        $f0, -0x4($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294967292)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4fa4) {
            ctx->pc = 0x1A5044u;
            goto label_1a5044;
        }
    }
    ctx->pc = 0x1A4FACu;
label_1a4fac:
    // 0x1a4fac: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x1a4facu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a4fb0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1a4fb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a4fb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a4fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a4fb8: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1A4FB8u;
    {
        const bool branch_taken_0x1a4fb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4FB8u;
            // 0x1a4fbc: 0xc440fff4  lwc1        $f0, -0xC($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294967284)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4fb8) {
            ctx->pc = 0x1A5044u;
            goto label_1a5044;
        }
    }
    ctx->pc = 0x1A4FC0u;
label_1a4fc0:
    // 0x1a4fc0: 0x94840002  lhu         $a0, 0x2($a0)
    ctx->pc = 0x1a4fc0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a4fc4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1a4fc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a4fc8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a4fc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a4fcc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a4fccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a4fd0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a4fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a4fd4: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1A4FD4u;
    {
        const bool branch_taken_0x1a4fd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4FD4u;
            // 0x1a4fd8: 0xc440fff4  lwc1        $f0, -0xC($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294967284)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4fd4) {
            ctx->pc = 0x1A5044u;
            goto label_1a5044;
        }
    }
    ctx->pc = 0x1A4FDCu;
label_1a4fdc:
    // 0x1a4fdc: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1a4fdcu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4fe0: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1A4FE0u;
    {
        const bool branch_taken_0x1a4fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a4fe0) {
            ctx->pc = 0x1A5044u;
            goto label_1a5044;
        }
    }
    ctx->pc = 0x1A4FE8u;
label_1a4fe8:
    // 0x1a4fe8: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x1a4fe8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a4fec: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a4fecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a4ff0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a4ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a4ff4: 0x8442fffe  lh          $v0, -0x2($v0)
    ctx->pc = 0x1a4ff4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294967294)));
    // 0x1a4ff8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a4ff8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4ffc: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1A4FFCu;
    {
        const bool branch_taken_0x1a4ffc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4FFCu;
            // 0x1a5000: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4ffc) {
            ctx->pc = 0x1A5044u;
            goto label_1a5044;
        }
    }
    ctx->pc = 0x1A5004u;
label_1a5004:
    // 0x1a5004: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x1a5004u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a5008: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1a5008u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a500c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a500cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a5010: 0x8442fffa  lh          $v0, -0x6($v0)
    ctx->pc = 0x1a5010u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294967290)));
    // 0x1a5014: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a5014u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a5018: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1A5018u;
    {
        const bool branch_taken_0x1a5018 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A501Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5018u;
            // 0x1a501c: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5018) {
            ctx->pc = 0x1A5044u;
            goto label_1a5044;
        }
    }
    ctx->pc = 0x1A5020u;
label_1a5020:
    // 0x1a5020: 0x94840002  lhu         $a0, 0x2($a0)
    ctx->pc = 0x1a5020u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a5024: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1a5024u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1a5028: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a5028u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a502c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a502cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a5030: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a5030u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a5034: 0x8442fffa  lh          $v0, -0x6($v0)
    ctx->pc = 0x1a5034u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294967290)));
    // 0x1a5038: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a5038u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a503c: 0x0  nop
    ctx->pc = 0x1a503cu;
    // NOP
    // 0x1a5040: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1a5040u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
label_1a5044:
    // 0x1a5044: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A4F20u: goto label_1a4f20;
            case 0x1A4F8Cu: goto label_1a4f8c;
            case 0x1A4F98u: goto label_1a4f98;
            case 0x1A4FACu: goto label_1a4fac;
            case 0x1A4FC0u: goto label_1a4fc0;
            case 0x1A4FDCu: goto label_1a4fdc;
            case 0x1A4FE8u: goto label_1a4fe8;
            case 0x1A5004u: goto label_1a5004;
            case 0x1A5020u: goto label_1a5020;
            case 0x1A5044u: goto label_1a5044;
            case 0x1A50B0u: goto label_1a50b0;
            case 0x1A50B8u: goto label_1a50b8;
            case 0x1A50E8u: goto label_1a50e8;
            case 0x1A50F0u: goto label_1a50f0;
            case 0x1A5100u: goto label_1a5100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A504Cu;
    // 0x1a504c: 0x0  nop
    ctx->pc = 0x1a504cu;
    // NOP
    // 0x1a5050: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1a5050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1a5054: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1a5054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1a5058: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1a5058u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1a505c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a505cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a5060: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1a5060u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5064: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a5064u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a5068: 0x27b30074  addiu       $s3, $sp, 0x74
    ctx->pc = 0x1a5068u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 116));
    // 0x1a506c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a506cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a5070: 0x27b20078  addiu       $s2, $sp, 0x78
    ctx->pc = 0x1a5070u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 120));
    // 0x1a5074: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a5074u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a5078: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1a5078u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1a507c: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x1a507cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5080: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x1a5080u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x1a5084: 0xc4a00004  lwc1        $f0, 0x4($a1)
    ctx->pc = 0x1a5084u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5088: 0xe6600000  swc1        $f0, 0x0($s3)
    ctx->pc = 0x1a5088u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 0), bits); }
    // 0x1a508c: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x1a508cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5090: 0xe6400000  swc1        $f0, 0x0($s2)
    ctx->pc = 0x1a5090u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
    // 0x1a5094: 0xc4c00000  lwc1        $f0, 0x0($a2)
    ctx->pc = 0x1a5094u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5098: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x1a5098u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x1a509c: 0xc4c00004  lwc1        $f0, 0x4($a2)
    ctx->pc = 0x1a509cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50a0: 0xe7a00064  swc1        $f0, 0x64($sp)
    ctx->pc = 0x1a50a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x1a50a4: 0xc4c00008  lwc1        $f0, 0x8($a2)
    ctx->pc = 0x1a50a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50a8: 0xc06946c  jal         func_1A51B0
    ctx->pc = 0x1A50A8u;
    SET_GPR_U32(ctx, 31, 0x1A50B0u);
    ctx->pc = 0x1A50ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50A8u;
            // 0x1a50ac: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A51B0u;
    if (runtime->hasFunction(0x1A51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50B0u; }
        if (ctx->pc != 0x1A50B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A51B0_0x1a51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50B0u; }
        if (ctx->pc != 0x1A50B0u) { return; }
    }
    ctx->pc = 0x1A50B0u;
label_1a50b0:
    // 0x1a50b0: 0xc06946c  jal         func_1A51B0
    ctx->pc = 0x1A50B0u;
    SET_GPR_U32(ctx, 31, 0x1A50B8u);
    ctx->pc = 0x1A50B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50B0u;
            // 0x1a50b4: 0x27a40060  addiu       $a0, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A51B0u;
    if (runtime->hasFunction(0x1A51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50B8u; }
        if (ctx->pc != 0x1A50B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A51B0_0x1a51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50B8u; }
        if (ctx->pc != 0x1A50B8u) { return; }
    }
    ctx->pc = 0x1A50B8u;
label_1a50b8:
    // 0x1a50b8: 0xc7a00070  lwc1        $f0, 0x70($sp)
    ctx->pc = 0x1a50b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50bc: 0x27b100a4  addiu       $s1, $sp, 0xA4
    ctx->pc = 0x1a50bcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 164));
    // 0x1a50c0: 0x27b000a8  addiu       $s0, $sp, 0xA8
    ctx->pc = 0x1a50c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
    // 0x1a50c4: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1a50c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a50c8: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x1a50c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1a50cc: 0x27a60060  addiu       $a2, $sp, 0x60
    ctx->pc = 0x1a50ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1a50d0: 0xe7a000a0  swc1        $f0, 0xA0($sp)
    ctx->pc = 0x1a50d0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 160), bits); }
    // 0x1a50d4: 0xc6600000  lwc1        $f0, 0x0($s3)
    ctx->pc = 0x1a50d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50d8: 0xe6200000  swc1        $f0, 0x0($s1)
    ctx->pc = 0x1a50d8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x1a50dc: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1a50dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50e0: 0xc069488  jal         func_1A5220
    ctx->pc = 0x1A50E0u;
    SET_GPR_U32(ctx, 31, 0x1A50E8u);
    ctx->pc = 0x1A50E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50E0u;
            // 0x1a50e4: 0xe6000000  swc1        $f0, 0x0($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5220u;
    if (runtime->hasFunction(0x1A5220u)) {
        auto targetFn = runtime->lookupFunction(0x1A5220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50E8u; }
        if (ctx->pc != 0x1A50E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5220_0x1a5220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50E8u; }
        if (ctx->pc != 0x1A50E8u) { return; }
    }
    ctx->pc = 0x1A50E8u;
label_1a50e8:
    // 0x1a50e8: 0xc06946c  jal         func_1A51B0
    ctx->pc = 0x1A50E8u;
    SET_GPR_U32(ctx, 31, 0x1A50F0u);
    ctx->pc = 0x1A50ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50E8u;
            // 0x1a50ec: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A51B0u;
    if (runtime->hasFunction(0x1A51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50F0u; }
        if (ctx->pc != 0x1A50F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A51B0_0x1a51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50F0u; }
        if (ctx->pc != 0x1A50F0u) { return; }
    }
    ctx->pc = 0x1A50F0u;
label_1a50f0:
    // 0x1a50f0: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1a50f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1a50f4: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x1a50f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a50f8: 0xc069488  jal         func_1A5220
    ctx->pc = 0x1A50F8u;
    SET_GPR_U32(ctx, 31, 0x1A5100u);
    ctx->pc = 0x1A50FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50F8u;
            // 0x1a50fc: 0x27a600a0  addiu       $a2, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5220u;
    if (runtime->hasFunction(0x1A5220u)) {
        auto targetFn = runtime->lookupFunction(0x1A5220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5100u; }
        if (ctx->pc != 0x1A5100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5220_0x1a5220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5100u; }
        if (ctx->pc != 0x1A5100u) { return; }
    }
    ctx->pc = 0x1A5100u;
label_1a5100:
    // 0x1a5100: 0xae80000c  sw          $zero, 0xC($s4)
    ctx->pc = 0x1a5100u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 12), GPR_U32(ctx, 0));
    // 0x1a5104: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1a5104u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1a5108: 0xae80001c  sw          $zero, 0x1C($s4)
    ctx->pc = 0x1a5108u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 28), GPR_U32(ctx, 0));
    // 0x1a510c: 0xae80002c  sw          $zero, 0x2C($s4)
    ctx->pc = 0x1a510cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 44), GPR_U32(ctx, 0));
    // 0x1a5110: 0xae83003c  sw          $v1, 0x3C($s4)
    ctx->pc = 0x1a5110u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 60), GPR_U32(ctx, 3));
    // 0x1a5114: 0xc7a000a0  lwc1        $f0, 0xA0($sp)
    ctx->pc = 0x1a5114u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5118: 0xe6800000  swc1        $f0, 0x0($s4)
    ctx->pc = 0x1a5118u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 0), bits); }
    // 0x1a511c: 0xc6200000  lwc1        $f0, 0x0($s1)
    ctx->pc = 0x1a511cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5120: 0xe6800004  swc1        $f0, 0x4($s4)
    ctx->pc = 0x1a5120u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 4), bits); }
    // 0x1a5124: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x1a5124u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5128: 0xe6800008  swc1        $f0, 0x8($s4)
    ctx->pc = 0x1a5128u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 8), bits); }
    // 0x1a512c: 0xc7a00090  lwc1        $f0, 0x90($sp)
    ctx->pc = 0x1a512cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 144)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5130: 0xe6800010  swc1        $f0, 0x10($s4)
    ctx->pc = 0x1a5130u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 16), bits); }
    // 0x1a5134: 0xc7a00094  lwc1        $f0, 0x94($sp)
    ctx->pc = 0x1a5134u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 148)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5138: 0xe6800014  swc1        $f0, 0x14($s4)
    ctx->pc = 0x1a5138u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 20), bits); }
    // 0x1a513c: 0xc7a00098  lwc1        $f0, 0x98($sp)
    ctx->pc = 0x1a513cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 152)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5140: 0xe6800018  swc1        $f0, 0x18($s4)
    ctx->pc = 0x1a5140u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 24), bits); }
    // 0x1a5144: 0xc7a00080  lwc1        $f0, 0x80($sp)
    ctx->pc = 0x1a5144u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 128)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5148: 0xe6800020  swc1        $f0, 0x20($s4)
    ctx->pc = 0x1a5148u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 32), bits); }
    // 0x1a514c: 0xc7a00084  lwc1        $f0, 0x84($sp)
    ctx->pc = 0x1a514cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 132)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5150: 0xe6800024  swc1        $f0, 0x24($s4)
    ctx->pc = 0x1a5150u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 36), bits); }
    // 0x1a5154: 0xc7a00088  lwc1        $f0, 0x88($sp)
    ctx->pc = 0x1a5154u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 136)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5158: 0xe6800028  swc1        $f0, 0x28($s4)
    ctx->pc = 0x1a5158u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 40), bits); }
    // 0x1a515c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1a515cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1a5160: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1a5160u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a5164: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a5164u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a5168: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a5168u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a516c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a516cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a5170: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a5170u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5174: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5174u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5174u;
            // 0x1a5178: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A4F20u: goto label_1a4f20;
            case 0x1A4F8Cu: goto label_1a4f8c;
            case 0x1A4F98u: goto label_1a4f98;
            case 0x1A4FACu: goto label_1a4fac;
            case 0x1A4FC0u: goto label_1a4fc0;
            case 0x1A4FDCu: goto label_1a4fdc;
            case 0x1A4FE8u: goto label_1a4fe8;
            case 0x1A5004u: goto label_1a5004;
            case 0x1A5020u: goto label_1a5020;
            case 0x1A5044u: goto label_1a5044;
            case 0x1A50B0u: goto label_1a50b0;
            case 0x1A50B8u: goto label_1a50b8;
            case 0x1A50E8u: goto label_1a50e8;
            case 0x1A50F0u: goto label_1a50f0;
            case 0x1A5100u: goto label_1a5100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A517Cu;
    // 0x1a517c: 0x0  nop
    ctx->pc = 0x1a517cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
