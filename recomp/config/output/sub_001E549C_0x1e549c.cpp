#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E549C
// Address: 0x1e549c - 0x1e57d8
void sub_001E549C_0x1e549c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E549C_0x1e549c");
#endif

    switch (ctx->pc) {
        case 0x1e5574u: goto label_1e5574;
        case 0x1e55c8u: goto label_1e55c8;
        case 0x1e55ecu: goto label_1e55ec;
        case 0x1e566cu: goto label_1e566c;
        case 0x1e575cu: goto label_1e575c;
        case 0x1e57a0u: goto label_1e57a0;
        default: break;
    }

    ctx->pc = 0x1e549cu;

    // 0x1e549c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e549cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e54a0: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e54a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e54a4: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e54a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e54a8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e54a8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e54ac: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e54acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e54b0: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e54b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e54b4: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e54b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e54b8: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e54b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e54bc: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e54bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e54c0: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e54c0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e54c4: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e54c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e54c8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e54c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e54cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e54ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e54d0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E54D0u;
    {
        const bool branch_taken_0x1e54d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e54d0) {
            ctx->pc = 0x1E54F8u;
            goto label_1e54f8;
        }
    }
    ctx->pc = 0x1E54D8u;
    // 0x1e54d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e54d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e54dc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e54dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e54e0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e54e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e54e4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e54e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e54e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e54e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e54ec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e54ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e54f0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E54F0u;
    {
        const bool branch_taken_0x1e54f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e54f0) {
            ctx->pc = 0x1E550Cu;
            goto label_1e550c;
        }
    }
    ctx->pc = 0x1E54F8u;
label_1e54f8:
    // 0x1e54f8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e54f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e54fc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e54fcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5500: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5504: 0x100000ae  b           . + 4 + (0xAE << 2)
    ctx->pc = 0x1E5504u;
    {
        const bool branch_taken_0x1e5504 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5504) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E550Cu;
label_1e550c:
    // 0x1e550c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e550cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5510: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5510u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5514: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5514u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5518: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5518u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e551c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e551cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5520: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5524: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5524u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e5528: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e5528u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e552c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e552cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e5530: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E5530u;
    {
        const bool branch_taken_0x1e5530 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5530) {
            ctx->pc = 0x1E554Cu;
            goto label_1e554c;
        }
    }
    ctx->pc = 0x1E5538u;
    // 0x1e5538: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e5538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e553c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e553cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e5540: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e5540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5544: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1E5544u;
    {
        const bool branch_taken_0x1e5544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5544) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E554Cu;
label_1e554c:
    // 0x1e554c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e554cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5550: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5550u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5554: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5554u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5558: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e5558u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e555c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e555cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e5560: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e5560u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e5564: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5564u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5568: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e5568u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e556c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E556Cu;
    SET_GPR_U32(ctx, 31, 0x1E5574u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5574u; }
        if (ctx->pc != 0x1E5574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E5574u; }
        if (ctx->pc != 0x1E5574u) { return; }
    }
    ctx->pc = 0x1E5574u;
label_1e5574:
    // 0x1e5574: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e5574u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e5578: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e5578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e557c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E557Cu;
    {
        const bool branch_taken_0x1e557c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e557c) {
            ctx->pc = 0x1E5598u;
            goto label_1e5598;
        }
    }
    ctx->pc = 0x1E5584u;
    // 0x1e5584: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e5584u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e5588: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e5588u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e558c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e558cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e5590: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x1E5590u;
    {
        const bool branch_taken_0x1e5590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5590) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E5598u;
label_1e5598:
    // 0x1e5598: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5598u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e559c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e559cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e55a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e55a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e55a4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e55a4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e55a8: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e55a8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e55ac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e55acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e55b0: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e55b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e55b4: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e55b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e55b8: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e55b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e55bc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e55bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e55c0: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E55C0u;
    SET_GPR_U32(ctx, 31, 0x1E55C8u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E55C8u; }
        if (ctx->pc != 0x1E55C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E55C8u; }
        if (ctx->pc != 0x1E55C8u) { return; }
    }
    ctx->pc = 0x1E55C8u;
label_1e55c8:
    // 0x1e55c8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e55c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e55cc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e55ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e55d0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E55D0u;
    {
        const bool branch_taken_0x1e55d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e55d0) {
            ctx->pc = 0x1E5600u;
            goto label_1e5600;
        }
    }
    ctx->pc = 0x1E55D8u;
    // 0x1e55d8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e55d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e55dc: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e55dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e55e0: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e55e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e55e4: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E55E4u;
    SET_GPR_U32(ctx, 31, 0x1E55ECu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E55ECu; }
        if (ctx->pc != 0x1E55ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E55ECu; }
        if (ctx->pc != 0x1E55ECu) { return; }
    }
    ctx->pc = 0x1E55ECu;
label_1e55ec:
    // 0x1e55ec: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e55ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e55f0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e55f0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e55f4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e55f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e55f8: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x1E55F8u;
    {
        const bool branch_taken_0x1e55f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e55f8) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E5600u;
label_1e5600:
    // 0x1e5600: 0x27c60018  addiu       $a2, $fp, 0x18
    ctx->pc = 0x1e5600u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e5604: 0x8cc50000  lw          $a1, 0x0($a2)
    ctx->pc = 0x1e5604u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1e5608: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5608u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e560c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e560cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5610: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1e5610u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e5614: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1e5614u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1e5618: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e561c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e561cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5620: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e5620u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e5624: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e5624u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e5628: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5628u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e562c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e562cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5630: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e5630u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5634: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e5634u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e5638: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e5638u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e563c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e563cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e5640: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5640u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e5644: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5644u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5648: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e5648u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e564c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e564cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e5650: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1e5650u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1e5654: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5654u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5658: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1e5658u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e565c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1e565cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1e5660: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1e5660u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1e5664: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x1e5664u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
    // 0x1e5668: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e5668u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
label_1e566c:
    // 0x1e566c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e566cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5670: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e5670u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e5674: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5678: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1e5678u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1e567c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E567Cu;
    {
        const bool branch_taken_0x1e567c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e567c) {
            ctx->pc = 0x1E568Cu;
            goto label_1e568c;
        }
    }
    ctx->pc = 0x1E5684u;
    // 0x1e5684: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1E5684u;
    {
        const bool branch_taken_0x1e5684 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5684) {
            ctx->pc = 0x1E5748u;
            goto label_1e5748;
        }
    }
    ctx->pc = 0x1E568Cu;
label_1e568c:
    // 0x1e568c: 0x27c70018  addiu       $a3, $fp, 0x18
    ctx->pc = 0x1e568cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1e5690: 0x8ce60000  lw          $a2, 0x0($a3)
    ctx->pc = 0x1e5690u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1e5694: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e5694u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5698: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e5698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e569c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e569cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e56a0: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1e56a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1e56a4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e56a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e56a8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e56a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e56ac: 0x304400ff  andi        $a0, $v0, 0xFF
    ctx->pc = 0x1e56acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e56b0: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x1e56b0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1e56b4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e56b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e56b8: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e56b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e56bc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e56bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e56c0: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e56c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e56c4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e56c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e56c8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e56c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e56cc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e56ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e56d0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e56d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e56d4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e56d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e56d8: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e56d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e56dc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e56dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e56e0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e56e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e56e4: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e56e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e56e8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e56e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e56ec: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e56ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e56f0: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e56f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e56f4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e56f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e56f8: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e56f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e56fc: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e56fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5700: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e5700u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e5704: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e5704u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e5708: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5708u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e570c: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1e570cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1e5710: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e5710u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e5714: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1e5714u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5718: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e5718u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e571c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e571cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e5720: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e5720u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e5724: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e5724u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e5728: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1e5728u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1e572c: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1e572cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1e5730: 0xace60000  sw          $a2, 0x0($a3)
    ctx->pc = 0x1e5730u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 6));
    // 0x1e5734: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e5734u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e5738: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e5738u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e573c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e573cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e5740: 0x1000ffca  b           . + 4 + (-0x36 << 2)
    ctx->pc = 0x1E5740u;
    {
        const bool branch_taken_0x1e5740 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e5740) {
            ctx->pc = 0x1E566Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e566c;
        }
    }
    ctx->pc = 0x1E5748u;
label_1e5748:
    // 0x1e5748: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e5748u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e574c: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e574cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e5750: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e5750u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5754: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E5754u;
    SET_GPR_U32(ctx, 31, 0x1E575Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E575Cu; }
        if (ctx->pc != 0x1E575Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E575Cu; }
        if (ctx->pc != 0x1E575Cu) { return; }
    }
    ctx->pc = 0x1E575Cu;
label_1e575c:
    // 0x1e575c: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1e575cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e5760: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1e5760u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1e5764: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e5764u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5768: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e5768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e576c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e576cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e5770: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1e5770u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5774: 0x97c3000c  lhu         $v1, 0xC($fp)
    ctx->pc = 0x1e5774u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e5778: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1e5778u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e577c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e577cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e5780: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e5780u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e5784: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e5784u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e5788: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e5788u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e578c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e578cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5790: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1e5790u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e5794: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e5794u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5798: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E5798u;
    SET_GPR_U32(ctx, 31, 0x1E57A0u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E57A0u; }
        if (ctx->pc != 0x1E57A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E57A0u; }
        if (ctx->pc != 0x1E57A0u) { return; }
    }
    ctx->pc = 0x1E57A0u;
label_1e57a0:
    // 0x1e57a0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E57A0u;
    {
        const bool branch_taken_0x1e57a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e57a0) {
            ctx->pc = 0x1E57BCu;
            goto label_1e57bc;
        }
    }
    ctx->pc = 0x1E57A8u;
    // 0x1e57a8: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e57a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e57ac: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e57acu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e57b0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e57b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e57b4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E57B4u;
    {
        const bool branch_taken_0x1e57b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e57b4) {
            ctx->pc = 0x1E57C0u;
            goto label_1e57c0;
        }
    }
    ctx->pc = 0x1E57BCu;
label_1e57bc:
    // 0x1e57bc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e57bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e57c0:
    // 0x1e57c0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e57c0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e57c4: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e57c4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e57c8: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e57c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e57cc: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e57ccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e57d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E57D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E54F8u: goto label_1e54f8;
            case 0x1E550Cu: goto label_1e550c;
            case 0x1E554Cu: goto label_1e554c;
            case 0x1E5574u: goto label_1e5574;
            case 0x1E5598u: goto label_1e5598;
            case 0x1E55C8u: goto label_1e55c8;
            case 0x1E55ECu: goto label_1e55ec;
            case 0x1E5600u: goto label_1e5600;
            case 0x1E566Cu: goto label_1e566c;
            case 0x1E568Cu: goto label_1e568c;
            case 0x1E5748u: goto label_1e5748;
            case 0x1E575Cu: goto label_1e575c;
            case 0x1E57A0u: goto label_1e57a0;
            case 0x1E57BCu: goto label_1e57bc;
            case 0x1E57C0u: goto label_1e57c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E57D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
