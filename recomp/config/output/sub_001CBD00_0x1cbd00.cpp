#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBD00
// Address: 0x1cbd00 - 0x1cbde0
void sub_001CBD00_0x1cbd00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBD00_0x1cbd00");
#endif

    switch (ctx->pc) {
        case 0x1cbd48u: goto label_1cbd48;
        case 0x1cbd74u: goto label_1cbd74;
        case 0x1cbd98u: goto label_1cbd98;
        case 0x1cbdc4u: goto label_1cbdc4;
        default: break;
    }

    ctx->pc = 0x1cbd00u;

    // 0x1cbd00: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1cbd00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1cbd04: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbd04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbd08: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1cbd08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1cbd0c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cbd0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cbd10: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cbd10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cbd14: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1cbd14u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cbd18: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cbd18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cbd1c: 0x8c22d9f8  lw          $v0, -0x2608($at)
    ctx->pc = 0x1cbd1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957560)));
    // 0x1cbd20: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CBD20u;
    {
        const bool branch_taken_0x1cbd20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CBD24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBD20u;
            // 0x1cbd24: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbd20) {
            ctx->pc = 0x1CBD38u;
            goto label_1cbd38;
        }
    }
    ctx->pc = 0x1CBD28u;
    // 0x1cbd28: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbd28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbd2c: 0x8c22da00  lw          $v0, -0x2600($at)
    ctx->pc = 0x1cbd2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbd30: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBD30u;
    {
        const bool branch_taken_0x1cbd30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbd30) {
            ctx->pc = 0x1CBD40u;
            goto label_1cbd40;
        }
    }
    ctx->pc = 0x1CBD38u;
label_1cbd38:
    // 0x1cbd38: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1CBD38u;
    {
        const bool branch_taken_0x1cbd38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBD3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBD38u;
            // 0x1cbd3c: 0x2402fff0  addiu       $v0, $zero, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbd38) {
            ctx->pc = 0x1CBDC8u;
            goto label_1cbdc8;
        }
    }
    ctx->pc = 0x1CBD40u;
label_1cbd40:
    // 0x1cbd40: 0xc072f78  jal         func_1CBDE0
    ctx->pc = 0x1CBD40u;
    SET_GPR_U32(ctx, 31, 0x1CBD48u);
    ctx->pc = 0x1CBDE0u;
    if (runtime->hasFunction(0x1CBDE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBD48u; }
        if (ctx->pc != 0x1CBD48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDE0_0x1cbde0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBD48u; }
        if (ctx->pc != 0x1CBD48u) { return; }
    }
    ctx->pc = 0x1CBD48u;
label_1cbd48:
    // 0x1cbd48: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbd48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbd4c: 0x8c30d9f0  lw          $s0, -0x2610($at)
    ctx->pc = 0x1cbd4cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957552)));
    // 0x1cbd50: 0x211082a  slt         $at, $s0, $s1
    ctx->pc = 0x1cbd50u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1cbd54: 0x221800a  movz        $s0, $s1, $at
    ctx->pc = 0x1cbd54u;
    if (GPR_U64(ctx, 1) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 17));
    // 0x1cbd58: 0x1a000006  blez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CBD58u;
    {
        const bool branch_taken_0x1cbd58 = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x1cbd58) {
            ctx->pc = 0x1CBD74u;
            goto label_1cbd74;
        }
    }
    ctx->pc = 0x1CBD60u;
    // 0x1cbd60: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1cbd60u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1cbd64: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1cbd64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cbd68: 0x24a5fa20  addiu       $a1, $a1, -0x5E0
    ctx->pc = 0x1cbd68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294965792));
    // 0x1cbd6c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1CBD6Cu;
    SET_GPR_U32(ctx, 31, 0x1CBD74u);
    ctx->pc = 0x1CBD70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBD6Cu;
            // 0x1cbd70: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBD74u; }
        if (ctx->pc != 0x1CBD74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBD74u; }
        if (ctx->pc != 0x1CBD74u) { return; }
    }
    ctx->pc = 0x1CBD74u;
label_1cbd74:
    // 0x1cbd74: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbd74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbd78: 0x8c22d9f0  lw          $v0, -0x2610($at)
    ctx->pc = 0x1cbd78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957552)));
    // 0x1cbd7c: 0x503023  subu        $a2, $v0, $s0
    ctx->pc = 0x1cbd7cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1cbd80: 0x10c00005  beqz        $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CBD80u;
    {
        const bool branch_taken_0x1cbd80 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbd80) {
            ctx->pc = 0x1CBD98u;
            goto label_1cbd98;
        }
    }
    ctx->pc = 0x1CBD88u;
    // 0x1cbd88: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cbd88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cbd8c: 0x2484fa20  addiu       $a0, $a0, -0x5E0
    ctx->pc = 0x1cbd8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965792));
    // 0x1cbd90: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x1CBD90u;
    SET_GPR_U32(ctx, 31, 0x1CBD98u);
    ctx->pc = 0x1CBD94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBD90u;
            // 0x1cbd94: 0x902821  addu        $a1, $a0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBD98u; }
        if (ctx->pc != 0x1CBD98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBD98u; }
        if (ctx->pc != 0x1CBD98u) { return; }
    }
    ctx->pc = 0x1CBD98u;
label_1cbd98:
    // 0x1cbd98: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbd98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbd9c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cbd9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cbda0: 0x8c23d9f0  lw          $v1, -0x2610($at)
    ctx->pc = 0x1cbda0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957552)));
    // 0x1cbda4: 0x2442fa20  addiu       $v0, $v0, -0x5E0
    ctx->pc = 0x1cbda4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965792));
    // 0x1cbda8: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1cbda8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1cbdac: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbdacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbdb0: 0xac23d9f0  sw          $v1, -0x2610($at)
    ctx->pc = 0x1cbdb0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957552), GPR_U32(ctx, 3));
    // 0x1cbdb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cbdb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cbdb8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbdb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbdbc: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CBDBCu;
    SET_GPR_U32(ctx, 31, 0x1CBDC4u);
    ctx->pc = 0x1CBDC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBDBCu;
            // 0x1cbdc0: 0xac225ff0  sw          $v0, 0x5FF0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 24560), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBDF0u;
    if (runtime->hasFunction(0x1CBDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBDC4u; }
        if (ctx->pc != 0x1CBDC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDF0_0x1cbdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBDC4u; }
        if (ctx->pc != 0x1CBDC4u) { return; }
    }
    ctx->pc = 0x1CBDC4u;
label_1cbdc4:
    // 0x1cbdc4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1cbdc4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1cbdc8:
    // 0x1cbdc8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1cbdc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cbdcc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cbdccu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cbdd0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cbdd0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cbdd4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbdd4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbdd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBDD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBDDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBDD8u;
            // 0x1cbddc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBD38u: goto label_1cbd38;
            case 0x1CBD40u: goto label_1cbd40;
            case 0x1CBD48u: goto label_1cbd48;
            case 0x1CBD74u: goto label_1cbd74;
            case 0x1CBD98u: goto label_1cbd98;
            case 0x1CBDC4u: goto label_1cbdc4;
            case 0x1CBDC8u: goto label_1cbdc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBDE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
