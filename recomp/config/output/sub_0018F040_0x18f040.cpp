#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018F040
// Address: 0x18f040 - 0x18f1e0
void sub_0018F040_0x18f040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018F040_0x18f040");
#endif

    switch (ctx->pc) {
        case 0x18f134u: goto label_18f134;
        default: break;
    }

    ctx->pc = 0x18f040u;

    // 0x18f040: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f040u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f044: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x18f044u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18f048: 0x8c224160  lw          $v0, 0x4160($at)
    ctx->pc = 0x18f048u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16736)));
    // 0x18f04c: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x18f04cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x18f050: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x18f050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18f054: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18f054u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18f058: 0x84430006  lh          $v1, 0x6($v0)
    ctx->pc = 0x18f058u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x18f05c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18f05cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f060: 0x0  nop
    ctx->pc = 0x18f060u;
    // NOP
    // 0x18f064: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18f064u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18f068: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x18f068u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f06c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x18F06Cu;
    {
        const bool branch_taken_0x18f06c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18f06c) {
            ctx->pc = 0x18F084u;
            goto label_18f084;
        }
    }
    ctx->pc = 0x18F074u;
    // 0x18f074: 0x94880002  lhu         $t0, 0x2($a0)
    ctx->pc = 0x18f074u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18f078: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x18f078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18f07c: 0x15030005  bne         $t0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x18F07Cu;
    {
        const bool branch_taken_0x18f07c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 3));
        ctx->pc = 0x18F080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F07Cu;
            // 0x18f080: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f07c) {
            ctx->pc = 0x18F094u;
            goto label_18f094;
        }
    }
    ctx->pc = 0x18F084u;
label_18f084:
    // 0x18f084: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18f084u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18f088: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18f088u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f08c: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x18F08Cu;
    {
        const bool branch_taken_0x18f08c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F08Cu;
            // 0x18f090: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f08c) {
            ctx->pc = 0x18F1D8u;
            goto label_18f1d8;
        }
    }
    ctx->pc = 0x18F094u;
label_18f094:
    // 0x18f094: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x18f094u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x18f098: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18f098u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18f09c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x18f09cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18f0a0: 0x8463fffa  lh          $v1, -0x6($v1)
    ctx->pc = 0x18f0a0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 4294967290)));
    // 0x18f0a4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18f0a4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f0a8: 0x0  nop
    ctx->pc = 0x18f0a8u;
    // NOP
    // 0x18f0ac: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18f0acu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18f0b0: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18f0b0u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f0b4: 0x4501000d  bc1t        . + 4 + (0xD << 2)
    ctx->pc = 0x18F0B4u;
    {
        const bool branch_taken_0x18f0b4 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18f0b4) {
            ctx->pc = 0x18F0ECu;
            goto label_18f0ec;
        }
    }
    ctx->pc = 0x18F0BCu;
    // 0x18f0bc: 0x2507ffff  addiu       $a3, $t0, -0x1
    ctx->pc = 0x18f0bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x18f0c0: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x18f0c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x18f0c4: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x18f0c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x18f0c8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18f0c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18f0cc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18f0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18f0d0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18f0d0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18f0d4: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18f0d4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18f0d8: 0x94820002  lhu         $v0, 0x2($a0)
    ctx->pc = 0x18f0d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18f0dc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18f0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18f0e0: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x18f0e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18f0e4: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x18F0E4u;
    {
        const bool branch_taken_0x18f0e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F0E4u;
            // 0x18f0e8: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f0e4) {
            ctx->pc = 0x18F1D8u;
            goto label_18f1d8;
        }
    }
    ctx->pc = 0x18F0ECu;
label_18f0ec:
    // 0x18f0ec: 0x71c3c  dsll32      $v1, $a3, 16
    ctx->pc = 0x18f0ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18f0f0: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x18f0f0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x18f0f4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18F0F4u;
    {
        const bool branch_taken_0x18f0f4 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x18f0f4) {
            ctx->pc = 0x18F104u;
            goto label_18f104;
        }
    }
    ctx->pc = 0x18F0FCu;
    // 0x18f0fc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18F0FCu;
    {
        const bool branch_taken_0x18f0fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F0FCu;
            // 0x18f100: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f0fc) {
            ctx->pc = 0x18F11Cu;
            goto label_18f11c;
        }
    }
    ctx->pc = 0x18F104u;
label_18f104:
    // 0x18f104: 0x68182a  slt         $v1, $v1, $t0
    ctx->pc = 0x18f104u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x18f108: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x18F108u;
    {
        const bool branch_taken_0x18f108 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x18F10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F108u;
            // 0x18f10c: 0x7243c  dsll32      $a0, $a3, 16 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) << (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f108) {
            ctx->pc = 0x18F120u;
            goto label_18f120;
        }
    }
    ctx->pc = 0x18F110u;
    // 0x18f110: 0x2503ffff  addiu       $v1, $t0, -0x1
    ctx->pc = 0x18f110u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x18f114: 0x33c3c  dsll32      $a3, $v1, 16
    ctx->pc = 0x18f114u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) << (32 + 16));
    // 0x18f118: 0x73c3f  dsra32      $a3, $a3, 16
    ctx->pc = 0x18f118u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
label_18f11c:
    // 0x18f11c: 0x7243c  dsll32      $a0, $a3, 16
    ctx->pc = 0x18f11cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) << (32 + 16));
label_18f120:
    // 0x18f120: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x18f120u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x18f124: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x18f124u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x18f128: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18f128u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18f12c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18f12cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18f130: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18f130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18f134:
    // 0x18f134: 0x84440006  lh          $a0, 0x6($v0)
    ctx->pc = 0x18f134u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x18f138: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x18f138u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f13c: 0x0  nop
    ctx->pc = 0x18f13cu;
    // NOP
    // 0x18f140: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18f140u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18f144: 0x460c0032  c.eq.s      $f0, $f12
    ctx->pc = 0x18f144u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f148: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x18F148u;
    {
        const bool branch_taken_0x18f148 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18f148) {
            ctx->pc = 0x18F160u;
            goto label_18f160;
        }
    }
    ctx->pc = 0x18F150u;
    // 0x18f150: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18f150u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18f154: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x18f154u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f158: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x18F158u;
    {
        const bool branch_taken_0x18f158 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F15Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F158u;
            // 0x18f15c: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f158) {
            ctx->pc = 0x18F1D8u;
            goto label_18f1d8;
        }
    }
    ctx->pc = 0x18F160u;
label_18f160:
    // 0x18f160: 0x460c0034  c.lt.s      $f0, $f12
    ctx->pc = 0x18f160u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f164: 0x4500000d  bc1f        . + 4 + (0xD << 2)
    ctx->pc = 0x18F164u;
    {
        const bool branch_taken_0x18f164 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18f164) {
            ctx->pc = 0x18F19Cu;
            goto label_18f19c;
        }
    }
    ctx->pc = 0x18F16Cu;
    // 0x18f16c: 0x84430012  lh          $v1, 0x12($v0)
    ctx->pc = 0x18f16cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 18)));
    // 0x18f170: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18f170u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f174: 0x0  nop
    ctx->pc = 0x18f174u;
    // NOP
    // 0x18f178: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18f178u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18f17c: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18f17cu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f180: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18F180u;
    {
        const bool branch_taken_0x18f180 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18f180) {
            ctx->pc = 0x18F19Cu;
            goto label_18f19c;
        }
    }
    ctx->pc = 0x18F188u;
    // 0x18f188: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18f188u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18f18c: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x18f18cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x18f190: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x18f190u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x18f194: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x18F194u;
    {
        const bool branch_taken_0x18f194 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F194u;
            // 0x18f198: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f194) {
            ctx->pc = 0x18F1D8u;
            goto label_18f1d8;
        }
    }
    ctx->pc = 0x18F19Cu;
label_18f19c:
    // 0x18f19c: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x18f19cu;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f1a0: 0x0  nop
    ctx->pc = 0x18f1a0u;
    // NOP
    // 0x18f1a4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18f1a4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18f1a8: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18f1a8u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f1ac: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18F1ACu;
    {
        const bool branch_taken_0x18f1ac = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18F1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F1ACu;
            // 0x18f1b0: 0x24e30001  addiu       $v1, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f1ac) {
            ctx->pc = 0x18F1C8u;
            goto label_18f1c8;
        }
    }
    ctx->pc = 0x18F1B4u;
    // 0x18f1b4: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x18f1b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x18f1b8: 0x2442fff4  addiu       $v0, $v0, -0xC
    ctx->pc = 0x18f1b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967284));
    // 0x18f1bc: 0x33c3c  dsll32      $a3, $v1, 16
    ctx->pc = 0x18f1bcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) << (32 + 16));
    // 0x18f1c0: 0x1000ffdc  b           . + 4 + (-0x24 << 2)
    ctx->pc = 0x18F1C0u;
    {
        const bool branch_taken_0x18f1c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F1C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F1C0u;
            // 0x18f1c4: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f1c0) {
            ctx->pc = 0x18F134u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18f134;
        }
    }
    ctx->pc = 0x18F1C8u;
label_18f1c8:
    // 0x18f1c8: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x18f1c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x18f1cc: 0x33c3c  dsll32      $a3, $v1, 16
    ctx->pc = 0x18f1ccu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) << (32 + 16));
    // 0x18f1d0: 0x1000ffd8  b           . + 4 + (-0x28 << 2)
    ctx->pc = 0x18F1D0u;
    {
        const bool branch_taken_0x18f1d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F1D0u;
            // 0x18f1d4: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f1d0) {
            ctx->pc = 0x18F134u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18f134;
        }
    }
    ctx->pc = 0x18F1D8u;
label_18f1d8:
    // 0x18f1d8: 0x3e00008  jr          $ra
    ctx->pc = 0x18F1D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F084u: goto label_18f084;
            case 0x18F094u: goto label_18f094;
            case 0x18F0ECu: goto label_18f0ec;
            case 0x18F104u: goto label_18f104;
            case 0x18F11Cu: goto label_18f11c;
            case 0x18F120u: goto label_18f120;
            case 0x18F134u: goto label_18f134;
            case 0x18F160u: goto label_18f160;
            case 0x18F19Cu: goto label_18f19c;
            case 0x18F1C8u: goto label_18f1c8;
            case 0x18F1D8u: goto label_18f1d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F1E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
