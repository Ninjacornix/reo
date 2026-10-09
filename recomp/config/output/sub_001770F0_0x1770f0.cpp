#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001770F0
// Address: 0x1770f0 - 0x177240
void sub_001770F0_0x1770f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001770F0_0x1770f0");
#endif

    switch (ctx->pc) {
        case 0x177138u: goto label_177138;
        case 0x177180u: goto label_177180;
        case 0x177200u: goto label_177200;
        default: break;
    }

    ctx->pc = 0x1770f0u;

    // 0x1770f0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1770f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1770f4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1770f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1770f8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1770f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1770fc: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1770fcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177100: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x177100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x177104: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x177104u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177108: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x177108u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17710c: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x17710cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x177110: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x177110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x177114: 0x100802d  daddu       $s0, $t0, $zero
    ctx->pc = 0x177114u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177118: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x177118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17711c: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x17711cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177120: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x177120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x177124: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x177124u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177128: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x177128u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x17712c: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17712cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x177130: 0xc05d8d4  jal         func_176350
    ctx->pc = 0x177130u;
    SET_GPR_U32(ctx, 31, 0x177138u);
    ctx->pc = 0x177134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177130u;
            // 0x177134: 0x2455f138  addiu       $s5, $v0, -0xEC8 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176350u;
    if (runtime->hasFunction(0x176350u)) {
        auto targetFn = runtime->lookupFunction(0x176350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177138u; }
        if (ctx->pc != 0x177138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176350_0x176350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177138u; }
        if (ctx->pc != 0x177138u) { return; }
    }
    ctx->pc = 0x177138u;
label_177138:
    // 0x177138: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x177138u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x17713c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x17713cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177140: 0x3c01461c  lui         $at, 0x461C
    ctx->pc = 0x177140u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17948 << 16));
    // 0x177144: 0x34214000  ori         $at, $at, 0x4000
    ctx->pc = 0x177144u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)16384);
    // 0x177148: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x177148u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x17714c: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x17714cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x177150: 0x1446000d  bne         $v0, $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x177150u;
    {
        const bool branch_taken_0x177150 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 6));
        ctx->pc = 0x177154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177150u;
            // 0x177154: 0x502018  mult        $a0, $v0, $s0 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x177150) {
            ctx->pc = 0x177188u;
            goto label_177188;
        }
    }
    ctx->pc = 0x177158u;
    // 0x177158: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x177158u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17715c: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17715Cu;
    {
        const bool branch_taken_0x17715c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x17715c) {
            ctx->pc = 0x177160u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17715Cu;
            // 0x177160: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x177170u;
            goto label_177170;
        }
    }
    ctx->pc = 0x177164u;
    // 0x177164: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x177164u;
    {
        const bool branch_taken_0x177164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177164u;
            // 0x177168: 0xae260000  sw          $a2, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177164) {
            ctx->pc = 0x177218u;
            goto label_177218;
        }
    }
    ctx->pc = 0x17716Cu;
    // 0x17716c: 0x0  nop
    ctx->pc = 0x17716cu;
    // NOP
label_177170:
    // 0x177170: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x177170u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177174: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x177174u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177178: 0xc05dc90  jal         func_177240
    ctx->pc = 0x177178u;
    SET_GPR_U32(ctx, 31, 0x177180u);
    ctx->pc = 0x17717Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177178u;
            // 0x17717c: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177240u;
    if (runtime->hasFunction(0x177240u)) {
        auto targetFn = runtime->lookupFunction(0x177240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177180u; }
        if (ctx->pc != 0x177180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177240_0x177240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177180u; }
        if (ctx->pc != 0x177180u) { return; }
    }
    ctx->pc = 0x177180u;
label_177180:
    // 0x177180: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x177180u;
    {
        const bool branch_taken_0x177180 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177180u;
            // 0x177184: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177180) {
            ctx->pc = 0x17721Cu;
            goto label_17721c;
        }
    }
    ctx->pc = 0x177188u;
label_177188:
    // 0x177188: 0x8ea30008  lw          $v1, 0x8($s5)
    ctx->pc = 0x177188u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x17718c: 0x44930000  mtc1        $s3, $f0
    ctx->pc = 0x17718cu;
    { uint32_t bits = GPR_U32(ctx, 19); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x177190: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x177190u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x177194: 0x44940800  mtc1        $s4, $f1
    ctx->pc = 0x177194u;
    { uint32_t bits = GPR_U32(ctx, 20); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x177198: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x177198u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x17719c: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x17719cu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1771a0: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1771A0u;
    {
        const bool branch_taken_0x1771a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1771a0) {
            ctx->pc = 0x1771A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1771A0u;
            // 0x1771a4: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1771A8u;
            goto label_1771a8;
        }
    }
    ctx->pc = 0x1771A8u;
label_1771a8:
    // 0x1771a8: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x1771a8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1771ac: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1771acu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1771b0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1771b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1771b4: 0x46030002  mul.s       $f0, $f0, $f3
    ctx->pc = 0x1771b4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[3]);
    // 0x1771b8: 0x8e4509dc  lw          $a1, 0x9DC($s2)
    ctx->pc = 0x1771b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2524)));
    // 0x1771bc: 0x0  nop
    ctx->pc = 0x1771bcu;
    // NOP
    // 0x1771c0: 0x0  nop
    ctx->pc = 0x1771c0u;
    // NOP
    // 0x1771c4: 0x46010043  div.s       $f1, $f0, $f1
    ctx->pc = 0x1771c4u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[0] / ctx->f[1];
    // 0x1771c8: 0x46000b06  mov.s       $f12, $f1
    ctx->pc = 0x1771c8u;
    ctx->f[12] = FPU_MOV_S(ctx->f[1]);
    // 0x1771cc: 0x1812  mflo        $v1
    ctx->pc = 0x1771ccu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1771d0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1771d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1771d4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1771d4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1771d8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1771d8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1771dc: 0x46030002  mul.s       $f0, $f0, $f3
    ctx->pc = 0x1771dcu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[3]);
    // 0x1771e0: 0x0  nop
    ctx->pc = 0x1771e0u;
    // NOP
    // 0x1771e4: 0x0  nop
    ctx->pc = 0x1771e4u;
    // NOP
    // 0x1771e8: 0x46020343  div.s       $f13, $f0, $f2
    ctx->pc = 0x1771e8u;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[13] = std::bit_cast<float>(__maxf); } else ctx->f[13] = ctx->f[0] / ctx->f[2];
    // 0x1771ec: 0x10a60006  beq         $a1, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1771ECu;
    {
        const bool branch_taken_0x1771ec = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        ctx->pc = 0x1771F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1771ECu;
            // 0x1771f0: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1771ec) {
            ctx->pc = 0x177208u;
            goto label_177208;
        }
    }
    ctx->pc = 0x1771F4u;
    // 0x1771f4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1771f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1771f8: 0xc05dcae  jal         func_1772B8
    ctx->pc = 0x1771F8u;
    SET_GPR_U32(ctx, 31, 0x177200u);
    ctx->pc = 0x1771FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1771F8u;
            // 0x1771fc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1772B8u;
    if (runtime->hasFunction(0x1772B8u)) {
        auto targetFn = runtime->lookupFunction(0x1772B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177200u; }
        if (ctx->pc != 0x177200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001772B8_0x1772b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177200u; }
        if (ctx->pc != 0x177200u) { return; }
    }
    ctx->pc = 0x177200u;
label_177200:
    // 0x177200: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x177200u;
    {
        const bool branch_taken_0x177200 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177200u;
            // 0x177204: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177200) {
            ctx->pc = 0x17721Cu;
            goto label_17721c;
        }
    }
    ctx->pc = 0x177208u;
label_177208:
    // 0x177208: 0x460d0836  c.le.s      $f1, $f13
    ctx->pc = 0x177208u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[13])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17720c: 0x45020002  bc1fl       . + 4 + (0x2 << 2)
    ctx->pc = 0x17720Cu;
    {
        const bool branch_taken_0x17720c = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x17720c) {
            ctx->pc = 0x177210u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17720Cu;
            // 0x177210: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x177218u;
            goto label_177218;
        }
    }
    ctx->pc = 0x177214u;
    // 0x177214: 0xae250000  sw          $a1, 0x0($s1)
    ctx->pc = 0x177214u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 5));
label_177218:
    // 0x177218: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x177218u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_17721c:
    // 0x17721c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17721cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x177220: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x177220u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x177224: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x177224u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x177228: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x177228u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17722c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x17722cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x177230: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x177230u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x177234: 0x3e00008  jr          $ra
    ctx->pc = 0x177234u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177234u;
            // 0x177238: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177138u: goto label_177138;
            case 0x177170u: goto label_177170;
            case 0x177180u: goto label_177180;
            case 0x177188u: goto label_177188;
            case 0x1771A8u: goto label_1771a8;
            case 0x177200u: goto label_177200;
            case 0x177208u: goto label_177208;
            case 0x177218u: goto label_177218;
            case 0x17721Cu: goto label_17721c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17723Cu;
    // 0x17723c: 0x0  nop
    ctx->pc = 0x17723cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
