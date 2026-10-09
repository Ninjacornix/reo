#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00194210
// Address: 0x194210 - 0x194470
void sub_00194210_0x194210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00194210_0x194210");
#endif

    switch (ctx->pc) {
        case 0x19424cu: goto label_19424c;
        case 0x194258u: goto label_194258;
        case 0x1942c8u: goto label_1942c8;
        case 0x1942d8u: goto label_1942d8;
        case 0x1943a0u: goto label_1943a0;
        case 0x1943c0u: goto label_1943c0;
        case 0x194458u: goto label_194458;
        default: break;
    }

    ctx->pc = 0x194210u;

    // 0x194210: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x194210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x194214: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194214u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194218: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x194218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19421c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19421cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x194220: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x194220u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x194224: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194224u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194228: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194228u;
    {
        const bool branch_taken_0x194228 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19422Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194228u;
            // 0x19422c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194228) {
            ctx->pc = 0x194238u;
            goto label_194238;
        }
    }
    ctx->pc = 0x194230u;
    // 0x194230: 0x1000008a  b           . + 4 + (0x8A << 2)
    ctx->pc = 0x194230u;
    {
        const bool branch_taken_0x194230 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194230u;
            // 0x194234: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194230) {
            ctx->pc = 0x19445Cu;
            goto label_19445c;
        }
    }
    ctx->pc = 0x194238u;
label_194238:
    // 0x194238: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x194238u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x19423c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x19423cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x194240: 0x2484fe90  addiu       $a0, $a0, -0x170
    ctx->pc = 0x194240u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966928));
    // 0x194244: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x194244u;
    SET_GPR_U32(ctx, 31, 0x19424Cu);
    ctx->pc = 0x194248u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194244u;
            // 0x194248: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19424Cu; }
        if (ctx->pc != 0x19424Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19424Cu; }
        if (ctx->pc != 0x19424Cu) { return; }
    }
    ctx->pc = 0x19424Cu;
label_19424c:
    // 0x19424c: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x19424cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x194250: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x194250u;
    SET_GPR_U32(ctx, 31, 0x194258u);
    ctx->pc = 0x194254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194250u;
            // 0x194254: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194258u; }
        if (ctx->pc != 0x194258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194258u; }
        if (ctx->pc != 0x194258u) { return; }
    }
    ctx->pc = 0x194258u;
label_194258:
    // 0x194258: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x194258u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x19425c: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x19425cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x194260: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x194260u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x194264: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x194264u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x194268: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x194268u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x19426c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19426cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194270: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194270u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194274: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x194274u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x194278: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x194278u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x19427c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x19427cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x194280: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x194280u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194284: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194284u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194288: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19428c: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x19428cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x194290: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194290u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194294: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x194294u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194298: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194298u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19429c: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x19429cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x1942a0: 0x8602000e  lh          $v0, 0xE($s0)
    ctx->pc = 0x1942a0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x1942a4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1942a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1942a8: 0x8603000c  lh          $v1, 0xC($s0)
    ctx->pc = 0x1942a8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1942ac: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1942acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1942b0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1942b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1942b4: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1942b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1942b8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1942b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1942bc: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1942bcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1942c0: 0xc06629c  jal         func_198A70
    ctx->pc = 0x1942C0u;
    SET_GPR_U32(ctx, 31, 0x1942C8u);
    ctx->pc = 0x1942C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1942C0u;
            // 0x1942c4: 0x86040000  lh          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1942C8u; }
        if (ctx->pc != 0x1942C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1942C8u; }
        if (ctx->pc != 0x1942C8u) { return; }
    }
    ctx->pc = 0x1942C8u;
label_1942c8:
    // 0x1942c8: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x1942c8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1942cc: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1942ccu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1942d0: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1942D0u;
    SET_GPR_U32(ctx, 31, 0x1942D8u);
    ctx->pc = 0x1942D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1942D0u;
            // 0x1942d4: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1942D8u; }
        if (ctx->pc != 0x1942D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1942D8u; }
        if (ctx->pc != 0x1942D8u) { return; }
    }
    ctx->pc = 0x1942D8u;
label_1942d8:
    // 0x1942d8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1942d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1942dc: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1942dcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1942e0: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1942e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1942e4: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1942e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1942e8: 0x11243c  dsll32      $a0, $s1, 16
    ctx->pc = 0x1942e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 16));
    // 0x1942ec: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1942ecu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1942f0: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1942f0u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1942f4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1942f4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1942f8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1942f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1942fc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1942fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x194300: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194304: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194304u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x194308: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194308u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19430c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x19430cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x194310: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194310u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194314: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194314u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194318: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194318u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19431c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x19431cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194320: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194320u;
    {
        const bool branch_taken_0x194320 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194320u;
            // 0x194324: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194320) {
            ctx->pc = 0x194338u;
            goto label_194338;
        }
    }
    ctx->pc = 0x194328u;
    // 0x194328: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194328u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x19432c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x19432cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194330: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194330u;
    {
        const bool branch_taken_0x194330 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194330u;
            // 0x194334: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194330) {
            ctx->pc = 0x194354u;
            goto label_194354;
        }
    }
    ctx->pc = 0x194338u;
label_194338:
    // 0x194338: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194338u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x19433c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x19433cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194340: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194340u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194344: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194344u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194348: 0x0  nop
    ctx->pc = 0x194348u;
    // NOP
    // 0x19434c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x19434cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194350: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194354:
    // 0x194354: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194354u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194358: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194358u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x19435c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19435cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194360: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x194360u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x194364: 0xfc220038  sd          $v0, 0x38($at)
    ctx->pc = 0x194364u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
    // 0x194368: 0x86020012  lh          $v0, 0x12($s0)
    ctx->pc = 0x194368u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 18)));
    // 0x19436c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19436cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194370: 0x86030010  lh          $v1, 0x10($s0)
    ctx->pc = 0x194370u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x194374: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194374u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194378: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194378u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x19437c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x19437cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194380: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194380u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194384: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x194384u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x194388: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x194388u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19438c: 0x86020004  lh          $v0, 0x4($s0)
    ctx->pc = 0x19438cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x194390: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x194390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x194394: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x194394u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194398: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194398u;
    SET_GPR_U32(ctx, 31, 0x1943A0u);
    ctx->pc = 0x19439Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194398u;
            // 0x19439c: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1943A0u; }
        if (ctx->pc != 0x1943A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1943A0u; }
        if (ctx->pc != 0x1943A0u) { return; }
    }
    ctx->pc = 0x1943A0u;
label_1943a0:
    // 0x1943a0: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1943a0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1943a4: 0x86030002  lh          $v1, 0x2($s0)
    ctx->pc = 0x1943a4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1943a8: 0x86020006  lh          $v0, 0x6($s0)
    ctx->pc = 0x1943a8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1943ac: 0x118c3f  dsra32      $s1, $s1, 16
    ctx->pc = 0x1943acu;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
    // 0x1943b0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1943b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1943b4: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1943b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1943b8: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1943B8u;
    SET_GPR_U32(ctx, 31, 0x1943C0u);
    ctx->pc = 0x1943BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1943B8u;
            // 0x1943bc: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1943C0u; }
        if (ctx->pc != 0x1943C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1943C0u; }
        if (ctx->pc != 0x1943C0u) { return; }
    }
    ctx->pc = 0x1943C0u;
label_1943c0:
    // 0x1943c0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1943c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1943c4: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1943c4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1943c8: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1943c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1943cc: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1943ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1943d0: 0x11243c  dsll32      $a0, $s1, 16
    ctx->pc = 0x1943d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 16));
    // 0x1943d4: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1943d4u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1943d8: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1943d8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1943dc: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1943dcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1943e0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1943e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1943e4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1943e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1943e8: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1943e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1943ec: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1943ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1943f0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1943f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1943f4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1943f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1943f8: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1943f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1943fc: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1943fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194400: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194400u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194404: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194404u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194408: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194408u;
    {
        const bool branch_taken_0x194408 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x19440Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194408u;
            // 0x19440c: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194408) {
            ctx->pc = 0x194420u;
            goto label_194420;
        }
    }
    ctx->pc = 0x194410u;
    // 0x194410: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194410u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194414: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194414u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194418: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194418u;
    {
        const bool branch_taken_0x194418 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19441Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194418u;
            // 0x19441c: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194418) {
            ctx->pc = 0x19443Cu;
            goto label_19443c;
        }
    }
    ctx->pc = 0x194420u;
label_194420:
    // 0x194420: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194420u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194424: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194424u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194428: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194428u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x19442c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x19442cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194430: 0x0  nop
    ctx->pc = 0x194430u;
    // NOP
    // 0x194434: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194434u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194438: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194438u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_19443c:
    // 0x19443c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19443cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194440: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194440u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194444: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x194444u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x194448: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194448u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x19444c: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x19444cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x194450: 0xc064f88  jal         func_193E20
    ctx->pc = 0x194450u;
    SET_GPR_U32(ctx, 31, 0x194458u);
    ctx->pc = 0x194454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194450u;
            // 0x194454: 0xfc220048  sd          $v0, 0x48($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194458u; }
        if (ctx->pc != 0x194458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194458u; }
        if (ctx->pc != 0x194458u) { return; }
    }
    ctx->pc = 0x194458u;
label_194458:
    // 0x194458: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194458u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_19445c:
    // 0x19445c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x19445cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x194460: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x194460u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x194464: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x194464u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194468: 0x3e00008  jr          $ra
    ctx->pc = 0x194468u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19446Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194468u;
            // 0x19446c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x194238u: goto label_194238;
            case 0x19424Cu: goto label_19424c;
            case 0x194258u: goto label_194258;
            case 0x1942C8u: goto label_1942c8;
            case 0x1942D8u: goto label_1942d8;
            case 0x194338u: goto label_194338;
            case 0x194354u: goto label_194354;
            case 0x1943A0u: goto label_1943a0;
            case 0x1943C0u: goto label_1943c0;
            case 0x194420u: goto label_194420;
            case 0x19443Cu: goto label_19443c;
            case 0x194458u: goto label_194458;
            case 0x19445Cu: goto label_19445c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194470u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
