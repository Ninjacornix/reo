#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E38B8
// Address: 0x1e38b8 - 0x1e3a90
void sub_001E38B8_0x1e38b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E38B8_0x1e38b8");
#endif

    switch (ctx->pc) {
        case 0x1e396cu: goto label_1e396c;
        case 0x1e39a0u: goto label_1e39a0;
        case 0x1e39c4u: goto label_1e39c4;
        case 0x1e3a44u: goto label_1e3a44;
        case 0x1e3a74u: goto label_1e3a74;
        default: break;
    }

    ctx->pc = 0x1e38b8u;

    // 0x1e38b8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e38b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e38bc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e38bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e38c0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e38c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e38c4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e38c4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e38c8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e38c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e38cc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e38ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e38d0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e38d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e38d4: 0xafc00010  sw          $zero, 0x10($fp)
    ctx->pc = 0x1e38d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
    // 0x1e38d8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e38d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e38dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e38dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e38e0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E38E0u;
    {
        const bool branch_taken_0x1e38e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e38e0) {
            ctx->pc = 0x1E3908u;
            goto label_1e3908;
        }
    }
    ctx->pc = 0x1E38E8u;
    // 0x1e38e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e38e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e38ec: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e38ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e38f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e38f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e38f4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e38f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e38f8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e38f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e38fc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e38fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3900: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3900u;
    {
        const bool branch_taken_0x1e3900 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3900) {
            ctx->pc = 0x1E391Cu;
            goto label_1e391c;
        }
    }
    ctx->pc = 0x1E3908u;
label_1e3908:
    // 0x1e3908: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e3908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e390c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e390cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3910: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3910u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3914: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E3914u;
    {
        const bool branch_taken_0x1e3914 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3914) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E391Cu;
label_1e391c:
    // 0x1e391c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e391cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3920: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e3920u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e3924: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e3924u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e3928: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e3928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e392c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e392cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e3930: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e3930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e3934: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e3934u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e3938: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e3938u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e393c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e393cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3940: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3940u;
    {
        const bool branch_taken_0x1e3940 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3940) {
            ctx->pc = 0x1E395Cu;
            goto label_1e395c;
        }
    }
    ctx->pc = 0x1E3948u;
    // 0x1e3948: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e394c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e394cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3950: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3954: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E3954u;
    {
        const bool branch_taken_0x1e3954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3954) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E395Cu;
label_1e395c:
    // 0x1e395c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e395cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3960: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3960u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3964: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3964u;
    SET_GPR_U32(ctx, 31, 0x1E396Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E396Cu; }
        if (ctx->pc != 0x1E396Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E396Cu; }
        if (ctx->pc != 0x1E396Cu) { return; }
    }
    ctx->pc = 0x1E396Cu;
label_1e396c:
    // 0x1e396c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e396cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e3970: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3974: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3974u;
    {
        const bool branch_taken_0x1e3974 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3974) {
            ctx->pc = 0x1E3990u;
            goto label_1e3990;
        }
    }
    ctx->pc = 0x1E397Cu;
    // 0x1e397c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e397cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e3980: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3980u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3984: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3984u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3988: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E3988u;
    {
        const bool branch_taken_0x1e3988 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3988) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E3990u;
label_1e3990:
    // 0x1e3990: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e3990u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3994: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e3994u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3998: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3998u;
    SET_GPR_U32(ctx, 31, 0x1E39A0u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E39A0u; }
        if (ctx->pc != 0x1E39A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E39A0u; }
        if (ctx->pc != 0x1E39A0u) { return; }
    }
    ctx->pc = 0x1E39A0u;
label_1e39a0:
    // 0x1e39a0: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e39a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e39a4: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e39a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e39a8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E39A8u;
    {
        const bool branch_taken_0x1e39a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e39a8) {
            ctx->pc = 0x1E39D8u;
            goto label_1e39d8;
        }
    }
    ctx->pc = 0x1E39B0u;
    // 0x1e39b0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e39b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e39b4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e39b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e39b8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e39b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e39bc: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E39BCu;
    SET_GPR_U32(ctx, 31, 0x1E39C4u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E39C4u; }
        if (ctx->pc != 0x1E39C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E39C4u; }
        if (ctx->pc != 0x1E39C4u) { return; }
    }
    ctx->pc = 0x1E39C4u;
label_1e39c4:
    // 0x1e39c4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e39c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e39c8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e39c8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e39cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e39ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e39d0: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1E39D0u;
    {
        const bool branch_taken_0x1e39d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e39d0) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E39D8u;
label_1e39d8:
    // 0x1e39d8: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e39d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e39dc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e39dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e39e0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e39e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e39e4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e39e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e39e8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e39e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e39ec: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e39ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e39f0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e39f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e39f4: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e39f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e39f8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e39f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e39fc: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e39fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3a00: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3a00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3a04: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e3a04u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e3a08: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e3a08u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3a0c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e3a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e3a10: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3a10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e3a14: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3a14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3a18: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e3a18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3a1c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3a1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3a20: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e3a20u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e3a24: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e3a24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3a28: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e3a28u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3a2c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e3a2cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e3a30: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e3a30u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e3a34: 0x2408000b  addiu       $t0, $zero, 0xB
    ctx->pc = 0x1e3a34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1e3a38: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e3a38u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3a3c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E3A3Cu;
    SET_GPR_U32(ctx, 31, 0x1E3A44u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3A44u; }
        if (ctx->pc != 0x1E3A44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3A44u; }
        if (ctx->pc != 0x1E3A44u) { return; }
    }
    ctx->pc = 0x1E3A44u;
label_1e3a44:
    // 0x1e3a44: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3A44u;
    {
        const bool branch_taken_0x1e3a44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3a44) {
            ctx->pc = 0x1E3A60u;
            goto label_1e3a60;
        }
    }
    ctx->pc = 0x1E3A4Cu;
    // 0x1e3a4c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e3a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3a50: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3a50u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3a54: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3a54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3a58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E3A58u;
    {
        const bool branch_taken_0x1e3a58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3a58) {
            ctx->pc = 0x1E3A78u;
            goto label_1e3a78;
        }
    }
    ctx->pc = 0x1E3A60u;
label_1e3a60:
    // 0x1e3a60: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e3a60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e3a64: 0x2405001b  addiu       $a1, $zero, 0x1B
    ctx->pc = 0x1e3a64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x1e3a68: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e3a68u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e3a6c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E3A6Cu;
    SET_GPR_U32(ctx, 31, 0x1E3A74u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3A74u; }
        if (ctx->pc != 0x1E3A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3A74u; }
        if (ctx->pc != 0x1E3A74u) { return; }
    }
    ctx->pc = 0x1E3A74u;
label_1e3a74:
    // 0x1e3a74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e3a74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e3a78:
    // 0x1e3a78: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3a78u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3a7c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e3a7cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e3a80: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e3a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e3a84: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e3a84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e3a88: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3A88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E3908u: goto label_1e3908;
            case 0x1E391Cu: goto label_1e391c;
            case 0x1E395Cu: goto label_1e395c;
            case 0x1E396Cu: goto label_1e396c;
            case 0x1E3990u: goto label_1e3990;
            case 0x1E39A0u: goto label_1e39a0;
            case 0x1E39C4u: goto label_1e39c4;
            case 0x1E39D8u: goto label_1e39d8;
            case 0x1E3A44u: goto label_1e3a44;
            case 0x1E3A60u: goto label_1e3a60;
            case 0x1E3A74u: goto label_1e3a74;
            case 0x1E3A78u: goto label_1e3a78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3A90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
