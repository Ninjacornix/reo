#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179E18
// Address: 0x179e18 - 0x179e98
void sub_00179E18_0x179e18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179E18_0x179e18");
#endif

    switch (ctx->pc) {
        case 0x179e3cu: goto label_179e3c;
        case 0x179e50u: goto label_179e50;
        default: break;
    }

    ctx->pc = 0x179e18u;

    // 0x179e18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179e18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179e1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179e20: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179e20u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179e24: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179e24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179e28: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179e2c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179e2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179e30: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179e34: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179E34u;
    SET_GPR_U32(ctx, 31, 0x179E3Cu);
    ctx->pc = 0x179E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179E34u;
            // 0x179e38: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179E3Cu; }
        if (ctx->pc != 0x179E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179E3Cu; }
        if (ctx->pc != 0x179E3Cu) { return; }
    }
    ctx->pc = 0x179E3Cu;
label_179e3c:
    // 0x179e3c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179e3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179e40: 0x1220000f  beqz        $s1, . + 4 + (0xF << 2)
    ctx->pc = 0x179E40u;
    {
        const bool branch_taken_0x179e40 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E40u;
            // 0x179e44: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179e40) {
            ctx->pc = 0x179E80u;
            goto label_179e80;
        }
    }
    ctx->pc = 0x179E48u;
    // 0x179e48: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179E48u;
    SET_GPR_U32(ctx, 31, 0x179E50u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179E50u; }
        if (ctx->pc != 0x179E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179E50u; }
        if (ctx->pc != 0x179E50u) { return; }
    }
    ctx->pc = 0x179E50u;
label_179e50:
    // 0x179e50: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x179e50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x179e54: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179E54u;
    {
        const bool branch_taken_0x179e54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x179E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E54u;
            // 0x179e58: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179e54) {
            ctx->pc = 0x179E68u;
            goto label_179e68;
        }
    }
    ctx->pc = 0x179E5Cu;
    // 0x179e5c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x179E5Cu;
    {
        const bool branch_taken_0x179e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x179E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E5Cu;
            // 0x179e60: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179e5c) {
            ctx->pc = 0x179E80u;
            goto label_179e80;
        }
    }
    ctx->pc = 0x179E64u;
    // 0x179e64: 0x0  nop
    ctx->pc = 0x179e64u;
    // NOP
label_179e68:
    // 0x179e68: 0x92230019  lbu         $v1, 0x19($s1)
    ctx->pc = 0x179e68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 25)));
    // 0x179e6c: 0x14640004  bne         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x179E6Cu;
    {
        const bool branch_taken_0x179e6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x179E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E6Cu;
            // 0x179e70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179e6c) {
            ctx->pc = 0x179E80u;
            goto label_179e80;
        }
    }
    ctx->pc = 0x179E74u;
    // 0x179e74: 0x9223001a  lbu         $v1, 0x1A($s1)
    ctx->pc = 0x179e74u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x179e78: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179e7c: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179e7cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179e80:
    // 0x179e80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179e80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179e84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179e84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179e88: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179e88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179e8c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179e8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179e90: 0x3e00008  jr          $ra
    ctx->pc = 0x179E90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179E90u;
            // 0x179e94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179E3Cu: goto label_179e3c;
            case 0x179E50u: goto label_179e50;
            case 0x179E68u: goto label_179e68;
            case 0x179E80u: goto label_179e80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179E98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
