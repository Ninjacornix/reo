#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133058
// Address: 0x133058 - 0x133140
void sub_00133058_0x133058(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133058_0x133058");
#endif

    switch (ctx->pc) {
        case 0x133090u: goto label_133090;
        case 0x133098u: goto label_133098;
        case 0x1330b0u: goto label_1330b0;
        default: break;
    }

    ctx->pc = 0x133058u;

    // 0x133058: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x133058u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13305c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x13305cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x133060: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x133060u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133064: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x133064u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x133068: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x133068u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13306c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x13306cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x133070: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x133070u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x133074: 0x82630072  lb          $v1, 0x72($s3)
    ctx->pc = 0x133074u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 114)));
    // 0x133078: 0x10600029  beqz        $v1, . + 4 + (0x29 << 2)
    ctx->pc = 0x133078u;
    {
        const bool branch_taken_0x133078 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13307Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133078u;
            // 0x13307c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133078) {
            ctx->pc = 0x133120u;
            goto label_133120;
        }
    }
    ctx->pc = 0x133080u;
    // 0x133080: 0x8e64000c  lw          $a0, 0xC($s3)
    ctx->pc = 0x133080u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x133084: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x133084u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x133088: 0xc04b22c  jal         func_12C8B0
    ctx->pc = 0x133088u;
    SET_GPR_U32(ctx, 31, 0x133090u);
    ctx->pc = 0x13308Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133088u;
            // 0x13308c: 0x2610b750  addiu       $s0, $s0, -0x48B0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294948688));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C8B0u;
    if (runtime->hasFunction(0x12C8B0u)) {
        auto targetFn = runtime->lookupFunction(0x12C8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133090u; }
        if (ctx->pc != 0x133090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C8B0_0x12c8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133090u; }
        if (ctx->pc != 0x133090u) { return; }
    }
    ctx->pc = 0x133090u;
label_133090:
    // 0x133090: 0xc04cb02  jal         func_132C08
    ctx->pc = 0x133090u;
    SET_GPR_U32(ctx, 31, 0x133098u);
    ctx->pc = 0x133094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133090u;
            // 0x133094: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132C08u;
    if (runtime->hasFunction(0x132C08u)) {
        auto targetFn = runtime->lookupFunction(0x132C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133098u; }
        if (ctx->pc != 0x133098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132C08_0x132c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133098u; }
        if (ctx->pc != 0x133098u) { return; }
    }
    ctx->pc = 0x133098u;
label_133098:
    // 0x133098: 0x8e110000  lw          $s1, 0x0($s0)
    ctx->pc = 0x133098u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13309c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13309cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1330a0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1330a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1330a4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1330a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1330a8: 0xc04c858  jal         func_132160
    ctx->pc = 0x1330A8u;
    SET_GPR_U32(ctx, 31, 0x1330B0u);
    ctx->pc = 0x1330ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1330A8u;
            // 0x1330ac: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132160u;
    if (runtime->hasFunction(0x132160u)) {
        auto targetFn = runtime->lookupFunction(0x132160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1330B0u; }
        if (ctx->pc != 0x1330B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132160_0x132160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1330B0u; }
        if (ctx->pc != 0x1330B0u) { return; }
    }
    ctx->pc = 0x1330B0u;
label_1330b0:
    // 0x1330b0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1330b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1330b4: 0xc7a00000  lwc1        $f0, 0x0($sp)
    ctx->pc = 0x1330b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1330b8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1330b8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1330bc: 0x3c014f00  lui         $at, 0x4F00
    ctx->pc = 0x1330bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)20224 << 16));
    // 0x1330c0: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x1330c0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x1330c4: 0xc7a20004  lwc1        $f2, 0x4($sp)
    ctx->pc = 0x1330c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1330c8: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1330c8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1330cc: 0xc441b788  lwc1        $f1, -0x4878($v0)
    ctx->pc = 0x1330ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294948744)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1330d0: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1330d0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1330d4: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x1330d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x1330d8: 0x0  nop
    ctx->pc = 0x1330d8u;
    // NOP
    // 0x1330dc: 0x0  nop
    ctx->pc = 0x1330dcu;
    // NOP
    // 0x1330e0: 0x46020003  div.s       $f0, $f0, $f2
    ctx->pc = 0x1330e0u;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[2];
    // 0x1330e4: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x1330e4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1330e8: 0x46001836  c.le.s      $f3, $f0
    ctx->pc = 0x1330e8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[3], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1330ec: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1330ecu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1330f0: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1330f0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1330f4: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x1330F4u;
    {
        const bool branch_taken_0x1330f4 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1330F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1330F4u;
            // 0x1330f8: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1330f4) {
            ctx->pc = 0x133110u;
            goto label_133110;
        }
    }
    ctx->pc = 0x1330FCu;
    // 0x1330fc: 0x46030001  sub.s       $f0, $f0, $f3
    ctx->pc = 0x1330fcu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[3]);
    // 0x133100: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x133100u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x133104: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x133104u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x133108: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x133108u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x13310c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x13310cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
label_133110:
    // 0x133110: 0xae64009c  sw          $a0, 0x9C($s3)
    ctx->pc = 0x133110u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 156), GPR_U32(ctx, 4));
    // 0x133114: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x133114u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x133118: 0x8c64f3c4  lw          $a0, -0xC3C($v1)
    ctx->pc = 0x133118u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294964164)));
    // 0x13311c: 0xae6400a0  sw          $a0, 0xA0($s3)
    ctx->pc = 0x13311cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 160), GPR_U32(ctx, 4));
label_133120:
    // 0x133120: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x133120u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133124: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x133124u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133128: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x133128u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13312c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x13312cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x133130: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x133130u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x133134: 0x3e00008  jr          $ra
    ctx->pc = 0x133134u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133134u;
            // 0x133138: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133090u: goto label_133090;
            case 0x133098u: goto label_133098;
            case 0x1330B0u: goto label_1330b0;
            case 0x133110u: goto label_133110;
            case 0x133120u: goto label_133120;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13313Cu;
    // 0x13313c: 0x0  nop
    ctx->pc = 0x13313cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
