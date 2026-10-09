#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E1EE8
// Address: 0x1e1ee8 - 0x1e2140
void sub_001E1EE8_0x1e1ee8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E1EE8_0x1e1ee8");
#endif

    switch (ctx->pc) {
        case 0x1e1facu: goto label_1e1fac;
        case 0x1e1fe0u: goto label_1e1fe0;
        case 0x1e2004u: goto label_1e2004;
        case 0x1e202cu: goto label_1e202c;
        case 0x1e2064u: goto label_1e2064;
        case 0x1e2088u: goto label_1e2088;
        case 0x1e20a0u: goto label_1e20a0;
        case 0x1e20d4u: goto label_1e20d4;
        case 0x1e210cu: goto label_1e210c;
        default: break;
    }

    ctx->pc = 0x1e1ee8u;

    // 0x1e1ee8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1e1ee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1e1eec: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1e1eecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1e1ef0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1e1ef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1e1ef4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e1ef4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1ef8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e1ef8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e1efc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e1efcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e1f00: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e1f00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e1f04: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1e1f04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e1f08: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e1f08u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e1f0c: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1e1f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1e1f10: 0xa7c2000c  sh          $v0, 0xC($fp)
    ctx->pc = 0x1e1f10u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e1f14: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e1f14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0x1e1f18: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e1f18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1f1c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e1f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e1f20: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E1F20u;
    {
        const bool branch_taken_0x1e1f20 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e1f20) {
            ctx->pc = 0x1E1F48u;
            goto label_1e1f48;
        }
    }
    ctx->pc = 0x1E1F28u;
    // 0x1e1f28: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1f2c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1f2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1f30: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1f30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1f34: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1f34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1f38: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1f3c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1f40: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1F40u;
    {
        const bool branch_taken_0x1e1f40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1f40) {
            ctx->pc = 0x1E1F5Cu;
            goto label_1e1f5c;
        }
    }
    ctx->pc = 0x1E1F48u;
label_1e1f48:
    // 0x1e1f48: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e1f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e1f4c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1f50: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1f54: 0x10000074  b           . + 4 + (0x74 << 2)
    ctx->pc = 0x1E1F54u;
    {
        const bool branch_taken_0x1e1f54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1f54) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E1F5Cu;
label_1e1f5c:
    // 0x1e1f5c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e1f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e1f60: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e1f60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e1f64: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e1f64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e1f68: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e1f68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e1f6c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e1f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e1f70: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e1f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e1f74: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e1f74u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1e1f78: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e1f78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1f7c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e1f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e1f80: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1F80u;
    {
        const bool branch_taken_0x1e1f80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1f80) {
            ctx->pc = 0x1E1F9Cu;
            goto label_1e1f9c;
        }
    }
    ctx->pc = 0x1E1F88u;
    // 0x1e1f88: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e1f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e1f8c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1f90: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1f90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1f94: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x1E1F94u;
    {
        const bool branch_taken_0x1e1f94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1f94) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E1F9Cu;
label_1e1f9c:
    // 0x1e1f9c: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e1f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1fa0: 0x24050028  addiu       $a1, $zero, 0x28
    ctx->pc = 0x1e1fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e1fa4: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E1FA4u;
    SET_GPR_U32(ctx, 31, 0x1E1FACu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1FACu; }
        if (ctx->pc != 0x1E1FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1FACu; }
        if (ctx->pc != 0x1E1FACu) { return; }
    }
    ctx->pc = 0x1E1FACu;
label_1e1fac:
    // 0x1e1fac: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e1facu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e1fb0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e1fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1fb4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E1FB4u;
    {
        const bool branch_taken_0x1e1fb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1fb4) {
            ctx->pc = 0x1E1FD0u;
            goto label_1e1fd0;
        }
    }
    ctx->pc = 0x1E1FBCu;
    // 0x1e1fbc: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e1fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e1fc0: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e1fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e1fc4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e1fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e1fc8: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1E1FC8u;
    {
        const bool branch_taken_0x1e1fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e1fc8) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E1FD0u;
label_1e1fd0:
    // 0x1e1fd0: 0x8fc4001c  lw          $a0, 0x1C($fp)
    ctx->pc = 0x1e1fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1fd4: 0x24050028  addiu       $a1, $zero, 0x28
    ctx->pc = 0x1e1fd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e1fd8: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E1FD8u;
    SET_GPR_U32(ctx, 31, 0x1E1FE0u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1FE0u; }
        if (ctx->pc != 0x1E1FE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E1FE0u; }
        if (ctx->pc != 0x1E1FE0u) { return; }
    }
    ctx->pc = 0x1E1FE0u;
label_1e1fe0:
    // 0x1e1fe0: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e1fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e1fe4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e1fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e1fe8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E1FE8u;
    {
        const bool branch_taken_0x1e1fe8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e1fe8) {
            ctx->pc = 0x1E2018u;
            goto label_1e2018;
        }
    }
    ctx->pc = 0x1E1FF0u;
    // 0x1e1ff0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e1ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e1ff4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e1ff4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e1ff8: 0x8fc5001c  lw          $a1, 0x1C($fp)
    ctx->pc = 0x1e1ff8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e1ffc: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E1FFCu;
    SET_GPR_U32(ctx, 31, 0x1E2004u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2004u; }
        if (ctx->pc != 0x1E2004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2004u; }
        if (ctx->pc != 0x1E2004u) { return; }
    }
    ctx->pc = 0x1E2004u;
label_1e2004:
    // 0x1e2004: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e2004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e2008: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e2008u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e200c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e200cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e2010: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x1E2010u;
    {
        const bool branch_taken_0x1e2010 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2010) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E2018u;
label_1e2018:
    // 0x1e2018: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e2018u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e201c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e201cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e2020: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e2020u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e2024: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E2024u;
    SET_GPR_U32(ctx, 31, 0x1E202Cu);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E202Cu; }
        if (ctx->pc != 0x1E202Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E202Cu; }
        if (ctx->pc != 0x1E202Cu) { return; }
    }
    ctx->pc = 0x1E202Cu;
label_1e202c:
    // 0x1e202c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e202cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2030: 0xa040000f  sb          $zero, 0xF($v0)
    ctx->pc = 0x1e2030u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 15), (uint8_t)GPR_U32(ctx, 0));
    // 0x1e2034: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2034u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2038: 0xa0400010  sb          $zero, 0x10($v0)
    ctx->pc = 0x1e2038u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 16), (uint8_t)GPR_U32(ctx, 0));
    // 0x1e203c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e203cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2040: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1E2040u;
    {
        const bool branch_taken_0x1e2040 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e2040) {
            ctx->pc = 0x1E206Cu;
            goto label_1e206c;
        }
    }
    ctx->pc = 0x1E2048u;
    // 0x1e2048: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2048u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e204c: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1e204cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1e2050: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e2050u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e2054: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e2054u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e2058: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e2058u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e205c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E205Cu;
    SET_GPR_U32(ctx, 31, 0x1E2064u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2064u; }
        if (ctx->pc != 0x1E2064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2064u; }
        if (ctx->pc != 0x1E2064u) { return; }
    }
    ctx->pc = 0x1E2064u;
label_1e2064:
    // 0x1e2064: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2068: 0xa040001f  sb          $zero, 0x1F($v0)
    ctx->pc = 0x1e2068u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 31), (uint8_t)GPR_U32(ctx, 0));
label_1e206c:
    // 0x1e206c: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e206cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2070: 0x97c2000c  lhu         $v0, 0xC($fp)
    ctx->pc = 0x1e2070u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e2074: 0xac620020  sw          $v0, 0x20($v1)
    ctx->pc = 0x1e2074u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32), GPR_U32(ctx, 2));
    // 0x1e2078: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e2078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e207c: 0x8c440020  lw          $a0, 0x20($v0)
    ctx->pc = 0x1e207cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x1e2080: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E2080u;
    SET_GPR_U32(ctx, 31, 0x1E2088u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2088u; }
        if (ctx->pc != 0x1E2088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E2088u; }
        if (ctx->pc != 0x1E2088u) { return; }
    }
    ctx->pc = 0x1E2088u;
label_1e2088:
    // 0x1e2088: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e2088u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e208c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e208cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e2090: 0xac430020  sw          $v1, 0x20($v0)
    ctx->pc = 0x1e2090u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 3));
    // 0x1e2094: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e2094u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e2098: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1E2098u;
    SET_GPR_U32(ctx, 31, 0x1E20A0u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E20A0u; }
        if (ctx->pc != 0x1E20A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E20A0u; }
        if (ctx->pc != 0x1E20A0u) { return; }
    }
    ctx->pc = 0x1E20A0u;
label_1e20a0:
    // 0x1e20a0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e20a0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e20a4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e20a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e20a8: 0xac430024  sw          $v1, 0x24($v0)
    ctx->pc = 0x1e20a8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 36), GPR_U32(ctx, 3));
    // 0x1e20ac: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e20acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e20b0: 0x90420614  lbu         $v0, 0x614($v0)
    ctx->pc = 0x1e20b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1556)));
    // 0x1e20b4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1e20b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e20b8: 0x8fc5001c  lw          $a1, 0x1C($fp)
    ctx->pc = 0x1e20b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e20bc: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e20bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e20c0: 0x24070028  addiu       $a3, $zero, 0x28
    ctx->pc = 0x1e20c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1e20c4: 0x24080046  addiu       $t0, $zero, 0x46
    ctx->pc = 0x1e20c4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1e20c8: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1e20c8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e20cc: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E20CCu;
    SET_GPR_U32(ctx, 31, 0x1E20D4u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E20D4u; }
        if (ctx->pc != 0x1E20D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E20D4u; }
        if (ctx->pc != 0x1E20D4u) { return; }
    }
    ctx->pc = 0x1E20D4u;
label_1e20d4:
    // 0x1e20d4: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1e20d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1e20d8: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1e20d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e20dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E20DCu;
    {
        const bool branch_taken_0x1e20dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e20dc) {
            ctx->pc = 0x1E20F8u;
            goto label_1e20f8;
        }
    }
    ctx->pc = 0x1E20E4u;
    // 0x1e20e4: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e20e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e20e8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e20e8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e20ec: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e20ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e20f0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E20F0u;
    {
        const bool branch_taken_0x1e20f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e20f0) {
            ctx->pc = 0x1E2128u;
            goto label_1e2128;
        }
    }
    ctx->pc = 0x1E20F8u;
label_1e20f8:
    // 0x1e20f8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e20f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e20fc: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x1e20fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1e2100: 0x8fc60014  lw          $a2, 0x14($fp)
    ctx->pc = 0x1e2100u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2104: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E2104u;
    SET_GPR_U32(ctx, 31, 0x1E210Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E210Cu; }
        if (ctx->pc != 0x1E210Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E210Cu; }
        if (ctx->pc != 0x1E210Cu) { return; }
    }
    ctx->pc = 0x1E210Cu;
label_1e210c:
    // 0x1e210c: 0x8fc30020  lw          $v1, 0x20($fp)
    ctx->pc = 0x1e210cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e2110: 0x90640614  lbu         $a0, 0x614($v1)
    ctx->pc = 0x1e2110u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1556)));
    // 0x1e2114: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x1e2114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e2118: 0xa0620614  sb          $v0, 0x614($v1)
    ctx->pc = 0x1e2118u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1556), (uint8_t)GPR_U32(ctx, 2));
    // 0x1e211c: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x1e211cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1e2120: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e2120u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e2124: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e2124u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
label_1e2128:
    // 0x1e2128: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e2128u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e212c: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1e212cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1e2130: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1e2130u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1e2134: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1e2134u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1e2138: 0x3e00008  jr          $ra
    ctx->pc = 0x1E2138u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E1F48u: goto label_1e1f48;
            case 0x1E1F5Cu: goto label_1e1f5c;
            case 0x1E1F9Cu: goto label_1e1f9c;
            case 0x1E1FACu: goto label_1e1fac;
            case 0x1E1FD0u: goto label_1e1fd0;
            case 0x1E1FE0u: goto label_1e1fe0;
            case 0x1E2004u: goto label_1e2004;
            case 0x1E2018u: goto label_1e2018;
            case 0x1E202Cu: goto label_1e202c;
            case 0x1E2064u: goto label_1e2064;
            case 0x1E206Cu: goto label_1e206c;
            case 0x1E2088u: goto label_1e2088;
            case 0x1E20A0u: goto label_1e20a0;
            case 0x1E20D4u: goto label_1e20d4;
            case 0x1E20F8u: goto label_1e20f8;
            case 0x1E210Cu: goto label_1e210c;
            case 0x1E2128u: goto label_1e2128;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E2140u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
