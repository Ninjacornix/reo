#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1B60
// Address: 0x1c1b60 - 0x1c1c20
void sub_001C1B60_0x1c1b60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1B60_0x1c1b60");
#endif

    switch (ctx->pc) {
        case 0x1c1b88u: goto label_1c1b88;
        case 0x1c1ba4u: goto label_1c1ba4;
        case 0x1c1bc8u: goto label_1c1bc8;
        case 0x1c1bd0u: goto label_1c1bd0;
        case 0x1c1be8u: goto label_1c1be8;
        case 0x1c1bf0u: goto label_1c1bf0;
        default: break;
    }

    ctx->pc = 0x1c1b60u;

label_1c1b60:
    // 0x1c1b60: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1c1b60u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1b64: 0x90620003  lbu         $v0, 0x3($v1)
    ctx->pc = 0x1c1b64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 3)));
    // 0x1c1b68: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C1B68u;
    {
        const bool branch_taken_0x1c1b68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1B6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1B68u;
            // 0x1c1b6c: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1b68) {
            ctx->pc = 0x1C1B7Cu;
            goto label_1c1b7c;
        }
    }
    ctx->pc = 0x1C1B70u;
    // 0x1c1b70: 0x24020017  addiu       $v0, $zero, 0x17
    ctx->pc = 0x1c1b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x1c1b74: 0x80706a2  j           func_1C1A88
    ctx->pc = 0x1C1B74u;
    ctx->pc = 0x1C1B78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1B74u;
            // 0x1c1b78: 0xa0620003  sb          $v0, 0x3($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1A88u;
    if (runtime->hasFunction(0x1C1A88u)) {
        auto targetFn = runtime->lookupFunction(0x1C1A88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C1A88_0x1c1a88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C1B7Cu;
label_1c1b7c:
    // 0x1c1b7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1B7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1B7Cu;
            // 0x1c1b80: 0xa0620003  sb          $v0, 0x3($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1B60u: goto label_1c1b60;
            case 0x1C1B7Cu: goto label_1c1b7c;
            case 0x1C1B88u: goto label_1c1b88;
            case 0x1C1BA4u: goto label_1c1ba4;
            case 0x1C1BC8u: goto label_1c1bc8;
            case 0x1C1BD0u: goto label_1c1bd0;
            case 0x1C1BE8u: goto label_1c1be8;
            case 0x1C1BF0u: goto label_1c1bf0;
            case 0x1C1BFCu: goto label_1c1bfc;
            case 0x1C1C00u: goto label_1c1c00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1B84u;
    // 0x1c1b84: 0x0  nop
    ctx->pc = 0x1c1b84u;
    // NOP
label_1c1b88:
    // 0x1c1b88: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c1b88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c1b8c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1c1b8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1c1b90: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1c1b90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1c1b94: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c1b94u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1b98: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c1b98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c1b9c: 0xc070640  jal         func_1C1900
    ctx->pc = 0x1C1B9Cu;
    SET_GPR_U32(ctx, 31, 0x1C1BA4u);
    ctx->pc = 0x1C1BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1B9Cu;
            // 0x1c1ba0: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1900u;
    if (runtime->hasFunction(0x1C1900u)) {
        auto targetFn = runtime->lookupFunction(0x1C1900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1BA4u; }
        if (ctx->pc != 0x1C1BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1900_0x1c1900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1BA4u; }
        if (ctx->pc != 0x1C1BA4u) { return; }
    }
    ctx->pc = 0x1C1BA4u;
label_1c1ba4:
    // 0x1c1ba4: 0x92220002  lbu         $v0, 0x2($s1)
    ctx->pc = 0x1c1ba4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1c1ba8: 0x508021  addu        $s0, $v0, $s0
    ctx->pc = 0x1c1ba8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1c1bac: 0x602000e  bltzl       $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x1C1BACu;
    {
        const bool branch_taken_0x1c1bac = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x1c1bac) {
            ctx->pc = 0x1C1BB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1BACu;
            // 0x1c1bb0: 0x2610003c  addiu       $s0, $s0, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 60));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1C1BE8u;
            goto label_1c1be8;
        }
    }
    ctx->pc = 0x1C1BB4u;
    // 0x1c1bb4: 0x2a02003c  slti        $v0, $s0, 0x3C
    ctx->pc = 0x1c1bb4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)60) ? 1 : 0);
    // 0x1c1bb8: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C1BB8u;
    {
        const bool branch_taken_0x1c1bb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c1bb8) {
            ctx->pc = 0x1C1BBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1BB8u;
            // 0x1c1bbc: 0xa2300002  sb          $s0, 0x2($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1C1BFCu;
            goto label_1c1bfc;
        }
    }
    ctx->pc = 0x1C1BC0u;
    // 0x1c1bc0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c1bc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1bc4: 0x0  nop
    ctx->pc = 0x1c1bc4u;
    // NOP
label_1c1bc8:
    // 0x1c1bc8: 0xc0706cc  jal         func_1C1B30
    ctx->pc = 0x1C1BC8u;
    SET_GPR_U32(ctx, 31, 0x1C1BD0u);
    ctx->pc = 0x1C1BCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1BC8u;
            // 0x1c1bcc: 0x2610ffc4  addiu       $s0, $s0, -0x3C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967236));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1B30u;
    if (runtime->hasFunction(0x1C1B30u)) {
        auto targetFn = runtime->lookupFunction(0x1C1B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1BD0u; }
        if (ctx->pc != 0x1C1BD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1B30_0x1c1b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1BD0u; }
        if (ctx->pc != 0x1C1BD0u) { return; }
    }
    ctx->pc = 0x1C1BD0u;
label_1c1bd0:
    // 0x1c1bd0: 0x2a02003c  slti        $v0, $s0, 0x3C
    ctx->pc = 0x1c1bd0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)60) ? 1 : 0);
    // 0x1c1bd4: 0x1040fffc  beqz        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x1C1BD4u;
    {
        const bool branch_taken_0x1c1bd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1BD4u;
            // 0x1c1bd8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1bd4) {
            ctx->pc = 0x1C1BC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c1bc8;
        }
    }
    ctx->pc = 0x1C1BDCu;
    // 0x1c1bdc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C1BDCu;
    {
        const bool branch_taken_0x1c1bdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1BDCu;
            // 0x1c1be0: 0xa2300002  sb          $s0, 0x2($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1bdc) {
            ctx->pc = 0x1C1C00u;
            goto label_1c1c00;
        }
    }
    ctx->pc = 0x1C1BE4u;
    // 0x1c1be4: 0x0  nop
    ctx->pc = 0x1c1be4u;
    // NOP
label_1c1be8:
    // 0x1c1be8: 0xc0706d8  jal         func_1C1B60
    ctx->pc = 0x1C1BE8u;
    SET_GPR_U32(ctx, 31, 0x1C1BF0u);
    ctx->pc = 0x1C1BECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1BE8u;
            // 0x1c1bec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1B60u;
    goto label_1c1b60;
    ctx->pc = 0x1C1BF0u;
label_1c1bf0:
    // 0x1c1bf0: 0x602fffd  bltzl       $s0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x1C1BF0u;
    {
        const bool branch_taken_0x1c1bf0 = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x1c1bf0) {
            ctx->pc = 0x1C1BF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1BF0u;
            // 0x1c1bf4: 0x2610003c  addiu       $s0, $s0, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 60));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1C1BE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c1be8;
        }
    }
    ctx->pc = 0x1C1BF8u;
    // 0x1c1bf8: 0xa2300002  sb          $s0, 0x2($s1)
    ctx->pc = 0x1c1bf8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 16));
label_1c1bfc:
    // 0x1c1bfc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c1bfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1c1c00:
    // 0x1c1c00: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c1c00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c1c04: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1c1c04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1c08: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1c1c08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1c0c: 0x807065a  j           func_1C1968
    ctx->pc = 0x1C1C0Cu;
    ctx->pc = 0x1C1C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1C0Cu;
            // 0x1c1c10: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1968u;
    if (runtime->hasFunction(0x1C1968u)) {
        auto targetFn = runtime->lookupFunction(0x1C1968u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C1968_0x1c1968(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C1C14u;
    // 0x1c1c14: 0x0  nop
    ctx->pc = 0x1c1c14u;
    // NOP
    // 0x1c1c18: 0x80706e2  j           func_1C1B88
    ctx->pc = 0x1C1C18u;
    ctx->pc = 0x1C1C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1C18u;
            // 0x1c1c1c: 0x2405fde4  addiu       $a1, $zero, -0x21C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966756));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1B88u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1c1b88;
    ctx->pc = 0x1C1C20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
