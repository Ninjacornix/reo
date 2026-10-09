#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00197BB0
// Address: 0x197bb0 - 0x1982d0
void sub_00197BB0_0x197bb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00197BB0_0x197bb0");
#endif

    switch (ctx->pc) {
        case 0x197be0u: goto label_197be0;
        case 0x197bf4u: goto label_197bf4;
        case 0x1982acu: goto label_1982ac;
        default: break;
    }

    ctx->pc = 0x197bb0u;

    // 0x197bb0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x197bb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x197bb4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x197bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x197bb8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x197bb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x197bbc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x197bbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x197bc0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x197bc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x197bc4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x197bc4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x197bc8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x197bc8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x197bcc: 0x12220006  beq         $s1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x197BCCu;
    {
        const bool branch_taken_0x197bcc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x197BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197BCCu;
            // 0x197bd0: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197bcc) {
            ctx->pc = 0x197BE8u;
            goto label_197be8;
        }
    }
    ctx->pc = 0x197BD4u;
    // 0x197bd4: 0x24040030  addiu       $a0, $zero, 0x30
    ctx->pc = 0x197bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x197bd8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x197BD8u;
    SET_GPR_U32(ctx, 31, 0x197BE0u);
    ctx->pc = 0x197BDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x197BD8u;
            // 0x197bdc: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197BE0u; }
        if (ctx->pc != 0x197BE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197BE0u; }
        if (ctx->pc != 0x197BE0u) { return; }
    }
    ctx->pc = 0x197BE0u;
label_197be0:
    // 0x197be0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x197BE0u;
    {
        const bool branch_taken_0x197be0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197BE0u;
            // 0x197be4: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197be0) {
            ctx->pc = 0x197BF8u;
            goto label_197bf8;
        }
    }
    ctx->pc = 0x197BE8u;
label_197be8:
    // 0x197be8: 0x24040040  addiu       $a0, $zero, 0x40
    ctx->pc = 0x197be8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x197bec: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x197BECu;
    SET_GPR_U32(ctx, 31, 0x197BF4u);
    ctx->pc = 0x197BF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x197BECu;
            // 0x197bf0: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197BF4u; }
        if (ctx->pc != 0x197BF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197BF4u; }
        if (ctx->pc != 0x197BF4u) { return; }
    }
    ctx->pc = 0x197BF4u;
label_197bf4:
    // 0x197bf4: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x197bf4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_197bf8:
    // 0x197bf8: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x197bf8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x197bfc: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x197bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x197c00: 0xe42021  addu        $a0, $a3, $a0
    ctx->pc = 0x197c00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x197c04: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x197c04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x197c08: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x197c08u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x197c0c: 0x4303c  dsll32      $a2, $a0, 0
    ctx->pc = 0x197c0cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197c10: 0x3c035000  lui         $v1, 0x5000
    ctx->pc = 0x197c10u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20480 << 16));
    // 0x197c14: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x197c14u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x197c18: 0xe32025  or          $a0, $a3, $v1
    ctx->pc = 0x197c18u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x197c1c: 0xfc460000  sd          $a2, 0x0($v0)
    ctx->pc = 0x197c1cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x197c20: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x197c20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x197c24: 0xac450008  sw          $a1, 0x8($v0)
    ctx->pc = 0x197c24u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 5));
    // 0x197c28: 0x3283c  dsll32      $a1, $v1, 0
    ctx->pc = 0x197c28u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197c2c: 0xac44000c  sw          $a0, 0xC($v0)
    ctx->pc = 0x197c2cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 4));
    // 0x197c30: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x197c30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x197c34: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x197c34u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x197c38: 0x3203c  dsll32      $a0, $v1, 0
    ctx->pc = 0x197c38u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197c3c: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x197c3cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x197c40: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x197c40u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x197c44: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x197c44u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x197c48: 0x2403000e  addiu       $v1, $zero, 0xE
    ctx->pc = 0x197c48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x197c4c: 0xfc440010  sd          $a0, 0x10($v0)
    ctx->pc = 0x197c4cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 4));
    // 0x197c50: 0x32450c00  andi        $a1, $s2, 0xC00
    ctx->pc = 0x197c50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)3072);
    // 0x197c54: 0x14a0009d  bnez        $a1, . + 4 + (0x9D << 2)
    ctx->pc = 0x197C54u;
    {
        const bool branch_taken_0x197c54 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x197C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197C54u;
            // 0x197c58: 0xfc430018  sd          $v1, 0x18($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197c54) {
            ctx->pc = 0x197ECCu;
            goto label_197ecc;
        }
    }
    ctx->pc = 0x197C5Cu;
    // 0x197c5c: 0x3243000f  andi        $v1, $s2, 0xF
    ctx->pc = 0x197c5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)15);
    // 0x197c60: 0x2c610006  sltiu       $at, $v1, 0x6
    ctx->pc = 0x197c60u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x197c64: 0x10200097  beqz        $at, . + 4 + (0x97 << 2)
    ctx->pc = 0x197C64u;
    {
        const bool branch_taken_0x197c64 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x197C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197C64u;
            // 0x197c68: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197c64) {
            ctx->pc = 0x197EC4u;
            goto label_197ec4;
        }
    }
    ctx->pc = 0x197C6Cu;
    // 0x197c6c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x197c6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x197c70: 0x24841d00  addiu       $a0, $a0, 0x1D00
    ctx->pc = 0x197c70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7424));
    // 0x197c74: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x197c74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x197c78: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x197c78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x197c7c: 0x600008  jr          $v1
    ctx->pc = 0x197C7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x197C84u: goto label_197c84;
            case 0x197D20u: goto label_197d20;
            case 0x197DBCu: goto label_197dbc;
            case 0x197E08u: goto label_197e08;
            case 0x197E40u: goto label_197e40;
            case 0x197E8Cu: goto label_197e8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197C84u;
label_197c84:
    // 0x197c84: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197c84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197c88: 0x24030050  addiu       $v1, $zero, 0x50
    ctx->pc = 0x197c88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x197c8c: 0x10830020  beq         $a0, $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x197C8Cu;
    {
        const bool branch_taken_0x197c8c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197C8Cu;
            // 0x197c90: 0x24100016  addiu       $s0, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197c8c) {
            ctx->pc = 0x197D10u;
            goto label_197d10;
        }
    }
    ctx->pc = 0x197C94u;
    // 0x197c94: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x197c94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x197c98: 0x1083001b  beq         $a0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x197C98u;
    {
        const bool branch_taken_0x197c98 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197C98u;
            // 0x197c9c: 0x24100019  addiu       $s0, $zero, 0x19 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197c98) {
            ctx->pc = 0x197D08u;
            goto label_197d08;
        }
    }
    ctx->pc = 0x197CA0u;
    // 0x197ca0: 0x24030030  addiu       $v1, $zero, 0x30
    ctx->pc = 0x197ca0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x197ca4: 0x10830016  beq         $a0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x197CA4u;
    {
        const bool branch_taken_0x197ca4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197CA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197CA4u;
            // 0x197ca8: 0x24100006  addiu       $s0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197ca4) {
            ctx->pc = 0x197D00u;
            goto label_197d00;
        }
    }
    ctx->pc = 0x197CACu;
    // 0x197cac: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x197cacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x197cb0: 0x10830011  beq         $a0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x197CB0u;
    {
        const bool branch_taken_0x197cb0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197CB0u;
            // 0x197cb4: 0x24100009  addiu       $s0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197cb0) {
            ctx->pc = 0x197CF8u;
            goto label_197cf8;
        }
    }
    ctx->pc = 0x197CB8u;
    // 0x197cb8: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x197CB8u;
    {
        const bool branch_taken_0x197cb8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197CB8u;
            // 0x197cbc: 0x24030010  addiu       $v1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197cb8) {
            ctx->pc = 0x197CE4u;
            goto label_197ce4;
        }
    }
    ctx->pc = 0x197CC0u;
    // 0x197cc0: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197CC0u;
    {
        const bool branch_taken_0x197cc0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197cc0) {
            ctx->pc = 0x197CD0u;
            goto label_197cd0;
        }
    }
    ctx->pc = 0x197CC8u;
    // 0x197cc8: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x197CC8u;
    {
        const bool branch_taken_0x197cc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197CC8u;
            // 0x197ccc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197cc8) {
            ctx->pc = 0x197D18u;
            goto label_197d18;
        }
    }
    ctx->pc = 0x197CD0u;
label_197cd0:
    // 0x197cd0: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x197cd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197cd4: 0x24030068  addiu       $v1, $zero, 0x68
    ctx->pc = 0x197cd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    // 0x197cd8: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x197cd8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197cdc: 0x1000014d  b           . + 4 + (0x14D << 2)
    ctx->pc = 0x197CDCu;
    {
        const bool branch_taken_0x197cdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197CDCu;
            // 0x197ce0: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197cdc) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197CE4u;
label_197ce4:
    // 0x197ce4: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x197ce4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197ce8: 0x240300a8  addiu       $v1, $zero, 0xA8
    ctx->pc = 0x197ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 168));
    // 0x197cec: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x197cecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197cf0: 0x10000148  b           . + 4 + (0x148 << 2)
    ctx->pc = 0x197CF0u;
    {
        const bool branch_taken_0x197cf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197CF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197CF0u;
            // 0x197cf4: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197cf0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197CF8u;
label_197cf8:
    // 0x197cf8: 0x10000147  b           . + 4 + (0x147 << 2)
    ctx->pc = 0x197CF8u;
    {
        const bool branch_taken_0x197cf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197CF8u;
            // 0x197cfc: 0x3c030100  lui         $v1, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197cf8) {
            ctx->pc = 0x198218u;
            goto label_198218;
        }
    }
    ctx->pc = 0x197D00u;
label_197d00:
    // 0x197d00: 0x10000144  b           . + 4 + (0x144 << 2)
    ctx->pc = 0x197D00u;
    {
        const bool branch_taken_0x197d00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197d00) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D08u;
label_197d08:
    // 0x197d08: 0x10000142  b           . + 4 + (0x142 << 2)
    ctx->pc = 0x197D08u;
    {
        const bool branch_taken_0x197d08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197d08) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D10u;
label_197d10:
    // 0x197d10: 0x10000140  b           . + 4 + (0x140 << 2)
    ctx->pc = 0x197D10u;
    {
        const bool branch_taken_0x197d10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197d10) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D18u;
label_197d18:
    // 0x197d18: 0x10000166  b           . + 4 + (0x166 << 2)
    ctx->pc = 0x197D18u;
    {
        const bool branch_taken_0x197d18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D18u;
            // 0x197d1c: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d18) {
            ctx->pc = 0x1982B4u;
            goto label_1982b4;
        }
    }
    ctx->pc = 0x197D20u;
label_197d20:
    // 0x197d20: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197d20u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197d24: 0x24030050  addiu       $v1, $zero, 0x50
    ctx->pc = 0x197d24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x197d28: 0x10830020  beq         $a0, $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x197D28u;
    {
        const bool branch_taken_0x197d28 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197D2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D28u;
            // 0x197d2c: 0x24100056  addiu       $s0, $zero, 0x56 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 86));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d28) {
            ctx->pc = 0x197DACu;
            goto label_197dac;
        }
    }
    ctx->pc = 0x197D30u;
    // 0x197d30: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x197d30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x197d34: 0x1083001b  beq         $a0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x197D34u;
    {
        const bool branch_taken_0x197d34 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D34u;
            // 0x197d38: 0x24100099  addiu       $s0, $zero, 0x99 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 153));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d34) {
            ctx->pc = 0x197DA4u;
            goto label_197da4;
        }
    }
    ctx->pc = 0x197D3Cu;
    // 0x197d3c: 0x24030030  addiu       $v1, $zero, 0x30
    ctx->pc = 0x197d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x197d40: 0x10830016  beq         $a0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x197D40u;
    {
        const bool branch_taken_0x197d40 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D40u;
            // 0x197d44: 0x24100046  addiu       $s0, $zero, 0x46 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d40) {
            ctx->pc = 0x197D9Cu;
            goto label_197d9c;
        }
    }
    ctx->pc = 0x197D48u;
    // 0x197d48: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x197d48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x197d4c: 0x10830011  beq         $a0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x197D4Cu;
    {
        const bool branch_taken_0x197d4c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D4Cu;
            // 0x197d50: 0x24100089  addiu       $s0, $zero, 0x89 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 137));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d4c) {
            ctx->pc = 0x197D94u;
            goto label_197d94;
        }
    }
    ctx->pc = 0x197D54u;
    // 0x197d54: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x197D54u;
    {
        const bool branch_taken_0x197d54 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D54u;
            // 0x197d58: 0x24030010  addiu       $v1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d54) {
            ctx->pc = 0x197D80u;
            goto label_197d80;
        }
    }
    ctx->pc = 0x197D5Cu;
    // 0x197d5c: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197D5Cu;
    {
        const bool branch_taken_0x197d5c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197d5c) {
            ctx->pc = 0x197D6Cu;
            goto label_197d6c;
        }
    }
    ctx->pc = 0x197D64u;
    // 0x197d64: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x197D64u;
    {
        const bool branch_taken_0x197d64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D64u;
            // 0x197d68: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d64) {
            ctx->pc = 0x197DB4u;
            goto label_197db4;
        }
    }
    ctx->pc = 0x197D6Cu;
label_197d6c:
    // 0x197d6c: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x197d6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197d70: 0x2403006a  addiu       $v1, $zero, 0x6A
    ctx->pc = 0x197d70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 106));
    // 0x197d74: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x197d74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197d78: 0x10000126  b           . + 4 + (0x126 << 2)
    ctx->pc = 0x197D78u;
    {
        const bool branch_taken_0x197d78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D78u;
            // 0x197d7c: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d78) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D80u;
label_197d80:
    // 0x197d80: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x197d80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197d84: 0x240300aa  addiu       $v1, $zero, 0xAA
    ctx->pc = 0x197d84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 170));
    // 0x197d88: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x197d88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197d8c: 0x10000121  b           . + 4 + (0x121 << 2)
    ctx->pc = 0x197D8Cu;
    {
        const bool branch_taken_0x197d8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197D90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197D8Cu;
            // 0x197d90: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197d8c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D94u;
label_197d94:
    // 0x197d94: 0x1000011f  b           . + 4 + (0x11F << 2)
    ctx->pc = 0x197D94u;
    {
        const bool branch_taken_0x197d94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197d94) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197D9Cu;
label_197d9c:
    // 0x197d9c: 0x1000011d  b           . + 4 + (0x11D << 2)
    ctx->pc = 0x197D9Cu;
    {
        const bool branch_taken_0x197d9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197d9c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DA4u;
label_197da4:
    // 0x197da4: 0x1000011b  b           . + 4 + (0x11B << 2)
    ctx->pc = 0x197DA4u;
    {
        const bool branch_taken_0x197da4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197da4) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DACu;
label_197dac:
    // 0x197dac: 0x10000119  b           . + 4 + (0x119 << 2)
    ctx->pc = 0x197DACu;
    {
        const bool branch_taken_0x197dac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197dac) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DB4u;
label_197db4:
    // 0x197db4: 0x1000013e  b           . + 4 + (0x13E << 2)
    ctx->pc = 0x197DB4u;
    {
        const bool branch_taken_0x197db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197db4) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197DBCu;
label_197dbc:
    // 0x197dbc: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197dbcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197dc0: 0x24030030  addiu       $v1, $zero, 0x30
    ctx->pc = 0x197dc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x197dc4: 0x1083000c  beq         $a0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x197DC4u;
    {
        const bool branch_taken_0x197dc4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197DC4u;
            // 0x197dc8: 0x24100044  addiu       $s0, $zero, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197dc4) {
            ctx->pc = 0x197DF8u;
            goto label_197df8;
        }
    }
    ctx->pc = 0x197DCCu;
    // 0x197dcc: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x197DCCu;
    {
        const bool branch_taken_0x197dcc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197DCCu;
            // 0x197dd0: 0x24100088  addiu       $s0, $zero, 0x88 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 136));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197dcc) {
            ctx->pc = 0x197DF0u;
            goto label_197df0;
        }
    }
    ctx->pc = 0x197DD4u;
    // 0x197dd4: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x197dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x197dd8: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197DD8u;
    {
        const bool branch_taken_0x197dd8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197DD8u;
            // 0x197ddc: 0x24100048  addiu       $s0, $zero, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197dd8) {
            ctx->pc = 0x197DE8u;
            goto label_197de8;
        }
    }
    ctx->pc = 0x197DE0u;
    // 0x197de0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x197DE0u;
    {
        const bool branch_taken_0x197de0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197DE0u;
            // 0x197de4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197de0) {
            ctx->pc = 0x197E00u;
            goto label_197e00;
        }
    }
    ctx->pc = 0x197DE8u;
label_197de8:
    // 0x197de8: 0x1000010a  b           . + 4 + (0x10A << 2)
    ctx->pc = 0x197DE8u;
    {
        const bool branch_taken_0x197de8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197de8) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DF0u;
label_197df0:
    // 0x197df0: 0x10000108  b           . + 4 + (0x108 << 2)
    ctx->pc = 0x197DF0u;
    {
        const bool branch_taken_0x197df0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197df0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197DF8u;
label_197df8:
    // 0x197df8: 0x10000106  b           . + 4 + (0x106 << 2)
    ctx->pc = 0x197DF8u;
    {
        const bool branch_taken_0x197df8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197df8) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E00u;
label_197e00:
    // 0x197e00: 0x1000012b  b           . + 4 + (0x12B << 2)
    ctx->pc = 0x197E00u;
    {
        const bool branch_taken_0x197e00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197e00) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197E08u;
label_197e08:
    // 0x197e08: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197e08u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197e0c: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x197e0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x197e10: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x197E10u;
    {
        const bool branch_taken_0x197e10 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E10u;
            // 0x197e14: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e10) {
            ctx->pc = 0x197E30u;
            goto label_197e30;
        }
    }
    ctx->pc = 0x197E18u;
    // 0x197e18: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x197E18u;
    {
        const bool branch_taken_0x197e18 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E18u;
            // 0x197e1c: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e18) {
            ctx->pc = 0x197E28u;
            goto label_197e28;
        }
    }
    ctx->pc = 0x197E20u;
    // 0x197e20: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x197E20u;
    {
        const bool branch_taken_0x197e20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E20u;
            // 0x197e24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e20) {
            ctx->pc = 0x197E38u;
            goto label_197e38;
        }
    }
    ctx->pc = 0x197E28u;
label_197e28:
    // 0x197e28: 0x100000fa  b           . + 4 + (0xFA << 2)
    ctx->pc = 0x197E28u;
    {
        const bool branch_taken_0x197e28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197e28) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E30u;
label_197e30:
    // 0x197e30: 0x100000f8  b           . + 4 + (0xF8 << 2)
    ctx->pc = 0x197E30u;
    {
        const bool branch_taken_0x197e30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197e30) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E38u;
label_197e38:
    // 0x197e38: 0x1000011d  b           . + 4 + (0x11D << 2)
    ctx->pc = 0x197E38u;
    {
        const bool branch_taken_0x197e38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197e38) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197E40u;
label_197e40:
    // 0x197e40: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197e40u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197e44: 0x24030050  addiu       $v1, $zero, 0x50
    ctx->pc = 0x197e44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x197e48: 0x1083000c  beq         $a0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x197E48u;
    {
        const bool branch_taken_0x197e48 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E48u;
            // 0x197e4c: 0x24100054  addiu       $s0, $zero, 0x54 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 84));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e48) {
            ctx->pc = 0x197E7Cu;
            goto label_197e7c;
        }
    }
    ctx->pc = 0x197E50u;
    // 0x197e50: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x197E50u;
    {
        const bool branch_taken_0x197e50 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E50u;
            // 0x197e54: 0x24100098  addiu       $s0, $zero, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 152));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e50) {
            ctx->pc = 0x197E74u;
            goto label_197e74;
        }
    }
    ctx->pc = 0x197E58u;
    // 0x197e58: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x197e58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x197e5c: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197E5Cu;
    {
        const bool branch_taken_0x197e5c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E5Cu;
            // 0x197e60: 0x24100058  addiu       $s0, $zero, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e5c) {
            ctx->pc = 0x197E6Cu;
            goto label_197e6c;
        }
    }
    ctx->pc = 0x197E64u;
    // 0x197e64: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x197E64u;
    {
        const bool branch_taken_0x197e64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E64u;
            // 0x197e68: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e64) {
            ctx->pc = 0x197E84u;
            goto label_197e84;
        }
    }
    ctx->pc = 0x197E6Cu;
label_197e6c:
    // 0x197e6c: 0x100000e9  b           . + 4 + (0xE9 << 2)
    ctx->pc = 0x197E6Cu;
    {
        const bool branch_taken_0x197e6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197e6c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E74u;
label_197e74:
    // 0x197e74: 0x100000e7  b           . + 4 + (0xE7 << 2)
    ctx->pc = 0x197E74u;
    {
        const bool branch_taken_0x197e74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197e74) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E7Cu;
label_197e7c:
    // 0x197e7c: 0x100000e5  b           . + 4 + (0xE5 << 2)
    ctx->pc = 0x197E7Cu;
    {
        const bool branch_taken_0x197e7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197e7c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197E84u;
label_197e84:
    // 0x197e84: 0x1000010a  b           . + 4 + (0x10A << 2)
    ctx->pc = 0x197E84u;
    {
        const bool branch_taken_0x197e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197e84) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197E8Cu;
label_197e8c:
    // 0x197e8c: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197e8cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197e90: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x197e90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x197e94: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x197E94u;
    {
        const bool branch_taken_0x197e94 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E94u;
            // 0x197e98: 0x24100011  addiu       $s0, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e94) {
            ctx->pc = 0x197EB4u;
            goto label_197eb4;
        }
    }
    ctx->pc = 0x197E9Cu;
    // 0x197e9c: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x197E9Cu;
    {
        const bool branch_taken_0x197e9c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197E9Cu;
            // 0x197ea0: 0x24100012  addiu       $s0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197e9c) {
            ctx->pc = 0x197EACu;
            goto label_197eac;
        }
    }
    ctx->pc = 0x197EA4u;
    // 0x197ea4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x197EA4u;
    {
        const bool branch_taken_0x197ea4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197EA4u;
            // 0x197ea8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197ea4) {
            ctx->pc = 0x197EBCu;
            goto label_197ebc;
        }
    }
    ctx->pc = 0x197EACu;
label_197eac:
    // 0x197eac: 0x100000d9  b           . + 4 + (0xD9 << 2)
    ctx->pc = 0x197EACu;
    {
        const bool branch_taken_0x197eac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197eac) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197EB4u;
label_197eb4:
    // 0x197eb4: 0x100000d7  b           . + 4 + (0xD7 << 2)
    ctx->pc = 0x197EB4u;
    {
        const bool branch_taken_0x197eb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197eb4) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197EBCu;
label_197ebc:
    // 0x197ebc: 0x100000fc  b           . + 4 + (0xFC << 2)
    ctx->pc = 0x197EBCu;
    {
        const bool branch_taken_0x197ebc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197ebc) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197EC4u;
label_197ec4:
    // 0x197ec4: 0x100000fa  b           . + 4 + (0xFA << 2)
    ctx->pc = 0x197EC4u;
    {
        const bool branch_taken_0x197ec4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197EC4u;
            // 0x197ec8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197ec4) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197ECCu;
label_197ecc:
    // 0x197ecc: 0x24030400  addiu       $v1, $zero, 0x400
    ctx->pc = 0x197eccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x197ed0: 0x14a3006b  bne         $a1, $v1, . + 4 + (0x6B << 2)
    ctx->pc = 0x197ED0u;
    {
        const bool branch_taken_0x197ed0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x197ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197ED0u;
            // 0x197ed4: 0x24030800  addiu       $v1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197ed0) {
            ctx->pc = 0x198080u;
            goto label_198080;
        }
    }
    ctx->pc = 0x197ED8u;
    // 0x197ed8: 0x3243000f  andi        $v1, $s2, 0xF
    ctx->pc = 0x197ed8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)15);
    // 0x197edc: 0x2c610006  sltiu       $at, $v1, 0x6
    ctx->pc = 0x197edcu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x197ee0: 0x10200065  beqz        $at, . + 4 + (0x65 << 2)
    ctx->pc = 0x197EE0u;
    {
        const bool branch_taken_0x197ee0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x197EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197EE0u;
            // 0x197ee4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197ee0) {
            ctx->pc = 0x198078u;
            goto label_198078;
        }
    }
    ctx->pc = 0x197EE8u;
    // 0x197ee8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x197ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x197eec: 0x24841ce0  addiu       $a0, $a0, 0x1CE0
    ctx->pc = 0x197eecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7392));
    // 0x197ef0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x197ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x197ef4: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x197ef4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x197ef8: 0x600008  jr          $v1
    ctx->pc = 0x197EF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x197F00u: goto label_197f00;
            case 0x197F4Cu: goto label_197f4c;
            case 0x197FC0u: goto label_197fc0;
            case 0x197FF8u: goto label_197ff8;
            case 0x19801Cu: goto label_19801c;
            case 0x198054u: goto label_198054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197F00u;
label_197f00:
    // 0x197f00: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197f00u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197f04: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x197F04u;
    {
        const bool branch_taken_0x197f04 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197F08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F04u;
            // 0x197f08: 0x24030010  addiu       $v1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f04) {
            ctx->pc = 0x197F30u;
            goto label_197f30;
        }
    }
    ctx->pc = 0x197F0Cu;
    // 0x197f0c: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197F0Cu;
    {
        const bool branch_taken_0x197f0c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197f0c) {
            ctx->pc = 0x197F1Cu;
            goto label_197f1c;
        }
    }
    ctx->pc = 0x197F14u;
    // 0x197f14: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x197F14u;
    {
        const bool branch_taken_0x197f14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F14u;
            // 0x197f18: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f14) {
            ctx->pc = 0x197F44u;
            goto label_197f44;
        }
    }
    ctx->pc = 0x197F1Cu;
label_197f1c:
    // 0x197f1c: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x197f1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197f20: 0x240300a4  addiu       $v1, $zero, 0xA4
    ctx->pc = 0x197f20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 164));
    // 0x197f24: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x197f24u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197f28: 0x100000ba  b           . + 4 + (0xBA << 2)
    ctx->pc = 0x197F28u;
    {
        const bool branch_taken_0x197f28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F28u;
            // 0x197f2c: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f28) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197F30u;
label_197f30:
    // 0x197f30: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x197f30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197f34: 0x2403002a  addiu       $v1, $zero, 0x2A
    ctx->pc = 0x197f34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x197f38: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x197f38u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197f3c: 0x100000b5  b           . + 4 + (0xB5 << 2)
    ctx->pc = 0x197F3Cu;
    {
        const bool branch_taken_0x197f3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F3Cu;
            // 0x197f40: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f3c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197F44u;
label_197f44:
    // 0x197f44: 0x100000da  b           . + 4 + (0xDA << 2)
    ctx->pc = 0x197F44u;
    {
        const bool branch_taken_0x197f44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197f44) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197F4Cu;
label_197f4c:
    // 0x197f4c: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197f4cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197f50: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x197f50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x197f54: 0x10830016  beq         $a0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x197F54u;
    {
        const bool branch_taken_0x197f54 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F54u;
            // 0x197f58: 0x24100096  addiu       $s0, $zero, 0x96 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 150));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f54) {
            ctx->pc = 0x197FB0u;
            goto label_197fb0;
        }
    }
    ctx->pc = 0x197F5Cu;
    // 0x197f5c: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x197f5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x197f60: 0x10830011  beq         $a0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x197F60u;
    {
        const bool branch_taken_0x197f60 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F60u;
            // 0x197f64: 0x24100086  addiu       $s0, $zero, 0x86 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 134));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f60) {
            ctx->pc = 0x197FA8u;
            goto label_197fa8;
        }
    }
    ctx->pc = 0x197F68u;
    // 0x197f68: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x197F68u;
    {
        const bool branch_taken_0x197f68 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F68u;
            // 0x197f6c: 0x24030010  addiu       $v1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f68) {
            ctx->pc = 0x197F94u;
            goto label_197f94;
        }
    }
    ctx->pc = 0x197F70u;
    // 0x197f70: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197F70u;
    {
        const bool branch_taken_0x197f70 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197f70) {
            ctx->pc = 0x197F80u;
            goto label_197f80;
        }
    }
    ctx->pc = 0x197F78u;
    // 0x197f78: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x197F78u;
    {
        const bool branch_taken_0x197f78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F78u;
            // 0x197f7c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f78) {
            ctx->pc = 0x197FB8u;
            goto label_197fb8;
        }
    }
    ctx->pc = 0x197F80u;
label_197f80:
    // 0x197f80: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x197f80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197f84: 0x240300a6  addiu       $v1, $zero, 0xA6
    ctx->pc = 0x197f84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 166));
    // 0x197f88: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x197f88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197f8c: 0x100000a1  b           . + 4 + (0xA1 << 2)
    ctx->pc = 0x197F8Cu;
    {
        const bool branch_taken_0x197f8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197F8Cu;
            // 0x197f90: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197f8c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197F94u;
label_197f94:
    // 0x197f94: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x197f94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197f98: 0x240300aa  addiu       $v1, $zero, 0xAA
    ctx->pc = 0x197f98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 170));
    // 0x197f9c: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x197f9cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197fa0: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x197FA0u;
    {
        const bool branch_taken_0x197fa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197FA0u;
            // 0x197fa4: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197fa0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FA8u;
label_197fa8:
    // 0x197fa8: 0x1000009a  b           . + 4 + (0x9A << 2)
    ctx->pc = 0x197FA8u;
    {
        const bool branch_taken_0x197fa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197fa8) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FB0u;
label_197fb0:
    // 0x197fb0: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x197FB0u;
    {
        const bool branch_taken_0x197fb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197fb0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FB8u;
label_197fb8:
    // 0x197fb8: 0x100000bd  b           . + 4 + (0xBD << 2)
    ctx->pc = 0x197FB8u;
    {
        const bool branch_taken_0x197fb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197fb8) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197FC0u;
label_197fc0:
    // 0x197fc0: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x197fc0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197fc4: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x197fc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x197fc8: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x197FC8u;
    {
        const bool branch_taken_0x197fc8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x197FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197FC8u;
            // 0x197fcc: 0x24100084  addiu       $s0, $zero, 0x84 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 132));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197fc8) {
            ctx->pc = 0x197FE8u;
            goto label_197fe8;
        }
    }
    ctx->pc = 0x197FD0u;
    // 0x197fd0: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x197FD0u;
    {
        const bool branch_taken_0x197fd0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x197FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197FD0u;
            // 0x197fd4: 0x24100088  addiu       $s0, $zero, 0x88 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 136));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197fd0) {
            ctx->pc = 0x197FE0u;
            goto label_197fe0;
        }
    }
    ctx->pc = 0x197FD8u;
    // 0x197fd8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x197FD8u;
    {
        const bool branch_taken_0x197fd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197FD8u;
            // 0x197fdc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197fd8) {
            ctx->pc = 0x197FF0u;
            goto label_197ff0;
        }
    }
    ctx->pc = 0x197FE0u;
label_197fe0:
    // 0x197fe0: 0x1000008c  b           . + 4 + (0x8C << 2)
    ctx->pc = 0x197FE0u;
    {
        const bool branch_taken_0x197fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197fe0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FE8u;
label_197fe8:
    // 0x197fe8: 0x1000008a  b           . + 4 + (0x8A << 2)
    ctx->pc = 0x197FE8u;
    {
        const bool branch_taken_0x197fe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197fe8) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x197FF0u;
label_197ff0:
    // 0x197ff0: 0x100000af  b           . + 4 + (0xAF << 2)
    ctx->pc = 0x197FF0u;
    {
        const bool branch_taken_0x197ff0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197ff0) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x197FF8u;
label_197ff8:
    // 0x197ff8: 0x324300f0  andi        $v1, $s2, 0xF0
    ctx->pc = 0x197ff8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x197ffc: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197FFCu;
    {
        const bool branch_taken_0x197ffc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x198000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197FFCu;
            // 0x198000: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197ffc) {
            ctx->pc = 0x19800Cu;
            goto label_19800c;
        }
    }
    ctx->pc = 0x198004u;
    // 0x198004: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x198004u;
    {
        const bool branch_taken_0x198004 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198004u;
            // 0x198008: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198004) {
            ctx->pc = 0x198014u;
            goto label_198014;
        }
    }
    ctx->pc = 0x19800Cu;
label_19800c:
    // 0x19800c: 0x10000081  b           . + 4 + (0x81 << 2)
    ctx->pc = 0x19800Cu;
    {
        const bool branch_taken_0x19800c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19800c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198014u;
label_198014:
    // 0x198014: 0x100000a6  b           . + 4 + (0xA6 << 2)
    ctx->pc = 0x198014u;
    {
        const bool branch_taken_0x198014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198014) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x19801Cu;
label_19801c:
    // 0x19801c: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x19801cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x198020: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x198020u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x198024: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x198024u;
    {
        const bool branch_taken_0x198024 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x198028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198024u;
            // 0x198028: 0x24100094  addiu       $s0, $zero, 0x94 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 148));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198024) {
            ctx->pc = 0x198044u;
            goto label_198044;
        }
    }
    ctx->pc = 0x19802Cu;
    // 0x19802c: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19802Cu;
    {
        const bool branch_taken_0x19802c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x198030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19802Cu;
            // 0x198030: 0x24100098  addiu       $s0, $zero, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 152));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19802c) {
            ctx->pc = 0x19803Cu;
            goto label_19803c;
        }
    }
    ctx->pc = 0x198034u;
    // 0x198034: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x198034u;
    {
        const bool branch_taken_0x198034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198034u;
            // 0x198038: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198034) {
            ctx->pc = 0x19804Cu;
            goto label_19804c;
        }
    }
    ctx->pc = 0x19803Cu;
label_19803c:
    // 0x19803c: 0x10000075  b           . + 4 + (0x75 << 2)
    ctx->pc = 0x19803Cu;
    {
        const bool branch_taken_0x19803c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19803c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198044u;
label_198044:
    // 0x198044: 0x10000073  b           . + 4 + (0x73 << 2)
    ctx->pc = 0x198044u;
    {
        const bool branch_taken_0x198044 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198044) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x19804Cu;
label_19804c:
    // 0x19804c: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x19804Cu;
    {
        const bool branch_taken_0x19804c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19804c) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198054u;
label_198054:
    // 0x198054: 0x324300f0  andi        $v1, $s2, 0xF0
    ctx->pc = 0x198054u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x198058: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198058u;
    {
        const bool branch_taken_0x198058 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x19805Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198058u;
            // 0x19805c: 0x24100056  addiu       $s0, $zero, 0x56 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 86));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198058) {
            ctx->pc = 0x198068u;
            goto label_198068;
        }
    }
    ctx->pc = 0x198060u;
    // 0x198060: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x198060u;
    {
        const bool branch_taken_0x198060 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198060u;
            // 0x198064: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198060) {
            ctx->pc = 0x198070u;
            goto label_198070;
        }
    }
    ctx->pc = 0x198068u;
label_198068:
    // 0x198068: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x198068u;
    {
        const bool branch_taken_0x198068 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198068) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198070u;
label_198070:
    // 0x198070: 0x1000008f  b           . + 4 + (0x8F << 2)
    ctx->pc = 0x198070u;
    {
        const bool branch_taken_0x198070 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198070) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198078u;
label_198078:
    // 0x198078: 0x1000008d  b           . + 4 + (0x8D << 2)
    ctx->pc = 0x198078u;
    {
        const bool branch_taken_0x198078 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19807Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198078u;
            // 0x19807c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198078) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198080u;
label_198080:
    // 0x198080: 0x14a30064  bne         $a1, $v1, . + 4 + (0x64 << 2)
    ctx->pc = 0x198080u;
    {
        const bool branch_taken_0x198080 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x198084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198080u;
            // 0x198084: 0x3244000f  andi        $a0, $s2, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x198080) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198088u;
    // 0x198088: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x198088u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19808c: 0x10830051  beq         $a0, $v1, . + 4 + (0x51 << 2)
    ctx->pc = 0x19808Cu;
    {
        const bool branch_taken_0x19808c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x198090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19808Cu;
            // 0x198090: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19808c) {
            ctx->pc = 0x1981D4u;
            goto label_1981d4;
        }
    }
    ctx->pc = 0x198094u;
    // 0x198094: 0x10830041  beq         $a0, $v1, . + 4 + (0x41 << 2)
    ctx->pc = 0x198094u;
    {
        const bool branch_taken_0x198094 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x198094) {
            ctx->pc = 0x19819Cu;
            goto label_19819c;
        }
    }
    ctx->pc = 0x19809Cu;
    // 0x19809c: 0x10800018  beqz        $a0, . + 4 + (0x18 << 2)
    ctx->pc = 0x19809Cu;
    {
        const bool branch_taken_0x19809c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1980A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19809Cu;
            // 0x1980a0: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19809c) {
            ctx->pc = 0x198100u;
            goto label_198100;
        }
    }
    ctx->pc = 0x1980A4u;
    // 0x1980a4: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1980A4u;
    {
        const bool branch_taken_0x1980a4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1980a4) {
            ctx->pc = 0x1980B4u;
            goto label_1980b4;
        }
    }
    ctx->pc = 0x1980ACu;
    // 0x1980ac: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1980ACu;
    {
        const bool branch_taken_0x1980ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1980B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1980ACu;
            // 0x1980b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1980ac) {
            ctx->pc = 0x19820Cu;
            goto label_19820c;
        }
    }
    ctx->pc = 0x1980B4u;
label_1980b4:
    // 0x1980b4: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x1980b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x1980b8: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1980B8u;
    {
        const bool branch_taken_0x1980b8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1980BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1980B8u;
            // 0x1980bc: 0x24030010  addiu       $v1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1980b8) {
            ctx->pc = 0x1980E4u;
            goto label_1980e4;
        }
    }
    ctx->pc = 0x1980C0u;
    // 0x1980c0: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1980C0u;
    {
        const bool branch_taken_0x1980c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1980c0) {
            ctx->pc = 0x1980D0u;
            goto label_1980d0;
        }
    }
    ctx->pc = 0x1980C8u;
    // 0x1980c8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1980C8u;
    {
        const bool branch_taken_0x1980c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1980CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1980C8u;
            // 0x1980cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1980c8) {
            ctx->pc = 0x1980F8u;
            goto label_1980f8;
        }
    }
    ctx->pc = 0x1980D0u;
label_1980d0:
    // 0x1980d0: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x1980d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1980d4: 0x240300a1  addiu       $v1, $zero, 0xA1
    ctx->pc = 0x1980d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 161));
    // 0x1980d8: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1980d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1980dc: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1980DCu;
    {
        const bool branch_taken_0x1980dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1980E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1980DCu;
            // 0x1980e0: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1980dc) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1980E4u;
label_1980e4:
    // 0x1980e4: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x1980e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1980e8: 0x240300a2  addiu       $v1, $zero, 0xA2
    ctx->pc = 0x1980e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 162));
    // 0x1980ec: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1980ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1980f0: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1980F0u;
    {
        const bool branch_taken_0x1980f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1980F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1980F0u;
            // 0x1980f4: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1980f0) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1980F8u;
label_1980f8:
    // 0x1980f8: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x1980F8u;
    {
        const bool branch_taken_0x1980f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1980f8) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198100u;
label_198100:
    // 0x198100: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x198100u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x198104: 0x24030050  addiu       $v1, $zero, 0x50
    ctx->pc = 0x198104u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x198108: 0x10830020  beq         $a0, $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x198108u;
    {
        const bool branch_taken_0x198108 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x19810Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198108u;
            // 0x19810c: 0x24100056  addiu       $s0, $zero, 0x56 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 86));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198108) {
            ctx->pc = 0x19818Cu;
            goto label_19818c;
        }
    }
    ctx->pc = 0x198110u;
    // 0x198110: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x198110u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x198114: 0x1083001b  beq         $a0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x198114u;
    {
        const bool branch_taken_0x198114 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x198118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198114u;
            // 0x198118: 0x24100099  addiu       $s0, $zero, 0x99 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 153));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198114) {
            ctx->pc = 0x198184u;
            goto label_198184;
        }
    }
    ctx->pc = 0x19811Cu;
    // 0x19811c: 0x24030030  addiu       $v1, $zero, 0x30
    ctx->pc = 0x19811cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x198120: 0x10830016  beq         $a0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x198120u;
    {
        const bool branch_taken_0x198120 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x198124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198120u;
            // 0x198124: 0x24100046  addiu       $s0, $zero, 0x46 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198120) {
            ctx->pc = 0x19817Cu;
            goto label_19817c;
        }
    }
    ctx->pc = 0x198128u;
    // 0x198128: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x198128u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x19812c: 0x10830011  beq         $a0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x19812Cu;
    {
        const bool branch_taken_0x19812c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x198130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19812Cu;
            // 0x198130: 0x24100089  addiu       $s0, $zero, 0x89 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 137));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19812c) {
            ctx->pc = 0x198174u;
            goto label_198174;
        }
    }
    ctx->pc = 0x198134u;
    // 0x198134: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x198134u;
    {
        const bool branch_taken_0x198134 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x198138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198134u;
            // 0x198138: 0x24030010  addiu       $v1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198134) {
            ctx->pc = 0x198160u;
            goto label_198160;
        }
    }
    ctx->pc = 0x19813Cu;
    // 0x19813c: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19813Cu;
    {
        const bool branch_taken_0x19813c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x19813c) {
            ctx->pc = 0x19814Cu;
            goto label_19814c;
        }
    }
    ctx->pc = 0x198144u;
    // 0x198144: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x198144u;
    {
        const bool branch_taken_0x198144 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198144u;
            // 0x198148: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198144) {
            ctx->pc = 0x198194u;
            goto label_198194;
        }
    }
    ctx->pc = 0x19814Cu;
label_19814c:
    // 0x19814c: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x19814cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x198150: 0x240300a9  addiu       $v1, $zero, 0xA9
    ctx->pc = 0x198150u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 169));
    // 0x198154: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x198154u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x198158: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x198158u;
    {
        const bool branch_taken_0x198158 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19815Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198158u;
            // 0x19815c: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198158) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198160u;
label_198160:
    // 0x198160: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x198160u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x198164: 0x240300aa  addiu       $v1, $zero, 0xAA
    ctx->pc = 0x198164u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 170));
    // 0x198168: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x198168u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x19816c: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x19816Cu;
    {
        const bool branch_taken_0x19816c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19816Cu;
            // 0x198170: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19816c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198174u;
label_198174:
    // 0x198174: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x198174u;
    {
        const bool branch_taken_0x198174 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198174) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x19817Cu;
label_19817c:
    // 0x19817c: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x19817Cu;
    {
        const bool branch_taken_0x19817c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19817c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198184u;
label_198184:
    // 0x198184: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x198184u;
    {
        const bool branch_taken_0x198184 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198184) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x19818Cu;
label_19818c:
    // 0x19818c: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x19818Cu;
    {
        const bool branch_taken_0x19818c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19818c) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198194u;
label_198194:
    // 0x198194: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x198194u;
    {
        const bool branch_taken_0x198194 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198194) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x19819Cu;
label_19819c:
    // 0x19819c: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x19819cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x1981a0: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x1981a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1981a4: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1981A4u;
    {
        const bool branch_taken_0x1981a4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1981A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1981A4u;
            // 0x1981a8: 0x24100081  addiu       $s0, $zero, 0x81 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 129));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1981a4) {
            ctx->pc = 0x1981C4u;
            goto label_1981c4;
        }
    }
    ctx->pc = 0x1981ACu;
    // 0x1981ac: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1981ACu;
    {
        const bool branch_taken_0x1981ac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1981B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1981ACu;
            // 0x1981b0: 0x24100082  addiu       $s0, $zero, 0x82 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 130));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1981ac) {
            ctx->pc = 0x1981BCu;
            goto label_1981bc;
        }
    }
    ctx->pc = 0x1981B4u;
    // 0x1981b4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1981B4u;
    {
        const bool branch_taken_0x1981b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1981B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1981B4u;
            // 0x1981b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1981b4) {
            ctx->pc = 0x1981CCu;
            goto label_1981cc;
        }
    }
    ctx->pc = 0x1981BCu;
label_1981bc:
    // 0x1981bc: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1981BCu;
    {
        const bool branch_taken_0x1981bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1981bc) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1981C4u;
label_1981c4:
    // 0x1981c4: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1981C4u;
    {
        const bool branch_taken_0x1981c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1981c4) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1981CCu;
label_1981cc:
    // 0x1981cc: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1981CCu;
    {
        const bool branch_taken_0x1981cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1981cc) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x1981D4u;
label_1981d4:
    // 0x1981d4: 0x324400f0  andi        $a0, $s2, 0xF0
    ctx->pc = 0x1981d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)240);
    // 0x1981d8: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x1981d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1981dc: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1981DCu;
    {
        const bool branch_taken_0x1981dc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1981E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1981DCu;
            // 0x1981e0: 0x24100091  addiu       $s0, $zero, 0x91 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 145));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1981dc) {
            ctx->pc = 0x1981FCu;
            goto label_1981fc;
        }
    }
    ctx->pc = 0x1981E4u;
    // 0x1981e4: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1981E4u;
    {
        const bool branch_taken_0x1981e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1981E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1981E4u;
            // 0x1981e8: 0x24100092  addiu       $s0, $zero, 0x92 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 146));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1981e4) {
            ctx->pc = 0x1981F4u;
            goto label_1981f4;
        }
    }
    ctx->pc = 0x1981ECu;
    // 0x1981ec: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1981ECu;
    {
        const bool branch_taken_0x1981ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1981F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1981ECu;
            // 0x1981f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1981ec) {
            ctx->pc = 0x198204u;
            goto label_198204;
        }
    }
    ctx->pc = 0x1981F4u;
label_1981f4:
    // 0x1981f4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1981F4u;
    {
        const bool branch_taken_0x1981f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1981f4) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x1981FCu;
label_1981fc:
    // 0x1981fc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1981FCu;
    {
        const bool branch_taken_0x1981fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1981fc) {
            ctx->pc = 0x198214u;
            goto label_198214;
        }
    }
    ctx->pc = 0x198204u;
label_198204:
    // 0x198204: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x198204u;
    {
        const bool branch_taken_0x198204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x198204) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x19820Cu;
label_19820c:
    // 0x19820c: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x19820Cu;
    {
        const bool branch_taken_0x19820c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19820c) {
            ctx->pc = 0x1982B0u;
            goto label_1982b0;
        }
    }
    ctx->pc = 0x198214u;
label_198214:
    // 0x198214: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x198214u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
label_198218:
    // 0x198218: 0x2431824  and         $v1, $s2, $v1
    ctx->pc = 0x198218u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & GPR_U64(ctx, 3));
    // 0x19821c: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x19821Cu;
    {
        const bool branch_taken_0x19821c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x198220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19821Cu;
            // 0x198220: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19821c) {
            ctx->pc = 0x198238u;
            goto label_198238;
        }
    }
    ctx->pc = 0x198224u;
    // 0x198224: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x198224u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x198228: 0x240300a8  addiu       $v1, $zero, 0xA8
    ctx->pc = 0x198228u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 168));
    // 0x19822c: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x19822cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x198230: 0x648025  or          $s0, $v1, $a0
    ctx->pc = 0x198230u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x198234: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x198234u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_198238:
    // 0x198238: 0x1223000f  beq         $s1, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x198238u;
    {
        const bool branch_taken_0x198238 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x19823Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198238u;
            // 0x19823c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198238) {
            ctx->pc = 0x198278u;
            goto label_198278;
        }
    }
    ctx->pc = 0x198240u;
    // 0x198240: 0x12230009  beq         $s1, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x198240u;
    {
        const bool branch_taken_0x198240 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        if (branch_taken_0x198240) {
            ctx->pc = 0x198268u;
            goto label_198268;
        }
    }
    ctx->pc = 0x198248u;
    // 0x198248: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x198248u;
    {
        const bool branch_taken_0x198248 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x198248) {
            ctx->pc = 0x198258u;
            goto label_198258;
        }
    }
    ctx->pc = 0x198250u;
    // 0x198250: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x198250u;
    {
        const bool branch_taken_0x198250 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198250u;
            // 0x198254: 0x2293c  dsll32      $a1, $v0, 4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198250) {
            ctx->pc = 0x198294u;
            goto label_198294;
        }
    }
    ctx->pc = 0x198258u;
label_198258:
    // 0x198258: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x198258u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x19825c: 0x24030042  addiu       $v1, $zero, 0x42
    ctx->pc = 0x19825cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
    // 0x198260: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x198260u;
    {
        const bool branch_taken_0x198260 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198260u;
            // 0x198264: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198260) {
            ctx->pc = 0x198290u;
            goto label_198290;
        }
    }
    ctx->pc = 0x198268u;
label_198268:
    // 0x198268: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x198268u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x19826c: 0x24030043  addiu       $v1, $zero, 0x43
    ctx->pc = 0x19826cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x198270: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x198270u;
    {
        const bool branch_taken_0x198270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x198274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198270u;
            // 0x198274: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198270) {
            ctx->pc = 0x198290u;
            goto label_198290;
        }
    }
    ctx->pc = 0x198278u;
label_198278:
    // 0x198278: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x198278u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x19827c: 0x24030042  addiu       $v1, $zero, 0x42
    ctx->pc = 0x19827cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
    // 0x198280: 0xfc430028  sd          $v1, 0x28($v0)
    ctx->pc = 0x198280u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
    // 0x198284: 0x24030043  addiu       $v1, $zero, 0x43
    ctx->pc = 0x198284u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x198288: 0xfc500030  sd          $s0, 0x30($v0)
    ctx->pc = 0x198288u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 48), GPR_U64(ctx, 16));
    // 0x19828c: 0xfc430038  sd          $v1, 0x38($v0)
    ctx->pc = 0x19828cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 56), GPR_U64(ctx, 3));
label_198290:
    // 0x198290: 0x2293c  dsll32      $a1, $v0, 4
    ctx->pc = 0x198290u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
label_198294:
    // 0x198294: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x198294u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x198298: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x198298u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x19829c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x19829cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1982a0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1982a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1982a4: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x1982A4u;
    SET_GPR_U32(ctx, 31, 0x1982ACu);
    ctx->pc = 0x1982A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1982A4u;
            // 0x1982a8: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1982ACu; }
        if (ctx->pc != 0x1982ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1982ACu; }
        if (ctx->pc != 0x1982ACu) { return; }
    }
    ctx->pc = 0x1982ACu;
label_1982ac:
    // 0x1982ac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1982acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1982b0:
    // 0x1982b0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1982b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1982b4:
    // 0x1982b4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1982b4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1982b8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1982b8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1982bc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1982bcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1982c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1982C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1982C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1982C0u;
            // 0x1982c4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x197BE0u: goto label_197be0;
            case 0x197BE8u: goto label_197be8;
            case 0x197BF4u: goto label_197bf4;
            case 0x197BF8u: goto label_197bf8;
            case 0x197C84u: goto label_197c84;
            case 0x197CD0u: goto label_197cd0;
            case 0x197CE4u: goto label_197ce4;
            case 0x197CF8u: goto label_197cf8;
            case 0x197D00u: goto label_197d00;
            case 0x197D08u: goto label_197d08;
            case 0x197D10u: goto label_197d10;
            case 0x197D18u: goto label_197d18;
            case 0x197D20u: goto label_197d20;
            case 0x197D6Cu: goto label_197d6c;
            case 0x197D80u: goto label_197d80;
            case 0x197D94u: goto label_197d94;
            case 0x197D9Cu: goto label_197d9c;
            case 0x197DA4u: goto label_197da4;
            case 0x197DACu: goto label_197dac;
            case 0x197DB4u: goto label_197db4;
            case 0x197DBCu: goto label_197dbc;
            case 0x197DE8u: goto label_197de8;
            case 0x197DF0u: goto label_197df0;
            case 0x197DF8u: goto label_197df8;
            case 0x197E00u: goto label_197e00;
            case 0x197E08u: goto label_197e08;
            case 0x197E28u: goto label_197e28;
            case 0x197E30u: goto label_197e30;
            case 0x197E38u: goto label_197e38;
            case 0x197E40u: goto label_197e40;
            case 0x197E6Cu: goto label_197e6c;
            case 0x197E74u: goto label_197e74;
            case 0x197E7Cu: goto label_197e7c;
            case 0x197E84u: goto label_197e84;
            case 0x197E8Cu: goto label_197e8c;
            case 0x197EACu: goto label_197eac;
            case 0x197EB4u: goto label_197eb4;
            case 0x197EBCu: goto label_197ebc;
            case 0x197EC4u: goto label_197ec4;
            case 0x197ECCu: goto label_197ecc;
            case 0x197F00u: goto label_197f00;
            case 0x197F1Cu: goto label_197f1c;
            case 0x197F30u: goto label_197f30;
            case 0x197F44u: goto label_197f44;
            case 0x197F4Cu: goto label_197f4c;
            case 0x197F80u: goto label_197f80;
            case 0x197F94u: goto label_197f94;
            case 0x197FA8u: goto label_197fa8;
            case 0x197FB0u: goto label_197fb0;
            case 0x197FB8u: goto label_197fb8;
            case 0x197FC0u: goto label_197fc0;
            case 0x197FE0u: goto label_197fe0;
            case 0x197FE8u: goto label_197fe8;
            case 0x197FF0u: goto label_197ff0;
            case 0x197FF8u: goto label_197ff8;
            case 0x19800Cu: goto label_19800c;
            case 0x198014u: goto label_198014;
            case 0x19801Cu: goto label_19801c;
            case 0x19803Cu: goto label_19803c;
            case 0x198044u: goto label_198044;
            case 0x19804Cu: goto label_19804c;
            case 0x198054u: goto label_198054;
            case 0x198068u: goto label_198068;
            case 0x198070u: goto label_198070;
            case 0x198078u: goto label_198078;
            case 0x198080u: goto label_198080;
            case 0x1980B4u: goto label_1980b4;
            case 0x1980D0u: goto label_1980d0;
            case 0x1980E4u: goto label_1980e4;
            case 0x1980F8u: goto label_1980f8;
            case 0x198100u: goto label_198100;
            case 0x19814Cu: goto label_19814c;
            case 0x198160u: goto label_198160;
            case 0x198174u: goto label_198174;
            case 0x19817Cu: goto label_19817c;
            case 0x198184u: goto label_198184;
            case 0x19818Cu: goto label_19818c;
            case 0x198194u: goto label_198194;
            case 0x19819Cu: goto label_19819c;
            case 0x1981BCu: goto label_1981bc;
            case 0x1981C4u: goto label_1981c4;
            case 0x1981CCu: goto label_1981cc;
            case 0x1981D4u: goto label_1981d4;
            case 0x1981F4u: goto label_1981f4;
            case 0x1981FCu: goto label_1981fc;
            case 0x198204u: goto label_198204;
            case 0x19820Cu: goto label_19820c;
            case 0x198214u: goto label_198214;
            case 0x198218u: goto label_198218;
            case 0x198238u: goto label_198238;
            case 0x198258u: goto label_198258;
            case 0x198268u: goto label_198268;
            case 0x198278u: goto label_198278;
            case 0x198290u: goto label_198290;
            case 0x198294u: goto label_198294;
            case 0x1982ACu: goto label_1982ac;
            case 0x1982B0u: goto label_1982b0;
            case 0x1982B4u: goto label_1982b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1982C8u;
    // 0x1982c8: 0x0  nop
    ctx->pc = 0x1982c8u;
    // NOP
    // 0x1982cc: 0x0  nop
    ctx->pc = 0x1982ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
