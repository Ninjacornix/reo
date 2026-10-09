#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E51B0
// Address: 0x1e51b0 - 0x1e549c
void sub_001E51B0_0x1e51b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E51B0_0x1e51b0");
#endif

    switch (ctx->pc) {
        case 0x1e52b0u: goto label_1e52b0;
        case 0x1e530cu: goto label_1e530c;
        case 0x1e536cu: goto label_1e536c;
        case 0x1e5424u: goto label_1e5424;
        case 0x1e5464u: goto label_1e5464;
        default: break;
    }

    ctx->pc = 0x1e51b0u;

    // 0x1e51b0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1e51b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1e51b4: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e51b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e51b8: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e51b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e51bc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e51bcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e51c0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e51c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e51c4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e51c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e51c8: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e51c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e51cc: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e51ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e51d0: 0xffc90068  sd          $t1, 0x68($fp)
    ctx->pc = 0x1e51d0u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 104), GPR_U64(ctx, 9));
    // 0x1e51d4: 0xffca0070  sd          $t2, 0x70($fp)
    ctx->pc = 0x1e51d4u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 112), GPR_U64(ctx, 10));
    // 0x1e51d8: 0xffcb0078  sd          $t3, 0x78($fp)
    ctx->pc = 0x1e51d8u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 120), GPR_U64(ctx, 11));
    // 0x1e51dc: 0xe7cc0048  swc1        $f12, 0x48($fp)
    ctx->pc = 0x1e51dcu;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 72), bits); }
    // 0x1e51e0: 0xe7cd004c  swc1        $f13, 0x4C($fp)
    ctx->pc = 0x1e51e0u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 76), bits); }
    // 0x1e51e4: 0xe7ce0050  swc1        $f14, 0x50($fp)
    ctx->pc = 0x1e51e4u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 80), bits); }
    // 0x1e51e8: 0xe7cf0054  swc1        $f15, 0x54($fp)
    ctx->pc = 0x1e51e8u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 84), bits); }
    // 0x1e51ec: 0xe7d00058  swc1        $f16, 0x58($fp)
    ctx->pc = 0x1e51ecu;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 88), bits); }
    // 0x1e51f0: 0xe7d1005c  swc1        $f17, 0x5C($fp)
    ctx->pc = 0x1e51f0u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 92), bits); }
    // 0x1e51f4: 0xe7d20060  swc1        $f18, 0x60($fp)
    ctx->pc = 0x1e51f4u;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 96), bits); }
    // 0x1e51f8: 0xe7d30064  swc1        $f19, 0x64($fp)
    ctx->pc = 0x1e51f8u;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 100), bits); }
    // 0x1e51fc: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e51fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e5200: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e5200u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e5204: 0xafc00024  sw          $zero, 0x24($fp)
    ctx->pc = 0x1e5204u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
    // 0x1e5208: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5208u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e520c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e520cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5210: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5210u;
    {
        const bool branch_taken_0x1e5210 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5210) {
            ctx->pc = 0x1E5238u;
            goto label_1e5238;
        }
    }
    ctx->pc = 0x1E5218u;
    // 0x1e5218: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5218u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e521c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e521cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5220: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5220u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5224: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5224u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5228: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e522c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e522cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5230: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5230u;
    {
        const bool branch_taken_0x1e5230 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5230) {
            ctx->pc = 0x1E524Cu;
            goto label_1e524c;
        }
    }
    ctx->pc = 0x1E5238u;
label_1e5238:
    // 0x1e5238: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e5238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e523c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e523cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5240: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5240u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5244: 0x1000008f  b           . + 4 + (0x8F << 2)
    ctx->pc = 0x1E5244u;
    {
        const bool branch_taken_0x1e5244 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5244) {
            ctx->pc = 0x1E5484u;
            goto label_1e5484;
        }
    }
    ctx->pc = 0x1E524Cu;
label_1e524c:
    // 0x1e524c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e524cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5250: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5250u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5254: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5254u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5258: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e525c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e525cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5260: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5260u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5264: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e5264u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e5268: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e5268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e526c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e526cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5270: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5270u;
    {
        const bool branch_taken_0x1e5270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5270) {
            ctx->pc = 0x1E528Cu;
            goto label_1e528c;
        }
    }
    ctx->pc = 0x1E5278u;
    // 0x1e5278: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5278u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e527c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e527cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5280: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5280u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5284: 0x1000007f  b           . + 4 + (0x7F << 2)
    ctx->pc = 0x1E5284u;
    {
        const bool branch_taken_0x1e5284 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5284) {
            ctx->pc = 0x1E5484u;
            goto label_1e5484;
        }
    }
    ctx->pc = 0x1E528Cu;
label_1e528c:
    // 0x1e528c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e528cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5290: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5290u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5294: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e5294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5298: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e5298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e529c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e529cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e52a0: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e52a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e52a4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e52a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e52a8: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E52A8u;
    SET_GPR_U32(ctx, 31, 0x1E52B0u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E52B0u; }
        if (ctx->pc != 0x1E52B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E52B0u; }
        if (ctx->pc != 0x1E52B0u) { return; }
    }
    ctx->pc = 0x1E52B0u;
label_1e52b0:
    // 0x1e52b0: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e52b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e52b4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e52b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e52b8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E52B8u;
    {
        const bool branch_taken_0x1e52b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e52b8) {
            ctx->pc = 0x1E52D4u;
            goto label_1e52d4;
        }
    }
    ctx->pc = 0x1E52C0u;
    // 0x1e52c0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e52c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e52c4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e52c4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e52c8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e52c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e52cc: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x1E52CCu;
    {
        const bool branch_taken_0x1e52cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e52cc) {
            ctx->pc = 0x1E5484u;
            goto label_1e5484;
        }
    }
    ctx->pc = 0x1E52D4u;
label_1e52d4:
    // 0x1e52d4: 0x27c20080  addiu       $v0, $fp, 0x80
    ctx->pc = 0x1e52d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 128));
    // 0x1e52d8: 0x2442ffe8  addiu       $v0, $v0, -0x18
    ctx->pc = 0x1e52d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967272));
    // 0x1e52dc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e52dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e52e0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e52e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e52e4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e52e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e52e8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e52e8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e52ec: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e52ecu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e52f0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e52f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e52f4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e52f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e52f8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e52f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e52fc: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e52fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5300: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e5300u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5304: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E5304u;
    SET_GPR_U32(ctx, 31, 0x1E530Cu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E530Cu; }
        if (ctx->pc != 0x1E530Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E530Cu; }
        if (ctx->pc != 0x1E530Cu) { return; }
    }
    ctx->pc = 0x1E530Cu;
label_1e530c:
    // 0x1e530c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e530cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e5310: 0x27c6001c  addiu       $a2, $fp, 0x1C
    ctx->pc = 0x1e5310u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 28));
    // 0x1e5314: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e5314u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e5318: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5318u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e531c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e531cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e5320: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e5320u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e5324: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5324u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5328: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e5328u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e532c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e532cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e5330: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5330u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5334: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e5334u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5338: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e5338u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e533c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e533cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e5340: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e5340u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e5344: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5344u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5348: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e5348u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e534c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e534cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e5350: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e5350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e5354: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5354u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5358: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5358u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e535c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e535cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e5360: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e5360u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e5364: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e5364u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e5368: 0xafc00028  sw          $zero, 0x28($fp)
    ctx->pc = 0x1e5368u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 0));
label_1e536c:
    // 0x1e536c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e536cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e5370: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e5370u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5374: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1e5374u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1e5378: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E5378u;
    {
        const bool branch_taken_0x1e5378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e5378) {
            ctx->pc = 0x1E5388u;
            goto label_1e5388;
        }
    }
    ctx->pc = 0x1E5380u;
    // 0x1e5380: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1E5380u;
    {
        const bool branch_taken_0x1e5380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5380) {
            ctx->pc = 0x1E5410u;
            goto label_1e5410;
        }
    }
    ctx->pc = 0x1E5388u;
label_1e5388:
    // 0x1e5388: 0x27c30014  addiu       $v1, $fp, 0x14
    ctx->pc = 0x1e5388u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1e538c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1e538cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1e5390: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e5390u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5394: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e5394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e5398: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e5398u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e539c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1e539cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e53a0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e53a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e53a4: 0x27c6001c  addiu       $a2, $fp, 0x1C
    ctx->pc = 0x1e53a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 28));
    // 0x1e53a8: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e53a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e53ac: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e53acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e53b0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e53b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e53b4: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e53b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e53b8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e53b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e53bc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e53bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e53c0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e53c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e53c4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e53c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e53c8: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e53c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e53cc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e53ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e53d0: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e53d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e53d4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e53d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e53d8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e53d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e53dc: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e53dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e53e0: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e53e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e53e4: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e53e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e53e8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e53e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e53ec: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e53ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e53f0: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e53f0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e53f4: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e53f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e53f8: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e53f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e53fc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e53fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e5400: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e5400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e5404: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e5404u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e5408: 0x1000ffd8  b           . + 4 + (-0x28 << 2)
    ctx->pc = 0x1E5408u;
    {
        const bool branch_taken_0x1e5408 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5408) {
            ctx->pc = 0x1E536Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e536c;
        }
    }
    ctx->pc = 0x1E5410u;
label_1e5410:
    // 0x1e5410: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5410u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5414: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e5414u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5418: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e5418u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e541c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E541Cu;
    SET_GPR_U32(ctx, 31, 0x1E5424u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5424u; }
        if (ctx->pc != 0x1E5424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5424u; }
        if (ctx->pc != 0x1E5424u) { return; }
    }
    ctx->pc = 0x1E5424u;
label_1e5424:
    // 0x1e5424: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e5424u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5428: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e5428u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e542c: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e542cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5430: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5430u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5434: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e5434u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5438: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e5438u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e543c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e543cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e5440: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e5440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e5444: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e5444u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5448: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e5448u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e544c: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e544cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e5450: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e5450u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5454: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1e5454u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e5458: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e5458u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e545c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E545Cu;
    SET_GPR_U32(ctx, 31, 0x1E5464u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5464u; }
        if (ctx->pc != 0x1E5464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5464u; }
        if (ctx->pc != 0x1E5464u) { return; }
    }
    ctx->pc = 0x1E5464u;
label_1e5464:
    // 0x1e5464: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5464u;
    {
        const bool branch_taken_0x1e5464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5464) {
            ctx->pc = 0x1E5480u;
            goto label_1e5480;
        }
    }
    ctx->pc = 0x1E546Cu;
    // 0x1e546c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e546cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e5470: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5470u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5474: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5478: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E5478u;
    {
        const bool branch_taken_0x1e5478 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5478) {
            ctx->pc = 0x1E5484u;
            goto label_1e5484;
        }
    }
    ctx->pc = 0x1E5480u;
label_1e5480:
    // 0x1e5480: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e5480u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e5484:
    // 0x1e5484: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e5484u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5488: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e5488u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e548c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e548cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e5490: 0x27bd0080  addiu       $sp, $sp, 0x80
    ctx->pc = 0x1e5490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1e5494: 0x3e00008  jr          $ra
    ctx->pc = 0x1E5494u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E5238u: goto label_1e5238;
            case 0x1E524Cu: goto label_1e524c;
            case 0x1E528Cu: goto label_1e528c;
            case 0x1E52B0u: goto label_1e52b0;
            case 0x1E52D4u: goto label_1e52d4;
            case 0x1E530Cu: goto label_1e530c;
            case 0x1E536Cu: goto label_1e536c;
            case 0x1E5388u: goto label_1e5388;
            case 0x1E5410u: goto label_1e5410;
            case 0x1E5424u: goto label_1e5424;
            case 0x1E5464u: goto label_1e5464;
            case 0x1E5480u: goto label_1e5480;
            case 0x1E5484u: goto label_1e5484;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E549Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
