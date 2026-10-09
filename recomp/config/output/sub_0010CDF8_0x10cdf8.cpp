#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010CDF8
// Address: 0x10cdf8 - 0x10cee0
void sub_0010CDF8_0x10cdf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010CDF8_0x10cdf8");
#endif

    switch (ctx->pc) {
        case 0x10ce34u: goto label_10ce34;
        case 0x10ce58u: goto label_10ce58;
        case 0x10ce90u: goto label_10ce90;
        case 0x10ceb0u: goto label_10ceb0;
        default: break;
    }

    ctx->pc = 0x10cdf8u;

    // 0x10cdf8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x10cdf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x10cdfc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x10cdfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x10ce00: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x10ce00u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ce04: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10ce04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10ce08: 0x26420040  addiu       $v0, $s2, 0x40
    ctx->pc = 0x10ce08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 64));
    // 0x10ce0c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10ce0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10ce10: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x10ce10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x10ce14: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x10ce14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x10ce18: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x10ce18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x10ce1c: 0x8e450030  lw          $a1, 0x30($s2)
    ctx->pc = 0x10ce1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x10ce20: 0x54a20017  bnel        $a1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x10CE20u;
    {
        const bool branch_taken_0x10ce20 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x10ce20) {
            ctx->pc = 0x10CE24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10CE20u;
            // 0x10ce24: 0x8e530034  lw          $s3, 0x34($s2) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10CE80u;
            goto label_10ce80;
        }
    }
    ctx->pc = 0x10CE28u;
    // 0x10ce28: 0x8e440054  lw          $a0, 0x54($s2)
    ctx->pc = 0x10ce28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x10ce2c: 0xc041c76  jal         func_1071D8
    ctx->pc = 0x10CE2Cu;
    SET_GPR_U32(ctx, 31, 0x10CE34u);
    ctx->pc = 0x10CE30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10CE2Cu;
            // 0x10ce30: 0x24050400  addiu       $a1, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CE34u; }
        if (ctx->pc != 0x10CE34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001071D8_0x1071d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CE34u; }
        if (ctx->pc != 0x10CE34u) { return; }
    }
    ctx->pc = 0x10CE34u;
label_10ce34:
    // 0x10ce34: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10ce34u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ce38: 0x12200021  beqz        $s1, . + 4 + (0x21 << 2)
    ctx->pc = 0x10CE38u;
    {
        const bool branch_taken_0x10ce38 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CE38u;
            // 0x10ce3c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ce38) {
            ctx->pc = 0x10CEC0u;
            goto label_10cec0;
        }
    }
    ctx->pc = 0x10CE40u;
    // 0x10ce40: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x10ce40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x10ce44: 0xae510030  sw          $s1, 0x30($s2)
    ctx->pc = 0x10ce44u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 17));
    // 0x10ce48: 0xae420034  sw          $v0, 0x34($s2)
    ctx->pc = 0x10ce48u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 2));
    // 0x10ce4c: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x10ce4cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x10ce50: 0x263103fd  addiu       $s1, $s1, 0x3FD
    ctx->pc = 0x10ce50u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1021));
    // 0x10ce54: 0x26440042  addiu       $a0, $s2, 0x42
    ctx->pc = 0x10ce54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 66));
label_10ce58:
    // 0x10ce58: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x10ce58u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10ce5c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x10ce5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x10ce60: 0x2331021  addu        $v0, $s1, $s3
    ctx->pc = 0x10ce60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x10ce64: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x10ce64u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x10ce68: 0x0  nop
    ctx->pc = 0x10ce68u;
    // NOP
    // 0x10ce6c: 0x661fffa  bgez        $s3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10CE6Cu;
    {
        const bool branch_taken_0x10ce6c = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x10CE70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CE6Cu;
            // 0x10ce70: 0xa0430000  sb          $v1, 0x0($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ce6c) {
            ctx->pc = 0x10CE58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ce58;
        }
    }
    ctx->pc = 0x10CE74u;
    // 0x10ce74: 0xae510000  sw          $s1, 0x0($s2)
    ctx->pc = 0x10ce74u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    // 0x10ce78: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x10CE78u;
    {
        const bool branch_taken_0x10ce78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CE7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CE78u;
            // 0x10ce7c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ce78) {
            ctx->pc = 0x10CEC0u;
            goto label_10cec0;
        }
    }
    ctx->pc = 0x10CE80u;
label_10ce80:
    // 0x10ce80: 0x8e440054  lw          $a0, 0x54($s2)
    ctx->pc = 0x10ce80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x10ce84: 0x13a040  sll         $s4, $s3, 1
    ctx->pc = 0x10ce84u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
    // 0x10ce88: 0xc04269e  jal         func_109A78
    ctx->pc = 0x10CE88u;
    SET_GPR_U32(ctx, 31, 0x10CE90u);
    ctx->pc = 0x10CE8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10CE88u;
            // 0x10ce8c: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x109A78u;
    if (runtime->hasFunction(0x109A78u)) {
        auto targetFn = runtime->lookupFunction(0x109A78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CE90u; }
        if (ctx->pc != 0x10CE90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00109A78_0x109a78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CE90u; }
        if (ctx->pc != 0x10CE90u) { return; }
    }
    ctx->pc = 0x10CE90u;
label_10ce90:
    // 0x10ce90: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10ce90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ce94: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x10CE94u;
    {
        const bool branch_taken_0x10ce94 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CE98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CE94u;
            // 0x10ce98: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ce94) {
            ctx->pc = 0x10CEC0u;
            goto label_10cec0;
        }
    }
    ctx->pc = 0x10CE9Cu;
    // 0x10ce9c: 0x2338021  addu        $s0, $s1, $s3
    ctx->pc = 0x10ce9cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 19)));
    // 0x10cea0: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x10cea0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cea4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10cea4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cea8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x10CEA8u;
    SET_GPR_U32(ctx, 31, 0x10CEB0u);
    ctx->pc = 0x10CEACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10CEA8u;
            // 0x10ceac: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CEB0u; }
        if (ctx->pc != 0x10CEB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CEB0u; }
        if (ctx->pc != 0x10CEB0u) { return; }
    }
    ctx->pc = 0x10CEB0u;
label_10ceb0:
    // 0x10ceb0: 0xae500000  sw          $s0, 0x0($s2)
    ctx->pc = 0x10ceb0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 16));
    // 0x10ceb4: 0xae540034  sw          $s4, 0x34($s2)
    ctx->pc = 0x10ceb4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 20));
    // 0x10ceb8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10ceb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cebc: 0xae510030  sw          $s1, 0x30($s2)
    ctx->pc = 0x10cebcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 17));
label_10cec0:
    // 0x10cec0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10cec0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10cec4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10cec4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10cec8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x10cec8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10cecc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x10ceccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10ced0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x10ced0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10ced4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x10ced4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x10ced8: 0x3e00008  jr          $ra
    ctx->pc = 0x10CED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10CEDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CED8u;
            // 0x10cedc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10CE34u: goto label_10ce34;
            case 0x10CE58u: goto label_10ce58;
            case 0x10CE80u: goto label_10ce80;
            case 0x10CE90u: goto label_10ce90;
            case 0x10CEB0u: goto label_10ceb0;
            case 0x10CEC0u: goto label_10cec0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10CEE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
