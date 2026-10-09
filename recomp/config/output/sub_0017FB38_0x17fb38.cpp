#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017FB38
// Address: 0x17fb38 - 0x17fcc8
void sub_0017FB38_0x17fb38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017FB38_0x17fb38");
#endif

    ctx->pc = 0x17fb38u;

    // 0x17fb38: 0x46006406  mov.s       $f16, $f12
    ctx->pc = 0x17fb38u;
    ctx->f[16] = FPU_MOV_S(ctx->f[12]);
    // 0x17fb3c: 0x10c0002a  beqz        $a2, . + 4 + (0x2A << 2)
    ctx->pc = 0x17FB3Cu;
    {
        const bool branch_taken_0x17fb3c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FB40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FB3Cu;
            // 0x17fb40: 0x46006bc6  mov.s       $f15, $f13 (Delay Slot)
        ctx->f[15] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17fb3c) {
            ctx->pc = 0x17FBE8u;
            goto label_17fbe8;
        }
    }
    ctx->pc = 0x17FB44u;
    // 0x17fb44: 0xc4a10000  lwc1        $f1, 0x0($a1)
    ctx->pc = 0x17fb44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x17fb48: 0xc4a20004  lwc1        $f2, 0x4($a1)
    ctx->pc = 0x17fb48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x17fb4c: 0x46018242  mul.s       $f9, $f16, $f1
    ctx->pc = 0x17fb4cu;
    ctx->f[9] = FPU_MUL_S(ctx->f[16], ctx->f[1]);
    // 0x17fb50: 0xc4a30008  lwc1        $f3, 0x8($a1)
    ctx->pc = 0x17fb50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x17fb54: 0x46027a82  mul.s       $f10, $f15, $f2
    ctx->pc = 0x17fb54u;
    ctx->f[10] = FPU_MUL_S(ctx->f[15], ctx->f[2]);
    // 0x17fb58: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x17fb58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x17fb5c: 0x44812800  mtc1        $at, $f5
    ctx->pc = 0x17fb5cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
    // 0x17fb60: 0x46037182  mul.s       $f6, $f14, $f3
    ctx->pc = 0x17fb60u;
    ctx->f[6] = FPU_MUL_S(ctx->f[14], ctx->f[3]);
    // 0x17fb64: 0xe490000c  swc1        $f16, 0xC($a0)
    ctx->pc = 0x17fb64u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 12), bits); }
    // 0x17fb68: 0x460009c7  neg.s       $f7, $f1
    ctx->pc = 0x17fb68u;
    ctx->f[7] = FPU_NEG_S(ctx->f[1]);
    // 0x17fb6c: 0xe48f001c  swc1        $f15, 0x1C($a0)
    ctx->pc = 0x17fb6cu;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 28), bits); }
    // 0x17fb70: 0x460a4800  add.s       $f0, $f9, $f10
    ctx->pc = 0x17fb70u;
    ctx->f[0] = FPU_ADD_S(ctx->f[9], ctx->f[10]);
    // 0x17fb74: 0xe48e002c  swc1        $f14, 0x2C($a0)
    ctx->pc = 0x17fb74u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 44), bits); }
    // 0x17fb78: 0x46001107  neg.s       $f4, $f2
    ctx->pc = 0x17fb78u;
    ctx->f[4] = FPU_NEG_S(ctx->f[2]);
    // 0x17fb7c: 0xe4870030  swc1        $f7, 0x30($a0)
    ctx->pc = 0x17fb7cu;
    { float f = ctx->f[7]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x17fb80: 0x46001a07  neg.s       $f8, $f3
    ctx->pc = 0x17fb80u;
    ctx->f[8] = FPU_NEG_S(ctx->f[3]);
    // 0x17fb84: 0x46060000  add.s       $f0, $f0, $f6
    ctx->pc = 0x17fb84u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[6]);
    // 0x17fb88: 0xe4840034  swc1        $f4, 0x34($a0)
    ctx->pc = 0x17fb88u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x17fb8c: 0x460179c2  mul.s       $f7, $f15, $f1
    ctx->pc = 0x17fb8cu;
    ctx->f[7] = FPU_MUL_S(ctx->f[15], ctx->f[1]);
    // 0x17fb90: 0x46028102  mul.s       $f4, $f16, $f2
    ctx->pc = 0x17fb90u;
    ctx->f[4] = FPU_MUL_S(ctx->f[16], ctx->f[2]);
    // 0x17fb94: 0xe4880038  swc1        $f8, 0x38($a0)
    ctx->pc = 0x17fb94u;
    { float f = ctx->f[8]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
    // 0x17fb98: 0x46002801  sub.s       $f0, $f5, $f0
    ctx->pc = 0x17fb98u;
    ctx->f[0] = FPU_SUB_S(ctx->f[5], ctx->f[0]);
    // 0x17fb9c: 0x46017042  mul.s       $f1, $f14, $f1
    ctx->pc = 0x17fb9cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[14], ctx->f[1]);
    // 0x17fba0: 0xe4870010  swc1        $f7, 0x10($a0)
    ctx->pc = 0x17fba0u;
    { float f = ctx->f[7]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 16), bits); }
    // 0x17fba4: 0x46027082  mul.s       $f2, $f14, $f2
    ctx->pc = 0x17fba4u;
    ctx->f[2] = FPU_MUL_S(ctx->f[14], ctx->f[2]);
    // 0x17fba8: 0xe4840004  swc1        $f4, 0x4($a0)
    ctx->pc = 0x17fba8u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x17fbac: 0x46050141  sub.s       $f5, $f0, $f5
    ctx->pc = 0x17fbacu;
    ctx->f[5] = FPU_SUB_S(ctx->f[0], ctx->f[5]);
    // 0x17fbb0: 0x46004a40  add.s       $f9, $f9, $f0
    ctx->pc = 0x17fbb0u;
    ctx->f[9] = FPU_ADD_S(ctx->f[9], ctx->f[0]);
    // 0x17fbb4: 0xe4810020  swc1        $f1, 0x20($a0)
    ctx->pc = 0x17fbb4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 32), bits); }
    // 0x17fbb8: 0x46005280  add.s       $f10, $f10, $f0
    ctx->pc = 0x17fbb8u;
    ctx->f[10] = FPU_ADD_S(ctx->f[10], ctx->f[0]);
    // 0x17fbbc: 0xe4820024  swc1        $f2, 0x24($a0)
    ctx->pc = 0x17fbbcu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 36), bits); }
    // 0x17fbc0: 0x46003180  add.s       $f6, $f6, $f0
    ctx->pc = 0x17fbc0u;
    ctx->f[6] = FPU_ADD_S(ctx->f[6], ctx->f[0]);
    // 0x17fbc4: 0xe485003c  swc1        $f5, 0x3C($a0)
    ctx->pc = 0x17fbc4u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 60), bits); }
    // 0x17fbc8: 0x46038002  mul.s       $f0, $f16, $f3
    ctx->pc = 0x17fbc8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[16], ctx->f[3]);
    // 0x17fbcc: 0xe4890000  swc1        $f9, 0x0($a0)
    ctx->pc = 0x17fbccu;
    { float f = ctx->f[9]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x17fbd0: 0x460378c2  mul.s       $f3, $f15, $f3
    ctx->pc = 0x17fbd0u;
    ctx->f[3] = FPU_MUL_S(ctx->f[15], ctx->f[3]);
    // 0x17fbd4: 0xe48a0014  swc1        $f10, 0x14($a0)
    ctx->pc = 0x17fbd4u;
    { float f = ctx->f[10]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 20), bits); }
    // 0x17fbd8: 0xe4860028  swc1        $f6, 0x28($a0)
    ctx->pc = 0x17fbd8u;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 40), bits); }
    // 0x17fbdc: 0xe4800008  swc1        $f0, 0x8($a0)
    ctx->pc = 0x17fbdcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x17fbe0: 0x3e00008  jr          $ra
    ctx->pc = 0x17FBE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FBE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FBE0u;
            // 0x17fbe4: 0xe4830018  swc1        $f3, 0x18($a0) (Delay Slot)
        { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 24), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17FBE8u: goto label_17fbe8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FBE8u;
label_17fbe8:
    // 0x17fbe8: 0xc4a20000  lwc1        $f2, 0x0($a1)
    ctx->pc = 0x17fbe8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x17fbec: 0xc4a40004  lwc1        $f4, 0x4($a1)
    ctx->pc = 0x17fbecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x17fbf0: 0x46028142  mul.s       $f5, $f16, $f2
    ctx->pc = 0x17fbf0u;
    ctx->f[5] = FPU_MUL_S(ctx->f[16], ctx->f[2]);
    // 0x17fbf4: 0xc4a70008  lwc1        $f7, 0x8($a1)
    ctx->pc = 0x17fbf4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x17fbf8: 0x46047982  mul.s       $f6, $f15, $f4
    ctx->pc = 0x17fbf8u;
    ctx->f[6] = FPU_MUL_S(ctx->f[15], ctx->f[4]);
    // 0x17fbfc: 0x3c01bf80  lui         $at, 0xBF80
    ctx->pc = 0x17fbfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49024 << 16));
    // 0x17fc00: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x17fc00u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x17fc04: 0x46077202  mul.s       $f8, $f14, $f7
    ctx->pc = 0x17fc04u;
    ctx->f[8] = FPU_MUL_S(ctx->f[14], ctx->f[7]);
    // 0x17fc08: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x17fc08u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x17fc0c: 0x46001247  neg.s       $f9, $f2
    ctx->pc = 0x17fc0cu;
    ctx->f[9] = FPU_NEG_S(ctx->f[2]);
    // 0x17fc10: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x17fc10u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x17fc14: 0x46062800  add.s       $f0, $f5, $f6
    ctx->pc = 0x17fc14u;
    ctx->f[0] = FPU_ADD_S(ctx->f[5], ctx->f[6]);
    // 0x17fc18: 0xac80002c  sw          $zero, 0x2C($a0)
    ctx->pc = 0x17fc18u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x17fc1c: 0x46047282  mul.s       $f10, $f14, $f4
    ctx->pc = 0x17fc1cu;
    ctx->f[10] = FPU_MUL_S(ctx->f[14], ctx->f[4]);
    // 0x17fc20: 0x460022c7  neg.s       $f11, $f4
    ctx->pc = 0x17fc20u;
    ctx->f[11] = FPU_NEG_S(ctx->f[4]);
    // 0x17fc24: 0x46080000  add.s       $f0, $f0, $f8
    ctx->pc = 0x17fc24u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[8]);
    // 0x17fc28: 0x460278c2  mul.s       $f3, $f15, $f2
    ctx->pc = 0x17fc28u;
    ctx->f[3] = FPU_MUL_S(ctx->f[15], ctx->f[2]);
    // 0x17fc2c: 0x46078302  mul.s       $f12, $f16, $f7
    ctx->pc = 0x17fc2cu;
    ctx->f[12] = FPU_MUL_S(ctx->f[16], ctx->f[7]);
    // 0x17fc30: 0x0  nop
    ctx->pc = 0x17fc30u;
    // NOP
    // 0x17fc34: 0x0  nop
    ctx->pc = 0x17fc34u;
    // NOP
    // 0x17fc38: 0x46000843  div.s       $f1, $f1, $f0
    ctx->pc = 0x17fc38u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[1] / ctx->f[0];
    // 0x17fc3c: 0x46002941  sub.s       $f5, $f5, $f0
    ctx->pc = 0x17fc3cu;
    ctx->f[5] = FPU_SUB_S(ctx->f[5], ctx->f[0]);
    // 0x17fc40: 0x46003181  sub.s       $f6, $f6, $f0
    ctx->pc = 0x17fc40u;
    ctx->f[6] = FPU_SUB_S(ctx->f[6], ctx->f[0]);
    // 0x17fc44: 0x46004201  sub.s       $f8, $f8, $f0
    ctx->pc = 0x17fc44u;
    ctx->f[8] = FPU_SUB_S(ctx->f[8], ctx->f[0]);
    // 0x17fc48: 0x46077b42  mul.s       $f13, $f15, $f7
    ctx->pc = 0x17fc48u;
    ctx->f[13] = FPU_MUL_S(ctx->f[15], ctx->f[7]);
    // 0x17fc4c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x17fc4cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x17fc50: 0x46027082  mul.s       $f2, $f14, $f2
    ctx->pc = 0x17fc50u;
    ctx->f[2] = FPU_MUL_S(ctx->f[14], ctx->f[2]);
    // 0x17fc54: 0x46048102  mul.s       $f4, $f16, $f4
    ctx->pc = 0x17fc54u;
    ctx->f[4] = FPU_MUL_S(ctx->f[16], ctx->f[4]);
    // 0x17fc58: 0x460039c7  neg.s       $f7, $f7
    ctx->pc = 0x17fc58u;
    ctx->f[7] = FPU_NEG_S(ctx->f[7]);
    // 0x17fc5c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x17fc5cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x17fc60: 0x46050942  mul.s       $f5, $f1, $f5
    ctx->pc = 0x17fc60u;
    ctx->f[5] = FPU_MUL_S(ctx->f[1], ctx->f[5]);
    // 0x17fc64: 0x460308c2  mul.s       $f3, $f1, $f3
    ctx->pc = 0x17fc64u;
    ctx->f[3] = FPU_MUL_S(ctx->f[1], ctx->f[3]);
    // 0x17fc68: 0x46020882  mul.s       $f2, $f1, $f2
    ctx->pc = 0x17fc68u;
    ctx->f[2] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x17fc6c: 0xe480003c  swc1        $f0, 0x3C($a0)
    ctx->pc = 0x17fc6cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 60), bits); }
    // 0x17fc70: 0x46090a42  mul.s       $f9, $f1, $f9
    ctx->pc = 0x17fc70u;
    ctx->f[9] = FPU_MUL_S(ctx->f[1], ctx->f[9]);
    // 0x17fc74: 0xe4850000  swc1        $f5, 0x0($a0)
    ctx->pc = 0x17fc74u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x17fc78: 0x46040902  mul.s       $f4, $f1, $f4
    ctx->pc = 0x17fc78u;
    ctx->f[4] = FPU_MUL_S(ctx->f[1], ctx->f[4]);
    // 0x17fc7c: 0xe4830010  swc1        $f3, 0x10($a0)
    ctx->pc = 0x17fc7cu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 16), bits); }
    // 0x17fc80: 0x46060982  mul.s       $f6, $f1, $f6
    ctx->pc = 0x17fc80u;
    ctx->f[6] = FPU_MUL_S(ctx->f[1], ctx->f[6]);
    // 0x17fc84: 0xe4820020  swc1        $f2, 0x20($a0)
    ctx->pc = 0x17fc84u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 32), bits); }
    // 0x17fc88: 0x460a0a82  mul.s       $f10, $f1, $f10
    ctx->pc = 0x17fc88u;
    ctx->f[10] = FPU_MUL_S(ctx->f[1], ctx->f[10]);
    // 0x17fc8c: 0xe4890030  swc1        $f9, 0x30($a0)
    ctx->pc = 0x17fc8cu;
    { float f = ctx->f[9]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x17fc90: 0x460b0ac2  mul.s       $f11, $f1, $f11
    ctx->pc = 0x17fc90u;
    ctx->f[11] = FPU_MUL_S(ctx->f[1], ctx->f[11]);
    // 0x17fc94: 0xe4840004  swc1        $f4, 0x4($a0)
    ctx->pc = 0x17fc94u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x17fc98: 0x460c0b02  mul.s       $f12, $f1, $f12
    ctx->pc = 0x17fc98u;
    ctx->f[12] = FPU_MUL_S(ctx->f[1], ctx->f[12]);
    // 0x17fc9c: 0xe4860014  swc1        $f6, 0x14($a0)
    ctx->pc = 0x17fc9cu;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 20), bits); }
    // 0x17fca0: 0x460d0b42  mul.s       $f13, $f1, $f13
    ctx->pc = 0x17fca0u;
    ctx->f[13] = FPU_MUL_S(ctx->f[1], ctx->f[13]);
    // 0x17fca4: 0xe48a0024  swc1        $f10, 0x24($a0)
    ctx->pc = 0x17fca4u;
    { float f = ctx->f[10]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 36), bits); }
    // 0x17fca8: 0x46080a02  mul.s       $f8, $f1, $f8
    ctx->pc = 0x17fca8u;
    ctx->f[8] = FPU_MUL_S(ctx->f[1], ctx->f[8]);
    // 0x17fcac: 0xe48b0034  swc1        $f11, 0x34($a0)
    ctx->pc = 0x17fcacu;
    { float f = ctx->f[11]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x17fcb0: 0x46070842  mul.s       $f1, $f1, $f7
    ctx->pc = 0x17fcb0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[7]);
    // 0x17fcb4: 0xe48c0008  swc1        $f12, 0x8($a0)
    ctx->pc = 0x17fcb4u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x17fcb8: 0xe48d0018  swc1        $f13, 0x18($a0)
    ctx->pc = 0x17fcb8u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 24), bits); }
    // 0x17fcbc: 0xe4880028  swc1        $f8, 0x28($a0)
    ctx->pc = 0x17fcbcu;
    { float f = ctx->f[8]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 40), bits); }
    // 0x17fcc0: 0x3e00008  jr          $ra
    ctx->pc = 0x17FCC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FCC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FCC0u;
            // 0x17fcc4: 0xe4810038  swc1        $f1, 0x38($a0) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17FBE8u: goto label_17fbe8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FCC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
