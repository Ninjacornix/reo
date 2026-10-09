#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE4B0
// Address: 0x1ae4b0 - 0x1ae6d0
void sub_001AE4B0_0x1ae4b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE4B0_0x1ae4b0");
#endif

    switch (ctx->pc) {
        case 0x1ae4e0u: goto label_1ae4e0;
        case 0x1ae4f8u: goto label_1ae4f8;
        case 0x1ae508u: goto label_1ae508;
        case 0x1ae548u: goto label_1ae548;
        case 0x1ae62cu: goto label_1ae62c;
        case 0x1ae6a0u: goto label_1ae6a0;
        default: break;
    }

    ctx->pc = 0x1ae4b0u;

    // 0x1ae4b0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1ae4b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1ae4b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ae4b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ae4b8: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1ae4b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1ae4bc: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x1ae4bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1ae4c0: 0x7fb40050  sq          $s4, 0x50($sp)
    ctx->pc = 0x1ae4c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 20));
    // 0x1ae4c4: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x1ae4c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x1ae4c8: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x1ae4c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x1ae4cc: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1ae4ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1ae4d0: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1ae4d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1ae4d4: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1ae4d4u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1ae4d8: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AE4D8u;
    SET_GPR_U32(ctx, 31, 0x1AE4E0u);
    ctx->pc = 0x1AE4DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE4D8u;
            // 0x1ae4dc: 0xa02043ff  sb          $zero, 0x43FF($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17407), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE4E0u; }
        if (ctx->pc != 0x1AE4E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE4E0u; }
        if (ctx->pc != 0x1AE4E0u) { return; }
    }
    ctx->pc = 0x1AE4E0u;
label_1ae4e0:
    // 0x1ae4e0: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1AE4E0u;
    {
        const bool branch_taken_0x1ae4e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE4E0u;
            // 0x1ae4e4: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae4e0) {
            ctx->pc = 0x1AE544u;
            goto label_1ae544;
        }
    }
    ctx->pc = 0x1AE4E8u;
    // 0x1ae4e8: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1ae4e8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1ae4ec: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1ae4ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae4f0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1AE4F0u;
    {
        const bool branch_taken_0x1ae4f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE4F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE4F0u;
            // 0x1ae4f4: 0x26108dc8  addiu       $s0, $s0, -0x7238 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294938056));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae4f0) {
            ctx->pc = 0x1AE534u;
            goto label_1ae534;
        }
    }
    ctx->pc = 0x1AE4F8u;
label_1ae4f8:
    // 0x1ae4f8: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x1AE4F8u;
    {
        const bool branch_taken_0x1ae4f8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae4f8) {
            ctx->pc = 0x1AE52Cu;
            goto label_1ae52c;
        }
    }
    ctx->pc = 0x1AE500u;
    // 0x1ae500: 0xc04c7be  jal         func_131EF8
    ctx->pc = 0x1AE500u;
    SET_GPR_U32(ctx, 31, 0x1AE508u);
    ctx->pc = 0x1AE504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE500u;
            // 0x1ae504: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131EF8u;
    if (runtime->hasFunction(0x131EF8u)) {
        auto targetFn = runtime->lookupFunction(0x131EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE508u; }
        if (ctx->pc != 0x1AE508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE508u; }
        if (ctx->pc != 0x1AE508u) { return; }
    }
    ctx->pc = 0x1AE508u;
label_1ae508:
    // 0x1ae508: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ae508u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ae50c: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE50Cu;
    {
        const bool branch_taken_0x1ae50c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AE510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE50Cu;
            // 0x1ae510: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae50c) {
            ctx->pc = 0x1AE51Cu;
            goto label_1ae51c;
        }
    }
    ctx->pc = 0x1AE514u;
    // 0x1ae514: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AE514u;
    {
        const bool branch_taken_0x1ae514 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1ae514) {
            ctx->pc = 0x1AE52Cu;
            goto label_1ae52c;
        }
    }
    ctx->pc = 0x1AE51Cu;
label_1ae51c:
    // 0x1ae51c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ae51cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ae520: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ae520u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ae524: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AE524u;
    {
        const bool branch_taken_0x1ae524 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE524u;
            // 0x1ae528: 0xa02243ff  sb          $v0, 0x43FF($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17407), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae524) {
            ctx->pc = 0x1AE540u;
            goto label_1ae540;
        }
    }
    ctx->pc = 0x1AE52Cu;
label_1ae52c:
    // 0x1ae52c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1ae52cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1ae530: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1ae530u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
label_1ae534:
    // 0x1ae534: 0x2a220003  slti        $v0, $s1, 0x3
    ctx->pc = 0x1ae534u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1ae538: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1AE538u;
    {
        const bool branch_taken_0x1ae538 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ae538) {
            ctx->pc = 0x1AE4F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ae4f8;
        }
    }
    ctx->pc = 0x1AE540u;
label_1ae540:
    // 0x1ae540: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1ae540u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ae544:
    // 0x1ae544: 0x141840  sll         $v1, $s4, 1
    ctx->pc = 0x1ae544u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
label_1ae548:
    // 0x1ae548: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae548u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae54c: 0x741821  addu        $v1, $v1, $s4
    ctx->pc = 0x1ae54cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x1ae550: 0x24428d70  addiu       $v0, $v0, -0x7290
    ctx->pc = 0x1ae550u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937968));
    // 0x1ae554: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1ae554u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae558: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1ae558u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae55c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1ae55cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ae560: 0x14400049  bnez        $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x1AE560u;
    {
        const bool branch_taken_0x1ae560 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ae560) {
            ctx->pc = 0x1AE688u;
            goto label_1ae688;
        }
    }
    ctx->pc = 0x1AE568u;
    // 0x1ae568: 0xc602000c  lwc1        $f2, 0xC($s0)
    ctx->pc = 0x1ae568u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1ae56c: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x1ae56cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1ae570: 0x0  nop
    ctx->pc = 0x1ae570u;
    // NOP
    // 0x1ae574: 0x46020832  c.eq.s      $f1, $f2
    ctx->pc = 0x1ae574u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[1], ctx->f[2])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ae578: 0x45010043  bc1t        . + 4 + (0x43 << 2)
    ctx->pc = 0x1AE578u;
    {
        const bool branch_taken_0x1ae578 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1AE57Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE578u;
            // 0x1ae57c: 0x2612000c  addiu       $s2, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae578) {
            ctx->pc = 0x1AE688u;
            goto label_1ae688;
        }
    }
    ctx->pc = 0x1AE580u;
    // 0x1ae580: 0xc6000010  lwc1        $f0, 0x10($s0)
    ctx->pc = 0x1ae580u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1ae584: 0x46020500  add.s       $f20, $f0, $f2
    ctx->pc = 0x1ae584u;
    ctx->f[20] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x1ae588: 0x4601a034  c.lt.s      $f20, $f1
    ctx->pc = 0x1ae588u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[20], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ae58c: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1AE58Cu;
    {
        const bool branch_taken_0x1ae58c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1AE590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE58Cu;
            // 0x1ae590: 0x26110010  addiu       $s1, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae58c) {
            ctx->pc = 0x1AE598u;
            goto label_1ae598;
        }
    }
    ctx->pc = 0x1AE594u;
    // 0x1ae594: 0x46000d06  mov.s       $f20, $f1
    ctx->pc = 0x1ae594u;
    ctx->f[20] = FPU_MOV_S(ctx->f[1]);
label_1ae598:
    // 0x1ae598: 0x3c0242fe  lui         $v0, 0x42FE
    ctx->pc = 0x1ae598u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17150 << 16));
    // 0x1ae59c: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x1ae59cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1ae5a0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ae5a0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ae5a4: 0x0  nop
    ctx->pc = 0x1ae5a4u;
    // NOP
    // 0x1ae5a8: 0x4600a083  div.s       $f2, $f20, $f0
    ctx->pc = 0x1ae5a8u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[20] / ctx->f[0];
    // 0x1ae5ac: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1ae5acu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ae5b0: 0x0  nop
    ctx->pc = 0x1ae5b0u;
    // NOP
    // 0x1ae5b4: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x1ae5b4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1ae5b8: 0x46011002  mul.s       $f0, $f2, $f1
    ctx->pc = 0x1ae5b8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x1ae5bc: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ae5bcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1ae5c0: 0x44130000  mfc1        $s3, $f0
    ctx->pc = 0x1ae5c0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 19, bits); }
    // 0x1ae5c4: 0x0  nop
    ctx->pc = 0x1ae5c4u;
    // NOP
    // 0x1ae5c8: 0x73082a  slt         $at, $v1, $s3
    ctx->pc = 0x1ae5c8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x1ae5cc: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE5CCu;
    {
        const bool branch_taken_0x1ae5cc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae5cc) {
            ctx->pc = 0x1AE5DCu;
            goto label_1ae5dc;
        }
    }
    ctx->pc = 0x1AE5D4u;
    // 0x1ae5d4: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x1ae5d4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae5d8: 0x46000d06  mov.s       $f20, $f1
    ctx->pc = 0x1ae5d8u;
    ctx->f[20] = FPU_MOV_S(ctx->f[1]);
label_1ae5dc:
    // 0x1ae5dc: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1ae5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1ae5e0: 0x12620012  beq         $s3, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AE5E0u;
    {
        const bool branch_taken_0x1ae5e0 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 2));
        ctx->pc = 0x1AE5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE5E0u;
            // 0x1ae5e4: 0x3c02002c  lui         $v0, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae5e0) {
            ctx->pc = 0x1AE62Cu;
            goto label_1ae62c;
        }
    }
    ctx->pc = 0x1AE5E8u;
    // 0x1ae5e8: 0x141880  sll         $v1, $s4, 2
    ctx->pc = 0x1ae5e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
    // 0x1ae5ec: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae5f0: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1ae5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae5f4: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1ae5f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ae5f8: 0x3262007f  andi        $v0, $s3, 0x7F
    ctx->pc = 0x1ae5f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)127);
    // 0x1ae5fc: 0x22880  sll         $a1, $v0, 2
    ctx->pc = 0x1ae5fcu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ae600: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1ae600u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1ae604: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1ae604u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1ae608: 0x24634060  addiu       $v1, $v1, 0x4060
    ctx->pc = 0x1ae608u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16480));
    // 0x1ae60c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1ae60cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1ae610: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1ae610u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ae614: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1ae614u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ae618: 0x0  nop
    ctx->pc = 0x1ae618u;
    // NOP
    // 0x1ae61c: 0x0  nop
    ctx->pc = 0x1ae61cu;
    // NOP
    // 0x1ae620: 0x2812  mflo        $a1
    ctx->pc = 0x1ae620u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x1ae624: 0xc04c9ee  jal         func_1327B8
    ctx->pc = 0x1AE624u;
    SET_GPR_U32(ctx, 31, 0x1AE62Cu);
    ctx->pc = 0x1327B8u;
    if (runtime->hasFunction(0x1327B8u)) {
        auto targetFn = runtime->lookupFunction(0x1327B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE62Cu; }
        if (ctx->pc != 0x1AE62Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001327B8_0x1327b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE62Cu; }
        if (ctx->pc != 0x1AE62Cu) { return; }
    }
    ctx->pc = 0x1AE62Cu;
label_1ae62c:
    // 0x1ae62c: 0xae130004  sw          $s3, 0x4($s0)
    ctx->pc = 0x1ae62cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 19));
    // 0x1ae630: 0xe6340000  swc1        $f20, 0x0($s1)
    ctx->pc = 0x1ae630u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x1ae634: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x1ae634u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1ae638: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1ae638u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1ae63c: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x1ae63cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1ae640: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AE640u;
    {
        const bool branch_taken_0x1ae640 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE640u;
            // 0x1ae644: 0x83082a  slt         $at, $a0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae640) {
            ctx->pc = 0x1AE664u;
            goto label_1ae664;
        }
    }
    ctx->pc = 0x1AE648u;
    // 0x1ae648: 0xc6410000  lwc1        $f1, 0x0($s2)
    ctx->pc = 0x1ae648u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ae64c: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1ae64cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ae650: 0x0  nop
    ctx->pc = 0x1ae650u;
    // NOP
    // 0x1ae654: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1ae654u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ae658: 0x4500000a  bc1f        . + 4 + (0xA << 2)
    ctx->pc = 0x1AE658u;
    {
        const bool branch_taken_0x1ae658 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x1ae658) {
            ctx->pc = 0x1AE684u;
            goto label_1ae684;
        }
    }
    ctx->pc = 0x1AE660u;
    // 0x1ae660: 0x83082a  slt         $at, $a0, $v1
    ctx->pc = 0x1ae660u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
label_1ae664:
    // 0x1ae664: 0x14200008  bnez        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1AE664u;
    {
        const bool branch_taken_0x1ae664 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ae664) {
            ctx->pc = 0x1AE688u;
            goto label_1ae688;
        }
    }
    ctx->pc = 0x1AE66Cu;
    // 0x1ae66c: 0xc6410000  lwc1        $f1, 0x0($s2)
    ctx->pc = 0x1ae66cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ae670: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1ae670u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ae674: 0x0  nop
    ctx->pc = 0x1ae674u;
    // NOP
    // 0x1ae678: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1ae678u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ae67c: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1AE67Cu;
    {
        const bool branch_taken_0x1ae67c = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x1ae67c) {
            ctx->pc = 0x1AE688u;
            goto label_1ae688;
        }
    }
    ctx->pc = 0x1AE684u;
label_1ae684:
    // 0x1ae684: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1ae684u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
label_1ae688:
    // 0x1ae688: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1ae688u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1ae68c: 0x2a820003  slti        $v0, $s4, 0x3
    ctx->pc = 0x1ae68cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1ae690: 0x1440ffad  bnez        $v0, . + 4 + (-0x53 << 2)
    ctx->pc = 0x1AE690u;
    {
        const bool branch_taken_0x1ae690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AE694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE690u;
            // 0x1ae694: 0x141840  sll         $v1, $s4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae690) {
            ctx->pc = 0x1AE548u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ae548;
        }
    }
    ctx->pc = 0x1AE698u;
    // 0x1ae698: 0xc04afbe  jal         func_12BEF8
    ctx->pc = 0x1AE698u;
    SET_GPR_U32(ctx, 31, 0x1AE6A0u);
    ctx->pc = 0x12BEF8u;
    if (runtime->hasFunction(0x12BEF8u)) {
        auto targetFn = runtime->lookupFunction(0x12BEF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE6A0u; }
        if (ctx->pc != 0x1AE6A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BEF8_0x12bef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE6A0u; }
        if (ctx->pc != 0x1AE6A0u) { return; }
    }
    ctx->pc = 0x1AE6A0u;
label_1ae6a0:
    // 0x1ae6a0: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1ae6a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ae6a4: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1ae6a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1ae6a8: 0x7bb40050  lq          $s4, 0x50($sp)
    ctx->pc = 0x1ae6a8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ae6ac: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x1ae6acu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ae6b0: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1ae6b0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ae6b4: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1ae6b4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ae6b8: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1ae6b8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae6bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE6BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE6C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE6BCu;
            // 0x1ae6c0: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE4E0u: goto label_1ae4e0;
            case 0x1AE4F8u: goto label_1ae4f8;
            case 0x1AE508u: goto label_1ae508;
            case 0x1AE51Cu: goto label_1ae51c;
            case 0x1AE52Cu: goto label_1ae52c;
            case 0x1AE534u: goto label_1ae534;
            case 0x1AE540u: goto label_1ae540;
            case 0x1AE544u: goto label_1ae544;
            case 0x1AE548u: goto label_1ae548;
            case 0x1AE598u: goto label_1ae598;
            case 0x1AE5DCu: goto label_1ae5dc;
            case 0x1AE62Cu: goto label_1ae62c;
            case 0x1AE664u: goto label_1ae664;
            case 0x1AE684u: goto label_1ae684;
            case 0x1AE688u: goto label_1ae688;
            case 0x1AE6A0u: goto label_1ae6a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE6C4u;
    // 0x1ae6c4: 0x0  nop
    ctx->pc = 0x1ae6c4u;
    // NOP
    // 0x1ae6c8: 0x0  nop
    ctx->pc = 0x1ae6c8u;
    // NOP
    // 0x1ae6cc: 0x0  nop
    ctx->pc = 0x1ae6ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
