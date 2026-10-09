#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129C08
// Address: 0x129c08 - 0x129d48
void sub_00129C08_0x129c08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129C08_0x129c08");
#endif

    switch (ctx->pc) {
        case 0x129c28u: goto label_129c28;
        case 0x129c50u: goto label_129c50;
        case 0x129c58u: goto label_129c58;
        case 0x129c6cu: goto label_129c6c;
        case 0x129cb8u: goto label_129cb8;
        case 0x129ce8u: goto label_129ce8;
        case 0x129d30u: goto label_129d30;
        default: break;
    }

    ctx->pc = 0x129c08u;

label_129c08:
    // 0x129c08: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129c08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129c0c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129c0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129c10: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x129c10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129c14: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x129C14u;
    {
        const bool branch_taken_0x129c14 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x129C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129C14u;
            // 0x129c18: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129c14) {
            ctx->pc = 0x129C30u;
            goto label_129c30;
        }
    }
    ctx->pc = 0x129C1Cu;
    // 0x129c1c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129c1cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129c20: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129C20u;
    SET_GPR_U32(ctx, 31, 0x129C28u);
    ctx->pc = 0x129C24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129C20u;
            // 0x129c24: 0x2484a180  addiu       $a0, $a0, -0x5E80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129C28u; }
        if (ctx->pc != 0x129C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129C28u; }
        if (ctx->pc != 0x129C28u) { return; }
    }
    ctx->pc = 0x129C28u;
label_129c28:
    // 0x129c28: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x129C28u;
    {
        const bool branch_taken_0x129c28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129C28u;
            // 0x129c2c: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129c28) {
            ctx->pc = 0x129C94u;
            goto label_129c94;
        }
    }
    ctx->pc = 0x129C30u;
label_129c30:
    // 0x129c30: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x129c30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x129c34: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x129c34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x129c38: 0x3442fffe  ori         $v0, $v0, 0xFFFE
    ctx->pc = 0x129c38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
    // 0x129c3c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x129c3cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x129c40: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x129C40u;
    {
        const bool branch_taken_0x129c40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x129c40) {
            ctx->pc = 0x129C64u;
            goto label_129c64;
        }
    }
    ctx->pc = 0x129C48u;
    // 0x129c48: 0xc04c3fa  jal         func_130FE8
    ctx->pc = 0x129C48u;
    SET_GPR_U32(ctx, 31, 0x129C50u);
    ctx->pc = 0x129C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129C48u;
            // 0x129c4c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130FE8u;
    if (runtime->hasFunction(0x130FE8u)) {
        auto targetFn = runtime->lookupFunction(0x130FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129C50u; }
        if (ctx->pc != 0x129C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130FE8_0x130fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129C50u; }
        if (ctx->pc != 0x129C50u) { return; }
    }
    ctx->pc = 0x129C50u;
label_129c50:
    // 0x129c50: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x129C50u;
    SET_GPR_U32(ctx, 31, 0x129C58u);
    ctx->pc = 0x129C54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129C50u;
            // 0x129c54: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129C58u; }
        if (ctx->pc != 0x129C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129C58u; }
        if (ctx->pc != 0x129C58u) { return; }
    }
    ctx->pc = 0x129C58u;
label_129c58:
    // 0x129c58: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x129c58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x129c5c: 0x1043000d  beq         $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x129C5Cu;
    {
        const bool branch_taken_0x129c5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x129C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129C5Cu;
            // 0x129c60: 0x2402fffb  addiu       $v0, $zero, -0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129c5c) {
            ctx->pc = 0x129C94u;
            goto label_129c94;
        }
    }
    ctx->pc = 0x129C64u;
label_129c64:
    // 0x129c64: 0xc04c390  jal         func_130E40
    ctx->pc = 0x129C64u;
    SET_GPR_U32(ctx, 31, 0x129C6Cu);
    ctx->pc = 0x129C68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129C64u;
            // 0x129c68: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130E40u;
    if (runtime->hasFunction(0x130E40u)) {
        auto targetFn = runtime->lookupFunction(0x130E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129C6Cu; }
        if (ctx->pc != 0x129C6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E40_0x130e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129C6Cu; }
        if (ctx->pc != 0x129C6Cu) { return; }
    }
    ctx->pc = 0x129C6Cu;
label_129c6c:
    // 0x129c6c: 0x3c04000f  lui         $a0, 0xF
    ctx->pc = 0x129c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)15 << 16));
    // 0x129c70: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x129c70u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x129c74: 0x244507ff  addiu       $a1, $v0, 0x7FF
    ctx->pc = 0x129c74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x129c78: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x129c78u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x129c7c: 0x2403fffb  addiu       $v1, $zero, -0x5
    ctx->pc = 0x129c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x129c80: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x129c80u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x129c84: 0x3484fffe  ori         $a0, $a0, 0xFFFE
    ctx->pc = 0x129c84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65534);
    // 0x129c88: 0x82202a  slt         $a0, $a0, $v0
    ctx->pc = 0x129c88u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x129c8c: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x129c8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x129c90: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x129c90u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
label_129c94:
    // 0x129c94: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129c94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129c98: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x129c98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129c9c: 0x3e00008  jr          $ra
    ctx->pc = 0x129C9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129CA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129C9Cu;
            // 0x129ca0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129C08u: goto label_129c08;
            case 0x129C28u: goto label_129c28;
            case 0x129C30u: goto label_129c30;
            case 0x129C50u: goto label_129c50;
            case 0x129C58u: goto label_129c58;
            case 0x129C64u: goto label_129c64;
            case 0x129C6Cu: goto label_129c6c;
            case 0x129C94u: goto label_129c94;
            case 0x129CB8u: goto label_129cb8;
            case 0x129CE8u: goto label_129ce8;
            case 0x129CF8u: goto label_129cf8;
            case 0x129D04u: goto label_129d04;
            case 0x129D30u: goto label_129d30;
            case 0x129D38u: goto label_129d38;
            case 0x129D3Cu: goto label_129d3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129CA4u;
    // 0x129ca4: 0x0  nop
    ctx->pc = 0x129ca4u;
    // NOP
    // 0x129ca8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129ca8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129cac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x129cacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x129cb0: 0xc04a702  jal         func_129C08
    ctx->pc = 0x129CB0u;
    SET_GPR_U32(ctx, 31, 0x129CB8u);
    ctx->pc = 0x129C08u;
    goto label_129c08;
    ctx->pc = 0x129CB8u;
label_129cb8:
    // 0x129cb8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129cb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129cbc: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x129cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x129cc0: 0x3e00008  jr          $ra
    ctx->pc = 0x129CC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129CC0u;
            // 0x129cc4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129C08u: goto label_129c08;
            case 0x129C28u: goto label_129c28;
            case 0x129C30u: goto label_129c30;
            case 0x129C50u: goto label_129c50;
            case 0x129C58u: goto label_129c58;
            case 0x129C64u: goto label_129c64;
            case 0x129C6Cu: goto label_129c6c;
            case 0x129C94u: goto label_129c94;
            case 0x129CB8u: goto label_129cb8;
            case 0x129CE8u: goto label_129ce8;
            case 0x129CF8u: goto label_129cf8;
            case 0x129D04u: goto label_129d04;
            case 0x129D30u: goto label_129d30;
            case 0x129D38u: goto label_129d38;
            case 0x129D3Cu: goto label_129d3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129CC8u;
    // 0x129cc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129cc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129ccc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129cccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129cd0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x129cd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129cd4: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x129CD4u;
    {
        const bool branch_taken_0x129cd4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x129CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129CD4u;
            // 0x129cd8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129cd4) {
            ctx->pc = 0x129CF8u;
            goto label_129cf8;
        }
    }
    ctx->pc = 0x129CDCu;
    // 0x129cdc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129ce0: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129CE0u;
    SET_GPR_U32(ctx, 31, 0x129CE8u);
    ctx->pc = 0x129CE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129CE0u;
            // 0x129ce4: 0x2484a1b0  addiu       $a0, $a0, -0x5E50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129CE8u; }
        if (ctx->pc != 0x129CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129CE8u; }
        if (ctx->pc != 0x129CE8u) { return; }
    }
    ctx->pc = 0x129CE8u;
label_129ce8:
    // 0x129ce8: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x129ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x129cec: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x129CECu;
    {
        const bool branch_taken_0x129cec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129CECu;
            // 0x129cf0: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129cec) {
            ctx->pc = 0x129D04u;
            goto label_129d04;
        }
    }
    ctx->pc = 0x129CF4u;
    // 0x129cf4: 0x0  nop
    ctx->pc = 0x129cf4u;
    // NOP
label_129cf8:
    // 0x129cf8: 0x8c820018  lw          $v0, 0x18($a0)
    ctx->pc = 0x129cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x129cfc: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x129cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x129d00: 0x8c82001c  lw          $v0, 0x1C($a0)
    ctx->pc = 0x129d00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
label_129d04:
    // 0x129d04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129d04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129d08: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x129d08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129d0c: 0x3e00008  jr          $ra
    ctx->pc = 0x129D0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D0Cu;
            // 0x129d10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129C08u: goto label_129c08;
            case 0x129C28u: goto label_129c28;
            case 0x129C30u: goto label_129c30;
            case 0x129C50u: goto label_129c50;
            case 0x129C58u: goto label_129c58;
            case 0x129C64u: goto label_129c64;
            case 0x129C6Cu: goto label_129c6c;
            case 0x129C94u: goto label_129c94;
            case 0x129CB8u: goto label_129cb8;
            case 0x129CE8u: goto label_129ce8;
            case 0x129CF8u: goto label_129cf8;
            case 0x129D04u: goto label_129d04;
            case 0x129D30u: goto label_129d30;
            case 0x129D38u: goto label_129d38;
            case 0x129D3Cu: goto label_129d3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129D14u;
    // 0x129d14: 0x0  nop
    ctx->pc = 0x129d14u;
    // NOP
    // 0x129d18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129d18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129d1c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x129D1Cu;
    {
        const bool branch_taken_0x129d1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x129D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D1Cu;
            // 0x129d20: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129d1c) {
            ctx->pc = 0x129D38u;
            goto label_129d38;
        }
    }
    ctx->pc = 0x129D24u;
    // 0x129d24: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129d24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129d28: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129D28u;
    SET_GPR_U32(ctx, 31, 0x129D30u);
    ctx->pc = 0x129D2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129D28u;
            // 0x129d2c: 0x2484a1e0  addiu       $a0, $a0, -0x5E20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129D30u; }
        if (ctx->pc != 0x129D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129D30u; }
        if (ctx->pc != 0x129D30u) { return; }
    }
    ctx->pc = 0x129D30u;
label_129d30:
    // 0x129d30: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x129D30u;
    {
        const bool branch_taken_0x129d30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D30u;
            // 0x129d34: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129d30) {
            ctx->pc = 0x129D3Cu;
            goto label_129d3c;
        }
    }
    ctx->pc = 0x129D38u;
label_129d38:
    // 0x129d38: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x129d38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
label_129d3c:
    // 0x129d3c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129d3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129d40: 0x3e00008  jr          $ra
    ctx->pc = 0x129D40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D40u;
            // 0x129d44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129C08u: goto label_129c08;
            case 0x129C28u: goto label_129c28;
            case 0x129C30u: goto label_129c30;
            case 0x129C50u: goto label_129c50;
            case 0x129C58u: goto label_129c58;
            case 0x129C64u: goto label_129c64;
            case 0x129C6Cu: goto label_129c6c;
            case 0x129C94u: goto label_129c94;
            case 0x129CB8u: goto label_129cb8;
            case 0x129CE8u: goto label_129ce8;
            case 0x129CF8u: goto label_129cf8;
            case 0x129D04u: goto label_129d04;
            case 0x129D30u: goto label_129d30;
            case 0x129D38u: goto label_129d38;
            case 0x129D3Cu: goto label_129d3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129D48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
