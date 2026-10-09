#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E4818
// Address: 0x1e4818 - 0x1e4b38
void sub_001E4818_0x1e4818(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E4818_0x1e4818");
#endif

    switch (ctx->pc) {
        case 0x1e4918u: goto label_1e4918;
        case 0x1e4974u: goto label_1e4974;
        case 0x1e4998u: goto label_1e4998;
        case 0x1e4a08u: goto label_1e4a08;
        case 0x1e4ac0u: goto label_1e4ac0;
        case 0x1e4b00u: goto label_1e4b00;
        default: break;
    }

    ctx->pc = 0x1e4818u;

    // 0x1e4818: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1e4818u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1e481c: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e481cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e4820: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e4820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e4824: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e4824u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4828: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e4828u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e482c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e482cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e4830: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e4830u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e4834: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e4834u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4838: 0xffc90068  sd          $t1, 0x68($fp)
    ctx->pc = 0x1e4838u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 104), GPR_U64(ctx, 9));
    // 0x1e483c: 0xffca0070  sd          $t2, 0x70($fp)
    ctx->pc = 0x1e483cu;
    WRITE64(ADD32(GPR_U32(ctx, 30), 112), GPR_U64(ctx, 10));
    // 0x1e4840: 0xffcb0078  sd          $t3, 0x78($fp)
    ctx->pc = 0x1e4840u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 120), GPR_U64(ctx, 11));
    // 0x1e4844: 0xe7cc0048  swc1        $f12, 0x48($fp)
    ctx->pc = 0x1e4844u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 72), bits); }
    // 0x1e4848: 0xe7cd004c  swc1        $f13, 0x4C($fp)
    ctx->pc = 0x1e4848u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 76), bits); }
    // 0x1e484c: 0xe7ce0050  swc1        $f14, 0x50($fp)
    ctx->pc = 0x1e484cu;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 80), bits); }
    // 0x1e4850: 0xe7cf0054  swc1        $f15, 0x54($fp)
    ctx->pc = 0x1e4850u;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 84), bits); }
    // 0x1e4854: 0xe7d00058  swc1        $f16, 0x58($fp)
    ctx->pc = 0x1e4854u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 88), bits); }
    // 0x1e4858: 0xe7d1005c  swc1        $f17, 0x5C($fp)
    ctx->pc = 0x1e4858u;
    { float f = ctx->f[17]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 92), bits); }
    // 0x1e485c: 0xe7d20060  swc1        $f18, 0x60($fp)
    ctx->pc = 0x1e485cu;
    { float f = ctx->f[18]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 96), bits); }
    // 0x1e4860: 0xe7d30064  swc1        $f19, 0x64($fp)
    ctx->pc = 0x1e4860u;
    { float f = ctx->f[19]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 30), 100), bits); }
    // 0x1e4864: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e4864u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e4868: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e4868u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e486c: 0xafc00024  sw          $zero, 0x24($fp)
    ctx->pc = 0x1e486cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
    // 0x1e4870: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e4870u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4874: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e4874u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e4878: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E4878u;
    {
        const bool branch_taken_0x1e4878 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e4878) {
            ctx->pc = 0x1E48A0u;
            goto label_1e48a0;
        }
    }
    ctx->pc = 0x1E4880u;
    // 0x1e4880: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e4880u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4884: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4884u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4888: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4888u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e488c: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e488cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4890: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4894: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4894u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4898: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4898u;
    {
        const bool branch_taken_0x1e4898 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4898) {
            ctx->pc = 0x1E48B4u;
            goto label_1e48b4;
        }
    }
    ctx->pc = 0x1E48A0u;
label_1e48a0:
    // 0x1e48a0: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e48a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e48a4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e48a4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e48a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e48a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e48ac: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x1E48ACu;
    {
        const bool branch_taken_0x1e48ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e48ac) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E48B4u;
label_1e48b4:
    // 0x1e48b4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e48b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e48b8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e48b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e48bc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e48bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e48c0: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e48c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e48c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e48c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e48c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e48c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e48cc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e48ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e48d0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e48d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e48d4: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e48d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e48d8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E48D8u;
    {
        const bool branch_taken_0x1e48d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e48d8) {
            ctx->pc = 0x1E48F4u;
            goto label_1e48f4;
        }
    }
    ctx->pc = 0x1E48E0u;
    // 0x1e48e0: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e48e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e48e4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e48e4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e48e8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e48e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e48ec: 0x1000008c  b           . + 4 + (0x8C << 2)
    ctx->pc = 0x1E48ECu;
    {
        const bool branch_taken_0x1e48ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e48ec) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E48F4u;
label_1e48f4:
    // 0x1e48f4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e48f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e48f8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e48f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e48fc: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e48fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4900: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4900u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4904: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4908: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e4908u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e490c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e490cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4910: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4910u;
    SET_GPR_U32(ctx, 31, 0x1E4918u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4918u; }
        if (ctx->pc != 0x1E4918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4918u; }
        if (ctx->pc != 0x1E4918u) { return; }
    }
    ctx->pc = 0x1E4918u;
label_1e4918:
    // 0x1e4918: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e4918u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e491c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e491cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4920: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4920u;
    {
        const bool branch_taken_0x1e4920 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4920) {
            ctx->pc = 0x1E493Cu;
            goto label_1e493c;
        }
    }
    ctx->pc = 0x1E4928u;
    // 0x1e4928: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e492c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e492cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4930: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4934: 0x1000007a  b           . + 4 + (0x7A << 2)
    ctx->pc = 0x1E4934u;
    {
        const bool branch_taken_0x1e4934 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4934) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E493Cu;
label_1e493c:
    // 0x1e493c: 0x27c20080  addiu       $v0, $fp, 0x80
    ctx->pc = 0x1e493cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 128));
    // 0x1e4940: 0x2442ffe8  addiu       $v0, $v0, -0x18
    ctx->pc = 0x1e4940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967272));
    // 0x1e4944: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4944u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4948: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4948u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e494c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e494cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4950: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e4950u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4954: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1e4954u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4958: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e495c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e495cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4960: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e4960u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4964: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e4964u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4968: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e4968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e496c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E496Cu;
    SET_GPR_U32(ctx, 31, 0x1E4974u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4974u; }
        if (ctx->pc != 0x1E4974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4974u; }
        if (ctx->pc != 0x1E4974u) { return; }
    }
    ctx->pc = 0x1E4974u;
label_1e4974:
    // 0x1e4974: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4974u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e4978: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e4978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e497c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E497Cu;
    {
        const bool branch_taken_0x1e497c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e497c) {
            ctx->pc = 0x1E49ACu;
            goto label_1e49ac;
        }
    }
    ctx->pc = 0x1E4984u;
    // 0x1e4984: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e4984u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e4988: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e4988u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e498c: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e498cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4990: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E4990u;
    SET_GPR_U32(ctx, 31, 0x1E4998u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4998u; }
        if (ctx->pc != 0x1E4998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4998u; }
        if (ctx->pc != 0x1E4998u) { return; }
    }
    ctx->pc = 0x1E4998u;
label_1e4998:
    // 0x1e4998: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e4998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e499c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e499cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e49a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e49a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e49a4: 0x1000005e  b           . + 4 + (0x5E << 2)
    ctx->pc = 0x1E49A4u;
    {
        const bool branch_taken_0x1e49a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e49a4) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E49ACu;
label_1e49ac:
    // 0x1e49ac: 0x27c6001c  addiu       $a2, $fp, 0x1C
    ctx->pc = 0x1e49acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 28));
    // 0x1e49b0: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e49b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e49b4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e49b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e49b8: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e49b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e49bc: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e49bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e49c0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e49c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e49c4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e49c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e49c8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e49c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e49cc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e49ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e49d0: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e49d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e49d4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e49d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e49d8: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e49d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e49dc: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1e49dcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1e49e0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e49e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e49e4: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e49e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e49e8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e49e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e49ec: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e49ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e49f0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e49f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e49f4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e49f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e49f8: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e49f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e49fc: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e49fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e4a00: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e4a00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e4a04: 0xafc00028  sw          $zero, 0x28($fp)
    ctx->pc = 0x1e4a04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 0));
label_1e4a08:
    // 0x1e4a08: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e4a08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e4a0c: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e4a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4a10: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1e4a10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1e4a14: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E4A14u;
    {
        const bool branch_taken_0x1e4a14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4a14) {
            ctx->pc = 0x1E4A24u;
            goto label_1e4a24;
        }
    }
    ctx->pc = 0x1E4A1Cu;
    // 0x1e4a1c: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1E4A1Cu;
    {
        const bool branch_taken_0x1e4a1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4a1c) {
            ctx->pc = 0x1E4AACu;
            goto label_1e4aac;
        }
    }
    ctx->pc = 0x1E4A24u;
label_1e4a24:
    // 0x1e4a24: 0x27c30014  addiu       $v1, $fp, 0x14
    ctx->pc = 0x1e4a24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1e4a28: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1e4a28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1e4a2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e4a2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4a30: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e4a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e4a34: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e4a34u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e4a38: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1e4a38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e4a3c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e4a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e4a40: 0x27c6001c  addiu       $a2, $fp, 0x1C
    ctx->pc = 0x1e4a40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 28));
    // 0x1e4a44: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e4a44u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e4a48: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4a48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4a4c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e4a4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e4a50: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e4a50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e4a54: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e4a54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4a58: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e4a58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4a5c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e4a60: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4a60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4a64: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e4a64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4a68: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e4a68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4a6c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e4a6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e4a70: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e4a70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4a74: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4a74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4a78: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e4a78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e4a7c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e4a80: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e4a80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e4a84: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4a84u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e4a88: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e4a88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4a8c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e4a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e4a90: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e4a90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e4a94: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e4a94u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e4a98: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e4a98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e4a9c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e4a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e4aa0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e4aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e4aa4: 0x1000ffd8  b           . + 4 + (-0x28 << 2)
    ctx->pc = 0x1E4AA4u;
    {
        const bool branch_taken_0x1e4aa4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4aa4) {
            ctx->pc = 0x1E4A08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e4a08;
        }
    }
    ctx->pc = 0x1E4AACu;
label_1e4aac:
    // 0x1e4aac: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e4aacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e4ab0: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e4ab0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4ab4: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4ab4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4ab8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E4AB8u;
    SET_GPR_U32(ctx, 31, 0x1E4AC0u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4AC0u; }
        if (ctx->pc != 0x1E4AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4AC0u; }
        if (ctx->pc != 0x1E4AC0u) { return; }
    }
    ctx->pc = 0x1E4AC0u;
label_1e4ac0:
    // 0x1e4ac0: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e4ac0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4ac4: 0x3442a400  ori         $v0, $v0, 0xA400
    ctx->pc = 0x1e4ac4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)41984);
    // 0x1e4ac8: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e4ac8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4acc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e4accu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e4ad0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e4ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4ad4: 0x97c30008  lhu         $v1, 0x8($fp)
    ctx->pc = 0x1e4ad4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e4ad8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e4ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e4adc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e4adcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e4ae0: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e4ae0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e4ae4: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1e4ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e4ae8: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e4ae8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e4aec: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e4aecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4af0: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1e4af0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e4af4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4af4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4af8: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E4AF8u;
    SET_GPR_U32(ctx, 31, 0x1E4B00u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4B00u; }
        if (ctx->pc != 0x1E4B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4B00u; }
        if (ctx->pc != 0x1E4B00u) { return; }
    }
    ctx->pc = 0x1E4B00u;
label_1e4b00:
    // 0x1e4b00: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4B00u;
    {
        const bool branch_taken_0x1e4b00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4b00) {
            ctx->pc = 0x1E4B1Cu;
            goto label_1e4b1c;
        }
    }
    ctx->pc = 0x1E4B08u;
    // 0x1e4b08: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4b08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4b0c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4b0cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4b10: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4b10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4b14: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E4B14u;
    {
        const bool branch_taken_0x1e4b14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4b14) {
            ctx->pc = 0x1E4B20u;
            goto label_1e4b20;
        }
    }
    ctx->pc = 0x1E4B1Cu;
label_1e4b1c:
    // 0x1e4b1c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e4b1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4b20:
    // 0x1e4b20: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4b20u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e4b24: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e4b24u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e4b28: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e4b28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e4b2c: 0x27bd0080  addiu       $sp, $sp, 0x80
    ctx->pc = 0x1e4b2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1e4b30: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4B30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E48A0u: goto label_1e48a0;
            case 0x1E48B4u: goto label_1e48b4;
            case 0x1E48F4u: goto label_1e48f4;
            case 0x1E4918u: goto label_1e4918;
            case 0x1E493Cu: goto label_1e493c;
            case 0x1E4974u: goto label_1e4974;
            case 0x1E4998u: goto label_1e4998;
            case 0x1E49ACu: goto label_1e49ac;
            case 0x1E4A08u: goto label_1e4a08;
            case 0x1E4A24u: goto label_1e4a24;
            case 0x1E4AACu: goto label_1e4aac;
            case 0x1E4AC0u: goto label_1e4ac0;
            case 0x1E4B00u: goto label_1e4b00;
            case 0x1E4B1Cu: goto label_1e4b1c;
            case 0x1E4B20u: goto label_1e4b20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E4B38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
