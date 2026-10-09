#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E65A4
// Address: 0x1e65a4 - 0x1e677c
void sub_001E65A4_0x1e65a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E65A4_0x1e65a4");
#endif

    switch (ctx->pc) {
        case 0x1e6674u: goto label_1e6674;
        case 0x1e66acu: goto label_1e66ac;
        case 0x1e66d0u: goto label_1e66d0;
        case 0x1e66fcu: goto label_1e66fc;
        case 0x1e6718u: goto label_1e6718;
        case 0x1e6744u: goto label_1e6744;
        default: break;
    }

    ctx->pc = 0x1e65a4u;

    // 0x1e65a4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e65a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e65a8: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e65a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e65ac: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e65acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e65b0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e65b0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e65b4: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e65b4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e65b8: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e65b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e65bc: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e65bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e65c0: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e65c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e65c4: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1e65c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1e65c8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e65c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e65cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e65ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e65d0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E65D0u;
    {
        const bool branch_taken_0x1e65d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e65d0) {
            ctx->pc = 0x1E65F8u;
            goto label_1e65f8;
        }
    }
    ctx->pc = 0x1E65D8u;
    // 0x1e65d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e65d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e65dc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e65dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e65e0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e65e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e65e4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e65e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e65e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e65e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e65ec: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e65ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e65f0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E65F0u;
    {
        const bool branch_taken_0x1e65f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e65f0) {
            ctx->pc = 0x1E660Cu;
            goto label_1e660c;
        }
    }
    ctx->pc = 0x1E65F8u;
label_1e65f8:
    // 0x1e65f8: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e65f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e65fc: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e65fcu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6600: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6600u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6604: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1E6604u;
    {
        const bool branch_taken_0x1e6604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6604) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E660Cu;
label_1e660c:
    // 0x1e660c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e660cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6610: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6610u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6614: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6614u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6618: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6618u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e661c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e661cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6620: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6620u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6624: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e6624u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e6628: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e6628u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e662c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e662cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6630: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6630u;
    {
        const bool branch_taken_0x1e6630 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6630) {
            ctx->pc = 0x1E664Cu;
            goto label_1e664c;
        }
    }
    ctx->pc = 0x1E6638u;
    // 0x1e6638: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e663c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e663cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6640: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6640u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6644: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1E6644u;
    {
        const bool branch_taken_0x1e6644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6644) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E664Cu;
label_1e664c:
    // 0x1e664c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e664cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6650: 0x2c420368  sltiu       $v0, $v0, 0x368
    ctx->pc = 0x1e6650u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)872) ? 1 : 0);
    // 0x1e6654: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6654u;
    {
        const bool branch_taken_0x1e6654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6654) {
            ctx->pc = 0x1E6664u;
            goto label_1e6664;
        }
    }
    ctx->pc = 0x1E665Cu;
    // 0x1e665c: 0x24020368  addiu       $v0, $zero, 0x368
    ctx->pc = 0x1e665cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 872));
    // 0x1e6660: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e6660u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
label_1e6664:
    // 0x1e6664: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e6664u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6668: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e6668u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e666c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E666Cu;
    SET_GPR_U32(ctx, 31, 0x1E6674u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6674u; }
        if (ctx->pc != 0x1E6674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6674u; }
        if (ctx->pc != 0x1E6674u) { return; }
    }
    ctx->pc = 0x1E6674u;
label_1e6674:
    // 0x1e6674: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e6674u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6678: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e667c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E667Cu;
    {
        const bool branch_taken_0x1e667c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e667c) {
            ctx->pc = 0x1E6698u;
            goto label_1e6698;
        }
    }
    ctx->pc = 0x1E6684u;
    // 0x1e6684: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e6684u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e6688: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6688u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e668c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e668cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6690: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1E6690u;
    {
        const bool branch_taken_0x1e6690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6690) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E6698u;
label_1e6698:
    // 0x1e6698: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e6698u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e669c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e669cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e66a0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e66a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e66a4: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E66A4u;
    SET_GPR_U32(ctx, 31, 0x1E66ACu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66ACu; }
        if (ctx->pc != 0x1E66ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66ACu; }
        if (ctx->pc != 0x1E66ACu) { return; }
    }
    ctx->pc = 0x1E66ACu;
label_1e66ac:
    // 0x1e66ac: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e66acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e66b0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e66b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e66b4: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E66B4u;
    {
        const bool branch_taken_0x1e66b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e66b4) {
            ctx->pc = 0x1E66E4u;
            goto label_1e66e4;
        }
    }
    ctx->pc = 0x1E66BCu;
    // 0x1e66bc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e66bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e66c0: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e66c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e66c4: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e66c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e66c8: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E66C8u;
    SET_GPR_U32(ctx, 31, 0x1E66D0u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66D0u; }
        if (ctx->pc != 0x1E66D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66D0u; }
        if (ctx->pc != 0x1E66D0u) { return; }
    }
    ctx->pc = 0x1E66D0u;
label_1e66d0:
    // 0x1e66d0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e66d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e66d4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e66d4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e66d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e66d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e66dc: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1E66DCu;
    {
        const bool branch_taken_0x1e66dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e66dc) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E66E4u;
label_1e66e4:
    // 0x1e66e4: 0x27c20004  addiu       $v0, $fp, 0x4
    ctx->pc = 0x1e66e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 4));
    // 0x1e66e8: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e66e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e66ec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e66ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e66f0: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1e66f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e66f4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E66F4u;
    SET_GPR_U32(ctx, 31, 0x1E66FCu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66FCu; }
        if (ctx->pc != 0x1E66FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E66FCu; }
        if (ctx->pc != 0x1E66FCu) { return; }
    }
    ctx->pc = 0x1E66FCu;
label_1e66fc:
    // 0x1e66fc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e66fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6700: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e6700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6704: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e6704u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6708: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e6708u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e670c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e670cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6710: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E6710u;
    SET_GPR_U32(ctx, 31, 0x1E6718u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6718u; }
        if (ctx->pc != 0x1E6718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6718u; }
        if (ctx->pc != 0x1E6718u) { return; }
    }
    ctx->pc = 0x1E6718u;
label_1e6718:
    // 0x1e6718: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e6718u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e671c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e671cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e6720: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e6720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e6724: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e6724u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6728: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1e6728u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e672c: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e672cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e6730: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e6730u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6734: 0x2408003f  addiu       $t0, $zero, 0x3F
    ctx->pc = 0x1e6734u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x1e6738: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e6738u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e673c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E673Cu;
    SET_GPR_U32(ctx, 31, 0x1E6744u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6744u; }
        if (ctx->pc != 0x1E6744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6744u; }
        if (ctx->pc != 0x1E6744u) { return; }
    }
    ctx->pc = 0x1E6744u;
label_1e6744:
    // 0x1e6744: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6744u;
    {
        const bool branch_taken_0x1e6744 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6744) {
            ctx->pc = 0x1E6760u;
            goto label_1e6760;
        }
    }
    ctx->pc = 0x1E674Cu;
    // 0x1e674c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e674cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6750: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6750u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6754: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6758: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E6758u;
    {
        const bool branch_taken_0x1e6758 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6758) {
            ctx->pc = 0x1E6764u;
            goto label_1e6764;
        }
    }
    ctx->pc = 0x1E6760u;
label_1e6760:
    // 0x1e6760: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e6760u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6764:
    // 0x1e6764: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6764u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6768: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e6768u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e676c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e676cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e6770: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e6770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e6774: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6774u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E65F8u: goto label_1e65f8;
            case 0x1E660Cu: goto label_1e660c;
            case 0x1E664Cu: goto label_1e664c;
            case 0x1E6664u: goto label_1e6664;
            case 0x1E6674u: goto label_1e6674;
            case 0x1E6698u: goto label_1e6698;
            case 0x1E66ACu: goto label_1e66ac;
            case 0x1E66D0u: goto label_1e66d0;
            case 0x1E66E4u: goto label_1e66e4;
            case 0x1E66FCu: goto label_1e66fc;
            case 0x1E6718u: goto label_1e6718;
            case 0x1E6744u: goto label_1e6744;
            case 0x1E6760u: goto label_1e6760;
            case 0x1E6764u: goto label_1e6764;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E677Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
