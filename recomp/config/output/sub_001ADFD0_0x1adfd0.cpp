#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ADFD0
// Address: 0x1adfd0 - 0x1ae0c0
void sub_001ADFD0_0x1adfd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ADFD0_0x1adfd0");
#endif

    switch (ctx->pc) {
        case 0x1ae06cu: goto label_1ae06c;
        default: break;
    }

    ctx->pc = 0x1adfd0u;

    // 0x1adfd0: 0x44851000  mtc1        $a1, $f2
    ctx->pc = 0x1adfd0u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1adfd4: 0x3c0342fe  lui         $v1, 0x42FE
    ctx->pc = 0x1adfd4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17150 << 16));
    // 0x1adfd8: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1adfd8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1adfdc: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1adfdcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1adfe0: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1adfe0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1adfe4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1adfe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1adfe8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1adfe8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1adfec: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1adfecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1adff0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1adff0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1adff4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1adff4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1adff8: 0x280c0  sll         $s0, $v0, 3
    ctx->pc = 0x1adff8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1adffc: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1adffcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae000: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae000u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae004: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1ae004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1ae008: 0x46011043  div.s       $f1, $f2, $f1
    ctx->pc = 0x1ae008u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[1];
    // 0x1ae00c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ae00cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ae010: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1ae010u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1ae014: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1ae014u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1ae018: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae018u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae01c: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae01cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae020: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae024: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1ae024u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1ae028: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ae028u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae02c: 0x24634060  addiu       $v1, $v1, 0x4060
    ctx->pc = 0x1ae02cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16480));
    // 0x1ae030: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1ae030u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1ae034: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1ae034u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1ae038: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1ae038u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1ae03c: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x1ae03cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1ae040: 0x0  nop
    ctx->pc = 0x1ae040u;
    // NOP
    // 0x1ae044: 0x30b1007f  andi        $s1, $a1, 0x7F
    ctx->pc = 0x1ae044u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)127);
    // 0x1ae048: 0x112880  sll         $a1, $s1, 2
    ctx->pc = 0x1ae048u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1ae04c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1ae04cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1ae050: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1ae050u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ae054: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1ae054u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ae058: 0x0  nop
    ctx->pc = 0x1ae058u;
    // NOP
    // 0x1ae05c: 0x0  nop
    ctx->pc = 0x1ae05cu;
    // NOP
    // 0x1ae060: 0x2812  mflo        $a1
    ctx->pc = 0x1ae060u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x1ae064: 0xc04c9ee  jal         func_1327B8
    ctx->pc = 0x1AE064u;
    SET_GPR_U32(ctx, 31, 0x1AE06Cu);
    ctx->pc = 0x1327B8u;
    if (runtime->hasFunction(0x1327B8u)) {
        auto targetFn = runtime->lookupFunction(0x1327B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE06Cu; }
        if (ctx->pc != 0x1AE06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001327B8_0x1327b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE06Cu; }
        if (ctx->pc != 0x1AE06Cu) { return; }
    }
    ctx->pc = 0x1AE06Cu;
label_1ae06c:
    // 0x1ae06c: 0x44910000  mtc1        $s1, $f0
    ctx->pc = 0x1ae06cu;
    { uint32_t bits = GPR_U32(ctx, 17); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ae070: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae070u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae074: 0x24638d74  addiu       $v1, $v1, -0x728C
    ctx->pc = 0x1ae074u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937972));
    // 0x1ae078: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae078u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae07c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1ae07cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1ae080: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1ae080u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1ae084: 0xac710000  sw          $s1, 0x0($v1)
    ctx->pc = 0x1ae084u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 17));
    // 0x1ae088: 0x24428d80  addiu       $v0, $v0, -0x7280
    ctx->pc = 0x1ae088u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937984));
    // 0x1ae08c: 0x502021  addu        $a0, $v0, $s0
    ctx->pc = 0x1ae08cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ae090: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae090u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae094: 0x24638d7c  addiu       $v1, $v1, -0x7284
    ctx->pc = 0x1ae094u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937980));
    // 0x1ae098: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ae098u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae09c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1ae09cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1ae0a0: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x1ae0a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x1ae0a4: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1ae0a4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1ae0a8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ae0a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ae0ac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ae0acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae0b0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae0b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae0b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE0B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE0B4u;
            // 0x1ae0b8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE06Cu: goto label_1ae06c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE0BCu;
    // 0x1ae0bc: 0x0  nop
    ctx->pc = 0x1ae0bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
