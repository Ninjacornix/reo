#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017DC48
// Address: 0x17dc48 - 0x17de60
void sub_0017DC48_0x17dc48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017DC48_0x17dc48");
#endif

    switch (ctx->pc) {
        case 0x17dc58u: goto label_17dc58;
        case 0x17dc90u: goto label_17dc90;
        case 0x17dce0u: goto label_17dce0;
        case 0x17dd20u: goto label_17dd20;
        case 0x17dd48u: goto label_17dd48;
        case 0x17dd70u: goto label_17dd70;
        case 0x17dda8u: goto label_17dda8;
        case 0x17dde0u: goto label_17dde0;
        case 0x17de10u: goto label_17de10;
        case 0x17de30u: goto label_17de30;
        default: break;
    }

    ctx->pc = 0x17dc48u;

    // 0x17dc48: 0x24ec0400  addiu       $t4, $a3, 0x400
    ctx->pc = 0x17dc48u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), 1024));
    // 0x17dc4c: 0x24ed0800  addiu       $t5, $a3, 0x800
    ctx->pc = 0x17dc4cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 7), 2048));
    // 0x17dc50: 0x2408000f  addiu       $t0, $zero, 0xF
    ctx->pc = 0x17dc50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x17dc54: 0x24e2080f  addiu       $v0, $a3, 0x80F
    ctx->pc = 0x17dc54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 2063));
label_17dc58:
    // 0x17dc58: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x17dc58u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x17dc5c: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x17dc5cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x17dc60: 0x0  nop
    ctx->pc = 0x17dc60u;
    // NOP
    // 0x17dc64: 0x0  nop
    ctx->pc = 0x17dc64u;
    // NOP
    // 0x17dc68: 0x0  nop
    ctx->pc = 0x17dc68u;
    // NOP
    // 0x17dc6c: 0x501fffa  bgez        $t0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17DC6Cu;
    {
        const bool branch_taken_0x17dc6c = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x17DC70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DC6Cu;
            // 0x17dc70: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dc6c) {
            ctx->pc = 0x17DC58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dc58;
        }
    }
    ctx->pc = 0x17DC74u;
    // 0x17dc74: 0x3c013f94  lui         $at, 0x3F94
    ctx->pc = 0x17dc74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16276 << 16));
    // 0x17dc78: 0x3421fdf3  ori         $at, $at, 0xFDF3
    ctx->pc = 0x17dc78u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)65011);
    // 0x17dc7c: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x17dc7cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x17dc80: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x17dc80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x17dc84: 0x3c014f00  lui         $at, 0x4F00
    ctx->pc = 0x17dc84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)20224 << 16));
    // 0x17dc88: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x17dc88u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x17dc8c: 0x3c098000  lui         $t1, 0x8000
    ctx->pc = 0x17dc8cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32768 << 16));
label_17dc90:
    // 0x17dc90: 0x2502fff0  addiu       $v0, $t0, -0x10
    ctx->pc = 0x17dc90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967280));
    // 0x17dc94: 0x1a82021  addu        $a0, $t5, $t0
    ctx->pc = 0x17dc94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 8)));
    // 0x17dc98: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x17dc98u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17dc9c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x17dc9cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x17dca0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x17dca0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x17dca4: 0x46020002  mul.s       $f0, $f0, $f2
    ctx->pc = 0x17dca4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x17dca8: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x17dca8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17dcac: 0x460000e4  .word       0x460000E4                   # cvt.w.s     $f3, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x17dcacu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x17dcb0: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x17dcb0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x17dcb4: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x17DCB4u;
    {
        const bool branch_taken_0x17dcb4 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x17DCB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DCB4u;
            // 0x17dcb8: 0x290300ec  slti        $v1, $t0, 0xEC (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)236) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dcb4) {
            ctx->pc = 0x17DCCCu;
            goto label_17dccc;
        }
    }
    ctx->pc = 0x17DCBCu;
    // 0x17dcbc: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x17dcbcu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x17dcc0: 0x460000e4  .word       0x460000E4                   # cvt.w.s     $f3, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x17dcc0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x17dcc4: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x17dcc4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x17dcc8: 0x491025  or          $v0, $v0, $t1
    ctx->pc = 0x17dcc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 9));
label_17dccc:
    // 0x17dccc: 0x1460fff0  bnez        $v1, . + 4 + (-0x10 << 2)
    ctx->pc = 0x17DCCCu;
    {
        const bool branch_taken_0x17dccc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17DCD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DCCCu;
            // 0x17dcd0: 0xa0820000  sb          $v0, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dccc) {
            ctx->pc = 0x17DC90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dc90;
        }
    }
    ctx->pc = 0x17DCD4u;
    // 0x17dcd4: 0x240800ec  addiu       $t0, $zero, 0xEC
    ctx->pc = 0x17dcd4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 236));
    // 0x17dcd8: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x17dcd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17dcdc: 0x0  nop
    ctx->pc = 0x17dcdcu;
    // NOP
label_17dce0:
    // 0x17dce0: 0x1a81821  addu        $v1, $t5, $t0
    ctx->pc = 0x17dce0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 8)));
    // 0x17dce4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x17dce4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x17dce8: 0x29020100  slti        $v0, $t0, 0x100
    ctx->pc = 0x17dce8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x17dcec: 0x0  nop
    ctx->pc = 0x17dcecu;
    // NOP
    // 0x17dcf0: 0x0  nop
    ctx->pc = 0x17dcf0u;
    // NOP
    // 0x17dcf4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17DCF4u;
    {
        const bool branch_taken_0x17dcf4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17DCF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DCF4u;
            // 0x17dcf8: 0xa0640000  sb          $a0, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dcf4) {
            ctx->pc = 0x17DCE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dce0;
        }
    }
    ctx->pc = 0x17DCFCu;
    // 0x17dcfc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x17dcfcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x17dd00: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x17dd00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x17dd04: 0xa22026  xor         $a0, $a1, $v0
    ctx->pc = 0x17dd04u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 2));
    // 0x17dd08: 0xc21026  xor         $v0, $a2, $v0
    ctx->pc = 0x17dd08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) ^ GPR_U64(ctx, 2));
    // 0x17dd0c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x17dd0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x17dd10: 0x24080008  addiu       $t0, $zero, 0x8
    ctx->pc = 0x17dd10u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x17dd14: 0x62300a  movz        $a2, $v1, $v0
    ctx->pc = 0x17dd14u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x17dd18: 0x25820020  addiu       $v0, $t4, 0x20
    ctx->pc = 0x17dd18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), 32));
    // 0x17dd1c: 0x64280a  movz        $a1, $v1, $a0
    ctx->pc = 0x17dd1cu;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 3));
label_17dd20:
    // 0x17dd20: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x17dd20u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x17dd24: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x17dd24u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x17dd28: 0x0  nop
    ctx->pc = 0x17dd28u;
    // NOP
    // 0x17dd2c: 0x0  nop
    ctx->pc = 0x17dd2cu;
    // NOP
    // 0x17dd30: 0x0  nop
    ctx->pc = 0x17dd30u;
    // NOP
    // 0x17dd34: 0x501fffa  bgez        $t0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17DD34u;
    {
        const bool branch_taken_0x17dd34 = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x17DD38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DD34u;
            // 0x17dd38: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dd34) {
            ctx->pc = 0x17DD20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dd20;
        }
    }
    ctx->pc = 0x17DD3Cu;
    // 0x17dd3c: 0x25820024  addiu       $v0, $t4, 0x24
    ctx->pc = 0x17dd3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), 36));
    // 0x17dd40: 0x24080007  addiu       $t0, $zero, 0x7
    ctx->pc = 0x17dd40u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x17dd44: 0x0  nop
    ctx->pc = 0x17dd44u;
    // NOP
label_17dd48:
    // 0x17dd48: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x17dd48u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x17dd4c: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x17dd4cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x17dd50: 0x0  nop
    ctx->pc = 0x17dd50u;
    // NOP
    // 0x17dd54: 0x0  nop
    ctx->pc = 0x17dd54u;
    // NOP
    // 0x17dd58: 0x0  nop
    ctx->pc = 0x17dd58u;
    // NOP
    // 0x17dd5c: 0x501fffa  bgez        $t0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17DD5Cu;
    {
        const bool branch_taken_0x17dd5c = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x17DD60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DD5Cu;
            // 0x17dd60: 0x24420004  addiu       $v0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dd5c) {
            ctx->pc = 0x17DD48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dd48;
        }
    }
    ctx->pc = 0x17DD64u;
    // 0x17dd64: 0x14a6000c  bne         $a1, $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x17DD64u;
    {
        const bool branch_taken_0x17dd64 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 6));
        ctx->pc = 0x17DD68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DD64u;
            // 0x17dd68: 0x24080011  addiu       $t0, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dd64) {
            ctx->pc = 0x17DD98u;
            goto label_17dd98;
        }
    }
    ctx->pc = 0x17DD6Cu;
    // 0x17dd6c: 0x25830044  addiu       $v1, $t4, 0x44
    ctx->pc = 0x17dd6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 12), 68));
label_17dd70:
    // 0x17dd70: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x17dd70u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x17dd74: 0xac650000  sw          $a1, 0x0($v1)
    ctx->pc = 0x17dd74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
    // 0x17dd78: 0x290200e0  slti        $v0, $t0, 0xE0
    ctx->pc = 0x17dd78u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)224) ? 1 : 0);
    // 0x17dd7c: 0x0  nop
    ctx->pc = 0x17dd7cu;
    // NOP
    // 0x17dd80: 0x0  nop
    ctx->pc = 0x17dd80u;
    // NOP
    // 0x17dd84: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17DD84u;
    {
        const bool branch_taken_0x17dd84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17DD88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DD84u;
            // 0x17dd88: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dd84) {
            ctx->pc = 0x17DD70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dd70;
        }
    }
    ctx->pc = 0x17DD8Cu;
    // 0x17dd8c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x17DD8Cu;
    {
        const bool branch_taken_0x17dd8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17DD90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DD8Cu;
            // 0x17dd90: 0x25820380  addiu       $v0, $t4, 0x380 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), 896));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17dd8c) {
            ctx->pc = 0x17DDDCu;
            goto label_17dddc;
        }
    }
    ctx->pc = 0x17DD94u;
    // 0x17dd94: 0x0  nop
    ctx->pc = 0x17dd94u;
    // NOP
label_17dd98:
    // 0x17dd98: 0xc55023  subu        $t2, $a2, $a1
    ctx->pc = 0x17dd98u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x17dd9c: 0x240b00cf  addiu       $t3, $zero, 0xCF
    ctx->pc = 0x17dd9cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 207));
    // 0x17dda0: 0x25890044  addiu       $t1, $t4, 0x44
    ctx->pc = 0x17dda0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 12), 68));
    // 0x17dda4: 0x0  nop
    ctx->pc = 0x17dda4u;
    // NOP
label_17dda8:
    // 0x17dda8: 0x14b001b  divu        $zero, $t2, $t3
    ctx->pc = 0x17dda8u;
    { uint32_t divisor = GPR_U32(ctx, 11); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,10); } }
    // 0x17ddac: 0x2503ffef  addiu       $v1, $t0, -0x11
    ctx->pc = 0x17ddacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967279));
    // 0x17ddb0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x17ddb0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x17ddb4: 0x51600001  beql        $t3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x17DDB4u;
    {
        const bool branch_taken_0x17ddb4 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        if (branch_taken_0x17ddb4) {
            ctx->pc = 0x17DDB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17DDB4u;
            // 0x17ddb8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x17DDBCu;
            goto label_17ddbc;
        }
    }
    ctx->pc = 0x17DDBCu;
label_17ddbc:
    // 0x17ddbc: 0x290400e0  slti        $a0, $t0, 0xE0
    ctx->pc = 0x17ddbcu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)224) ? 1 : 0);
    // 0x17ddc0: 0x1012  mflo        $v0
    ctx->pc = 0x17ddc0u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x17ddc4: 0x437018  mult        $t6, $v0, $v1
    ctx->pc = 0x17ddc4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 14, (int32_t)result); }
    // 0x17ddc8: 0x1c51021  addu        $v0, $t6, $a1
    ctx->pc = 0x17ddc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 5)));
    // 0x17ddcc: 0xad220000  sw          $v0, 0x0($t1)
    ctx->pc = 0x17ddccu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 2));
    // 0x17ddd0: 0x1480fff5  bnez        $a0, . + 4 + (-0xB << 2)
    ctx->pc = 0x17DDD0u;
    {
        const bool branch_taken_0x17ddd0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x17DDD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DDD0u;
            // 0x17ddd4: 0x25290004  addiu       $t1, $t1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ddd0) {
            ctx->pc = 0x17DDA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dda8;
        }
    }
    ctx->pc = 0x17DDD8u;
    // 0x17ddd8: 0x25820380  addiu       $v0, $t4, 0x380
    ctx->pc = 0x17ddd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), 896));
label_17dddc:
    // 0x17dddc: 0x2408000f  addiu       $t0, $zero, 0xF
    ctx->pc = 0x17dddcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_17dde0:
    // 0x17dde0: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x17dde0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x17dde4: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x17dde4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x17dde8: 0x0  nop
    ctx->pc = 0x17dde8u;
    // NOP
    // 0x17ddec: 0x0  nop
    ctx->pc = 0x17ddecu;
    // NOP
    // 0x17ddf0: 0x0  nop
    ctx->pc = 0x17ddf0u;
    // NOP
    // 0x17ddf4: 0x501fffa  bgez        $t0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17DDF4u;
    {
        const bool branch_taken_0x17ddf4 = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x17DDF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DDF4u;
            // 0x17ddf8: 0x24420004  addiu       $v0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ddf4) {
            ctx->pc = 0x17DDE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dde0;
        }
    }
    ctx->pc = 0x17DDFCu;
    // 0x17ddfc: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x17ddfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x17de00: 0x258203c0  addiu       $v0, $t4, 0x3C0
    ctx->pc = 0x17de00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), 960));
    // 0x17de04: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x17de04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x17de08: 0x2408000f  addiu       $t0, $zero, 0xF
    ctx->pc = 0x17de08u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x17de0c: 0x0  nop
    ctx->pc = 0x17de0cu;
    // NOP
label_17de10:
    // 0x17de10: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x17de10u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x17de14: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x17de14u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x17de18: 0x0  nop
    ctx->pc = 0x17de18u;
    // NOP
    // 0x17de1c: 0x0  nop
    ctx->pc = 0x17de1cu;
    // NOP
    // 0x17de20: 0x0  nop
    ctx->pc = 0x17de20u;
    // NOP
    // 0x17de24: 0x501fffa  bgez        $t0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x17DE24u;
    {
        const bool branch_taken_0x17de24 = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x17DE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DE24u;
            // 0x17de28: 0x24420004  addiu       $v0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17de24) {
            ctx->pc = 0x17DE10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17de10;
        }
    }
    ctx->pc = 0x17DE2Cu;
    // 0x17de2c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x17de2cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17de30:
    // 0x17de30: 0x1a81821  addu        $v1, $t5, $t0
    ctx->pc = 0x17de30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 8)));
    // 0x17de34: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x17de34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x17de38: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x17de38u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17de3c: 0x29040100  slti        $a0, $t0, 0x100
    ctx->pc = 0x17de3cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x17de40: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17de40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17de44: 0x4c1021  addu        $v0, $v0, $t4
    ctx->pc = 0x17de44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x17de48: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x17de48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17de4c: 0xace30000  sw          $v1, 0x0($a3)
    ctx->pc = 0x17de4cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x17de50: 0x1480fff7  bnez        $a0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x17DE50u;
    {
        const bool branch_taken_0x17de50 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x17DE54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DE50u;
            // 0x17de54: 0x24e70004  addiu       $a3, $a3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17de50) {
            ctx->pc = 0x17DE30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17de30;
        }
    }
    ctx->pc = 0x17DE58u;
    // 0x17de58: 0x3e00008  jr          $ra
    ctx->pc = 0x17DE58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17DC58u: goto label_17dc58;
            case 0x17DC90u: goto label_17dc90;
            case 0x17DCCCu: goto label_17dccc;
            case 0x17DCE0u: goto label_17dce0;
            case 0x17DD20u: goto label_17dd20;
            case 0x17DD48u: goto label_17dd48;
            case 0x17DD70u: goto label_17dd70;
            case 0x17DD98u: goto label_17dd98;
            case 0x17DDA8u: goto label_17dda8;
            case 0x17DDBCu: goto label_17ddbc;
            case 0x17DDDCu: goto label_17dddc;
            case 0x17DDE0u: goto label_17dde0;
            case 0x17DE10u: goto label_17de10;
            case 0x17DE30u: goto label_17de30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17DE60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
