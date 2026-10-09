#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE0C0
// Address: 0x1ae0c0 - 0x1ae1e0
void sub_001AE0C0_0x1ae0c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE0C0_0x1ae0c0");
#endif

    switch (ctx->pc) {
        case 0x1ae118u: goto label_1ae118;
        case 0x1ae1ccu: goto label_1ae1cc;
        default: break;
    }

    ctx->pc = 0x1ae0c0u;

    // 0x1ae0c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1ae0c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ae0c4: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae0c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae0c8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ae0c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ae0cc: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae0d0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ae0d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ae0d4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1ae0d4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae0d8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae0d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae0dc: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1ae0dcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae0e0: 0x30b0007f  andi        $s0, $a1, 0x7F
    ctx->pc = 0x1ae0e0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)127);
    // 0x1ae0e4: 0x442021  addu        $a0, $v0, $a0
    ctx->pc = 0x1ae0e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ae0e8: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1ae0e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ae0ec: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1ae0ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1ae0f0: 0x24424060  addiu       $v0, $v0, 0x4060
    ctx->pc = 0x1ae0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16480));
    // 0x1ae0f4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae0f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae0f8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ae0f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae0fc: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1ae0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1ae100: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1ae100u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ae104: 0x0  nop
    ctx->pc = 0x1ae104u;
    // NOP
    // 0x1ae108: 0x0  nop
    ctx->pc = 0x1ae108u;
    // NOP
    // 0x1ae10c: 0x2812  mflo        $a1
    ctx->pc = 0x1ae10cu;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x1ae110: 0xc04c9ee  jal         func_1327B8
    ctx->pc = 0x1AE110u;
    SET_GPR_U32(ctx, 31, 0x1AE118u);
    ctx->pc = 0x1AE114u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE110u;
            // 0x1ae114: 0x8c840000  lw          $a0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1327B8u;
    if (runtime->hasFunction(0x1327B8u)) {
        auto targetFn = runtime->lookupFunction(0x1327B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE118u; }
        if (ctx->pc != 0x1AE118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001327B8_0x1327b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE118u; }
        if (ctx->pc != 0x1AE118u) { return; }
    }
    ctx->pc = 0x1AE118u;
label_1ae118:
    // 0x1ae118: 0x111040  sll         $v0, $s1, 1
    ctx->pc = 0x1ae118u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1ae11c: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae11cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae120: 0x512021  addu        $a0, $v0, $s1
    ctx->pc = 0x1ae120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1ae124: 0x24638d78  addiu       $v1, $v1, -0x7288
    ctx->pc = 0x1ae124u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937976));
    // 0x1ae128: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae128u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae12c: 0x428c0  sll         $a1, $a0, 3
    ctx->pc = 0x1ae12cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1ae130: 0x24428d74  addiu       $v0, $v0, -0x728C
    ctx->pc = 0x1ae130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937972));
    // 0x1ae134: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1ae134u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1ae138: 0x452021  addu        $a0, $v0, $a1
    ctx->pc = 0x1ae138u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1ae13c: 0xac700000  sw          $s0, 0x0($v1)
    ctx->pc = 0x1ae13cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 16));
    // 0x1ae140: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ae140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ae144: 0x202082a  slt         $at, $s0, $v0
    ctx->pc = 0x1ae144u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1ae148: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AE148u;
    {
        const bool branch_taken_0x1ae148 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE14Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE148u;
            // 0x1ae14c: 0x3c02002c  lui         $v0, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae148) {
            ctx->pc = 0x1AE154u;
            goto label_1ae154;
        }
    }
    ctx->pc = 0x1AE150u;
    // 0x1ae150: 0xac900000  sw          $s0, 0x0($a0)
    ctx->pc = 0x1ae150u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
label_1ae154:
    // 0x1ae154: 0x44900000  mtc1        $s0, $f0
    ctx->pc = 0x1ae154u;
    { uint32_t bits = GPR_U32(ctx, 16); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ae158: 0x24428d80  addiu       $v0, $v0, -0x7280
    ctx->pc = 0x1ae158u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937984));
    // 0x1ae15c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1ae15cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1ae160: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1ae160u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1ae164: 0xc4410000  lwc1        $f1, 0x0($v0)
    ctx->pc = 0x1ae164u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ae168: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1ae168u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ae16c: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x1AE16Cu;
    {
        const bool branch_taken_0x1ae16c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1ae16c) {
            ctx->pc = 0x1AE178u;
            goto label_1ae178;
        }
    }
    ctx->pc = 0x1AE174u;
    // 0x1ae174: 0xe4400000  swc1        $f0, 0x0($v0)
    ctx->pc = 0x1ae174u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
label_1ae178:
    // 0x1ae178: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ae178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ae17c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ae17cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae180: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ae180u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae184: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae184u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae188: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE18Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE188u;
            // 0x1ae18c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE118u: goto label_1ae118;
            case 0x1AE154u: goto label_1ae154;
            case 0x1AE178u: goto label_1ae178;
            case 0x1AE1CCu: goto label_1ae1cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE190u;
    // 0x1ae190: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1ae190u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ae194: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ae194u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ae198: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x1ae198u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ae19c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ae19cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ae1a0: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae1a4: 0x328c0  sll         $a1, $v1, 3
    ctx->pc = 0x1ae1a4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae1a8: 0x24428d70  addiu       $v0, $v0, -0x7290
    ctx->pc = 0x1ae1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937968));
    // 0x1ae1ac: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ae1acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae1b0: 0x452021  addu        $a0, $v0, $a1
    ctx->pc = 0x1ae1b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1ae1b4: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae1b8: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1ae1b8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ae1bc: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae1c0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae1c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae1c4: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1AE1C4u;
    SET_GPR_U32(ctx, 31, 0x1AE1CCu);
    ctx->pc = 0x1AE1C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE1C4u;
            // 0x1ae1c8: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE1CCu; }
        if (ctx->pc != 0x1AE1CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE1CCu; }
        if (ctx->pc != 0x1AE1CCu) { return; }
    }
    ctx->pc = 0x1AE1CCu;
label_1ae1cc:
    // 0x1ae1cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ae1ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae1d0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ae1d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae1d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE1D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE1D4u;
            // 0x1ae1d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE118u: goto label_1ae118;
            case 0x1AE154u: goto label_1ae154;
            case 0x1AE178u: goto label_1ae178;
            case 0x1AE1CCu: goto label_1ae1cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE1DCu;
    // 0x1ae1dc: 0x0  nop
    ctx->pc = 0x1ae1dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
