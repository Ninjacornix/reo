#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136C40
// Address: 0x136c40 - 0x136d48
void sub_00136C40_0x136c40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136C40_0x136c40");
#endif

    switch (ctx->pc) {
        case 0x136c74u: goto label_136c74;
        case 0x136c94u: goto label_136c94;
        case 0x136cb4u: goto label_136cb4;
        case 0x136cc8u: goto label_136cc8;
        case 0x136ce0u: goto label_136ce0;
        case 0x136cf4u: goto label_136cf4;
        case 0x136d1cu: goto label_136d1c;
        default: break;
    }

    ctx->pc = 0x136c40u;

    // 0x136c40: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x136c40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x136c44: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x136c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136c48: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x136c48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c4c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x136c4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x136c50: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x136c50u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c54: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x136c54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x136c58: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x136c58u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136c5c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x136c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x136c60: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136C60u;
    {
        const bool branch_taken_0x136c60 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C60u;
            // 0x136c64: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136c60) {
            ctx->pc = 0x136C80u;
            goto label_136c80;
        }
    }
    ctx->pc = 0x136C68u;
    // 0x136c68: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136c68u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136c6c: 0xc04d480  jal         func_135200
    ctx->pc = 0x136C6Cu;
    SET_GPR_U32(ctx, 31, 0x136C74u);
    ctx->pc = 0x136C70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136C6Cu;
            // 0x136c70: 0x2484c1c0  addiu       $a0, $a0, -0x3E40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C74u; }
        if (ctx->pc != 0x136C74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C74u; }
        if (ctx->pc != 0x136C74u) { return; }
    }
    ctx->pc = 0x136C74u;
label_136c74:
    // 0x136c74: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x136C74u;
    {
        const bool branch_taken_0x136c74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C74u;
            // 0x136c78: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136c74) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136C7Cu;
    // 0x136c7c: 0x0  nop
    ctx->pc = 0x136c7cu;
    // NOP
label_136c80:
    // 0x136c80: 0x16400007  bnez        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x136C80u;
    {
        const bool branch_taken_0x136c80 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x136c80) {
            ctx->pc = 0x136CA0u;
            goto label_136ca0;
        }
    }
    ctx->pc = 0x136C88u;
    // 0x136c88: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136c88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136c8c: 0xc04d480  jal         func_135200
    ctx->pc = 0x136C8Cu;
    SET_GPR_U32(ctx, 31, 0x136C94u);
    ctx->pc = 0x136C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136C8Cu;
            // 0x136c90: 0x2484c1e8  addiu       $a0, $a0, -0x3E18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C94u; }
        if (ctx->pc != 0x136C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C94u; }
        if (ctx->pc != 0x136C94u) { return; }
    }
    ctx->pc = 0x136C94u;
label_136c94:
    // 0x136c94: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x136C94u;
    {
        const bool branch_taken_0x136c94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136C94u;
            // 0x136c98: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136c94) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136C9Cu;
    // 0x136c9c: 0x0  nop
    ctx->pc = 0x136c9cu;
    // NOP
label_136ca0:
    // 0x136ca0: 0x16200007  bnez        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x136CA0u;
    {
        const bool branch_taken_0x136ca0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x136ca0) {
            ctx->pc = 0x136CC0u;
            goto label_136cc0;
        }
    }
    ctx->pc = 0x136CA8u;
    // 0x136ca8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136ca8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136cac: 0xc04d480  jal         func_135200
    ctx->pc = 0x136CACu;
    SET_GPR_U32(ctx, 31, 0x136CB4u);
    ctx->pc = 0x136CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136CACu;
            // 0x136cb0: 0x2484c210  addiu       $a0, $a0, -0x3DF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951440));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CB4u; }
        if (ctx->pc != 0x136CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CB4u; }
        if (ctx->pc != 0x136CB4u) { return; }
    }
    ctx->pc = 0x136CB4u;
label_136cb4:
    // 0x136cb4: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x136CB4u;
    {
        const bool branch_taken_0x136cb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136CB4u;
            // 0x136cb8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136cb4) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136CBCu;
    // 0x136cbc: 0x0  nop
    ctx->pc = 0x136cbcu;
    // NOP
label_136cc0:
    // 0x136cc0: 0xc04d558  jal         func_135560
    ctx->pc = 0x136CC0u;
    SET_GPR_U32(ctx, 31, 0x136CC8u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CC8u; }
        if (ctx->pc != 0x136CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CC8u; }
        if (ctx->pc != 0x136CC8u) { return; }
    }
    ctx->pc = 0x136CC8u;
label_136cc8:
    // 0x136cc8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x136cc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136ccc: 0x56000006  bnel        $s0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x136CCCu;
    {
        const bool branch_taken_0x136ccc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136ccc) {
            ctx->pc = 0x136CD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136CCCu;
            // 0x136cd0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136CE8u;
            goto label_136ce8;
        }
    }
    ctx->pc = 0x136CD4u;
    // 0x136cd4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136cd4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136cd8: 0xc04d480  jal         func_135200
    ctx->pc = 0x136CD8u;
    SET_GPR_U32(ctx, 31, 0x136CE0u);
    ctx->pc = 0x136CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136CD8u;
            // 0x136cdc: 0x2484c238  addiu       $a0, $a0, -0x3DC8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CE0u; }
        if (ctx->pc != 0x136CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CE0u; }
        if (ctx->pc != 0x136CE0u) { return; }
    }
    ctx->pc = 0x136CE0u;
label_136ce0:
    // 0x136ce0: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x136CE0u;
    {
        const bool branch_taken_0x136ce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136CE0u;
            // 0x136ce4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136ce0) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136CE8u;
label_136ce8:
    // 0x136ce8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x136ce8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136cec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x136CECu;
    SET_GPR_U32(ctx, 31, 0x136CF4u);
    ctx->pc = 0x136CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136CECu;
            // 0x136cf0: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CF4u; }
        if (ctx->pc != 0x136CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CF4u; }
        if (ctx->pc != 0x136CF4u) { return; }
    }
    ctx->pc = 0x136CF4u;
label_136cf4:
    // 0x136cf4: 0xafb10000  sw          $s1, 0x0($sp)
    ctx->pc = 0x136cf4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 17));
    // 0x136cf8: 0xafb20004  sw          $s2, 0x4($sp)
    ctx->pc = 0x136cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 18));
    // 0x136cfc: 0xafb30008  sw          $s3, 0x8($sp)
    ctx->pc = 0x136cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 19));
    // 0x136d00: 0x8e020060  lw          $v0, 0x60($s0)
    ctx->pc = 0x136d00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x136d04: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x136D04u;
    {
        const bool branch_taken_0x136d04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D04u;
            // 0x136d08: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d04) {
            ctx->pc = 0x136D28u;
            goto label_136d28;
        }
    }
    ctx->pc = 0x136D0Cu;
    // 0x136d0c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x136d0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x136d10: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136d10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136d14: 0x40f809  jalr        $v0
    ctx->pc = 0x136D14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136D1Cu);
        ctx->pc = 0x136D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D14u;
            // 0x136d18: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136D1Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136D1Cu; }
            if (ctx->pc != 0x136D1Cu) { return; }
        }
        }
    }
    ctx->pc = 0x136D1Cu;
label_136d1c:
    // 0x136d1c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x136D1Cu;
    {
        const bool branch_taken_0x136d1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D1Cu;
            // 0x136d20: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136d1c) {
            ctx->pc = 0x136D30u;
            goto label_136d30;
        }
    }
    ctx->pc = 0x136D24u;
    // 0x136d24: 0x0  nop
    ctx->pc = 0x136d24u;
    // NOP
label_136d28:
    // 0x136d28: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x136d28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_136d2c:
    // 0x136d2c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136d2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136d30:
    // 0x136d30: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136d30u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136d34: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x136d34u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x136d38: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x136d38u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x136d3c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x136d3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x136d40: 0x3e00008  jr          $ra
    ctx->pc = 0x136D40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136D40u;
            // 0x136d44: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136C74u: goto label_136c74;
            case 0x136C80u: goto label_136c80;
            case 0x136C94u: goto label_136c94;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CF4u: goto label_136cf4;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136D48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
