#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1B60
// Address: 0x1a1b60 - 0x1a1c60
void sub_001A1B60_0x1a1b60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1B60_0x1a1b60");
#endif

    switch (ctx->pc) {
        case 0x1a1b70u: goto label_1a1b70;
        case 0x1a1c34u: goto label_1a1c34;
        case 0x1a1c40u: goto label_1a1c40;
        default: break;
    }

    ctx->pc = 0x1a1b60u;

    // 0x1a1b60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a1b60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a1b64: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a1b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a1b68: 0xc0697d4  jal         func_1A5F50
    ctx->pc = 0x1A1B68u;
    SET_GPR_U32(ctx, 31, 0x1A1B70u);
    ctx->pc = 0x1A5F50u;
    if (runtime->hasFunction(0x1A5F50u)) {
        auto targetFn = runtime->lookupFunction(0x1A5F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1B70u; }
        if (ctx->pc != 0x1A1B70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5F50_0x1a5f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1B70u; }
        if (ctx->pc != 0x1A1B70u) { return; }
    }
    ctx->pc = 0x1A1B70u;
label_1a1b70:
    // 0x1a1b70: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1b70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1b74: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a1b74u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a1b78: 0xa020ff18  sb          $zero, -0xE8($at)
    ctx->pc = 0x1a1b78u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294967064), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a1b7c: 0x24840a30  addiu       $a0, $a0, 0xA30
    ctx->pc = 0x1a1b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2608));
    // 0x1a1b80: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1b80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1b84: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x1a1b84u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a1b88: 0x8c22ffa8  lw          $v0, -0x58($at)
    ctx->pc = 0x1a1b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1a1b8c: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1a1b8cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a1b90: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1b90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1b94: 0x8c22ffa8  lw          $v0, -0x58($at)
    ctx->pc = 0x1a1b94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1a1b98: 0x90830001  lbu         $v1, 0x1($a0)
    ctx->pc = 0x1a1b98u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1a1b9c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1b9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1ba0: 0xa0430001  sb          $v1, 0x1($v0)
    ctx->pc = 0x1a1ba0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a1ba4: 0x8c22ffa8  lw          $v0, -0x58($at)
    ctx->pc = 0x1a1ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1a1ba8: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x1a1ba8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a1bac: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1bacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1bb0: 0xa4430002  sh          $v1, 0x2($v0)
    ctx->pc = 0x1a1bb0u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a1bb4: 0x8c22ffa8  lw          $v0, -0x58($at)
    ctx->pc = 0x1a1bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1a1bb8: 0xc4800004  lwc1        $f0, 0x4($a0)
    ctx->pc = 0x1a1bb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a1bbc: 0xe4400004  swc1        $f0, 0x4($v0)
    ctx->pc = 0x1a1bbcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x1a1bc0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1bc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1bc4: 0x8c24ffa8  lw          $a0, -0x58($at)
    ctx->pc = 0x1a1bc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1a1bc8: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x1a1bc8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1a1bcc: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A1BCCu;
    {
        const bool branch_taken_0x1a1bcc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a1bcc) {
            ctx->pc = 0x1A1BF4u;
            goto label_1a1bf4;
        }
    }
    ctx->pc = 0x1A1BD4u;
    // 0x1a1bd4: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x1a1bd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1a1bd8: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A1BD8u;
    {
        const bool branch_taken_0x1a1bd8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1a1bd8) {
            ctx->pc = 0x1A1BF4u;
            goto label_1a1bf4;
        }
    }
    ctx->pc = 0x1A1BE0u;
    // 0x1a1be0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1be0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1be4: 0x9022ff18  lbu         $v0, -0xE8($at)
    ctx->pc = 0x1a1be4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294967064)));
    // 0x1a1be8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1a1be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a1bec: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1becu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1bf0: 0xa022ff18  sb          $v0, -0xE8($at)
    ctx->pc = 0x1a1bf0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294967064), (uint8_t)GPR_U32(ctx, 2));
label_1a1bf4:
    // 0x1a1bf4: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a1bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a1bf8: 0x24420a30  addiu       $v0, $v0, 0xA30
    ctx->pc = 0x1a1bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2608));
    // 0x1a1bfc: 0xc442000c  lwc1        $f2, 0xC($v0)
    ctx->pc = 0x1a1bfcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1a1c00: 0xc4410010  lwc1        $f1, 0x10($v0)
    ctx->pc = 0x1a1c00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a1c04: 0xc4400014  lwc1        $f0, 0x14($v0)
    ctx->pc = 0x1a1c04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a1c08: 0xe482001c  swc1        $f2, 0x1C($a0)
    ctx->pc = 0x1a1c08u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 28), bits); }
    // 0x1a1c0c: 0xe4810020  swc1        $f1, 0x20($a0)
    ctx->pc = 0x1a1c0cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 32), bits); }
    // 0x1a1c10: 0xe4800024  swc1        $f0, 0x24($a0)
    ctx->pc = 0x1a1c10u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 36), bits); }
    // 0x1a1c14: 0xc4420018  lwc1        $f2, 0x18($v0)
    ctx->pc = 0x1a1c14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1a1c18: 0xc441001c  lwc1        $f1, 0x1C($v0)
    ctx->pc = 0x1a1c18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a1c1c: 0xc4400020  lwc1        $f0, 0x20($v0)
    ctx->pc = 0x1a1c1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a1c20: 0xe4820028  swc1        $f2, 0x28($a0)
    ctx->pc = 0x1a1c20u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 40), bits); }
    // 0x1a1c24: 0xe481002c  swc1        $f1, 0x2C($a0)
    ctx->pc = 0x1a1c24u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 44), bits); }
    // 0x1a1c28: 0xe4800030  swc1        $f0, 0x30($a0)
    ctx->pc = 0x1a1c28u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x1a1c2c: 0xc068718  jal         func_1A1C60
    ctx->pc = 0x1A1C2Cu;
    SET_GPR_U32(ctx, 31, 0x1A1C34u);
    ctx->pc = 0x1A1C30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1C2Cu;
            // 0x1a1c30: 0x8c450008  lw          $a1, 0x8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1C60u;
    if (runtime->hasFunction(0x1A1C60u)) {
        auto targetFn = runtime->lookupFunction(0x1A1C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1C34u; }
        if (ctx->pc != 0x1A1C34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1C60_0x1a1c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1C34u; }
        if (ctx->pc != 0x1A1C34u) { return; }
    }
    ctx->pc = 0x1A1C34u;
label_1a1c34:
    // 0x1a1c34: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1c34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1c38: 0xc06872c  jal         func_1A1CB0
    ctx->pc = 0x1A1C38u;
    SET_GPR_U32(ctx, 31, 0x1A1C40u);
    ctx->pc = 0x1A1C3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1C38u;
            // 0x1a1c3c: 0x8c24ffa8  lw          $a0, -0x58($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1CB0u;
    if (runtime->hasFunction(0x1A1CB0u)) {
        auto targetFn = runtime->lookupFunction(0x1A1CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1C40u; }
        if (ctx->pc != 0x1A1C40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1CB0_0x1a1cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1C40u; }
        if (ctx->pc != 0x1A1C40u) { return; }
    }
    ctx->pc = 0x1A1C40u;
label_1a1c40:
    // 0x1a1c40: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1c40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1c44: 0x8c24ffa8  lw          $a0, -0x58($at)
    ctx->pc = 0x1a1c44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1a1c48: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x1a1c48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1a1c4c: 0xac830034  sw          $v1, 0x34($a0)
    ctx->pc = 0x1a1c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 3));
    // 0x1a1c50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a1c50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1c54: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1C54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1C54u;
            // 0x1a1c58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1B70u: goto label_1a1b70;
            case 0x1A1BF4u: goto label_1a1bf4;
            case 0x1A1C34u: goto label_1a1c34;
            case 0x1A1C40u: goto label_1a1c40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1C5Cu;
    // 0x1a1c5c: 0x0  nop
    ctx->pc = 0x1a1c5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
