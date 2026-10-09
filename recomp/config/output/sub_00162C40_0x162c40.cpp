#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162C40
// Address: 0x162c40 - 0x162d20
void sub_00162C40_0x162c40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162C40_0x162c40");
#endif

    switch (ctx->pc) {
        case 0x162cd4u: goto label_162cd4;
        case 0x162cecu: goto label_162cec;
        default: break;
    }

    ctx->pc = 0x162c40u;

    // 0x162c40: 0x3c020006  lui         $v0, 0x6
    ctx->pc = 0x162c40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)6 << 16));
    // 0x162c44: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x162c44u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x162c48: 0x24072000  addiu       $a3, $zero, 0x2000
    ctx->pc = 0x162c48u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x162c4c: 0x3442952c  ori         $v0, $v0, 0x952C
    ctx->pc = 0x162c4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)38188);
    // 0x162c50: 0x34633c68  ori         $v1, $v1, 0x3C68
    ctx->pc = 0x162c50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15464);
    // 0x162c54: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x162c54u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x162c58: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x162c58u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x162c5c: 0xacc70000  sw          $a3, 0x0($a2)
    ctx->pc = 0x162c5cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 7));
    // 0x162c60: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x162c60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x162c64: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x162c64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x162c68: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x162c68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x162c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x162C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162C6Cu;
            // 0x162c70: 0x471021  addu        $v0, $v0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162C90u: goto label_162c90;
            case 0x162CD4u: goto label_162cd4;
            case 0x162CECu: goto label_162cec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162C74u;
    // 0x162c74: 0x0  nop
    ctx->pc = 0x162c74u;
    // NOP
    // 0x162c78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162c78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162c7c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162c7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162c80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162c80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162c84: 0x8058b24  j           func_162C90
    ctx->pc = 0x162C84u;
    ctx->pc = 0x162C88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162C84u;
            // 0x162c88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162C90u;
    goto label_162c90;
    ctx->pc = 0x162C8Cu;
    // 0x162c8c: 0x0  nop
    ctx->pc = 0x162c8cu;
    // NOP
label_162c90:
    // 0x162c90: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x162c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x162c94: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x162c94u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162c98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162c9c: 0x249001ec  addiu       $s0, $a0, 0x1EC
    ctx->pc = 0x162c9cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 492));
    // 0x162ca0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x162ca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x162ca4: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x162ca4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162ca8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x162ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x162cac: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x162cacu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162cb0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x162cb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162cb4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x162cb4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162cb8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x162cb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x162cbc: 0x8c910040  lw          $s1, 0x40($a0)
    ctx->pc = 0x162cbcu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x162cc0: 0x8e050010  lw          $a1, 0x10($s0)
    ctx->pc = 0x162cc0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x162cc4: 0x8e12000c  lw          $s2, 0xC($s0)
    ctx->pc = 0x162cc4u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x162cc8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x162cc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162ccc: 0xc05a7fc  jal         func_169FF0
    ctx->pc = 0x162CCCu;
    SET_GPR_U32(ctx, 31, 0x162CD4u);
    ctx->pc = 0x162CD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162CCCu;
            // 0x162cd0: 0x24a500c0  addiu       $a1, $a1, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169FF0u;
    if (runtime->hasFunction(0x169FF0u)) {
        auto targetFn = runtime->lookupFunction(0x169FF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162CD4u; }
        if (ctx->pc != 0x162CD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169FF0_0x169ff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162CD4u; }
        if (ctx->pc != 0x162CD4u) { return; }
    }
    ctx->pc = 0x162CD4u;
label_162cd4:
    // 0x162cd4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x162cd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162cd8: 0x266500c0  addiu       $a1, $s3, 0xC0
    ctx->pc = 0x162cd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 192));
    // 0x162cdc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x162cdcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162ce0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x162ce0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162ce4: 0xc05a7fc  jal         func_169FF0
    ctx->pc = 0x162CE4u;
    SET_GPR_U32(ctx, 31, 0x162CECu);
    ctx->pc = 0x162CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162CE4u;
            // 0x162ce8: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169FF0u;
    if (runtime->hasFunction(0x169FF0u)) {
        auto targetFn = runtime->lookupFunction(0x169FF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162CECu; }
        if (ctx->pc != 0x162CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169FF0_0x169ff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162CECu; }
        if (ctx->pc != 0x162CECu) { return; }
    }
    ctx->pc = 0x162CECu;
label_162cec:
    // 0x162cec: 0xae130010  sw          $s3, 0x10($s0)
    ctx->pc = 0x162cecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 19));
    // 0x162cf0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162cf0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162cf4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162cf4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162cf8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x162cf8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162cfc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x162cfcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x162d00: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x162d00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x162d04: 0x3e00008  jr          $ra
    ctx->pc = 0x162D04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162D04u;
            // 0x162d08: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162C90u: goto label_162c90;
            case 0x162CD4u: goto label_162cd4;
            case 0x162CECu: goto label_162cec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162D0Cu;
    // 0x162d0c: 0x0  nop
    ctx->pc = 0x162d0cu;
    // NOP
    // 0x162d10: 0x3e00008  jr          $ra
    ctx->pc = 0x162D10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162D10u;
            // 0x162d14: 0x8c8201f8  lw          $v0, 0x1F8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 504)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162C90u: goto label_162c90;
            case 0x162CD4u: goto label_162cd4;
            case 0x162CECu: goto label_162cec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162D18u;
    // 0x162d18: 0x3e00008  jr          $ra
    ctx->pc = 0x162D18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162D18u;
            // 0x162d1c: 0x8c820200  lw          $v0, 0x200($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 512)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162C90u: goto label_162c90;
            case 0x162CD4u: goto label_162cd4;
            case 0x162CECu: goto label_162cec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162D20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
