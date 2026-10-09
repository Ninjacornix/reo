#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9970
// Address: 0x1b9970 - 0x1ba170
void sub_001B9970_0x1b9970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9970_0x1b9970");
#endif

    switch (ctx->pc) {
        case 0x1b9a58u: goto label_1b9a58;
        case 0x1b9ac0u: goto label_1b9ac0;
        case 0x1b9aecu: goto label_1b9aec;
        case 0x1b9b10u: goto label_1b9b10;
        case 0x1b9b3cu: goto label_1b9b3c;
        case 0x1b9b68u: goto label_1b9b68;
        case 0x1b9b8cu: goto label_1b9b8c;
        case 0x1b9c14u: goto label_1b9c14;
        case 0x1b9c54u: goto label_1b9c54;
        case 0x1b9c70u: goto label_1b9c70;
        case 0x1b9c88u: goto label_1b9c88;
        case 0x1b9ca0u: goto label_1b9ca0;
        case 0x1b9cb4u: goto label_1b9cb4;
        case 0x1b9ce0u: goto label_1b9ce0;
        case 0x1b9e40u: goto label_1b9e40;
        case 0x1b9e50u: goto label_1b9e50;
        case 0x1b9e64u: goto label_1b9e64;
        case 0x1b9ef4u: goto label_1b9ef4;
        case 0x1b9f10u: goto label_1b9f10;
        case 0x1b9f3cu: goto label_1b9f3c;
        case 0x1b9f70u: goto label_1b9f70;
        case 0x1b9fc4u: goto label_1b9fc4;
        case 0x1b9fe8u: goto label_1b9fe8;
        case 0x1ba010u: goto label_1ba010;
        case 0x1ba024u: goto label_1ba024;
        case 0x1ba068u: goto label_1ba068;
        case 0x1ba0b4u: goto label_1ba0b4;
        case 0x1ba0d4u: goto label_1ba0d4;
        case 0x1ba12cu: goto label_1ba12c;
        case 0x1ba150u: goto label_1ba150;
        default: break;
    }

    ctx->pc = 0x1b9970u;

label_1b9970:
    // 0x1b9970: 0x90830002  lbu         $v1, 0x2($a0)
    ctx->pc = 0x1b9970u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1b9974: 0x2c61000f  sltiu       $at, $v1, 0xF
    ctx->pc = 0x1b9974u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)15) ? 1 : 0);
    // 0x1b9978: 0x1020002b  beqz        $at, . + 4 + (0x2B << 2)
    ctx->pc = 0x1B9978u;
    {
        const bool branch_taken_0x1b9978 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B997Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9978u;
            // 0x1b997c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9978) {
            ctx->pc = 0x1B9A28u;
            goto label_1b9a28;
        }
    }
    ctx->pc = 0x1B9980u;
    // 0x1b9980: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1b9980u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1b9984: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b9984u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9988: 0x24c601b0  addiu       $a2, $a2, 0x1B0
    ctx->pc = 0x1b9988u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 432));
    // 0x1b998c: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1b998cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1b9990: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1b9990u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b9994: 0x600008  jr          $v1
    ctx->pc = 0x1B9994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B999Cu: goto label_1b999c;
            case 0x1B99B8u: goto label_1b99b8;
            case 0x1B99D4u: goto label_1b99d4;
            case 0x1B99F0u: goto label_1b99f0;
            case 0x1B9A0Cu: goto label_1b9a0c;
            case 0x1B9A28u: goto label_1b9a28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B999Cu;
label_1b999c:
    // 0x1b999c: 0xc4820038  lwc1        $f2, 0x38($a0)
    ctx->pc = 0x1b999cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b99a0: 0xc481003c  lwc1        $f1, 0x3C($a0)
    ctx->pc = 0x1b99a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b99a4: 0xc4800040  lwc1        $f0, 0x40($a0)
    ctx->pc = 0x1b99a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b99a8: 0xe4a20000  swc1        $f2, 0x0($a1)
    ctx->pc = 0x1b99a8u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x1b99ac: 0xe4a10004  swc1        $f1, 0x4($a1)
    ctx->pc = 0x1b99acu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
    // 0x1b99b0: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1B99B0u;
    {
        const bool branch_taken_0x1b99b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B99B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B99B0u;
            // 0x1b99b4: 0xe4a00008  swc1        $f0, 0x8($a1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b99b0) {
            ctx->pc = 0x1B9A38u;
            goto label_1b9a38;
        }
    }
    ctx->pc = 0x1B99B8u;
label_1b99b8:
    // 0x1b99b8: 0xc4820038  lwc1        $f2, 0x38($a0)
    ctx->pc = 0x1b99b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b99bc: 0xc481003c  lwc1        $f1, 0x3C($a0)
    ctx->pc = 0x1b99bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b99c0: 0xc4800040  lwc1        $f0, 0x40($a0)
    ctx->pc = 0x1b99c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b99c4: 0xe4a20000  swc1        $f2, 0x0($a1)
    ctx->pc = 0x1b99c4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x1b99c8: 0xe4a10004  swc1        $f1, 0x4($a1)
    ctx->pc = 0x1b99c8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
    // 0x1b99cc: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1B99CCu;
    {
        const bool branch_taken_0x1b99cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B99D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B99CCu;
            // 0x1b99d0: 0xe4a00008  swc1        $f0, 0x8($a1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b99cc) {
            ctx->pc = 0x1B9A38u;
            goto label_1b9a38;
        }
    }
    ctx->pc = 0x1B99D4u;
label_1b99d4:
    // 0x1b99d4: 0xc4820038  lwc1        $f2, 0x38($a0)
    ctx->pc = 0x1b99d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b99d8: 0xc481003c  lwc1        $f1, 0x3C($a0)
    ctx->pc = 0x1b99d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b99dc: 0xc4800040  lwc1        $f0, 0x40($a0)
    ctx->pc = 0x1b99dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b99e0: 0xe4a20000  swc1        $f2, 0x0($a1)
    ctx->pc = 0x1b99e0u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x1b99e4: 0xe4a10004  swc1        $f1, 0x4($a1)
    ctx->pc = 0x1b99e4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
    // 0x1b99e8: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1B99E8u;
    {
        const bool branch_taken_0x1b99e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B99ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B99E8u;
            // 0x1b99ec: 0xe4a00008  swc1        $f0, 0x8($a1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b99e8) {
            ctx->pc = 0x1B9A38u;
            goto label_1b9a38;
        }
    }
    ctx->pc = 0x1B99F0u;
label_1b99f0:
    // 0x1b99f0: 0xc4820070  lwc1        $f2, 0x70($a0)
    ctx->pc = 0x1b99f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b99f4: 0xc4810074  lwc1        $f1, 0x74($a0)
    ctx->pc = 0x1b99f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 116)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b99f8: 0xc4800078  lwc1        $f0, 0x78($a0)
    ctx->pc = 0x1b99f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 120)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b99fc: 0xe4a20000  swc1        $f2, 0x0($a1)
    ctx->pc = 0x1b99fcu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x1b9a00: 0xe4a10004  swc1        $f1, 0x4($a1)
    ctx->pc = 0x1b9a00u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
    // 0x1b9a04: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1B9A04u;
    {
        const bool branch_taken_0x1b9a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9A04u;
            // 0x1b9a08: 0xe4a00008  swc1        $f0, 0x8($a1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9a04) {
            ctx->pc = 0x1B9A38u;
            goto label_1b9a38;
        }
    }
    ctx->pc = 0x1B9A0Cu;
label_1b9a0c:
    // 0x1b9a0c: 0xc4820038  lwc1        $f2, 0x38($a0)
    ctx->pc = 0x1b9a0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b9a10: 0xc481003c  lwc1        $f1, 0x3C($a0)
    ctx->pc = 0x1b9a10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9a14: 0xc4800040  lwc1        $f0, 0x40($a0)
    ctx->pc = 0x1b9a14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b9a18: 0xe4a20000  swc1        $f2, 0x0($a1)
    ctx->pc = 0x1b9a18u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x1b9a1c: 0xe4a10004  swc1        $f1, 0x4($a1)
    ctx->pc = 0x1b9a1cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
    // 0x1b9a20: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B9A20u;
    {
        const bool branch_taken_0x1b9a20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9A20u;
            // 0x1b9a24: 0xe4a00008  swc1        $f0, 0x8($a1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9a20) {
            ctx->pc = 0x1B9A38u;
            goto label_1b9a38;
        }
    }
    ctx->pc = 0x1B9A28u;
label_1b9a28:
    // 0x1b9a28: 0xaca00008  sw          $zero, 0x8($a1)
    ctx->pc = 0x1b9a28u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 0));
    // 0x1b9a2c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b9a2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9a30: 0xaca00004  sw          $zero, 0x4($a1)
    ctx->pc = 0x1b9a30u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 0));
    // 0x1b9a34: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x1b9a34u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
label_1b9a38:
    // 0x1b9a38: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9A38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9970u: goto label_1b9970;
            case 0x1B999Cu: goto label_1b999c;
            case 0x1B99B8u: goto label_1b99b8;
            case 0x1B99D4u: goto label_1b99d4;
            case 0x1B99F0u: goto label_1b99f0;
            case 0x1B9A0Cu: goto label_1b9a0c;
            case 0x1B9A28u: goto label_1b9a28;
            case 0x1B9A38u: goto label_1b9a38;
            case 0x1B9A58u: goto label_1b9a58;
            case 0x1B9AC0u: goto label_1b9ac0;
            case 0x1B9AC8u: goto label_1b9ac8;
            case 0x1B9AECu: goto label_1b9aec;
            case 0x1B9AF4u: goto label_1b9af4;
            case 0x1B9B10u: goto label_1b9b10;
            case 0x1B9B3Cu: goto label_1b9b3c;
            case 0x1B9B44u: goto label_1b9b44;
            case 0x1B9B68u: goto label_1b9b68;
            case 0x1B9B6Cu: goto label_1b9b6c;
            case 0x1B9B8Cu: goto label_1b9b8c;
            case 0x1B9BE8u: goto label_1b9be8;
            case 0x1B9C14u: goto label_1b9c14;
            case 0x1B9C54u: goto label_1b9c54;
            case 0x1B9C70u: goto label_1b9c70;
            case 0x1B9C78u: goto label_1b9c78;
            case 0x1B9C88u: goto label_1b9c88;
            case 0x1B9CA0u: goto label_1b9ca0;
            case 0x1B9CA8u: goto label_1b9ca8;
            case 0x1B9CB4u: goto label_1b9cb4;
            case 0x1B9CB8u: goto label_1b9cb8;
            case 0x1B9CBCu: goto label_1b9cbc;
            case 0x1B9CE0u: goto label_1b9ce0;
            case 0x1B9D24u: goto label_1b9d24;
            case 0x1B9D68u: goto label_1b9d68;
            case 0x1B9D98u: goto label_1b9d98;
            case 0x1B9DB8u: goto label_1b9db8;
            case 0x1B9DBCu: goto label_1b9dbc;
            case 0x1B9DECu: goto label_1b9dec;
            case 0x1B9E0Cu: goto label_1b9e0c;
            case 0x1B9E10u: goto label_1b9e10;
            case 0x1B9E40u: goto label_1b9e40;
            case 0x1B9E48u: goto label_1b9e48;
            case 0x1B9E50u: goto label_1b9e50;
            case 0x1B9E64u: goto label_1b9e64;
            case 0x1B9E68u: goto label_1b9e68;
            case 0x1B9EC4u: goto label_1b9ec4;
            case 0x1B9EF4u: goto label_1b9ef4;
            case 0x1B9F08u: goto label_1b9f08;
            case 0x1B9F10u: goto label_1b9f10;
            case 0x1B9F3Cu: goto label_1b9f3c;
            case 0x1B9F70u: goto label_1b9f70;
            case 0x1B9FC4u: goto label_1b9fc4;
            case 0x1B9FE8u: goto label_1b9fe8;
            case 0x1B9FF0u: goto label_1b9ff0;
            case 0x1BA010u: goto label_1ba010;
            case 0x1BA024u: goto label_1ba024;
            case 0x1BA028u: goto label_1ba028;
            case 0x1BA068u: goto label_1ba068;
            case 0x1BA090u: goto label_1ba090;
            case 0x1BA0B4u: goto label_1ba0b4;
            case 0x1BA0BCu: goto label_1ba0bc;
            case 0x1BA0D4u: goto label_1ba0d4;
            case 0x1BA0E0u: goto label_1ba0e0;
            case 0x1BA0E4u: goto label_1ba0e4;
            case 0x1BA12Cu: goto label_1ba12c;
            case 0x1BA150u: goto label_1ba150;
            case 0x1BA154u: goto label_1ba154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9A40u;
    // 0x1b9a40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b9a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b9a44: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b9a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b9a48: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b9a48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9a4c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b9a4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b9a50: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b9a50u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9a54: 0x111900  sll         $v1, $s1, 4
    ctx->pc = 0x1b9a54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
label_1b9a58:
    // 0x1b9a58: 0x3c02003c  lui         $v0, 0x3C
    ctx->pc = 0x1b9a58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)60 << 16));
    // 0x1b9a5c: 0x711823  subu        $v1, $v1, $s1
    ctx->pc = 0x1b9a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1b9a60: 0x24422750  addiu       $v0, $v0, 0x2750
    ctx->pc = 0x1b9a60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10064));
    // 0x1b9a64: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b9a64u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9a68: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1b9a68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9a6c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1b9a6cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b9a70: 0x1040003d  beqz        $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x1B9A70u;
    {
        const bool branch_taken_0x1b9a70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9a70) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9A78u;
    // 0x1b9a78: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1b9a78u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1b9a7c: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x1B9A7Cu;
    {
        const bool branch_taken_0x1b9a7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9a7c) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9A84u;
    // 0x1b9a84: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x1b9a84u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b9a88: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1B9A88u;
    {
        const bool branch_taken_0x1b9a88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9A88u;
            // 0x1b9a8c: 0x21e3c  dsll32      $v1, $v0, 24 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9a88) {
            ctx->pc = 0x1B9AF4u;
            goto label_1b9af4;
        }
    }
    ctx->pc = 0x1B9A90u;
    // 0x1b9a90: 0x8e030024  lw          $v1, 0x24($s0)
    ctx->pc = 0x1b9a90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1b9a94: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1B9A94u;
    {
        const bool branch_taken_0x1b9a94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9a94) {
            ctx->pc = 0x1B9AC8u;
            goto label_1b9ac8;
        }
    }
    ctx->pc = 0x1B9A9Cu;
    // 0x1b9a9c: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1b9a9cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b9aa0: 0x24670008  addiu       $a3, $v1, 0x8
    ctx->pc = 0x1b9aa0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1b9aa4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9aa4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9aa8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9aa8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9aac: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9aacu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9ab0: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9ab0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ab4: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9ab4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ab8: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9AB8u;
    SET_GPR_U32(ctx, 31, 0x1B9AC0u);
    ctx->pc = 0x1B9ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9AB8u;
            // 0x1b9abc: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9AC0u; }
        if (ctx->pc != 0x1B9AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9AC0u; }
        if (ctx->pc != 0x1B9AC0u) { return; }
    }
    ctx->pc = 0x1B9AC0u;
label_1b9ac0:
    // 0x1b9ac0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1B9AC0u;
    {
        const bool branch_taken_0x1b9ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9AC0u;
            // 0x1b9ac4: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9ac0) {
            ctx->pc = 0x1B9B6Cu;
            goto label_1b9b6c;
        }
    }
    ctx->pc = 0x1B9AC8u;
label_1b9ac8:
    // 0x1b9ac8: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1b9ac8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b9acc: 0x2607002c  addiu       $a3, $s0, 0x2C
    ctx->pc = 0x1b9accu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
    // 0x1b9ad0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9ad0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9ad4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9ad4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ad8: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9ad8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9adc: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9adcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ae0: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9ae0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ae4: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9AE4u;
    SET_GPR_U32(ctx, 31, 0x1B9AECu);
    ctx->pc = 0x1B9AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9AE4u;
            // 0x1b9ae8: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9AECu; }
        if (ctx->pc != 0x1B9AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9AECu; }
        if (ctx->pc != 0x1B9AECu) { return; }
    }
    ctx->pc = 0x1B9AECu;
label_1b9aec:
    // 0x1b9aec: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1B9AECu;
    {
        const bool branch_taken_0x1b9aec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9aec) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9AF4u;
label_1b9af4:
    // 0x1b9af4: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1b9af4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1b9af8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b9af8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9afc: 0x1462001a  bne         $v1, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1B9AFCu;
    {
        const bool branch_taken_0x1b9afc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b9afc) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9B04u;
    // 0x1b9b04: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x1b9b04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1b9b08: 0xc06e65c  jal         func_1B9970
    ctx->pc = 0x1B9B08u;
    SET_GPR_U32(ctx, 31, 0x1B9B10u);
    ctx->pc = 0x1B9B0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B08u;
            // 0x1b9b0c: 0x27a50030  addiu       $a1, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B9970u;
    goto label_1b9970;
    ctx->pc = 0x1B9B10u;
label_1b9b10:
    // 0x1b9b10: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1B9B10u;
    {
        const bool branch_taken_0x1b9b10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9b10) {
            ctx->pc = 0x1B9B44u;
            goto label_1b9b44;
        }
    }
    ctx->pc = 0x1B9B18u;
    // 0x1b9b18: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1b9b18u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b9b1c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9b1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9b20: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9b20u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b24: 0x27a70030  addiu       $a3, $sp, 0x30
    ctx->pc = 0x1b9b24u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1b9b28: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9b28u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9b2c: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9b2cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b30: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9b30u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b34: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9B34u;
    SET_GPR_U32(ctx, 31, 0x1B9B3Cu);
    ctx->pc = 0x1B9B38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B34u;
            // 0x1b9b38: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B3Cu; }
        if (ctx->pc != 0x1B9B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B3Cu; }
        if (ctx->pc != 0x1B9B3Cu) { return; }
    }
    ctx->pc = 0x1B9B3Cu;
label_1b9b3c:
    // 0x1b9b3c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B9B3Cu;
    {
        const bool branch_taken_0x1b9b3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9b3c) {
            ctx->pc = 0x1B9B68u;
            goto label_1b9b68;
        }
    }
    ctx->pc = 0x1B9B44u;
label_1b9b44:
    // 0x1b9b44: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1b9b44u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1b9b48: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9b48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9b4c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9b4cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b50: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b9b50u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b54: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9b54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9b58: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9b58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b5c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9b5cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b60: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9B60u;
    SET_GPR_U32(ctx, 31, 0x1B9B68u);
    ctx->pc = 0x1B9B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B60u;
            // 0x1b9b64: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B68u; }
        if (ctx->pc != 0x1B9B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B68u; }
        if (ctx->pc != 0x1B9B68u) { return; }
    }
    ctx->pc = 0x1B9B68u;
label_1b9b68:
    // 0x1b9b68: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b9b68u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b9b6c:
    // 0x1b9b6c: 0x2a220004  slti        $v0, $s1, 0x4
    ctx->pc = 0x1b9b6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b9b70: 0x1440ffb9  bnez        $v0, . + 4 + (-0x47 << 2)
    ctx->pc = 0x1B9B70u;
    {
        const bool branch_taken_0x1b9b70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B70u;
            // 0x1b9b74: 0x111900  sll         $v1, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9b70) {
            ctx->pc = 0x1B9A58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b9a58;
        }
    }
    ctx->pc = 0x1B9B78u;
    // 0x1b9b78: 0x3c04003c  lui         $a0, 0x3C
    ctx->pc = 0x1b9b78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)60 << 16));
    // 0x1b9b7c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b9b7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9b80: 0x24842750  addiu       $a0, $a0, 0x2750
    ctx->pc = 0x1b9b80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10064));
    // 0x1b9b84: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B9B84u;
    SET_GPR_U32(ctx, 31, 0x1B9B8Cu);
    ctx->pc = 0x1B9B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B84u;
            // 0x1b9b88: 0x240600f0  addiu       $a2, $zero, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B8Cu; }
        if (ctx->pc != 0x1B9B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9B8Cu; }
        if (ctx->pc != 0x1B9B8Cu) { return; }
    }
    ctx->pc = 0x1B9B8Cu;
label_1b9b8c:
    // 0x1b9b8c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b9b8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b9b90: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b9b90u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b9b94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b9b94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9b98: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9B98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9B98u;
            // 0x1b9b9c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9970u: goto label_1b9970;
            case 0x1B999Cu: goto label_1b999c;
            case 0x1B99B8u: goto label_1b99b8;
            case 0x1B99D4u: goto label_1b99d4;
            case 0x1B99F0u: goto label_1b99f0;
            case 0x1B9A0Cu: goto label_1b9a0c;
            case 0x1B9A28u: goto label_1b9a28;
            case 0x1B9A38u: goto label_1b9a38;
            case 0x1B9A58u: goto label_1b9a58;
            case 0x1B9AC0u: goto label_1b9ac0;
            case 0x1B9AC8u: goto label_1b9ac8;
            case 0x1B9AECu: goto label_1b9aec;
            case 0x1B9AF4u: goto label_1b9af4;
            case 0x1B9B10u: goto label_1b9b10;
            case 0x1B9B3Cu: goto label_1b9b3c;
            case 0x1B9B44u: goto label_1b9b44;
            case 0x1B9B68u: goto label_1b9b68;
            case 0x1B9B6Cu: goto label_1b9b6c;
            case 0x1B9B8Cu: goto label_1b9b8c;
            case 0x1B9BE8u: goto label_1b9be8;
            case 0x1B9C14u: goto label_1b9c14;
            case 0x1B9C54u: goto label_1b9c54;
            case 0x1B9C70u: goto label_1b9c70;
            case 0x1B9C78u: goto label_1b9c78;
            case 0x1B9C88u: goto label_1b9c88;
            case 0x1B9CA0u: goto label_1b9ca0;
            case 0x1B9CA8u: goto label_1b9ca8;
            case 0x1B9CB4u: goto label_1b9cb4;
            case 0x1B9CB8u: goto label_1b9cb8;
            case 0x1B9CBCu: goto label_1b9cbc;
            case 0x1B9CE0u: goto label_1b9ce0;
            case 0x1B9D24u: goto label_1b9d24;
            case 0x1B9D68u: goto label_1b9d68;
            case 0x1B9D98u: goto label_1b9d98;
            case 0x1B9DB8u: goto label_1b9db8;
            case 0x1B9DBCu: goto label_1b9dbc;
            case 0x1B9DECu: goto label_1b9dec;
            case 0x1B9E0Cu: goto label_1b9e0c;
            case 0x1B9E10u: goto label_1b9e10;
            case 0x1B9E40u: goto label_1b9e40;
            case 0x1B9E48u: goto label_1b9e48;
            case 0x1B9E50u: goto label_1b9e50;
            case 0x1B9E64u: goto label_1b9e64;
            case 0x1B9E68u: goto label_1b9e68;
            case 0x1B9EC4u: goto label_1b9ec4;
            case 0x1B9EF4u: goto label_1b9ef4;
            case 0x1B9F08u: goto label_1b9f08;
            case 0x1B9F10u: goto label_1b9f10;
            case 0x1B9F3Cu: goto label_1b9f3c;
            case 0x1B9F70u: goto label_1b9f70;
            case 0x1B9FC4u: goto label_1b9fc4;
            case 0x1B9FE8u: goto label_1b9fe8;
            case 0x1B9FF0u: goto label_1b9ff0;
            case 0x1BA010u: goto label_1ba010;
            case 0x1BA024u: goto label_1ba024;
            case 0x1BA028u: goto label_1ba028;
            case 0x1BA068u: goto label_1ba068;
            case 0x1BA090u: goto label_1ba090;
            case 0x1BA0B4u: goto label_1ba0b4;
            case 0x1BA0BCu: goto label_1ba0bc;
            case 0x1BA0D4u: goto label_1ba0d4;
            case 0x1BA0E0u: goto label_1ba0e0;
            case 0x1BA0E4u: goto label_1ba0e4;
            case 0x1BA12Cu: goto label_1ba12c;
            case 0x1BA150u: goto label_1ba150;
            case 0x1BA154u: goto label_1ba154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9BA0u;
    // 0x1b9ba0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b9ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b9ba4: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1b9ba4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1b9ba8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b9ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b9bac: 0x24a54c10  addiu       $a1, $a1, 0x4C10
    ctx->pc = 0x1b9bacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19472));
    // 0x1b9bb0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b9bb0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b9bb4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b9bb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9bb8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b9bb8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9bbc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b9bbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b9bc0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b9bc0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9bc4: 0x84860038  lh          $a2, 0x38($a0)
    ctx->pc = 0x1b9bc4u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x1b9bc8: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1b9bc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1b9bcc: 0x80840004  lb          $a0, 0x4($a0)
    ctx->pc = 0x1b9bccu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1b9bd0: 0x1083003a  beq         $a0, $v1, . + 4 + (0x3A << 2)
    ctx->pc = 0x1B9BD0u;
    {
        const bool branch_taken_0x1b9bd0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B9BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9BD0u;
            // 0x1b9bd4: 0x80b00000  lb          $s0, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9bd0) {
            ctx->pc = 0x1B9CBCu;
            goto label_1b9cbc;
        }
    }
    ctx->pc = 0x1B9BD8u;
    // 0x1b9bd8: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9BD8u;
    {
        const bool branch_taken_0x1b9bd8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9bd8) {
            ctx->pc = 0x1B9BE8u;
            goto label_1b9be8;
        }
    }
    ctx->pc = 0x1B9BE0u;
    // 0x1b9be0: 0x100000a1  b           . + 4 + (0xA1 << 2)
    ctx->pc = 0x1B9BE0u;
    {
        const bool branch_taken_0x1b9be0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9BE0u;
            // 0x1b9be4: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9be0) {
            ctx->pc = 0x1B9E68u;
            goto label_1b9e68;
        }
    }
    ctx->pc = 0x1B9BE8u;
label_1b9be8:
    // 0x1b9be8: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1b9be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1b9bec: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b9becu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b9bf0: 0xa2220004  sb          $v0, 0x4($s1)
    ctx->pc = 0x1b9bf0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b9bf4: 0x2624002c  addiu       $a0, $s1, 0x2C
    ctx->pc = 0x1b9bf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9bf8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b9bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b9bfc: 0x26260014  addiu       $a2, $s1, 0x14
    ctx->pc = 0x1b9bfcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    // 0x1b9c00: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b9c04: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9c04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9c08: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1b9c08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9c0c: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1B9C0Cu;
    SET_GPR_U32(ctx, 31, 0x1B9C14u);
    ctx->pc = 0x1B9C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C0Cu;
            // 0x1b9c10: 0x26270018  addiu       $a3, $s1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C14u; }
        if (ctx->pc != 0x1B9C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C14u; }
        if (ctx->pc != 0x1B9C14u) { return; }
    }
    ctx->pc = 0x1B9C14u;
label_1b9c14:
    // 0x1b9c14: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1b9c14u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9c18: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x1b9c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9c1c: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x1b9c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x1b9c20: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x1b9c20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9c24: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x1b9c24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x1b9c28: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x1b9c28u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1b9c2c: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B9C2Cu;
    {
        const bool branch_taken_0x1b9c2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9c2c) {
            ctx->pc = 0x1B9C78u;
            goto label_1b9c78;
        }
    }
    ctx->pc = 0x1B9C34u;
    // 0x1b9c34: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9c34u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9c38: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9c38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9c3c: 0x8e270014  lw          $a3, 0x14($s1)
    ctx->pc = 0x1b9c3cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9c40: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9c40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9c44: 0x8e280018  lw          $t0, 0x18($s1)
    ctx->pc = 0x1b9c44u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9c48: 0x2409ffff  addiu       $t1, $zero, -0x1
    ctx->pc = 0x1b9c48u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b9c4c: 0xc06b1fc  jal         func_1AC7F0
    ctx->pc = 0x1B9C4Cu;
    SET_GPR_U32(ctx, 31, 0x1B9C54u);
    ctx->pc = 0x1B9C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C4Cu;
            // 0x1b9c50: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC7F0u;
    if (runtime->hasFunction(0x1AC7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AC7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C54u; }
        if (ctx->pc != 0x1B9C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC7F0_0x1ac7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C54u; }
        if (ctx->pc != 0x1B9C54u) { return; }
    }
    ctx->pc = 0x1B9C54u;
label_1b9c54:
    // 0x1b9c54: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9c54u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9c58: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9c58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9c5c: 0x8e270014  lw          $a3, 0x14($s1)
    ctx->pc = 0x1b9c5cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9c60: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9c60u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9c64: 0x8e280018  lw          $t0, 0x18($s1)
    ctx->pc = 0x1b9c64u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9c68: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1B9C68u;
    SET_GPR_U32(ctx, 31, 0x1B9C70u);
    ctx->pc = 0x1B9C6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C68u;
            // 0x1b9c6c: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C70u; }
        if (ctx->pc != 0x1B9C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C70u; }
        if (ctx->pc != 0x1B9C70u) { return; }
    }
    ctx->pc = 0x1B9C70u;
label_1b9c70:
    // 0x1b9c70: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B9C70u;
    {
        const bool branch_taken_0x1b9c70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C70u;
            // 0x1b9c74: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9c70) {
            ctx->pc = 0x1B9CB8u;
            goto label_1b9cb8;
        }
    }
    ctx->pc = 0x1B9C78u;
label_1b9c78:
    // 0x1b9c78: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9c78u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9c7c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9c7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9c80: 0xc06e85c  jal         func_1BA170
    ctx->pc = 0x1B9C80u;
    SET_GPR_U32(ctx, 31, 0x1B9C88u);
    ctx->pc = 0x1B9C84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C80u;
            // 0x1b9c84: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA170u;
    if (runtime->hasFunction(0x1BA170u)) {
        auto targetFn = runtime->lookupFunction(0x1BA170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C88u; }
        if (ctx->pc != 0x1B9C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA170_0x1ba170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9C88u; }
        if (ctx->pc != 0x1B9C88u) { return; }
    }
    ctx->pc = 0x1B9C88u;
label_1b9c88:
    // 0x1b9c88: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B9C88u;
    {
        const bool branch_taken_0x1b9c88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9c88) {
            ctx->pc = 0x1B9CB4u;
            goto label_1b9cb4;
        }
    }
    ctx->pc = 0x1B9C90u;
    // 0x1b9c90: 0x16400005  bnez        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B9C90u;
    {
        const bool branch_taken_0x1b9c90 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C90u;
            // 0x1b9c94: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9c90) {
            ctx->pc = 0x1B9CA8u;
            goto label_1b9ca8;
        }
    }
    ctx->pc = 0x1B9C98u;
    // 0x1b9c98: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1B9C98u;
    SET_GPR_U32(ctx, 31, 0x1B9CA0u);
    ctx->pc = 0x1B9C9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9C98u;
            // 0x1b9c9c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CA0u; }
        if (ctx->pc != 0x1B9CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CA0u; }
        if (ctx->pc != 0x1B9CA0u) { return; }
    }
    ctx->pc = 0x1B9CA0u;
label_1b9ca0:
    // 0x1b9ca0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9CA0u;
    {
        const bool branch_taken_0x1b9ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9ca0) {
            ctx->pc = 0x1B9CB4u;
            goto label_1b9cb4;
        }
    }
    ctx->pc = 0x1B9CA8u;
label_1b9ca8:
    // 0x1b9ca8: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x1b9ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9cac: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1B9CACu;
    SET_GPR_U32(ctx, 31, 0x1B9CB4u);
    ctx->pc = 0x1B9CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9CACu;
            // 0x1b9cb0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CB4u; }
        if (ctx->pc != 0x1B9CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CB4u; }
        if (ctx->pc != 0x1B9CB4u) { return; }
    }
    ctx->pc = 0x1B9CB4u;
label_1b9cb4:
    // 0x1b9cb4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b9cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_1b9cb8:
    // 0x1b9cb8: 0xa6220008  sh          $v0, 0x8($s1)
    ctx->pc = 0x1b9cb8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 2));
label_1b9cbc:
    // 0x1b9cbc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b9cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b9cc0: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b9cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b9cc4: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b9cc8: 0x2624002c  addiu       $a0, $s1, 0x2C
    ctx->pc = 0x1b9cc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9ccc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9cd0: 0x27a6004c  addiu       $a2, $sp, 0x4C
    ctx->pc = 0x1b9cd0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
    // 0x1b9cd4: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1b9cd4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9cd8: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1B9CD8u;
    SET_GPR_U32(ctx, 31, 0x1B9CE0u);
    ctx->pc = 0x1B9CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9CD8u;
            // 0x1b9cdc: 0x27a70048  addiu       $a3, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CE0u; }
        if (ctx->pc != 0x1B9CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9CE0u; }
        if (ctx->pc != 0x1B9CE0u) { return; }
    }
    ctx->pc = 0x1B9CE0u;
label_1b9ce0:
    // 0x1b9ce0: 0x8fa5004c  lw          $a1, 0x4C($sp)
    ctx->pc = 0x1b9ce0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1b9ce4: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1b9ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9ce8: 0x1065000e  beq         $v1, $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x1B9CE8u;
    {
        const bool branch_taken_0x1b9ce8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1b9ce8) {
            ctx->pc = 0x1B9D24u;
            goto label_1b9d24;
        }
    }
    ctx->pc = 0x1B9CF0u;
    // 0x1b9cf0: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x1b9cf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b9cf4: 0x3c034080  lui         $v1, 0x4080
    ctx->pc = 0x1b9cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16512 << 16));
    // 0x1b9cf8: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1b9cf8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9cfc: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1b9cfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b9d00: 0xa42023  subu        $a0, $a1, $a0
    ctx->pc = 0x1b9d00u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1b9d04: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1b9d04u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b9d08: 0x0  nop
    ctx->pc = 0x1b9d08u;
    // NOP
    // 0x1b9d0c: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1b9d0cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1b9d10: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1b9d10u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1b9d14: 0xe620001c  swc1        $f0, 0x1C($s1)
    ctx->pc = 0x1b9d14u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 28), bits); }
    // 0x1b9d18: 0x8fa4004c  lw          $a0, 0x4C($sp)
    ctx->pc = 0x1b9d18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1b9d1c: 0xae240014  sw          $a0, 0x14($s1)
    ctx->pc = 0x1b9d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 4));
    // 0x1b9d20: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1b9d20u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
label_1b9d24:
    // 0x1b9d24: 0x8fa50048  lw          $a1, 0x48($sp)
    ctx->pc = 0x1b9d24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1b9d28: 0x8e230018  lw          $v1, 0x18($s1)
    ctx->pc = 0x1b9d28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9d2c: 0x1065000e  beq         $v1, $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x1B9D2Cu;
    {
        const bool branch_taken_0x1b9d2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1b9d2c) {
            ctx->pc = 0x1B9D68u;
            goto label_1b9d68;
        }
    }
    ctx->pc = 0x1B9D34u;
    // 0x1b9d34: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x1b9d34u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1b9d38: 0x3c034080  lui         $v1, 0x4080
    ctx->pc = 0x1b9d38u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16512 << 16));
    // 0x1b9d3c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1b9d3cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9d40: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1b9d40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b9d44: 0xa42023  subu        $a0, $a1, $a0
    ctx->pc = 0x1b9d44u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1b9d48: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x1b9d48u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b9d4c: 0x0  nop
    ctx->pc = 0x1b9d4cu;
    // NOP
    // 0x1b9d50: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1b9d50u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1b9d54: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1b9d54u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1b9d58: 0xe6200020  swc1        $f0, 0x20($s1)
    ctx->pc = 0x1b9d58u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 32), bits); }
    // 0x1b9d5c: 0x8fa40048  lw          $a0, 0x48($sp)
    ctx->pc = 0x1b9d5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1b9d60: 0xae240018  sw          $a0, 0x18($s1)
    ctx->pc = 0x1b9d60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 4));
    // 0x1b9d64: 0xa623000a  sh          $v1, 0xA($s1)
    ctx->pc = 0x1b9d64u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 3));
label_1b9d68:
    // 0x1b9d68: 0x86230008  lh          $v1, 0x8($s1)
    ctx->pc = 0x1b9d68u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1b9d6c: 0x10600013  beqz        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B9D6Cu;
    {
        const bool branch_taken_0x1b9d6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9D6Cu;
            // 0x1b9d70: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9d6c) {
            ctx->pc = 0x1B9DBCu;
            goto label_1b9dbc;
        }
    }
    ctx->pc = 0x1B9D74u;
    // 0x1b9d74: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b9d74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b9d78: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1b9d78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9d7c: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b9d7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b9d80: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b9d80u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b9d84: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9D84u;
    {
        const bool branch_taken_0x1b9d84 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9d84) {
            ctx->pc = 0x1B9D98u;
            goto label_1b9d98;
        }
    }
    ctx->pc = 0x1B9D8Cu;
    // 0x1b9d8c: 0x8e230014  lw          $v1, 0x14($s1)
    ctx->pc = 0x1b9d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1b9d90: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B9D90u;
    {
        const bool branch_taken_0x1b9d90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9D90u;
            // 0x1b9d94: 0xae23000c  sw          $v1, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9d90) {
            ctx->pc = 0x1B9DB8u;
            goto label_1b9db8;
        }
    }
    ctx->pc = 0x1B9D98u;
label_1b9d98:
    // 0x1b9d98: 0xc621000c  lwc1        $f1, 0xC($s1)
    ctx->pc = 0x1b9d98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9d9c: 0xc620001c  lwc1        $f0, 0x1C($s1)
    ctx->pc = 0x1b9d9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b9da0: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1b9da0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1b9da4: 0x46000800  add.s       $f0, $f1, $f0
    ctx->pc = 0x1b9da4u;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1b9da8: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b9da8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b9dac: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1b9dacu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b9db0: 0x0  nop
    ctx->pc = 0x1b9db0u;
    // NOP
    // 0x1b9db4: 0xae23000c  sw          $v1, 0xC($s1)
    ctx->pc = 0x1b9db4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
label_1b9db8:
    // 0x1b9db8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9db8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b9dbc:
    // 0x1b9dbc: 0x8623000a  lh          $v1, 0xA($s1)
    ctx->pc = 0x1b9dbcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x1b9dc0: 0x10600013  beqz        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B9DC0u;
    {
        const bool branch_taken_0x1b9dc0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9dc0) {
            ctx->pc = 0x1B9E10u;
            goto label_1b9e10;
        }
    }
    ctx->pc = 0x1B9DC8u;
    // 0x1b9dc8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b9dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b9dcc: 0xa623000a  sh          $v1, 0xA($s1)
    ctx->pc = 0x1b9dccu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9dd0: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b9dd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b9dd4: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b9dd4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b9dd8: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9DD8u;
    {
        const bool branch_taken_0x1b9dd8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9dd8) {
            ctx->pc = 0x1B9DECu;
            goto label_1b9dec;
        }
    }
    ctx->pc = 0x1B9DE0u;
    // 0x1b9de0: 0x8e230018  lw          $v1, 0x18($s1)
    ctx->pc = 0x1b9de0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1b9de4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B9DE4u;
    {
        const bool branch_taken_0x1b9de4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9DE4u;
            // 0x1b9de8: 0xae230010  sw          $v1, 0x10($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9de4) {
            ctx->pc = 0x1B9E0Cu;
            goto label_1b9e0c;
        }
    }
    ctx->pc = 0x1B9DECu;
label_1b9dec:
    // 0x1b9dec: 0xc6210010  lwc1        $f1, 0x10($s1)
    ctx->pc = 0x1b9decu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9df0: 0xc6200020  lwc1        $f0, 0x20($s1)
    ctx->pc = 0x1b9df0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b9df4: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1b9df4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1b9df8: 0x46000800  add.s       $f0, $f1, $f0
    ctx->pc = 0x1b9df8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1b9dfc: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b9dfcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b9e00: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1b9e00u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b9e04: 0x0  nop
    ctx->pc = 0x1b9e04u;
    // NOP
    // 0x1b9e08: 0xae230010  sw          $v1, 0x10($s1)
    ctx->pc = 0x1b9e08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
label_1b9e0c:
    // 0x1b9e0c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9e0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b9e10:
    // 0x1b9e10: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B9E10u;
    {
        const bool branch_taken_0x1b9e10 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9e10) {
            ctx->pc = 0x1B9E64u;
            goto label_1b9e64;
        }
    }
    ctx->pc = 0x1B9E18u;
    // 0x1b9e18: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x1b9e18u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1b9e1c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B9E1Cu;
    {
        const bool branch_taken_0x1b9e1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9E1Cu;
            // 0x1b9e20: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9e1c) {
            ctx->pc = 0x1B9E48u;
            goto label_1b9e48;
        }
    }
    ctx->pc = 0x1B9E24u;
    // 0x1b9e24: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9e24u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9e28: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9e28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9e2c: 0x8e27000c  lw          $a3, 0xC($s1)
    ctx->pc = 0x1b9e2cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b9e30: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9e30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9e34: 0x8e280010  lw          $t0, 0x10($s1)
    ctx->pc = 0x1b9e34u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1b9e38: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1B9E38u;
    SET_GPR_U32(ctx, 31, 0x1B9E40u);
    ctx->pc = 0x1B9E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9E38u;
            // 0x1b9e3c: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E40u; }
        if (ctx->pc != 0x1B9E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E40u; }
        if (ctx->pc != 0x1B9E40u) { return; }
    }
    ctx->pc = 0x1B9E40u;
label_1b9e40:
    // 0x1b9e40: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B9E40u;
    {
        const bool branch_taken_0x1b9e40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9e40) {
            ctx->pc = 0x1B9E64u;
            goto label_1b9e64;
        }
    }
    ctx->pc = 0x1B9E48u;
label_1b9e48:
    // 0x1b9e48: 0xc06b91c  jal         func_1AE470
    ctx->pc = 0x1B9E48u;
    SET_GPR_U32(ctx, 31, 0x1B9E50u);
    ctx->pc = 0x1AE470u;
    if (runtime->hasFunction(0x1AE470u)) {
        auto targetFn = runtime->lookupFunction(0x1AE470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E50u; }
        if (ctx->pc != 0x1B9E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE470_0x1ae470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E50u; }
        if (ctx->pc != 0x1B9E50u) { return; }
    }
    ctx->pc = 0x1B9E50u;
label_1b9e50:
    // 0x1b9e50: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9E50u;
    {
        const bool branch_taken_0x1b9e50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9e50) {
            ctx->pc = 0x1B9E64u;
            goto label_1b9e64;
        }
    }
    ctx->pc = 0x1B9E58u;
    // 0x1b9e58: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x1b9e58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b9e5c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1B9E5Cu;
    SET_GPR_U32(ctx, 31, 0x1B9E64u);
    ctx->pc = 0x1B9E60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9E5Cu;
            // 0x1b9e60: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E64u; }
        if (ctx->pc != 0x1B9E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9E64u; }
        if (ctx->pc != 0x1B9E64u) { return; }
    }
    ctx->pc = 0x1B9E64u;
label_1b9e64:
    // 0x1b9e64: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b9e64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1b9e68:
    // 0x1b9e68: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b9e68u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b9e6c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b9e6cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b9e70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b9e70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9e74: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9E74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9E74u;
            // 0x1b9e78: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9970u: goto label_1b9970;
            case 0x1B999Cu: goto label_1b999c;
            case 0x1B99B8u: goto label_1b99b8;
            case 0x1B99D4u: goto label_1b99d4;
            case 0x1B99F0u: goto label_1b99f0;
            case 0x1B9A0Cu: goto label_1b9a0c;
            case 0x1B9A28u: goto label_1b9a28;
            case 0x1B9A38u: goto label_1b9a38;
            case 0x1B9A58u: goto label_1b9a58;
            case 0x1B9AC0u: goto label_1b9ac0;
            case 0x1B9AC8u: goto label_1b9ac8;
            case 0x1B9AECu: goto label_1b9aec;
            case 0x1B9AF4u: goto label_1b9af4;
            case 0x1B9B10u: goto label_1b9b10;
            case 0x1B9B3Cu: goto label_1b9b3c;
            case 0x1B9B44u: goto label_1b9b44;
            case 0x1B9B68u: goto label_1b9b68;
            case 0x1B9B6Cu: goto label_1b9b6c;
            case 0x1B9B8Cu: goto label_1b9b8c;
            case 0x1B9BE8u: goto label_1b9be8;
            case 0x1B9C14u: goto label_1b9c14;
            case 0x1B9C54u: goto label_1b9c54;
            case 0x1B9C70u: goto label_1b9c70;
            case 0x1B9C78u: goto label_1b9c78;
            case 0x1B9C88u: goto label_1b9c88;
            case 0x1B9CA0u: goto label_1b9ca0;
            case 0x1B9CA8u: goto label_1b9ca8;
            case 0x1B9CB4u: goto label_1b9cb4;
            case 0x1B9CB8u: goto label_1b9cb8;
            case 0x1B9CBCu: goto label_1b9cbc;
            case 0x1B9CE0u: goto label_1b9ce0;
            case 0x1B9D24u: goto label_1b9d24;
            case 0x1B9D68u: goto label_1b9d68;
            case 0x1B9D98u: goto label_1b9d98;
            case 0x1B9DB8u: goto label_1b9db8;
            case 0x1B9DBCu: goto label_1b9dbc;
            case 0x1B9DECu: goto label_1b9dec;
            case 0x1B9E0Cu: goto label_1b9e0c;
            case 0x1B9E10u: goto label_1b9e10;
            case 0x1B9E40u: goto label_1b9e40;
            case 0x1B9E48u: goto label_1b9e48;
            case 0x1B9E50u: goto label_1b9e50;
            case 0x1B9E64u: goto label_1b9e64;
            case 0x1B9E68u: goto label_1b9e68;
            case 0x1B9EC4u: goto label_1b9ec4;
            case 0x1B9EF4u: goto label_1b9ef4;
            case 0x1B9F08u: goto label_1b9f08;
            case 0x1B9F10u: goto label_1b9f10;
            case 0x1B9F3Cu: goto label_1b9f3c;
            case 0x1B9F70u: goto label_1b9f70;
            case 0x1B9FC4u: goto label_1b9fc4;
            case 0x1B9FE8u: goto label_1b9fe8;
            case 0x1B9FF0u: goto label_1b9ff0;
            case 0x1BA010u: goto label_1ba010;
            case 0x1BA024u: goto label_1ba024;
            case 0x1BA028u: goto label_1ba028;
            case 0x1BA068u: goto label_1ba068;
            case 0x1BA090u: goto label_1ba090;
            case 0x1BA0B4u: goto label_1ba0b4;
            case 0x1BA0BCu: goto label_1ba0bc;
            case 0x1BA0D4u: goto label_1ba0d4;
            case 0x1BA0E0u: goto label_1ba0e0;
            case 0x1BA0E4u: goto label_1ba0e4;
            case 0x1BA12Cu: goto label_1ba12c;
            case 0x1BA150u: goto label_1ba150;
            case 0x1BA154u: goto label_1ba154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9E7Cu;
    // 0x1b9e7c: 0x0  nop
    ctx->pc = 0x1b9e7cu;
    // NOP
    // 0x1b9e80: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b9e80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b9e84: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1b9e84u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1b9e88: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b9e88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b9e8c: 0x24a54c10  addiu       $a1, $a1, 0x4C10
    ctx->pc = 0x1b9e8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19472));
    // 0x1b9e90: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b9e90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9e94: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9e94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9e98: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b9e98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b9e9c: 0x84860038  lh          $a2, 0x38($a0)
    ctx->pc = 0x1b9e9cu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x1b9ea0: 0x80830004  lb          $v1, 0x4($a0)
    ctx->pc = 0x1b9ea0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1b9ea4: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1b9ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1b9ea8: 0x80b00000  lb          $s0, 0x0($a1)
    ctx->pc = 0x1b9ea8u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1b9eac: 0x10680018  beq         $v1, $t0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B9EACu;
    {
        const bool branch_taken_0x1b9eac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        ctx->pc = 0x1B9EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9EACu;
            // 0x1b9eb0: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9eac) {
            ctx->pc = 0x1B9F10u;
            goto label_1b9f10;
        }
    }
    ctx->pc = 0x1B9EB4u;
    // 0x1b9eb4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9EB4u;
    {
        const bool branch_taken_0x1b9eb4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9eb4) {
            ctx->pc = 0x1B9EC4u;
            goto label_1b9ec4;
        }
    }
    ctx->pc = 0x1B9EBCu;
    // 0x1b9ebc: 0x1000005a  b           . + 4 + (0x5A << 2)
    ctx->pc = 0x1B9EBCu;
    {
        const bool branch_taken_0x1b9ebc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9EBCu;
            // 0x1b9ec0: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9ebc) {
            ctx->pc = 0x1BA028u;
            goto label_1ba028;
        }
    }
    ctx->pc = 0x1B9EC4u;
label_1b9ec4:
    // 0x1b9ec4: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1b9ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b9ec8: 0xa2220004  sb          $v0, 0x4($s1)
    ctx->pc = 0x1b9ec8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b9ecc: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x1b9eccu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1b9ed0: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1B9ED0u;
    {
        const bool branch_taken_0x1b9ed0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9ed0) {
            ctx->pc = 0x1B9F08u;
            goto label_1b9f08;
        }
    }
    ctx->pc = 0x1B9ED8u;
    // 0x1b9ed8: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9ed8u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9edc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9edcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9ee0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9ee0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ee4: 0x2627002c  addiu       $a3, $s1, 0x2C
    ctx->pc = 0x1b9ee4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9ee8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9ee8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9eec: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9EECu;
    SET_GPR_U32(ctx, 31, 0x1B9EF4u);
    ctx->pc = 0x1B9EF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9EECu;
            // 0x1b9ef0: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9EF4u; }
        if (ctx->pc != 0x1B9EF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9EF4u; }
        if (ctx->pc != 0x1B9EF4u) { return; }
    }
    ctx->pc = 0x1B9EF4u;
label_1b9ef4:
    // 0x1b9ef4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1b9ef4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b9ef8: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1b9ef8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1b9efc: 0xa6240008  sh          $a0, 0x8($s1)
    ctx->pc = 0x1b9efcu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 4));
    // 0x1b9f00: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9F00u;
    {
        const bool branch_taken_0x1b9f00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9F00u;
            // 0x1b9f04: 0xa623000a  sh          $v1, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9f00) {
            ctx->pc = 0x1B9F10u;
            goto label_1b9f10;
        }
    }
    ctx->pc = 0x1B9F08u;
label_1b9f08:
    // 0x1b9f08: 0xc06e650  jal         func_1B9940
    ctx->pc = 0x1B9F08u;
    SET_GPR_U32(ctx, 31, 0x1B9F10u);
    ctx->pc = 0x1B9940u;
    if (runtime->hasFunction(0x1B9940u)) {
        auto targetFn = runtime->lookupFunction(0x1B9940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F10u; }
        if (ctx->pc != 0x1B9F10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B9940_0x1b9940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F10u; }
        if (ctx->pc != 0x1B9F10u) { return; }
    }
    ctx->pc = 0x1B9F10u;
label_1b9f10:
    // 0x1b9f10: 0x8623000a  lh          $v1, 0xA($s1)
    ctx->pc = 0x1b9f10u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x1b9f14: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b9f14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b9f18: 0xa623000a  sh          $v1, 0xA($s1)
    ctx->pc = 0x1b9f18u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9f1c: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b9f1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b9f20: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b9f20u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b9f24: 0x4610012  bgez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B9F24u;
    {
        const bool branch_taken_0x1b9f24 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x1b9f24) {
            ctx->pc = 0x1B9F70u;
            goto label_1b9f70;
        }
    }
    ctx->pc = 0x1B9F2Cu;
    // 0x1b9f2c: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1b9f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1b9f30: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9f30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9f34: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B9F34u;
    SET_GPR_U32(ctx, 31, 0x1B9F3Cu);
    ctx->pc = 0x1B9F38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9F34u;
            // 0x1b9f38: 0xa622000a  sh          $v0, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F3Cu; }
        if (ctx->pc != 0x1B9F3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F3Cu; }
        if (ctx->pc != 0x1B9F3Cu) { return; }
    }
    ctx->pc = 0x1B9F3Cu;
label_1b9f3c:
    // 0x1b9f3c: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b9f3cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b9f40: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9f40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9f44: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1b9f44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b9f48: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9f48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9f4c: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1b9f4cu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1b9f50: 0x2627002c  addiu       $a3, $s1, 0x2C
    ctx->pc = 0x1b9f50u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9f54: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9f54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9f58: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9f58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9f5c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9f5cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9f60: 0x82220002  lb          $v0, 0x2($s1)
    ctx->pc = 0x1b9f60u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9f64: 0x1810  mfhi        $v1
    ctx->pc = 0x1b9f64u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1b9f68: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9F68u;
    SET_GPR_U32(ctx, 31, 0x1B9F70u);
    ctx->pc = 0x1B9F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9F68u;
            // 0x1b9f6c: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F70u; }
        if (ctx->pc != 0x1B9F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F70u; }
        if (ctx->pc != 0x1B9F70u) { return; }
    }
    ctx->pc = 0x1B9F70u;
label_1b9f70:
    // 0x1b9f70: 0x86230008  lh          $v1, 0x8($s1)
    ctx->pc = 0x1b9f70u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1b9f74: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b9f74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b9f78: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1b9f78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9f7c: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b9f7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b9f80: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b9f80u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b9f84: 0x4610027  bgez        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1B9F84u;
    {
        const bool branch_taken_0x1b9f84 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x1b9f84) {
            ctx->pc = 0x1BA024u;
            goto label_1ba024;
        }
    }
    ctx->pc = 0x1B9F8Cu;
    // 0x1b9f8c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b9f8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b9f90: 0xa6220008  sh          $v0, 0x8($s1)
    ctx->pc = 0x1b9f90u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b9f94: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x1b9f94u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1b9f98: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B9F98u;
    {
        const bool branch_taken_0x1b9f98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9F98u;
            // 0x1b9f9c: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9f98) {
            ctx->pc = 0x1B9FF0u;
            goto label_1b9ff0;
        }
    }
    ctx->pc = 0x1B9FA0u;
    // 0x1b9fa0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b9fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b9fa4: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b9fa4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b9fa8: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b9fac: 0x2624002c  addiu       $a0, $s1, 0x2C
    ctx->pc = 0x1b9facu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9fb0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9fb4: 0x27a6003c  addiu       $a2, $sp, 0x3C
    ctx->pc = 0x1b9fb4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x1b9fb8: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1b9fb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9fbc: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1B9FBCu;
    SET_GPR_U32(ctx, 31, 0x1B9FC4u);
    ctx->pc = 0x1B9FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9FBCu;
            // 0x1b9fc0: 0x27a70038  addiu       $a3, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9FC4u; }
        if (ctx->pc != 0x1B9FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9FC4u; }
        if (ctx->pc != 0x1B9FC4u) { return; }
    }
    ctx->pc = 0x1B9FC4u;
label_1b9fc4:
    // 0x1b9fc4: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1B9FC4u;
    {
        const bool branch_taken_0x1b9fc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9fc4) {
            ctx->pc = 0x1BA024u;
            goto label_1ba024;
        }
    }
    ctx->pc = 0x1B9FCCu;
    // 0x1b9fcc: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9fccu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9fd0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9fd4: 0x8fa7003c  lw          $a3, 0x3C($sp)
    ctx->pc = 0x1b9fd4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1b9fd8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9fd8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9fdc: 0x8fa80038  lw          $t0, 0x38($sp)
    ctx->pc = 0x1b9fdcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1b9fe0: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1B9FE0u;
    SET_GPR_U32(ctx, 31, 0x1B9FE8u);
    ctx->pc = 0x1B9FE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9FE0u;
            // 0x1b9fe4: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9FE8u; }
        if (ctx->pc != 0x1B9FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9FE8u; }
        if (ctx->pc != 0x1B9FE8u) { return; }
    }
    ctx->pc = 0x1B9FE8u;
label_1b9fe8:
    // 0x1b9fe8: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1B9FE8u;
    {
        const bool branch_taken_0x1b9fe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9fe8) {
            ctx->pc = 0x1BA024u;
            goto label_1ba024;
        }
    }
    ctx->pc = 0x1B9FF0u;
label_1b9ff0:
    // 0x1b9ff0: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b9ff0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b9ff4: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b9ff8: 0x2624002c  addiu       $a0, $s1, 0x2C
    ctx->pc = 0x1b9ff8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9ffc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ba000: 0x27a6003c  addiu       $a2, $sp, 0x3C
    ctx->pc = 0x1ba000u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x1ba004: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1ba004u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ba008: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1BA008u;
    SET_GPR_U32(ctx, 31, 0x1BA010u);
    ctx->pc = 0x1BA00Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA008u;
            // 0x1ba00c: 0x27a70038  addiu       $a3, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA010u; }
        if (ctx->pc != 0x1BA010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA010u; }
        if (ctx->pc != 0x1BA010u) { return; }
    }
    ctx->pc = 0x1BA010u;
label_1ba010:
    // 0x1ba010: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BA010u;
    {
        const bool branch_taken_0x1ba010 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba010) {
            ctx->pc = 0x1BA024u;
            goto label_1ba024;
        }
    }
    ctx->pc = 0x1BA018u;
    // 0x1ba018: 0x8fa5003c  lw          $a1, 0x3C($sp)
    ctx->pc = 0x1ba018u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1ba01c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1BA01Cu;
    SET_GPR_U32(ctx, 31, 0x1BA024u);
    ctx->pc = 0x1BA020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA01Cu;
            // 0x1ba020: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA024u; }
        if (ctx->pc != 0x1BA024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA024u; }
        if (ctx->pc != 0x1BA024u) { return; }
    }
    ctx->pc = 0x1BA024u;
label_1ba024:
    // 0x1ba024: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ba024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1ba028:
    // 0x1ba028: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ba028u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ba02c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba02cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba030: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA030u;
            // 0x1ba034: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9970u: goto label_1b9970;
            case 0x1B999Cu: goto label_1b999c;
            case 0x1B99B8u: goto label_1b99b8;
            case 0x1B99D4u: goto label_1b99d4;
            case 0x1B99F0u: goto label_1b99f0;
            case 0x1B9A0Cu: goto label_1b9a0c;
            case 0x1B9A28u: goto label_1b9a28;
            case 0x1B9A38u: goto label_1b9a38;
            case 0x1B9A58u: goto label_1b9a58;
            case 0x1B9AC0u: goto label_1b9ac0;
            case 0x1B9AC8u: goto label_1b9ac8;
            case 0x1B9AECu: goto label_1b9aec;
            case 0x1B9AF4u: goto label_1b9af4;
            case 0x1B9B10u: goto label_1b9b10;
            case 0x1B9B3Cu: goto label_1b9b3c;
            case 0x1B9B44u: goto label_1b9b44;
            case 0x1B9B68u: goto label_1b9b68;
            case 0x1B9B6Cu: goto label_1b9b6c;
            case 0x1B9B8Cu: goto label_1b9b8c;
            case 0x1B9BE8u: goto label_1b9be8;
            case 0x1B9C14u: goto label_1b9c14;
            case 0x1B9C54u: goto label_1b9c54;
            case 0x1B9C70u: goto label_1b9c70;
            case 0x1B9C78u: goto label_1b9c78;
            case 0x1B9C88u: goto label_1b9c88;
            case 0x1B9CA0u: goto label_1b9ca0;
            case 0x1B9CA8u: goto label_1b9ca8;
            case 0x1B9CB4u: goto label_1b9cb4;
            case 0x1B9CB8u: goto label_1b9cb8;
            case 0x1B9CBCu: goto label_1b9cbc;
            case 0x1B9CE0u: goto label_1b9ce0;
            case 0x1B9D24u: goto label_1b9d24;
            case 0x1B9D68u: goto label_1b9d68;
            case 0x1B9D98u: goto label_1b9d98;
            case 0x1B9DB8u: goto label_1b9db8;
            case 0x1B9DBCu: goto label_1b9dbc;
            case 0x1B9DECu: goto label_1b9dec;
            case 0x1B9E0Cu: goto label_1b9e0c;
            case 0x1B9E10u: goto label_1b9e10;
            case 0x1B9E40u: goto label_1b9e40;
            case 0x1B9E48u: goto label_1b9e48;
            case 0x1B9E50u: goto label_1b9e50;
            case 0x1B9E64u: goto label_1b9e64;
            case 0x1B9E68u: goto label_1b9e68;
            case 0x1B9EC4u: goto label_1b9ec4;
            case 0x1B9EF4u: goto label_1b9ef4;
            case 0x1B9F08u: goto label_1b9f08;
            case 0x1B9F10u: goto label_1b9f10;
            case 0x1B9F3Cu: goto label_1b9f3c;
            case 0x1B9F70u: goto label_1b9f70;
            case 0x1B9FC4u: goto label_1b9fc4;
            case 0x1B9FE8u: goto label_1b9fe8;
            case 0x1B9FF0u: goto label_1b9ff0;
            case 0x1BA010u: goto label_1ba010;
            case 0x1BA024u: goto label_1ba024;
            case 0x1BA028u: goto label_1ba028;
            case 0x1BA068u: goto label_1ba068;
            case 0x1BA090u: goto label_1ba090;
            case 0x1BA0B4u: goto label_1ba0b4;
            case 0x1BA0BCu: goto label_1ba0bc;
            case 0x1BA0D4u: goto label_1ba0d4;
            case 0x1BA0E0u: goto label_1ba0e0;
            case 0x1BA0E4u: goto label_1ba0e4;
            case 0x1BA12Cu: goto label_1ba12c;
            case 0x1BA150u: goto label_1ba150;
            case 0x1BA154u: goto label_1ba154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA038u;
    // 0x1ba038: 0x0  nop
    ctx->pc = 0x1ba038u;
    // NOP
    // 0x1ba03c: 0x0  nop
    ctx->pc = 0x1ba03cu;
    // NOP
    // 0x1ba040: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1ba040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1ba044: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1ba044u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1ba048: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ba048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ba04c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ba04cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ba050: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ba050u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ba054: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1ba054u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba058: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x1ba058u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1ba05c: 0x80304c11  lb          $s0, 0x4C11($at)
    ctx->pc = 0x1ba05cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 19473)));
    // 0x1ba060: 0xc06e65c  jal         func_1B9970
    ctx->pc = 0x1BA060u;
    SET_GPR_U32(ctx, 31, 0x1BA068u);
    ctx->pc = 0x1BA064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA060u;
            // 0x1ba064: 0x27a50038  addiu       $a1, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B9970u;
    goto label_1b9970;
    ctx->pc = 0x1BA068u;
label_1ba068:
    // 0x1ba068: 0x82230004  lb          $v1, 0x4($s1)
    ctx->pc = 0x1ba068u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ba06c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1ba06cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba070: 0x10640037  beq         $v1, $a0, . + 4 + (0x37 << 2)
    ctx->pc = 0x1BA070u;
    {
        const bool branch_taken_0x1ba070 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1BA074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA070u;
            // 0x1ba074: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba070) {
            ctx->pc = 0x1BA150u;
            goto label_1ba150;
        }
    }
    ctx->pc = 0x1BA078u;
    // 0x1ba078: 0x1068001a  beq         $v1, $t0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1BA078u;
    {
        const bool branch_taken_0x1ba078 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        if (branch_taken_0x1ba078) {
            ctx->pc = 0x1BA0E4u;
            goto label_1ba0e4;
        }
    }
    ctx->pc = 0x1BA080u;
    // 0x1ba080: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA080u;
    {
        const bool branch_taken_0x1ba080 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba080) {
            ctx->pc = 0x1BA090u;
            goto label_1ba090;
        }
    }
    ctx->pc = 0x1BA088u;
    // 0x1ba088: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1BA088u;
    {
        const bool branch_taken_0x1ba088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA088u;
            // 0x1ba08c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba088) {
            ctx->pc = 0x1BA154u;
            goto label_1ba154;
        }
    }
    ctx->pc = 0x1BA090u;
label_1ba090:
    // 0x1ba090: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ba090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ba094: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BA094u;
    {
        const bool branch_taken_0x1ba094 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA094u;
            // 0x1ba098: 0xa2230004  sb          $v1, 0x4($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba094) {
            ctx->pc = 0x1BA0BCu;
            goto label_1ba0bc;
        }
    }
    ctx->pc = 0x1BA09Cu;
    // 0x1ba09c: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1ba09cu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1ba0a0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ba0a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0a4: 0x27a70038  addiu       $a3, $sp, 0x38
    ctx->pc = 0x1ba0a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x1ba0a8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1ba0a8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0ac: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1BA0ACu;
    SET_GPR_U32(ctx, 31, 0x1BA0B4u);
    ctx->pc = 0x1BA0B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA0ACu;
            // 0x1ba0b0: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA0B4u; }
        if (ctx->pc != 0x1BA0B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA0B4u; }
        if (ctx->pc != 0x1BA0B4u) { return; }
    }
    ctx->pc = 0x1BA0B4u;
label_1ba0b4:
    // 0x1ba0b4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1BA0B4u;
    {
        const bool branch_taken_0x1ba0b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA0B4u;
            // 0x1ba0b8: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba0b4) {
            ctx->pc = 0x1BA0E0u;
            goto label_1ba0e0;
        }
    }
    ctx->pc = 0x1BA0BCu;
label_1ba0bc:
    // 0x1ba0bc: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1ba0bcu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1ba0c0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ba0c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0c4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1ba0c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0c8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1ba0c8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba0cc: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1BA0CCu;
    SET_GPR_U32(ctx, 31, 0x1BA0D4u);
    ctx->pc = 0x1BA0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA0CCu;
            // 0x1ba0d0: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA0D4u; }
        if (ctx->pc != 0x1BA0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA0D4u; }
        if (ctx->pc != 0x1BA0D4u) { return; }
    }
    ctx->pc = 0x1BA0D4u;
label_1ba0d4:
    // 0x1ba0d4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ba0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba0d8: 0xa2230004  sb          $v1, 0x4($s1)
    ctx->pc = 0x1ba0d8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ba0dc: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1ba0dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_1ba0e0:
    // 0x1ba0e0: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1ba0e0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
label_1ba0e4:
    // 0x1ba0e4: 0x86230008  lh          $v1, 0x8($s1)
    ctx->pc = 0x1ba0e4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1ba0e8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1ba0e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1ba0ec: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1ba0ecu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ba0f0: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1ba0f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1ba0f4: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1ba0f4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1ba0f8: 0x4610015  bgez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1BA0F8u;
    {
        const bool branch_taken_0x1ba0f8 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x1ba0f8) {
            ctx->pc = 0x1BA150u;
            goto label_1ba150;
        }
    }
    ctx->pc = 0x1BA100u;
    // 0x1ba100: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1ba100u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1ba104: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1ba104u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ba108: 0xa6220008  sh          $v0, 0x8($s1)
    ctx->pc = 0x1ba108u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ba10c: 0x27a40038  addiu       $a0, $sp, 0x38
    ctx->pc = 0x1ba10cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x1ba110: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1ba110u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1ba114: 0x27a6004c  addiu       $a2, $sp, 0x4C
    ctx->pc = 0x1ba114u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
    // 0x1ba118: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1ba118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1ba11c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ba11cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ba120: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1ba120u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ba124: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1BA124u;
    SET_GPR_U32(ctx, 31, 0x1BA12Cu);
    ctx->pc = 0x1BA128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA124u;
            // 0x1ba128: 0x27a70048  addiu       $a3, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA12Cu; }
        if (ctx->pc != 0x1BA12Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA12Cu; }
        if (ctx->pc != 0x1BA12Cu) { return; }
    }
    ctx->pc = 0x1BA12Cu;
label_1ba12c:
    // 0x1ba12c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BA12Cu;
    {
        const bool branch_taken_0x1ba12c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba12c) {
            ctx->pc = 0x1BA150u;
            goto label_1ba150;
        }
    }
    ctx->pc = 0x1BA134u;
    // 0x1ba134: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1ba134u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1ba138: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1ba138u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba13c: 0x8fa7004c  lw          $a3, 0x4C($sp)
    ctx->pc = 0x1ba13cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1ba140: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ba140u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba144: 0x8fa80048  lw          $t0, 0x48($sp)
    ctx->pc = 0x1ba144u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1ba148: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1BA148u;
    SET_GPR_U32(ctx, 31, 0x1BA150u);
    ctx->pc = 0x1BA14Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA148u;
            // 0x1ba14c: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA150u; }
        if (ctx->pc != 0x1BA150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA150u; }
        if (ctx->pc != 0x1BA150u) { return; }
    }
    ctx->pc = 0x1BA150u;
label_1ba150:
    // 0x1ba150: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ba150u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1ba154:
    // 0x1ba154: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ba154u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ba158: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba158u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba15c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA15Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA15Cu;
            // 0x1ba160: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9970u: goto label_1b9970;
            case 0x1B999Cu: goto label_1b999c;
            case 0x1B99B8u: goto label_1b99b8;
            case 0x1B99D4u: goto label_1b99d4;
            case 0x1B99F0u: goto label_1b99f0;
            case 0x1B9A0Cu: goto label_1b9a0c;
            case 0x1B9A28u: goto label_1b9a28;
            case 0x1B9A38u: goto label_1b9a38;
            case 0x1B9A58u: goto label_1b9a58;
            case 0x1B9AC0u: goto label_1b9ac0;
            case 0x1B9AC8u: goto label_1b9ac8;
            case 0x1B9AECu: goto label_1b9aec;
            case 0x1B9AF4u: goto label_1b9af4;
            case 0x1B9B10u: goto label_1b9b10;
            case 0x1B9B3Cu: goto label_1b9b3c;
            case 0x1B9B44u: goto label_1b9b44;
            case 0x1B9B68u: goto label_1b9b68;
            case 0x1B9B6Cu: goto label_1b9b6c;
            case 0x1B9B8Cu: goto label_1b9b8c;
            case 0x1B9BE8u: goto label_1b9be8;
            case 0x1B9C14u: goto label_1b9c14;
            case 0x1B9C54u: goto label_1b9c54;
            case 0x1B9C70u: goto label_1b9c70;
            case 0x1B9C78u: goto label_1b9c78;
            case 0x1B9C88u: goto label_1b9c88;
            case 0x1B9CA0u: goto label_1b9ca0;
            case 0x1B9CA8u: goto label_1b9ca8;
            case 0x1B9CB4u: goto label_1b9cb4;
            case 0x1B9CB8u: goto label_1b9cb8;
            case 0x1B9CBCu: goto label_1b9cbc;
            case 0x1B9CE0u: goto label_1b9ce0;
            case 0x1B9D24u: goto label_1b9d24;
            case 0x1B9D68u: goto label_1b9d68;
            case 0x1B9D98u: goto label_1b9d98;
            case 0x1B9DB8u: goto label_1b9db8;
            case 0x1B9DBCu: goto label_1b9dbc;
            case 0x1B9DECu: goto label_1b9dec;
            case 0x1B9E0Cu: goto label_1b9e0c;
            case 0x1B9E10u: goto label_1b9e10;
            case 0x1B9E40u: goto label_1b9e40;
            case 0x1B9E48u: goto label_1b9e48;
            case 0x1B9E50u: goto label_1b9e50;
            case 0x1B9E64u: goto label_1b9e64;
            case 0x1B9E68u: goto label_1b9e68;
            case 0x1B9EC4u: goto label_1b9ec4;
            case 0x1B9EF4u: goto label_1b9ef4;
            case 0x1B9F08u: goto label_1b9f08;
            case 0x1B9F10u: goto label_1b9f10;
            case 0x1B9F3Cu: goto label_1b9f3c;
            case 0x1B9F70u: goto label_1b9f70;
            case 0x1B9FC4u: goto label_1b9fc4;
            case 0x1B9FE8u: goto label_1b9fe8;
            case 0x1B9FF0u: goto label_1b9ff0;
            case 0x1BA010u: goto label_1ba010;
            case 0x1BA024u: goto label_1ba024;
            case 0x1BA028u: goto label_1ba028;
            case 0x1BA068u: goto label_1ba068;
            case 0x1BA090u: goto label_1ba090;
            case 0x1BA0B4u: goto label_1ba0b4;
            case 0x1BA0BCu: goto label_1ba0bc;
            case 0x1BA0D4u: goto label_1ba0d4;
            case 0x1BA0E0u: goto label_1ba0e0;
            case 0x1BA0E4u: goto label_1ba0e4;
            case 0x1BA12Cu: goto label_1ba12c;
            case 0x1BA150u: goto label_1ba150;
            case 0x1BA154u: goto label_1ba154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA164u;
    // 0x1ba164: 0x0  nop
    ctx->pc = 0x1ba164u;
    // NOP
    // 0x1ba168: 0x0  nop
    ctx->pc = 0x1ba168u;
    // NOP
    // 0x1ba16c: 0x0  nop
    ctx->pc = 0x1ba16cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
