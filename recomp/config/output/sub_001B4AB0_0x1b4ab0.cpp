#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4AB0
// Address: 0x1b4ab0 - 0x1b4c50
void sub_001B4AB0_0x1b4ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4AB0_0x1b4ab0");
#endif

    switch (ctx->pc) {
        case 0x1b4b4cu: goto label_1b4b4c;
        case 0x1b4b78u: goto label_1b4b78;
        case 0x1b4b8cu: goto label_1b4b8c;
        case 0x1b4bc8u: goto label_1b4bc8;
        case 0x1b4c04u: goto label_1b4c04;
        case 0x1b4c20u: goto label_1b4c20;
        case 0x1b4c28u: goto label_1b4c28;
        case 0x1b4c30u: goto label_1b4c30;
        default: break;
    }

    ctx->pc = 0x1b4ab0u;

    // 0x1b4ab0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b4ab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b4ab4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4ab4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4ab8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b4ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b4abc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1b4abcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b4ac0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b4ac0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b4ac4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b4ac4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4ac8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b4ac8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4acc: 0x902443c3  lbu         $a0, 0x43C3($at)
    ctx->pc = 0x1b4accu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17347)));
    // 0x1b4ad0: 0x14830002  bne         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B4AD0u;
    {
        const bool branch_taken_0x1b4ad0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b4ad0) {
            ctx->pc = 0x1B4ADCu;
            goto label_1b4adc;
        }
    }
    ctx->pc = 0x1B4AD8u;
    // 0x1b4ad8: 0x24110008  addiu       $s1, $zero, 0x8
    ctx->pc = 0x1b4ad8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_1b4adc:
    // 0x1b4adc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4adcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4ae0: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1b4ae0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1b4ae4: 0xa02043d6  sb          $zero, 0x43D6($at)
    ctx->pc = 0x1b4ae4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17366), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b4ae8: 0x2231824  and         $v1, $s1, $v1
    ctx->pc = 0x1b4ae8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & GPR_U64(ctx, 3));
    // 0x1b4aec: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4aecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4af0: 0x3282b  sltu        $a1, $zero, $v1
    ctx->pc = 0x1b4af0u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b4af4: 0x8c304460  lw          $s0, 0x4460($at)
    ctx->pc = 0x1b4af4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17504)));
    // 0x1b4af8: 0x11887c  dsll32      $s1, $s1, 1
    ctx->pc = 0x1b4af8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) << (32 + 1));
    // 0x1b4afc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b4afcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4b00: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4b00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4b04: 0x902443eb  lbu         $a0, 0x43EB($at)
    ctx->pc = 0x1b4b04u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17387)));
    // 0x1b4b08: 0x14830005  bne         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B4B08u;
    {
        const bool branch_taken_0x1b4b08 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B4B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4B08u;
            // 0x1b4b0c: 0x11887e  dsrl32      $s1, $s1, 1 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) >> (32 + 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4b08) {
            ctx->pc = 0x1B4B20u;
            goto label_1b4b20;
        }
    }
    ctx->pc = 0x1B4B10u;
    // 0x1b4b10: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b4b10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b4b14: 0x8c23aaf4  lw          $v1, -0x550C($at)
    ctx->pc = 0x1b4b14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945524)));
    // 0x1b4b18: 0x12230011  beq         $s1, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B4B18u;
    {
        const bool branch_taken_0x1b4b18 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b4b18) {
            ctx->pc = 0x1B4B60u;
            goto label_1b4b60;
        }
    }
    ctx->pc = 0x1B4B20u;
label_1b4b20:
    // 0x1b4b20: 0x14a0001a  bnez        $a1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1B4B20u;
    {
        const bool branch_taken_0x1b4b20 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b4b20) {
            ctx->pc = 0x1B4B8Cu;
            goto label_1b4b8c;
        }
    }
    ctx->pc = 0x1B4B28u;
    // 0x1b4b28: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b4b28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b4b2c: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1b4b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1b4b30: 0x24424770  addiu       $v0, $v0, 0x4770
    ctx->pc = 0x1b4b30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18288));
    // 0x1b4b34: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b4b34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4b38: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b4b38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b4b3c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1b4b3cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4b40: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1b4b40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b4b44: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1B4B44u;
    SET_GPR_U32(ctx, 31, 0x1B4B4Cu);
    ctx->pc = 0x1B4B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4B44u;
            // 0x1b4b48: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4B4Cu; }
        if (ctx->pc != 0x1B4B4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4B4Cu; }
        if (ctx->pc != 0x1B4B4Cu) { return; }
    }
    ctx->pc = 0x1B4B4Cu;
label_1b4b4c:
    // 0x1b4b4c: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B4B4Cu;
    {
        const bool branch_taken_0x1b4b4c = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1b4b4c) {
            ctx->pc = 0x1B4B60u;
            goto label_1b4b60;
        }
    }
    ctx->pc = 0x1B4B54u;
    // 0x1b4b54: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b4b54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4b58: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4b58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4b5c: 0xa02243eb  sb          $v0, 0x43EB($at)
    ctx->pc = 0x1b4b5cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17387), (uint8_t)GPR_U32(ctx, 2));
label_1b4b60:
    // 0x1b4b60: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4b60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4b64: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b4b64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4b68: 0x94274414  lhu         $a3, 0x4414($at)
    ctx->pc = 0x1b4b68u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17428)));
    // 0x1b4b6c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b4b6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4b70: 0xc06d350  jal         func_1B4D40
    ctx->pc = 0x1B4B70u;
    SET_GPR_U32(ctx, 31, 0x1B4B78u);
    ctx->pc = 0x1B4B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4B70u;
            // 0x1b4b74: 0x24060200  addiu       $a2, $zero, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B4D40u;
    if (runtime->hasFunction(0x1B4D40u)) {
        auto targetFn = runtime->lookupFunction(0x1B4D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4B78u; }
        if (ctx->pc != 0x1B4B78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4D40_0x1b4d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4B78u; }
        if (ctx->pc != 0x1B4B78u) { return; }
    }
    ctx->pc = 0x1B4B78u;
label_1b4b78:
    // 0x1b4b78: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b4b78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4b7c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4b7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4b80: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b4b80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4b84: 0xc06d588  jal         func_1B5620
    ctx->pc = 0x1B4B84u;
    SET_GPR_U32(ctx, 31, 0x1B4B8Cu);
    ctx->pc = 0x1B4B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4B84u;
            // 0x1b4b88: 0xa02243d6  sb          $v0, 0x43D6($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17366), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5620u;
    if (runtime->hasFunction(0x1B5620u)) {
        auto targetFn = runtime->lookupFunction(0x1B5620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4B8Cu; }
        if (ctx->pc != 0x1B4B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5620_0x1b5620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4B8Cu; }
        if (ctx->pc != 0x1B4B8Cu) { return; }
    }
    ctx->pc = 0x1B4B8Cu;
label_1b4b8c:
    // 0x1b4b8c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b4b8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b4b90: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b4b90u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4b94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4b94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4b98: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4B98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4B98u;
            // 0x1b4b9c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4ADCu: goto label_1b4adc;
            case 0x1B4B20u: goto label_1b4b20;
            case 0x1B4B4Cu: goto label_1b4b4c;
            case 0x1B4B60u: goto label_1b4b60;
            case 0x1B4B78u: goto label_1b4b78;
            case 0x1B4B8Cu: goto label_1b4b8c;
            case 0x1B4BC8u: goto label_1b4bc8;
            case 0x1B4C04u: goto label_1b4c04;
            case 0x1B4C20u: goto label_1b4c20;
            case 0x1B4C28u: goto label_1b4c28;
            case 0x1B4C30u: goto label_1b4c30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4BA0u;
    // 0x1b4ba0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b4ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b4ba4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b4ba4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b4ba8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b4ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b4bac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b4bacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b4bb0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b4bb0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4bb4: 0x8c22aa30  lw          $v0, -0x55D0($at)
    ctx->pc = 0x1b4bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945328)));
    // 0x1b4bb8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B4BB8u;
    {
        const bool branch_taken_0x1b4bb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4BB8u;
            // 0x1b4bbc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4bb8) {
            ctx->pc = 0x1B4BC8u;
            goto label_1b4bc8;
        }
    }
    ctx->pc = 0x1B4BC0u;
    // 0x1b4bc0: 0xc06d314  jal         func_1B4C50
    ctx->pc = 0x1B4BC0u;
    SET_GPR_U32(ctx, 31, 0x1B4BC8u);
    ctx->pc = 0x1B4C50u;
    if (runtime->hasFunction(0x1B4C50u)) {
        auto targetFn = runtime->lookupFunction(0x1B4C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4BC8u; }
        if (ctx->pc != 0x1B4BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4C50_0x1b4c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4BC8u; }
        if (ctx->pc != 0x1B4BC8u) { return; }
    }
    ctx->pc = 0x1B4BC8u;
label_1b4bc8:
    // 0x1b4bc8: 0x10807c  dsll32      $s0, $s0, 1
    ctx->pc = 0x1b4bc8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 1));
    // 0x1b4bcc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4bccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4bd0: 0x10807e  dsrl32      $s0, $s0, 1
    ctx->pc = 0x1b4bd0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 1));
    // 0x1b4bd4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b4bd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b4bd8: 0x8c28440c  lw          $t0, 0x440C($at)
    ctx->pc = 0x1b4bd8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1b4bdc: 0x24424770  addiu       $v0, $v0, 0x4770
    ctx->pc = 0x1b4bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18288));
    // 0x1b4be0: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b4be0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b4be4: 0x3c05000a  lui         $a1, 0xA
    ctx->pc = 0x1b4be4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)10 << 16));
    // 0x1b4be8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b4be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b4bec: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1b4becu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4bf0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1b4bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b4bf4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b4bf4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4bf8: 0x1058821  addu        $s1, $t0, $a1
    ctx->pc = 0x1b4bf8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1b4bfc: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1B4BFCu;
    SET_GPR_U32(ctx, 31, 0x1B4C04u);
    ctx->pc = 0x1B4C00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4BFCu;
            // 0x1b4c00: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C04u; }
        if (ctx->pc != 0x1B4C04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C04u; }
        if (ctx->pc != 0x1B4C04u) { return; }
    }
    ctx->pc = 0x1B4C04u;
label_1b4c04:
    // 0x1b4c04: 0x1840000a  blez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B4C04u;
    {
        const bool branch_taken_0x1b4c04 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1B4C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C04u;
            // 0x1b4c08: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4c04) {
            ctx->pc = 0x1B4C30u;
            goto label_1b4c30;
        }
    }
    ctx->pc = 0x1B4C0Cu;
    // 0x1b4c0c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b4c0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4c10: 0x94274414  lhu         $a3, 0x4414($at)
    ctx->pc = 0x1b4c10u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17428)));
    // 0x1b4c14: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1b4c14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4c18: 0xc06d404  jal         func_1B5010
    ctx->pc = 0x1B4C18u;
    SET_GPR_U32(ctx, 31, 0x1B4C20u);
    ctx->pc = 0x1B4C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C18u;
            // 0x1b4c1c: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5010u;
    if (runtime->hasFunction(0x1B5010u)) {
        auto targetFn = runtime->lookupFunction(0x1B5010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C20u; }
        if (ctx->pc != 0x1B4C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5010_0x1b5010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C20u; }
        if (ctx->pc != 0x1B4C20u) { return; }
    }
    ctx->pc = 0x1B4C20u;
label_1b4c20:
    // 0x1b4c20: 0xc06d568  jal         func_1B55A0
    ctx->pc = 0x1B4C20u;
    SET_GPR_U32(ctx, 31, 0x1B4C28u);
    ctx->pc = 0x1B55A0u;
    if (runtime->hasFunction(0x1B55A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C28u; }
        if (ctx->pc != 0x1B4C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55A0_0x1b55a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C28u; }
        if (ctx->pc != 0x1B4C28u) { return; }
    }
    ctx->pc = 0x1B4C28u;
label_1b4c28:
    // 0x1b4c28: 0xc06d588  jal         func_1B5620
    ctx->pc = 0x1B4C28u;
    SET_GPR_U32(ctx, 31, 0x1B4C30u);
    ctx->pc = 0x1B4C2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C28u;
            // 0x1b4c2c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5620u;
    if (runtime->hasFunction(0x1B5620u)) {
        auto targetFn = runtime->lookupFunction(0x1B5620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C30u; }
        if (ctx->pc != 0x1B4C30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5620_0x1b5620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C30u; }
        if (ctx->pc != 0x1B4C30u) { return; }
    }
    ctx->pc = 0x1B4C30u;
label_1b4c30:
    // 0x1b4c30: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b4c30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b4c34: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b4c34u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4c38: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4c38u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4c3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4C3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C3Cu;
            // 0x1b4c40: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4ADCu: goto label_1b4adc;
            case 0x1B4B20u: goto label_1b4b20;
            case 0x1B4B4Cu: goto label_1b4b4c;
            case 0x1B4B60u: goto label_1b4b60;
            case 0x1B4B78u: goto label_1b4b78;
            case 0x1B4B8Cu: goto label_1b4b8c;
            case 0x1B4BC8u: goto label_1b4bc8;
            case 0x1B4C04u: goto label_1b4c04;
            case 0x1B4C20u: goto label_1b4c20;
            case 0x1B4C28u: goto label_1b4c28;
            case 0x1B4C30u: goto label_1b4c30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4C44u;
    // 0x1b4c44: 0x0  nop
    ctx->pc = 0x1b4c44u;
    // NOP
    // 0x1b4c48: 0x0  nop
    ctx->pc = 0x1b4c48u;
    // NOP
    // 0x1b4c4c: 0x0  nop
    ctx->pc = 0x1b4c4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
