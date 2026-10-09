#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00151B60
// Address: 0x151b60 - 0x151cc0
void sub_00151B60_0x151b60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00151B60_0x151b60");
#endif

    switch (ctx->pc) {
        case 0x151bc8u: goto label_151bc8;
        case 0x151bd8u: goto label_151bd8;
        case 0x151bf0u: goto label_151bf0;
        case 0x151c20u: goto label_151c20;
        case 0x151c34u: goto label_151c34;
        case 0x151c4cu: goto label_151c4c;
        case 0x151c68u: goto label_151c68;
        case 0x151c94u: goto label_151c94;
        default: break;
    }

    ctx->pc = 0x151b60u;

    // 0x151b60: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x151b60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x151b64: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x151b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x151b68: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x151b68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151b6c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x151b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x151b70: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x151b70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x151b74: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x151b74u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151b78: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x151b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x151b7c: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x151b7cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151b80: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x151b80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x151b84: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x151b84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151b88: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x151b88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x151b8c: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x151b8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x151b90: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x151b90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x151b94: 0x8e320604  lw          $s2, 0x604($s1)
    ctx->pc = 0x151b94u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 1540)));
    // 0x151b98: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x151b98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x151b9c: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x151b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x151ba0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x151ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x151ba4: 0x245300e0  addiu       $s3, $v0, 0xE0
    ctx->pc = 0x151ba4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 224));
    // 0x151ba8: 0x2331821  addu        $v1, $s1, $s3
    ctx->pc = 0x151ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x151bac: 0x8c70000c  lw          $s0, 0xC($v1)
    ctx->pc = 0x151bacu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x151bb0: 0x1200002d  beqz        $s0, . + 4 + (0x2D << 2)
    ctx->pc = 0x151BB0u;
    {
        const bool branch_taken_0x151bb0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x151BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151BB0u;
            // 0x151bb4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151bb0) {
            ctx->pc = 0x151C68u;
            goto label_151c68;
        }
    }
    ctx->pc = 0x151BB8u;
    // 0x151bb8: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x151bb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151bbc: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x151bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x151bc0: 0x40f809  jalr        $v0
    ctx->pc = 0x151BC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x151BC8u);
        ctx->pc = 0x151BC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151BC0u;
            // 0x151bc4: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x151BC8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151BC8u: goto label_151bc8;
            case 0x151BD8u: goto label_151bd8;
            case 0x151BF0u: goto label_151bf0;
            case 0x151C20u: goto label_151c20;
            case 0x151C34u: goto label_151c34;
            case 0x151C4Cu: goto label_151c4c;
            case 0x151C68u: goto label_151c68;
            case 0x151C6Cu: goto label_151c6c;
            case 0x151C94u: goto label_151c94;
            case 0x151C98u: goto label_151c98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x151BC8u; }
            if (ctx->pc != 0x151BC8u) { return; }
        }
        }
    }
    ctx->pc = 0x151BC8u;
label_151bc8:
    // 0x151bc8: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x151bc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151bcc: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x151bccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x151bd0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x151BD0u;
    SET_GPR_U32(ctx, 31, 0x151BD8u);
    ctx->pc = 0x151BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x151BD0u;
            // 0x151bd4: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151BD8u; }
        if (ctx->pc != 0x151BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151BD8u; }
        if (ctx->pc != 0x151BD8u) { return; }
    }
    ctx->pc = 0x151BD8u;
label_151bd8:
    // 0x151bd8: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x151bd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151bdc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x151bdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151be0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x151be0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x151be4: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x151be4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x151be8: 0x40f809  jalr        $v0
    ctx->pc = 0x151BE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x151BF0u);
        ctx->pc = 0x151BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151BE8u;
            // 0x151bec: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x151BF0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151BC8u: goto label_151bc8;
            case 0x151BD8u: goto label_151bd8;
            case 0x151BF0u: goto label_151bf0;
            case 0x151C20u: goto label_151c20;
            case 0x151C34u: goto label_151c34;
            case 0x151C4Cu: goto label_151c4c;
            case 0x151C68u: goto label_151c68;
            case 0x151C6Cu: goto label_151c6c;
            case 0x151C94u: goto label_151c94;
            case 0x151C98u: goto label_151c98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x151BF0u; }
            if (ctx->pc != 0x151BF0u) { return; }
        }
        }
    }
    ctx->pc = 0x151BF0u;
label_151bf0:
    // 0x151bf0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x151bf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151bf4: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x151bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x151bf8: 0x27b60010  addiu       $s6, $sp, 0x10
    ctx->pc = 0x151bf8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x151bfc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x151bfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151c00: 0x2823023  subu        $a2, $s4, $v0
    ctx->pc = 0x151c00u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x151c04: 0x54102a  slt         $v0, $v0, $s4
    ctx->pc = 0x151c04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x151c08: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x151C08u;
    {
        const bool branch_taken_0x151c08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x151C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151C08u;
            // 0x151c0c: 0x2c0382d  daddu       $a3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151c08) {
            ctx->pc = 0x151C4Cu;
            goto label_151c4c;
        }
    }
    ctx->pc = 0x151C10u;
    // 0x151c10: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x151c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151c14: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x151c14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x151c18: 0x60f809  jalr        $v1
    ctx->pc = 0x151C18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x151C20u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x151C20u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151BC8u: goto label_151bc8;
            case 0x151BD8u: goto label_151bd8;
            case 0x151BF0u: goto label_151bf0;
            case 0x151C20u: goto label_151c20;
            case 0x151C34u: goto label_151c34;
            case 0x151C4Cu: goto label_151c4c;
            case 0x151C68u: goto label_151c68;
            case 0x151C6Cu: goto label_151c6c;
            case 0x151C94u: goto label_151c94;
            case 0x151C98u: goto label_151c98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x151C20u; }
            if (ctx->pc != 0x151C20u) { return; }
        }
        }
    }
    ctx->pc = 0x151C20u;
label_151c20:
    // 0x151c20: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x151c20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x151c24: 0x8fa40010  lw          $a0, 0x10($sp)
    ctx->pc = 0x151c24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x151c28: 0x8fa60014  lw          $a2, 0x14($sp)
    ctx->pc = 0x151c28u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x151c2c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x151C2Cu;
    SET_GPR_U32(ctx, 31, 0x151C34u);
    ctx->pc = 0x151C30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x151C2Cu;
            // 0x151c30: 0x2a52821  addu        $a1, $s5, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151C34u; }
        if (ctx->pc != 0x151C34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151C34u; }
        if (ctx->pc != 0x151C34u) { return; }
    }
    ctx->pc = 0x151C34u;
label_151c34:
    // 0x151c34: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x151c34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151c38: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x151c38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151c3c: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x151c3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151c40: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x151c40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x151c44: 0x40f809  jalr        $v0
    ctx->pc = 0x151C44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x151C4Cu);
        ctx->pc = 0x151C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151C44u;
            // 0x151c48: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x151C4Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151BC8u: goto label_151bc8;
            case 0x151BD8u: goto label_151bd8;
            case 0x151BF0u: goto label_151bf0;
            case 0x151C20u: goto label_151c20;
            case 0x151C34u: goto label_151c34;
            case 0x151C4Cu: goto label_151c4c;
            case 0x151C68u: goto label_151c68;
            case 0x151C6Cu: goto label_151c6c;
            case 0x151C94u: goto label_151c94;
            case 0x151C98u: goto label_151c98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x151C4Cu; }
            if (ctx->pc != 0x151C4Cu) { return; }
        }
        }
    }
    ctx->pc = 0x151C4Cu;
label_151c4c:
    // 0x151c4c: 0x2331021  addu        $v0, $s1, $s3
    ctx->pc = 0x151c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x151c50: 0x8c430010  lw          $v1, 0x10($v0)
    ctx->pc = 0x151c50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x151c54: 0x50600005  beql        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x151C54u;
    {
        const bool branch_taken_0x151c54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x151c54) {
            ctx->pc = 0x151C58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151C54u;
            // 0x151c58: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x151C6Cu;
            goto label_151c6c;
        }
    }
    ctx->pc = 0x151C5Cu;
    // 0x151c5c: 0x8c440014  lw          $a0, 0x14($v0)
    ctx->pc = 0x151c5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x151c60: 0x60f809  jalr        $v1
    ctx->pc = 0x151C60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x151C68u);
        ctx->pc = 0x151C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151C60u;
            // 0x151c64: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x151C68u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151BC8u: goto label_151bc8;
            case 0x151BD8u: goto label_151bd8;
            case 0x151BF0u: goto label_151bf0;
            case 0x151C20u: goto label_151c20;
            case 0x151C34u: goto label_151c34;
            case 0x151C4Cu: goto label_151c4c;
            case 0x151C68u: goto label_151c68;
            case 0x151C6Cu: goto label_151c6c;
            case 0x151C94u: goto label_151c94;
            case 0x151C98u: goto label_151c98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x151C68u; }
            if (ctx->pc != 0x151C68u) { return; }
        }
        }
    }
    ctx->pc = 0x151C68u;
label_151c68:
    // 0x151c68: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x151c68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_151c6c:
    // 0x151c6c: 0x1642000a  bne         $s2, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x151C6Cu;
    {
        const bool branch_taken_0x151c6c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x151C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151C6Cu;
            // 0x151c70: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151c6c) {
            ctx->pc = 0x151C98u;
            goto label_151c98;
        }
    }
    ctx->pc = 0x151C74u;
    // 0x151c74: 0x8e24011c  lw          $a0, 0x11C($s1)
    ctx->pc = 0x151c74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 284)));
    // 0x151c78: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x151C78u;
    {
        const bool branch_taken_0x151c78 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x151C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151C78u;
            // 0x151c7c: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151c78) {
            ctx->pc = 0x151C98u;
            goto label_151c98;
        }
    }
    ctx->pc = 0x151C80u;
    // 0x151c80: 0x8e260120  lw          $a2, 0x120($s1)
    ctx->pc = 0x151c80u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 288)));
    // 0x151c84: 0x286102a  slt         $v0, $s4, $a2
    ctx->pc = 0x151c84u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x151c88: 0x282300b  movn        $a2, $s4, $v0
    ctx->pc = 0x151c88u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 20));
    // 0x151c8c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x151C8Cu;
    SET_GPR_U32(ctx, 31, 0x151C94u);
    ctx->pc = 0x151C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x151C8Cu;
            // 0x151c90: 0xae260124  sw          $a2, 0x124($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 292), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151C94u; }
        if (ctx->pc != 0x151C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151C94u; }
        if (ctx->pc != 0x151C94u) { return; }
    }
    ctx->pc = 0x151C94u;
label_151c94:
    // 0x151c94: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x151c94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_151c98:
    // 0x151c98: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x151c98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x151c9c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x151c9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x151ca0: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x151ca0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x151ca4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x151ca4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x151ca8: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x151ca8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x151cac: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x151cacu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x151cb0: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x151cb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x151cb4: 0x3e00008  jr          $ra
    ctx->pc = 0x151CB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x151CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151CB4u;
            // 0x151cb8: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151BC8u: goto label_151bc8;
            case 0x151BD8u: goto label_151bd8;
            case 0x151BF0u: goto label_151bf0;
            case 0x151C20u: goto label_151c20;
            case 0x151C34u: goto label_151c34;
            case 0x151C4Cu: goto label_151c4c;
            case 0x151C68u: goto label_151c68;
            case 0x151C6Cu: goto label_151c6c;
            case 0x151C94u: goto label_151c94;
            case 0x151C98u: goto label_151c98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x151CBCu;
    // 0x151cbc: 0x0  nop
    ctx->pc = 0x151cbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
