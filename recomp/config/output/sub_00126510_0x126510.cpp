#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126510
// Address: 0x126510 - 0x126670
void sub_00126510_0x126510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126510_0x126510");
#endif

    switch (ctx->pc) {
        case 0x126570u: goto label_126570;
        case 0x1265a8u: goto label_1265a8;
        case 0x1265c4u: goto label_1265c4;
        case 0x126600u: goto label_126600;
        default: break;
    }

    ctx->pc = 0x126510u;

    // 0x126510: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x126510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x126514: 0xe7b60038  swc1        $f22, 0x38($sp)
    ctx->pc = 0x126514u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 56), bits); }
    // 0x126518: 0x3c014000  lui         $at, 0x4000
    ctx->pc = 0x126518u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16384 << 16));
    // 0x12651c: 0x4481b000  mtc1        $at, $f22
    ctx->pc = 0x12651cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[22], &bits, sizeof(bits)); }
    // 0x126520: 0xe7b40028  swc1        $f20, 0x28($sp)
    ctx->pc = 0x126520u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x126524: 0x0  nop
    ctx->pc = 0x126524u;
    // NOP
    // 0x126528: 0x0  nop
    ctx->pc = 0x126528u;
    // NOP
    // 0x12652c: 0x46160504  c1          0x160504
    ctx->pc = 0x12652cu;
    ctx->f[20] = FPU_SQRT_S(ctx->f[0]);
    // 0x126530: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x126530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x126534: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x126534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x126538: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x126538u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12653c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12653cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x126540: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x126540u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126544: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x126544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x126548: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x126548u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12654c: 0xe7b50030  swc1        $f21, 0x30($sp)
    ctx->pc = 0x12654cu;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x126550: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x126550u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126554: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x126554u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x126558: 0x4600b306  mov.s       $f12, $f22
    ctx->pc = 0x126558u;
    ctx->f[12] = FPU_MOV_S(ctx->f[22]);
    // 0x12655c: 0x4614a032  c.eq.s      $f20, $f20
    ctx->pc = 0x12655cu;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[20], ctx->f[20])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x126560: 0x45010004  bc1t        . + 4 + (0x4 << 2)
    ctx->pc = 0x126560u;
    {
        const bool branch_taken_0x126560 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x126564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126560u;
            // 0x126564: 0x4600a546  mov.s       $f21, $f20 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x126560) {
            ctx->pc = 0x126574u;
            goto label_126574;
        }
    }
    ctx->pc = 0x126568u;
    // 0x126568: 0xc0489c2  jal         func_122708
    ctx->pc = 0x126568u;
    SET_GPR_U32(ctx, 31, 0x126570u);
    ctx->pc = 0x122708u;
    if (runtime->hasFunction(0x122708u)) {
        auto targetFn = runtime->lookupFunction(0x122708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126570u; }
        if (ctx->pc != 0x126570u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122708_0x122708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126570u; }
        if (ctx->pc != 0x126570u) { return; }
    }
    ctx->pc = 0x126570u;
label_126570:
    // 0x126570: 0x46000546  mov.s       $f21, $f0
    ctx->pc = 0x126570u;
    ctx->f[21] = FPU_MOV_S(ctx->f[0]);
label_126574:
    // 0x126574: 0x44906000  mtc1        $s0, $f12
    ctx->pc = 0x126574u;
    { uint32_t bits = GPR_U32(ctx, 16); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x126578: 0x46806320  cvt.s.w     $f12, $f12
    ctx->pc = 0x126578u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[12], sizeof(tmp)); ctx->f[12] = FPU_CVT_S_W(tmp); }
    // 0x12657c: 0x3c0140c9  lui         $at, 0x40C9
    ctx->pc = 0x12657cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16585 << 16));
    // 0x126580: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x126580u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x126584: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x126584u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x126588: 0x44910800  mtc1        $s1, $f1
    ctx->pc = 0x126588u;
    { uint32_t bits = GPR_U32(ctx, 17); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x12658c: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x12658cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x126590: 0x46006302  mul.s       $f12, $f12, $f0
    ctx->pc = 0x126590u;
    ctx->f[12] = FPU_MUL_S(ctx->f[12], ctx->f[0]);
    // 0x126594: 0x0  nop
    ctx->pc = 0x126594u;
    // NOP
    // 0x126598: 0x0  nop
    ctx->pc = 0x126598u;
    // NOP
    // 0x12659c: 0x46016303  div.s       $f12, $f12, $f1
    ctx->pc = 0x12659cu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[12]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[12] / ctx->f[1];
    // 0x1265a0: 0xc0488f4  jal         func_1223D0
    ctx->pc = 0x1265A0u;
    SET_GPR_U32(ctx, 31, 0x1265A8u);
    ctx->pc = 0x1223D0u;
    if (runtime->hasFunction(0x1223D0u)) {
        auto targetFn = runtime->lookupFunction(0x1223D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1265A8u; }
        if (ctx->pc != 0x1265A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001223D0_0x1223d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1265A8u; }
        if (ctx->pc != 0x1265A8u) { return; }
    }
    ctx->pc = 0x1265A8u;
label_1265a8:
    // 0x1265a8: 0x4600b306  mov.s       $f12, $f22
    ctx->pc = 0x1265a8u;
    ctx->f[12] = FPU_MOV_S(ctx->f[22]);
    // 0x1265ac: 0x4600a046  mov.s       $f1, $f20
    ctx->pc = 0x1265acu;
    ctx->f[1] = FPU_MOV_S(ctx->f[20]);
    // 0x1265b0: 0x46010832  c.eq.s      $f1, $f1
    ctx->pc = 0x1265b0u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[1], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1265b4: 0x45010004  bc1t        . + 4 + (0x4 << 2)
    ctx->pc = 0x1265B4u;
    {
        const bool branch_taken_0x1265b4 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1265B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1265B4u;
            // 0x1265b8: 0x4600ad41  sub.s       $f21, $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_SUB_S(ctx->f[21], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1265b4) {
            ctx->pc = 0x1265C8u;
            goto label_1265c8;
        }
    }
    ctx->pc = 0x1265BCu;
    // 0x1265bc: 0xc0489c2  jal         func_122708
    ctx->pc = 0x1265BCu;
    SET_GPR_U32(ctx, 31, 0x1265C4u);
    ctx->pc = 0x122708u;
    if (runtime->hasFunction(0x122708u)) {
        auto targetFn = runtime->lookupFunction(0x122708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1265C4u; }
        if (ctx->pc != 0x1265C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122708_0x122708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1265C4u; }
        if (ctx->pc != 0x1265C4u) { return; }
    }
    ctx->pc = 0x1265C4u;
label_1265c4:
    // 0x1265c4: 0x46000046  mov.s       $f1, $f0
    ctx->pc = 0x1265c4u;
    ctx->f[1] = FPU_MOV_S(ctx->f[0]);
label_1265c8:
    // 0x1265c8: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x1265c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x1265cc: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1265ccu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1265d0: 0x46000d01  sub.s       $f20, $f1, $f0
    ctx->pc = 0x1265d0u;
    ctx->f[20] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1265d4: 0x4614a801  sub.s       $f0, $f21, $f20
    ctx->pc = 0x1265d4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[21], ctx->f[20]);
    // 0x1265d8: 0x4614ab00  add.s       $f12, $f21, $f20
    ctx->pc = 0x1265d8u;
    ctx->f[12] = FPU_ADD_S(ctx->f[21], ctx->f[20]);
    // 0x1265dc: 0x46006302  mul.s       $f12, $f12, $f0
    ctx->pc = 0x1265dcu;
    ctx->f[12] = FPU_MUL_S(ctx->f[12], ctx->f[0]);
    // 0x1265e0: 0x0  nop
    ctx->pc = 0x1265e0u;
    // NOP
    // 0x1265e4: 0x0  nop
    ctx->pc = 0x1265e4u;
    // NOP
    // 0x1265e8: 0x460c0004  c1          0xC0004
    ctx->pc = 0x1265e8u;
    ctx->f[0] = FPU_SQRT_S(ctx->f[0]);
    // 0x1265ec: 0x46000032  c.eq.s      $f0, $f0
    ctx->pc = 0x1265ecu;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1265f0: 0x45030004  bc1tl       . + 4 + (0x4 << 2)
    ctx->pc = 0x1265F0u;
    {
        const bool branch_taken_0x1265f0 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1265f0) {
            ctx->pc = 0x1265F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1265F0u;
            // 0x1265f4: 0x4600a801  sub.s       $f0, $f21, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[21], ctx->f[0]);
        ctx->in_delay_slot = false;
            ctx->pc = 0x126604u;
            goto label_126604;
        }
    }
    ctx->pc = 0x1265F8u;
    // 0x1265f8: 0xc0489c2  jal         func_122708
    ctx->pc = 0x1265F8u;
    SET_GPR_U32(ctx, 31, 0x126600u);
    ctx->pc = 0x122708u;
    if (runtime->hasFunction(0x122708u)) {
        auto targetFn = runtime->lookupFunction(0x122708u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126600u; }
        if (ctx->pc != 0x126600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122708_0x122708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126600u; }
        if (ctx->pc != 0x126600u) { return; }
    }
    ctx->pc = 0x126600u;
label_126600:
    // 0x126600: 0x4600a801  sub.s       $f0, $f21, $f0
    ctx->pc = 0x126600u;
    ctx->f[0] = FPU_SUB_S(ctx->f[21], ctx->f[0]);
label_126604:
    // 0x126604: 0xc7b50030  lwc1        $f21, 0x30($sp)
    ctx->pc = 0x126604u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x126608: 0x3c014580  lui         $at, 0x4580
    ctx->pc = 0x126608u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17792 << 16));
    // 0x12660c: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x12660cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x126610: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x126610u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x126614: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x126614u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x126618: 0x0  nop
    ctx->pc = 0x126618u;
    // NOP
    // 0x12661c: 0x0  nop
    ctx->pc = 0x12661cu;
    // NOP
    // 0x126620: 0x46140003  div.s       $f0, $f0, $f20
    ctx->pc = 0x126620u;
    if (ctx->f[20] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[20])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[20];
    // 0x126624: 0xc7b40028  lwc1        $f20, 0x28($sp)
    ctx->pc = 0x126624u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x126628: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x126628u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12662c: 0xc7b60038  lwc1        $f22, 0x38($sp)
    ctx->pc = 0x12662cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x126630: 0x46000047  neg.s       $f1, $f0
    ctx->pc = 0x126630u;
    ctx->f[1] = FPU_NEG_S(ctx->f[0]);
    // 0x126634: 0x46000080  add.s       $f2, $f0, $f0
    ctx->pc = 0x126634u;
    ctx->f[2] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
    // 0x126638: 0x46000842  mul.s       $f1, $f1, $f0
    ctx->pc = 0x126638u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x12663c: 0x46031082  mul.s       $f2, $f2, $f3
    ctx->pc = 0x12663cu;
    ctx->f[2] = FPU_MUL_S(ctx->f[2], ctx->f[3]);
    // 0x126640: 0x46030842  mul.s       $f1, $f1, $f3
    ctx->pc = 0x126640u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[3]);
    // 0x126644: 0x46001024  .word       0x46001024                   # cvt.w.s     $f0, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x126644u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x126648: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x126648u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x12664c: 0x46000824  .word       0x46000824                   # cvt.w.s     $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x12664cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x126650: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x126650u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x126654: 0xa6620000  sh          $v0, 0x0($s3)
    ctx->pc = 0x126654u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x126658: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x126658u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12665c: 0xa6430000  sh          $v1, 0x0($s2)
    ctx->pc = 0x12665cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x126660: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x126660u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x126664: 0x3e00008  jr          $ra
    ctx->pc = 0x126664u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126664u;
            // 0x126668: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126570u: goto label_126570;
            case 0x126574u: goto label_126574;
            case 0x1265A8u: goto label_1265a8;
            case 0x1265C4u: goto label_1265c4;
            case 0x1265C8u: goto label_1265c8;
            case 0x126600u: goto label_126600;
            case 0x126604u: goto label_126604;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12666Cu;
    // 0x12666c: 0x0  nop
    ctx->pc = 0x12666cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
