#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A4F20
// Address: 0x1a4f20 - 0x1a504c
void sub_001A4F20_0x1a4f20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A4F20_0x1a4f20");
#endif

    ctx->pc = 0x1a4f20u;

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
            case 0x1A4F8Cu: goto label_1a4f8c;
            case 0x1A4F98u: goto label_1a4f98;
            case 0x1A4FACu: goto label_1a4fac;
            case 0x1A4FC0u: goto label_1a4fc0;
            case 0x1A4FDCu: goto label_1a4fdc;
            case 0x1A4FE8u: goto label_1a4fe8;
            case 0x1A5004u: goto label_1a5004;
            case 0x1A5020u: goto label_1a5020;
            case 0x1A5044u: goto label_1a5044;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A504Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
