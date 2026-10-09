#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B71D0
// Address: 0x1b71d0 - 0x1b74d0
void sub_001B71D0_0x1b71d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B71D0_0x1b71d0");
#endif

    switch (ctx->pc) {
        case 0x1b7210u: goto label_1b7210;
        default: break;
    }

    ctx->pc = 0x1b71d0u;

    // 0x1b71d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b71d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b71d4: 0x24080014  addiu       $t0, $zero, 0x14
    ctx->pc = 0x1b71d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1b71d8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b71d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b71dc: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b71dcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71e0: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1b71e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1b71e4: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b71e4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71e8: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1b71e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1b71ec: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b71ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71f0: 0x8c8b000c  lw          $t3, 0xC($a0)
    ctx->pc = 0x1b71f0u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1b71f4: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x1b71f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71f8: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1b71f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71fc: 0xffab0000  sd          $t3, 0x0($sp)
    ctx->pc = 0x1b71fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 11));
    // 0x1b7200: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1b7200u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7204: 0x8e260054  lw          $a2, 0x54($s1)
    ctx->pc = 0x1b7204u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x1b7208: 0xc06dbf4  jal         func_1B6FD0
    ctx->pc = 0x1B7208u;
    SET_GPR_U32(ctx, 31, 0x1B7210u);
    ctx->pc = 0x1B720Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7208u;
            // 0x1b720c: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6FD0u;
    if (runtime->hasFunction(0x1B6FD0u)) {
        auto targetFn = runtime->lookupFunction(0x1B6FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7210u; }
        if (ctx->pc != 0x1B7210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6FD0_0x1b6fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7210u; }
        if (ctx->pc != 0x1B7210u) { return; }
    }
    ctx->pc = 0x1B7210u;
label_1b7210:
    // 0x1b7210: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b7210u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b7214: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1b7214u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7218: 0x8c26f9bc  lw          $a2, -0x644($at)
    ctx->pc = 0x1b7218u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965692)));
    // 0x1b721c: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x1b721cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1b7220: 0x461823  subu        $v1, $v0, $a2
    ctx->pc = 0x1b7220u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1b7224: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7224u;
    {
        const bool branch_taken_0x1b7224 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1B7228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7224u;
            // 0x1b7228: 0x31043  sra         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7224) {
            ctx->pc = 0x1B7234u;
            goto label_1b7234;
        }
    }
    ctx->pc = 0x1B722Cu;
    // 0x1b722c: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1b722cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b7230: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1b7230u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1b7234:
    // 0x1b7234: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b7234u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b7238: 0x24041000  addiu       $a0, $zero, 0x1000
    ctx->pc = 0x1b7238u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1b723c: 0x8c23f9c0  lw          $v1, -0x640($at)
    ctx->pc = 0x1b723cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1b7240: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1b7240u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1b7244: 0x832023  subu        $a0, $a0, $v1
    ctx->pc = 0x1b7244u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b7248: 0x4810003  bgez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7248u;
    {
        const bool branch_taken_0x1b7248 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1B724Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7248u;
            // 0x1b724c: 0x41843  sra         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7248) {
            ctx->pc = 0x1B7258u;
            goto label_1b7258;
        }
    }
    ctx->pc = 0x1B7250u;
    // 0x1b7250: 0x24830001  addiu       $v1, $a0, 0x1
    ctx->pc = 0x1b7250u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1b7254: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x1b7254u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
label_1b7258:
    // 0x1b7258: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1b7258u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b725c: 0x34900  sll         $t1, $v1, 4
    ctx->pc = 0x1b725cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1b7260: 0xc6200070  lwc1        $f0, 0x70($s1)
    ctx->pc = 0x1b7260u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b7264: 0x8e23006c  lw          $v1, 0x6C($s1)
    ctx->pc = 0x1b7264u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 108)));
    // 0x1b7268: 0x468008a0  cvt.s.w     $f2, $f1
    ctx->pc = 0x1b7268u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1b726c: 0x3c064420  lui         $a2, 0x4420
    ctx->pc = 0x1b726cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)17440 << 16));
    // 0x1b7270: 0x8e280074  lw          $t0, 0x74($s1)
    ctx->pc = 0x1b7270u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 116)));
    // 0x1b7274: 0x3c044180  lui         $a0, 0x4180
    ctx->pc = 0x1b7274u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16768 << 16));
    // 0x1b7278: 0x8e270098  lw          $a3, 0x98($s1)
    ctx->pc = 0x1b7278u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 152)));
    // 0x1b727c: 0x2031806  srlv        $v1, $v1, $s0
    ctx->pc = 0x1b727cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), GPR_U32(ctx, 16) & 0x1F));
    // 0x1b7280: 0x44860800  mtc1        $a2, $f1
    ctx->pc = 0x1b7280u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b7284: 0x0  nop
    ctx->pc = 0x1b7284u;
    // NOP
    // 0x1b7288: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1b7288u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1b728c: 0x84100  sll         $t0, $t0, 4
    ctx->pc = 0x1b728cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x1b7290: 0x46011083  div.s       $f2, $f2, $f1
    ctx->pc = 0x1b7290u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[2] / ctx->f[1];
    // 0x1b7294: 0x46020042  mul.s       $f1, $f0, $f2
    ctx->pc = 0x1b7294u;
    ctx->f[1] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1b7298: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1b7298u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b729c: 0x0  nop
    ctx->pc = 0x1b729cu;
    // NOP
    // 0x1b72a0: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x1b72a0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1b72a4: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b72a4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b72a8: 0x44060000  mfc1        $a2, $f0
    ctx->pc = 0x1b72a8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x1b72ac: 0x4600004  bltz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B72ACu;
    {
        const bool branch_taken_0x1b72ac = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1B72B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B72ACu;
            // 0x1b72b0: 0x73900  sll         $a3, $a3, 4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b72ac) {
            ctx->pc = 0x1B72C0u;
            goto label_1b72c0;
        }
    }
    ctx->pc = 0x1B72B4u;
    // 0x1b72b4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1b72b4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b72b8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B72B8u;
    {
        const bool branch_taken_0x1b72b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B72BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B72B8u;
            // 0x1b72bc: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b72b8) {
            ctx->pc = 0x1B72DCu;
            goto label_1b72dc;
        }
    }
    ctx->pc = 0x1B72C0u;
label_1b72c0:
    // 0x1b72c0: 0x32042  srl         $a0, $v1, 1
    ctx->pc = 0x1b72c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x1b72c4: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1b72c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1b72c8: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1b72c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1b72cc: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1b72ccu;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b72d0: 0x0  nop
    ctx->pc = 0x1b72d0u;
    // NOP
    // 0x1b72d4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1b72d4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1b72d8: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x1b72d8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_1b72dc:
    // 0x1b72dc: 0x46020082  mul.s       $f2, $f0, $f2
    ctx->pc = 0x1b72dcu;
    ctx->f[2] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1b72e0: 0x3c044180  lui         $a0, 0x4180
    ctx->pc = 0x1b72e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16768 << 16));
    // 0x1b72e4: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1b72e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1b72e8: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1b72e8u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b72ec: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1b72ecu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b72f0: 0x0  nop
    ctx->pc = 0x1b72f0u;
    // NOP
    // 0x1b72f4: 0x46020842  mul.s       $f1, $f1, $f2
    ctx->pc = 0x1b72f4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x1b72f8: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1b72f8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b72fc: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B72FCu;
    {
        const bool branch_taken_0x1b72fc = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b72fc) {
            ctx->pc = 0x1B7314u;
            goto label_1b7314;
        }
    }
    ctx->pc = 0x1B7304u;
    // 0x1b7304: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b7304u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b7308: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1b7308u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1b730c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B730Cu;
    {
        const bool branch_taken_0x1b730c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b730c) {
            ctx->pc = 0x1B732Cu;
            goto label_1b732c;
        }
    }
    ctx->pc = 0x1B7314u;
label_1b7314:
    // 0x1b7314: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1b7314u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1b7318: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1b7318u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1b731c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b731cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b7320: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1b7320u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1b7324: 0x0  nop
    ctx->pc = 0x1b7324u;
    // NOP
    // 0x1b7328: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1b7328u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
label_1b732c:
    // 0x1b732c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b732cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b7330: 0x8c23f9b4  lw          $v1, -0x64C($at)
    ctx->pc = 0x1b7330u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x1b7334: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B7334u;
    {
        const bool branch_taken_0x1b7334 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7334u;
            // 0x1b7338: 0x461821  addu        $v1, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7334) {
            ctx->pc = 0x1B7344u;
            goto label_1b7344;
        }
    }
    ctx->pc = 0x1B733Cu;
    // 0x1b733c: 0x84043  sra         $t0, $t0, 1
    ctx->pc = 0x1b733cu;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
    // 0x1b7340: 0x73842  srl         $a3, $a3, 1
    ctx->pc = 0x1b7340u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 7), 1));
label_1b7344:
    // 0x1b7344: 0x1284021  addu        $t0, $t1, $t0
    ctx->pc = 0x1b7344u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x1b7348: 0x641021  addu        $v0, $v1, $a0
    ctx->pc = 0x1b7348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b734c: 0x3303c  dsll32      $a2, $v1, 0
    ctx->pc = 0x1b734cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b7350: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1b7350u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7354: 0x8203c  dsll32      $a0, $t0, 0
    ctx->pc = 0x1b7354u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 8) << (32 + 0));
    // 0x1b7358: 0x1071021  addu        $v0, $t0, $a3
    ctx->pc = 0x1b7358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x1b735c: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1b735cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1b7360: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1b7360u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7364: 0x8e2d000c  lw          $t5, 0xC($s1)
    ctx->pc = 0x1b7364u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b7368: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1b7368u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1b736c: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x1b736cu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x1b7370: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x1b7370u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x1b7374: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1b7374u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1b7378: 0xc43825  or          $a3, $a2, $a0
    ctx->pc = 0x1b7378u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x1b737c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1b737cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1b7380: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1b7380u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1b7384: 0x3c065100  lui         $a2, 0x5100
    ctx->pc = 0x1b7384u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)20736 << 16));
    // 0x1b7388: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1b7388u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1b738c: 0x34cb0008  ori         $t3, $a2, 0x8
    ctx->pc = 0x1b738cu;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)8);
    // 0x1b7390: 0x344c0008  ori         $t4, $v0, 0x8
    ctx->pc = 0x1b7390u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8);
    // 0x1b7394: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x1b7394u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7398: 0xacac0000  sw          $t4, 0x0($a1)
    ctx->pc = 0x1b7398u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 12));
    // 0x1b739c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1b739cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b73a0: 0xaca00004  sw          $zero, 0x4($a1)
    ctx->pc = 0x1b73a0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 0));
    // 0x1b73a4: 0x435025  or          $t2, $v0, $v1
    ctx->pc = 0x1b73a4u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1b73a8: 0xaca00008  sw          $zero, 0x8($a1)
    ctx->pc = 0x1b73a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 0));
    // 0x1b73ac: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1b73acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1b73b0: 0xacab000c  sw          $t3, 0xC($a1)
    ctx->pc = 0x1b73b0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 11));
    // 0x1b73b4: 0x3c025540  lui         $v0, 0x5540
    ctx->pc = 0x1b73b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21824 << 16));
    // 0x1b73b8: 0x2409000e  addiu       $t1, $zero, 0xE
    ctx->pc = 0x1b73b8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1b73bc: 0xfcaa0010  sd          $t2, 0x10($a1)
    ctx->pc = 0x1b73bcu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 10));
    // 0x1b73c0: 0xfca90018  sd          $t1, 0x18($a1)
    ctx->pc = 0x1b73c0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 9));
    // 0x1b73c4: 0xd6100  sll         $t4, $t5, 4
    ctx->pc = 0x1b73c4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 13), 4));
    // 0x1b73c8: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1b73c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b73cc: 0x34424000  ori         $v0, $v0, 0x4000
    ctx->pc = 0x1b73ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16384);
    // 0x1b73d0: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x1b73d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1b73d4: 0x2408003f  addiu       $t0, $zero, 0x3F
    ctx->pc = 0x1b73d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x1b73d8: 0xfca00020  sd          $zero, 0x20($a1)
    ctx->pc = 0x1b73d8u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 32), GPR_U64(ctx, 0));
    // 0x1b73dc: 0x20c1006  srlv        $v0, $t4, $s0
    ctx->pc = 0x1b73dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 12), GPR_U32(ctx, 16) & 0x1F));
    // 0x1b73e0: 0xfca80028  sd          $t0, 0x28($a1)
    ctx->pc = 0x1b73e0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 40), GPR_U64(ctx, 8));
    // 0x1b73e4: 0x24460008  addiu       $a2, $v0, 0x8
    ctx->pc = 0x1b73e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1b73e8: 0x9e300054  lwu         $s0, 0x54($s1)
    ctx->pc = 0x1b73e8u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x1b73ec: 0x25820008  addiu       $v0, $t4, 0x8
    ctx->pc = 0x1b73ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), 8));
    // 0x1b73f0: 0x8e390058  lw          $t9, 0x58($s1)
    ctx->pc = 0x1b73f0u;
    SET_GPR_S32(ctx, 25, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x1b73f4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1b73f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b73f8: 0x8e38007c  lw          $t8, 0x7C($s1)
    ctx->pc = 0x1b73f8u;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 124)));
    // 0x1b73fc: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x1b73fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1b7400: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1b7400u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1b7404: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x1b7404u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x1b7408: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1b7408u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1b740c: 0x240e0006  addiu       $t6, $zero, 0x6
    ctx->pc = 0x1b740cu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1b7410: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x1b7410u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x1b7414: 0x240d0060  addiu       $t5, $zero, 0x60
    ctx->pc = 0x1b7414u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1b7418: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x1b7418u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x1b741c: 0x2031825  or          $v1, $s0, $v1
    ctx->pc = 0x1b741cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) | GPR_U64(ctx, 3));
    // 0x1b7420: 0x2783c  dsll32      $t7, $v0, 0
    ctx->pc = 0x1b7420u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7424: 0x240c0014  addiu       $t4, $zero, 0x14
    ctx->pc = 0x1b7424u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1b7428: 0x338c021  addu        $t8, $t9, $t8
    ctx->pc = 0x1b7428u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 25), GPR_U32(ctx, 24)));
    // 0x1b742c: 0x3c026400  lui         $v0, 0x6400
    ctx->pc = 0x1b742cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)25600 << 16));
    // 0x1b7430: 0x18803c  dsll32      $s0, $t8, 0
    ctx->pc = 0x1b7430u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 24) << (32 + 0));
    // 0x1b7434: 0x2403c  dsll32      $t0, $v0, 0
    ctx->pc = 0x1b7434u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7438: 0x10803e  dsrl32      $s0, $s0, 0
    ctx->pc = 0x1b7438u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 0));
    // 0x1b743c: 0x34028001  ori         $v0, $zero, 0x8001
    ctx->pc = 0x1b743cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x1b7440: 0x485825  or          $t3, $v0, $t0
    ctx->pc = 0x1b7440u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 2) | GPR_U64(ctx, 8));
    // 0x1b7444: 0x10817c  dsll32      $s0, $s0, 5
    ctx->pc = 0x1b7444u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 5));
    // 0x1b7448: 0x701825  or          $v1, $v1, $s0
    ctx->pc = 0x1b7448u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 16));
    // 0x1b744c: 0x3c020053  lui         $v0, 0x53
    ctx->pc = 0x1b744cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)83 << 16));
    // 0x1b7450: 0x6f1825  or          $v1, $v1, $t7
    ctx->pc = 0x1b7450u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 15));
    // 0x1b7454: 0x344a5310  ori         $t2, $v0, 0x5310
    ctx->pc = 0x1b7454u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)21264);
    // 0x1b7458: 0xfca30030  sd          $v1, 0x30($a1)
    ctx->pc = 0x1b7458u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 48), GPR_U64(ctx, 3));
    // 0x1b745c: 0x24090156  addiu       $t1, $zero, 0x156
    ctx->pc = 0x1b745cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 342));
    // 0x1b7460: 0xfcae0038  sd          $t6, 0x38($a1)
    ctx->pc = 0x1b7460u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 56), GPR_U64(ctx, 14));
    // 0x1b7464: 0x3c080008  lui         $t0, 0x8
    ctx->pc = 0x1b7464u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)8 << 16));
    // 0x1b7468: 0xfcad0040  sd          $t5, 0x40($a1)
    ctx->pc = 0x1b7468u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 64), GPR_U64(ctx, 13));
    // 0x1b746c: 0x35080008  ori         $t0, $t0, 0x8
    ctx->pc = 0x1b746cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)8);
    // 0x1b7470: 0xfcac0048  sd          $t4, 0x48($a1)
    ctx->pc = 0x1b7470u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 72), GPR_U64(ctx, 12));
    // 0x1b7474: 0x24a20090  addiu       $v0, $a1, 0x90
    ctx->pc = 0x1b7474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 144));
    // 0x1b7478: 0xfcab0050  sd          $t3, 0x50($a1)
    ctx->pc = 0x1b7478u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 80), GPR_U64(ctx, 11));
    // 0x1b747c: 0xfcaa0058  sd          $t2, 0x58($a1)
    ctx->pc = 0x1b747cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 88), GPR_U64(ctx, 10));
    // 0x1b7480: 0xfca90060  sd          $t1, 0x60($a1)
    ctx->pc = 0x1b7480u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 96), GPR_U64(ctx, 9));
    // 0x1b7484: 0x9e230080  lwu         $v1, 0x80($s1)
    ctx->pc = 0x1b7484u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 128)));
    // 0x1b7488: 0xfca30068  sd          $v1, 0x68($a1)
    ctx->pc = 0x1b7488u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 104), GPR_U64(ctx, 3));
    // 0x1b748c: 0xfca80070  sd          $t0, 0x70($a1)
    ctx->pc = 0x1b748cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 112), GPR_U64(ctx, 8));
    // 0x1b7490: 0x9e230078  lwu         $v1, 0x78($s1)
    ctx->pc = 0x1b7490u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 120)));
    // 0x1b7494: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1b7494u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b7498: 0x671825  or          $v1, $v1, $a3
    ctx->pc = 0x1b7498u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 7));
    // 0x1b749c: 0xfca30078  sd          $v1, 0x78($a1)
    ctx->pc = 0x1b749cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 120), GPR_U64(ctx, 3));
    // 0x1b74a0: 0xfca60080  sd          $a2, 0x80($a1)
    ctx->pc = 0x1b74a0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 128), GPR_U64(ctx, 6));
    // 0x1b74a4: 0x9e230078  lwu         $v1, 0x78($s1)
    ctx->pc = 0x1b74a4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 120)));
    // 0x1b74a8: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1b74a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b74ac: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1b74acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1b74b0: 0xfca30088  sd          $v1, 0x88($a1)
    ctx->pc = 0x1b74b0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 136), GPR_U64(ctx, 3));
    // 0x1b74b4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b74b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b74b8: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1b74b8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b74bc: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1b74bcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b74c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B74C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B74C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B74C0u;
            // 0x1b74c4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7210u: goto label_1b7210;
            case 0x1B7234u: goto label_1b7234;
            case 0x1B7258u: goto label_1b7258;
            case 0x1B72C0u: goto label_1b72c0;
            case 0x1B72DCu: goto label_1b72dc;
            case 0x1B7314u: goto label_1b7314;
            case 0x1B732Cu: goto label_1b732c;
            case 0x1B7344u: goto label_1b7344;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B74C8u;
    // 0x1b74c8: 0x0  nop
    ctx->pc = 0x1b74c8u;
    // NOP
    // 0x1b74cc: 0x0  nop
    ctx->pc = 0x1b74ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
