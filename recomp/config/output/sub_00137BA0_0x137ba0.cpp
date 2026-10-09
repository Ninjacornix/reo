#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137BA0
// Address: 0x137ba0 - 0x137d80
void sub_00137BA0_0x137ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137BA0_0x137ba0");
#endif

    switch (ctx->pc) {
        case 0x137bf8u: goto label_137bf8;
        case 0x137c38u: goto label_137c38;
        case 0x137c4cu: goto label_137c4c;
        case 0x137c58u: goto label_137c58;
        case 0x137c78u: goto label_137c78;
        case 0x137c88u: goto label_137c88;
        case 0x137c94u: goto label_137c94;
        case 0x137cf4u: goto label_137cf4;
        case 0x137d04u: goto label_137d04;
        case 0x137d14u: goto label_137d14;
        case 0x137d30u: goto label_137d30;
        default: break;
    }

    ctx->pc = 0x137ba0u;

    // 0x137ba0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x137ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x137ba4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x137ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137ba8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x137ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x137bac: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x137bacu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137bb0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x137bb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x137bb4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x137bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x137bb8: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x137bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x137bbc: 0x14430017  bne         $v0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x137BBCu;
    {
        const bool branch_taken_0x137bbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x137BC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137BBCu;
            // 0x137bc0: 0x92240002  lbu         $a0, 0x2($s1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137bbc) {
            ctx->pc = 0x137C1Cu;
            goto label_137c1c;
        }
    }
    ctx->pc = 0x137BC4u;
    // 0x137bc4: 0x82230002  lb          $v1, 0x2($s1)
    ctx->pc = 0x137bc4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x137bc8: 0x2c62000a  sltiu       $v0, $v1, 0xA
    ctx->pc = 0x137bc8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x137bcc: 0x50400013  beql        $v0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x137BCCu;
    {
        const bool branch_taken_0x137bcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x137bcc) {
            ctx->pc = 0x137BD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137BCCu;
            // 0x137bd0: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137C1Cu;
            goto label_137c1c;
        }
    }
    ctx->pc = 0x137BD4u;
    // 0x137bd4: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x137bd4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x137bd8: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x137bd8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x137bdc: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x137bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x137be0: 0x8c63c5a0  lw          $v1, -0x3A60($v1)
    ctx->pc = 0x137be0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294952352)));
    // 0x137be4: 0x600008  jr          $v1
    ctx->pc = 0x137BE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137BF0u: goto label_137bf0;
            case 0x137C10u: goto label_137c10;
            case 0x137C18u: goto label_137c18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137BECu;
    // 0x137bec: 0x0  nop
    ctx->pc = 0x137becu;
    // NOP
label_137bf0:
    // 0x137bf0: 0xc04dd9a  jal         func_137668
    ctx->pc = 0x137BF0u;
    SET_GPR_U32(ctx, 31, 0x137BF8u);
    ctx->pc = 0x137BF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137BF0u;
            // 0x137bf4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137668u;
    if (runtime->hasFunction(0x137668u)) {
        auto targetFn = runtime->lookupFunction(0x137668u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137BF8u; }
        if (ctx->pc != 0x137BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137668_0x137668(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137BF8u; }
        if (ctx->pc != 0x137BF8u) { return; }
    }
    ctx->pc = 0x137BF8u;
label_137bf8:
    // 0x137bf8: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x137bf8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x137bfc: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137c00: 0x2463bbe4  addiu       $v1, $v1, -0x441C
    ctx->pc = 0x137c00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949860));
    // 0x137c04: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x137c04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x137c08: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x137c08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137c0c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x137c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137c10:
    // 0x137c10: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x137c10u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x137c14: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x137c14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_137c18:
    // 0x137c18: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x137c18u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_137c1c:
    // 0x137c1c: 0x41600  sll         $v0, $a0, 24
    ctx->pc = 0x137c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x137c20: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x137c20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137c24: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x137c24u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x137c28: 0x5443002c  bnel        $v0, $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x137C28u;
    {
        const bool branch_taken_0x137c28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x137c28) {
            ctx->pc = 0x137C2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137C28u;
            // 0x137c2c: 0x41600  sll         $v0, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137CDCu;
            goto label_137cdc;
        }
    }
    ctx->pc = 0x137C30u;
    // 0x137c30: 0xc04e082  jal         func_138208
    ctx->pc = 0x137C30u;
    SET_GPR_U32(ctx, 31, 0x137C38u);
    ctx->pc = 0x137C34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137C30u;
            // 0x137c34: 0x24042000  addiu       $a0, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C38u; }
        if (ctx->pc != 0x137C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C38u; }
        if (ctx->pc != 0x137C38u) { return; }
    }
    ctx->pc = 0x137C38u;
label_137c38:
    // 0x137c38: 0xde250028  ld          $a1, 0x28($s1)
    ctx->pc = 0x137c38u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x137c3c: 0x8e240030  lw          $a0, 0x30($s1)
    ctx->pc = 0x137c3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x137c40: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x137c40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137c44: 0xc04e0fa  jal         func_1383E8
    ctx->pc = 0x137C44u;
    SET_GPR_U32(ctx, 31, 0x137C4Cu);
    ctx->pc = 0x137C48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137C44u;
            // 0x137c48: 0x52af8  dsll        $a1, $a1, 11 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 11);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1383E8u;
    if (runtime->hasFunction(0x1383E8u)) {
        auto targetFn = runtime->lookupFunction(0x1383E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C4Cu; }
        if (ctx->pc != 0x137C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001383E8_0x1383e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C4Cu; }
        if (ctx->pc != 0x137C4Cu) { return; }
    }
    ctx->pc = 0x137C4Cu;
label_137c4c:
    // 0x137c4c: 0x24042001  addiu       $a0, $zero, 0x2001
    ctx->pc = 0x137c4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8193));
    // 0x137c50: 0xc04e082  jal         func_138208
    ctx->pc = 0x137C50u;
    SET_GPR_U32(ctx, 31, 0x137C58u);
    ctx->pc = 0x137C54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137C50u;
            // 0x137c54: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C58u; }
        if (ctx->pc != 0x137C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C58u; }
        if (ctx->pc != 0x137C58u) { return; }
    }
    ctx->pc = 0x137C58u;
label_137c58:
    // 0x137c58: 0x6010005  bgez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x137C58u;
    {
        const bool branch_taken_0x137c58 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x137C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137C58u;
            // 0x137c5c: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137c58) {
            ctx->pc = 0x137C70u;
            goto label_137c70;
        }
    }
    ctx->pc = 0x137C60u;
    // 0x137c60: 0x10183c  dsll32      $v1, $s0, 0
    ctx->pc = 0x137c60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 0));
    // 0x137c64: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x137c64u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x137c68: 0xa2220002  sb          $v0, 0x2($s1)
    ctx->pc = 0x137c68u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x137c6c: 0xae230034  sw          $v1, 0x34($s1)
    ctx->pc = 0x137c6cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
label_137c70:
    // 0x137c70: 0xc04e082  jal         func_138208
    ctx->pc = 0x137C70u;
    SET_GPR_U32(ctx, 31, 0x137C78u);
    ctx->pc = 0x137C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137C70u;
            // 0x137c74: 0x24042100  addiu       $a0, $zero, 0x2100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C78u; }
        if (ctx->pc != 0x137C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C78u; }
        if (ctx->pc != 0x137C78u) { return; }
    }
    ctx->pc = 0x137C78u;
label_137c78:
    // 0x137c78: 0x8e240030  lw          $a0, 0x30($s1)
    ctx->pc = 0x137c78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x137c7c: 0x8e250018  lw          $a1, 0x18($s1)
    ctx->pc = 0x137c7cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x137c80: 0xc04e176  jal         func_1385D8
    ctx->pc = 0x137C80u;
    SET_GPR_U32(ctx, 31, 0x137C88u);
    ctx->pc = 0x137C84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137C80u;
            // 0x137c84: 0x8e260020  lw          $a2, 0x20($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1385D8u;
    if (runtime->hasFunction(0x1385D8u)) {
        auto targetFn = runtime->lookupFunction(0x1385D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C88u; }
        if (ctx->pc != 0x137C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001385D8_0x1385d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C88u; }
        if (ctx->pc != 0x137C88u) { return; }
    }
    ctx->pc = 0x137C88u;
label_137c88:
    // 0x137c88: 0x24042101  addiu       $a0, $zero, 0x2101
    ctx->pc = 0x137c88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8449));
    // 0x137c8c: 0xc04e082  jal         func_138208
    ctx->pc = 0x137C8Cu;
    SET_GPR_U32(ctx, 31, 0x137C94u);
    ctx->pc = 0x137C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137C8Cu;
            // 0x137c90: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C94u; }
        if (ctx->pc != 0x137C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137C94u; }
        if (ctx->pc != 0x137C94u) { return; }
    }
    ctx->pc = 0x137C94u;
label_137c94:
    // 0x137c94: 0x600000a  bltz        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x137C94u;
    {
        const bool branch_taken_0x137c94 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x137C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137C94u;
            // 0x137c98: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137c94) {
            ctx->pc = 0x137CC0u;
            goto label_137cc0;
        }
    }
    ctx->pc = 0x137C9Cu;
    // 0x137c9c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137ca0: 0xa2220002  sb          $v0, 0x2($s1)
    ctx->pc = 0x137ca0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x137ca4: 0x2463bbe0  addiu       $v1, $v1, -0x4420
    ctx->pc = 0x137ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949856));
    // 0x137ca8: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x137ca8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x137cac: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x137cacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x137cb0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x137cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137cb4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x137cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x137cb8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x137CB8u;
    {
        const bool branch_taken_0x137cb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x137CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137CB8u;
            // 0x137cbc: 0x41600  sll         $v0, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137cb8) {
            ctx->pc = 0x137CDCu;
            goto label_137cdc;
        }
    }
    ctx->pc = 0x137CC0u;
label_137cc0:
    // 0x137cc0: 0x10183c  dsll32      $v1, $s0, 0
    ctx->pc = 0x137cc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 0));
    // 0x137cc4: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x137cc4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x137cc8: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x137cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x137ccc: 0xa2220002  sb          $v0, 0x2($s1)
    ctx->pc = 0x137cccu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x137cd0: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x137cd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x137cd4: 0xae230034  sw          $v1, 0x34($s1)
    ctx->pc = 0x137cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
    // 0x137cd8: 0x41600  sll         $v0, $a0, 24
    ctx->pc = 0x137cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
label_137cdc:
    // 0x137cdc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x137cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x137ce0: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x137ce0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x137ce4: 0x1443001d  bne         $v0, $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x137CE4u;
    {
        const bool branch_taken_0x137ce4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x137CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137CE4u;
            // 0x137ce8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137ce4) {
            ctx->pc = 0x137D5Cu;
            goto label_137d5c;
        }
    }
    ctx->pc = 0x137CECu;
    // 0x137cec: 0xc04e082  jal         func_138208
    ctx->pc = 0x137CECu;
    SET_GPR_U32(ctx, 31, 0x137CF4u);
    ctx->pc = 0x137CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137CECu;
            // 0x137cf0: 0x24042200  addiu       $a0, $zero, 0x2200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8704));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137CF4u; }
        if (ctx->pc != 0x137CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137CF4u; }
        if (ctx->pc != 0x137CF4u) { return; }
    }
    ctx->pc = 0x137CF4u;
label_137cf4:
    // 0x137cf4: 0x8e240030  lw          $a0, 0x30($s1)
    ctx->pc = 0x137cf4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x137cf8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x137cf8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137cfc: 0xc04e128  jal         func_1384A0
    ctx->pc = 0x137CFCu;
    SET_GPR_U32(ctx, 31, 0x137D04u);
    ctx->pc = 0x137D00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137CFCu;
            // 0x137d00: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1384A0u;
    if (runtime->hasFunction(0x1384A0u)) {
        auto targetFn = runtime->lookupFunction(0x1384A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D04u; }
        if (ctx->pc != 0x137D04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001384A0_0x1384a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D04u; }
        if (ctx->pc != 0x137D04u) { return; }
    }
    ctx->pc = 0x137D04u;
label_137d04:
    // 0x137d04: 0x4410008  bgez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x137D04u;
    {
        const bool branch_taken_0x137d04 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x137d04) {
            ctx->pc = 0x137D28u;
            goto label_137d28;
        }
    }
    ctx->pc = 0x137D0Cu;
    // 0x137d0c: 0xc04e082  jal         func_138208
    ctx->pc = 0x137D0Cu;
    SET_GPR_U32(ctx, 31, 0x137D14u);
    ctx->pc = 0x137D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137D0Cu;
            // 0x137d10: 0x24042201  addiu       $a0, $zero, 0x2201 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8705));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D14u; }
        if (ctx->pc != 0x137D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D14u; }
        if (ctx->pc != 0x137D14u) { return; }
    }
    ctx->pc = 0x137D14u;
label_137d14:
    // 0x137d14: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x137d14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x137d18: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x137d18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x137d1c: 0xa2220002  sb          $v0, 0x2($s1)
    ctx->pc = 0x137d1cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x137d20: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x137D20u;
    {
        const bool branch_taken_0x137d20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x137D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137D20u;
            // 0x137d24: 0xae230034  sw          $v1, 0x34($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137d20) {
            ctx->pc = 0x137D58u;
            goto label_137d58;
        }
    }
    ctx->pc = 0x137D28u;
label_137d28:
    // 0x137d28: 0xc04e082  jal         func_138208
    ctx->pc = 0x137D28u;
    SET_GPR_U32(ctx, 31, 0x137D30u);
    ctx->pc = 0x137D2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137D28u;
            // 0x137d2c: 0x24042202  addiu       $a0, $zero, 0x2202 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8706));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D30u; }
        if (ctx->pc != 0x137D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137D30u; }
        if (ctx->pc != 0x137D30u) { return; }
    }
    ctx->pc = 0x137D30u;
label_137d30:
    // 0x137d30: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x137d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137d34: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x137D34u;
    {
        const bool branch_taken_0x137d34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x137D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137D34u;
            // 0x137d38: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137d34) {
            ctx->pc = 0x137D5Cu;
            goto label_137d5c;
        }
    }
    ctx->pc = 0x137D3Cu;
    // 0x137d3c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x137d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x137d40: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137d40u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137d44: 0xa2220002  sb          $v0, 0x2($s1)
    ctx->pc = 0x137d44u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x137d48: 0x2463bbe4  addiu       $v1, $v1, -0x441C
    ctx->pc = 0x137d48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949860));
    // 0x137d4c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x137d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x137d50: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x137d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137d54: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x137d54u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137d58:
    // 0x137d58: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x137d58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_137d5c:
    // 0x137d5c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x137d5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x137d60: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x137d60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x137d64: 0x3e00008  jr          $ra
    ctx->pc = 0x137D64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137D64u;
            // 0x137d68: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137BF0u: goto label_137bf0;
            case 0x137BF8u: goto label_137bf8;
            case 0x137C10u: goto label_137c10;
            case 0x137C18u: goto label_137c18;
            case 0x137C1Cu: goto label_137c1c;
            case 0x137C38u: goto label_137c38;
            case 0x137C4Cu: goto label_137c4c;
            case 0x137C58u: goto label_137c58;
            case 0x137C70u: goto label_137c70;
            case 0x137C78u: goto label_137c78;
            case 0x137C88u: goto label_137c88;
            case 0x137C94u: goto label_137c94;
            case 0x137CC0u: goto label_137cc0;
            case 0x137CDCu: goto label_137cdc;
            case 0x137CF4u: goto label_137cf4;
            case 0x137D04u: goto label_137d04;
            case 0x137D14u: goto label_137d14;
            case 0x137D28u: goto label_137d28;
            case 0x137D30u: goto label_137d30;
            case 0x137D58u: goto label_137d58;
            case 0x137D5Cu: goto label_137d5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137D6Cu;
    // 0x137d6c: 0x0  nop
    ctx->pc = 0x137d6cu;
    // NOP
    // 0x137d70: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137d70u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137d74: 0x3e00008  jr          $ra
    ctx->pc = 0x137D74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137D74u;
            // 0x137d78: 0x8c62bbc4  lw          $v0, -0x443C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294949828)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137BF0u: goto label_137bf0;
            case 0x137BF8u: goto label_137bf8;
            case 0x137C10u: goto label_137c10;
            case 0x137C18u: goto label_137c18;
            case 0x137C1Cu: goto label_137c1c;
            case 0x137C38u: goto label_137c38;
            case 0x137C4Cu: goto label_137c4c;
            case 0x137C58u: goto label_137c58;
            case 0x137C70u: goto label_137c70;
            case 0x137C78u: goto label_137c78;
            case 0x137C88u: goto label_137c88;
            case 0x137C94u: goto label_137c94;
            case 0x137CC0u: goto label_137cc0;
            case 0x137CDCu: goto label_137cdc;
            case 0x137CF4u: goto label_137cf4;
            case 0x137D04u: goto label_137d04;
            case 0x137D14u: goto label_137d14;
            case 0x137D28u: goto label_137d28;
            case 0x137D30u: goto label_137d30;
            case 0x137D58u: goto label_137d58;
            case 0x137D5Cu: goto label_137d5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137D7Cu;
    // 0x137d7c: 0x0  nop
    ctx->pc = 0x137d7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
