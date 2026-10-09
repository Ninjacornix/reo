#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E7D0
// Address: 0x18e7d0 - 0x18e910
void sub_0018E7D0_0x18e7d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E7D0_0x18e7d0");
#endif

    switch (ctx->pc) {
        case 0x18e800u: goto label_18e800;
        case 0x18e88cu: goto label_18e88c;
        case 0x18e8f0u: goto label_18e8f0;
        default: break;
    }

    ctx->pc = 0x18e7d0u;

    // 0x18e7d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x18e7d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18e7d4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x18e7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x18e7d8: 0x27a60038  addiu       $a2, $sp, 0x38
    ctx->pc = 0x18e7d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x18e7dc: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x18e7dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x18e7e0: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x18e7e0u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x18e7e4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18e7e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e7e8: 0xafa0003c  sw          $zero, 0x3C($sp)
    ctx->pc = 0x18e7e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 0));
    // 0x18e7ec: 0x46006506  mov.s       $f20, $f12
    ctx->pc = 0x18e7ecu;
    ctx->f[20] = FPU_MOV_S(ctx->f[12]);
    // 0x18e7f0: 0xafa00038  sw          $zero, 0x38($sp)
    ctx->pc = 0x18e7f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
    // 0x18e7f4: 0x86070000  lh          $a3, 0x0($s0)
    ctx->pc = 0x18e7f4u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18e7f8: 0xc063c10  jal         func_18F040
    ctx->pc = 0x18E7F8u;
    SET_GPR_U32(ctx, 31, 0x18E800u);
    ctx->pc = 0x18E7FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E7F8u;
            // 0x18e7fc: 0x27a5003c  addiu       $a1, $sp, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F040u;
    if (runtime->hasFunction(0x18F040u)) {
        auto targetFn = runtime->lookupFunction(0x18F040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E800u; }
        if (ctx->pc != 0x18E800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F040_0x18f040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E800u; }
        if (ctx->pc != 0x18E800u) { return; }
    }
    ctx->pc = 0x18E800u;
label_18e800:
    // 0x18e800: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x18e800u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x18e804: 0x8fa80038  lw          $t0, 0x38($sp)
    ctx->pc = 0x18e804u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x18e808: 0x15000006  bnez        $t0, . + 4 + (0x6 << 2)
    ctx->pc = 0x18E808u;
    {
        const bool branch_taken_0x18e808 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e808) {
            ctx->pc = 0x18E824u;
            goto label_18e824;
        }
    }
    ctx->pc = 0x18E810u;
    // 0x18e810: 0x8fa2003c  lw          $v0, 0x3C($sp)
    ctx->pc = 0x18e810u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x18e814: 0x84420004  lh          $v0, 0x4($v0)
    ctx->pc = 0x18e814u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x18e818: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18e818u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e81c: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x18E81Cu;
    {
        const bool branch_taken_0x18e81c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E81Cu;
            // 0x18e820: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e81c) {
            ctx->pc = 0x18E8FCu;
            goto label_18e8fc;
        }
    }
    ctx->pc = 0x18E824u;
label_18e824:
    // 0x18e824: 0x8fa4003c  lw          $a0, 0x3C($sp)
    ctx->pc = 0x18e824u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x18e828: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x18e828u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x18e82c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x18e82cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18e830: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x18E830u;
    {
        const bool branch_taken_0x18e830 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18E834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E830u;
            // 0x18e834: 0x3c020001  lui         $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e830) {
            ctx->pc = 0x18E894u;
            goto label_18e894;
        }
    }
    ctx->pc = 0x18E838u;
    // 0x18e838: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18E838u;
    {
        const bool branch_taken_0x18e838 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18e838) {
            ctx->pc = 0x18E848u;
            goto label_18e848;
        }
    }
    ctx->pc = 0x18E840u;
    // 0x18e840: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x18E840u;
    {
        const bool branch_taken_0x18e840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e840) {
            ctx->pc = 0x18E8F8u;
            goto label_18e8f8;
        }
    }
    ctx->pc = 0x18E848u;
label_18e848:
    // 0x18e848: 0x84850004  lh          $a1, 0x4($a0)
    ctx->pc = 0x18e848u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18e84c: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x18e84cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x18e850: 0x85030004  lh          $v1, 0x4($t0)
    ctx->pc = 0x18e850u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x18e854: 0x85020006  lh          $v0, 0x6($t0)
    ctx->pc = 0x18e854u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 6)));
    // 0x18e858: 0x84840006  lh          $a0, 0x6($a0)
    ctx->pc = 0x18e858u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x18e85c: 0x44850800  mtc1        $a1, $f1
    ctx->pc = 0x18e85cu;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e860: 0x0  nop
    ctx->pc = 0x18e860u;
    // NOP
    // 0x18e864: 0x46800b60  cvt.s.w     $f13, $f1
    ctx->pc = 0x18e864u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
    // 0x18e868: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x18e868u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e86c: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x18e86cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e870: 0x0  nop
    ctx->pc = 0x18e870u;
    // NOP
    // 0x18e874: 0x468003a0  cvt.s.w     $f14, $f0
    ctx->pc = 0x18e874u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[14] = FPU_CVT_S_W(tmp); }
    // 0x18e878: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18e878u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e87c: 0x0  nop
    ctx->pc = 0x18e87cu;
    // NOP
    // 0x18e880: 0x46800be0  cvt.s.w     $f15, $f1
    ctx->pc = 0x18e880u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[15] = FPU_CVT_S_W(tmp); }
    // 0x18e884: 0xc063c78  jal         func_18F1E0
    ctx->pc = 0x18E884u;
    SET_GPR_U32(ctx, 31, 0x18E88Cu);
    ctx->pc = 0x18E888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E884u;
            // 0x18e888: 0x46800420  cvt.s.w     $f16, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[16] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F1E0u;
    if (runtime->hasFunction(0x18F1E0u)) {
        auto targetFn = runtime->lookupFunction(0x18F1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E88Cu; }
        if (ctx->pc != 0x18E88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F1E0_0x18f1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E88Cu; }
        if (ctx->pc != 0x18E88Cu) { return; }
    }
    ctx->pc = 0x18E88Cu;
label_18e88c:
    // 0x18e88c: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x18E88Cu;
    {
        const bool branch_taken_0x18e88c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E88Cu;
            // 0x18e890: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e88c) {
            ctx->pc = 0x18E900u;
            goto label_18e900;
        }
    }
    ctx->pc = 0x18E894u;
label_18e894:
    // 0x18e894: 0x84870004  lh          $a3, 0x4($a0)
    ctx->pc = 0x18e894u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18e898: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x18e898u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x18e89c: 0x84860006  lh          $a2, 0x6($a0)
    ctx->pc = 0x18e89cu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x18e8a0: 0x8485000a  lh          $a1, 0xA($a0)
    ctx->pc = 0x18e8a0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x18e8a4: 0x85030006  lh          $v1, 0x6($t0)
    ctx->pc = 0x18e8a4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 6)));
    // 0x18e8a8: 0x85020008  lh          $v0, 0x8($t0)
    ctx->pc = 0x18e8a8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x18e8ac: 0x44870800  mtc1        $a3, $f1
    ctx->pc = 0x18e8acu;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e8b0: 0x44860000  mtc1        $a2, $f0
    ctx->pc = 0x18e8b0u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e8b4: 0x0  nop
    ctx->pc = 0x18e8b4u;
    // NOP
    // 0x18e8b8: 0x46800b60  cvt.s.w     $f13, $f1
    ctx->pc = 0x18e8b8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
    // 0x18e8bc: 0x85040004  lh          $a0, 0x4($t0)
    ctx->pc = 0x18e8bcu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x18e8c0: 0x468003a0  cvt.s.w     $f14, $f0
    ctx->pc = 0x18e8c0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[14] = FPU_CVT_S_W(tmp); }
    // 0x18e8c4: 0x44850800  mtc1        $a1, $f1
    ctx->pc = 0x18e8c4u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e8c8: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x18e8c8u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e8cc: 0x0  nop
    ctx->pc = 0x18e8ccu;
    // NOP
    // 0x18e8d0: 0x46800be0  cvt.s.w     $f15, $f1
    ctx->pc = 0x18e8d0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[15] = FPU_CVT_S_W(tmp); }
    // 0x18e8d4: 0x46800420  cvt.s.w     $f16, $f0
    ctx->pc = 0x18e8d4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[16] = FPU_CVT_S_W(tmp); }
    // 0x18e8d8: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x18e8d8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e8dc: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18e8dcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e8e0: 0x0  nop
    ctx->pc = 0x18e8e0u;
    // NOP
    // 0x18e8e4: 0x46800c60  cvt.s.w     $f17, $f1
    ctx->pc = 0x18e8e4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[17] = FPU_CVT_S_W(tmp); }
    // 0x18e8e8: 0xc063c98  jal         func_18F260
    ctx->pc = 0x18E8E8u;
    SET_GPR_U32(ctx, 31, 0x18E8F0u);
    ctx->pc = 0x18E8ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E8E8u;
            // 0x18e8ec: 0x468004a0  cvt.s.w     $f18, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[18] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F260u;
    if (runtime->hasFunction(0x18F260u)) {
        auto targetFn = runtime->lookupFunction(0x18F260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E8F0u; }
        if (ctx->pc != 0x18E8F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F260_0x18f260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E8F0u; }
        if (ctx->pc != 0x18E8F0u) { return; }
    }
    ctx->pc = 0x18E8F0u;
label_18e8f0:
    // 0x18e8f0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18E8F0u;
    {
        const bool branch_taken_0x18e8f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e8f0) {
            ctx->pc = 0x18E8FCu;
            goto label_18e8fc;
        }
    }
    ctx->pc = 0x18E8F8u;
label_18e8f8:
    // 0x18e8f8: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x18e8f8u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
label_18e8fc:
    // 0x18e8fc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x18e8fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_18e900:
    // 0x18e900: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x18e900u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x18e904: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x18e904u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18e908: 0x3e00008  jr          $ra
    ctx->pc = 0x18E908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18E90Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E908u;
            // 0x18e90c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18E800u: goto label_18e800;
            case 0x18E824u: goto label_18e824;
            case 0x18E848u: goto label_18e848;
            case 0x18E88Cu: goto label_18e88c;
            case 0x18E894u: goto label_18e894;
            case 0x18E8F0u: goto label_18e8f0;
            case 0x18E8F8u: goto label_18e8f8;
            case 0x18E8FCu: goto label_18e8fc;
            case 0x18E900u: goto label_18e900;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18E910u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
