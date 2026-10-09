#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011A9D8
// Address: 0x11a9d8 - 0x11abc8
void sub_0011A9D8_0x11a9d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011A9D8_0x11a9d8");
#endif

    switch (ctx->pc) {
        case 0x11aa14u: goto label_11aa14;
        case 0x11aa2cu: goto label_11aa2c;
        case 0x11aa50u: goto label_11aa50;
        case 0x11aab0u: goto label_11aab0;
        case 0x11aafcu: goto label_11aafc;
        case 0x11ab20u: goto label_11ab20;
        case 0x11ab48u: goto label_11ab48;
        case 0x11ab58u: goto label_11ab58;
        case 0x11ab60u: goto label_11ab60;
        case 0x11ab74u: goto label_11ab74;
        case 0x11ab84u: goto label_11ab84;
        case 0x11ab94u: goto label_11ab94;
        case 0x11ab9cu: goto label_11ab9c;
        default: break;
    }

    ctx->pc = 0x11a9d8u;

    // 0x11a9d8: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x11a9d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x11a9dc: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11a9dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11a9e0: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11a9e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11a9e4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11a9e4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a9e8: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11a9e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11a9ec: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x11a9ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a9f0: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11a9f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11a9f4: 0x24040011  addiu       $a0, $zero, 0x11
    ctx->pc = 0x11a9f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x11a9f8: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x11a9f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x11a9fc: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11a9fcu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11aa00: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11aa00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11aa04: 0x26d2ca40  addiu       $s2, $s6, -0x35C0
    ctx->pc = 0x11aa04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x11aa08: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11aa08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11aa0c: 0xc04619c  jal         func_118670
    ctx->pc = 0x11AA0Cu;
    SET_GPR_U32(ctx, 31, 0x11AA14u);
    ctx->pc = 0x11AA10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AA0Cu;
            // 0x11aa10: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AA14u; }
        if (ctx->pc != 0x11AA14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AA14u; }
        if (ctx->pc != 0x11AA14u) { return; }
    }
    ctx->pc = 0x11AA14u;
label_11aa14:
    // 0x11aa14: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11aa14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11aa18: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x11aa18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x11aa1c: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11AA1Cu;
    {
        const bool branch_taken_0x11aa1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11aa1c) {
            ctx->pc = 0x11AA20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AA1Cu;
            // 0x11aa20: 0x92220000  lbu         $v0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AA30u;
            goto label_11aa30;
        }
    }
    ctx->pc = 0x11AA24u;
    // 0x11aa24: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11AA24u;
    SET_GPR_U32(ctx, 31, 0x11AA2Cu);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AA2Cu; }
        if (ctx->pc != 0x11AA2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AA2Cu; }
        if (ctx->pc != 0x11AA2Cu) { return; }
    }
    ctx->pc = 0x11AA2Cu;
label_11aa2c:
    // 0x11aa2c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11aa2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_11aa30:
    // 0x11aa30: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11aa30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11aa34: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11aa34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11aa38: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x11AA38u;
    {
        const bool branch_taken_0x11aa38 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AA3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AA38u;
            // 0x11aa3c: 0xa242000c  sb          $v0, 0xC($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11aa38) {
            ctx->pc = 0x11AA7Cu;
            goto label_11aa7c;
        }
    }
    ctx->pc = 0x11AA40u;
    // 0x11aa40: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11aa40u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11aa44: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11aa44u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11aa48: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11aa48u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11aa4c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11aa4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11aa50:
    // 0x11aa50: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11aa50u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11aa54: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x11AA54u;
    {
        const bool branch_taken_0x11aa54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AA58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AA54u;
            // 0x11aa58: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11aa54) {
            ctx->pc = 0x11AA88u;
            goto label_11aa88;
        }
    }
    ctx->pc = 0x11AA5Cu;
    // 0x11aa5c: 0x2452021  addu        $a0, $s2, $a1
    ctx->pc = 0x11aa5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x11aa60: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11aa60u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11aa64: 0xa083000c  sb          $v1, 0xC($a0)
    ctx->pc = 0x11aa64u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 12), (uint8_t)GPR_U32(ctx, 3));
    // 0x11aa68: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11aa68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11aa6c: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11AA6Cu;
    {
        const bool branch_taken_0x11aa6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11aa6c) {
            ctx->pc = 0x11AA70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AA6Cu;
            // 0x11aa70: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AA50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11aa50;
        }
    }
    ctx->pc = 0x11AA74u;
    // 0x11aa74: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11AA74u;
    {
        const bool branch_taken_0x11aa74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AA78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AA74u;
            // 0x11aa78: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11aa74) {
            ctx->pc = 0x11AA8Cu;
            goto label_11aa8c;
        }
    }
    ctx->pc = 0x11AA7Cu;
label_11aa7c:
    // 0x11aa7c: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11aa7cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11aa80: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11aa80u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11aa84: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11aa84u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11aa88:
    // 0x11aa88: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11aa88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11aa8c:
    // 0x11aa8c: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11AA8Cu;
    {
        const bool branch_taken_0x11aa8c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11aa8c) {
            ctx->pc = 0x11AA90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AA8Cu;
            // 0x11aa90: 0xa240040b  sb          $zero, 0x40B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1035), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AA94u;
            goto label_11aa94;
        }
    }
    ctx->pc = 0x11AA94u;
label_11aa94:
    // 0x11aa94: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x11aa94u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11aa98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11aa98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11aa9c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11aa9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11aaa0: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x11AAA0u;
    {
        const bool branch_taken_0x11aaa0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AAA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AAA0u;
            // 0x11aaa4: 0xa242040c  sb          $v0, 0x40C($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1036), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11aaa0) {
            ctx->pc = 0x11AAD4u;
            goto label_11aad4;
        }
    }
    ctx->pc = 0x11AAA8u;
    // 0x11aaa8: 0x2646040c  addiu       $a2, $s2, 0x40C
    ctx->pc = 0x11aaa8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 1036));
    // 0x11aaac: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11aaacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11aab0:
    // 0x11aab0: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11aab0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11aab4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11AAB4u;
    {
        const bool branch_taken_0x11aab4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AAB4u;
            // 0x11aab8: 0x2051021  addu        $v0, $s0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11aab4) {
            ctx->pc = 0x11AAD4u;
            goto label_11aad4;
        }
    }
    ctx->pc = 0x11AABCu;
    // 0x11aabc: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x11aabcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x11aac0: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11aac0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11aac4: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11aac4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11aac8: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11aac8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11aacc: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11AACCu;
    {
        const bool branch_taken_0x11aacc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11aacc) {
            ctx->pc = 0x11AAD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AACCu;
            // 0x11aad0: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AAB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11aab0;
        }
    }
    ctx->pc = 0x11AAD4u;
label_11aad4:
    // 0x11aad4: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11aad4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x11aad8: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11AAD8u;
    {
        const bool branch_taken_0x11aad8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11aad8) {
            ctx->pc = 0x11AADCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AAD8u;
            // 0x11aadc: 0xa240080b  sb          $zero, 0x80B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 2059), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AAE0u;
            goto label_11aae0;
        }
    }
    ctx->pc = 0x11AAE0u;
label_11aae0:
    // 0x11aae0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11aae0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11aae4: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11aae4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11aae8: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11aae8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11aaec: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11aaecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11aaf0: 0xafa00024  sw          $zero, 0x24($sp)
    ctx->pc = 0x11aaf0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0x11aaf4: 0xc045188  jal         func_114620
    ctx->pc = 0x11AAF4u;
    SET_GPR_U32(ctx, 31, 0x11AAFCu);
    ctx->pc = 0x11AAF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AAF4u;
            // 0x11aaf8: 0x26d0ca40  addiu       $s0, $s6, -0x35C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AAFCu; }
        if (ctx->pc != 0x11AAFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AAFCu; }
        if (ctx->pc != 0x11AAFCu) { return; }
    }
    ctx->pc = 0x11AAFCu;
label_11aafc:
    // 0x11aafc: 0x2694d680  addiu       $s4, $s4, -0x2980
    ctx->pc = 0x11aafcu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
    // 0x11ab00: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11ab00u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ab04: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11ab04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ab08: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11ab08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11ab0c: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x11ab0cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x11ab10: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x11ab10u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x11ab14: 0x2405080c  addiu       $a1, $zero, 0x80C
    ctx->pc = 0x11ab14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2060));
    // 0x11ab18: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x11AB18u;
    SET_GPR_U32(ctx, 31, 0x11AB20u);
    ctx->pc = 0x11AB1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB18u;
            // 0x11ab1c: 0xae510000  sw          $s1, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB20u; }
        if (ctx->pc != 0x11AB20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB20u; }
        if (ctx->pc != 0x11AB20u) { return; }
    }
    ctx->pc = 0x11AB20u;
label_11ab20:
    // 0x11ab20: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x11ab20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x11ab24: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11ab24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ab28: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11ab28u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11ab2c: 0x24050011  addiu       $a1, $zero, 0x11
    ctx->pc = 0x11ab2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x11ab30: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11ab30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ab34: 0x2408080c  addiu       $t0, $zero, 0x80C
    ctx->pc = 0x11ab34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2060));
    // 0x11ab38: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x11ab38u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ab3c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11ab3cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11ab40: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11AB40u;
    SET_GPR_U32(ctx, 31, 0x11AB48u);
    ctx->pc = 0x11AB44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB40u;
            // 0x11ab44: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB48u; }
        if (ctx->pc != 0x11AB48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB48u; }
        if (ctx->pc != 0x11AB48u) { return; }
    }
    ctx->pc = 0x11AB48u;
label_11ab48:
    // 0x11ab48: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11AB48u;
    {
        const bool branch_taken_0x11ab48 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11AB4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB48u;
            // 0x11ab4c: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ab48) {
            ctx->pc = 0x11AB68u;
            goto label_11ab68;
        }
    }
    ctx->pc = 0x11AB50u;
    // 0x11ab50: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AB50u;
    SET_GPR_U32(ctx, 31, 0x11AB58u);
    ctx->pc = 0x11AB54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB50u;
            // 0x11ab54: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB58u; }
        if (ctx->pc != 0x11AB58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB58u; }
        if (ctx->pc != 0x11AB58u) { return; }
    }
    ctx->pc = 0x11AB58u;
label_11ab58:
    // 0x11ab58: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11AB58u;
    SET_GPR_U32(ctx, 31, 0x11AB60u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB60u; }
        if (ctx->pc != 0x11AB60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB60u; }
        if (ctx->pc != 0x11AB60u) { return; }
    }
    ctx->pc = 0x11AB60u;
label_11ab60:
    // 0x11ab60: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11AB60u;
    {
        const bool branch_taken_0x11ab60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB60u;
            // 0x11ab64: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ab60) {
            ctx->pc = 0x11ABA0u;
            goto label_11aba0;
        }
    }
    ctx->pc = 0x11AB68u;
label_11ab68:
    // 0x11ab68: 0x2821025  or          $v0, $s4, $v0
    ctx->pc = 0x11ab68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x11ab6c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11AB6Cu;
    SET_GPR_U32(ctx, 31, 0x11AB74u);
    ctx->pc = 0x11AB70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB6Cu;
            // 0x11ab70: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB74u; }
        if (ctx->pc != 0x11AB74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB74u; }
        if (ctx->pc != 0x11AB74u) { return; }
    }
    ctx->pc = 0x11AB74u;
label_11ab74:
    // 0x11ab74: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11AB74u;
    {
        const bool branch_taken_0x11ab74 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ab74) {
            ctx->pc = 0x11AB8Cu;
            goto label_11ab8c;
        }
    }
    ctx->pc = 0x11AB7Cu;
    // 0x11ab7c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AB7Cu;
    SET_GPR_U32(ctx, 31, 0x11AB84u);
    ctx->pc = 0x11AB80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB7Cu;
            // 0x11ab80: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB84u; }
        if (ctx->pc != 0x11AB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB84u; }
        if (ctx->pc != 0x11AB84u) { return; }
    }
    ctx->pc = 0x11AB84u;
label_11ab84:
    // 0x11ab84: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11AB84u;
    {
        const bool branch_taken_0x11ab84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AB88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB84u;
            // 0x11ab88: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ab84) {
            ctx->pc = 0x11ABA0u;
            goto label_11aba0;
        }
    }
    ctx->pc = 0x11AB8Cu;
label_11ab8c:
    // 0x11ab8c: 0xc045198  jal         func_114660
    ctx->pc = 0x11AB8Cu;
    SET_GPR_U32(ctx, 31, 0x11AB94u);
    ctx->pc = 0x11AB90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB8Cu;
            // 0x11ab90: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB94u; }
        if (ctx->pc != 0x11AB94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB94u; }
        if (ctx->pc != 0x11AB94u) { return; }
    }
    ctx->pc = 0x11AB94u;
label_11ab94:
    // 0x11ab94: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AB94u;
    SET_GPR_U32(ctx, 31, 0x11AB9Cu);
    ctx->pc = 0x11AB98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AB94u;
            // 0x11ab98: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB9Cu; }
        if (ctx->pc != 0x11AB9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AB9Cu; }
        if (ctx->pc != 0x11AB9Cu) { return; }
    }
    ctx->pc = 0x11AB9Cu;
label_11ab9c:
    // 0x11ab9c: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11ab9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11aba0:
    // 0x11aba0: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x11aba0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11aba4: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11aba4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11aba8: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11aba8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11abac: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11abacu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11abb0: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11abb0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11abb4: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11abb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11abb8: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11abb8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11abbc: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11abbcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11abc0: 0x3e00008  jr          $ra
    ctx->pc = 0x11ABC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11ABC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ABC0u;
            // 0x11abc4: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11AA14u: goto label_11aa14;
            case 0x11AA2Cu: goto label_11aa2c;
            case 0x11AA30u: goto label_11aa30;
            case 0x11AA50u: goto label_11aa50;
            case 0x11AA7Cu: goto label_11aa7c;
            case 0x11AA88u: goto label_11aa88;
            case 0x11AA8Cu: goto label_11aa8c;
            case 0x11AA94u: goto label_11aa94;
            case 0x11AAB0u: goto label_11aab0;
            case 0x11AAD4u: goto label_11aad4;
            case 0x11AAE0u: goto label_11aae0;
            case 0x11AAFCu: goto label_11aafc;
            case 0x11AB20u: goto label_11ab20;
            case 0x11AB48u: goto label_11ab48;
            case 0x11AB58u: goto label_11ab58;
            case 0x11AB60u: goto label_11ab60;
            case 0x11AB68u: goto label_11ab68;
            case 0x11AB74u: goto label_11ab74;
            case 0x11AB84u: goto label_11ab84;
            case 0x11AB8Cu: goto label_11ab8c;
            case 0x11AB94u: goto label_11ab94;
            case 0x11AB9Cu: goto label_11ab9c;
            case 0x11ABA0u: goto label_11aba0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11ABC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
