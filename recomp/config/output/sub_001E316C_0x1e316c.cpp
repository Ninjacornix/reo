#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E316C
// Address: 0x1e316c - 0x1e3428
void sub_001E316C_0x1e316c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E316C_0x1e316c");
#endif

    switch (ctx->pc) {
        case 0x1e3238u: goto label_1e3238;
        case 0x1e3278u: goto label_1e3278;
        case 0x1e329cu: goto label_1e329c;
        case 0x1e3318u: goto label_1e3318;
        case 0x1e33c4u: goto label_1e33c4;
        case 0x1e33f4u: goto label_1e33f4;
        default: break;
    }

    ctx->pc = 0x1e316cu;

    // 0x1e316c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e316cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e3170: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e3170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e3174: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e3174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e3178: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e3178u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e317c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e317cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e3180: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e3180u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e3184: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e3184u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e3188: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e3188u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e318c: 0x100102d  daddu       $v0, $t0, $zero
    ctx->pc = 0x1e318cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3190: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1e3190u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1e3194: 0xa7c20010  sh          $v0, 0x10($fp)
    ctx->pc = 0x1e3194u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 16), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e3198: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e3198u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e319c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e319cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e31a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e31a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e31a4: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E31A4u;
    {
        const bool branch_taken_0x1e31a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e31a4) {
            ctx->pc = 0x1E31CCu;
            goto label_1e31cc;
        }
    }
    ctx->pc = 0x1E31ACu;
    // 0x1e31ac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e31acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e31b0: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e31b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e31b4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e31b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e31b8: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e31b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e31bc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e31bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e31c0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e31c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e31c4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E31C4u;
    {
        const bool branch_taken_0x1e31c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e31c4) {
            ctx->pc = 0x1E31E0u;
            goto label_1e31e0;
        }
    }
    ctx->pc = 0x1E31CCu;
label_1e31cc:
    // 0x1e31cc: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e31ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e31d0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e31d0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e31d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e31d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e31d8: 0x1000008d  b           . + 4 + (0x8D << 2)
    ctx->pc = 0x1E31D8u;
    {
        const bool branch_taken_0x1e31d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e31d8) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E31E0u;
label_1e31e0:
    // 0x1e31e0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e31e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e31e4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e31e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e31e8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e31e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e31ec: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e31ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e31f0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e31f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e31f4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e31f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e31f8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e31f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e31fc: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e31fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e3200: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e3200u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e3204: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3204u;
    {
        const bool branch_taken_0x1e3204 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3204) {
            ctx->pc = 0x1E3220u;
            goto label_1e3220;
        }
    }
    ctx->pc = 0x1E320Cu;
    // 0x1e320c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e320cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e3210: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e3210u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3214: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3218: 0x1000007d  b           . + 4 + (0x7D << 2)
    ctx->pc = 0x1E3218u;
    {
        const bool branch_taken_0x1e3218 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3218) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E3220u;
label_1e3220:
    // 0x1e3220: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e3220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3224: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e3224u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e3228: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e3228u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e322c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e322cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3230: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E3230u;
    SET_GPR_U32(ctx, 31, 0x1E3238u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3238u; }
        if (ctx->pc != 0x1E3238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3238u; }
        if (ctx->pc != 0x1E3238u) { return; }
    }
    ctx->pc = 0x1E3238u;
label_1e3238:
    // 0x1e3238: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e3238u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e323c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e323cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3240: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3240u;
    {
        const bool branch_taken_0x1e3240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3240) {
            ctx->pc = 0x1E325Cu;
            goto label_1e325c;
        }
    }
    ctx->pc = 0x1E3248u;
    // 0x1e3248: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e3248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e324c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e324cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e3250: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e3250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e3254: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x1E3254u;
    {
        const bool branch_taken_0x1e3254 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e3254) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E325Cu;
label_1e325c:
    // 0x1e325c: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e325cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3260: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e3260u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e3264: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1e3264u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e3268: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e3268u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e326c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e326cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3270: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E3270u;
    SET_GPR_U32(ctx, 31, 0x1E3278u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3278u; }
        if (ctx->pc != 0x1E3278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3278u; }
        if (ctx->pc != 0x1E3278u) { return; }
    }
    ctx->pc = 0x1E3278u;
label_1e3278:
    // 0x1e3278: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e3278u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e327c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e327cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3280: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E3280u;
    {
        const bool branch_taken_0x1e3280 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3280) {
            ctx->pc = 0x1E32B0u;
            goto label_1e32b0;
        }
    }
    ctx->pc = 0x1E3288u;
    // 0x1e3288: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e3288u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e328c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e328cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e3290: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e3290u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e3294: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E3294u;
    SET_GPR_U32(ctx, 31, 0x1E329Cu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E329Cu; }
        if (ctx->pc != 0x1E329Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E329Cu; }
        if (ctx->pc != 0x1E329Cu) { return; }
    }
    ctx->pc = 0x1E329Cu;
label_1e329c:
    // 0x1e329c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e329cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e32a0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e32a0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e32a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e32a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e32a8: 0x10000059  b           . + 4 + (0x59 << 2)
    ctx->pc = 0x1E32A8u;
    {
        const bool branch_taken_0x1e32a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e32a8) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E32B0u;
label_1e32b0:
    // 0x1e32b0: 0x8fc50020  lw          $a1, 0x20($fp)
    ctx->pc = 0x1e32b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e32b4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e32b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e32b8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e32b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e32bc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e32bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e32c0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e32c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e32c4: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e32c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e32c8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e32c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e32cc: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e32ccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e32d0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e32d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e32d4: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e32d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e32d8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e32d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e32dc: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e32dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e32e0: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e32e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e32e4: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e32e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e32e8: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e32e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e32ec: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e32ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e32f0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e32f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e32f4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e32f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e32f8: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e32f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e32fc: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e32fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3300: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e3300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e3304: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e3304u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3308: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e3308u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e330c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e330cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3310: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E3310u;
    SET_GPR_U32(ctx, 31, 0x1E3318u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3318u; }
        if (ctx->pc != 0x1E3318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E3318u; }
        if (ctx->pc != 0x1E3318u) { return; }
    }
    ctx->pc = 0x1E3318u;
label_1e3318:
    // 0x1e3318: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e3318u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e331c: 0x3c024e41  lui         $v0, 0x4E41
    ctx->pc = 0x1e331cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20033 << 16));
    // 0x1e3320: 0x34424d45  ori         $v0, $v0, 0x4D45
    ctx->pc = 0x1e3320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19781);
    // 0x1e3324: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1E3324u;
    {
        const bool branch_taken_0x1e3324 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e3324) {
            ctx->pc = 0x1E3388u;
            goto label_1e3388;
        }
    }
    ctx->pc = 0x1E332Cu;
    // 0x1e332c: 0x8fc50020  lw          $a1, 0x20($fp)
    ctx->pc = 0x1e332cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3330: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e3330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3334: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e3334u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e3338: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e3338u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e333c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e333cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e3340: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e3340u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3344: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1e3344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e3348: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e3348u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e334c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e334cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e3350: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e3350u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e3354: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e3354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3358: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1e3358u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e335c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e335cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e3360: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3360u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e3364: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e3364u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e3368: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e3368u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e336c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e336cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e3370: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1e3370u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e3374: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e3374u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e3378: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e3378u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e337c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e337cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e3380: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e3380u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e3384: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1e3384u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
label_1e3388:
    // 0x1e3388: 0x97c20010  lhu         $v0, 0x10($fp)
    ctx->pc = 0x1e3388u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e338c: 0x3442a000  ori         $v0, $v0, 0xA000
    ctx->pc = 0x1e338cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40960);
    // 0x1e3390: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1e3390u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e3394: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e3394u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e3398: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e3398u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e339c: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1e339cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1e33a0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e33a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e33a4: 0x9042061c  lbu         $v0, 0x61C($v0)
    ctx->pc = 0x1e33a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1564)));
    // 0x1e33a8: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e33a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e33ac: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e33acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e33b0: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x1e33b0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e33b4: 0x24080008  addiu       $t0, $zero, 0x8
    ctx->pc = 0x1e33b4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1e33b8: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e33b8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e33bc: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E33BCu;
    SET_GPR_U32(ctx, 31, 0x1E33C4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E33C4u; }
        if (ctx->pc != 0x1E33C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E33C4u; }
        if (ctx->pc != 0x1E33C4u) { return; }
    }
    ctx->pc = 0x1E33C4u;
label_1e33c4:
    // 0x1e33c4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E33C4u;
    {
        const bool branch_taken_0x1e33c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e33c4) {
            ctx->pc = 0x1E33E0u;
            goto label_1e33e0;
        }
    }
    ctx->pc = 0x1E33CCu;
    // 0x1e33cc: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e33ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e33d0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e33d0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e33d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e33d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e33d8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E33D8u;
    {
        const bool branch_taken_0x1e33d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e33d8) {
            ctx->pc = 0x1E3410u;
            goto label_1e3410;
        }
    }
    ctx->pc = 0x1E33E0u;
label_1e33e0:
    // 0x1e33e0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e33e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e33e4: 0x24050025  addiu       $a1, $zero, 0x25
    ctx->pc = 0x1e33e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x1e33e8: 0x8fc60014  lw          $a2, 0x14($fp)
    ctx->pc = 0x1e33e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e33ec: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E33ECu;
    SET_GPR_U32(ctx, 31, 0x1E33F4u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E33F4u; }
        if (ctx->pc != 0x1E33F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E33F4u; }
        if (ctx->pc != 0x1E33F4u) { return; }
    }
    ctx->pc = 0x1E33F4u;
label_1e33f4:
    // 0x1e33f4: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1e33f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e33f8: 0x9064061c  lbu         $a0, 0x61C($v1)
    ctx->pc = 0x1e33f8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1564)));
    // 0x1e33fc: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e33fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e3400: 0xa062061c  sb          $v0, 0x61C($v1)
    ctx->pc = 0x1e3400u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1564), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e3404: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e3404u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e3408: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e3408u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e340c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e340cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
label_1e3410:
    // 0x1e3410: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e3410u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e3414: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e3414u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e3418: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e3418u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e341c: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e341cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e3420: 0x3e00008  jr          $ra
    ctx->pc = 0x1E3420u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E31CCu: goto label_1e31cc;
            case 0x1E31E0u: goto label_1e31e0;
            case 0x1E3220u: goto label_1e3220;
            case 0x1E3238u: goto label_1e3238;
            case 0x1E325Cu: goto label_1e325c;
            case 0x1E3278u: goto label_1e3278;
            case 0x1E329Cu: goto label_1e329c;
            case 0x1E32B0u: goto label_1e32b0;
            case 0x1E3318u: goto label_1e3318;
            case 0x1E3388u: goto label_1e3388;
            case 0x1E33C4u: goto label_1e33c4;
            case 0x1E33E0u: goto label_1e33e0;
            case 0x1E33F4u: goto label_1e33f4;
            case 0x1E3410u: goto label_1e3410;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E3428u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
