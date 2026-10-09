#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FB88
// Address: 0x12fb88 - 0x12fce0
void sub_0012FB88_0x12fb88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FB88_0x12fb88");
#endif

    switch (ctx->pc) {
        case 0x12fc70u: goto label_12fc70;
        default: break;
    }

    ctx->pc = 0x12fb88u;

    // 0x12fb88: 0xac850060  sw          $a1, 0x60($a0)
    ctx->pc = 0x12fb88u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 96), GPR_U32(ctx, 5));
    // 0x12fb8c: 0x3e00008  jr          $ra
    ctx->pc = 0x12FB8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB8Cu;
            // 0x12fb90: 0xac85003c  sw          $a1, 0x3C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FB94u;
    // 0x12fb94: 0x0  nop
    ctx->pc = 0x12fb94u;
    // NOP
    // 0x12fb98: 0x3e00008  jr          $ra
    ctx->pc = 0x12FB98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FB9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB98u;
            // 0x12fb9c: 0xac850064  sw          $a1, 0x64($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 100), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBA0u;
    // 0x12fba0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBA0u;
            // 0x12fba4: 0xac85006c  sw          $a1, 0x6C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 108), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBA8u;
    // 0x12fba8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBA8u;
            // 0x12fbac: 0xac850068  sw          $a1, 0x68($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 104), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBB0u;
    // 0x12fbb0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBB0u;
            // 0x12fbb4: 0xac850070  sw          $a1, 0x70($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 112), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBB8u;
    // 0x12fbb8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBB8u;
            // 0x12fbbc: 0xac850074  sw          $a1, 0x74($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 116), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBC0u;
    // 0x12fbc0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBC0u;
            // 0x12fbc4: 0xac850078  sw          $a1, 0x78($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 120), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBC8u;
    // 0x12fbc8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBC8u;
            // 0x12fbcc: 0xac85007c  sw          $a1, 0x7C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 124), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBD0u;
    // 0x12fbd0: 0x808202d6  lb          $v0, 0x2D6($a0)
    ctx->pc = 0x12fbd0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 726)));
    // 0x12fbd4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12fbd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fbd8: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12FBD8u;
    {
        const bool branch_taken_0x12fbd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x12fbd8) {
            ctx->pc = 0x12FBF0u;
            goto label_12fbf0;
        }
    }
    ctx->pc = 0x12FBE0u;
    // 0x12fbe0: 0x8c820048  lw          $v0, 0x48($a0)
    ctx->pc = 0x12fbe0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x12fbe4: 0xa08302d6  sb          $v1, 0x2D6($a0)
    ctx->pc = 0x12fbe4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 726), (uint8_t)GPR_U32(ctx, 3));
    // 0x12fbe8: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x12fbe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x12fbec: 0xac820048  sw          $v0, 0x48($a0)
    ctx->pc = 0x12fbecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 2));
label_12fbf0:
    // 0x12fbf0: 0x3e00008  jr          $ra
    ctx->pc = 0x12FBF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FBF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FBF0u;
            // 0x12fbf4: 0xa48502e8  sh          $a1, 0x2E8($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 744), (uint16_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FBF8u;
    // 0x12fbf8: 0x808202d6  lb          $v0, 0x2D6($a0)
    ctx->pc = 0x12fbf8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 726)));
    // 0x12fbfc: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x12fbfcu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x12fc00: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12fc00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fc04: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12FC04u;
    {
        const bool branch_taken_0x12fc04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x12FC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FC04u;
            // 0x12fc08: 0xa42821  addu        $a1, $a1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fc04) {
            ctx->pc = 0x12FC1Cu;
            goto label_12fc1c;
        }
    }
    ctx->pc = 0x12FC0Cu;
    // 0x12fc0c: 0x8c820048  lw          $v0, 0x48($a0)
    ctx->pc = 0x12fc0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x12fc10: 0xa08302d6  sb          $v1, 0x2D6($a0)
    ctx->pc = 0x12fc10u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 726), (uint8_t)GPR_U32(ctx, 3));
    // 0x12fc14: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x12fc14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x12fc18: 0xac820048  sw          $v0, 0x48($a0)
    ctx->pc = 0x12fc18u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 2));
label_12fc1c:
    // 0x12fc1c: 0x3e00008  jr          $ra
    ctx->pc = 0x12FC1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FC1Cu;
            // 0x12fc20: 0xa4a602ea  sh          $a2, 0x2EA($a1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 5), 746), (uint16_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FBF0u: goto label_12fbf0;
            case 0x12FC1Cu: goto label_12fc1c;
            case 0x12FC68u: goto label_12fc68;
            case 0x12FC70u: goto label_12fc70;
            case 0x12FCBCu: goto label_12fcbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FC24u;
    // 0x12fc24: 0x0  nop
    ctx->pc = 0x12fc24u;
    // NOP
    // 0x12fc28: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12fc28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12fc2c: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x12fc2cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12fc30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12fc34: 0x247002d7  addiu       $s0, $v1, 0x2D7
    ctx->pc = 0x12fc34u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 727));
    // 0x12fc38: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12fc38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12fc3c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12fc3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc40: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12fc40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12fc44: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12fc44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fc48: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12fc48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc4c: 0x806202d6  lb          $v0, 0x2D6($v1)
    ctx->pc = 0x12fc4cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 726)));
    // 0x12fc50: 0x10460005  beq         $v0, $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x12FC50u;
    {
        const bool branch_taken_0x12fc50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 6));
        ctx->pc = 0x12FC54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FC50u;
            // 0x12fc54: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fc50) {
            ctx->pc = 0x12FC68u;
            goto label_12fc68;
        }
    }
    ctx->pc = 0x12FC58u;
    // 0x12fc58: 0x8c620048  lw          $v0, 0x48($v1)
    ctx->pc = 0x12fc58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 72)));
    // 0x12fc5c: 0xa06602d6  sb          $a2, 0x2D6($v1)
    ctx->pc = 0x12fc5cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 726), (uint8_t)GPR_U32(ctx, 6));
    // 0x12fc60: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x12fc60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x12fc64: 0xac620048  sw          $v0, 0x48($v1)
    ctx->pc = 0x12fc64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 72), GPR_U32(ctx, 2));
label_12fc68:
    // 0x12fc68: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12FC68u;
    SET_GPR_U32(ctx, 31, 0x12FC70u);
    ctx->pc = 0x12FC6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FC68u;
            // 0x12fc6c: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FC70u; }
        if (ctx->pc != 0x12FC70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FC70u; }
        if (ctx->pc != 0x12FC70u) { return; }
    }
    ctx->pc = 0x12FC70u;
label_12fc70:
    // 0x12fc70: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12fc70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc74: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x12fc74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc78: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12fc78u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12fc7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12fc7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fc80: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x12fc80u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12fc84: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12fc84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12fc88: 0x8042d7e  j           func_10B5F8
    ctx->pc = 0x12FC88u;
    ctx->pc = 0x12FC8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FC88u;
            // 0x12fc8c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12FC90u;
    // 0x12fc90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12fc90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12fc94: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x12fc94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12fc98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12fc9c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12fc9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fca0: 0x80e202d6  lb          $v0, 0x2D6($a3)
    ctx->pc = 0x12fca0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 726)));
    // 0x12fca4: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12FCA4u;
    {
        const bool branch_taken_0x12fca4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x12FCA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FCA4u;
            // 0x12fca8: 0x24e402d7  addiu       $a0, $a3, 0x2D7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 727));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fca4) {
            ctx->pc = 0x12FCBCu;
            goto label_12fcbc;
        }
    }
    ctx->pc = 0x12FCACu;
    // 0x12fcac: 0x8ce20048  lw          $v0, 0x48($a3)
    ctx->pc = 0x12fcacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 72)));
    // 0x12fcb0: 0xa0e002d6  sb          $zero, 0x2D6($a3)
    ctx->pc = 0x12fcb0u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 726), (uint8_t)GPR_U32(ctx, 0));
    // 0x12fcb4: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x12fcb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x12fcb8: 0xace20048  sw          $v0, 0x48($a3)
    ctx->pc = 0x12fcb8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 72), GPR_U32(ctx, 2));
label_12fcbc:
    // 0x12fcbc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12fcbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fcc0: 0x2402ff80  addiu       $v0, $zero, -0x80
    ctx->pc = 0x12fcc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x12fcc4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12fcc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fcc8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x12fcc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12fccc: 0xa4e002e8  sh          $zero, 0x2E8($a3)
    ctx->pc = 0x12fcccu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 744), (uint16_t)GPR_U32(ctx, 0));
    // 0x12fcd0: 0xa4e202ec  sh          $v0, 0x2EC($a3)
    ctx->pc = 0x12fcd0u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 748), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fcd4: 0xa4e202ea  sh          $v0, 0x2EA($a3)
    ctx->pc = 0x12fcd4u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 746), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fcd8: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12FCD8u;
    ctx->pc = 0x12FCDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FCD8u;
            // 0x12fcdc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12FCE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
