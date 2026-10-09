#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EB830
// Address: 0x1eb830 - 0x1f05b4
void sub_001EB830_0x1eb830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EB830_0x1eb830");
#endif

    switch (ctx->pc) {
        case 0x1eb8b8u: goto label_1eb8b8;
        case 0x1eb9bcu: goto label_1eb9bc;
        case 0x1eba48u: goto label_1eba48;
        case 0x1eba68u: goto label_1eba68;
        case 0x1ebaa8u: goto label_1ebaa8;
        case 0x1ebb3cu: goto label_1ebb3c;
        default: break;
    }

    ctx->pc = 0x1eb830u;

    // 0x1eb830: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1eb830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1eb834: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x1eb834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x1eb838: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x1eb838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x1eb83c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1eb83cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb840: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1eb840u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1eb844: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1eb844u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1eb848: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1eb848u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1eb84c: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1eb84cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1eb850: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1eb850u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1eb854: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1eb854u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb858: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb858u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb85c: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x1eb85cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1eb860: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1eb860u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1eb864: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1eb864u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eb868: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eb868u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eb86c: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x1eb86cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1eb870: 0x1040007f  beqz        $v0, . + 4 + (0x7F << 2)
    ctx->pc = 0x1EB870u;
    {
        const bool branch_taken_0x1eb870 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb870) {
            ctx->pc = 0x1EBA70u;
            goto label_1eba70;
        }
    }
    ctx->pc = 0x1EB878u;
    // 0x1eb878: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1eb878u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb87c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eb87cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eb880: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1EB880u;
    {
        const bool branch_taken_0x1eb880 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb880) {
            ctx->pc = 0x1EB8F8u;
            goto label_1eb8f8;
        }
    }
    ctx->pc = 0x1EB888u;
    // 0x1eb888: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb88c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb88cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb890: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1eb890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1eb894: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eb894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eb898: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1eb898u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1eb89c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1eb89cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb8a0: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1eb8a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb8a4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1eb8a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb8a8: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x1eb8a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1eb8ac: 0x8cc60000  lw          $a2, 0x0($a2)
    ctx->pc = 0x1eb8acu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1eb8b0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1EB8B0u;
    SET_GPR_U32(ctx, 31, 0x1EB8B8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB8B8u; }
        if (ctx->pc != 0x1EB8B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB8B8u; }
        if (ctx->pc != 0x1EB8B8u) { return; }
    }
    ctx->pc = 0x1EB8B8u;
label_1eb8b8:
    // 0x1eb8b8: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1eb8b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb8bc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eb8bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb8c0: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1eb8c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb8c4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1eb8c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eb8c8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1eb8c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1eb8cc: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1eb8ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eb8d0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1eb8d0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1eb8d4: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1eb8d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb8d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb8d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb8dc: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1eb8dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb8e0: 0x8c44001c  lw          $a0, 0x1C($v0)
    ctx->pc = 0x1eb8e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1eb8e4: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1eb8e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1eb8e8: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1eb8e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eb8ec: 0xaca2001c  sw          $v0, 0x1C($a1)
    ctx->pc = 0x1eb8ecu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 2));
    // 0x1eb8f0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1eb8f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb8f4: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1eb8f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_1eb8f8:
    // 0x1eb8f8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eb8f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb8fc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1EB8FCu;
    {
        const bool branch_taken_0x1eb8fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eb8fc) {
            ctx->pc = 0x1EB910u;
            goto label_1eb910;
        }
    }
    ctx->pc = 0x1EB904u;
    // 0x1eb904: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eb904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eb908: 0x10001324  b           . + 4 + (0x1324 << 2)
    ctx->pc = 0x1EB908u;
    {
        const bool branch_taken_0x1eb908 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb908) {
            ctx->pc = 0x1F059Cu;
            goto label_1f059c;
        }
    }
    ctx->pc = 0x1EB910u;
label_1eb910:
    // 0x1eb910: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb914: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1eb914u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1eb918: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1eb918u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1eb91c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb91cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb920: 0xac40001c  sw          $zero, 0x1C($v0)
    ctx->pc = 0x1eb920u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
    // 0x1eb924: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1eb924u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb928: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1eb928u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1eb92c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1eb92cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1eb930: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1eb930u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb934: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb934u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb938: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x1eb938u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1eb93c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1eb93cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eb940: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eb940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eb944: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1eb944u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb948: 0xac830018  sw          $v1, 0x18($a0)
    ctx->pc = 0x1eb948u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x1eb94c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1eb94cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eb950: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1eb950u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1eb954: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1EB954u;
    {
        const bool branch_taken_0x1eb954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb954) {
            ctx->pc = 0x1EB970u;
            goto label_1eb970;
        }
    }
    ctx->pc = 0x1EB95Cu;
    // 0x1eb95c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb95cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb960: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb964: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1eb964u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1eb968: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1eb968u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1eb96c: 0xac620014  sw          $v0, 0x14($v1)
    ctx->pc = 0x1eb96cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 2));
label_1eb970:
    // 0x1eb970: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb974: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x1eb974u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1eb978: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1EB978u;
    {
        const bool branch_taken_0x1eb978 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eb978) {
            ctx->pc = 0x1EB9B4u;
            goto label_1eb9b4;
        }
    }
    ctx->pc = 0x1EB980u;
    // 0x1eb980: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb980u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb984: 0x27c50014  addiu       $a1, $fp, 0x14
    ctx->pc = 0x1eb984u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1eb988: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1eb988u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1eb98c: 0x24640020  addiu       $a0, $v1, 0x20
    ctx->pc = 0x1eb98cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1eb990: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eb990u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eb994: 0x442021  addu        $a0, $v0, $a0
    ctx->pc = 0x1eb994u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1eb998: 0x2402ff80  addiu       $v0, $zero, -0x80
    ctx->pc = 0x1eb998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x1eb99c: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1eb99cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1eb9a0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1eb9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1eb9a4: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1eb9a4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1eb9a8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb9a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb9ac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eb9acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eb9b0: 0xac620020  sw          $v0, 0x20($v1)
    ctx->pc = 0x1eb9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32), GPR_U32(ctx, 2));
label_1eb9b4:
    // 0x1eb9b4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1eb9b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb9b8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eb9b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_1eb9bc:
    // 0x1eb9bc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1eb9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eb9c0: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x1eb9c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1eb9c4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1EB9C4u;
    {
        const bool branch_taken_0x1eb9c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eb9c4) {
            ctx->pc = 0x1EB9D4u;
            goto label_1eb9d4;
        }
    }
    ctx->pc = 0x1EB9CCu;
    // 0x1eb9cc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1EB9CCu;
    {
        const bool branch_taken_0x1eb9cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb9cc) {
            ctx->pc = 0x1EBA00u;
            goto label_1eba00;
        }
    }
    ctx->pc = 0x1EB9D4u;
label_1eb9d4:
    // 0x1eb9d4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eb9d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb9d8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1eb9d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eb9dc: 0x24440020  addiu       $a0, $v0, 0x20
    ctx->pc = 0x1eb9dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
    // 0x1eb9e0: 0x24620004  addiu       $v0, $v1, 0x4
    ctx->pc = 0x1eb9e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eb9e4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1eb9e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1eb9e8: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1eb9e8u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1eb9ec: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1eb9ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eb9f0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1eb9f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1eb9f4: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eb9f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eb9f8: 0x1000fff0  b           . + 4 + (-0x10 << 2)
    ctx->pc = 0x1EB9F8u;
    {
        const bool branch_taken_0x1eb9f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb9f8) {
            ctx->pc = 0x1EB9BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eb9bc;
        }
    }
    ctx->pc = 0x1EBA00u;
label_1eba00:
    // 0x1eba00: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1eba00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eba04: 0x28420039  slti        $v0, $v0, 0x39
    ctx->pc = 0x1eba04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)57) ? 1 : 0);
    // 0x1eba08: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1EBA08u;
    {
        const bool branch_taken_0x1eba08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eba08) {
            ctx->pc = 0x1EBA50u;
            goto label_1eba50;
        }
    }
    ctx->pc = 0x1EBA10u;
    // 0x1eba10: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eba10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba14: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eba14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba18: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1eba18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1eba1c: 0xac62005c  sw          $v0, 0x5C($v1)
    ctx->pc = 0x1eba1cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 92), GPR_U32(ctx, 2));
    // 0x1eba20: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eba20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba24: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eba24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba28: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1eba28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1eba2c: 0xac620060  sw          $v0, 0x60($v1)
    ctx->pc = 0x1eba2cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 96), GPR_U32(ctx, 2));
    // 0x1eba30: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eba30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba34: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1eba34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1eba38: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1eba38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eba3c: 0x24050038  addiu       $a1, $zero, 0x38
    ctx->pc = 0x1eba3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
    // 0x1eba40: 0xc07add9  jal         func_1EB764
    ctx->pc = 0x1EBA40u;
    SET_GPR_U32(ctx, 31, 0x1EBA48u);
    ctx->pc = 0x1EB764u;
    if (runtime->hasFunction(0x1EB764u)) {
        auto targetFn = runtime->lookupFunction(0x1EB764u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EBA48u; }
        if (ctx->pc != 0x1EBA48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB764_0x1eb764(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EBA48u; }
        if (ctx->pc != 0x1EBA48u) { return; }
    }
    ctx->pc = 0x1EBA48u;
label_1eba48:
    // 0x1eba48: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1EBA48u;
    {
        const bool branch_taken_0x1eba48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eba48) {
            ctx->pc = 0x1EBB3Cu;
            goto label_1ebb3c;
        }
    }
    ctx->pc = 0x1EBA50u;
label_1eba50:
    // 0x1eba50: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eba50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba54: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1eba54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1eba58: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1eba58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eba5c: 0x24050040  addiu       $a1, $zero, 0x40
    ctx->pc = 0x1eba5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1eba60: 0xc07add9  jal         func_1EB764
    ctx->pc = 0x1EBA60u;
    SET_GPR_U32(ctx, 31, 0x1EBA68u);
    ctx->pc = 0x1EB764u;
    if (runtime->hasFunction(0x1EB764u)) {
        auto targetFn = runtime->lookupFunction(0x1EB764u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EBA68u; }
        if (ctx->pc != 0x1EBA68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB764_0x1eb764(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EBA68u; }
        if (ctx->pc != 0x1EBA68u) { return; }
    }
    ctx->pc = 0x1EBA68u;
label_1eba68:
    // 0x1eba68: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1EBA68u;
    {
        const bool branch_taken_0x1eba68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eba68) {
            ctx->pc = 0x1EBB3Cu;
            goto label_1ebb3c;
        }
    }
    ctx->pc = 0x1EBA70u;
label_1eba70:
    // 0x1eba70: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eba70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba74: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1eba74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba78: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1eba78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1eba7c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eba7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eba80: 0x24440024  addiu       $a0, $v0, 0x24
    ctx->pc = 0x1eba80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1eba84: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1eba84u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eba88: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eba88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eba8c: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x1eba8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1eba90: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1eba90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1eba94: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1eba94u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eba98: 0x8ca50000  lw          $a1, 0x0($a1)
    ctx->pc = 0x1eba98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1eba9c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1eba9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ebaa0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1EBAA0u;
    SET_GPR_U32(ctx, 31, 0x1EBAA8u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EBAA8u; }
        if (ctx->pc != 0x1EBAA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EBAA8u; }
        if (ctx->pc != 0x1EBAA8u) { return; }
    }
    ctx->pc = 0x1EBAA8u;
label_1ebaa8:
    // 0x1ebaa8: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1ebaa8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ebaac: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1ebaacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1ebab0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1ebab0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebab4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ebab4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ebab8: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x1ebab8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1ebabc: 0x821023  subu        $v0, $a0, $v0
    ctx->pc = 0x1ebabcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebac0: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x1ebac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x1ebac4: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1ebac4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1ebac8: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1ebac8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1ebacc: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1ebaccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1ebad0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1ebad0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebad4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ebad4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ebad8: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x1ebad8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1ebadc: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1ebadcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebae0: 0x2442ffc0  addiu       $v0, $v0, -0x40
    ctx->pc = 0x1ebae0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967232));
    // 0x1ebae4: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1ebae4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1ebae8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebaec: 0xac40001c  sw          $zero, 0x1C($v0)
    ctx->pc = 0x1ebaecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 0));
    // 0x1ebaf0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1ebaf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebaf4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebaf8: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1ebaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1ebafc: 0x24420200  addiu       $v0, $v0, 0x200
    ctx->pc = 0x1ebafcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 512));
    // 0x1ebb00: 0xac620018  sw          $v0, 0x18($v1)
    ctx->pc = 0x1ebb00u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24), GPR_U32(ctx, 2));
    // 0x1ebb04: 0x2c420200  sltiu       $v0, $v0, 0x200
    ctx->pc = 0x1ebb04u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)512) ? 1 : 0);
    // 0x1ebb08: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1EBB08u;
    {
        const bool branch_taken_0x1ebb08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ebb08) {
            ctx->pc = 0x1EBB24u;
            goto label_1ebb24;
        }
    }
    ctx->pc = 0x1EBB10u;
    // 0x1ebb10: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1ebb10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb14: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebb14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb18: 0x8c420014  lw          $v0, 0x14($v0)
    ctx->pc = 0x1ebb18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1ebb1c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ebb1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ebb20: 0xac620014  sw          $v0, 0x14($v1)
    ctx->pc = 0x1ebb20u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 2));
label_1ebb24:
    // 0x1ebb24: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebb24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb28: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1ebb28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1ebb2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ebb2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ebb30: 0x24050040  addiu       $a1, $zero, 0x40
    ctx->pc = 0x1ebb30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1ebb34: 0xc07add9  jal         func_1EB764
    ctx->pc = 0x1EBB34u;
    SET_GPR_U32(ctx, 31, 0x1EBB3Cu);
    ctx->pc = 0x1EB764u;
    if (runtime->hasFunction(0x1EB764u)) {
        auto targetFn = runtime->lookupFunction(0x1EB764u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EBB3Cu; }
        if (ctx->pc != 0x1EBB3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB764_0x1eb764(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EBB3Cu; }
        if (ctx->pc != 0x1EBB3Cu) { return; }
    }
    ctx->pc = 0x1EBB3Cu;
label_1ebb3c:
    // 0x1ebb3c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebb3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb40: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1ebb40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1ebb44: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebb44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebb48: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebb48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb4c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1ebb4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ebb50: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebb50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ebb54: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebb54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb58: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1ebb58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1ebb5c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ebb5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ebb60: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebb60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb64: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1ebb64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1ebb68: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ebb68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ebb6c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebb6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb70: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x1ebb70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1ebb74: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebb74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ebb78: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ebb78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ebb7c: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1ebb7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1ebb80: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebb80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebb84: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebb84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebb88: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ebb88u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ebb8c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ebb8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ebb90: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ebb90u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebb94: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ebb94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebb98: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebb98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebb9c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ebb9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebba0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebba4: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ebba4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ebba8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebba8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebbac: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ebbacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebbb0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ebbb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebbb4: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebbb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ebbb8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebbb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebbbc: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ebbbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebbc0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ebbc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ebbc4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebbc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebbc8: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ebbc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ebbcc: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ebbccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ebbd0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ebbd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebbd4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ebbd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ebbd8: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ebbd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebbdc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ebbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ebbe0: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebbe0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebbe4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebbe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebbe8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebbe8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebbec: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ebbecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebbf0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebbf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ebbf4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebbf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebbf8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ebbf8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ebbfc: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ebbfcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ebc00: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ebc00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebc04: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ebc04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ebc08: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebc08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebc0c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ebc0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ebc10: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ebc10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ebc14: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebc14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ebc18: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebc18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebc1c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ebc1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ebc20: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ebc20u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ebc24: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ebc24u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebc28: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ebc28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebc2c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebc2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebc30: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ebc30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebc34: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebc34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebc38: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ebc38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ebc3c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebc3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebc40: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ebc40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebc44: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ebc44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebc48: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebc48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ebc4c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebc4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebc50: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ebc50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebc54: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ebc54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ebc58: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebc58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebc5c: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ebc5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ebc60: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ebc60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ebc64: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ebc64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebc68: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ebc68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ebc6c: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ebc6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebc70: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ebc70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ebc74: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebc74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebc78: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebc78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebc7c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebc7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebc80: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ebc80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebc84: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebc84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ebc88: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebc88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebc8c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ebc8cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ebc90: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ebc90u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ebc94: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ebc94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebc98: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ebc98u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ebc9c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebc9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebca0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ebca0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ebca4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ebca4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ebca8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebca8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ebcac: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebcacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebcb0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ebcb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ebcb4: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ebcb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ebcb8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ebcb8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebcbc: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ebcbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebcc0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebcc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebcc4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ebcc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebcc8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebcc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebccc: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ebcccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ebcd0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebcd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebcd4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ebcd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebcd8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ebcd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebcdc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebcdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ebce0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebce0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebce4: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ebce4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebce8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ebce8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ebcec: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebcecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebcf0: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ebcf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ebcf4: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ebcf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ebcf8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ebcf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebcfc: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ebcfcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ebd00: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ebd00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebd04: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ebd04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ebd08: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebd08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebd0c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebd0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebd10: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebd10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebd14: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ebd14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebd18: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebd18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ebd1c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebd1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebd20: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ebd20u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ebd24: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ebd24u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ebd28: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ebd28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebd2c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ebd2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ebd30: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebd30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebd34: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ebd34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ebd38: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ebd38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ebd3c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebd3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ebd40: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebd40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebd44: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ebd44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ebd48: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ebd48u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ebd4c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ebd4cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebd50: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ebd50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebd54: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebd54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebd58: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ebd58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebd5c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebd5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebd60: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ebd60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ebd64: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebd64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebd68: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ebd68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebd6c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ebd6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebd70: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebd70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ebd74: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebd74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebd78: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ebd78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebd7c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ebd7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ebd80: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebd80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebd84: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ebd84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ebd88: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ebd88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ebd8c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ebd8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebd90: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ebd90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ebd94: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ebd94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebd98: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ebd98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ebd9c: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebd9cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebda0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebda0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebda4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebda4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebda8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ebda8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebdac: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebdacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ebdb0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebdb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebdb4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ebdb4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ebdb8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ebdb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ebdbc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ebdbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebdc0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ebdc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ebdc4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebdc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebdc8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ebdc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ebdcc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ebdccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ebdd0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebdd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ebdd4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebdd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebdd8: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ebdd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ebddc: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ebddcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ebde0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ebde0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebde4: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ebde4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebde8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebde8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebdec: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ebdecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebdf0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebdf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebdf4: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ebdf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ebdf8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebdf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebdfc: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ebdfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebe00: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ebe00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebe04: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebe04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ebe08: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebe08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebe0c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ebe0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebe10: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ebe10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ebe14: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebe14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebe18: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ebe18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ebe1c: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ebe1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ebe20: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ebe20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebe24: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ebe24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ebe28: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ebe28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebe2c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ebe2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ebe30: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebe30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebe34: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebe34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebe38: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebe38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebe3c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ebe3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebe40: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebe40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ebe44: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebe44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebe48: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ebe48u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ebe4c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ebe4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ebe50: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ebe50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebe54: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ebe54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ebe58: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebe58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebe5c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ebe5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ebe60: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ebe60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ebe64: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebe64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ebe68: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebe68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebe6c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ebe6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ebe70: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ebe70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ebe74: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ebe74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebe78: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ebe78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebe7c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebe7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebe80: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ebe80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebe84: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebe84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebe88: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ebe88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ebe8c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebe8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebe90: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ebe90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebe94: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ebe94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebe98: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebe98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ebe9c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebe9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebea0: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ebea0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebea4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ebea4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ebea8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebea8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebeac: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ebeacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ebeb0: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ebeb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ebeb4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ebeb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebeb8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ebeb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ebebc: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ebebcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebec0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ebec0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ebec4: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebec4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebec8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebecc: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebeccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebed0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ebed0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebed4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebed4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ebed8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebed8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebedc: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ebedcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ebee0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ebee0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ebee4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ebee4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebee8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ebee8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ebeec: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebeecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebef0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ebef0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ebef4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ebef4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ebef8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebef8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ebefc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebefcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebf00: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ebf00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ebf04: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ebf04u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ebf08: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ebf08u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebf0c: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ebf0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebf10: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebf10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebf14: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ebf14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebf18: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebf18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebf1c: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ebf1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ebf20: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebf20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebf24: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ebf24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebf28: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ebf28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebf2c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebf2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ebf30: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebf30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebf34: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ebf34u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebf38: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ebf38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ebf3c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebf3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebf40: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ebf40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ebf44: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ebf44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ebf48: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ebf48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebf4c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ebf4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ebf50: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ebf50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebf54: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ebf54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ebf58: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebf58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebf5c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebf5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebf60: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebf60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebf64: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ebf64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebf68: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebf68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ebf6c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebf6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebf70: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ebf70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ebf74: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ebf74u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ebf78: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ebf78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebf7c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ebf7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ebf80: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebf80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebf84: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ebf84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ebf88: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ebf88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ebf8c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebf8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ebf90: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ebf90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ebf94: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ebf94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ebf98: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ebf98u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ebf9c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ebf9cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ebfa0: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ebfa0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebfa4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebfa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebfa8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ebfa8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebfac: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ebfacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ebfb0: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ebfb0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ebfb4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebfb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebfb8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ebfb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ebfbc: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ebfbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ebfc0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebfc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ebfc4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebfc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebfc8: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ebfc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebfcc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ebfccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ebfd0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ebfd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebfd4: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ebfd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ebfd8: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ebfd8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ebfdc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ebfdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ebfe0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ebfe0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ebfe4: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ebfe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ebfe8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ebfe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ebfec: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ebfecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ebff0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ebff0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ebff4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ebff4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ebff8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ebff8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ebffc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ebffcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec000: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec004: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec004u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec008: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec008u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec00c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec00cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec010: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec010u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec014: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec018: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec018u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec01c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec01cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec020: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec020u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec024: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec024u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec028: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec028u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec02c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec02cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec030: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec030u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec034: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec034u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec038: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec03c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec03cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec040: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec044: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec044u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec048: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec048u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec04c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec04cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec050: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec050u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec054: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec058: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec058u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec05c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec05cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec060: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec060u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec064: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec064u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec068: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec068u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec06c: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec06cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec070: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec074: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec074u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec078: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ec078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec07c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec07cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec080: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ec080u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ec084: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec084u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec088: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec088u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec08c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec08cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec090: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec090u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec094: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec098: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec098u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec09c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec09cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec0a0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec0a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec0a4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec0a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec0a8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec0a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec0ac: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec0acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec0b0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec0b4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec0b8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec0b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec0bc: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec0bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec0c0: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec0c4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec0c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec0c8: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec0c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec0cc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec0d0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec0d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec0d4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec0d8: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec0d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec0dc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec0e0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec0e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec0e4: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec0e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec0e8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec0e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec0ec: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec0ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec0f0: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec0f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec0f4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec0f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec0f8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec0f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec0fc: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec100: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec100u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec104: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec104u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec108: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec108u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec10c: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ec10cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec110: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec110u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec114: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ec114u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ec118: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec118u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec11c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec11cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec120: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec120u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec124: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec124u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec128: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec128u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec12c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec12cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec130: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec130u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec134: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec134u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec138: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec138u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec13c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec13cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec140: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec140u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec144: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec148: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec148u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec14c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec14cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec150: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec150u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec154: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec154u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec158: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec158u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec15c: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec15cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec160: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec160u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec164: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec164u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec168: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec16c: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec16cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec170: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec174: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec174u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec178: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec178u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec17c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec17cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec180: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec180u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec184: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec184u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec188: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec18c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec18cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec190: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec190u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec194: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec194u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec198: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec198u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec19c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec19cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec1a0: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ec1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec1a4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec1a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec1a8: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ec1a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ec1ac: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec1acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec1b0: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec1b4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec1b8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec1b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec1bc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec1c0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec1c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec1c4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec1c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec1c8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec1c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec1cc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec1ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec1d0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec1d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec1d4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec1d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec1d8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec1d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec1dc: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec1dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec1e0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec1e4: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec1e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec1e8: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec1e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec1ec: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec1ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec1f0: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec1f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec1f4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec1f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec1f8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec1f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec1fc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec200: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec200u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec204: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec204u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec208: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec208u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec20c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec20cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec210: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec210u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec214: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec214u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec218: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec218u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec21c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec21cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec220: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec224: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec224u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec228: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec228u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec22c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec22cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec230: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec230u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec234: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ec234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec238: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec23c: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ec23cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ec240: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec240u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec244: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec244u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec248: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec248u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec24c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec24cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec250: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec250u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec254: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec254u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec258: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec258u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec25c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec25cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec260: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec260u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec264: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec268: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec268u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec26c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec26cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec270: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec270u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec274: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec274u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec278: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec278u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec27c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec27cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec280: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec280u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec284: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec284u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec288: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec288u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec28c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec28cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec290: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec290u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec294: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec294u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec298: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec298u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec29c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec29cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec2a0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec2a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec2a4: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec2a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec2a8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec2a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec2ac: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec2acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec2b0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec2b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec2b4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec2b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec2b8: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec2bc: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec2bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec2c0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec2c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec2c4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec2c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec2c8: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ec2c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec2cc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec2ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec2d0: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ec2d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ec2d4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec2d8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec2d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec2dc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec2e0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec2e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec2e4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec2e8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec2e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec2ec: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec2ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec2f0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec2f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec2f4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec2f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec2f8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec2f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec2fc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec2fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec300: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec304: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec304u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec308: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec308u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec30c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec30cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec310: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec310u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec314: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec314u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec318: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec318u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec31c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec31cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec320: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec320u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec324: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec324u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec328: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec328u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec32c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec32cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec330: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec330u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec334: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec334u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec338: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec338u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec33c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec33cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec340: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec340u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec344: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec348: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec348u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec34c: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec34cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec350: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec354: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec354u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec358: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec358u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec35c: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ec35cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec360: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec360u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec364: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ec364u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ec368: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec36c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec36cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec370: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec374: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec374u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec378: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec378u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec37c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec37cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec380: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec380u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec384: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec384u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec388: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec388u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec38c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec38cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec390: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec390u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec394: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec398: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec398u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec39c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec39cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec3a0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec3a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec3a4: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec3a8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec3a8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec3ac: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec3acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec3b0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec3b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec3b4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec3b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec3b8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec3b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec3bc: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec3bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec3c0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec3c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec3c4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec3c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec3c8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec3cc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec3d0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec3d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec3d4: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec3d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec3d8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec3d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec3dc: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec3dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec3e0: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec3e4: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec3e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec3e8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec3e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec3ec: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec3ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec3f0: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ec3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec3f4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec3f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec3f8: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ec3f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ec3fc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec3fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec400: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec400u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec404: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec408: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec408u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec40c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec40cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec410: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec410u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec414: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec414u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec418: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec418u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec41c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec41cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec420: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec420u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec424: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec424u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec428: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec428u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec42c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec42cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec430: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec430u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec434: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec434u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec438: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec438u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec43c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec43cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec440: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec440u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec444: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec444u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec448: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec448u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec44c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec44cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec450: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec450u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec454: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec458: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec458u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec45c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec45cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec460: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec460u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec464: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec464u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec468: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec468u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec46c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec46cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec470: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1ec470u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec474: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec474u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec478: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec478u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec47c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec47cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec480: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec480u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec484: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1ec484u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec488: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec48c: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ec48cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ec490: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec494: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec494u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec498: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec498u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec49c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec49cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec4a0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec4a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec4a4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec4a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec4a8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec4a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec4ac: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec4acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec4b0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec4b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec4b4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec4b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec4b8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec4b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec4bc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec4bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec4c0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec4c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec4c4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ec4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ec4c8: 0x24420058  addiu       $v0, $v0, 0x58
    ctx->pc = 0x1ec4c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 88));
    // 0x1ec4cc: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ec4ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ec4d0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ec4d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ec4d4: 0x24420044  addiu       $v0, $v0, 0x44
    ctx->pc = 0x1ec4d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 68));
    // 0x1ec4d8: 0xafc2003c  sw          $v0, 0x3C($fp)
    ctx->pc = 0x1ec4d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 2));
    // 0x1ec4dc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ec4dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ec4e0: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1ec4e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1ec4e4: 0xafc20040  sw          $v0, 0x40($fp)
    ctx->pc = 0x1ec4e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 2));
    // 0x1ec4e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1ec4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ec4ec: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1ec4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1ec4f0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ec4f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ec4f4: 0x8fc40038  lw          $a0, 0x38($fp)
    ctx->pc = 0x1ec4f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec4f8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1ec4f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec4fc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec4fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec500: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec504: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec504u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec508: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ec508u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec50c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec50cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec510: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec510u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec514: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ec514u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec518: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec51c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec51cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec520: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec520u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec524: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ec524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec528: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec52c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ec52cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ec530: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ec530u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec534: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ec534u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ec538: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ec538u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ec53c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec53cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec540: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec540u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec544: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec544u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ec548: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec548u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec54c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec54cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec550: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ec550u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ec554: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec554u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec558: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec558u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec55c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec55cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec560: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec560u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec564: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec564u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec568: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec568u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec56c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec56cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec570: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec574: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec574u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec578: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec57c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec57cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec580: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec580u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec584: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec584u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec588: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ec588u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec58c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ec58cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec590: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ec590u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ec594: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ec594u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ec598: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ec598u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ec59c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ec59cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec5a0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ec5a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ec5a4: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec5a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec5a8: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec5a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec5ac: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec5acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec5b0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec5b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec5b4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec5b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec5b8: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec5b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec5bc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec5bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec5c0: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ec5c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ec5c4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec5c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec5c8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec5c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec5cc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec5d0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec5d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec5d4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec5d8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec5d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec5dc: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec5e0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec5e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec5e4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec5e8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec5ec: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec5ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec5f0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec5f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec5f4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec5f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec5f8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec5f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec5fc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ec5fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ec600: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec600u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec604: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec604u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec608: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec608u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec60c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ec60cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec610: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec610u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec614: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec614u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec618: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ec618u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec61c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec61cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec620: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec620u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec624: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec624u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec628: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ec628u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec62c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec62cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec630: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ec630u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ec634: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ec634u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec638: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ec638u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ec63c: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ec63cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ec640: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec640u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec644: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec644u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec648: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec648u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ec64c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec64cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec650: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec654: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ec654u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ec658: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec65c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec65cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec660: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec660u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec664: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec664u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec668: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec668u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec66c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec66cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec670: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec670u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec674: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec678: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec678u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec67c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec67cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec680: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec680u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec684: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec684u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec688: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec68c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ec68cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec690: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ec690u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec694: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ec694u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ec698: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ec698u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ec69c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ec69cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ec6a0: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ec6a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec6a4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ec6a4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ec6a8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec6a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec6ac: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec6acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec6b0: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec6b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec6b4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec6b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec6b8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec6b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec6bc: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec6bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec6c0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec6c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec6c4: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ec6c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ec6c8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec6c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec6cc: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec6ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec6d0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec6d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec6d4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec6d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec6d8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec6dc: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec6dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec6e0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec6e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec6e4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec6e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec6e8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec6ec: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec6ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec6f0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec6f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec6f4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec6f8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec6fc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec700: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ec700u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ec704: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec704u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec708: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec708u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec70c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec70cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec710: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ec710u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec714: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec714u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec718: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec718u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec71c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ec71cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec720: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec724: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec724u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec728: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec728u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec72c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ec72cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec730: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec734: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ec734u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ec738: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ec738u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec73c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ec73cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ec740: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ec740u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ec744: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec744u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec748: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec748u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec74c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec74cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ec750: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec750u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec754: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec758: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ec758u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ec75c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec75cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec760: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec760u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec764: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec764u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec768: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec768u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec76c: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec76cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec770: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec770u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec774: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec774u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec778: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec778u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec77c: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec77cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec780: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec784: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec784u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec788: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec788u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec78c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec78cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec790: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ec790u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec794: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ec794u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec798: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ec798u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ec79c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ec79cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ec7a0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ec7a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ec7a4: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ec7a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec7a8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ec7a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ec7ac: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec7acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec7b0: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec7b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec7b4: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec7b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec7b8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec7b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec7bc: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec7bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec7c0: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec7c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec7c4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec7c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec7c8: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ec7c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ec7cc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec7ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec7d0: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec7d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec7d4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec7d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec7d8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec7d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec7dc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec7dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec7e0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec7e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec7e4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec7e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec7e8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec7e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec7ec: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec7ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec7f0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec7f4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec7f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec7f8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec7fc: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec7fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec800: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec804: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ec804u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ec808: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec808u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec80c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec80cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec810: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec810u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec814: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ec814u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec818: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec818u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec81c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec81cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec820: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ec820u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec824: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec824u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec828: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec828u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec82c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec82cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec830: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ec830u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec834: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec834u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec838: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ec838u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ec83c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ec83cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec840: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ec840u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ec844: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ec844u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ec848: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec848u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec84c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec84cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec850: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec850u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ec854: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec858: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec85c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ec85cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ec860: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec860u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec864: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec864u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec868: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec868u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec86c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec86cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec870: 0x8fc30024  lw          $v1, 0x24($fp)
    ctx->pc = 0x1ec870u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec874: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec874u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec878: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec878u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec87c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec87cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec880: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x1ec880u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ec884: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec888: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec888u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec88c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec88cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec890: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec894: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ec894u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec898: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ec898u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec89c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ec89cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ec8a0: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ec8a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ec8a4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ec8a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ec8a8: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ec8a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec8ac: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ec8acu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ec8b0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec8b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec8b4: 0x3c025a82  lui         $v0, 0x5A82
    ctx->pc = 0x1ec8b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)23170 << 16));
    // 0x1ec8b8: 0x34427999  ori         $v0, $v0, 0x7999
    ctx->pc = 0x1ec8b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)31129);
    // 0x1ec8bc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec8bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec8c0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec8c4: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec8c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec8c8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec8c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec8cc: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ec8ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ec8d0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec8d4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec8d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec8d8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec8d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec8dc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec8dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec8e0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec8e4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec8e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec8e8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec8e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec8ec: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec8ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec8f0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec8f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec8f4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec8f8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec8f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec8fc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec8fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec900: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec900u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ec904: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec908: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ec908u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ec90c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec90cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec910: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec914: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec914u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec918: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ec918u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec91c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec91cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec920: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec920u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec924: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ec924u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec928: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ec928u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ec92c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec92cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec930: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec930u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec934: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ec934u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ec938: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec93c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ec93cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ec940: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ec940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ec944: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ec944u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ec948: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ec948u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ec94c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec94cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ec950: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec950u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec954: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ec954u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ec958: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ec958u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ec95c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ec95cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ec960: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ec960u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ec964: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec964u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec968: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ec968u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ec96c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ec96cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ec970: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ec970u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec974: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ec974u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec978: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec97c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ec97cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec980: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec980u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec984: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ec984u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ec988: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec988u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec98c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec98cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ec990: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ec990u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec994: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ec994u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec998: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ec998u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ec99c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ec99cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ec9a0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ec9a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ec9a4: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ec9a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec9a8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ec9a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ec9ac: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ec9acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ec9b0: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ec9b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ec9b4: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ec9b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ec9b8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ec9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ec9bc: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ec9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ec9c0: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ec9c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ec9c4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ec9c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ec9c8: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ec9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ec9cc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ec9ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ec9d0: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ec9d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ec9d4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ec9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ec9d8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ec9d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ec9dc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ec9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ec9e0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ec9e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ec9e4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ec9e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ec9e8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ec9e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ec9ec: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ec9ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ec9f0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec9f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ec9f4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ec9f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ec9f8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ec9f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ec9fc: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ec9fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eca00: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eca00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eca04: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eca04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eca08: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eca08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eca0c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eca0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eca10: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eca10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eca14: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eca14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eca18: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eca18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eca1c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eca1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eca20: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1eca20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eca24: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eca24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eca28: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eca28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eca2c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eca2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eca30: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eca30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eca34: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eca34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eca38: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1eca38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1eca3c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1eca3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eca40: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1eca40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eca44: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1eca44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1eca48: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eca48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eca4c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eca4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eca50: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1eca50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1eca54: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eca54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eca58: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eca58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eca5c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1eca5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1eca60: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eca60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eca64: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1eca64u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1eca68: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1eca68u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1eca6c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1eca6cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eca70: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eca70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eca74: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eca74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eca78: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eca78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eca7c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eca7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eca80: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eca80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eca84: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eca84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eca88: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eca88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eca8c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1eca8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eca90: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eca90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eca94: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1eca94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1eca98: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1eca98u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1eca9c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1eca9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ecaa0: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ecaa0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecaa4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ecaa4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ecaa8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecaa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecaac: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ecaacu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ecab0: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ecab0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ecab4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ecab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecab8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecab8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ecabc: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ecabcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecac0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ecac0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ecac4: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ecac4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ecac8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ecac8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecacc: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecaccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ecad0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecad4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ecad4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ecad8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ecad8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ecadc: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ecadcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ecae0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ecae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ecae4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ecae4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecae8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ecae8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ecaec: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecaecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecaf0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ecaf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ecaf4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ecaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecaf8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecaf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ecafc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ecafcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecb00: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ecb00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ecb04: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecb04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecb08: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecb08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecb0c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecb0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecb10: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ecb10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ecb14: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecb14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecb18: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecb18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecb1c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ecb1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ecb20: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecb20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecb24: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ecb24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecb28: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecb28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ecb2c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ecb2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ecb30: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ecb30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ecb34: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ecb34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ecb38: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ecb38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ecb3c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ecb3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ecb40: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ecb40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ecb44: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecb44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecb48: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ecb48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ecb4c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecb4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ecb50: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ecb50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecb54: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ecb54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ecb58: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ecb58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ecb5c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecb5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecb60: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ecb60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ecb64: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ecb64u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ecb68: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ecb68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecb6c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ecb6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ecb70: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecb70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecb74: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecb74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecb78: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ecb78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecb7c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ecb7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecb80: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecb80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecb84: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecb84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ecb88: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ecb88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecb8c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ecb8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecb90: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ecb90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ecb94: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ecb94u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ecb98: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ecb98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ecb9c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ecb9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecba0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ecba0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ecba4: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecba4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecba8: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ecba8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ecbac: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ecbacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ecbb0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ecbb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecbb4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecbb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ecbb8: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ecbb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecbbc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ecbbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ecbc0: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ecbc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ecbc4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ecbc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecbc8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecbc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ecbcc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecbccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecbd0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ecbd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ecbd4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ecbd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ecbd8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ecbd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ecbdc: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ecbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ecbe0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ecbe0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecbe4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ecbe4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ecbe8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecbe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecbec: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ecbecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ecbf0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ecbf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecbf4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecbf4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ecbf8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ecbf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecbfc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ecbfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ecc00: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecc00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecc04: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecc04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecc08: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecc08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecc0c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ecc0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ecc10: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecc10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecc14: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecc14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecc18: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ecc18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ecc1c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecc1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecc20: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ecc20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecc24: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecc24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ecc28: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ecc28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ecc2c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ecc2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ecc30: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ecc30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ecc34: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ecc34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ecc38: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ecc38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ecc3c: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ecc3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ecc40: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecc40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecc44: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ecc44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ecc48: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecc48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ecc4c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ecc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecc50: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ecc50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ecc54: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ecc54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ecc58: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecc58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecc5c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ecc5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ecc60: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ecc60u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ecc64: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ecc64u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecc68: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ecc68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ecc6c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecc6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecc70: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecc70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecc74: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ecc74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecc78: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ecc78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecc7c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecc7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecc80: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecc80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ecc84: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ecc84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecc88: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ecc88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecc8c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ecc8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ecc90: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ecc90u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ecc94: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ecc94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ecc98: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ecc98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecc9c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ecc9cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ecca0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecca0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecca4: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ecca4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ecca8: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ecca8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1eccac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eccacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eccb0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eccb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eccb4: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eccb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eccb8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eccb8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eccbc: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eccbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eccc0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eccc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eccc4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eccc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eccc8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eccc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecccc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eccccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eccd0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eccd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eccd4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eccd4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eccd8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eccd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eccdc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eccdcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecce0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ecce0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ecce4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecce4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecce8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ecce8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eccec: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eccecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eccf0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eccf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eccf4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eccf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eccf8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eccf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eccfc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eccfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecd00: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecd00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecd04: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecd04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecd08: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ecd08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ecd0c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecd0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecd10: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecd10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecd14: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ecd14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ecd18: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecd18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecd1c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ecd1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecd20: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecd20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ecd24: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ecd24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ecd28: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ecd28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ecd2c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ecd2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ecd30: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ecd30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ecd34: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ecd34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ecd38: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ecd38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ecd3c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecd3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecd40: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ecd40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ecd44: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecd44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ecd48: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ecd48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecd4c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ecd4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ecd50: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ecd50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ecd54: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecd54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecd58: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ecd58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ecd5c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ecd5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ecd60: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ecd60u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecd64: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ecd64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ecd68: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecd68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecd6c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecd6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecd70: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ecd70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecd74: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ecd74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecd78: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecd78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecd7c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecd7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ecd80: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ecd80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecd84: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ecd84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecd88: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ecd88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ecd8c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ecd8cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ecd90: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ecd90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ecd94: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ecd94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecd98: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ecd98u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ecd9c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecd9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecda0: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ecda0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ecda4: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ecda4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ecda8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ecda8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecdac: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecdacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ecdb0: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ecdb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecdb4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ecdb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ecdb8: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ecdb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ecdbc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ecdbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecdc0: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecdc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ecdc4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecdc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecdc8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ecdc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ecdcc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ecdccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ecdd0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ecdd0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ecdd4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ecdd4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ecdd8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ecdd8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecddc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ecddcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ecde0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecde0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecde4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ecde4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ecde8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ecde8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecdec: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecdecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ecdf0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ecdf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecdf4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ecdf4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ecdf8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecdf8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecdfc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecdfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ece00: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ece00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ece04: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ece04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ece08: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ece08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ece0c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ece0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ece10: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ece10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ece14: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ece14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ece18: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ece18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ece1c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ece1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ece20: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ece20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ece24: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ece24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ece28: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ece28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ece2c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ece2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ece30: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ece30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ece34: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ece34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ece38: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ece38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ece3c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ece3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ece40: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ece40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ece44: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ece44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ece48: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ece48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ece4c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ece4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ece50: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ece50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ece54: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ece54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ece58: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ece58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ece5c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ece5cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ece60: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ece60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ece64: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ece64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ece68: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ece68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ece6c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ece6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ece70: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ece70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ece74: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ece74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ece78: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ece78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ece7c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ece7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ece80: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ece80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ece84: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ece84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ece88: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ece88u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ece8c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ece8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ece90: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ece90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ece94: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ece94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ece98: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ece98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ece9c: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ece9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ecea0: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ecea0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ecea4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ecea4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecea8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecea8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eceac: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eceacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eceb0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eceb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eceb4: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eceb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eceb8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eceb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecebc: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecebcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ecec0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecec0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecec4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ecec4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ecec8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ecec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ececc: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ececcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eced0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eced0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eced4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eced4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eced8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eced8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ecedc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecedcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecee0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ecee0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ecee4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ecee4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecee8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecee8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eceec: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eceecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecef0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ecef0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ecef4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecef4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecef8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecef8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecefc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecefcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecf00: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ecf00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ecf04: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecf04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecf08: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecf08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecf0c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ecf0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ecf10: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecf10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecf14: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ecf14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecf18: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecf18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ecf1c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ecf1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ecf20: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ecf20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ecf24: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ecf24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ecf28: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ecf28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ecf2c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ecf2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ecf30: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ecf30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ecf34: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecf34u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecf38: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ecf38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ecf3c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecf3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ecf40: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ecf40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecf44: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ecf44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ecf48: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ecf48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ecf4c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecf4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecf50: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ecf50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ecf54: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ecf54u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ecf58: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ecf58u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecf5c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ecf5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ecf60: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecf60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecf64: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecf64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecf68: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ecf68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecf6c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ecf6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecf70: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecf70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecf74: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecf74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ecf78: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ecf78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecf7c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ecf7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecf80: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ecf80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ecf84: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ecf84u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ecf88: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ecf88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ecf8c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ecf8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecf90: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ecf90u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ecf94: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ecf94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ecf98: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ecf98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ecf9c: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ecf9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ecfa0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ecfa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ecfa4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ecfa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ecfa8: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ecfa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ecfac: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ecfacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ecfb0: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ecfb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ecfb4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ecfb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ecfb8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ecfb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ecfbc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ecfbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ecfc0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ecfc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ecfc4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ecfc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ecfc8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ecfc8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ecfcc: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ecfccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ecfd0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ecfd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ecfd4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ecfd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ecfd8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecfd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ecfdc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ecfdcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ecfe0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ecfe0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ecfe4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ecfe4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ecfe8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ecfe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ecfec: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ecfecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ecff0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ecff0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ecff4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ecff4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ecff8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ecff8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ecffc: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ecffcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed000: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed004: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed004u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed008: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed008u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed00c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed00cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed010: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed014: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed014u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed018: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed018u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed01c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed01cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed020: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed020u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed024: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed024u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed028: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed028u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed02c: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed02cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed030: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed030u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed034: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed034u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed038: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed038u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed03c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed03cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed040: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed040u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed044: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed044u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed048: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed048u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed04c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed04cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed050: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed050u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed054: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed054u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed058: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed058u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed05c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed05cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed060: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed060u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed064: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed068: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed068u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed06c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed06cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed070: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed070u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed074: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed074u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed078: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed078u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed07c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed07cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed080: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed080u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed084: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed084u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed088: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed08c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed08cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed090: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed094: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed094u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed098: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed098u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed09c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed09cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed0a0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed0a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed0a4: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed0a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed0a8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed0a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed0ac: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed0acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed0b0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed0b4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed0b8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed0b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed0bc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed0bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed0c0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed0c4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed0c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed0c8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed0c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed0cc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed0ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed0d0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed0d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed0d4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed0d8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed0d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed0dc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed0e0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed0e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed0e4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed0e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed0e8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed0e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed0ec: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed0ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed0f0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed0f4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed0f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed0f8: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed0f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed0fc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed100: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed100u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed104: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed104u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed108: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed108u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed10c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed10cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed110: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed110u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed114: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed118: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed11c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed11cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed120: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed120u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed124: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed124u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed128: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed128u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed12c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed12cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed130: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed130u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed134: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed134u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed138: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed138u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed13c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed13cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed140: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed140u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed144: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed148: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed148u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed14c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed14cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed150: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed150u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed154: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed154u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed158: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed158u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed15c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed15cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed160: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed160u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed164: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed164u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed168: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed168u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed16c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed16cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed170: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed170u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed174: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed174u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed178: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed178u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed17c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed17cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed180: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed180u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed184: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed184u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed188: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed188u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed18c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed18cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed190: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed190u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed194: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed194u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed198: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed198u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed19c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed19cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed1a0: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed1a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed1a4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed1a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed1a8: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed1a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed1ac: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed1acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed1b0: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed1b4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed1b8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed1b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed1bc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed1c0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed1c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed1c4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed1c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed1c8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed1c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed1cc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed1ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed1d0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed1d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed1d4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed1d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed1d8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed1d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed1dc: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed1dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed1e0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed1e4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed1e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed1e8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed1e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed1ec: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed1ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed1f0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed1f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed1f4: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed1f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed1f8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed1f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed1fc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed1fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed200: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed200u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed204: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed204u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed208: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed208u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed20c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed20cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed210: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed210u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed214: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed218: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed218u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed21c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed21cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed220: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed224: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed224u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed228: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed228u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed22c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed22cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed230: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed230u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed234: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed238: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed23c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed23cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed240: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed240u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed244: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed244u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed248: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed248u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed24c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed24cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed250: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed250u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed254: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed254u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed258: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed258u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed25c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed25cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed260: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed260u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed264: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed264u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed268: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed26c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed26cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed270: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed270u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed274: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed274u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed278: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed278u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed27c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed27cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed280: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed280u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed284: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed284u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed288: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed288u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed28c: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed28cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed290: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed290u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed294: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed294u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed298: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed298u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed29c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed29cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed2a0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed2a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed2a4: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed2a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed2a8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed2a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed2ac: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed2acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed2b0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed2b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed2b4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed2b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed2b8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed2bc: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed2bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed2c0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed2c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed2c4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed2c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed2c8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed2c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed2cc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed2ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed2d0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed2d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed2d4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed2d8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed2d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed2dc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed2e0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed2e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed2e4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed2e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed2e8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed2e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed2ec: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed2ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed2f0: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed2f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed2f4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed2f8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed2f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed2fc: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed2fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed300: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed304: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed304u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed308: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed308u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed30c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed30cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed310: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed310u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed314: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed314u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed318: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed318u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed31c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed31cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed320: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed320u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed324: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed324u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed328: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed328u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed32c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed32cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed330: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed334: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed334u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed338: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed338u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed33c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed33cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed340: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed340u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed344: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed344u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed348: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed348u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed34c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed34cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed350: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed350u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed354: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed354u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed358: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed358u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed35c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed35cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed360: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed360u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed364: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed364u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed368: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed368u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed36c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed36cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed370: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed370u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed374: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed374u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed378: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed378u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed37c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed37cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed380: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed380u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed384: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed384u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed388: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed388u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed38c: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed38cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed390: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed394: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed394u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed398: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed398u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed39c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed39cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed3a0: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed3a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed3a4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed3a8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed3a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed3ac: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed3acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed3b0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed3b4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed3b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed3b8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed3b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed3bc: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed3bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed3c0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed3c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed3c4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed3c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed3c8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed3cc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed3ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed3d0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed3d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed3d4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed3d8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed3d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed3dc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed3dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed3e0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed3e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed3e4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed3e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed3e8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed3e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed3ec: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed3ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed3f0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed3f4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed3f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed3f8: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed3f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed3fc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed3fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed400: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed400u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed404: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed404u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed408: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed408u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed40c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed40cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed410: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed410u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed414: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed414u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed418: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed418u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed41c: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed41cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed420: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed420u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed424: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed424u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed428: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed428u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed42c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed42cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed430: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed430u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed434: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed434u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed438: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed438u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed43c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed43cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed440: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed440u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed444: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed444u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed448: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed448u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed44c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed44cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed450: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed450u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed454: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed458: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed458u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed45c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed45cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed460: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed460u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed464: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed464u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed468: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed468u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed46c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed46cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed470: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed470u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed474: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed474u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed478: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed478u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed47c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed47cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed480: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed480u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed484: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed484u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed488: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed488u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed48c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed48cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed490: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed490u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed494: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed494u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed498: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed498u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed49c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed49cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed4a0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed4a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed4a4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed4a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed4a8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed4a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed4ac: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed4acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed4b0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed4b4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed4b8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed4bc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed4bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed4c0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed4c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed4c4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed4c8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed4c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed4cc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed4ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed4d0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed4d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed4d4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed4d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed4d8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed4d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed4dc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed4dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed4e0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed4e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed4e4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed4e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed4e8: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed4e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed4ec: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed4f0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed4f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed4f4: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed4f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed4f8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed4fc: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed4fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed500: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed500u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed504: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed504u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed508: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed508u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed50c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed50cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed510: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed510u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed514: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed514u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed518: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed518u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed51c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed51cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed520: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed520u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed524: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed524u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed528: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed528u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed52c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed52cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed530: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed530u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed534: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed534u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed538: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed538u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed53c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed53cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed540: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed540u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed544: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed544u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed548: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed548u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed54c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed54cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed550: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed550u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed554: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed554u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed558: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed558u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed55c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed55cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed560: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed560u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed564: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed564u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed568: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed568u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed56c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed56cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed570: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed570u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed574: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed574u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed578: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed578u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed57c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed57cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed580: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed580u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed584: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed584u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed588: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed58c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed58cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed590: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed590u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed594: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed594u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed598: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed598u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed59c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed59cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed5a0: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed5a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed5a4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed5a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed5a8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed5a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed5ac: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed5acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed5b0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed5b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed5b4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed5b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed5b8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed5b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed5bc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed5bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed5c0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed5c4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed5c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed5c8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed5c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed5cc: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed5ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed5d0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed5d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed5d4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed5d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed5d8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed5d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed5dc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed5e0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed5e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed5e4: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed5e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed5e8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed5ec: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed5ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed5f0: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed5f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed5f4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed5f8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed5f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed5fc: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed5fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed600: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed600u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed604: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed608: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed608u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed60c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed60cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed610: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed610u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed614: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed614u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed618: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed618u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed61c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed61cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed620: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed620u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed624: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed628: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed62c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed62cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed630: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed630u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed634: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed634u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed638: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed638u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed63c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed63cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed640: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed640u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed644: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed644u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed648: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed648u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed64c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed64cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed650: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed650u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed654: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed654u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed658: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed65c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed65cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed660: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed660u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed664: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed664u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed668: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed668u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed66c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed66cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed670: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed670u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed674: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed674u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed678: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed678u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed67c: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed67cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed680: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed680u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed684: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed688: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed688u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed68c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed68cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed690: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed690u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed694: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed694u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed698: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed69c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed69cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed6a0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed6a4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed6a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed6a8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed6ac: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed6acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed6b0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed6b4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed6b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed6b8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed6b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed6bc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed6c0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed6c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed6c4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed6c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed6c8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed6c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed6cc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed6d0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed6d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed6d4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed6d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed6d8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed6dc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed6dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed6e0: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed6e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed6e4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed6e8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed6e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed6ec: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed6ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed6f0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed6f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed6f4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed6f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed6f8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed6fc: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed700: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed704: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed704u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed708: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed708u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed70c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed70cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed710: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed710u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed714: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed714u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed718: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed718u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed71c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed71cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed720: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed724: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed724u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed728: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed728u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed72c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed72cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed730: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed730u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed734: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed734u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed738: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed738u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed73c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed73cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed740: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed744: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed744u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed748: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed74c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed74cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed750: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed750u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed754: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed754u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed758: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed758u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed75c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed75cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed760: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed760u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed764: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed764u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed768: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed768u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed76c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed76cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed770: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed770u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed774: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed774u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed778: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed778u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed77c: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed77cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed780: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed780u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed784: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed784u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed788: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed788u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed78c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed78cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed790: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed790u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed794: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed794u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed798: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed798u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed79c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed79cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed7a0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed7a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed7a4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed7a8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed7a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed7ac: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed7acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed7b0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed7b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed7b4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed7b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed7b8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed7b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed7bc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed7bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed7c0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed7c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed7c4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed7c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed7c8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed7c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed7cc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed7d0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed7d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed7d4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed7d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed7d8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed7d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed7dc: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed7dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed7e0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed7e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed7e4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed7e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed7e8: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed7e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed7ec: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed7f0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed7f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed7f4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed7f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed7f8: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed7fc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed800: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed800u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed804: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed804u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed808: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed808u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed80c: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed80cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed810: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed814: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed814u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed818: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed818u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed81c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed81cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed820: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed824: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed824u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed828: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed82c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed82cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed830: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed830u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed834: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed834u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed838: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed838u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed83c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed83cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed840: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed840u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed844: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed844u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed848: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed848u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed84c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed84cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed850: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed854: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed854u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed858: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed858u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed85c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed85cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed860: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed860u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed864: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed864u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed868: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed868u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed86c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed86cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed870: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed870u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed874: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed874u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed878: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed878u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed87c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed87cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed880: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed880u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed884: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed884u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed888: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed888u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed88c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed88cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed890: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed894: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed894u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed898: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed898u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed89c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed89cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed8a0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed8a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed8a4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed8a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed8a8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed8a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed8ac: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed8acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed8b0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed8b4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed8b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed8b8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed8b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed8bc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed8bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed8c0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed8c4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed8c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed8c8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed8c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed8cc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed8ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed8d0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed8d4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed8d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed8d8: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed8d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed8dc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed8e0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed8e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed8e4: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed8e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed8e8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed8e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed8ec: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed8ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed8f0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed8f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed8f4: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed8f8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed8f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed8fc: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed8fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed900: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed900u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed904: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ed904u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ed908: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ed908u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ed90c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed90cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed910: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed910u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed914: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed914u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ed918: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed91c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed91cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed920: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ed920u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ed924: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed924u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed928: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ed928u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ed92c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ed92cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ed930: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ed930u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed934: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ed934u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed938: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed938u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed93c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed93cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed940: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed940u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed944: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed944u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed948: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed94c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed94cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ed950: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ed950u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed954: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ed954u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed958: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ed958u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ed95c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ed95cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ed960: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ed960u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ed964: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ed964u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed968: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ed968u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ed96c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ed96cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ed970: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1ed970u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1ed974: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1ed974u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1ed978: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ed978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ed97c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed97cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed980: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ed980u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ed984: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ed984u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ed988: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ed988u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ed98c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ed98cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ed990: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ed990u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ed994: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ed994u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ed998: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ed998u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ed99c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ed99cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ed9a0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ed9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ed9a4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ed9a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ed9a8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ed9a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ed9ac: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ed9acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ed9b0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed9b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ed9b4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ed9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ed9b8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ed9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ed9bc: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ed9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ed9c0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ed9c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ed9c4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ed9c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ed9c8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ed9c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ed9cc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed9ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed9d0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed9d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed9d4: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ed9d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ed9d8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed9d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed9dc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ed9dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed9e0: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ed9e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed9e4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ed9e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ed9e8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ed9e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ed9ec: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ed9ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ed9f0: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ed9f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ed9f4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ed9f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ed9f8: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ed9f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ed9fc: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ed9fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eda00: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1eda00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eda04: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1eda04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1eda08: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eda08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eda0c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eda0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eda10: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1eda10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1eda14: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eda14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eda18: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eda18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eda1c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1eda1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1eda20: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eda20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eda24: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1eda24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1eda28: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1eda28u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1eda2c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1eda2cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eda30: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eda30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eda34: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eda34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eda38: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eda38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eda3c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eda3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eda40: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eda40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eda44: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eda44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eda48: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eda48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eda4c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1eda4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eda50: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eda50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eda54: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1eda54u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1eda58: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1eda58u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1eda5c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1eda5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1eda60: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1eda60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eda64: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eda64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eda68: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eda68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eda6c: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1eda6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1eda70: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1eda70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1eda74: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eda74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eda78: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eda78u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eda7c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eda7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eda80: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eda80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eda84: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eda84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eda88: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eda88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eda8c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eda8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eda90: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eda90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eda94: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eda94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eda98: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eda98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eda9c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eda9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1edaa0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1edaa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1edaa4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1edaa4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edaa8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1edaa8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1edaac: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edaacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edab0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1edab0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1edab4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1edab4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edab8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1edab8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1edabc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edabcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1edac0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1edac0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1edac4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1edac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1edac8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edac8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edacc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edaccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edad0: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1edad0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edad4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edad8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edad8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edadc: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1edadcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edae0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edae0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edae4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1edae4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edae8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1edae8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1edaec: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1edaecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edaf0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1edaf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1edaf4: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1edaf4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1edaf8: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1edaf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edafc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1edafcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1edb00: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1edb00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1edb04: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1edb04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1edb08: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1edb08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1edb0c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1edb0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1edb10: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edb10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1edb14: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1edb14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1edb18: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1edb18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1edb1c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edb1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edb20: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1edb20u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1edb24: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1edb24u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1edb28: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1edb28u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edb2c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1edb2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edb30: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edb30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edb34: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edb34u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edb38: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1edb38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1edb3c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1edb3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edb40: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1edb40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1edb44: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1edb44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1edb48: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1edb48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1edb4c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1edb4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edb50: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1edb50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1edb54: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1edb54u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1edb58: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1edb58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1edb5c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1edb5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1edb60: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1edb60u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1edb64: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1edb64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1edb68: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1edb68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1edb6c: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1edb6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1edb70: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1edb70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1edb74: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1edb74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1edb78: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1edb78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1edb7c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1edb7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1edb80: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1edb80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1edb84: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1edb84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1edb88: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1edb88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1edb8c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edb8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edb90: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1edb90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1edb94: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1edb94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edb98: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1edb98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1edb9c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1edb9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1edba0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1edba0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edba4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1edba4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1edba8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edba8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edbac: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1edbacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1edbb0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1edbb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edbb4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1edbb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1edbb8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edbb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1edbbc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1edbbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1edbc0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1edbc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1edbc4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edbc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edbc8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edbc8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edbcc: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1edbccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edbd0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edbd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edbd4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edbd4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edbd8: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1edbd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edbdc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edbe0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1edbe0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edbe4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1edbe4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1edbe8: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1edbe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edbec: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1edbecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1edbf0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1edbf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1edbf4: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1edbf4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edbf8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1edbf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1edbfc: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1edbfcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1edc00: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1edc00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1edc04: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1edc04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1edc08: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1edc08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1edc0c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edc0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1edc10: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1edc10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1edc14: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1edc14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1edc18: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edc18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edc1c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1edc1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1edc20: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1edc20u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1edc24: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1edc24u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edc28: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1edc28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edc2c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edc2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edc30: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edc30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edc34: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1edc34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1edc38: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1edc38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edc3c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1edc3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1edc40: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1edc40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1edc44: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1edc44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1edc48: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1edc48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edc4c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1edc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1edc50: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1edc50u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1edc54: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1edc54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1edc58: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1edc58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1edc5c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1edc5cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1edc60: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1edc60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1edc64: 0x3c026ed9  lui         $v0, 0x6ED9
    ctx->pc = 0x1edc64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28377 << 16));
    // 0x1edc68: 0x3442eba1  ori         $v0, $v0, 0xEBA1
    ctx->pc = 0x1edc68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60321);
    // 0x1edc6c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1edc6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1edc70: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1edc70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1edc74: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1edc74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1edc78: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1edc78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1edc7c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1edc7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1edc80: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1edc80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1edc84: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1edc84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1edc88: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edc88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edc8c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1edc8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1edc90: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1edc90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edc94: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1edc94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1edc98: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1edc98u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1edc9c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1edc9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edca0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1edca0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1edca4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edca4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edca8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1edca8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1edcac: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1edcacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edcb0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1edcb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1edcb4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edcb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1edcb8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1edcb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1edcbc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1edcbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1edcc0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edcc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edcc4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edcc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edcc8: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1edcc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edccc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edcccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edcd0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edcd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edcd4: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1edcd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edcd8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edcd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edcdc: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1edcdcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edce0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1edce0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1edce4: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1edce4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edce8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1edce8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1edcec: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1edcecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1edcf0: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1edcf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edcf4: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1edcf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1edcf8: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1edcf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1edcfc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1edcfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1edd00: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1edd00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1edd04: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1edd04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1edd08: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edd08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1edd0c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1edd0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1edd10: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1edd10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1edd14: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edd14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edd18: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1edd18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1edd1c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1edd1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1edd20: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1edd20u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edd24: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1edd24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edd28: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edd28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edd2c: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1edd2cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1edd30: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1edd30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edd34: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edd34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edd38: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1edd38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edd3c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1edd3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1edd40: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1edd40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1edd44: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1edd44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1edd48: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1edd48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1edd4c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1edd4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1edd50: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1edd50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1edd54: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1edd54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edd58: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1edd58u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1edd5c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1edd5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1edd60: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1edd60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1edd64: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1edd64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1edd68: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1edd68u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1edd6c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1edd6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1edd70: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1edd70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1edd74: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1edd74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1edd78: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1edd78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1edd7c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1edd7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1edd80: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1edd80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1edd84: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1edd84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1edd88: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1edd88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1edd8c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1edd8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1edd90: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1edd90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1edd94: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edd94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edd98: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1edd98u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1edd9c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1edd9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edda0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1edda0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1edda4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1edda4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1edda8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1edda8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eddac: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eddacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eddb0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eddb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eddb4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eddb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eddb8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eddb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eddbc: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eddbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eddc0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eddc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eddc4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eddc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eddc8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eddc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eddcc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eddccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eddd0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eddd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eddd4: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eddd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eddd8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eddd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edddc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edddcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edde0: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1edde0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edde4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edde4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edde8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1edde8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eddec: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eddecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eddf0: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eddf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eddf4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eddf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eddf8: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1eddf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1eddfc: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1eddfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ede00: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ede00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ede04: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ede04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ede08: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ede08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ede0c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ede0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ede10: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ede10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ede14: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ede14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ede18: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ede18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ede1c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ede1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ede20: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ede20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ede24: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ede24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ede28: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ede28u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ede2c: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ede2cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ede30: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ede30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ede34: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ede34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ede38: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ede38u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ede3c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ede3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ede40: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ede40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ede44: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ede44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ede48: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ede48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ede4c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ede4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ede50: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ede50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ede54: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ede54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ede58: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ede58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ede5c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ede5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ede60: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ede60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ede64: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ede64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ede68: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ede68u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ede6c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ede6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ede70: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ede70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ede74: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ede74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ede78: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ede78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ede7c: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ede7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ede80: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ede80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ede84: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ede84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ede88: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ede88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ede8c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ede8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ede90: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ede90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ede94: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ede94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ede98: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ede98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ede9c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ede9cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1edea0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edea0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edea4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1edea4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1edea8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1edea8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edeac: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1edeacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1edeb0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1edeb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1edeb4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1edeb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edeb8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1edeb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1edebc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edebcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edec0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1edec0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1edec4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1edec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edec8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1edec8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1edecc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edeccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eded0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eded0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eded4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eded4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eded8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eded8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ededc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ededcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edee0: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1edee0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edee4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edee4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edee8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edee8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edeec: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1edeecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edef0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edef4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1edef4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edef8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1edef8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1edefc: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1edefcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edf00: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1edf00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1edf04: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1edf04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1edf08: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1edf08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edf0c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1edf0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1edf10: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1edf10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1edf14: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1edf14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1edf18: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1edf18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1edf1c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1edf1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1edf20: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edf20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1edf24: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1edf24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1edf28: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1edf28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1edf2c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edf2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edf30: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1edf30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1edf34: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1edf34u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1edf38: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1edf38u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edf3c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1edf3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edf40: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edf40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edf44: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1edf44u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1edf48: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1edf48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edf4c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edf4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edf50: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1edf50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edf54: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1edf54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1edf58: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1edf58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1edf5c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1edf5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1edf60: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1edf60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1edf64: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1edf64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1edf68: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1edf68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1edf6c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1edf6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edf70: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1edf70u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1edf74: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1edf74u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1edf78: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1edf78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1edf7c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1edf7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1edf80: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1edf80u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1edf84: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1edf84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1edf88: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1edf88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1edf8c: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1edf8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1edf90: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1edf90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1edf94: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1edf94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1edf98: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1edf98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1edf9c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1edf9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1edfa0: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1edfa0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1edfa4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1edfa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1edfa8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1edfa8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1edfac: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1edfacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1edfb0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1edfb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1edfb4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1edfb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1edfb8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1edfb8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1edfbc: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1edfbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1edfc0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1edfc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1edfc4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1edfc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1edfc8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1edfc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1edfcc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1edfccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1edfd0: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1edfd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1edfd4: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1edfd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1edfd8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1edfd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1edfdc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1edfdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1edfe0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1edfe0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1edfe4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edfe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edfe8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edfe8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edfec: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1edfecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1edff0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edff0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1edff4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1edff4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1edff8: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1edff8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1edffc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1edffcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee000: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee000u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee004: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee004u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee008: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee008u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee00c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee00cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee010: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee010u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee014: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee014u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee018: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee018u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee01c: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee01cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee020: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee020u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee024: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee024u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee028: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee028u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee02c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee02cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee030: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee030u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee034: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee034u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee038: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee03c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee03cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee040: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee040u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee044: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee044u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee048: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee048u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee04c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee04cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee050: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee050u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee054: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee054u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee058: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee058u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee05c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee05cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee060: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee060u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee064: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee064u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee068: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee068u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee06c: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee06cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee070: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee070u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee074: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee074u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee078: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee078u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee07c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee07cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee080: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee080u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee084: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee084u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee088: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee08c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee08cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee090: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee094: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee094u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee098: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee098u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee09c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee09cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee0a0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee0a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee0a4: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee0a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee0a8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee0a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee0ac: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee0acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee0b0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee0b4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee0b8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee0b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee0bc: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee0bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee0c0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee0c4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee0c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee0c8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee0c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee0cc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee0ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee0d0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee0d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee0d4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee0d8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee0d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee0dc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee0e0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee0e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee0e4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee0e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee0e8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee0e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee0ec: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee0ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee0f0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee0f4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee0f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee0f8: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee0f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee0fc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee100: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee100u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee104: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee104u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee108: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee108u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee10c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee10cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee110: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee110u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee114: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee118: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee11c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee11cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee120: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee120u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee124: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee124u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee128: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee128u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee12c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee12cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee130: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee130u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee134: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee134u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee138: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee138u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee13c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee13cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee140: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee140u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee144: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee148: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee148u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee14c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee14cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee150: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee150u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee154: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee154u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee158: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee158u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee15c: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee15cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee160: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee160u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee164: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee164u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee168: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee168u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee16c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee16cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee170: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee170u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee174: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee174u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee178: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee178u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee17c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee17cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee180: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee180u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee184: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee184u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee188: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee188u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee18c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee18cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee190: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee190u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee194: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee194u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee198: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee198u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee19c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee19cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee1a0: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee1a4: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee1a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee1a8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee1ac: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee1acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee1b0: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee1b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee1b4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee1b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee1b8: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee1b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee1bc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee1c0: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee1c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee1c4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee1c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee1c8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee1c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee1cc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee1ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee1d0: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee1d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee1d4: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee1d8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee1d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee1dc: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee1dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee1e0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee1e4: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee1e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee1e8: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee1e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee1ec: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee1ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee1f0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee1f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee1f4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee1f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee1f8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee1fc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee200: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee200u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee204: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee204u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee208: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee208u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee20c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee20cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee210: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee210u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee214: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee214u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee218: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee218u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee21c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee21cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee220: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee224: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee224u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee228: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee228u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee22c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee22cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee230: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee230u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee234: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee234u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee238: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee238u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee23c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee23cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee240: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee240u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee244: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee244u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee248: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee24c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee24cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee250: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee250u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee254: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee254u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee258: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee258u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee25c: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee25cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee260: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee260u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee264: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee268: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee268u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee26c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee26cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee270: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee270u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee274: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee274u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee278: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee278u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee27c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee27cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee280: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee280u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee284: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee284u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee288: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee288u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee28c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee28cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee290: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee290u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee294: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee294u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee298: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee298u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee29c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee29cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee2a0: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee2a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee2a4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee2a4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee2a8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee2a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee2ac: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee2acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee2b0: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee2b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee2b4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee2b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee2b8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee2b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee2bc: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee2bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee2c0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee2c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee2c4: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee2c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee2c8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee2c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee2cc: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee2ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee2d0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee2d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee2d4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee2d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee2d8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee2d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee2dc: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee2dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee2e0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee2e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee2e4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee2e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee2e8: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee2e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee2ec: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee2ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee2f0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee2f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee2f4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee2f8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee2f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee2fc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee2fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee300: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee300u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee304: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee304u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee308: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee308u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee30c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee30cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee310: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee310u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee314: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee318: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee318u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee31c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee31cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee320: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee324: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee324u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee328: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee328u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee32c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee32cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee330: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee334: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee334u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee338: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee338u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee33c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee33cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee340: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee340u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee344: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee344u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee348: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee348u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee34c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee34cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee350: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee350u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee354: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee354u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee358: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee358u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee35c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee35cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee360: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee360u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee364: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee364u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee368: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee368u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee36c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee36cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee370: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee374: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee374u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee378: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee378u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee37c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee37cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee380: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee380u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee384: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee384u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee388: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee388u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee38c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee38cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee390: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee390u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee394: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee398: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee398u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee39c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee39cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee3a0: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee3a4: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee3a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee3a8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee3a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee3ac: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee3acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee3b0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee3b4: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee3b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee3b8: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee3b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee3bc: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee3bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee3c0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee3c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee3c4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee3c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee3c8: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee3c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee3cc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee3ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee3d0: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee3d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee3d4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee3d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee3d8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee3d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee3dc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee3dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee3e0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee3e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee3e4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee3e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee3e8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee3e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee3ec: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee3ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee3f0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee3f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee3f4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee3f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee3f8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee3f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee3fc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee3fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee400: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee400u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee404: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee404u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee408: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee408u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee40c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee40cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee410: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee410u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee414: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee414u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee418: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee418u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee41c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee41cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee420: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee420u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee424: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee424u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee428: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee428u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee42c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee42cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee430: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee430u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee434: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee434u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee438: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee438u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee43c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee43cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee440: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee440u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee444: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee444u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee448: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee448u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee44c: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee44cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee450: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee450u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee454: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee454u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee458: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee458u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee45c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee45cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee460: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee460u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee464: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee464u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee468: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee468u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee46c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee46cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee470: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee470u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee474: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee474u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee478: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee478u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee47c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee47cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee480: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee480u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee484: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee484u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee488: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee488u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee48c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee48cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee490: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee494: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee494u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee498: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee498u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee49c: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee49cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee4a0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee4a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee4a4: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee4a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee4a8: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee4a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee4ac: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee4acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee4b0: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee4b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee4b4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee4b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee4b8: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee4b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee4bc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee4bcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee4c0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee4c4: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee4c8: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee4c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee4cc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee4ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee4d0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee4d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee4d4: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee4d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee4d8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee4d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee4dc: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee4dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee4e0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee4e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee4e4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee4e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee4e8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee4ec: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee4ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee4f0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee4f4: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee4f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee4f8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee4fc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee4fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee500: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee500u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee504: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee504u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee508: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee508u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee50c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee50cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee510: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee510u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee514: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee514u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee518: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee518u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee51c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee51cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee520: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee524: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee524u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee528: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee528u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee52c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee52cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee530: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee530u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee534: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee534u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee538: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee538u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee53c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee53cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee540: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee540u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee544: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee544u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee548: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee548u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee54c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee54cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee550: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee550u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee554: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee554u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee558: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee558u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee55c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee55cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee560: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee560u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee564: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee564u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee568: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee568u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee56c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee56cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee570: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee570u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee574: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee574u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee578: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee578u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee57c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee57cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee580: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee580u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee584: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee584u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee588: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee588u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee58c: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee58cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee590: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee590u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee594: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee594u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee598: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee598u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee59c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee59cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee5a0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee5a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee5a4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee5a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee5a8: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee5a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee5ac: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee5acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee5b0: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee5b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee5b4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee5b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee5b8: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee5bc: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee5bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee5c0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee5c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee5c4: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee5c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee5c8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee5c8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee5cc: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee5ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee5d0: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee5d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee5d4: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee5d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee5d8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee5d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee5dc: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee5dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee5e0: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee5e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee5e4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee5e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee5e8: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee5e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee5ec: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee5f0: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee5f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee5f4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee5f8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee5f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee5fc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee600: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee600u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee604: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee604u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee608: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee608u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee60c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee60cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee610: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee610u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee614: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee614u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee618: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee61c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee61cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee620: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee620u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee624: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee624u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee628: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee628u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee62c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee62cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee630: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee630u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee634: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee634u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee638: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee638u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee63c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee63cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee640: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee640u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee644: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee644u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee648: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee648u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee64c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee64cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee650: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee654: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee658: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee658u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee65c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee65cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee660: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee660u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee664: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee664u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee668: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee668u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee66c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee66cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee670: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee670u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee674: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee678: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee678u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee67c: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee67cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee680: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee680u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee684: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee684u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee688: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee688u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee68c: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee68cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee690: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee690u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee694: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee694u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee698: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee698u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee69c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee69cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee6a0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee6a4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee6a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee6a8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee6ac: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee6acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee6b0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee6b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee6b4: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee6b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee6b8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee6bc: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee6bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee6c0: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee6c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee6c4: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee6c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee6c8: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee6c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee6cc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee6ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee6d0: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee6d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee6d4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee6d4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee6d8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee6d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee6dc: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee6dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee6e0: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee6e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee6e4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee6e8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee6ec: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee6ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee6f0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee6f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee6f4: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee6f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee6f8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee6fc: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee6fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee700: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee704: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee704u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee708: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee708u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee70c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee70cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee710: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee710u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee714: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee714u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee718: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee718u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee71c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee71cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee720: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee720u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee724: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee724u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee728: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee728u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee72c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee72cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee730: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee730u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee734: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee734u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee738: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee738u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee73c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee73cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee740: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee740u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee744: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee744u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee748: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee748u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee74c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee74cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee750: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee750u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee754: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee754u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee758: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee758u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee75c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee75cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee760: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee764: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee764u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee768: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee768u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee76c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee76cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee770: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee770u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee774: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee774u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee778: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee778u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee77c: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee77cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee780: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee784: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee784u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee788: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee788u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee78c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee78cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee790: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee790u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee794: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee794u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee798: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee798u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee79c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee79cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee7a0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee7a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee7a4: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee7a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee7a8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee7a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee7ac: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee7acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee7b0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee7b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee7b4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee7b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee7b8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee7b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee7bc: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee7bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee7c0: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee7c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee7c4: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee7c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee7c8: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee7c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee7cc: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee7d0: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee7d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee7d4: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee7d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee7d8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee7d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee7dc: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee7dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee7e0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee7e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee7e4: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee7e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee7e8: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee7ec: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee7ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee7f0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee7f4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee7f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee7f8: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee7f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee7fc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee7fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee800: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee800u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee804: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee804u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee808: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee808u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee80c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee80cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee810: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee810u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee814: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee818: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee818u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee81c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee81cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee820: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee820u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee824: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee824u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee828: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee82c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee82cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee830: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee830u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee834: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee834u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee838: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee838u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee83c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee83cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee840: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee840u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee844: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee844u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee848: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee848u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee84c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee84cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee850: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee854: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee854u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee858: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee858u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee85c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee85cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee860: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee860u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee864: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee864u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee868: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee868u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee86c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee86cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee870: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee870u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee874: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee874u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee878: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee878u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee87c: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee87cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee880: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee880u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee884: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee884u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee888: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee888u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee88c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee88cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee890: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee894: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee894u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee898: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee898u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee89c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee89cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee8a0: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee8a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee8a4: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee8a4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee8a8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee8a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee8ac: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee8acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee8b0: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee8b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee8b4: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee8b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee8b8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee8bc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee8bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee8c0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee8c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee8c4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee8c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee8c8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee8c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee8cc: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee8ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee8d0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee8d4: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee8d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee8d8: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee8d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee8dc: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee8e0: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee8e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee8e4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee8e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee8e8: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee8e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee8ec: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee8ecu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee8f0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee8f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ee8f4: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ee8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ee8f8: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ee8f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ee8fc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ee8fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee900: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee900u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee904: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ee904u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee908: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee908u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee90c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ee90cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ee910: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee914: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee914u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ee918: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee91c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ee91cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ee920: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ee920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee924: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ee924u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ee928: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ee928u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ee92c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ee92cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee930: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ee930u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ee934: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee934u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee938: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ee938u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ee93c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ee93cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee940: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee940u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ee944: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee944u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee948: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ee948u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ee94c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee94cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee950: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee954: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee954u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee958: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ee958u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee95c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee95cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee960: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ee960u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee964: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ee964u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee968: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ee968u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ee96c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ee96cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ee970: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ee970u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ee974: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ee974u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ee978: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee97c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ee97cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ee980: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ee980u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ee984: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ee984u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ee988: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ee988u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ee98c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee98cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ee990: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ee990u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ee994: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ee994u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ee998: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ee998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ee99c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ee99cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ee9a0: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ee9a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ee9a4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ee9a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ee9a8: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ee9a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ee9ac: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ee9acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ee9b0: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ee9b0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee9b4: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee9b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee9b8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee9bc: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ee9bcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee9c0: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ee9c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ee9c4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ee9c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ee9c8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ee9c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ee9cc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ee9ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ee9d0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ee9d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ee9d4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ee9d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ee9d8: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ee9d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ee9dc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ee9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ee9e0: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ee9e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ee9e4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ee9e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ee9e8: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ee9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ee9ec: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ee9ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ee9f0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ee9f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ee9f4: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ee9f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ee9f8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ee9f8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ee9fc: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ee9fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eea00: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1eea00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1eea04: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1eea04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1eea08: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eea08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eea0c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eea0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eea10: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eea10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eea14: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eea14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eea18: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eea18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eea1c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eea1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eea20: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eea20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eea24: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eea24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eea28: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eea28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eea2c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eea2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eea30: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eea30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eea34: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eea34u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eea38: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eea38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eea3c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eea3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eea40: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eea40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eea44: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eea44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eea48: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eea48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eea4c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eea4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eea50: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eea50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eea54: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eea54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eea58: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eea58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eea5c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eea5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eea60: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eea60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eea64: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eea64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eea68: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eea68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eea6c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eea6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eea70: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1eea70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eea74: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eea74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eea78: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eea78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eea7c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eea7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eea80: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eea80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eea84: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eea84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eea88: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1eea88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1eea8c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1eea8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eea90: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1eea90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eea94: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1eea94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1eea98: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eea98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eea9c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eea9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eeaa0: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1eeaa0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1eeaa4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eeaa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eeaa8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eeaa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eeaac: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1eeaacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1eeab0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eeab0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eeab4: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1eeab4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1eeab8: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1eeab8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1eeabc: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1eeabcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eeac0: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eeac0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eeac4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eeac4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eeac8: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1eeac8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eeacc: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eeaccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eead0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eead0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eead4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1eead4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eead8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eead8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eeadc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1eeadcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eeae0: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1eeae0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1eeae4: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1eeae4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1eeae8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eeae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eeaec: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1eeaecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eeaf0: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eeaf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eeaf4: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1eeaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1eeaf8: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1eeaf8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1eeafc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1eeafcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1eeb00: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1eeb00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eeb04: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eeb04u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eeb08: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eeb08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eeb0c: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1eeb0cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1eeb10: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1eeb10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1eeb14: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eeb14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eeb18: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eeb18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eeb1c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eeb1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eeb20: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eeb20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eeb24: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eeb24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eeb28: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eeb28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eeb2c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eeb2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eeb30: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eeb30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eeb34: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eeb34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eeb38: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eeb38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eeb3c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eeb3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eeb40: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eeb40u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eeb44: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eeb44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eeb48: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eeb48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eeb4c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eeb4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eeb50: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eeb50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eeb54: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eeb54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eeb58: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eeb58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eeb5c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eeb5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eeb60: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eeb60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eeb64: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eeb64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eeb68: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eeb68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eeb6c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eeb6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eeb70: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eeb70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eeb74: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eeb74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eeb78: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eeb78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eeb7c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1eeb7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eeb80: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eeb80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eeb84: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eeb84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eeb88: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eeb88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eeb8c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eeb8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eeb90: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eeb90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eeb94: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1eeb94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1eeb98: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1eeb98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eeb9c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1eeb9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eeba0: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1eeba0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1eeba4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eeba4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eeba8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eeba8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eebac: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1eebacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1eebb0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eebb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eebb4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eebb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eebb8: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1eebb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1eebbc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eebbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eebc0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1eebc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1eebc4: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1eebc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1eebc8: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1eebc8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eebcc: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eebccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eebd0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eebd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eebd4: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1eebd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eebd8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eebd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eebdc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eebdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eebe0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1eebe0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eebe4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eebe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eebe8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1eebe8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eebec: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1eebecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1eebf0: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1eebf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1eebf4: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eebf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eebf8: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1eebf8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eebfc: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eebfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eec00: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1eec00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1eec04: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1eec04u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1eec08: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1eec08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1eec0c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1eec0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eec10: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eec10u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eec14: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eec14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eec18: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1eec18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1eec1c: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1eec1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1eec20: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eec20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eec24: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eec24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eec28: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eec28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eec2c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eec2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eec30: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eec30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eec34: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eec34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eec38: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eec38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eec3c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eec3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eec40: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eec40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eec44: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eec44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eec48: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eec48u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eec4c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eec4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eec50: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eec50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eec54: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eec54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eec58: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eec58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eec5c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eec5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eec60: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eec60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eec64: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eec64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eec68: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eec68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eec6c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eec6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eec70: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eec70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eec74: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eec74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eec78: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eec78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eec7c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eec7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eec80: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eec80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eec84: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eec84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eec88: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1eec88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eec8c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eec8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eec90: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eec90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eec94: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eec94u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eec98: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eec98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eec9c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eec9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eeca0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1eeca0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1eeca4: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1eeca4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eeca8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1eeca8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eecac: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1eecacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1eecb0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eecb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eecb4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eecb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eecb8: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1eecb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1eecbc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eecbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eecc0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eecc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eecc4: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1eecc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1eecc8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eecc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eeccc: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1eecccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1eecd0: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1eecd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1eecd4: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1eecd4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eecd8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eecd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eecdc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eecdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eece0: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1eece0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eece4: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eece4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eece8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eece8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eecec: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1eececu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eecf0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eecf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eecf4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1eecf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eecf8: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1eecf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1eecfc: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1eecfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1eed00: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eed00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eed04: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1eed04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eed08: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eed08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eed0c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1eed0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1eed10: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1eed10u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1eed14: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1eed14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1eed18: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1eed18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eed1c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eed1cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eed20: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eed20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eed24: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1eed24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1eed28: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1eed28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1eed2c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eed2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eed30: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eed30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eed34: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eed34u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eed38: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eed38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eed3c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eed3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eed40: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eed40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eed44: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eed44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eed48: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eed48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eed4c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eed4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eed50: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eed50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eed54: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eed54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eed58: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eed58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eed5c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eed5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eed60: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eed60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eed64: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eed64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eed68: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eed68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eed6c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eed6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eed70: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eed70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eed74: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eed74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eed78: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eed78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eed7c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eed7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eed80: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eed80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eed84: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eed84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eed88: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eed88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eed8c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eed8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eed90: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eed90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eed94: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1eed94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eed98: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eed98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eed9c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eed9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eeda0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eeda0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eeda4: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eeda4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eeda8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eeda8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eedac: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1eedacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1eedb0: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1eedb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eedb4: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1eedb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eedb8: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1eedb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1eedbc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eedbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eedc0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eedc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eedc4: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1eedc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1eedc8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eedc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eedcc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eedccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eedd0: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1eedd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1eedd4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eedd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eedd8: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1eedd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1eeddc: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1eeddcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1eede0: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1eede0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eede4: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eede4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eede8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eede8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eedec: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1eedecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eedf0: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eedf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eedf4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eedf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eedf8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1eedf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eedfc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eedfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eee00: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1eee00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eee04: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1eee04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1eee08: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1eee08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1eee0c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eee0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eee10: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1eee10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eee14: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eee14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eee18: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1eee18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1eee1c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1eee1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1eee20: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1eee20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1eee24: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1eee24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eee28: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eee28u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eee2c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eee2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eee30: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1eee30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1eee34: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1eee34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1eee38: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eee38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eee3c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eee3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eee40: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eee40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eee44: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eee44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eee48: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eee48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eee4c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eee4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eee50: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eee50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eee54: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eee54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eee58: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eee58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eee5c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eee5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eee60: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eee60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eee64: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eee64u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eee68: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eee68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eee6c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eee6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eee70: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eee70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eee74: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eee74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eee78: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eee78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eee7c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eee7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eee80: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eee80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eee84: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eee84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eee88: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eee88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eee8c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eee8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eee90: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eee90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eee94: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eee94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eee98: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eee98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eee9c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eee9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eeea0: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1eeea0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eeea4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eeea4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eeea8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eeea8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eeeac: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eeeacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eeeb0: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eeeb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eeeb4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eeeb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eeeb8: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1eeeb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1eeebc: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1eeebcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eeec0: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1eeec0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eeec4: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1eeec4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1eeec8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eeec8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eeecc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eeeccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eeed0: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1eeed0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1eeed4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eeed4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eeed8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eeed8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eeedc: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1eeedcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1eeee0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eeee0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eeee4: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1eeee4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1eeee8: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1eeee8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1eeeec: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1eeeecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eeef0: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eeef0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eeef4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eeef4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eeef8: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1eeef8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eeefc: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eeefcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eef00: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eef00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eef04: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1eef04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eef08: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eef08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eef0c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1eef0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1eef10: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1eef10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1eef14: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1eef14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1eef18: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eef18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eef1c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1eef1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eef20: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eef20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eef24: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1eef24u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1eef28: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1eef28u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1eef2c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1eef2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1eef30: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1eef30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eef34: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eef34u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eef38: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eef38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eef3c: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1eef3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1eef40: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1eef40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1eef44: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eef44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eef48: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eef48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eef4c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eef4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eef50: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eef50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eef54: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eef54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eef58: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eef58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eef5c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eef5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eef60: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eef60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eef64: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eef64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eef68: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eef68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eef6c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eef6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eef70: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eef70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eef74: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eef74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eef78: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eef78u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eef7c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eef7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eef80: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eef80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eef84: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eef84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eef88: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eef88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eef8c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eef8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eef90: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eef90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eef94: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eef94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eef98: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eef98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eef9c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eef9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eefa0: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eefa0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eefa4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eefa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eefa8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eefa8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eefac: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1eefacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eefb0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eefb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eefb4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eefb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eefb8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eefb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eefbc: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eefbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eefc0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eefc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eefc4: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1eefc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1eefc8: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1eefc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eefcc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1eefccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1eefd0: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1eefd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1eefd4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eefd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eefd8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eefd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eefdc: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1eefdcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1eefe0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eefe0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eefe4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eefe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eefe8: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1eefe8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1eefec: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eefecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eeff0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1eeff0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1eeff4: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1eeff4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1eeff8: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1eeff8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eeffc: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1eeffcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef000: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef004: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ef004u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ef008: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef008u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef00c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef00cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef010: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ef010u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef014: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef018: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ef018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ef01c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ef01cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ef020: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ef020u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ef024: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef024u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef028: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef028u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef02c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef02cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef030: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef030u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef034: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef034u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef038: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef038u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef03c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef03cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef040: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef040u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef044: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef044u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef048: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ef048u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ef04c: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ef04cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ef050: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef054: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef054u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef058: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef058u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef05c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef05cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef060: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef060u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef064: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef068: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef068u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef06c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef06cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef070: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef070u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef074: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef074u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef078: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef078u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef07c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef07cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef080: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef080u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef084: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef084u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef088: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef088u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef08c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef08cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef090: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef090u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef094: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef094u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef098: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef098u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef09c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef09cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef0a0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef0a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef0a4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef0a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef0a8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef0a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef0ac: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef0acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef0b0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef0b4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef0b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef0b8: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef0b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef0bc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef0c0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef0c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef0c4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef0c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef0c8: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef0c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef0cc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef0d0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef0d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef0d4: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef0d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef0d8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef0dc: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef0dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef0e0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef0e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef0e4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef0e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef0e8: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef0e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef0ec: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef0ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef0f0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef0f4: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef0f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef0f8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef0fc: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef0fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef100: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef100u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef104: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x1ef104u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef108: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef108u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef10c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef10cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef110: 0x622024  and         $a0, $v1, $v0
    ctx->pc = 0x1ef110u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ef114: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef114u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef118: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef118u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef11c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ef11cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef120: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef120u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef124: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1ef124u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1ef128: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1ef128u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1ef12c: 0xa21821  addu        $v1, $a1, $v0
    ctx->pc = 0x1ef12cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1ef130: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef130u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef134: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef134u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef138: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef13c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef13cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef140: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef140u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef144: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef144u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef148: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef148u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef14c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef14cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef150: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef150u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef154: 0x3c028f1b  lui         $v0, 0x8F1B
    ctx->pc = 0x1ef154u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36635 << 16));
    // 0x1ef158: 0x3442bcdc  ori         $v0, $v0, 0xBCDC
    ctx->pc = 0x1ef158u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)48348);
    // 0x1ef15c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef15cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef160: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef160u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef164: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef164u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef168: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef168u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef16c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef16cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef170: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef174: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef174u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef178: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef178u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef17c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef17cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef180: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef184: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef184u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef188: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef188u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef18c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef18cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef190: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef190u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef194: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef194u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef198: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef198u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef19c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef19cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef1a0: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef1a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef1a4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef1a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef1a8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef1a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef1ac: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef1acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef1b0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef1b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef1b4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef1b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef1b8: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef1b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef1bc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef1c0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef1c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef1c4: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef1c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef1c8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef1c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef1cc: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef1ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef1d0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef1d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef1d4: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef1d8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef1d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef1dc: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef1dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef1e0: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef1e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef1e4: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef1e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef1e8: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef1e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef1ec: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef1ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef1f0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef1f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef1f4: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef1f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef1f8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef1f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef1fc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef200: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef200u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef204: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef204u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef208: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef208u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef20c: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef20cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef210: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef210u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef214: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef214u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef218: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef218u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef21c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef21cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef220: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef224: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef224u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef228: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef228u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef22c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef22cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef230: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef230u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef234: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef234u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef238: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef238u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef23c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef23cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef240: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef240u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef244: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef244u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef248: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef248u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef24c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef24cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef250: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1ef250u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1ef254: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1ef254u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1ef258: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef25c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef25cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef260: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef260u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef264: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef264u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef268: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef268u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef26c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef26cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef270: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef270u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef274: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef274u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef278: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef278u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef27c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef27cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef280: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef280u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef284: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef284u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef288: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef288u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef28c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef28cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef290: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef290u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef294: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef294u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef298: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef298u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef29c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef29cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef2a0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef2a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef2a4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef2a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef2a8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef2a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef2ac: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef2acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef2b0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef2b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef2b4: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef2b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef2b8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef2bc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef2bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef2c0: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef2c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef2c4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef2c8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef2c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef2cc: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef2ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef2d0: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef2d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef2d4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef2d8: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef2d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef2dc: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef2dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef2e0: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef2e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef2e4: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef2e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef2e8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef2e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef2ec: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef2ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef2f0: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef2f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef2f4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef2f8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef2f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef2fc: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef2fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef300: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef304: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef304u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef308: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef308u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef30c: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef30cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef310: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef310u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef314: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef318: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef318u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef31c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef31cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef320: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef324: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef324u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef328: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef328u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef32c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef32cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef330: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef330u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef334: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef334u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef338: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef338u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef33c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef33cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef340: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef340u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef344: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef344u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef348: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef348u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef34c: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1ef34cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1ef350: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1ef350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1ef354: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef354u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef358: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef358u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef35c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef35cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef360: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef360u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef364: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef364u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef368: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef36c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef36cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef370: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef374: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef374u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef378: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef378u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef37c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef37cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef380: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef380u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef384: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef384u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef388: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef388u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef38c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef38cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef390: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef390u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef394: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef398: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef398u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef39c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef39cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef3a0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef3a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef3a4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef3a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef3a8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef3a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef3ac: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef3acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef3b0: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef3b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef3b4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef3b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef3b8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef3b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef3bc: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef3bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef3c0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef3c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef3c4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef3c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef3c8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef3c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef3cc: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef3d0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef3d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef3d4: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef3d8: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef3d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef3dc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef3dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef3e0: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef3e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef3e4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef3e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef3e8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef3e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef3ec: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef3ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef3f0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef3f4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef3f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef3f8: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef3f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef3fc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef3fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef400: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef400u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef404: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef404u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef408: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef408u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef40c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef40cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef410: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef410u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef414: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef414u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef418: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef418u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef41c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef41cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef420: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef420u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef424: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef424u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef428: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef428u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef42c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef42cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef430: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef430u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef434: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef434u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef438: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef438u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef43c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef43cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef440: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef440u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef444: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef444u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef448: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1ef448u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1ef44c: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1ef44cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1ef450: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef450u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef454: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef454u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef458: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef458u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef45c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef45cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef460: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef460u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef464: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef464u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef468: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef468u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef46c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef46cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef470: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef470u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef474: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef474u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef478: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef478u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef47c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef47cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef480: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef480u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef484: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef484u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef488: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef488u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef48c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef48cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef490: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef494: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef494u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef498: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef498u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef49c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef49cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef4a0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef4a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef4a4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef4a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef4a8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef4a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef4ac: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef4acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef4b0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef4b4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef4b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef4b8: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef4b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef4bc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef4bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef4c0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef4c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef4c4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef4c8: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef4c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef4cc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef4ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef4d0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef4d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef4d4: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef4d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef4d8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef4d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef4dc: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef4dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef4e0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef4e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef4e4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef4e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef4e8: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef4e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef4ec: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef4f0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef4f4: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef4f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef4f8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef4fc: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef4fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef500: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef500u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef504: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef504u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef508: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef50c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef50cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef510: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef510u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef514: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef514u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef518: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef518u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef51c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef51cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef520: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef524: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef524u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef528: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef528u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef52c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef52cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef530: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef530u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef534: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef534u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef538: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef538u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef53c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef53cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef540: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef540u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef544: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1ef544u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1ef548: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1ef548u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1ef54c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef54cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef550: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef550u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef554: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef554u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef558: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef558u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef55c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef55cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef560: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef560u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef564: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef564u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef568: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef568u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef56c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef56cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef570: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef574: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef574u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef578: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef578u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef57c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef57cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef580: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef580u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef584: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef584u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef588: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef588u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef58c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef58cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef590: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef590u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef594: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef594u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef598: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef598u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef59c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef59cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef5a0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef5a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef5a4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef5a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef5a8: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef5a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef5ac: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef5acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef5b0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef5b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef5b4: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef5b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef5b8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef5bc: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef5bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef5c0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef5c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef5c4: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef5c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef5c8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef5c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef5cc: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef5ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef5d0: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef5d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef5d4: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef5d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef5d8: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef5d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef5dc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef5dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef5e0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef5e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef5e4: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef5e8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef5ec: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef5f0: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef5f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef5f4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef5f8: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef5f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef5fc: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef600: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef600u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef604: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef604u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef608: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef608u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef60c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef60cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef610: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef610u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef614: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef614u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef618: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef618u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef61c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef61cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef620: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef620u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef624: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef624u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef628: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef628u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef62c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef62cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef630: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef630u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef634: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef634u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef638: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef638u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef63c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef63cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef640: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1ef640u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1ef644: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1ef644u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1ef648: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef648u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef64c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef64cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef650: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef650u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef654: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef654u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef658: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef658u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef65c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef65cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef660: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef660u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef664: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef668: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef668u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef66c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef66cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef670: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef670u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef674: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef674u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef678: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef67c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef67cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef680: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef680u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef684: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef684u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef688: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef68c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef68cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef690: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef690u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef694: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef698: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef698u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef69c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef69cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef6a0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef6a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef6a4: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef6a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef6a8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef6ac: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef6acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef6b0: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef6b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef6b4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef6b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef6b8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef6b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef6bc: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef6bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef6c0: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef6c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef6c4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef6c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef6c8: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef6c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef6cc: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef6ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef6d0: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef6d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef6d4: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef6d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef6d8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef6d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef6dc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef6dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef6e0: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef6e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef6e4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef6e8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef6e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef6ec: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef6ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef6f0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef6f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef6f4: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef6f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef6f8: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef6fc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef6fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef700: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef700u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef704: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef704u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef708: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef708u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef70c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef70cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef710: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef710u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef714: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef714u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef718: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef718u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef71c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef71cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef720: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef720u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef724: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef724u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef728: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef728u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef72c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef72cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef730: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef730u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef734: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef734u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef738: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef738u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef73c: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1ef73cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1ef740: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1ef740u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1ef744: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef744u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef748: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef748u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef74c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef74cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef750: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef750u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef754: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef754u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef758: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef75c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef75cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef760: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef764: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef764u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef768: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef76c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef76cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef770: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef770u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef774: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef774u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef778: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef778u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef77c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef77cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef780: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef780u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef784: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef784u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef788: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef788u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef78c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef78cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef790: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef790u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef794: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef794u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef798: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef798u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef79c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef79cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef7a0: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef7a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef7a4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef7a8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef7a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef7ac: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef7acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef7b0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef7b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef7b4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef7b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef7b8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef7b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef7bc: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef7bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef7c0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef7c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef7c4: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef7c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef7c8: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef7c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef7cc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef7d0: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef7d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef7d4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef7d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef7d8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef7d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef7dc: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef7dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef7e0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef7e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef7e4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef7e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef7e8: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef7e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef7ec: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef7f0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef7f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef7f4: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef7f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef7f8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef7f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef7fc: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef7fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef800: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef800u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef804: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef804u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef808: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef80c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef80cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef810: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef810u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef814: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef818: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef818u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef81c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef81cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef820: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef820u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef824: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef824u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef828: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef828u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef82c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef82cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef830: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef830u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef834: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef834u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef838: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1ef838u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1ef83c: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1ef83cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1ef840: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef840u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef844: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef844u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef848: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef848u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef84c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef84cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef850: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef850u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef854: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef858: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef858u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef85c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef85cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef860: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef860u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef864: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef864u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef868: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef868u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef86c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef86cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef870: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef870u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef874: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef874u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef878: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef878u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef87c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef87cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef880: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef880u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef884: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef884u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef888: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef88c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef88cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef890: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef890u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef894: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef894u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef898: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef898u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef89c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef89cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef8a0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef8a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef8a4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef8a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef8a8: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef8a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef8ac: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef8acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef8b0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef8b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef8b4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef8b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef8b8: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef8bc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef8bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef8c0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef8c4: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef8c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef8c8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef8c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef8cc: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef8ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef8d0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef8d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef8d4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef8d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef8d8: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef8d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef8dc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef8e0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef8e4: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef8e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef8e8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef8e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef8ec: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef8ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef8f0: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef8f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef8f4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef8f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef8f8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef8fc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef8fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef900: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef900u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef904: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef908: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef908u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef90c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef90cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef910: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ef914: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1ef914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef918: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1ef918u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef91c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1ef91cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1ef920: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1ef920u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1ef924: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1ef924u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1ef928: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1ef928u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef92c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1ef92cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1ef930: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1ef930u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ef934: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1ef934u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1ef938: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1ef938u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1ef93c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ef93cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ef940: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef940u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef944: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1ef944u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ef948: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef948u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef94c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1ef94cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1ef950: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1ef950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ef954: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ef954u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ef958: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef958u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef95c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ef95cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ef960: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ef960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef964: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1ef964u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1ef968: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1ef968u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1ef96c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1ef96cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef970: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ef970u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ef974: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef974u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef978: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ef978u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ef97c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1ef97cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ef980: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef980u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1ef984: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef984u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef988: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ef988u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ef98c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef98cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef990: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef990u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef994: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef994u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef998: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1ef998u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef99c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef99cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef9a0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef9a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef9a4: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1ef9a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef9a8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1ef9a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ef9ac: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1ef9acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1ef9b0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ef9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ef9b4: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1ef9b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1ef9b8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef9bc: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1ef9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1ef9c0: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1ef9c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ef9c4: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1ef9c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1ef9c8: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1ef9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1ef9cc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef9ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1ef9d0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1ef9d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1ef9d4: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1ef9d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1ef9d8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1ef9d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1ef9dc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1ef9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1ef9e0: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1ef9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1ef9e4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1ef9e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ef9e8: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1ef9e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1ef9ec: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1ef9ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1ef9f0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1ef9f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ef9f4: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1ef9f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ef9f8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1ef9f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ef9fc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1ef9fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efa00: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efa00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efa04: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efa04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efa08: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efa08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efa0c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1efa0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1efa10: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1efa10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efa14: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1efa14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efa18: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1efa18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1efa1c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1efa1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1efa20: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1efa20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1efa24: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1efa24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efa28: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1efa28u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1efa2c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efa2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efa30: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1efa30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1efa34: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1efa34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1efa38: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1efa38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efa3c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efa3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efa40: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1efa40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efa44: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efa44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efa48: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1efa48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1efa4c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efa4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efa50: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1efa50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1efa54: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efa54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efa58: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1efa58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1efa5c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1efa5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efa60: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1efa60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1efa64: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1efa64u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1efa68: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1efa68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efa6c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1efa6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1efa70: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efa70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efa74: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1efa74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1efa78: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1efa78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efa7c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1efa7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1efa80: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efa80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efa84: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1efa84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1efa88: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efa88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efa8c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efa8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efa90: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efa90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efa94: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1efa94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efa98: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efa98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efa9c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efa9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efaa0: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1efaa0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efaa4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efaa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efaa8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efaa8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efaac: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efaacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efab0: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1efab0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efab4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efab8: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1efab8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1efabc: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1efabcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efac0: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1efac0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1efac4: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1efac4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1efac8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efac8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efacc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efaccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efad0: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1efad0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1efad4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efad8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efadc: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1efadcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1efae0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efae0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efae4: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1efae4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1efae8: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1efae8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1efaec: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1efaecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efaf0: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1efaf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efaf4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efaf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efaf8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efaf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efafc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efafcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efb00: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efb00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efb04: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efb04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efb08: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1efb08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1efb0c: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1efb0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efb10: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1efb10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efb14: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1efb14u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1efb18: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1efb18u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1efb1c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1efb1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1efb20: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1efb20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efb24: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1efb24u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1efb28: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efb28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efb2c: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1efb2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1efb30: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1efb30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1efb34: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1efb34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efb38: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efb38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efb3c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1efb3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efb40: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efb40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efb44: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1efb44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1efb48: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efb48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efb4c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1efb4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1efb50: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efb50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efb54: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1efb54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1efb58: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1efb58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efb5c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1efb5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1efb60: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1efb60u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1efb64: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1efb64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efb68: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1efb68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1efb6c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efb6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efb70: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1efb70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1efb74: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1efb74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efb78: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1efb78u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1efb7c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efb7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efb80: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1efb80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1efb84: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efb84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efb88: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efb88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efb8c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efb8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efb90: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1efb90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efb94: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efb94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efb98: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efb98u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efb9c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1efb9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efba0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efba4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efba4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efba8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efba8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efbac: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1efbacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efbb0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efbb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efbb4: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1efbb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1efbb8: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1efbb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efbbc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1efbbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1efbc0: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1efbc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1efbc4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efbc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efbc8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efbc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efbcc: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1efbccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1efbd0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efbd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efbd4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efbd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efbd8: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1efbd8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1efbdc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efbe0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1efbe0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1efbe4: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1efbe4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1efbe8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1efbe8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efbec: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1efbecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efbf0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efbf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efbf4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efbf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efbf8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efbf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efbfc: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efbfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efc00: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efc00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efc04: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1efc04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1efc08: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1efc08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efc0c: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1efc0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efc10: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1efc10u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1efc14: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1efc14u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1efc18: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1efc18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1efc1c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1efc1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efc20: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1efc20u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1efc24: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efc24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efc28: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1efc28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1efc2c: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1efc2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1efc30: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1efc30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efc34: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efc34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efc38: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1efc38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efc3c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efc3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efc40: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1efc40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1efc44: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efc44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efc48: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1efc48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1efc4c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efc50: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1efc50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1efc54: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1efc54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efc58: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1efc58u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1efc5c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1efc5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1efc60: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1efc60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efc64: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1efc64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1efc68: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efc68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efc6c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1efc6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1efc70: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1efc70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efc74: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1efc74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1efc78: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efc78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efc7c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1efc7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1efc80: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efc80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efc84: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efc84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efc88: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efc88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efc8c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1efc8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efc90: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efc90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efc94: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efc94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efc98: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1efc98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efc9c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efc9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efca0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efca0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efca4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efca4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efca8: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1efca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efcac: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efcacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efcb0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1efcb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1efcb4: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1efcb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efcb8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1efcb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1efcbc: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1efcbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1efcc0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efcc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efcc4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efcc4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efcc8: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1efcc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1efccc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efcccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efcd0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efcd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efcd4: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1efcd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1efcd8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efcd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efcdc: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1efcdcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1efce0: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1efce0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1efce4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1efce4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efce8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1efce8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efcec: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efcecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efcf0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efcf0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efcf4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efcf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efcf8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efcf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efcfc: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efcfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efd00: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1efd00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1efd04: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1efd04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efd08: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1efd08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efd0c: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1efd0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1efd10: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1efd10u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1efd14: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1efd14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1efd18: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1efd18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efd1c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1efd1cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1efd20: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efd20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efd24: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1efd24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1efd28: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1efd28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1efd2c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1efd2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efd30: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efd30u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efd34: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1efd34u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efd38: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efd38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efd3c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1efd3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1efd40: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efd40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efd44: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1efd44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1efd48: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efd48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efd4c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1efd4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1efd50: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1efd50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efd54: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1efd54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1efd58: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1efd58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1efd5c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1efd5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efd60: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1efd60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1efd64: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efd64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efd68: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1efd68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1efd6c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1efd6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efd70: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1efd70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1efd74: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efd74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efd78: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1efd78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1efd7c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efd7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efd80: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efd80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efd84: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efd84u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efd88: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1efd88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efd8c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efd8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efd90: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efd90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efd94: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1efd94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efd98: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efd98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efd9c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efd9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efda0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efda0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efda4: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1efda4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efda8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efda8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efdac: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1efdacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1efdb0: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1efdb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efdb4: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1efdb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1efdb8: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1efdb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1efdbc: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efdbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efdc0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efdc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efdc4: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1efdc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1efdc8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efdc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efdcc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efdccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efdd0: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1efdd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1efdd4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efdd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efdd8: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1efdd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1efddc: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1efddcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1efde0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1efde0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efde4: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1efde4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efde8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efde8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efdec: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efdecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efdf0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efdf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efdf4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efdf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efdf8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efdf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efdfc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1efdfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1efe00: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1efe00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efe04: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1efe04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efe08: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1efe08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1efe0c: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1efe0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1efe10: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1efe10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1efe14: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1efe14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efe18: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1efe18u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1efe1c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efe1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efe20: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1efe20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1efe24: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1efe24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1efe28: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1efe28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efe2c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efe2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efe30: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1efe30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1efe34: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efe34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efe38: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1efe38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1efe3c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efe3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efe40: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1efe40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1efe44: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efe44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efe48: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1efe48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1efe4c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1efe4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efe50: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1efe50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1efe54: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1efe54u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1efe58: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1efe58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efe5c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1efe5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1efe60: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efe60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efe64: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1efe64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1efe68: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1efe68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1efe6c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1efe6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1efe70: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efe70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efe74: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1efe74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1efe78: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efe78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efe7c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efe7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efe80: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efe80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efe84: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1efe84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efe88: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efe88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efe8c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efe8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efe90: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1efe90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efe94: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1efe94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1efe98: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efe98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efe9c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1efe9cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1efea0: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1efea0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1efea4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efea4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efea8: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1efea8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1efeac: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1efeacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1efeb0: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1efeb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1efeb4: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1efeb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1efeb8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1efeb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1efebc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1efebcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1efec0: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1efec0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1efec4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1efec4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1efec8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1efec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1efecc: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1efeccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1efed0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1efed0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1efed4: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1efed4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1efed8: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1efed8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1efedc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1efedcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1efee0: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1efee0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1efee4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1efee4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1efee8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1efee8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efeec: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1efeecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1efef0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1efef0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efef4: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efef4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efef8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1efef8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1efefc: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1efefcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eff00: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eff00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eff04: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1eff04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1eff08: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1eff08u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1eff0c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1eff0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1eff10: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1eff10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eff14: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eff14u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eff18: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1eff18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1eff1c: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1eff1cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1eff20: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1eff20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1eff24: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1eff24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1eff28: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eff28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eff2c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1eff2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1eff30: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1eff30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1eff34: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1eff34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1eff38: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eff38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eff3c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eff3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eff40: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eff40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eff44: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eff44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eff48: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eff48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eff4c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1eff4cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1eff50: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1eff50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1eff54: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1eff54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1eff58: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eff58u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eff5c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eff5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eff60: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eff60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eff64: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eff64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eff68: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eff68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eff6c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1eff6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1eff70: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1eff70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eff74: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1eff74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1eff78: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eff78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eff7c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eff7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eff80: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1eff80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1eff84: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eff84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eff88: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1eff88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eff8c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1eff8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1eff90: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1eff90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1eff94: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1eff94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1eff98: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eff98u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eff9c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1eff9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1effa0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1effa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1effa4: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1effa4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1effa8: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1effa8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1effac: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1effacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1effb0: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1effb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1effb4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1effb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1effb8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1effb8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1effbc: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1effbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1effc0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1effc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1effc4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1effc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1effc8: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1effc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1effcc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1effccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1effd0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1effd0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1effd4: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1effd4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1effd8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1effd8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1effdc: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1effdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1effe0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1effe0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1effe4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1effe4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1effe8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1effe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1effec: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1effecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1efff0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1efff0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1efff4: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1efff4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1efff8: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1efff8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1efffc: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1efffcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f0000: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1f0000u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1f0004: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1f0004u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1f0008: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1f0008u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1f000c: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1f000cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f0010: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f0010u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f0014: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f0014u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f0018: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1f0018u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1f001c: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1f001cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1f0020: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f0024: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f0024u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f0028: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1f0028u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f002c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f002cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f0030: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1f0030u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1f0034: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f0034u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f0038: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1f0038u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1f003c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f003cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f0040: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1f0040u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1f0044: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1f0044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f0048: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1f0048u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1f004c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1f004cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1f0050: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f0050u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f0054: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1f0054u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1f0058: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0058u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f005c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1f005cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1f0060: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1f0060u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f0064: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0064u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1f0068: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f0068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f006c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1f006cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f0070: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f0070u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f0074: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0074u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0078: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f0078u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f007c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1f007cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f0080: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0080u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0084: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f0084u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0088: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1f0088u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f008c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f008cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0090: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f0090u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0094: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f0094u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f0098: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1f0098u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f009c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f009cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f00a0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1f00a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1f00a4: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1f00a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f00a8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1f00a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1f00ac: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1f00acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1f00b0: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f00b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f00b4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f00b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f00b8: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1f00b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1f00bc: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f00bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f00c0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f00c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f00c4: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1f00c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1f00c8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f00c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f00cc: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1f00ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1f00d0: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1f00d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1f00d4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1f00d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f00d8: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1f00d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f00dc: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f00dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f00e0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f00e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f00e4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f00e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f00e8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f00e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f00ec: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f00ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f00f0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1f00f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1f00f4: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1f00f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f00f8: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1f00f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f00fc: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1f00fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1f0100: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1f0100u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1f0104: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1f0104u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1f0108: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1f0108u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f010c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f010cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f0110: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f0110u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f0114: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1f0114u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1f0118: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1f0118u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1f011c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f011cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f0120: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f0120u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f0124: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1f0124u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f0128: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f0128u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f012c: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1f012cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1f0130: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f0130u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f0134: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1f0134u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1f0138: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f0138u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f013c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1f013cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1f0140: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1f0140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f0144: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1f0144u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1f0148: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1f0148u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1f014c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f014cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f0150: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1f0150u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1f0154: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0154u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f0158: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1f0158u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1f015c: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1f015cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f0160: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0160u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1f0164: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f0164u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f0168: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1f0168u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f016c: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f016cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f0170: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0174: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f0174u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0178: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1f0178u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f017c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f017cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0180: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f0180u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0184: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1f0184u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f0188: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f018c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f018cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0190: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f0190u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f0194: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1f0194u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f0198: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0198u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f019c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1f019cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1f01a0: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1f01a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f01a4: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1f01a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1f01a8: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1f01a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1f01ac: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f01acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f01b0: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f01b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f01b4: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1f01b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1f01b8: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f01b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f01bc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f01bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f01c0: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1f01c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1f01c4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f01c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f01c8: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1f01c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1f01cc: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1f01ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1f01d0: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1f01d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f01d4: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1f01d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f01d8: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f01d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f01dc: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f01dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f01e0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f01e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f01e4: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f01e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f01e8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f01e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f01ec: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1f01ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1f01f0: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1f01f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f01f4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1f01f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f01f8: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1f01f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1f01fc: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1f01fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1f0200: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1f0200u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1f0204: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1f0204u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f0208: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f0208u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f020c: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f020cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f0210: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1f0210u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1f0214: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1f0214u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1f0218: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0218u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f021c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f021cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f0220: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1f0220u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f0224: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f0224u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f0228: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1f0228u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1f022c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f022cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f0230: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1f0230u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1f0234: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f0234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f0238: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1f0238u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1f023c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1f023cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f0240: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1f0240u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1f0244: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1f0244u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1f0248: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f0248u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f024c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1f024cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1f0250: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0250u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f0254: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1f0254u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1f0258: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1f0258u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f025c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f025cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1f0260: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f0260u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f0264: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1f0264u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f0268: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f0268u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f026c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f026cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0270: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f0270u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0274: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1f0274u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f0278: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0278u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f027c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f027cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0280: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1f0280u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f0284: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0284u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0288: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f0288u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f028c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f028cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f0290: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1f0290u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f0294: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0294u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0298: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1f0298u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1f029c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1f029cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f02a0: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1f02a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1f02a4: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1f02a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1f02a8: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f02a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f02ac: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f02acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f02b0: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1f02b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1f02b4: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f02b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f02b8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f02b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f02bc: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1f02bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1f02c0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f02c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f02c4: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1f02c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1f02c8: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1f02c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1f02cc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1f02ccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f02d0: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1f02d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f02d4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f02d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f02d8: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f02d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f02dc: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f02dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f02e0: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f02e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f02e4: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f02e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f02e8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1f02e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1f02ec: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1f02ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f02f0: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1f02f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f02f4: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1f02f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1f02f8: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1f02f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1f02fc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1f02fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1f0300: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1f0300u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f0304: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f0304u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f0308: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f0308u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f030c: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1f030cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1f0310: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1f0310u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1f0314: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f0318: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f0318u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f031c: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1f031cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f0320: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f0320u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f0324: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1f0324u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1f0328: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f0328u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f032c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1f032cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1f0330: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f0330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f0334: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1f0334u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1f0338: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1f0338u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f033c: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1f033cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1f0340: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1f0340u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1f0344: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f0344u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f0348: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1f0348u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1f034c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f034cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f0350: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1f0350u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1f0354: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1f0354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f0358: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0358u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1f035c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f035cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f0360: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1f0360u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f0364: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f0364u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f0368: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f036c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f036cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0370: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1f0370u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f0374: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0374u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0378: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f0378u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f037c: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1f037cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f0380: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0380u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0384: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f0384u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0388: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f0388u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f038c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1f038cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f0390: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f0390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0394: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1f0394u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1f0398: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1f0398u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f039c: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1f039cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1f03a0: 0xafc30040  sw          $v1, 0x40($fp)
    ctx->pc = 0x1f03a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 3));
    // 0x1f03a4: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f03a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f03a8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f03a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f03ac: 0xafc4003c  sw          $a0, 0x3C($fp)
    ctx->pc = 0x1f03acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 4));
    // 0x1f03b0: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f03b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f03b4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f03b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f03b8: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1f03b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1f03bc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f03bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f03c0: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1f03c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1f03c4: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1f03c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1f03c8: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1f03c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f03cc: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1f03ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f03d0: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f03d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f03d4: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f03d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f03d8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f03d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f03dc: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f03dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f03e0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f03e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f03e4: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1f03e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1f03e8: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1f03e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f03ec: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1f03ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f03f0: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1f03f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1f03f4: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1f03f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1f03f8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1f03f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1f03fc: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1f03fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f0400: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f0400u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f0404: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f0404u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f0408: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1f0408u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1f040c: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1f040cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1f0410: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0410u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f0414: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f0414u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f0418: 0x8fc40034  lw          $a0, 0x34($fp)
    ctx->pc = 0x1f0418u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f041c: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1f041cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1f0420: 0xafc40034  sw          $a0, 0x34($fp)
    ctx->pc = 0x1f0420u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 4));
    // 0x1f0424: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f0424u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f0428: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1f0428u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1f042c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f042cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f0430: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1f0430u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1f0434: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1f0434u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f0438: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1f0438u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1f043c: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1f043cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1f0440: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f0440u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f0444: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1f0444u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1f0448: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0448u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f044c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1f044cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1f0450: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1f0450u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f0454: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0454u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1f0458: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1f0458u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1f045c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1f045cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f0460: 0x8fc4003c  lw          $a0, 0x3C($fp)
    ctx->pc = 0x1f0460u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1f0464: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0464u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0468: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f0468u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f046c: 0x8fc40040  lw          $a0, 0x40($fp)
    ctx->pc = 0x1f046cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1f0470: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f0470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0474: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f0474u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0478: 0x8fc40044  lw          $a0, 0x44($fp)
    ctx->pc = 0x1f0478u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1f047c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1f047cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1f0480: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f0480u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f0484: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f0484u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f0488: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0488u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f048c: 0x21940  sll         $v1, $v0, 5
    ctx->pc = 0x1f048cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1f0490: 0x216c2  srl         $v0, $v0, 27
    ctx->pc = 0x1f0490u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 27));
    // 0x1f0494: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1f0494u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f0498: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1f0498u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f049c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f049cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f04a0: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x1f04a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f04a4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f04a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f04a8: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1f04a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1f04ac: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f04acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f04b0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1f04b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1f04b4: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1f04b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f04b8: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1f04b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f04bc: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x1f04bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1f04c0: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x1f04c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x1f04c4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1f04c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1f04c8: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1f04c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1f04cc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f04ccu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f04d0: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1f04d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f04d4: 0x3c02ca62  lui         $v0, 0xCA62
    ctx->pc = 0x1f04d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)51810 << 16));
    // 0x1f04d8: 0x3442c1d6  ori         $v0, $v0, 0xC1D6
    ctx->pc = 0x1f04d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49622);
    // 0x1f04dc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f04dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f04e0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1f04e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1f04e4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f04e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f04e8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1f04e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1f04ec: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f04ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f04f0: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1f04f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1f04f4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1f04f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f04f8: 0x21f80  sll         $v1, $v0, 30
    ctx->pc = 0x1f04f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 30));
    // 0x1f04fc: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1f04fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1f0500: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f0500u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f0504: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1f0504u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1f0508: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0508u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f050c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1f050cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1f0510: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1f0510u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1f0514: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0514u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1f0518: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f0518u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f051c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f051cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0520: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1f0520u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f0524: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1f0524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1f0528: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f052c: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x1f052cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x1f0530: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f0530u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0534: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f0534u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0538: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1f0538u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1f053c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1f053cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1f0540: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f0544: 0xac820004  sw          $v0, 0x4($a0)
    ctx->pc = 0x1f0544u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
    // 0x1f0548: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f0548u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f054c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f054cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0550: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1f0550u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1f0554: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1f0554u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1f0558: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0558u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f055c: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x1f055cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x1f0560: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f0560u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0564: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f0564u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0568: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x1f0568u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f056c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1f056cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f0570: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0570u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f0574: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x1f0574u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x1f0578: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f0578u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f057c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f057cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0580: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x1f0580u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1f0584: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1f0584u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1f0588: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1f0588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f058c: 0xac820010  sw          $v0, 0x10($a0)
    ctx->pc = 0x1f058cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x1f0590: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f0590u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f0594: 0x28420039  slti        $v0, $v0, 0x39
    ctx->pc = 0x1f0594u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)57) ? 1 : 0);
    // 0x1f0598: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1f0598u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
label_1f059c:
    // 0x1f059c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f059cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f05a0: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x1f05a0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1f05a4: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x1f05a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1f05a8: 0x27bd0060  addiu       $sp, $sp, 0x60
    ctx->pc = 0x1f05a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1f05ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1F05ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EB8B8u: goto label_1eb8b8;
            case 0x1EB8F8u: goto label_1eb8f8;
            case 0x1EB910u: goto label_1eb910;
            case 0x1EB970u: goto label_1eb970;
            case 0x1EB9B4u: goto label_1eb9b4;
            case 0x1EB9BCu: goto label_1eb9bc;
            case 0x1EB9D4u: goto label_1eb9d4;
            case 0x1EBA00u: goto label_1eba00;
            case 0x1EBA48u: goto label_1eba48;
            case 0x1EBA50u: goto label_1eba50;
            case 0x1EBA68u: goto label_1eba68;
            case 0x1EBA70u: goto label_1eba70;
            case 0x1EBAA8u: goto label_1ebaa8;
            case 0x1EBB24u: goto label_1ebb24;
            case 0x1EBB3Cu: goto label_1ebb3c;
            case 0x1F059Cu: goto label_1f059c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F05B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
