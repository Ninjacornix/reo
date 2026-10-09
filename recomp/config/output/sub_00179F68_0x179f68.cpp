#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179F68
// Address: 0x179f68 - 0x179fd0
void sub_00179F68_0x179f68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179F68_0x179f68");
#endif

    switch (ctx->pc) {
        case 0x179f8cu: goto label_179f8c;
        case 0x179fa0u: goto label_179fa0;
        default: break;
    }

    ctx->pc = 0x179f68u;

    // 0x179f68: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179f68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179f6c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179f6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179f70: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179f70u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179f74: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179f74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179f78: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179f78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179f7c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179f80: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179f80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179f84: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179F84u;
    SET_GPR_U32(ctx, 31, 0x179F8Cu);
    ctx->pc = 0x179F88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179F84u;
            // 0x179f88: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179F8Cu; }
        if (ctx->pc != 0x179F8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179F8Cu; }
        if (ctx->pc != 0x179F8Cu) { return; }
    }
    ctx->pc = 0x179F8Cu;
label_179f8c:
    // 0x179f8c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179f8cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179f90: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x179F90u;
    {
        const bool branch_taken_0x179f90 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179F90u;
            // 0x179f94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179f90) {
            ctx->pc = 0x179FB8u;
            goto label_179fb8;
        }
    }
    ctx->pc = 0x179F98u;
    // 0x179f98: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179F98u;
    SET_GPR_U32(ctx, 31, 0x179FA0u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179FA0u; }
        if (ctx->pc != 0x179FA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179FA0u; }
        if (ctx->pc != 0x179FA0u) { return; }
    }
    ctx->pc = 0x179FA0u;
label_179fa0:
    // 0x179fa0: 0x240300e0  addiu       $v1, $zero, 0xE0
    ctx->pc = 0x179fa0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x179fa4: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179FA4u;
    {
        const bool branch_taken_0x179fa4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x179FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179FA4u;
            // 0x179fa8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179fa4) {
            ctx->pc = 0x179FB8u;
            goto label_179fb8;
        }
    }
    ctx->pc = 0x179FACu;
    // 0x179fac: 0x92230019  lbu         $v1, 0x19($s1)
    ctx->pc = 0x179facu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 25)));
    // 0x179fb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179fb4: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179fb8:
    // 0x179fb8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179fb8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179fbc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179fbcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179fc0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179fc0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179fc4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179fc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179fc8: 0x3e00008  jr          $ra
    ctx->pc = 0x179FC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179FC8u;
            // 0x179fcc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179F8Cu: goto label_179f8c;
            case 0x179FA0u: goto label_179fa0;
            case 0x179FB8u: goto label_179fb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179FD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
