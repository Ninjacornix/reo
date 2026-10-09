#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00194C80
// Address: 0x194c80 - 0x194fcc
void sub_00194C80_0x194c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00194C80_0x194c80");
#endif

    switch (ctx->pc) {
        case 0x194cb8u: goto label_194cb8;
        case 0x194cc4u: goto label_194cc4;
        case 0x194fb8u: goto label_194fb8;
        default: break;
    }

    ctx->pc = 0x194c80u;

    // 0x194c80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x194c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x194c84: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194c84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194c88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x194c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x194c8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x194c8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x194c90: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194c90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194c94: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194C94u;
    {
        const bool branch_taken_0x194c94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x194C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C94u;
            // 0x194c98: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194c94) {
            ctx->pc = 0x194CA4u;
            goto label_194ca4;
        }
    }
    ctx->pc = 0x194C9Cu;
    // 0x194c9c: 0x100000c7  b           . + 4 + (0xC7 << 2)
    ctx->pc = 0x194C9Cu;
    {
        const bool branch_taken_0x194c9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194CA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C9Cu;
            // 0x194ca0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194c9c) {
            ctx->pc = 0x194FBCu;
            goto label_194fbc;
        }
    }
    ctx->pc = 0x194CA4u;
label_194ca4:
    // 0x194ca4: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x194ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x194ca8: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x194ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x194cac: 0x2484ffd0  addiu       $a0, $a0, -0x30
    ctx->pc = 0x194cacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967248));
    // 0x194cb0: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x194CB0u;
    SET_GPR_U32(ctx, 31, 0x194CB8u);
    ctx->pc = 0x194CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194CB0u;
            // 0x194cb4: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194CB8u; }
        if (ctx->pc != 0x194CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194CB8u; }
        if (ctx->pc != 0x194CB8u) { return; }
    }
    ctx->pc = 0x194CB8u;
label_194cb8:
    // 0x194cb8: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x194cb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x194cbc: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x194CBCu;
    SET_GPR_U32(ctx, 31, 0x194CC4u);
    ctx->pc = 0x194CC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194CBCu;
            // 0x194cc0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194CC4u; }
        if (ctx->pc != 0x194CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194CC4u; }
        if (ctx->pc != 0x194CC4u) { return; }
    }
    ctx->pc = 0x194CC4u;
label_194cc4:
    // 0x194cc4: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x194cc4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x194cc8: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x194cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x194ccc: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x194cccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x194cd0: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x194cd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x194cd4: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x194cd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x194cd8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194cd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194cdc: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194cdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194ce0: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x194ce0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x194ce4: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x194ce4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x194ce8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x194ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x194cec: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x194cecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194cf0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194cf0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194cf4: 0x9e02000c  lwu         $v0, 0xC($s0)
    ctx->pc = 0x194cf4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x194cf8: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x194cf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x194cfc: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x194cfcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194d00: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194d00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194d04: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x194d04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x194d08: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x194d08u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x194d0c: 0xc6010024  lwc1        $f1, 0x24($s0)
    ctx->pc = 0x194d0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d10: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194d10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194d14: 0xc600000c  lwc1        $f0, 0xC($s0)
    ctx->pc = 0x194d14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194d18: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x194d18u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x194d1c: 0xe7a0002c  swc1        $f0, 0x2C($sp)
    ctx->pc = 0x194d1cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x194d20: 0xc6010028  lwc1        $f1, 0x28($s0)
    ctx->pc = 0x194d20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d24: 0x9fa3002c  lwu         $v1, 0x2C($sp)
    ctx->pc = 0x194d24u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x194d28: 0xc600000c  lwc1        $f0, 0xC($s0)
    ctx->pc = 0x194d28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194d2c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x194d2cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x194d30: 0xe7a00028  swc1        $f0, 0x28($sp)
    ctx->pc = 0x194d30u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x194d34: 0x9fa20028  lwu         $v0, 0x28($sp)
    ctx->pc = 0x194d34u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x194d38: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194d38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194d3c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194d3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194d40: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x194d40u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x194d44: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194d44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194d48: 0xc420fd5c  lwc1        $f0, -0x2A4($at)
    ctx->pc = 0x194d48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966620)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194d4c: 0xc6010000  lwc1        $f1, 0x0($s0)
    ctx->pc = 0x194d4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d50: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x194d50u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x194d54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194d54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194d58: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x194d58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x194d5c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x194D5Cu;
    {
        const bool branch_taken_0x194d5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x194D60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194D5Cu;
            // 0x194d60: 0x46000a01  sub.s       $f8, $f1, $f0 (Delay Slot)
        ctx->f[8] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x194d5c) {
            ctx->pc = 0x194D8Cu;
            goto label_194d8c;
        }
    }
    ctx->pc = 0x194D64u;
    // 0x194d64: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194d64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194d68: 0x3c023f00  lui         $v0, 0x3F00
    ctx->pc = 0x194d68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16128 << 16));
    // 0x194d6c: 0xc421fd60  lwc1        $f1, -0x2A0($at)
    ctx->pc = 0x194d6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d70: 0xc6020004  lwc1        $f2, 0x4($s0)
    ctx->pc = 0x194d70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x194d74: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194d74u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194d78: 0x0  nop
    ctx->pc = 0x194d78u;
    // NOP
    // 0x194d7c: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x194d7cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x194d80: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x194d80u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x194d84: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x194D84u;
    {
        const bool branch_taken_0x194d84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194D84u;
            // 0x194d88: 0x460101c2  mul.s       $f7, $f0, $f1 (Delay Slot)
        ctx->f[7] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x194d84) {
            ctx->pc = 0x194DA0u;
            goto label_194da0;
        }
    }
    ctx->pc = 0x194D8Cu;
label_194d8c:
    // 0x194d8c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194d8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194d90: 0xc420fd60  lwc1        $f0, -0x2A0($at)
    ctx->pc = 0x194d90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194d94: 0xc6010004  lwc1        $f1, 0x4($s0)
    ctx->pc = 0x194d94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d98: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x194d98u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x194d9c: 0x460009c1  sub.s       $f7, $f1, $f0
    ctx->pc = 0x194d9cu;
    ctx->f[7] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
label_194da0:
    // 0x194da0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194da0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194da4: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x194da4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x194da8: 0xc426fd58  lwc1        $f6, -0x2A8($at)
    ctx->pc = 0x194da8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x194dac: 0x44821800  mtc1        $v0, $f3
    ctx->pc = 0x194dacu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x194db0: 0xc6040008  lwc1        $f4, 0x8($s0)
    ctx->pc = 0x194db0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x194db4: 0x3c02bf00  lui         $v0, 0xBF00
    ctx->pc = 0x194db4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48896 << 16));
    // 0x194db8: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x194db8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x194dbc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194dbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194dc0: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194dc4: 0xc425fd54  lwc1        $f5, -0x2AC($at)
    ctx->pc = 0x194dc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x194dc8: 0x460320c1  sub.s       $f3, $f4, $f3
    ctx->pc = 0x194dc8u;
    ctx->f[3] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x194dcc: 0x468031a0  cvt.s.w     $f6, $f6
    ctx->pc = 0x194dccu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[6], sizeof(tmp)); ctx->f[6] = FPU_CVT_S_W(tmp); }
    // 0x194dd0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194dd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194dd4: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194dd4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194dd8: 0x46031082  mul.s       $f2, $f2, $f3
    ctx->pc = 0x194dd8u;
    ctx->f[2] = FPU_MUL_S(ctx->f[2], ctx->f[3]);
    // 0x194ddc: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x194ddcu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x194de0: 0x46073180  add.s       $f6, $f6, $f7
    ctx->pc = 0x194de0u;
    ctx->f[6] = FPU_ADD_S(ctx->f[6], ctx->f[7]);
    // 0x194de4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194de4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194de8: 0x460030a4  .word       0x460030A4                   # cvt.w.s     $f2, $f6 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194de8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[6]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194dec: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194decu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194df0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194df0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194df4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194df4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194df8: 0x468028a0  cvt.s.w     $f2, $f5
    ctx->pc = 0x194df8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[5], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194dfc: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x194dfcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x194e00: 0x46081080  add.s       $f2, $f2, $f8
    ctx->pc = 0x194e00u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[8]);
    // 0x194e04: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194e04u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194e08: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194e08u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194e0c: 0x0  nop
    ctx->pc = 0x194e0cu;
    // NOP
    // 0x194e10: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194e10u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194e14: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194E14u;
    {
        const bool branch_taken_0x194e14 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194E18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194E14u;
            // 0x194e18: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194e14) {
            ctx->pc = 0x194E2Cu;
            goto label_194e2c;
        }
    }
    ctx->pc = 0x194E1Cu;
    // 0x194e1c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194e1cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194e20: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194e20u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194e24: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194E24u;
    {
        const bool branch_taken_0x194e24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194E24u;
            // 0x194e28: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194e24) {
            ctx->pc = 0x194E48u;
            goto label_194e48;
        }
    }
    ctx->pc = 0x194E2Cu;
label_194e2c:
    // 0x194e2c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194e2cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194e30: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194e30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194e34: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194e34u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194e38: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194e38u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194e3c: 0x0  nop
    ctx->pc = 0x194e3cu;
    // NOP
    // 0x194e40: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194e40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194e44: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194e44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194e48:
    // 0x194e48: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194e48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194e4c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194e4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194e50: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194e50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194e54: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x194e54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x194e58: 0xfc220038  sd          $v0, 0x38($at)
    ctx->pc = 0x194e58u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
    // 0x194e5c: 0xc601002c  lwc1        $f1, 0x2C($s0)
    ctx->pc = 0x194e5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194e60: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194e60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194e64: 0xc600001c  lwc1        $f0, 0x1C($s0)
    ctx->pc = 0x194e64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194e68: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x194e68u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x194e6c: 0xe7a0002c  swc1        $f0, 0x2C($sp)
    ctx->pc = 0x194e6cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x194e70: 0xc6010030  lwc1        $f1, 0x30($s0)
    ctx->pc = 0x194e70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194e74: 0x9fa3002c  lwu         $v1, 0x2C($sp)
    ctx->pc = 0x194e74u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x194e78: 0xc600001c  lwc1        $f0, 0x1C($s0)
    ctx->pc = 0x194e78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194e7c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x194e7cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x194e80: 0xe7a00028  swc1        $f0, 0x28($sp)
    ctx->pc = 0x194e80u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x194e84: 0x9fa20028  lwu         $v0, 0x28($sp)
    ctx->pc = 0x194e84u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x194e88: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194e88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194e8c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194e8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194e90: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x194e90u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x194e94: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194e94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194e98: 0xc420fd5c  lwc1        $f0, -0x2A4($at)
    ctx->pc = 0x194e98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966620)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194e9c: 0xc6010010  lwc1        $f1, 0x10($s0)
    ctx->pc = 0x194e9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194ea0: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x194ea0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x194ea4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194ea4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194ea8: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x194ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x194eac: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x194EACu;
    {
        const bool branch_taken_0x194eac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x194EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194EACu;
            // 0x194eb0: 0x46000a01  sub.s       $f8, $f1, $f0 (Delay Slot)
        ctx->f[8] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x194eac) {
            ctx->pc = 0x194EDCu;
            goto label_194edc;
        }
    }
    ctx->pc = 0x194EB4u;
    // 0x194eb4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194eb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194eb8: 0x3c023f00  lui         $v0, 0x3F00
    ctx->pc = 0x194eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16128 << 16));
    // 0x194ebc: 0xc421fd60  lwc1        $f1, -0x2A0($at)
    ctx->pc = 0x194ebcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194ec0: 0xc6020014  lwc1        $f2, 0x14($s0)
    ctx->pc = 0x194ec0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x194ec4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194ec4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194ec8: 0x0  nop
    ctx->pc = 0x194ec8u;
    // NOP
    // 0x194ecc: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x194eccu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x194ed0: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x194ed0u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x194ed4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x194ED4u;
    {
        const bool branch_taken_0x194ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194ED4u;
            // 0x194ed8: 0x460101c2  mul.s       $f7, $f0, $f1 (Delay Slot)
        ctx->f[7] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x194ed4) {
            ctx->pc = 0x194EF0u;
            goto label_194ef0;
        }
    }
    ctx->pc = 0x194EDCu;
label_194edc:
    // 0x194edc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194edcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194ee0: 0xc420fd60  lwc1        $f0, -0x2A0($at)
    ctx->pc = 0x194ee0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194ee4: 0xc6010014  lwc1        $f1, 0x14($s0)
    ctx->pc = 0x194ee4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194ee8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x194ee8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x194eec: 0x460009c1  sub.s       $f7, $f1, $f0
    ctx->pc = 0x194eecu;
    ctx->f[7] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
label_194ef0:
    // 0x194ef0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194ef0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194ef4: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x194ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x194ef8: 0xc426fd58  lwc1        $f6, -0x2A8($at)
    ctx->pc = 0x194ef8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x194efc: 0x44821800  mtc1        $v0, $f3
    ctx->pc = 0x194efcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x194f00: 0xc6040018  lwc1        $f4, 0x18($s0)
    ctx->pc = 0x194f00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x194f04: 0x3c02bf00  lui         $v0, 0xBF00
    ctx->pc = 0x194f04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48896 << 16));
    // 0x194f08: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x194f08u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x194f0c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194f0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194f10: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194f10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194f14: 0xc425fd54  lwc1        $f5, -0x2AC($at)
    ctx->pc = 0x194f14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x194f18: 0x460320c1  sub.s       $f3, $f4, $f3
    ctx->pc = 0x194f18u;
    ctx->f[3] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x194f1c: 0x46031082  mul.s       $f2, $f2, $f3
    ctx->pc = 0x194f1cu;
    ctx->f[2] = FPU_MUL_S(ctx->f[2], ctx->f[3]);
    // 0x194f20: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194f20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194f24: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194f24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194f28: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194f28u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194f2c: 0x0  nop
    ctx->pc = 0x194f2cu;
    // NOP
    // 0x194f30: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x194f30u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x194f34: 0x468030a0  cvt.s.w     $f2, $f6
    ctx->pc = 0x194f34u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[6], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194f38: 0x46071080  add.s       $f2, $f2, $f7
    ctx->pc = 0x194f38u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[7]);
    // 0x194f3c: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194f3cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194f40: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194f40u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194f44: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194f44u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194f48: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194f48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194f4c: 0x468028a0  cvt.s.w     $f2, $f5
    ctx->pc = 0x194f4cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[5], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194f50: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x194f50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x194f54: 0x46081080  add.s       $f2, $f2, $f8
    ctx->pc = 0x194f54u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[8]);
    // 0x194f58: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194f58u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194f5c: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194f5cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194f60: 0x0  nop
    ctx->pc = 0x194f60u;
    // NOP
    // 0x194f64: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194f64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194f68: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194F68u;
    {
        const bool branch_taken_0x194f68 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194F68u;
            // 0x194f6c: 0x432825  or          $a1, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194f68) {
            ctx->pc = 0x194F80u;
            goto label_194f80;
        }
    }
    ctx->pc = 0x194F70u;
    // 0x194f70: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194f70u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194f74: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194f74u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194f78: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194F78u;
    {
        const bool branch_taken_0x194f78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194F78u;
            // 0x194f7c: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194f78) {
            ctx->pc = 0x194F9Cu;
            goto label_194f9c;
        }
    }
    ctx->pc = 0x194F80u;
label_194f80:
    // 0x194f80: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194f80u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194f84: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194f84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194f88: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194f88u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194f8c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194f8cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194f90: 0x0  nop
    ctx->pc = 0x194f90u;
    // NOP
    // 0x194f94: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194f94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194f98: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194f98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194f9c:
    // 0x194f9c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194f9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194fa0: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194fa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194fa4: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x194fa4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x194fa8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194fa8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194fac: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x194facu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x194fb0: 0xc064f88  jal         func_193E20
    ctx->pc = 0x194FB0u;
    SET_GPR_U32(ctx, 31, 0x194FB8u);
    ctx->pc = 0x194FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194FB0u;
            // 0x194fb4: 0xfc220048  sd          $v0, 0x48($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194FB8u; }
        if (ctx->pc != 0x194FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194FB8u; }
        if (ctx->pc != 0x194FB8u) { return; }
    }
    ctx->pc = 0x194FB8u;
label_194fb8:
    // 0x194fb8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_194fbc:
    // 0x194fbc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x194fbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x194fc0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x194fc0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194fc4: 0x3e00008  jr          $ra
    ctx->pc = 0x194FC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194FC4u;
            // 0x194fc8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x194CA4u: goto label_194ca4;
            case 0x194CB8u: goto label_194cb8;
            case 0x194CC4u: goto label_194cc4;
            case 0x194D8Cu: goto label_194d8c;
            case 0x194DA0u: goto label_194da0;
            case 0x194E2Cu: goto label_194e2c;
            case 0x194E48u: goto label_194e48;
            case 0x194EDCu: goto label_194edc;
            case 0x194EF0u: goto label_194ef0;
            case 0x194F80u: goto label_194f80;
            case 0x194F9Cu: goto label_194f9c;
            case 0x194FB8u: goto label_194fb8;
            case 0x194FBCu: goto label_194fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194FCCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
