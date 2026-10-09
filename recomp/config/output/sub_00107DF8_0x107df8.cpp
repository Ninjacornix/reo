#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107DF8
// Address: 0x107df8 - 0x107ea0
void sub_00107DF8_0x107df8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107DF8_0x107df8");
#endif

    switch (ctx->pc) {
        case 0x107e24u: goto label_107e24;
        case 0x107e68u: goto label_107e68;
        default: break;
    }

    ctx->pc = 0x107df8u;

    // 0x107df8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x107df8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x107dfc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x107dfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x107e00: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x107e00u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107e04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x107e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x107e08: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x107e08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107e0c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x107e0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x107e10: 0x8e03004c  lw          $v1, 0x4C($s0)
    ctx->pc = 0x107e10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x107e14: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x107E14u;
    {
        const bool branch_taken_0x107e14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x107E18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107E14u;
            // 0x107e18: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107e14) {
            ctx->pc = 0x107E30u;
            goto label_107e30;
        }
    }
    ctx->pc = 0x107E1Cu;
    // 0x107e1c: 0xc040e4e  jal         func_103938
    ctx->pc = 0x107E1Cu;
    SET_GPR_U32(ctx, 31, 0x107E24u);
    ctx->pc = 0x107E20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x107E1Cu;
            // 0x107e20: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103938u;
    if (runtime->hasFunction(0x103938u)) {
        auto targetFn = runtime->lookupFunction(0x103938u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107E24u; }
        if (ctx->pc != 0x107E24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103938_0x103938(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107E24u; }
        if (ctx->pc != 0x107E24u) { return; }
    }
    ctx->pc = 0x107E24u;
label_107e24:
    // 0x107e24: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x107e24u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107e28: 0x10600017  beqz        $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x107E28u;
    {
        const bool branch_taken_0x107e28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x107E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107E28u;
            // 0x107e2c: 0xae03004c  sw          $v1, 0x4C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107e28) {
            ctx->pc = 0x107E88u;
            goto label_107e88;
        }
    }
    ctx->pc = 0x107E30u;
label_107e30:
    // 0x107e30: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x107e30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x107e34: 0x432021  addu        $a0, $v0, $v1
    ctx->pc = 0x107e34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x107e38: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x107e38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x107e3c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x107E3Cu;
    {
        const bool branch_taken_0x107e3c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x107E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107E3Cu;
            // 0x107e40: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107e3c) {
            ctx->pc = 0x107E50u;
            goto label_107e50;
        }
    }
    ctx->pc = 0x107E44u;
    // 0x107e44: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x107e44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x107e48: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x107E48u;
    {
        const bool branch_taken_0x107e48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107E48u;
            // 0x107e4c: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107e48) {
            ctx->pc = 0x107E7Cu;
            goto label_107e7c;
        }
    }
    ctx->pc = 0x107E50u;
label_107e50:
    // 0x107e50: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x107e50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107e54: 0x2228004  sllv        $s0, $v0, $s1
    ctx->pc = 0x107e54u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 17) & 0x1F));
    // 0x107e58: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x107e58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x107e5c: 0x103080  sll         $a2, $s0, 2
    ctx->pc = 0x107e5cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x107e60: 0xc040e4e  jal         func_103938
    ctx->pc = 0x107E60u;
    SET_GPR_U32(ctx, 31, 0x107E68u);
    ctx->pc = 0x107E64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x107E60u;
            // 0x107e64: 0x24c60014  addiu       $a2, $a2, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103938u;
    if (runtime->hasFunction(0x103938u)) {
        auto targetFn = runtime->lookupFunction(0x103938u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107E68u; }
        if (ctx->pc != 0x107E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103938_0x103938(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107E68u; }
        if (ctx->pc != 0x107E68u) { return; }
    }
    ctx->pc = 0x107E68u;
label_107e68:
    // 0x107e68: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x107e68u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107e6c: 0x50600007  beql        $v1, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x107E6Cu;
    {
        const bool branch_taken_0x107e6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x107e6c) {
            ctx->pc = 0x107E70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107E6Cu;
            // 0x107e70: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107E8Cu;
            goto label_107e8c;
        }
    }
    ctx->pc = 0x107E74u;
    // 0x107e74: 0xac710004  sw          $s1, 0x4($v1)
    ctx->pc = 0x107e74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 17));
    // 0x107e78: 0xac700008  sw          $s0, 0x8($v1)
    ctx->pc = 0x107e78u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 16));
label_107e7c:
    // 0x107e7c: 0xac600010  sw          $zero, 0x10($v1)
    ctx->pc = 0x107e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    // 0x107e80: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x107e80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107e84: 0xac60000c  sw          $zero, 0xC($v1)
    ctx->pc = 0x107e84u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
label_107e88:
    // 0x107e88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x107e88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_107e8c:
    // 0x107e8c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x107e8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x107e90: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x107e90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x107e94: 0x3e00008  jr          $ra
    ctx->pc = 0x107E94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107E94u;
            // 0x107e98: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107E24u: goto label_107e24;
            case 0x107E30u: goto label_107e30;
            case 0x107E50u: goto label_107e50;
            case 0x107E68u: goto label_107e68;
            case 0x107E7Cu: goto label_107e7c;
            case 0x107E88u: goto label_107e88;
            case 0x107E8Cu: goto label_107e8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107E9Cu;
    // 0x107e9c: 0x0  nop
    ctx->pc = 0x107e9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
