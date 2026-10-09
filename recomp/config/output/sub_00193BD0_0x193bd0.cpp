#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193BD0
// Address: 0x193bd0 - 0x193c80
void sub_00193BD0_0x193bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193BD0_0x193bd0");
#endif

    ctx->pc = 0x193bd0u;

    // 0x193bd0: 0x24a50010  addiu       $a1, $a1, 0x10
    ctx->pc = 0x193bd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x193bd4: 0x61980  sll         $v1, $a2, 6
    ctx->pc = 0x193bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 6));
    // 0x193bd8: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x193bd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x193bdc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x193be0: 0x84a3000a  lh          $v1, 0xA($a1)
    ctx->pc = 0x193be0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 10)));
    // 0x193be4: 0xac830174  sw          $v1, 0x174($a0)
    ctx->pc = 0x193be4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 372), GPR_U32(ctx, 3));
    // 0x193be8: 0x84a30000  lh          $v1, 0x0($a1)
    ctx->pc = 0x193be8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x193bec: 0xa48300c4  sh          $v1, 0xC4($a0)
    ctx->pc = 0x193becu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 196), (uint16_t)GPR_U32(ctx, 3));
    // 0x193bf0: 0x94a30002  lhu         $v1, 0x2($a1)
    ctx->pc = 0x193bf0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x193bf4: 0xa48300c6  sh          $v1, 0xC6($a0)
    ctx->pc = 0x193bf4u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 198), (uint16_t)GPR_U32(ctx, 3));
    // 0x193bf8: 0x84a30006  lh          $v1, 0x6($a1)
    ctx->pc = 0x193bf8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x193bfc: 0xa4830182  sh          $v1, 0x182($a0)
    ctx->pc = 0x193bfcu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 386), (uint16_t)GPR_U32(ctx, 3));
    // 0x193c00: 0x84a30008  lh          $v1, 0x8($a1)
    ctx->pc = 0x193c00u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x193c04: 0xa4830180  sh          $v1, 0x180($a0)
    ctx->pc = 0x193c04u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 384), (uint16_t)GPR_U32(ctx, 3));
    // 0x193c08: 0xc4a00010  lwc1        $f0, 0x10($a1)
    ctx->pc = 0x193c08u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c0c: 0xe48000dc  swc1        $f0, 0xDC($a0)
    ctx->pc = 0x193c0cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 220), bits); }
    // 0x193c10: 0xe4800104  swc1        $f0, 0x104($a0)
    ctx->pc = 0x193c10u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 260), bits); }
    // 0x193c14: 0xc4a00014  lwc1        $f0, 0x14($a1)
    ctx->pc = 0x193c14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c18: 0xe48000e0  swc1        $f0, 0xE0($a0)
    ctx->pc = 0x193c18u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 224), bits); }
    // 0x193c1c: 0xe4800108  swc1        $f0, 0x108($a0)
    ctx->pc = 0x193c1cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 264), bits); }
    // 0x193c20: 0xc4a00018  lwc1        $f0, 0x18($a1)
    ctx->pc = 0x193c20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c24: 0xe48000e4  swc1        $f0, 0xE4($a0)
    ctx->pc = 0x193c24u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 228), bits); }
    // 0x193c28: 0xe480010c  swc1        $f0, 0x10C($a0)
    ctx->pc = 0x193c28u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 268), bits); }
    // 0x193c2c: 0xc4a00020  lwc1        $f0, 0x20($a1)
    ctx->pc = 0x193c2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c30: 0xe48000e8  swc1        $f0, 0xE8($a0)
    ctx->pc = 0x193c30u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 232), bits); }
    // 0x193c34: 0xe4800110  swc1        $f0, 0x110($a0)
    ctx->pc = 0x193c34u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 272), bits); }
    // 0x193c38: 0xc4a00024  lwc1        $f0, 0x24($a1)
    ctx->pc = 0x193c38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c3c: 0xe48000ec  swc1        $f0, 0xEC($a0)
    ctx->pc = 0x193c3cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 236), bits); }
    // 0x193c40: 0xe4800114  swc1        $f0, 0x114($a0)
    ctx->pc = 0x193c40u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 276), bits); }
    // 0x193c44: 0xc4a00028  lwc1        $f0, 0x28($a1)
    ctx->pc = 0x193c44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c48: 0xe48000f0  swc1        $f0, 0xF0($a0)
    ctx->pc = 0x193c48u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 240), bits); }
    // 0x193c4c: 0xe4800118  swc1        $f0, 0x118($a0)
    ctx->pc = 0x193c4cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 280), bits); }
    // 0x193c50: 0xc4a00030  lwc1        $f0, 0x30($a1)
    ctx->pc = 0x193c50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c54: 0xe48000f4  swc1        $f0, 0xF4($a0)
    ctx->pc = 0x193c54u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 244), bits); }
    // 0x193c58: 0xe480011c  swc1        $f0, 0x11C($a0)
    ctx->pc = 0x193c58u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 284), bits); }
    // 0x193c5c: 0xc4a00034  lwc1        $f0, 0x34($a1)
    ctx->pc = 0x193c5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c60: 0xe48000f8  swc1        $f0, 0xF8($a0)
    ctx->pc = 0x193c60u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 248), bits); }
    // 0x193c64: 0xe4800120  swc1        $f0, 0x120($a0)
    ctx->pc = 0x193c64u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 288), bits); }
    // 0x193c68: 0xc4a00038  lwc1        $f0, 0x38($a1)
    ctx->pc = 0x193c68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193c6c: 0xe48000fc  swc1        $f0, 0xFC($a0)
    ctx->pc = 0x193c6cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 252), bits); }
    // 0x193c70: 0xe4800124  swc1        $f0, 0x124($a0)
    ctx->pc = 0x193c70u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 292), bits); }
    // 0x193c74: 0xac8000d8  sw          $zero, 0xD8($a0)
    ctx->pc = 0x193c74u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 216), GPR_U32(ctx, 0));
    // 0x193c78: 0x3e00008  jr          $ra
    ctx->pc = 0x193C78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193C78u;
            // 0x193c7c: 0xac8000d4  sw          $zero, 0xD4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 212), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x193C80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
