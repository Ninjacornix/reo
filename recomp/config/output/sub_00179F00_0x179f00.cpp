#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179F00
// Address: 0x179f00 - 0x179f68
void sub_00179F00_0x179f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179F00_0x179f00");
#endif

    switch (ctx->pc) {
        case 0x179f24u: goto label_179f24;
        case 0x179f38u: goto label_179f38;
        default: break;
    }

    ctx->pc = 0x179f00u;

    // 0x179f00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179f00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179f04: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179f04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179f08: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179f08u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179f0c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179f0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179f10: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179f10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179f14: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179f14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179f18: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179f18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179f1c: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179F1Cu;
    SET_GPR_U32(ctx, 31, 0x179F24u);
    ctx->pc = 0x179F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179F1Cu;
            // 0x179f20: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179F24u; }
        if (ctx->pc != 0x179F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179F24u; }
        if (ctx->pc != 0x179F24u) { return; }
    }
    ctx->pc = 0x179F24u;
label_179f24:
    // 0x179f24: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179f24u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179f28: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x179F28u;
    {
        const bool branch_taken_0x179f28 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179F28u;
            // 0x179f2c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179f28) {
            ctx->pc = 0x179F50u;
            goto label_179f50;
        }
    }
    ctx->pc = 0x179F30u;
    // 0x179f30: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179F30u;
    SET_GPR_U32(ctx, 31, 0x179F38u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179F38u; }
        if (ctx->pc != 0x179F38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179F38u; }
        if (ctx->pc != 0x179F38u) { return; }
    }
    ctx->pc = 0x179F38u;
label_179f38:
    // 0x179f38: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x179f38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x179f3c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179F3Cu;
    {
        const bool branch_taken_0x179f3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x179F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179F3Cu;
            // 0x179f40: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179f3c) {
            ctx->pc = 0x179F50u;
            goto label_179f50;
        }
    }
    ctx->pc = 0x179F44u;
    // 0x179f44: 0x8e23001c  lw          $v1, 0x1C($s1)
    ctx->pc = 0x179f44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x179f48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179f4c: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179f50:
    // 0x179f50: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179f50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179f54: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179f54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179f58: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179f58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179f5c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179f5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179f60: 0x3e00008  jr          $ra
    ctx->pc = 0x179F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179F60u;
            // 0x179f64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179F24u: goto label_179f24;
            case 0x179F38u: goto label_179f38;
            case 0x179F50u: goto label_179f50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179F68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
